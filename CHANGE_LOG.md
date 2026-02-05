## v2.2.43

* Update AutoCAD ObjectARX version to 2027 release candidate
* [#457] improve Db.EvalVariant ctor to detect int16_t vs int32_t
* add Color.toHTMLColor EntityColor.toHTMLColor
* [#447] Refactor tests, lots of work on this task, I fixed items as I went along, mostly bad, or missing stubs

## v2.2.42

* add 3 point arc Db.Arc(Ge.Point3d(0,0,0),Ge.Point3d(50,50,0),Ge.Point3d(100,0,0))
* add Db.Polyline length
* [#451] fix Ge.Matrix3d.scale3d sign was always positive
* add Matrix3d::scale3dMagnitude same as scale3d, but always positive
* fixed PyDb3PointAngularDimension::xLine2Point() returned xLine1Point
* Improve stubs
* [#447] Refactor tests progress, theses are also worth a look as samples

## v2.2.41

* [#446] this release fixes a bug where some geometry classes had invalid signatures with regards to AcGePlane, Ge.Plane

## v2.2.40

* added AcXRefLayerPropertyOverrideType wrapper (Acad Only)
* [#445] added enum AdskBoolean, this resolves an enum conflict  where kTrue, kFalse were opposite, please use fully qualified enums when possible
* improve PyEd.SelectionSet, was iterating twice
* improve PyRxApp::moduleName(), avoid strlen
* refactor std::wstring PyRxApp::the_error()
* improve BlockTableRecord::hasAttributeDefinitions ARX only check is DXF group code 70 has been set, the improvement is to actually check.
* improve test_block_icon and BlockTableRecord::getPreviewIcon()
* improved performance in function Db.Polyline.isPointInside when the polyline contains bulges.
* [#443] (intellicad)implement missing AxTable methods in ICARX AxTable::GetText AxTable::SetText
* updated samples and stubs

## v2.2.39

* improved performance converting AutoCAD’s strings to Python (wchar_t to char)
* improved performance in function Db.Polyline.isPointInside when the polyline contains bulges.
* [#443] (intellicad)implement missing AxTable methods in ICARX AxTable::GetText AxTable::SetText

## v2.2.3*

* test build for Intellicad

## v2.2.37

* [#422] fix crash on close for Gstar2025
* improve PyGePoint2dArrayRepr and PyGePoint3dArrayRepr
* fix v24 project,

## v2.2.36

* add PyDb3dSolid::createCone
* add PyDb3dSolid::createCylinder
* [#423] PyDbAssocDependency
* [#423] PyDbAssocValueDependency
* improve PyDbGraph, added findCycles overload
* add LayerFilter::filterExpressionTree returns a list of tuple[str,str] with the values
* fix bad stub LayerTableRecord
* depreciated ObjectId::isValid() #has a warning, will be removed at some later date
* improve stubs (.pyi)

## v2.2.35

support CMS IntelliCAD 14.0

## v2.2.34

* add objectIdArray.Sort
* add objectIdArray.reverse
* added Db.Curve.isOn, alias of Ge.Curve, more user friendly as it only returns a bool instead of a tuple
* added PyGePoint2dArrayRepr and PyGePoint3dArrayRepr
* [#432] progress on Brx Mechanical
* [#423] progress on PyDb.AssocAction classes
* [#429] add AcDbDoubleClickOverrulableEntity
* fix  PyGeCurve2d::getSamplePoints

## v2.2.33

* BRX PyGeBoundBlock2d
* Enable PL namespace for BRX
* improve AutoDocLock, prevents document switching, with this lock, users cannot switch drawing tabs.
* added BlockReference.effectiveName() as an alias for BlockReference.getBlockName, the latter might be depreciated at some point
* added Db.BlockReference.hasAttributes
* Added custom object, Db.OverrulableEntity (beta), the goal is to have an object that any user can use to overrule without having to overrule an existing type. OverrulableEntity has filers that will persist through drawing sessions. Since it is a custom object, users that do not have PyRx installed will see the last Proxy graphic. If there are no overrules for the object, the graphic is a point.  The Fields I added should cover most any type of custom graphic.

This is still beta, so it’s best not to share any drawings that have this entity yet.

```C++
//data
 AcGePoint3d m_pos = AcGePoint3d::kOrigin;   // Transformed
 AcGeVector3d m_dir = AcGeVector3d::kXAxis;  // Transformed
 AcGeVector3d m_normal = AcGeVector3d::kZAxis;// Transformed

 AcString m_guid; // a developer key?
 AcString m_name; // anything
 AcString m_descr;// anything

 Adesk::Int64 m_type = 0; // anything
 Adesk::Int64 m_mask = 0; // anything
 Adesk::Int64 m_index = 0; // anything

 std::vector<Adesk::Int32> m_flags;//
 std::vector<Adesk::Int32> m_ints; // data
 std::vector<double> m_reals;      // " "
 std::vector<AcString> m_strings;  // " "
 std::vector<AcGePoint3d> m_points;//Transformed
```

## v2.2.32

* add helper function BlockReference.attlist, returns a list [(tag, value)]
* add helper function BlockReference.attdict, returns a dictionary {tag , value}
* Internal improvements

## v2.2.31

* Added @Ap.using_scope(), provides a scope for managing object lifetimes
* Fix Database.getVisualStyleList()
* Improve GsCore::getBlockImage() ignores non visible entities when computing view extents
* BlockTableRecord::visibleObjectIds(), ignores non visible entities, useful for dynamic blocks
* Improve ResultBuffer, added support AcDbHandle

## v2.2.30

* Support for BricsVAD V26

## v2.2.29

* change from AVX2 to AVX to prevent crashes on older computers

## v2.2.28

* added Ed.Core.lineWeightDialog
* added Ed.Core.linetypeDialog
* remove convertEntityToHatch (this was a function for old R13 hatches)
* fixed PyEdSelectionSet iterator, the buffer was not cleared on subsequent iterations
* progress on exit, the goal was to remove acrxLockApplication, make PyRx unloadable, differed
* internal, changed loading sequence of wxPython and Python
* PyUnicode_AsUTF8 is depreciated, use PyUnicode_AsUTF8AndSize

## v2.2.27

* [#418] refactored wxWidgets startup and shutdown. This release should also properly shuts down Python.  
* added support for BricsCAD beta 3, Other versions of BricsCAD are disabled

## v2.2.26

* [#417] raise KeyError instead of ErrorStatusException(eKeyNotFound) for SymbolTable and Dictionary
* [#416] added  std::filesystem::path::make_preferred() for OS in Ax methods
* [#414] add change_cwd parameter to command decorator
* [#389] Package Versioning
* [#399] add version pydantic_settings>=2.10.0
* Document::Open checks for SDI mode
* Refactor Database::getBlocks, PyDbSymbolTable

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
