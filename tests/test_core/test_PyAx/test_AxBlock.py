from __future__ import annotations

from pyrx import Ap, Ax, Ge
from tests import MEDIA_DIR


# modelspace is derived from Block
class TestAxBlock:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def test_add3DFace(self):
        pnts = [
            Ge.Point3d(0, 0, 0),
            Ge.Point3d(100, 0, 0),
            Ge.Point3d(100, 100, 0),
            Ge.Point3d(0, 100, 0),
        ]
        axSpace = self.axDoc.modelSpace()
        face = axSpace.add3DFace(pnts[0], pnts[1], pnts[2], pnts[3])
        assert face.objectName() == "AcDbFace"
        assert face.entityType() == Ax.AcEntityName.ac3dFace

    def test_add3DMesh(self):
        pnts = [
            Ge.Point3d(0, 0, 0),
            Ge.Point3d(2, 0, 1),
            Ge.Point3d(4, 0, 0),
            Ge.Point3d(6, 0, 1),
            Ge.Point3d(0, 2, 0),
            Ge.Point3d(2, 2, 1),
            Ge.Point3d(4, 2, 0),
            Ge.Point3d(6, 2, 1),
            Ge.Point3d(0, 4, 0),
            Ge.Point3d(2, 4, 1),
            Ge.Point3d(4, 4, 0),
            Ge.Point3d(6, 4, 1),
            Ge.Point3d(0, 6, 0),
            Ge.Point3d(2, 6, 1),
            Ge.Point3d(4, 6, 0),
            Ge.Point3d(6, 6, 1),
        ]
        axSpace = self.axDoc.modelSpace()
        mesh = axSpace.add3DMesh(4, 4, pnts)
        assert mesh.objectName() == "AcDbPolygonMesh"
        assert mesh.entityType() == Ax.AcEntityName.acPolygonMesh

    def test_add3DPoly(self):
        pnts = [
            Ge.Point3d(0, 0, 0),
            Ge.Point3d(100, 0, 0),
            Ge.Point3d(100, 100, 0),
            Ge.Point3d(0, 100, 0),
        ]
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.add3DPoly(pnts)
        assert ent.objectName() == "AcDb3dPolyline"
        assert ent.entityType() == Ax.AcEntityName.ac3dPolyline

    def test_addArc(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addArc(Ge.Point3d(0, 0, 0), 5, 10, 230)
        assert ent.objectName() == "AcDbArc"
        assert ent.entityType() == Ax.AcEntityName.acArc

    def test_addAttribute(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addAttribute(
            1,
            Ax.AcAttributeMode.acAttributeModeVerify,
            "New Prompt",
            Ge.Point3d(0, 5, 0),
            "NEW_TAG",
            "New Value",
        )
        assert ent.objectName() == "AcDbAttributeDefinition"
        assert ent.entityType() == Ax.AcEntityName.acAttribute

    def test_addBox(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addBox(Ge.Point3d(0, 0, 0), 100, 200, 300)
        assert ent.objectName() == "AcDb3dSolid"
        assert ent.entityType() == Ax.AcEntityName.ac3dSolid

    def test_addCircle(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addCircle(Ge.Point3d(0, 0, 0), 100)
        assert ent.objectName() == "AcDbCircle"
        assert ent.entityType() == Ax.AcEntityName.acCircle

    def test_addCone(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addCone(Ge.Point3d(0, 0, 0), 100, 100)
        assert ent.objectName() == "AcDb3dSolid"
        assert ent.entityType() == Ax.AcEntityName.ac3dSolid

    def test_addCylinder(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addCylinder(Ge.Point3d(0, 0, 0), 100, 100)
        assert ent.objectName() == "AcDb3dSolid"
        assert ent.entityType() == Ax.AcEntityName.ac3dSolid

    def test_addDimAligned(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addDimAligned(
            Ge.Point3d(0, 0, 0), Ge.Point3d(100, 0, 0), Ge.Point3d(50, 10, 0)
        )
        assert ent.objectName() == "AcDbAlignedDimension"
        assert ent.entityType() == Ax.AcEntityName.acDimAligned

    def test_addDimAngular(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addDimAngular(
            Ge.Point3d(0, 5, 0),
            Ge.Point3d(1, 7, 0),
            Ge.Point3d(1, 3, 0),
            Ge.Point3d(3, 5, 0),
        )
        assert ent.objectName() == "AcDb2LineAngularDimension"
        assert ent.entityType() == Ax.AcEntityName.acDimAngular

    def test_addDim3PointAngular(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addDim3PointAngular(
            Ge.Point3d(0, 5, 0),
            Ge.Point3d(1, 7, 0),
            Ge.Point3d(1, 3, 0),
            Ge.Point3d(3, 5, 0),
        )
        assert ent.objectName() == "AcDb3PointAngularDimension"
        assert ent.entityType() == Ax.AcEntityName.acDim3PointAngular

    def test_addDimDiametric(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addDimDiametric(Ge.Point3d(5, 3, 0), Ge.Point3d(5, 5, 0), 1)
        assert ent.objectName() == "AcDbDiametricDimension"
        assert ent.entityType() == Ax.AcEntityName.acDimDiametric

    def test_addDimRotated(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addDimRotated(
            Ge.Point3d(0, 5, 0), Ge.Point3d(5, 5, 0), Ge.Point3d(0, 0, 0), 2.094
        )
        assert ent.objectName() == "AcDbRotatedDimension"
        assert ent.entityType() == Ax.AcEntityName.acDimRotated
        
    def test_addDimOrdinate(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addDimOrdinate(Ge.Point3d(0, 5, 0), Ge.Point3d(10, 5, 0), 5)
        assert ent.objectName() == "AcDbOrdinateDimension"
        assert ent.entityType() == Ax.AcEntityName.acDimOrdinate

    def test_addDimRadial(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addDimRadial(Ge.Point3d(0, 0, 0), Ge.Point3d(5, 5, 0), 5)
        assert ent.objectName() == "AcDbRadialDimension"
        assert ent.entityType() == Ax.AcEntityName.acDimRadial

    def test_addEllipse(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addEllipse(Ge.Point3d(5, 5, 0), Ge.Vector3d(10, 20, 0), 0.3)
        assert ent.objectName() == "AcDbEllipse"
        assert ent.entityType() == Ax.AcEntityName.acEllipse

    def test_addEllipticalCone(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addEllipticalCone(Ge.Point3d(5, 5, 0), 10, 5, 20)
        assert ent.objectName() == "AcDb3dSolid"
        assert ent.entityType() == Ax.AcEntityName.ac3dSolid

    def test_addEllipticalCylinder(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addEllipticalCylinder(Ge.Point3d(5, 5, 0), 10, 5, 20)
        assert ent.objectName() == "AcDb3dSolid"
        assert ent.entityType() == Ax.AcEntityName.ac3dSolid

    def test_addMText(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addMText(Ge.Point3d(0, 0, 0), 1, "YOLO")
        assert ent.objectName() == "AcDbMText"
        assert ent.entityType() == Ax.AcEntityName.acMtext

    def test_addLeader(self):
        axSpace = self.axDoc.modelSpace()
        anno = axSpace.addMText(Ge.Point3d(4, 5, 0), 1, "YOLO")
        pnts = [Ge.Point3d(0, 0, 0), Ge.Point3d(4, 4, 0), Ge.Point3d(4, 5, 0)]
        ent = axSpace.addLeader(pnts, anno, Ax.AcLeaderType.acSplineWithArrow)
        assert ent.objectName() == "AcDbLeader"
        assert ent.entityType() == Ax.AcEntityName.acLeader

    def test_addPoint(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addPoint(Ge.Point3d(0, 0, 0))
        assert ent.objectName() == "AcDbPoint"
        assert ent.entityType() == Ax.AcEntityName.acPoint

    def test_addLightWeightPolyline(self):
        axSpace = self.axDoc.modelSpace()
        pnts = [Ge.Point2d(0, 5), Ge.Point2d(1, 7), Ge.Point2d(1, 3), Ge.Point2d(3, 5)]
        ent = axSpace.addLightWeightPolyline(pnts)
        assert ent.objectName() == "AcDbPolyline"
        assert ent.entityType() == Ax.AcEntityName.acPolylineLight

    def test_addPolyline(self):
        axSpace = self.axDoc.modelSpace()
        pnts = [
            Ge.Point3d(0, 5, 0),
            Ge.Point3d(1, 7, 0),
            Ge.Point3d(1, 3, 0),
            Ge.Point3d(3, 5, 0),
        ]
        ent = axSpace.addPolyline(pnts)
        assert ent.objectName() == "AcDb2dPolyline"
        assert ent.entityType() == Ax.AcEntityName.acPolyline2d


    def test_addRay(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addRay(Ge.Point3d(5, 3, 0), Ge.Point3d(5, 5, 0))
        assert ent.objectName() == "AcDbRay"
        assert ent.entityType() == Ax.AcEntityName.acRay

    def test_addRegion(self):
        axSpace = self.axDoc.modelSpace()
        pnts = [
            Ge.Point2d(0, 0),
            Ge.Point2d(0, 1),
            Ge.Point2d(1, 1),
            Ge.Point2d(1, 0),
            Ge.Point2d(0, 0),
        ]
        regions = axSpace.addRegion([axSpace.addLightWeightPolyline(pnts)])
        assert len(regions) != 0
        assert regions[0].objectName() == "AcDbRegion"
        assert regions[0].entityType() == Ax.AcEntityName.acRegion
        

    def test_addSpline(self):
        axSpace = self.axDoc.modelSpace()
        pnts = [Ge.Point3d(1, 1, 0), Ge.Point3d(5, 5, 0), Ge.Point3d(10, 0, 0)]
        ent = axSpace.addSpline(
            pnts, Ge.Vector3d(0.5, 0.5, 0), Ge.Vector3d(0.5, 0.5, 0)
        )
        assert ent.objectName() == "AcDbSpline"
        assert ent.entityType() == Ax.AcEntityName.acSpline

    def test_addText(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addText("YOLO", Ge.Point3d(0.5, 0.5, 0), 1)
        assert ent.objectName() == "AcDbText"
        assert int(ent.entityType()) == int(Ax.AcEntityName.acText)

    def test_addTolerance(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addTolerance("YOLO", Ge.Point3d(0.5, 0.5, 0), Ge.Vector3d.kXAxis)
        assert ent.objectName() == "AcDbFcf"
        assert ent.entityType() == Ax.AcEntityName.acTolerance

    def test_insertBlock(self):
        axSpace = self.axDoc.modelSpace()
        blockPath = str(MEDIA_DIR / "18X36RP.dwg")
        ent = axSpace.insertBlock(
            Ge.Point3d(0, 0, 0), blockPath, Ge.Scale3d(1, 1, 1), 0
        )
        assert ent.objectName() == "AcDbBlockReference"
        assert ent.entityType() == Ax.AcEntityName.acBlockReference

    def test_addHatch(self):
        axSpace = self.axDoc.modelSpace()
        outerloop = axSpace.addCircle(Ge.Point3d.kOrigin, 10)
        hatch = axSpace.addHatch(
            Ax.acHatchPatternTypePreDefined,
            "SOLID",
            True,
            Ax.AcHatchObjectType.acHatchObject,
        )
        hatch.appendOuterLoop([outerloop])
        assert hatch.objectName() == "AcDbHatch"
        assert hatch.entityType() == Ax.AcEntityName.acHatch

    def test_addRaster(self):
        axSpace = self.axDoc.modelSpace()
        rasterPath = str(MEDIA_DIR / "rastertest.jpg")
        ent = axSpace.addRaster(rasterPath, Ge.Point3d.kOrigin, 1, 0)
        assert ent.objectName() == "AcDbRasterImage"
        assert ent.entityType() == Ax.AcEntityName.acRaster

    def test_addLine(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addLine(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 0, 0))
        assert ent.objectName() == "AcDbLine"
        assert ent.entityType() == Ax.AcEntityName.acLine

    def test_addPolyfaceMesh(self):
        axSpace = self.axDoc.modelSpace()
        pnts = [
            Ge.Point3d(4, 7, 0),
            Ge.Point3d(5, 7, 0),
            Ge.Point3d(6, 7, 0),
            Ge.Point3d(4, 6, 0),
            Ge.Point3d(5, 6, 0),
            Ge.Point3d(6, 6, 1),
        ]
        faces = [1, 2, 5, 4, 2, 3, 6, 5]
        ent = axSpace.addPolyfaceMesh(pnts, faces)
        assert ent.objectName() == "AcDbPolyFaceMesh"
        assert ent.entityType() == Ax.AcEntityName.acPolyfaceMesh

    def test_addMLine(self):
        axSpace = self.axDoc.modelSpace()
        pnts = [
            Ge.Point3d(0, 5, 0),
            Ge.Point3d(1, 7, 0),
            Ge.Point3d(1, 3, 0),
            Ge.Point3d(3, 5, 0),
        ]
        ent = axSpace.addMLine(pnts)
        assert ent.objectName() == "AcDbMline"
        assert ent.entityType() == Ax.AcEntityName.acMline

    def test_attachExternalReference(self):
        axSpace = self.axDoc.modelSpace()
        blockPath = str(MEDIA_DIR / "18X36RP.dwg")
        ent = axSpace.attachExternalReference(
            blockPath, "myxref", Ge.Point3d(0, 0, 0), Ge.Scale3d(1, 1, 1), 0, True
        )
        assert ent.objectName() == "AcDbBlockReference"
        assert ent.entityType() == Ax.AcEntityName.acBlockReference

    def test_addTable(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addTable(Ge.Point3d(0, 0, 0), 5, 5, 5, 5)
        assert ent.objectName() == "AcDbTable"
        assert ent.entityType() == Ax.AcEntityName.acTable

    def test_addSection(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addSection(
            Ge.Point3d(0, 0, 0), Ge.Point3d(100, 100, 0), Ge.Vector3d.kZAxis
        )
        assert ent.objectName() == "AcDbSection"
        assert int(ent.entityType()) == int(Ax.AcEntityName.acSection)

    def test_addMLeader(self):
        axSpace = self.axDoc.modelSpace()

        pnts = [
            Ge.Point3d(1, 1, 0),
            Ge.Point3d(1, 2, 0),
            Ge.Point3d(2, 2, 0),
            Ge.Point3d(3, 2, 0),
            Ge.Point3d(4, 4, 0),
        ]
        ent = axSpace.addMLeader(pnts)
        assert ent.objectName() == "AcDbMLeader"
        assert ent.entityType() == Ax.AcEntityName.acMLeader
