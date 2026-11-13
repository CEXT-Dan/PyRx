# AI Notes — PyRx test workflow

Notes for the AI assistant (and humans) working on the PyRx test suite.

## Paths

All stub files are in `pyrx\`
C++ headers and implmentation are in `PyRxCore\`
Python samples are in `PySamples\`
most used test files are in `tests\test_core\`
all SDK files are in `M:\Dev\ArxSdk`

## Building PyRx (ARX/BRX/ZRX/GRX)

`AI/build_pyrx.py` builds the **latest** PyRx module + RxLoader for each CAD host with
MSBuild (Visual Studio 2022, toolset v143). Output lands in `Bin/<core>/x64/<Config>/`.

| host | CAD | core project | loader project | Debug x64 output |
|------|-----|--------------|----------------|------------------|
| `acad` | AutoCAD 2027 | PyRx26.0 | RxLoader26.0 | `Bin/PyRx26.0/x64/Debug/PyRx26.0.arx` + `RxLoader26.0.arx` + `pyrx_onload.py` |
| `bcad` | BricsCAD V27 | PyRxV27.0 | RxLoaderV27.0 | `Bin/PyRxV27.0/x64/Debug/PyRxV27.0.brx` + loader |
| `zcad` | ZWCAD 2027 | PyRxZ27.0 | RxLoaderZ27.0 | `Bin/PyRxZ27.0/x64/Debug/PyRxZ27.0.zrx` + loader |
| `gcad` | GstarCAD 2027 | PyRxG27.0 | RxLoaderG27.0 | `Bin/PyRxG27.0/x64/Debug/PyRxG27.0.grx` + loader |

```bash
python AI/build_pyrx.py                 # ALL hosts, Debug|x64
python AI/build_pyrx.py acad            # AutoCAD 2027 only (the unit-test autoload host)
python AI/build_pyrx.py bcad zcad       # any subset (host names are case-insensitive)
python AI/build_pyrx.py acad --config Release
python AI/build_pyrx.py acad --rebuild  # clean + rebuild
python AI/build_pyrx.py acad --dry-run  # print the MSBuild commands, build nothing
python AI/build_pyrx.py --msbuild "C:\...\MSBuild.exe"   # override MSBuild discovery
```

Notes:
- Only the **latest** version per CAD is built (PyRx26.0 = AutoCAD 2027; V27.0/Z27.0/G27.0 =
  the 2027 releases of Brics/Zw/Gstar). Older versions exist in the sln but aren't built here.
- SDK paths come from env vars `ARX2027`, `BRX27`, `ZRX2027`, `GRX27` (see `BUILDENV.txt`);
  the tool checks them up front and fails with a clear message if one is missing/wrong.
- Builds are **incremental**: seconds when nothing changed; a few minutes when a header
  changed (the core project compiles ~100 .cpp files). MSBuild output streams live.
- Needs Visual Studio 2022 (2026 also works) with the *Desktop development with C++*
  workload. The tool finds MSBuild via vswhere and prefers VS 2022 (projects pin toolset v143).
- Manual MSBuild equivalent, one project at a time (from the repo root):
  ```
  MSBuild.exe PyRxCore\PyRx26.0.vcxproj  -p:Configuration=Debug -p:Platform=x64 -p:SolutionDir="M:\Dev\Projects\PyRxGit\"
  MSBuild.exe PyRxLoader\RxLoader26.0.vcxproj -p:Configuration=Debug -p:Platform=x64 -p:SolutionDir="M:\Dev\Projects\PyRxGit\"
  ```
  `-p:SolutionDir` (absolute, trailing `\`) is **required** — `OutDir` is
  `$(SolutionDir)Bin\...` and is empty when building a vcxproj outside the solution.
- Git Bash mangles MSBuild `/t:`-style switches (MSYS path conversion) — use the dash form
  (`-t:`, `-p:`) there, or run from cmd/PowerShell. Python's subprocess is unaffected.
- AutoCAD 2027 autoloads the unit tests from `Bin\PyRx26.0\x64\Debug\` — rebuild after any
  C++ change, then re-run `AI/run_pyrx_tests.py`.

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

## Helper files in this folder

- `build_pyrx.py` — build the latest PyRx + RxLoader for AutoCAD/BricsCAD/ZWCAD/GstarCAD
  (Debug or Release, x64). See "Building PyRx" above.
- `run_pyrx_tests.py` — **recommended** blocking runner: launches the CAD host, blocks until it
  exits, evaluates every host log, prints a PASS/FAIL verdict + exit code. See "Quick start" above.
- `PROMPT_create_class_tests.md` — reusable prompt template: "Create tests for class XXXX",
  with coverage checklist, hard rules, run/verify steps, and definition of done.
- `parse_test_output.py` — summarize the newest test log (failures + summary).
