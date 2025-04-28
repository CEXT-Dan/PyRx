## v2.2.7

* Replace PYLOAD, PYRELOAD open file dialog with native windows version, cad’s did not filter correctly 
* [#295] fixed regression, PYLOAD error messages were silenced
* Fix SmSheetSetMgr closeAll()
* [#292] fix print function does not display % character
* [#291] Enable sheet set fixes for BrisCAD 25.2
* Renamed conflicting wblock overload that accepts an already constructed database to wblockByRef, Python wants the same return type across overloads 
* Improved versioning 
* [#278] add BlockTableRecord effectiveName, also attempts to handle the effective name for BricsCAD’s parametric blocks (SR 196681)

### What's Changed

* Ruff by @gswifort in https://github.com/CEXT-Dan/PyRx/pull/279
* Ruff by @gswifort in https://github.com/CEXT-Dan/PyRx/pull/280
* Rework test_runner.py by @rdesparbes in https://github.com/CEXT-Dan/PyRx/pull/281
* Integrate mypy in CI by @rdesparbes in https://github.com/CEXT-Dan/PyRx/pull/284
* Add pytest to CI by @rdesparbes in https://github.com/CEXT-Dan/PyRx/pull/299

**Full Changelog**: https://github.com/CEXT-Dan/PyRx/compare/v2.2.6...v2.2.7

## v2.2.6

pip install cad-pyrx
python -m pip install git+https://github.com/CEXT-Dan/PyRx.git@v2.2.5

* [#254] show wx.ToolTip in modeless dialogs 
* move from boost 1_85 boost 1_88?
* use v25.2 SDK for BricsCAD
* [#276] fix AcGsView::getSnapShot, does not pickup shademode in brx
* [#273] Add support for GStarCAD 2026
* [#165] finish Ax space

### What's Changed

* Fix invalid syntax and symbols in PyBrxBim.pyi by @rdesparbes in https://github.com/CEXT-Dan/PyRx/pull/256
* Introduce Ruff in CI by @rdesparbes in https://github.com/CEXT-Dan/PyRx/pull/261
* fix pyrx_imp.py by @gswifort in https://github.com/CEXT-Dan/PyRx/pull/263
* Add subprocess calls to run 'ruff check --fix pyrx' in gen_pyi.py by @gswifort in https://github.com/CEXT-Dan/PyRx/pull/264
* Decouple pyi generation from RX by @rdesparbes in https://github.com/CEXT-Dan/PyRx/pull/267
* fix __init__.py, missing Ax, Cv, Bim, Brx by @gswifort in https://github.com/CEXT-Dan/PyRx/pull/268
* Fix tests not passing in test_pyi_gen.py by @rdesparbes in https://github.com/CEXT-Dan/PyRx/pull/269
* Fix some type hint errors reported by mypy in .pyi files by @rdesparbes in https://github.com/CEXT-Dan/PyRx/pull/270
* class extending BlockReference by @gswifort in https://github.com/CEXT-Dan/PyRx/pull/272
* Restore disabled test in test_pyi_gen.py by @rdesparbes in https://github.com/CEXT-Dan/PyRx/pull/274
* Remove TypeFixer by @rdesparbes in https://github.com/CEXT-Dan/PyRx/pull/277

## v2.2.5

* [#253] fixes the issue shuffling sys.path during loading, and is restored afterwards
* [#252] add pyc file support
* [#165] AcadMLeaderStyle, AcadMaterial, AcadDimension (and derived)

## v2.2.4

* [#246] missed AcadDocument.Save()
* [#243] add SortentsTable and AcadSortentsTable
* [#228] fix typos in Editor reactor
* [#225] improve loading sequence
* [#225] improve loading sequence
* [#165] added AcadTable, AcadDimension, AcadDimAligned
