from __future__ import annotations
import pytest
from tests import HOST
from pyrx import Ap, Ge, Ax


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

    def test_addArc(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addArc(Ge.Point3d(0, 0, 0), 5, 10, 230)
        assert ent.objectName() == "AcDbArc"

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
        
    def test_addBox(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addBox(Ge.Point3d(0, 0, 0), 100, 200, 300)
        assert ent.objectName() == "AcDb3dSolid"
        
    def test_addCircle(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addCircle(Ge.Point3d(0, 0, 0), 100)
        assert ent.objectName() == "AcDbCircle"
        
    def test_addCone(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addCone(Ge.Point3d(0, 0, 0), 100, 100)
        assert ent.objectName() == "AcDb3dSolid"
        
    def test_addCylinder(self):
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addCylinder(Ge.Point3d(0, 0, 0), 100, 100)
        assert ent.objectName() == "AcDb3dSolid"
