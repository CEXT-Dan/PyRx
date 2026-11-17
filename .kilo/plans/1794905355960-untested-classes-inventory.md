# Untested-Classes Inventory (PyRx)

## Goal
Produce a file in `AI/` listing every **non-enum class** in the PyRx stubs that **does not have a dedicated unit-test file** under `tests/test_core/`, so a dedicated test file can be created one-per-class. The deliverable is the **listing only** — do NOT write test files.

## Verified context
- **Stubs**: 14 top-level `.pyi` in `pyrx/` → PyRx, PyGe, PyGi, PyGs, PyDb, PyAp, PyEd, PyPl, PySm, PyBr, PyAx, PyBrx, PyBrxBim, PyBrxCv. `pyrx/doc_utils/stubs/` holds 2 helper stubs (duplicates) → **excluded**.
- **Counts**: 1132 total `class` defs; 428 are enums (`_BoostPythonEnum` base) ⇒ **~704 non-enum** in the 14 top-level modules (≈701 after dropping 3 doc_utils duplicates).
- **Import aliases** (`pyrx/__init__.py:30-57`): PyRx→Rx, PyGe→Ge, PyGi→Gi, PyGs→Gs, PyDb→Db, PyAp→Ap, PyEd→Ed, PyPl→Pl, PySm→Sm, PyBr→Br, PyAx→Ax, PyBrx→Brx, PyBrxBim→Bim, PyBrxCv→Cv.
- **Test folders** (`tests/test_core/`): test_PyAp, test_PyAx, test_PyDb, test_PyEd, test_PyGe, test_PyRx, test_PySm, test_PyBr, test_PyGs, test_Brx, test_wx.
- **No test folder**: PyGi, PyPl, PyBrx. PyBrxBim/PyBrxCv only have `test_Brx/test_BcadBim.py` + `test_BcadCivil.py` (not per-class files).
- **Edge cases found (must not create false "untested")**:
  - `test_PyDb/test_entity.py` (lowercase) tests `Db.Entity`/`Db.Point` → class `Entity`.
  - `test_PyDb/test_Ployline.py` (typo) tests `Db.Polyline` → class `Polyline`.
  - `test_PyDb/test_desc.py` = helper (`getHostName`), `test_PyGe/test_Pickle.py` = pickling, `test_wx/test_wx.py` = wx UI → none map to a single class.

## Decisions (confirmed)
1. **Enums excluded** — only classes + their methods are in scope.
2. **"Tested" = a dedicated test file exists** for the class (rule below). Mixed tests (e.g. abstract `Db.Curve` tested via `Db.Line`) remain valid and count as tested.
3. **Deliverable is the listing only** (no test files written, no renames, no test runs).
4. **All output in `AI/`** — primary human-readable file + machine-readable JSON + intermediates.

## Module → test-folder map
| module | test folder |
|---|---|
| PyRx | test_PyRx |
| PyGe | test_PyGe |
| PyGi | (none) |
| PyGs | test_PyGs |
| PyDb | test_PyDb |
| PyAp | test_PyAp |
| PyEd | test_PyEd |
| PyPl | (none) |
| PySm | test_PySm |
| PyBr | test_PyBr |
| PyAx | test_PyAx |
| PyBrx | test_Brx |
| PyBrxBim | test_Brx |
| PyBrxCv | test_Brx |

## Matching rule (per class `C` in module `M`, folder `F = map[M]`)
1. **TESTED** — `F/test_<C>.py` exists (case-insensitive exact).
2. **MANUAL REVIEW (near-miss in F)** — no exact match in F, but a `test_<X>.py` in F where `X` is a near-miss of `C` (Damerau–Levenshtein distance ≤ 1, case-insensitive) → flag with the candidate file. (Catches `test_Ployline.py`→`Polyline`.)
3. **MANUAL REVIEW (cross-folder exact)** — no exact match in F, but `test_<C>.py` (case-insensitive) exists in a *different* folder AND `C`'s name is unique across all modules → flag with that folder.
4. **UNTESTED** — none of the above.
- **Collision guard**: if `C`'s name exists in >1 module, only its own folder `F` may satisfy "TESTED"; never credit another module's folder (avoids crediting `PyAp.LayerFilter` via `PyDb`'s file, etc.).

## Tasks
1. Create **`AI/scripts/list_untested_classes.py`** (new, stdlib only, deterministic, no deps):
   - Parse all top-level `pyrx/*.pyi` (skip `doc_utils/stubs/`).
   - For each `^class <Name>(...)`: record module (file stem), class name, bases, line number.
   - Classify **enum** ⇔ any base is `_BoostPythonEnum`.
   - Emit **`AI/classes_all.json`**: `[{module, class, line, bases, is_enum}]` (keep all, flag enums).
   - Scan `tests/test_core/**/test_*.py` filenames; build the tested/review sets per the rule above.
   - Emit **`AI/tested_classes.json`**: `[{module, class, category, evidence_file}]` where category ∈ {TESTED, REVIEW_NEARMISS, REVIEW_CROSSFOLDER}.
   - Emit deliverables below.
2. Emit **`AI/classes_without_tests.md`** (primary):
   - Header: scope, totals, generation date, source paths.
   - Per-module sections (sorted), one checkbox line each: `- [ ] PyDb.SomeClass`.
   - A **"Manual review (possible typo/case or cross-folder)"** section listing candidates + the matched file, so nothing is silently dropped and no duplicate test file is created.
   - A note for modules with no test folder (PyGi, PyPl, PyBrx).
3. Emit **`AI/classes_without_tests.json`**: `[{module, class}]` for the UNTESTED set.
4. Print a short stdout summary: per-module untested counts, total untested, total manual-review.

## Files created (all under `AI/`)
- `AI/scripts/list_untested_classes.py` (the tool)
- `AI/classes_all.json` (intermediate)
- `AI/tested_classes.json` (intermediate)
- **`AI/classes_without_tests.md`** (primary deliverable)
- **`AI/classes_without_tests.json`** (machine-readable)

## Validation
- Runs with no external deps: `python AI/scripts/list_untested_classes.py`.
- Spot-check output:
  - `PyDb.Entity` → TESTED (`test_entity.py`, case-insensitive exact).
  - `PyDb.Polyline` → MANUAL REVIEW (near-miss `test_Ployline.py`), NOT in the "create new" list.
  - `PyDb.Curve` → TESTED (`test_PyDb/test_Curve.py`).
  - All `PyGi.*` non-enum → UNTESTED (no folder).
  - `PyDb.LayerFilter` and `PyAp.LayerFilter` → both UNTESTED (collision guard).
  - `PyGe.Point3d` → TESTED; `PyDb.Point` → TESTED; `PyDb.Polyline2d`/`Polyline3d` → UNTESTED (no `test_Polyline2d.py`).
- Totals sanity: `untested + tested + manual_review` == number of non-enum classes (~701–704).

## Out of scope
- Writing/renaming test files (e.g. fixing `test_Ployline.py`); running the tests; enum classes; `doc_utils/stubs/` duplicates.

## Optional enhancement (not blocking)
- Also tag each untested class as **abstract/base** (e.g. `Entity`, `DbObject`, `Curve`, `Surface`, `Traverser`) vs **concrete** to help prioritize. (Abstract ones would typically be tested via a concrete subclass, per the user's note.)
