from __future__ import annotations

import pytest

from pyrx import Ap, Ge


def makeEnts(axDoc):
    axSpace = axDoc.modelSpace()
    for idx1 in range(1, 49):
        for idx2 in range(1, 49):
            axSpace.addPoint(Ge.Point3d(idx1, idx2, 0))
    for idx1 in range(1, 49):
        axSpace.addLine(Ge.Point3d(1, idx1, 0), Ge.Point3d(10, idx1, 0))


@pytest.mark.known_failure_GRX
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
        for _ent in axSet.entities():
            cnt1 += 1
        cnt2 = 0
        for _ent in axSet:
            cnt2 += 1
        for ent in axSet:
            assert ent.objectName() == "AcDbPoint"
        axSet.delete()
        assert count >= 2304
        assert cnt1 >= 2304
        assert cnt2 >= 2304

    def test_selectWindowFilter(self):
        axSets = self.axDoc.selectionSets()
        axSet = axSets.add("PYRX3")
        ll = Ge.Point3d(0, 0, 0)
        ur = Ge.Point3d(100, 100, 0)
        axSet.selectWindow(ll, ur, [(0, "LINE")])
        count = axSet.count()
        cnt1 = 0
        for _ent in axSet.entities():
            cnt1 += 1
        cnt2 = 0
        for _ent in axSet:
            cnt2 += 1
        for ent in axSet:
            assert ent.objectName() == "AcDbLine"
        axSet.delete()
        assert count >= 48
        assert cnt1 >= 48
        assert cnt2 >= 48

    def test_selectCrossingFilter(self):
        axSets = self.axDoc.selectionSets()
        axSet = axSets.add("PYRX3")
        ll = Ge.Point3d(0, 0, 0)
        ur = Ge.Point3d(100, 100, 0)
        axSet.selectCrossing(ll, ur, [(0, "LINE")])
        count = axSet.count()
        cnt1 = 0
        for _ent in axSet.entities():
            cnt1 += 1
        cnt2 = 0
        for _ent in axSet:
            cnt2 += 1
        for ent in axSet:
            assert ent.objectName() == "AcDbLine"
        axSet.delete()
        assert count >= 48
        assert cnt1 >= 48
        assert cnt2 >= 48

    def test_selectFenceFilter(self):
        axSets = self.axDoc.selectionSets()
        axSet = axSets.add("PYRX3")
        filter = [(0, "LINE")]
        fence = [Ge.Point3d(5, 0, 0), Ge.Point3d(5, 100, 0)]
        axSet.selectFence(fence, filter)
        count = axSet.count()
        cnt1 = 0
        for _ent in axSet.entities():
            cnt1 += 1
        cnt2 = 0
        for _ent in axSet:
            cnt2 += 1
        for ent in axSet:
            assert ent.objectName() == "AcDbLine"
        axSet.delete()
        assert count >= 48
        assert cnt1 >= 48
        assert cnt2 >= 48

    def test_selectWindowPolygonFilter(self):
        axSets = self.axDoc.selectionSets()
        axSet = axSets.add("PYRX4")
        filter = [(0, "LINE")]
        poly = [
            Ge.Point3d(0, 0, 0),
            Ge.Point3d(0, 100, 0),
            Ge.Point3d(100, 100, 0),
            Ge.Point3d(100, 0, 0),
        ]
        axSet.selectWindowPolygon(poly, filter)
        count = axSet.count()
        cnt1 = 0
        for _ent in axSet.entities():
            cnt1 += 1
        cnt2 = 0
        for _ent in axSet:
            cnt2 += 1
        for ent in axSet:
            assert ent.objectName() == "AcDbLine"
        axSet.delete()
        assert count >= 48
        assert cnt1 >= 48
        assert cnt2 >= 48

    def test_selectCrossingPolygonFilter(self):
        axSets = self.axDoc.selectionSets()
        axSet = axSets.add("PYRX5")
        filter = [(0, "LINE")]
        poly = [
            Ge.Point3d(0, 0, 0),
            Ge.Point3d(0, 100, 0),
            Ge.Point3d(100, 100, 0),
            Ge.Point3d(100, 0, 0),
        ]
        axSet.selectCrossingPolygon(poly, filter)
        count = axSet.count()
        cnt1 = 0
        for _ent in axSet.entities():
            cnt1 += 1
        cnt2 = 0
        for _ent in axSet:
            cnt2 += 1
        for ent in axSet:
            assert ent.objectName() == "AcDbLine"
        assert axSet.name() == "PYRX5"
        axSet.delete()
        assert count >= 48
        assert cnt1 >= 48
        assert cnt2 >= 48

    def test_select_add_remove(self):
        axSpace = self.axDoc.modelSpace()
        line1 = axSpace.addLine(Ge.Point3d(0, 0, 0), Ge.Point3d(0, 100, 0))
        line2 = axSpace.addLine(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 0, 0))
        axSets = self.axDoc.selectionSets()
        axSet = axSets.add("PYRX6")
        assert axSet.name() == "PYRX6"
        axSet.addItems([line1, line2])
        assert axSet.count() == 2
        axSet.removeItems([line1, line2])
        assert axSet.count() == 0
        axSet.delete()
