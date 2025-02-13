from __future__ import annotations
import pytest

from pyrx import Ap, Ax, Ge


class TestAxDatabase:

    def test_getinstance(self):
        axApp = Ap.Application.acadApplication()
        axDoc = axApp.activeDocument()
        axDb = axDoc.database()
        assert axDb.className() == "AcadDatabase"

    def test_copyObjects(self):
        axApp = Ap.Application.acadApplication()
        axDoc = axApp.activeDocument()
        axDb = axDoc.database()
        acSpace = axDb.modelSpace()
        line1 = acSpace.addLine(Ge.Point3d(0, 0, 0), Ge.Point3d(10, 0, 0))
        line2 = acSpace.addLine(Ge.Point3d(0, 1, 0), Ge.Point3d(10, 1, 0))
        copies = axDb.copyObjects([line1, line2], acSpace)
        assert len(copies) == 2
        assert copies[0].objectName() == "AcDbLine"
        assert copies[1].objectName() == "AcDbLine"
