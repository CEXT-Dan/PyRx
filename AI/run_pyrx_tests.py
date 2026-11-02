# ruff: noqa
"""Blocking wrapper for the PyRx CAD-host test runner.

Launches ``run_tests.bat`` (which starts the CAD host, runs pytest inside it, and
exits when the host closes), blocks until it finishes, then locates the newest
log in ``tests/output/``, waits for it to finish flushing, and prints a verdict.

This removes the flakiest part of the manual workflow (polling ``acad.exe`` /
guessing log size): the runner's own process exit is the reliable "done" signal.

Usage (run from anywhere; paths are resolved relative to this file):
    python AI/run_pyrx_tests.py -k OverrulableEntity        # scoped run
    python AI/run_pyrx_tests.py                              # full suite
    python AI/run_pyrx_tests.py --hosts bcad --pyinit 0x101 -k Face
    python AI/run_pyrx_tests.py --known-failures --no-slow
    python AI/run_pyrx_tests.py -k Face --pytest-args "--tb=short -q"   # extra pytest args
    python AI/run_pyrx_tests.py -k Face --tail 40            # print last 40 log lines

Exit code: 0 = all selected tests passed; non-zero = failures, errors, host crash,
or timeout.
"""

from __future__ import annotations

import argparse
import re
import subprocess
import sys
import time
from pathlib import Path

HERE = Path(__file__).resolve().parent
REPO_ROOT = HERE.parent
RUNNER_BAT = REPO_ROOT / "run_tests.bat"
OUTPUT_DIR = REPO_ROOT / "tests" / "output"

SUMMARY_RE = re.compile(r"(\d+)\s+(passed|failed|error|errors|skipped|xfailed|xpassed|deselected)")


def list_logs() -> list[Path]:
    if not OUTPUT_DIR.exists():
        return []
    return sorted(OUTPUT_DIR.glob("test_*.log"), key=lambda p: p.stat().st_mtime)


def new_logs(pre_run: set[Path]) -> list[Path]:
    """Return the log(s) created by this run (not present before we launched).

    One log is produced per CAD host, so a multi-host run yields several. We report on all
    of them and fail if any single host fails.
    """
    fresh = [p for p in list_logs() if p not in pre_run]
    if fresh:
        return sorted(fresh, key=lambda p: p.name)
    # Fallback: newest log overall (e.g. if a prior cleanup raced the timestamp).
    all_logs = list_logs()
    return [all_logs[-1]] if all_logs else []


def wait_for_flush(log: Path, stable_checks: int = 3, interval: float = 0.35, max_wait: float = 30.0) -> None:
    """Wait until the log size is stable a few times in a row (buffer flushed)."""
    last = -1
    stable = 0
    deadline = time.time() + max_wait
    while time.time() < deadline:
        size = log.stat().st_size
        if size == last:
            stable += 1
            if stable >= stable_checks:
                return
        else:
            last, stable = size, 0
        time.sleep(interval)


def build_command(args: argparse.Namespace) -> list[str]:
    runner_flags: list[str] = []
    if args.hosts:
        runner_flags += ["--hosts", *args.hosts]
    if args.no_slow:
        runner_flags += ["--no-slow"]
    if args.pyinit is not None:
        runner_flags += ["--pyinit", args.pyinit]
    if args.known_failures:
        runner_flags += ["--known-failures"]
    if args.debug:
        runner_flags += ["--debug"]

    pytest_args: list[str] = []
    if args.k:
        pytest_args += ["-k", args.k]
    if args.pytest_args:
        pytest_args += args.pytest_args.split()
    if pytest_args:
        runner_flags += ["--pytest", *pytest_args]

    # ``cmd /c`` + an arg list avoids POSIX shell-quoting pitfalls on Windows.
    return ["cmd", "/c", "run_tests.bat", *runner_flags]


def parse_verdict(log: Path) -> tuple[bool, list[str]]:
    """Return (passed, lines_to_print) based on the log contents."""
    text = log.read_text(encoding="utf-8", errors="replace")
    lines = text.splitlines()
    out: list[str] = []

    # FAILURES section (between the FAILURES header and the short summary).
    fail_idx = next((i for i, l in enumerate(lines) if re.match(r"^=+\s*FAILURES", l)), None)
    if fail_idx is not None:
        end_idx = next(
            (i for i in range(fail_idx + 1, len(lines)) if "short test summary" in lines[i]),
            len(lines),
        )
        section = lines[fail_idx:end_idx]
        out.append("\n".join(section[:200]))
        if len(section) > 200:
            out.append(f"... ({len(section) - 200} more FAILURES lines)")

    # ERRORS section, if any.
    err_idx = next((i for i, l in enumerate(lines) if re.match(r"^=+\s*ERRORS", l)), None)
    if err_idx is not None:
        out.append("\n".join(lines[err_idx:err_idx + 60]))

    # All summary count lines (there are two pytest passes: command + app context).
    summaries = [l for l in lines if "=" in l and SUMMARY_RE.search(l) and ("passed" in l or "failed" in l or "error" in l)]
    if summaries:
        out.append("\n".join(summaries[-8:]))
    else:
        out.append("(no pytest summary line found in log)")

    # Verdict: failed if any summary reports a positive failed/errors count, or no summary at all.
    passed = True
    for l in summaries:
        m_failed = re.search(r"(\d+)\s+failed", l)
        m_error = re.search(r"(\d+)\s+error", l)
        if (m_failed and int(m_failed.group(1)) > 0) or (m_error and int(m_error.group(1)) > 0):
            passed = False
    if not summaries:
        passed = False
    return passed, out


def main() -> int:
    ap = argparse.ArgumentParser(description="Blocking PyRx CAD-host test runner wrapper.")
    ap.add_argument("-k", "--k", metavar="PATTERN", help="pytest -k expression (selects matching tests).")
    ap.add_argument("--hosts", nargs="+", metavar="HOST", help="Hosts to run (acad bcad gcad icad zcad).")
    ap.add_argument("--pyinit", metavar="FLAGS", help="pyinit flags passed to the CAD host (e.g. 0x1).")
    ap.add_argument("--no-slow", action="store_true", help="Skip slow tests.")
    ap.add_argument("--known-failures", action="store_true", help="Include known-failure tests.")
    ap.add_argument("--debug", action="store_true", help="Keep the host open (no _QUIT).")
    ap.add_argument("--pytest-args", default=None, metavar="ARGS",
                    help="Extra pytest args as ONE string (e.g. '--tb=short -q'), appended after -k.")
    ap.add_argument("--timeout", type=float, default=600.0, help="Max seconds to wait for the host (default 600).")
    ap.add_argument("--tail", type=int, default=0, metavar="N", help="Also print the last N lines of the log.")
    ap.add_argument("--dry-run", action="store_true", help="Print the command and exit without running.")
    args = ap.parse_args()

    if not RUNNER_BAT.exists():
        print(f"ERROR: runner not found at {RUNNER_BAT}", file=sys.stderr)
        return 2

    cmd = build_command(args)
    print("$", " ".join(cmd))
    if args.dry_run:
        return 0

    pre_run = set(list_logs())
    OUTPUT_DIR.mkdir(parents=True, exist_ok=True)

    print(f"[run_pyrx_tests] launching host ... (timeout {args.timeout:.0f}s)\n", flush=True)
    try:
        proc = subprocess.run(cmd, cwd=str(REPO_ROOT), timeout=args.timeout)
    except subprocess.TimeoutExpired:
        print(f"\n[run_pyrx_tests] TIMEOUT after {args.timeout:.0f}s — host did not exit. "
              "It may be hung or waiting on the UI.", file=sys.stderr)
        return 3

    logs = new_logs(pre_run)
    if not logs:
        print("\n[run_pyrx_tests] FAILED: no log produced in tests/output/ "
              "(host likely crashed before pytest started, or the run was interrupted).", file=sys.stderr)
        print(f"[run_pyrx_tests] runner exit code = {proc.returncode}", file=sys.stderr)
        return 4

    all_passed = True
    for log in logs:
        wait_for_flush(log)
        passed, out_lines = parse_verdict(log)
        all_passed = all_passed and passed

        print("\n" + "=" * 70)
        print(f"HOST LOG: {log.name}   ->  {'PASS' if passed else 'FAIL'}")
        print("=" * 70)
        print("\n".join(out_lines))
        if args.tail > 0:
            tail = log.read_text(encoding="utf-8", errors="replace").splitlines()[-args.tail:]
            print(f"\n--- last {args.tail} lines ---")
            print("\n".join(tail))

    verdict = "PASS" if all_passed else "FAIL"
    print("\n" + "=" * 70)
    print(f"OVERALL: {verdict}   ({len(logs)} host log(s); runner exit code = {proc.returncode})")
    print("=" * 70)
    return 0 if all_passed else 1


if __name__ == "__main__":
    sys.exit(main())
