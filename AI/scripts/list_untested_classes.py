#!/usr/bin/env python3
"""List PyRx stub classes that lack a dedicated unit-test file.

Scans the top-level stubs in pyrx/*.pyi (pyrx/doc_utils/stubs/ duplicates are
excluded automatically because only top-level *.pyi files are parsed),
classifies every non-enum class as TESTED / MANUAL REVIEW / UNTESTED against
the test files under tests/test_core/, and writes the results under AI/.

Matching rule (per class C in module M, test folder F = MODULE_TO_TEST_FOLDER[M]):
  1. TESTED              - F/test_<C>.py exists (case-insensitive exact).
  2. REVIEW_NEARMISS     - no exact match in F, but a test_<X>.py in F where X is
                           a near-miss of C (Damerau-Levenshtein distance <= 1,
                           case-insensitive).
  3. REVIEW_CONVENTION   - PyAx only: classes are named "Acad<Suffix>" while
                           their dedicated test files follow the module-alias
                           convention "test_Ax<Suffix>.py" (e.g. test_AxEntity.py
                           tests PyAx.AcadEntity). That prefix swap is a
                           Damerau-Levenshtein distance of 2 (beyond the near-miss
                           threshold), so it is matched explicitly and routed to
                           manual review rather than TESTED or UNTESTED.
  4. REVIEW_CROSSFOLDER  - no exact match in F, but test_<C>.py exists in a
                           different folder AND C's name is unique across all
                           modules (collision guard).
  5. UNTESTED            - none of the above.

Stdlib only, deterministic output (sorted, stable), no external dependencies.
Run:  python AI/scripts/list_untested_classes.py
"""

from __future__ import annotations

import json
import re
from datetime import date
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
STUBS_DIR = ROOT / "pyrx"
TESTS_DIR = ROOT / "tests" / "test_core"
OUT_DIR = ROOT / "AI"

MODULE_TO_TEST_FOLDER = {
    "PyAp": "test_PyAp",
    "PyAx": "test_PyAx",
    "PyBr": "test_PyBr",
    "PyBrx": "test_Brx",
    "PyBrxBim": "test_Brx",
    "PyBrxCv": "test_Brx",
    "PyDb": "test_PyDb",
    "PyEd": "test_PyEd",
    "PyGe": "test_PyGe",
    "PyGi": None,
    "PyGs": "test_PyGs",
    "PyPl": None,
    "PyRx": "test_PyRx",
    "PySm": "test_PySm",
}

# Class headers are single-line: `class Name:` or `class Name(base, other):`.
# Verified: no nested classes and no multi-line headers in pyrx/*.pyi.
CLASS_RE = re.compile(r"^class\s+(\w+)\s*(?:\(([^()]*)\))?:")


def parse_stubs() -> list[dict]:
    classes = []
    for path in sorted(STUBS_DIR.glob("*.pyi")):
        module = path.stem
        text = path.read_text(encoding="utf-8")
        for lineno, line in enumerate(text.splitlines(), start=1):
            m = CLASS_RE.match(line)
            if m is None:
                continue
            name = m.group(1)
            bases_raw = m.group(2)
            bases = [b.strip() for b in bases_raw.split(",") if b.strip()] if bases_raw else []
            classes.append(
                {
                    "module": module,
                    "class": name,
                    "line": lineno,
                    "bases": bases,
                    "is_enum": any(b.rsplit(".", 1)[-1] == "_BoostPythonEnum" for b in bases),
                }
            )
    return classes


def _lev_le1(a: str, b: str) -> bool:
    """True iff Levenshtein distance(a, b) <= 1."""
    if a == b:
        return True
    la, lb = len(a), len(b)
    if abs(la - lb) > 1:
        return False
    if la > lb:
        a, b, la, lb = b, a, lb, la
    i = j = 0
    used_gap = False
    while i < la and j < lb:
        if a[i] == b[j]:
            i += 1
            j += 1
        else:
            if used_gap:
                return False
            used_gap = True
            if la == lb:
                i += 1  # substitution
            j += 1  # substitution, or deletion from the longer string b
    return True


def _one_adjacent_transposition(a: str, b: str) -> bool:
    if len(a) != len(b) or len(a) < 2:
        return False
    diffs = [k for k in range(len(a)) if a[k] != b[k]]
    return (
        len(diffs) == 2
        and diffs[1] == diffs[0] + 1
        and a[diffs[0]] == b[diffs[1]]
        and a[diffs[1]] == b[diffs[0]]
    )


def dl_le1(a: str, b: str) -> bool:
    """True iff Damerau-Levenshtein distance(a, b) <= 1.

    Distance 1 is exactly one operation: substitution, insertion, deletion
    (i.e. Levenshtein <= 1), or a single adjacent transposition (equal
    length with exactly two swapped adjacent positions).
    """
    return _lev_le1(a, b) or _one_adjacent_transposition(a, b)


def scan_test_files():
    """Return (folder -> {lower_name: rel_path}, lower_name -> [rel_path, ...])."""
    folder_to_names: dict[str, dict[str, str]] = {}
    name_to_files: dict[str, list[str]] = {}
    for folder in sorted(p for p in TESTS_DIR.iterdir() if p.is_dir()):
        names: dict[str, str] = {}
        for tf in sorted(folder.glob("test_*.py")):
            if not tf.name.startswith("test_") or not tf.name.endswith(".py"):
                continue
            x = tf.name[len("test_") : -len(".py")].lower()
            rel = f"{folder.name}/{tf.name}"
            names[x] = rel
            name_to_files.setdefault(x, []).append(rel)
        folder_to_names[folder.name] = names
    return folder_to_names, name_to_files


def convention_candidates(module: str, low: str, names: dict[str, str]) -> list[str]:
    """PyAx naming-convention matches (see module docstring, rule 3).

    Two observed file-name variants in test_PyAx:
      - test_Ax<Suffix>.py   for class Acad<Suffix>  (e.g. test_AxEntity.py / AcadEntity)
      - test_Ax<Class>.py    using the full class name (e.g. test_AxModelSpace.py / ModelSpace,
        test_AxAcadSortentsTable.py / AcadSortentsTable)
    """
    if module != "PyAx":
        return []
    out = []
    if low.startswith("acad") and len(low) > 4:
        x = "ax" + low[4:]
        if x in names:
            out.append(x)
    x = "ax" + low
    if x in names and x not in out:
        out.append(x)
    return out


def classify(classes: list[dict]):
    """Split non-enum classes into (tested_or_review, untested) lists."""
    name_modules: dict[str, set[str]] = {}
    for c in classes:
        name_modules.setdefault(c["class"].lower(), set()).add(c["module"])

    folder_to_names, name_to_files = scan_test_files()

    tested = []
    untested = []
    for c in classes:
        if c["is_enum"]:
            continue
        low = c["class"].lower()
        module = c["module"]
        entry = {"module": module, "class": c["class"]}
        folder = MODULE_TO_TEST_FOLDER.get(module)
        if folder is None or folder not in folder_to_names:
            untested.append(entry)
            continue
        names = folder_to_names[folder]
        if low in names:
            tested.append({**entry, "category": "TESTED", "evidence_file": names[low]})
            continue
        near = sorted(x for x in names if x != low and dl_le1(low, x))
        conv = [x for x in convention_candidates(module, low, names) if x not in near]
        if near or conv:
            category = "REVIEW_CONVENTION" if conv else "REVIEW_NEARMISS"
            tested.append(
                {
                    **entry,
                    "category": category,
                    "evidence_file": "; ".join(names[x] for x in near + conv),
                }
            )
            continue
        # Collision guard: only credit a cross-folder exact file when the
        # class name is unique across all modules.
        if len(name_modules[low]) == 1 and low in name_to_files:
            tested.append(
                {
                    **entry,
                    "category": "REVIEW_CROSSFOLDER",
                    "evidence_file": "; ".join(name_to_files[low]),
                }
            )
            continue
        untested.append(entry)
    return tested, untested


def compute_base_flags(classes: list[dict]) -> set[str]:
    """Return 'Module.Class' keys that are used as a base of some class.

    Heuristic (plan's optional enhancement): a class that appears as a base
    of another class (qualified or bare reference) is typically abstract /
    base and would normally be tested through a concrete subclass.
    """
    refs: set[str] = set()
    for c in classes:
        for b in c["bases"]:
            refs.add(b)
            refs.add(b.rsplit(".", 1)[-1])
    flags = set()
    for c in classes:
        if f"{c['module']}.{c['class']}" in refs or c["class"] in refs:
            flags.add(f"{c['module']}.{c['class']}")
    return flags


def write_outputs(classes, tested, untested, base_flags) -> None:
    OUT_DIR.mkdir(parents=True, exist_ok=True)

    total = len(classes)
    enums = sum(1 for c in classes if c["is_enum"])
    in_scope = total - enums
    n_tested = sum(1 for t in tested if t["category"] == "TESTED")
    n_review = sum(1 for t in tested if t["category"] != "TESTED")
    n_untested = len(untested)

    classes_all = [
        {
            "module": c["module"],
            "class": c["class"],
            "line": c["line"],
            "bases": c["bases"],
            "is_enum": c["is_enum"],
        }
        for c in sorted(classes, key=lambda c: (c["module"], c["line"]))
    ]
    (OUT_DIR / "classes_all.json").write_text(
        json.dumps(classes_all, indent=2) + "\n", encoding="utf-8"
    )

    tested_sorted = sorted(
        tested, key=lambda t: (t["module"], t["class"], t["category"])
    )
    (OUT_DIR / "tested_classes.json").write_text(
        json.dumps(tested_sorted, indent=2) + "\n", encoding="utf-8"
    )

    untested_sorted = sorted(untested, key=lambda u: (u["module"], u["class"]))
    (OUT_DIR / "classes_without_tests.json").write_text(
        json.dumps(untested_sorted, indent=2) + "\n", encoding="utf-8"
    )

    # ---- Markdown deliverable ----
    modules = sorted({c["module"] for c in classes})
    untested_by_module: dict[str, list[dict]] = {m: [] for m in modules}
    for u in untested_sorted:
        untested_by_module[u["module"]].append(u)

    review_nearmiss = [t for t in tested_sorted if t["category"] == "REVIEW_NEARMISS"]
    review_convention = [t for t in tested_sorted if t["category"] == "REVIEW_CONVENTION"]
    review_crossfolder = [t for t in tested_sorted if t["category"] == "REVIEW_CROSSFOLDER"]
    no_folder = [m for m in modules if MODULE_TO_TEST_FOLDER.get(m) is None]

    lines: list[str] = []
    lines.append("# Untested PyRx Classes")
    lines.append("")
    lines.append(f"- Generated: {date.today().isoformat()}")
    lines.append("- Scope: non-enum `class` definitions in the 14 top-level stubs `pyrx/*.pyi` "
                 "(`pyrx/doc_utils/stubs/` duplicates excluded); enums (`_BoostPythonEnum` bases) are out of scope.")
    lines.append(f"- Totals: {total} classes, {enums} enums, **{in_scope} in scope**")
    lines.append(f"- Results: {n_tested} tested, {n_review} manual review, **{n_untested} untested**")
    lines.append(f"- Sources: stubs in `{STUBS_DIR.relative_to(ROOT).as_posix()}/`, tests under `{TESTS_DIR.relative_to(ROOT).as_posix()}/`")
    lines.append("- Rule: a class counts as TESTED only when its own module's test folder contains `test_<Class>.py` "
                 "(case-insensitive). Near-miss filenames (Damerau-Levenshtein distance <= 1), the PyAx "
                 "`Acad*` class ↔ `test_Ax*` file naming convention, and cross-folder exact matches for unique "
                 "class names are listed under *Manual review* instead, so nothing is silently dropped and no "
                 "duplicate test file is created. Class names that exist in more than one module are never "
                 "credited via another module's folder (collision guard).")
    lines.append("")
    lines.append("## Untested classes (create one test file per class)")
    lines.append("")
    for m in modules:
        items = untested_by_module[m]
        folder = MODULE_TO_TEST_FOLDER.get(m)
        folder_txt = folder if folder else "(no test folder)"
        lines.append(f"### {m} ({len(items)}) — test folder: `{folder_txt}`")
        lines.append("")
        if not items:
            lines.append("_all non-enum classes covered_")
            lines.append("")
            continue
        for u in items:
            suffix = " *(base)*" if f"{u['module']}.{u['class']}" in base_flags else ""
            lines.append(f"- [ ] {u['module']}.{u['class']}{suffix}")
        lines.append("")

    lines.append("## Manual review (possible typo/case or cross-folder)")
    lines.append("")
    if not (review_nearmiss or review_convention or review_crossfolder):
        lines.append("_none_")
        lines.append("")
    for t in review_nearmiss:
        lines.append(f"- {t['module']}.{t['class']} — near-miss file: `tests/test_core/{t['evidence_file']}` "
                     "(check before creating a duplicate)")
    if review_convention:
        lines.append("")
        lines.append(f"PyAx naming convention — dedicated test files use the module alias `Ax` in place of "
                     f"the `Acad` prefix (or prepend `Ax` to the class name), e.g. `test_AxEntity.py` ↔ "
                     f"`AcadEntity`, `test_AxModelSpace.py` ↔ `ModelSpace`, `test_AxAcadSortentsTable.py` ↔ "
                     f"`AcadSortentsTable`. Each entry below already has a dedicated test file; verify before "
                     f"creating a duplicate:")
        lines.append("")
        for t in review_convention:
            lines.append(f"- {t['module']}.{t['class']} — convention file: `tests/test_core/{t['evidence_file']}`")
    if review_crossfolder:
        lines.append("")
        for t in review_crossfolder:
            lines.append(f"- {t['module']}.{t['class']} — exact file in another folder: "
                         f"`tests/test_core/{t['evidence_file']}` (verify it tests this class)")
    if review_nearmiss or review_convention or review_crossfolder:
        lines.append("")

    lines.append("## Notes")
    lines.append("")
    if no_folder:
        lines.append(f"- Modules with **no test folder** at all — every non-enum class above in these "
                     f"modules is untested: {', '.join(no_folder)}.")
    if "PyBrx" in modules:
        lines.append("- `PyBrx` shares the `test_Brx` folder with `PyBrxBim`/`PyBrxCv`; that folder contains "
                     "`test_BcadBim.py`/`test_BcadCivil.py` (module-level tests), not per-class PyBrx files.")
    lines.append("- `*(base)*` marks a class used as a base of another class (typically abstract; normally "
                 "tested through a concrete subclass) — useful for prioritization.")
    lines.append("- Helper test files that do not map to a single class (e.g. `test_PyDb/test_desc.py`, "
                 "`test_PyGe/test_Pickle.py`, `test_wx/test_wx.py`) are not credited to any class.")
    lines.append("")

    (OUT_DIR / "classes_without_tests.md").write_text("\n".join(lines), encoding="utf-8")

    # ---- stdout summary ----
    print("Per-module untested counts:")
    for m in modules:
        print(f"  {m}: {len(untested_by_module[m])}")
    print(f"Total untested:    {n_untested}")
    print(f"Total manual review: {n_review}")
    print(f"Total tested:      {n_tested}")
    print(f"Non-enum classes:  {in_scope} (sanity: {n_untested} + {n_review} + {n_tested} "
          f"= {n_untested + n_review + n_tested})")


def main() -> None:
    classes = parse_stubs()
    tested, untested = classify(classes)
    base_flags = compute_base_flags(classes)
    write_outputs(classes, tested, untested, base_flags)


if __name__ == "__main__":
    main()
