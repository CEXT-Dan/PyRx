# Generic prompt: create tests for a class

Copy the prompt below, replace `<ClassName>`, and hand it to the AI assistant.
It assumes this repo (PyRx) and the conventions in `AI_Notes/README.md`.

---

## PROMPT (copy from here)

Create a complete unit test file for the class **`<ClassName>`** (namespace `PyDb` / `PyGe` / `PyAx` / ... as appropriate).

**Context**
- Test file location: `tests/test_core/test_Py<Namespace>/test_<ClassName>.py`
  (follow the folder layout of sibling test files).
- Stub signatures: `pyrx/Py<Namespace>.pyi` — search for `class <ClassName>` to find its full API surface.
- **The `.pyi` may be wrong.** Before relying on any signature, verify the real binding in the C++
  sources: find `makePy...<ClassName>...Wrapper()` / the `Py<ClassName>` class in `PyRxCore/*.cpp`
  and check the actual `init<>` overloads and which methods are bound (and what they return/throw).
- Read 1–2 sibling test files in the same folder first (e.g. `test_Line.py`, `test_Circle.py`,
  or `test_Face.py` as the golden example) and match their style exactly.
- Workflow notes: `AI_Notes/README.md` (how to run tests, done-detection, conventions, gotchas).

**Test coverage checklist** (adapt per class; skip what doesn't apply)
1. Class introspection: `className()`, `desc().name()`, `isA()` / `isKindOf(...)`, `cast()`, `cloneFrom()`.
2. Every constructor overload — construct, then verify each property reflects the inputs.
3. Getter/setter round-trips for every bound property (set → get → assert equality).
4. Default values: construct empty, assert sensible defaults.
5. Error behavior: out-of-range indices / bad values → `pytest.raises(RuntimeError)`
   (`Db.ErrorStatusException`); negative values into unsigned C++ params → `pytest.raises((OverflowError, ValueError))`.
6. DB round-trip where the class is an entity: add to modelspace, reopen by `ObjectId`
   (ForRead / ForWrite), verify persistence of changes, then erase (cleanup).
7. Geometry methods (e.g. `intersectWith`, extents) with hit, miss, boundary, and degenerate cases.
8. Entity base behavior: `objectId()` null until added, `isErased()`, `erase()`,
   `isReadEnabled()` / `isWriteEnabled()` after each open mode.

**Hard rules**
- NEVER write tests that intentionally trigger host-crash paths. Known crash (kills AutoCAD,
  aborts the whole session): calling a mutator on an object opened ForRead. If a bad-input path
  might crash instead of raising, leave a NOTE comment instead of a test.
- Tests that add entities to the current drawing MUST clean up (open ForWrite → `erase()` → `close()`).
  Use helper methods like `_add_to_db` / `_erase` (see `test_Face.py`).
- `Db.curDb().addToModelspace(entity)` leaves the entity open for write — call `.close()` before
  reopening the id with another wrapper.
- Match repo assertion style (`assert x == True`), and keep docstrings short.

**Run and verify**
1. Scoped fast run (background): `./run_tests --pyinit 0x1 --no-slow --hosts acad --pytest -k <ClassName>`
   - Poll `tasklist | grep -i acad` until it exits (~30 s per run); log lands in `tests/output/test_*.log`.
   - Inspect: `python AI_Notes/parse_test_output.py <ClassName>` (FAILURES section + summary).
   - If a test failed because a signature differs from the `.pyi`: fix the TEST to match the real
     binding (check `PyRxCore/*.cpp`), and note the discrepancy in `AI_Notes/README.md`.
2. Iterate until all new tests pass in the scoped run.
3. Final full run: `local_test_runner.bat` (clear `tests/output/` first; ~128 KB log ≈ done).
   Verify the whole suite is green (0 failed) — new tests must not break others.
4. Update `AI_Notes/README.md`: add class-specific findings/gotchas and a Status line
   (date, test count, suite summary).

**Definition of done**
- [ ] `tests/test_core/test_Py<Namespace>/test_<ClassName>.py` exists, all tests pass
- [ ] Full `local_test_runner.bat` run green
- [ ] `AI_Notes/README.md` updated with findings + status
- [ ] Any `.pyi`/binding discrepancies documented (and reported to the user so they can fix the stubs)

---

## Tips for filling it in (for the human)

- For small classes (e.g. `Color`, `ObjectId`) the geometry/persistence items don't apply — the
  checklist is intentionally over-complete; the AI should adapt.
- If the class lives in another namespace (`PyAx`, `PyGe`, `PyBr`), adjust the test folder and the
  stub file name in the prompt.
- For `known_failure_*` hosts: if a test only fails on one CAD host (e.g. BricsCAD), mark it
  `@pytest.mark.known_failure_BRX` (markers: `_ARX _BRX _GRX _IRX _ZRX`, defined in `tests/pytest.ini`)
  instead of deleting it.
- Keep scoped runs fast: `-k <ClassName>` matches the class name anywhere in the node id — make sure
  no other test file's names contain that substring (check the "selected" count in the log).
