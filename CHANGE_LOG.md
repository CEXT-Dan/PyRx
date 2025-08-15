## v2.2.25

* [#413] fix dispose issue with CvDbLabelStyle
* upgrade boost_1_88_0 -> boost_1_89_0
* Document::acadDocument, returns axDoc from doc
* AcadEntity::TransformBy is now non com.
* added Database::audit
* C++ modules are now compiled with AVX2

## v2.2.24

Added new command PYPIP
Added support for BricsCAD beta 2

## v2.2.23

* minor update for BRX26
* [#398] add class BrxCvDbAttribVariant

## v2.2.22

* [#401] Remove support for drag and drop loading as it breaks AutoCAD’s block palette
* added Point3dArray .isPlanar
* added Point3dArray . convexHull
* added Point3dArray . convexHullIndexes - Uses Andrew's monotone chain algorithm, ignores the Z

## v2.2.21

* Add Ge.Point2dArray. convexHull

## v2.2.20

* Add drag and drop loading support for .py and .pyc
* [#385] add missing len methods for geometry (Ge.Point2d)
* add Database::getBlockTable() utility method
* add Database.getBlocks returns a dictionary {name: id}
* add ObjectIdArray clear
* add ObjectIdArray.getIdsOfType, the idea is to be able to extract out types as needed, returns a new ObjectIdArray

## v2.2.19

* Add Db.Core.groupCodeToType
* [#375] Enforce boost::noncopyable, reactors are overruling are explicit no copy
* [#377] getKword  should return PromptStatus
* [#383] Ge.Matrix direct constructor

## v2.2.18

* [#374] build for BricsCAD v26 beta, is locked to version 26.1.1.0,
  * SR183699 acedGetPredefinedPatterns() (Ed.Core.getPredefinedPattens())
  * SR164260 AcDb3dProfile
  * SR179181 IAcSmSheet2
  * SR196681 effective block definition name
  * SR84527 field reactor

* Added convenience methods, Database.modelSpace and Database.modelSpace
* [#372] fixed Ge.Point2d invalid stubs

## v2.2.17

* added support for Point2dArray, Point3dArray in Polylines
* added multi-threaded sort utilities in Point2dArray, Point3dArray
* added Polyline::isPointInside
* fix AcDbExtents2dIntersects and AcDbExtents3dIntersects
* add Polyline::isCCW
* Polyline::simplify
* added Point2dTree, Point3dTree kd-trees that use [nanoflann](https://github.com/jlblancoc/nanoflann)

## v2.2.16

* Improve AcGeMatrix2d, added scale2d(), origin(), xAxis(), yAxis()
* Improve AcGeMatrix3d, added origin(), xAxis(), yAxis(), (), zAxis()
* [#367] add Point2dArray Point3dArray
* added Gi.Geometry::image, takes wxImage or Gi.PixelBGRA32Array from createFromWxImage
* [#366] added missing functions in Db.Region
* double getPerimeter() const;
* double              getArea() const;
* AcGeVector3d        getNormal() const;
* void                booleanOper(AcDb::BoolOperType operation, PyDbRegion& otherRegion);
* Adesk::UInt32       numChanges() const;

## v2.2.15

* [#361] IndexFilterManager
* [#363] Add Ed.Core.getCurrentView()
* [#322] Added ApApplication::listFilesInPath ApApplication::listFilesInPathRecursive
* Cleaned up and tested samples

## v2.2.14

* Updated constructors for `PyDbBlockBegin`, `PyDbBlockEnd`, and `PyDbSequenceEnd`
* improved class OsnapPointRef, added support for BricsCAD
* [#354] fix exception in BrxCvDbHAlignment
* [#216] added workaround for invalid inherited docstring
* rework docstrings to remove invalid line endings

## v2.2.13

* [#335] this release fixes issues found in the field evaluator, see the sample for notes, it should still be considered beta

## v2.2.12

* [#335] Wrap FieldEvaluator **
* [#342] remvove Db.Extents.overlaps, use intersects
* [#346] added Entity.transparency

** FieldEvaluator is beta

## v2.2.11

* fix icompare strings, used internally, did not handle other locales properly
* fix ax AddExtrudedSolid
* added helper PyGe.Matrix3d.scale3d() returns x.length() y.length() z.length() * [#338] add Db.PlotSettingsValidator.refreshLists()
* added Db.Extents.overlaps
* improve stubs

## v2.2.10

* [#224] added optional open erased argument to database objects that were missing them
* [#331] remove debugpy.wait_for_client()
* [#90] implemented brx bim export reactor, sample needs work
* added Document.getWxWindow * made C++ conform to PerformanceRule.ruleset
* improved document locking

## v2.2.9

* [#330] fixed issue that could cause an exception during shutdown in GStarCAD

## v2.2.8

* [#226] added Graph, XrefGraph, ObjectIdGraph and nodes
* added Ed.Code.curDwgXrefGraph
* added support for purge using ObjectIdGraph
* add support for user config by copying pyrx.toml to appdata/pyrx/
* Python modules are default run with optimization_level 2, this can be overridden in config
* add PYPTREPL, shows a python console window

# v2.2.7

* Replace PYLOAD, PYRELOAD open file dialog with native windows version, cad’s did not filter correctly
* [#295] fixed regression, PYLOAD error messages were silenced
* Fix SmSheetSetMgr closeAll()
* [#292] fix print function does not display % character
* [#291] Enable sheet set fixes for BrisCAD 25.2
* Renamed conflicting wblock overload that accepts an already constructed database to wblockByRef, Python wants the same return type across overloads
* Improved versioning
* [#278] add BlockTableRecord effectiveName, also attempts to handle the effective name for BricsCAD’s parametric blocks (SR 196681)

### What's Changed

* Ruff by @gswifort in <https://github.com/CEXT-Dan/PyRx/pull/279>
* Ruff by @gswifort in <https://github.com/CEXT-Dan/PyRx/pull/280>
* Rework test_runner.py by @rdesparbes in <https://github.com/CEXT-Dan/PyRx/pull/281>
* Integrate mypy in CI by @rdesparbes in <https://github.com/CEXT-Dan/PyRx/pull/284>
* Add pytest to CI by @rdesparbes in <https://github.com/CEXT-Dan/PyRx/pull/299>

**Full Changelog**: <https://github.com/CEXT-Dan/PyRx/compare/v2.2.6...v2.2.7>

## v2.2.6

pip install cad-pyrx
python -m pip install git+<https://github.com/CEXT-Dan/PyRx.git@v2.2.5>

* [#254] show wx.ToolTip in modeless dialogs
* move from boost 1_85 boost 1_88?
* use v25.2 SDK for BricsCAD
* [#276] fix AcGsView::getSnapShot, does not pickup shademode in brx
* [#273] Add support for GStarCAD 2026
* [#165] finish Ax space

### What's Changed

* Fix invalid syntax and symbols in PyBrxBim.pyi by @rdesparbes in <https://github.com/CEXT-Dan/PyRx/pull/256>
* Introduce Ruff in CI by @rdesparbes in <https://github.com/CEXT-Dan/PyRx/pull/261>
* fix pyrx_imp.py by @gswifort in <https://github.com/CEXT-Dan/PyRx/pull/263>
* Add subprocess calls to run 'ruff check --fix pyrx' in gen_pyi.py by @gswifort in <https://github.com/CEXT-Dan/PyRx/pull/264>
* Decouple pyi generation from RX by @rdesparbes in <https://github.com/CEXT-Dan/PyRx/pull/267>
* fix **init**.py, missing Ax, Cv, Bim, Brx by @gswifort in <https://github.com/CEXT-Dan/PyRx/pull/268>
* Fix tests not passing in test_pyi_gen.py by @rdesparbes in <https://github.com/CEXT-Dan/PyRx/pull/269>
* Fix some type hint errors reported by mypy in .pyi files by @rdesparbes in <https://github.com/CEXT-Dan/PyRx/pull/270>
* class extending BlockReference by @gswifort in <https://github.com/CEXT-Dan/PyRx/pull/272>
* Restore disabled test in test_pyi_gen.py by @rdesparbes in <https://github.com/CEXT-Dan/PyRx/pull/274>
* Remove TypeFixer by @rdesparbes in <https://github.com/CEXT-Dan/PyRx/pull/277>

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
