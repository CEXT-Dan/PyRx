from __future__ import annotations
import pytest

from pyrx import Db
from pyrx import Ap

def getHostName():
    """Returns ARX, BRX, ZRX etc. directly from the CAD runtime environment."""
    try:
        host = Ap.Application.hostAPI()
        return host[:3].upper()
    except Exception:
        # Fallback if evaluated during an IDE parse or outside an active CAD session
        return "ARX"

# Instantly sets the runtime environment variable during test collection
CURRENT_HOST = getHostName()

class TestDesc:
    @pytest.mark.parametrize(
        "member, expected",
        [
            ("AbstractViewTable", "AcDbAbstractViewTable"),
            ("AbstractViewTableRecord", "AcDbAbstractViewTableRecord"),
            ("AcValue", "AcValue"),
            ("AlignedDimension", "AcDbAlignedDimension"),
            ("AnnotationScale", "AcDbAnnotationScale"),
            ("Arc", "AcDbArc"),
            ("ArcDimension", "AcDbArcDimension"),
            ("AssocPersSubentIdPE", "AcDbAssocPersSubentIdPE"),
            ("AttributeDefinition", "AcDbAttributeDefinition"),
            ("AttributeReference", "AcDbAttribute"),
            ("BlockBegin", "AcDbBlockBegin"),
            ("BlockEnd", "AcDbBlockEnd"),
            ("BlockTable", "AcDbBlockTable"),
            ("BlockTableRecord", "AcDbBlockTableRecord"),
            ("Body", "AcDbBody"),
            ("Circle", "AcDbCircle"),
            ("Curve", "AcDbCurve"),
            ("DatabaseReactor", "AcDbDatabaseReactor"),
            ("DbObject", "AcDbObject"),
            ("DbObjectOverrule", "AcDbObjectOverrule"),
            ("DbObjectReactor", "AcDbObjectReactor"),
            ("DiametricDimension", "AcDbDiametricDimension"),
            ("Dictionary", "AcDbDictionary"),
            ("DimAssoc", "AcDbDimAssoc"),
            ("DimStyleTable", "AcDbDimStyleTable"),
            ("DimStyleTableRecord", "AcDbDimStyleTableRecord"),
            ("Dimension", "AcDbDimension"),
            ("Ellipse", "AcDbEllipse"),
            ("Entity", "AcDbEntity"),
            ("EntityHyperlinkPE", "AcDbEntityHyperlinkPE"),
            ("EntityReactor", "AcDbEntityReactor"),
            ("EvalVariant", "AcDbEvalVariant"),
            ("ExtrudedSurface", "AcDbExtrudedSurface"),
            ("Face", "AcDbFace"),
            ("Fcf", "AcDbFcf"),
            ("Field", "AcDbField"),
            ("GeoData", "AcDbGeoData"),
            ("GeoPositionMarker", "AcDbGeoPositionMarker"),
            ("GripOverrule", "AcDbGripOverrule"),
            ("Group", "AcDbGroup"),
            ("Hatch", "AcDbHatch"),
            ("Helix", "AcDbHelix"),
            ("Image", "AcDbImage"),
            ("JoinEntityPE", "AcDbJoinEntityPE"),
            ("LayerFilter", "AcDbLayerFilter"),
            ("LayerStateManager", "AcDbLayerStateManager"),
            ("LayerTable", "AcDbLayerTable"),
            ("LayerTableRecord", "AcDbLayerTableRecord"),
            ("Layout", "AcDbLayout"),
            ("LayoutManager", "__LayoutManager__"),
            ("Leader", "AcDbLeader"),
            ("Line", "AcDbLine"),
            ("LineAngularDimension2", "AcDb2LineAngularDimension"),
            ("LinetypeTable", "AcDbLinetypeTable"),
            ("LinetypeTableRecord", "AcDbLinetypeTableRecord"),
            ("LoftedSurface", "AcDbLoftedSurface"),
            ("MInsertBlock", "AcDbMInsertBlock"),
            ("MLeader", "AcDbMLeader"),
            ("MLeaderStyle", "AcDbMLeaderStyle"),
            ("MPolygon", "AcDbMPolygon"),
            ("MText", "AcDbMText"),
            ("Mline", "AcDbMline"),
            ("MlineStyle", "AcDbMlineStyle"),
            ("NurbSurface", "AcDbNurbSurface"),
            ("ObjectContext", "AcDbObjectContext"),
            ("ObjectContextCollection", "AcDbObjectContextCollection"),
            ("ObjectContextManager", "AcDbObjectContextManager"),
            ("OrdinateDimension", "AcDbOrdinateDimension"),
            ("OsnapOverrule", "AcDbOsnapOverrule"),
            ("OsnapPointRef", "AcDbOsnapPointRef"),
            ("OverrulableEntity", "PyRxOverrulableEntity"),
            ("PdfDefinition", "AcDbPdfDefinition"),
            ("PdfReference", "AcDbPdfReference"),
            ("PlaneSurface", "AcDbPlaneSurface"),
            ("PlotSettings", "AcDbPlotSettings"),
            ("Point", "AcDbPoint"),
            ("Point3AngularDimension", "AcDb3PointAngularDimension"),
            ("PointRef", "AcDbPointRef"),
            ("PolyFaceMeshVertex", "AcDbPolyFaceMeshVertex"),
            ("PolygonMeshVertex", "AcDbPolygonMeshVertex"),
            ("Polyline", "AcDbPolyline"),
            ("Polyline2d", "AcDb2dPolyline"),
            ("Polyline3d", "AcDb3dPolyline"),
            ("Polyline3dVertex", "AcDb3dPolylineVertex"),
            ("Profile3d", "AcDb3dProfile"),
            ("RadialDimension", "AcDbRadialDimension"),
            ("RadialDimensionLarge", "AcDbRadialDimensionLarge"),
            ("RasterImage", "AcDbRasterImage"),
            ("RasterImageDef", "AcDbRasterImageDef"),
            ("RasterImageDefReactor", "AcDbRasterImageDefReactor"),
            ("Ray", "AcDbRay"),
            ("RegAppTable", "AcDbRegAppTable"),
            ("RegAppTableRecord", "AcDbRegAppTableRecord"),
            ("Region", "AcDbRegion"),
            ("RevolvedSurface", "AcDbRevolvedSurface"),
            ("RotatedDimension", "AcDbRotatedDimension"),
            ("Section", "AcDbSection"),
            ("SectionManager", "AcDbSectionManager"),
            ("SectionSettings", "AcDbSectionSettings"),
            ("Shape", "AcDbShape"),
            ("Solid", "AcDbSolid"),
            ("Solid3d", "AcDb3dSolid"),
            ("SortentsTable", "AcDbSortentsTable"),
            ("SpatialFilter", "AcDbSpatialFilter"),
            ("Spline", "AcDbSpline"),
            ("SubDMesh", "AcDbSubDMesh"),
            ("Surface", "AcDbSurface"),
            ("SweptSurface", "AcDbSweptSurface"),
            ("SymbolTable", "AcDbSymbolTable"),
            ("SymbolTableRecord", "AcDbSymbolTableRecord"),
            ("Table", "AcDbTable"),
            ("TableStyle", "AcDbTableStyle"),
            ("Text", "AcDbText"),
            ("TextStyleTable", "AcDbTextStyleTable"),
            ("TextStyleTableRecord", "AcDbTextStyleTableRecord"),
            ("Trace", "AcDbTrace"),
            ("Transaction", "AcTransaction"),
            ("TransactionManager", "AcDbTransactionManager"),
            ("UCSTable", "AcDbUCSTable"),
            ("UCSTableRecord", "AcDbUCSTableRecord"),
            ("UnderlayDefinition", "AcDbUnderlayDefinition"),
            ("UnderlayReference", "AcDbUnderlayReference"),
            ("Vertex", "AcDbVertex"),
            ("Vertex2d", "AcDb2dVertex"),
            ("ViewTable", "AcDbViewTable"),
            ("ViewTableRecord", "AcDbViewTableRecord"),
            ("Viewport", "AcDbViewport"),
            ("ViewportTable", "AcDbViewportTable"),
            ("ViewportTableRecord", "AcDbViewportTableRecord"),
            ("Wipeout", "AcDbWipeout"),
            ("Xline", "AcDbXline"),
            ("Xrecord", "AcDbXrecord"),

            # --- MOVED IN FROM test_acad_failure ---
            # These are isolated as individual test entries.
            # strict=True means if they accidentally PASS on ARX later, pytest flags it as a failure.
            pytest.param(
                "PointCloudColorMap", "AcDbPointCloudColorMap",
                marks=pytest.mark.xfail(condition=CURRENT_HOST == "ARX", reason="Known ARX issue", strict=True)
            ),
            pytest.param(
                "PointCloudDefEx", "AcDbPointCloudDefEx",
                marks=pytest.mark.xfail(condition=CURRENT_HOST == "ARX", reason="Known ARX issue", strict=True)
            ),
            pytest.param(
                "PointCloudEx", "AcDbPointCloudEx",
                marks=pytest.mark.xfail(condition=CURRENT_HOST == "ARX", reason="Known ARX issue", strict=True)
            ),
            pytest.param(
                "GeoMap", "AcDbGeoMap",
                marks=pytest.mark.xfail(condition=CURRENT_HOST == "ARX", reason="Known ARX issue", strict=True)
            ),
            
            # --- EXTENSION EXAMPLE ---
            # You can easily mark items for other CAD platform environments here:
            # pytest.param(
            #     "BricsCadBugClass", "AcDbBricsCadBugClass",
            #     marks=pytest.mark.xfail(condition=CURRENT_HOST == "BRX", reason="Known BRX issue", strict=True)
            # ),
        ],
    )
    def test_name(self, member, expected):
        # Special-case: LayoutManager uses isA() comparison on an instance
        if member == "LayoutManager":
            assert Db.LayoutManager().isA() == Db.LayoutManager.desc()
            return

        desc = getattr(Db, member)
        try:
            name = desc.desc().name()
        except TypeError:
            name = desc().desc().name()
        assert name == expected
