from __future__ import annotations

import pytest

from pyrx import Ap, Ax, Ge


class TestAxEntity:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def test_trueColore(self):
        axSpace = self.axDoc.modelSpace()
        axColor = Ax.AcadAcCmColor(100, 100, 100)
        ent = axSpace.addLine(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 0, 0))
        ent.setTrueColor(axColor)
        axColor2 = ent.trueColor()
        assert axColor.red() == axColor2.red()
        assert axColor.green() == axColor2.green()
        assert axColor.blue() == axColor2.blue()

    @pytest.mark.known_failure_IRX
    def test_intersectWith(self):
        axSpace = self.axDoc.modelSpace()
        axLine1 = axSpace.addLine(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 100, 0))
        axLine2 = axSpace.addLine(Ge.Point3d(100, 0, 0), Ge.Point3d(0, 100, 0))
        axCircle = axSpace.addCircle(Ge.Point3d(50, 50, 0), 50)
        inters1 = axLine1.intersectWith(axLine2, Ax.AcExtendOption.acExtendNone)
        inters2 = axLine1.intersectWith(axCircle, Ax.AcExtendOption.acExtendNone)
        inters3 = axLine2.intersectWith(axCircle, Ax.AcExtendOption.acExtendNone)
        assert len(inters1) == 1
        assert inters1[0] == Ge.Point3d(50, 50, 0)
        assert len(inters2) == 2
        assert len(inters3) == 2
        assert inters2[0].distanceTo(inters2[1]) == 100.0
        assert inters3[0].distanceTo(inters3[1]) == 100.0

    @pytest.mark.known_failure_ZRX
    @pytest.mark.known_failure_GRX
    def test_arrayPolar(self):
        axSpace = self.axDoc.modelSpace()
        axEnt = axSpace.addCircle(Ge.Point3d(2, 2, 0), 1)
        axEnts: list[Ax.AcadEntity]
        axEnts = axEnt.arrayPolar(4, 3.14, Ge.Point3d(3, 3, 0))
        assert len(axEnts) == 3

    def test_layer(self):
        axSpace = self.axDoc.modelSpace()
        line = axSpace.addLine(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 0, 0))
        original_layer = line.layer()
        assert original_layer is not None
        line.setLayer("0")
        assert line.layer() == "0"

    def test_linetype(self):
        axSpace = self.axDoc.modelSpace()
        line = axSpace.addLine(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 0, 0))
        original_linetype = line.linetype()
        assert original_linetype is not None
        line.setLinetype("Continuous")
        assert line.linetype() == "Continuous"

    def test_lineweight(self):
        axSpace = self.axDoc.modelSpace()
        line = axSpace.addLine(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 0, 0))
        original_weight = line.lineweight()
        assert original_weight is not None
        line.setLineweight(Ax.AcLineWeight.acLnWt070)
        assert line.lineweight() == Ax.AcLineWeight.acLnWt070

    def test_entity_handle(self):
        axSpace = self.axDoc.modelSpace()
        line = axSpace.addLine(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 0, 0))
        handle = line.handle()
        assert handle is not None
        assert len(handle.toString()) > 0

    def test_entity_id(self):
        axSpace = self.axDoc.modelSpace()
        line = axSpace.addLine(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 0, 0))
        ename = line.objectId()
        assert ename.isNull() is False

    def test_copy(self):
        axSpace = self.axDoc.modelSpace()
        line = axSpace.addLine(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 0, 0))
        initial_count = axSpace.count()
        copied_line = line.copy()
        assert copied_line is not None
        assert axSpace.count() == initial_count + 1

    @pytest.mark.known_failure_IRX
    def test_entity_deletion(self):
        axSpace = self.axDoc.modelSpace()
        line = axSpace.addLine(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 0, 0))
        initial_count = axSpace.count()
        line.erase()
        assert axSpace.count() == initial_count - 1

    def test_get_bounding_box(self):
        axSpace = self.axDoc.modelSpace()
        line = axSpace.addLine(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 100, 0))
        minpoint, maxpoint = line.boundingBox()
        assert minpoint == Ge.Point3d(0, 0, 0)
        assert maxpoint == Ge.Point3d(100, 100, 0)
        assert isinstance(minpoint, Ge.Point3d)
        assert isinstance(maxpoint, Ge.Point3d)

    def test_offset(self):
        axSpace = self.axDoc.modelSpace()
        line = axSpace.addLine(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 0, 0))
        offset_entities = line.offset(10)
        assert len(offset_entities) > 0

    def test_highlight(self):
        axSpace = self.axDoc.modelSpace()
        line = axSpace.addLine(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 0, 0))
        line.highlight(True)
        line.highlight(False)

    def test_entity_visible(self):
        axSpace = self.axDoc.modelSpace()
        line = axSpace.addLine(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 0, 0))
        original_visible = line.isVisible()
        assert isinstance(original_visible, bool)
        line.setVisible(False)
        assert line.isVisible() == False
        line.setVisible(True)
        assert line.isVisible() == True
