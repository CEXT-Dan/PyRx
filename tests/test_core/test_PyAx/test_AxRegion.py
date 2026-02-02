from __future__ import annotations

from pyrx import Ap, Ge


class TestAxRegion:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def test_explode(self):
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
        ents = regions[0].explode()
        assert len(ents) == 4
