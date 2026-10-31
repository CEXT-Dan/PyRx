"""Summarize the newest PyRx test log in tests/output.

Usage:
    python AI_Notes/parse_test_output.py            # FAILURES section + short summary of latest log
    python AI_Notes/parse_test_output.py Face       # ... plus every line mentioning "Face"
    python AI_Notes/parse_test_output.py path.log   # explicit log path
"""

from __future__ import annotations

import re
import sys
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent.parent
OUTPUT_DIR = REPO_ROOT / "tests" / "output"


def latest_log(explicit: str | None) -> Path:
    if explicit:
        p = Path(explicit)
        if not p.is_absolute():
            p = REPO_ROOT / p
        if not p.exists():
            raise FileNotFoundError(p)
        return p
    logs = list(OUTPUT_DIR.glob("test_*.log"))
    if not logs:
        raise FileNotFoundError(f"no logs in {OUTPUT_DIR} (tests still running or never started)")
    return max(logs, key=lambda p: p.stat().st_mtime)


def main() -> int:
    arg = sys.argv[1] if len(sys.argv) > 1 else None
    log_path: Path | None = None
    filter_text: str | None = None
    if arg:
        candidate = Path(arg) if Path(arg).is_absolute() else (REPO_ROOT / arg)
        if candidate.exists() and candidate.suffix == ".log":
            log_path = candidate
        else:
            filter_text = arg  # treat as a search filter on the latest log
    if log_path is None:
        log_path = latest_log(None)

    text = log_path.read_text(encoding="utf-8", errors="replace")
    lines = text.splitlines()

    print(f"=== {log_path} ({log_path.stat().st_size} bytes, {len(lines)} lines) ===")

    # FAILURES section (pytest -vv): between "FAILURES" header and "short test summary"
    fail_idx = next((i for i, l in enumerate(lines) if re.match(r"^=+ FAILURES", l)), None)
    if fail_idx is not None:
        end_idx = next(
            (i for i in range(fail_idx + 1, len(lines)) if "short test summary" in lines[i]),
            len(lines),
        )
        section = lines[fail_idx:end_idx]
        print("\n".join(section[:400]))
        if len(section) > 400:
            print(f"... ({len(section) - 400} more lines)")
    else:
        print("\n(no FAILURES section found)")

    # errors section, if any
    err_idx = next((i for i, l in enumerate(lines) if re.match(r"^=+ ERRORS", l)), None)
    if err_idx is not None:
        print("\n" + "\n".join(lines[err_idx:err_idx + 60]))

    # short summary / final counts
    for i, l in enumerate(lines):
        if re.search(r"(\d+ (passed|failed|error|skipped|xfailed|xpassed))", l) and "=" in l:
            print(l)
    print("\n--- last 15 lines ---")
    print("\n".join(lines[-15:]))

    if filter_text:
        matched = [(i, l) for i, l in enumerate(lines) if filter_text.lower() in l.lower()]
        print(f"\n--- {len(matched)} lines matching '{filter_text}' (first 120) ---")
        for i, l in matched[:120]:
            print(f"{i + 1}: {l}")

    # overall pass/fail verdict
    m = re.search(r"=+ (\d+) failed", text)
    e = re.search(r"=+ \d+ (errors?)", text)
    print("\nVERDICT:", "FAILED" if (m or e) else "OK (no failed/errors in summary)" if "=" in text else "UNKNOWN (no summary found)")
    return 1 if (m or e) else 0


if __name__ == "__main__":
    sys.exit(main())
