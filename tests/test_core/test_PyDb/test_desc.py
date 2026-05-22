from __future__ import annotations
import pytest
from pyrx import Db, Ap


def getHostName():
    """Returns ARX, BRX, ZRX, etc. based on the running CAD engine application context."""
    try:
        host = Ap.Application.hostAPI()
        return host[:3].upper()
    except Exception:
        # Fallback to ARX if evaluated outside a running CAD environment (e.g. IDE parse)
        return "ARX"


# Determine the runtime platform environment instantly on collection
CURRENT_HOST = getHostName()


class TestDesc:
    @pytest.mark.parametrize(
        "member, expected",
        [
            ("AbstractViewTable", "AcDbAbstractViewTable"),
            ("AbstractViewTableRecord", "AcDbAbstractViewTableRecord"),
            ("AlignedDimension", "AcDbAlignedDimension"),
            ("AnnotationScale", "AcDbAnnotationScale"),
            ("Arc", "AcDbArc"),
            ("ArcDimension", "AcDbArcDimension"),
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
            ("PolyFaceMeshVertex", "AcDbPolyFaceMeshVertex"),
            ("PolygonMeshVertex", "AcDbPolygonMeshVertex"),
            ("Polyline", "AcDbPolyline"),
            ("Polyline2d", "AcDb2dPolyline"),
            ("Polyline3d", "AcDb3dPolyline"),
            ("Polyline3dVertex", "AcDb3dPolylineVertex"),
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
            # --- DYNAMICALLY FLAGGED KNOWN FAILURES (via test_acad_failure) ---
            # Using pytest.param maps each assertion to its own independent item.
            # strict=True turns unexpected passes (XPASS) into failures to keep you updated.
            pytest.param(
                "PointCloudColorMap",
                "AcDbPointCloudColorMap",
                marks=pytest.mark.xfail(
                    condition=CURRENT_HOST in ["ARX", "BRX"], reason="Known issue", strict=True
                ),
            ),
            pytest.param(
                "PointCloudDefEx",
                "AcDbPointCloudDefEx",
                marks=pytest.mark.xfail(
                    condition=CURRENT_HOST in ["ARX", "BRX"], reason="Known issue", strict=True
                ),
            ),
            pytest.param(
                "PointCloudEx",
                "AcDbPointCloudEx",
                marks=pytest.mark.xfail(
                    condition=CURRENT_HOST in ["ARX", "BRX"], reason="Known issue", strict=True
                ),
            ),
            pytest.param(
                "GeoMap",
                "AcDbGeoMap",
                marks=pytest.mark.xfail(
                    condition=CURRENT_HOST in ["ARX", "BRX"], reason="Known issue", strict=True
                ),
            ),
            pytest.param(
                "PointRef",
                "AcDbPointRef",
                marks=pytest.mark.xfail(
                    condition=CURRENT_HOST in ["BRX"], reason="Known issue", strict=True
                ),
            ),
            pytest.param(
                "Profile3d",
                "AcDb3dProfile",
                marks=pytest.mark.xfail(
                    condition=CURRENT_HOST in ["BRX", "GRX", "ZRX"],
                    reason="Known issue",
                    strict=True,
                ),
            ),
            pytest.param(
                "AssocPersSubentIdPE",
                "AcDbAssocPersSubentIdPE",
                marks=pytest.mark.xfail(
                    condition=CURRENT_HOST in ["ZRX"], reason="Known issue", strict=True
                ),
            ),
            pytest.param(
                "JoinEntityPE",
                "AcDbJoinEntityPE",
                marks=pytest.mark.xfail(
                    condition=CURRENT_HOST in ["GRX", "ZRX"], reason="Known issue", strict=True
                ),
            ),
            pytest.param(
                "NurbSurface",
                "AcDbNurbSurface",
                marks=pytest.mark.xfail(
                    condition=CURRENT_HOST in ["GRX", "ZRX"], reason="Known issue", strict=True
                ),
            ),
            pytest.param(
                "AcValue",
                "AcValue",
                marks=pytest.mark.xfail(
                    condition=CURRENT_HOST in ["GRX"], reason="Known issue", strict=True
                ),
            ),
            pytest.param(
                "EntityHyperlinkPE",
                "AcDbEntityHyperlinkPE",
                marks=pytest.mark.xfail(
                    condition=CURRENT_HOST in ["GRX"], reason="Known issue", strict=True
                ),
            ),
        ],
    )
    def test_name(self, member, expected):
        # Special-case: LayoutManager uses isA() comparison on an instance
        if member == "LayoutManager":
            if CURRENT_HOST in ["ZRX", "GRX"]:
                return  # oof
            assert Db.LayoutManager().isA() == Db.LayoutManager.desc()
            return

        desc = getattr(Db, member)
        try:
            name = desc.desc().name()
        except TypeError:
            name = desc().desc().name()
        assert name == expected
