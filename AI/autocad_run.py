#!/usr/bin/env python3
"""Launch AutoCAD with a PyRx Python module loaded via the /ld flag.

The tool:
  * finds acad.exe (defaults to AutoCAD 2027),
  * starts it with:  acad.exe /ld <module>,
  * optionally waits for expected text to appear in the module log,
  * closes AutoCAD again when done.

The module under test is expected to log to the file given by --log; the
AI_RUN_LOG environment variable is set for AutoCAD so the module knows
where to write.  The log file is truncated at launch so every run starts
fresh.

Examples:
  python autocad_run.py                                  # load ai_template.py (default)
  python autocad_run.py --wait 90 --expect OnPyInitApp   # auto-close after init callback
  python autocad_run.py -m my_experiment.py --wait 90     # load a module you copied from the template
  python autocad_run.py -m C:\\other\\mod.py --force

Exit codes:
  0 = launched (and, if --wait was used, AutoCAD closed successfully)
  1 = AutoCAD was closed but --expect text was never seen in the log
  2 = AutoCAD is already running (close it or pass --force)
  3 = module / acad.exe / log file not found
"""
import argparse
import os
import subprocess
import sys
import time

TOOL_DIR = os.path.dirname(os.path.abspath(__file__))
DEFAULT_ACAD = r"C:\Program Files\Autodesk\AutoCAD 2027\acad.exe"
DEFAULT_MODULE = os.path.join(TOOL_DIR, "ai_template.py")
DEFAULT_LOG = os.path.join(TOOL_DIR, "ai_run.log")


def find_matching_acad_pids(acad_path):
    """Return PIDs of acad.exe processes running from the same folder as acad_path.

    Other AutoCAD versions (2021/2024/...) are deliberately left alone.
    """
    folder = os.path.dirname(os.path.abspath(acad_path)).lower().replace("'", "''")
    ps = (
        "$f='%s';"
        "Get-CimInstance Win32_Process -Filter \"Name='acad.exe'\" |"
        " Where-Object { $_.ExecutablePath -and $_.ExecutablePath.ToLower().StartsWith($f) } |"
        " Select-Object -ExpandProperty ProcessId"
    ) % folder
    out = subprocess.run(
        ["powershell", "-NoProfile", "-Command", ps],
        capture_output=True,
        text=True,
    )
    pids = []
    for tok in out.stdout.split():
        tok = tok.strip()
        if tok.isdigit():
            pids.append(int(tok))
    return pids


def kill_pids(pids):
    pids = [p for p in pids if p]
    if not pids:
        return
    subprocess.run(
        ["taskkill", "/F", "/PID", *[str(p) for p in pids]],
        capture_output=True,
    )
    time.sleep(1)


def log_has_text(path, text):
    try:
        with open(path, encoding="utf-8", errors="replace") as f:
            return text in f.read()
    except OSError:
        return False


def print_log(path, max_lines=100):
    try:
        with open(path, encoding="utf-8", errors="replace") as f:
            lines = f.read().splitlines()
    except OSError:
        print("  (no log file)")
        return
    if not lines:
        print("  (log is empty)")
        return
    shown = lines[-max_lines:]
    print("  --- %s (last %d of %d lines) ---" % (path, len(shown), len(lines)))
    for line in shown:
        print("  " + line)


def main():
    ap = argparse.ArgumentParser(
        description=__doc__,
        formatter_class=argparse.RawDescriptionHelpFormatter,
    )
    ap.add_argument(
        "-m", "--module",
        default=DEFAULT_MODULE,
        help="Python module to load with /ld (default: ai_template.py)",
    )
    ap.add_argument(
        "--acad",
        default=DEFAULT_ACAD,
        help="Path to acad.exe (default: AutoCAD 2027)",
    )
    ap.add_argument(
        "--log",
        default=DEFAULT_LOG,
        help="Log file the module should write (default: ai_run.log)",
    )
    ap.add_argument(
        "--wait",
        type=int,
        default=0,
        metavar="SECONDS",
        help="Wait up to N seconds watching the log, then close AutoCAD. "
             "0 = leave AutoCAD running (default)",
    )
    ap.add_argument(
        "--expect",
        default=None,
        help="Close AutoCAD as soon as this text appears in the log",
    )
    ap.add_argument(
        "--force",
        action="store_true",
        help="Kill running AutoCAD instances of this version before launching",
    )
    args = ap.parse_args()

    module = os.path.abspath(args.module)
    if not os.path.isfile(module):
        print("ERROR: module not found: %s" % module)
        return 3

    acad = args.acad
    if not os.path.isfile(acad):
        print("ERROR: acad.exe not found: %s" % acad)
        return 3

    pids = find_matching_acad_pids(acad)
    if pids:
        if args.force:
            print("Killing running AutoCAD instance(s): %s" % ", ".join(map(str, pids)))
            kill_pids(pids)
        else:
            print("ERROR: AutoCAD is already running (PID %s)." % ", ".join(map(str, pids)))
            print("Close it first, or re-run with --force to kill it.")
            return 2

    # Fresh log file; path shared with the module via AI_RUN_LOG.
    try:
        with open(args.log, "w", encoding="utf-8"):
            pass
    except OSError as e:
        print("ERROR: cannot write log file %s: %s" % (args.log, e))
        return 3

    env = os.environ.copy()
    env["AI_RUN_LOG"] = os.path.abspath(args.log)

    print("Launching: %s" % acad)
    print("  /ld   %s" % module)
    print("  log   %s" % env["AI_RUN_LOG"])
    proc = subprocess.Popen([acad, "/ld", module], env=env)
    print("AutoCAD started (PID %d)." % proc.pid)

    if args.wait <= 0:
        print("Leaving AutoCAD running. Close it when done.")
        return 0

    deadline = time.time() + args.wait
    found = False
    while True:
        if args.expect and log_has_text(args.log, args.expect):
            found = True
            break
        if time.time() >= deadline:
            break
        time.sleep(1)

    print("Closing AutoCAD...")
    kill_pids([proc.pid])
    kill_pids(find_matching_acad_pids(acad))
    print_log(args.log)

    if args.expect and not found:
        print("ERROR: expected text never appeared in the log: %s" % args.expect)
        return 1
    print("Done.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
