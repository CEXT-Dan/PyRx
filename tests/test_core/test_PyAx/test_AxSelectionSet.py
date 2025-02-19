from __future__ import annotations
import pytest
from tests import MEDIA_DIR
from pyrx import Ap, Ge, Db, Ax, Ed


def makeEnts(axDoc):
    axSpace = axDoc.modelSpace()
    for idx1 in range(1, 49):
        for idx2 in range(1, 49):
            axSpace.addPoint(Ge.Point3d(idx1, idx2, 0))
    for idx1 in range(1, 49):
        axSpace.addLine(Ge.Point3d(1, idx1, 0), Ge.Point3d(10, idx1, 0))

class TestAxSelectionSet:
    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()
        makeEnts(self.axDoc)
        self.axApp.zoomExtents()

    def test_sscount(self):
        axSets = self.axDoc.selectionSets()
        sscount = axSets.count()  # brx has in not zero?
        axSet = axSets.add("PYRX1")
        assert axSets.count() == sscount + 1
        axSet.delete()
        assert axSets.count() == sscount

    def test_selectAllFilter(self):
        axSets = self.axDoc.selectionSets()
        axSet = axSets.add("PYRX2")
        axSet.selectAll([(0, "POINT")])
        count = axSet.count()
        cnt1 = 0
        for ent in axSet.entities():
            cnt1 += 1
        cnt2 = 0
        for ent in axSet:
            cnt2 += 1
        ent: Ax.AcadEntity
        for ent in axSet:
            assert ent.objectName() == "AcDbPoint"
        axSet.delete()
        assert count >= 2304
        assert cnt1 >= 2304
        assert cnt2 >= 2304

    def test_selectWindowlFilter(self):
        axSets = self.axDoc.selectionSets()
        axSet = axSets.add("PYRX3")
        ll = Ge.Point3d(0, 0, 0)
        ur = Ge.Point3d(100, 100, 0)
        axSet.selectWindow(ll, ur, [(0, "LINE")])
        count = axSet.count()
        cnt1 = 0
        for ent in axSet.entities():
            cnt1 += 1
        cnt2 = 0
        for ent in axSet:
            cnt2 += 1
        ent: Ax.AcadEntity
        for ent in axSet:
            assert ent.objectName() == "AcDbLine"
        axSet.delete()
        assert count >= 48
        assert cnt1 >= 48
        assert cnt2 >= 48
