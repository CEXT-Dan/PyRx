# AI Notes — PyRx test workflow

Notes for the AI assistant (and humans) working on the PyRx test suite.

## How tests are run

- Tests run **inside a CAD host** (AutoCAD by default). There is no plain `pytest` here.
- `local_test_runner.bat` → `./run_tests --pyinit 0x1 --no-slow --hosts acad`
  - `run_tests.bat` → `python -m tests.runner` (parses args, launches `acad.exe /b test.scr`)
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
./run_tests --pyinit 0x1 --no-slow --hosts acad --pytest -k Face
```

- `-k Face` only selects `tests/test_core/test_PyDb/test_Face.py` (TestFace class).
- Everything before `--pytest` goes to the runner; everything after goes to pytest.
- `--hosts acad|bcad|gcad|zcad ...`, `--no-slow`, `--known-failures`, `--debug` are runner flags.
- Host exe paths come from env vars `ACAD_EXE`, `BCAD_EXE`, ... (see `tests/.env` / `tests/runner.py`).

## Inspecting results

Use the helper: `python AI_Notes/parse_test_output.py [substring]`
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

## Face-specific knowledge (AcDbFace)

- `Face(p0,p1,p2)` → triangle: vertex 3 == vertex 2 (DXF group 70 bit 16 "triangular").
- `Face(p0,p1,p2,p3)` → quad, split into triangles (v0,v1,v2) and (v0,v2,v3) — diagonal is v0→v2.
  Non-planar quads are allowed (warped faces); `intersectWith` interpolates per-triangle.
- Visibility ctors: **the C++ binding takes 4 edge-visibility booleans (e0..e3) only**,
  even though `pyrx/PyDb.pyi` shows 5 (`e0vis`..`e4vis`). Verified against
  `PyRxCore/PyDbEnts.cpp` (makePyDbFaceWrapper) — pass 4 bools, not 5.
  `isEdgeVisibleAt(i)` is only valid for i in 0..3 (else eInvalidIndex).
- Face has **NO** `setNormal`/`normal`/`setThickness`/`thickness` binding (those are bound per-entity
  for Point/Line/Arc/Circle/etc.). Shared entity base (PyDbEntity.cpp) provides:
  `color`, `setColor`, `colorIndex`, `setColorIndex`, `layerId`, `setLayer`, `castShadows`,
  `setCastShadows`, `setDatabaseDefaults`; PyDbObject.cpp adds `objectId`, `close`, `erase`,
  `isErased`, `isReadEnabled`, `isWriteEnabled`, `upgradeOpen`, `downgradeOpen`, `setXData`.
- `intersectWith(linearEnt: PyGe.LinearEnt3d)` → `list[PyGe.Point3d]`; accepts `LineSeg3d`, `Ray3d`, `Line3d`.
- Mutators (`setVertexAt`, `makeEdgeVisibleAt/InvisibleAt`) require write access when the object
  is database-resident (else error eWasNotOpenForWrite); free (non-resident) faces can be mutated directly.

## Gotchas verified while testing Face (2026-10-31, AutoCAD 2027 / ARX26)

- `Face(id)` default ctor opens ForRead; `Face(id, kForWrite)` opens ForWrite.
- `Db.curDb().addToModelspace(face)` leaves `face` open for write — call `face.close()` before
  re-opening the id with another wrapper.
- Error statuses DO raise `Db.ErrorStatusException` (subclass of RuntimeError) for bad values:
  `Face.getVertexAt(4)`, `setVertexAt(4, p)`, `isEdgeVisibleAt(4)` all raise.
  But **negative indices** raise `OverflowError` ("can't convert negative value to unsigned int")
  because C++ params are unsigned — catch `(OverflowError, ValueError)` for those.
- `.pyi` files can be WRONG vs the actual binding (5 bools vs 4). When a test fails with a
  constructor/arg error, check `PyRxCore/*.cpp` `makePy...Wrapper()` for the real `init<>` overloads.

## Status (2026-10-31)

- `tests/test_core/test_PyDb/test_Face.py` — **done, 40/40 tests green** in full run
  (`local_test_runner.bat`): suite summary `1377 passed, 3 skipped, 11 deselected, 4 xfailed, 0 failed`.
- Fast-iteration loop that worked well:
  1. `./run_tests --pyinit 0x1 --no-slow --hosts acad --pytest -k <Class>` (background + `nohup`)
  2. poll `tasklist | grep -i acad` until it exits (~30 s per scoped run)
  3. `python AI_Notes/parse_test_output.py` for FAILURES + summary
  4. for binding doubts: check `PyRxCore/PyDb*.cpp` `makePy...Wrapper()` overloads (the `.pyi` can be wrong)

## Helper files in this folder

- `PROMPT_create_class_tests.md` — reusable prompt template: "Create tests for class XXXX",
  with coverage checklist, hard rules, run/verify steps, and definition of done.
- `parse_test_output.py` — summarize the newest test log (failures + summary).
