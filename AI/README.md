# AI Notes — PyRx test workflow

Notes for the AI assistant (and humans) working on the PyRx test suite.

## Paths

All stub files are in `pyrx\`
C++ headers and implmentation are in `PyRxCore\`
Python samples are in `PySamples\`
most used test files are in `tests\test_core\`


## Quick start: use the helper (RECOMMENDED)

`AI/run_pyrx_tests.py` is a **blocking** wrapper that launches `run_tests.bat`, waits for the
CAD host(s) to exit (no polling / log-size guessing), waits for the log to flush, evaluates **every
host log**, and prints a PASS/FAIL verdict with a proper exit code. Prefer this over the raw
`run_tests.bat` + `tasklist` dance.

```bash
# scoped (fast iteration) — AutoCAD only:
python AI/run_pyrx_tests.py --hosts acad --pyinit 0x1 --no-slow -k <Class>

# full suite, all hosts:
python AI/run_pyrx_tests.py

# examples:
python AI/run_pyrx_tests.py --dry-run                                  # print cmd, don't run
python AI/run_pyrx_tests.py --hosts acad --no-slow -k Face --tail 40    # show last 40 log lines
python AI/run_pyrx_tests.py -k Face --pytest-args "--tb=short -q"       # extra pytest args
```

- Flags map to the runner: `--hosts`, `--no-slow`, `--pyinit`, `--known-failures`, `--debug`.
- `-k <pat>` → pytest `-k`; `--pytest-args "..."` (one string) appends extra pytest args.
- Exit codes: `0` = all hosts passed; `1` = a host failed; `3` = timeout; `4` = no log (host crash).
- **Omitting `--hosts` runs on EVERY installed host** (BricsCAD, AutoCAD, ZwCAD, GstarCAD) — slower,
  but the helper reports each host log and fails if any fails. Use `--hosts acad` for a fast loop.

## How tests are run (manual / reference)

- Tests run **inside a CAD host** (AutoCAD by default). There is no plain `pytest` here.
- `local_test_runner.bat` → `./run_tests --pyinit 0x1 --no-slow --hosts acad`
  - `run_tests.bat` → `dotenv -f tests\.env run python -m tests.runner %*` (parses args, launches `acad.exe /b test.scr`)
  - **`./run_tests` does NOT exist on this machine** (missing wrapper) — run **`run_tests.bat`** instead.
  - **Launch recipe (verified from Git Bash, from the repo root):**
    ```bash
    cd /m/Dev/Projects/PyRxGit
    rm -f tests/output/test_*.log
    ./run_tests.bat --pyinit 0x1 --no-slow --hosts acad --pytest -k <Class> > /tmp/run.log 2>&1 &
    ```
    - `./` prefix is REQUIRED: bare `run_tests.bat` → `command not found` (bash won't add `.bat` to PATH).
    - Backgrounding is done by the bash `&` (NOT `nohup`; `nohup` can't resolve `.bat` and `nohup`/`&`
      do nothing inside `cmd //c`). If `./run_tests.bat` ever fails, the fallback is
      `cmd //c "run_tests.bat …" > /tmp/run.log 2>&1 &` (still backgrounded by the bash `&`).
    - Poll for completion: `tasklist 2>/dev/null | grep -i acad.exe` — loop until it prints nothing
      (≈20–30 s for a scoped run, longer for a full run). The pytest log lands in `tests/output/`.
  - AutoCAD loads `tests/host_runner.py`, which runs `pytest.main(["-vv", tests/])`
    **twice**: once in "command context" (`-m "not slow and not appctx"`) and once in
    "application context" (`-m "appctx and not slow"`).
- Output is captured to **`tests/output/test_<HOST>_<YYYY_MM_DD_HH_MM_SS>.log`** (plain pytest text, `-vv`).
  On this machine the AutoCAD 2027 host id is **`ARX26`** (e.g. `test_ARX26_2026_10_31_14_50_44.log`),
  NOT `ACAD` — match with `test_*.log` when picking the newest file.
- The runner quits AutoCAD when done (`_QUIT _Y` in the script).

## How to know the run is finished

1. A new file appears in `tests/output/` (clear the folder before starting).
2. Its size stabilizes around ~120 KB for a **full** run (0 KB = still running / buffer not flushed).
3. The `acad.exe` process is gone.

## Scoped runs (fast iteration — recommended while developing one test file)

You can inject extra pytest args after a `--pytest` marker:

```
./run_tests.bat --pyinit 0x1 --no-slow --hosts acad --pytest -k Face
```
(background it with `> /tmp/run.log 2>&1 &` and poll `tasklist | grep -i acad.exe`, see above)

- `-k Face` only selects `tests/test_core/test_PyDb/test_Face.py` (TestFace class).
- Everything before `--pytest` goes to the runner; everything after goes to pytest.
- `--hosts acad|bcad|gcad|zcad ...`, `--no-slow`, `--known-failures`, `--debug` are runner flags.
- Host exe paths come from env vars `ACAD_EXE`, `BCAD_EXE`, ... (see `tests/.env` / `tests/runner.py`).

## Inspecting results

Use the helper: `python AI/parse_test_output.py [substring]`
- no arg → latest log in `tests/output/`: prints FAILURES section + short summary
- with arg (e.g. `Face`) → also greps the log for that substring
- or just read the last ~40 lines of the newest `tests/output/test_ACAD_*.log` (short summary)

## Conventions for writing tests (observed in the suite)

- Tests live in `tests/test_core/test_PyDb/test_<Class>.py`, class `Test<...>`.
- Import `from pyrx import Db, Ge` (and `Ap`, `Ed` as needed).
- Stub signatures: `pyrx/PyDb.pyi`, `pyrx/PyGe.pyi` (big — search for `class <Name>`).
- Host-specific known failures: `@pytest.mark.known_failure_BRX` / `_ZRX` / `_GRX` / `_IRX` / `_ARX`
  (markers registered in `tests/pytest.ini`). `--no-slow` skips `@pytest.mark.slow`.
- Assertions style: `assert x == True` / `== False` (repo uses loose comparison), exact `Point3d` equality works.
- Errors: ObjectARX error statuses surface as exceptions; `Db.ErrorStatusException(RuntimeError)`
  has `.code` (e.g. `Db.ErrorStatus.eInvalidIndex`). `pytest.raises(RuntimeError)` is a safe catch-all.
- **DANGER:** some error paths do NOT raise a catchable Python exception — they crash the host
  (Windows fatal exception 0xe0000001, access violation), which aborts the WHOLE test session
  (no FAILURES section, no app-context run). Known trigger (verified 2026-10-31 on AutoCAD 2027):
  calling a mutator (`Face.setVertexAt`, `Face.makeEdgeInvisibleAt`) on an object opened ForRead.
  Never write tests that intentionally trigger such paths; leave a NOTE comment instead.
- No transaction API needed in these tests: entities are created bare and added with
  `Db.curDb().addToModelspace(entity)` (leaves the entity open for write — call `.close()` after).
- Cleanup: open `Db.Face(id, Db.OpenMode.kForWrite)`, call `.erase()`, `.close()`.
  (The suite doesn't always clean up, but new tests should — use the `_add_to_db`/`_erase` helpers in test_Face.py.)
- `setDatabaseDefaults()` (no arg → current db) before adding an entity is a good habit.
- `Db.OpenMode` has both `kForRead`/`kForWrite` and `ForRead`/`ForWrite` aliases.
- Entity methods that ACTUALLY work on Face (verified 2026-10-31): `objectId()`, `isA()`,
  `isKindOf(desc)`, `isErased()`, `erase()`, `close()`, `upgradeOpen()`, `downgradeOpen()`,
  `isReadEnabled()`, `isWriteEnabled()`, `color()`, `colorIndex()`, `castShadows()`, `setDatabaseDefaults()`.
  Do NOT assume `setNormal`/`setThickness` exist on Face — see the Face section below.
  (For other entities, always verify the method is bound in `PyRxCore/*.cpp` before testing it.)
- `RxClass` from `desc()` has `.name()`; `obj.isA() == Db.Face.desc()` comparison works.
- `.pyi` files can be WRONG vs the actual binding, check the cpp in `PyRxCore/*.cpp`

## Status (2026-11-02)

- `tests/test_core/test_PyDb/test_OverrulableEntity.py` — **done, 29/29 tests green** in scoped run
  (`-k OverrulableEntity`) and in the full run. Full `run_tests.bat --pyinit 0x1 --no-slow --hosts acad`
  summary: **1407 passed, 3 skipped, 11 deselected, 4 xfailed, 0 failed**. Covers class introspection,
  default ctor, `cloneFrom`/`cast`, default values, every getter/setter round-trip, DB persistence
  (add → reopen ForRead/ForWrite → verify → erase), `erase()`, and `transformBy`. No `.pyi`/binding
  discrepancies found (stub matched the binding exactly).

## Status (2026-10-31)

- `tests/test_core/test_PyDb/test_Face.py` — **done, 40/40 tests green** in full run
  (`local_test_runner.bat`): suite summary `1377 passed, 3 skipped, 11 deselected, 4 xfailed, 0 failed`.
- Fast-iteration loop that worked well:
  1. `./run_tests.bat --pyinit 0x1 --no-slow --hosts acad --pytest -k <Class> > /tmp/run.log 2>&1 &`
  2. poll `tasklist | grep -i acad.exe` until it exits (~20–30 s per scoped run)
  3. `python AI/parse_test_output.py` for FAILURES + summary
  4. for binding doubts: check `PyRxCore/PyDb*.cpp` `makePy...Wrapper()` overloads (the `.pyi` can be wrong)

## Helper files in this folder

- `run_pyrx_tests.py` — **recommended** blocking runner: launches the CAD host, blocks until it
  exits, evaluates every host log, prints a PASS/FAIL verdict + exit code. See "Quick start" above.
- `PROMPT_create_class_tests.md` — reusable prompt template: "Create tests for class XXXX",
  with coverage checklist, hard rules, run/verify steps, and definition of done.
- `parse_test_output.py` — summarize the newest test log (failures + summary).
