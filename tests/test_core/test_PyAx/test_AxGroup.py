from __future__ import annotations

import pytest

from pyrx import Ap, Ax, Ge


def _split_list(a_list):
    half = len(a_list) // 2
    return a_list[:half], a_list[half:]


class TestAxGroup:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def _add_points(self, n: int) -> list[Ax.AcadEntity]:
        axModel = self.axDoc.modelSpace()
        return [axModel.addPoint(Ge.Point3d(i, i, 0)) for i in range(n)]

    def _make_group(self, name: str, n: int = 10) -> tuple[Ax.AcadGroup, list[Ax.AcadEntity]]:
        points = self._add_points(n)
        group = self.axDoc.groups().add(name)
        group.appendItems(points)
        return group, points

    # --- static / class methods ---

    def test_className(self):
        assert Ax.AcadGroup.className() == "AcadGroup"

    def test_init_raises(self):
        with pytest.raises(Exception):
            Ax.AcadGroup()

    # --- name ---

    def test_name(self):
        group, _ = self._make_group("axgroup_name", 1)
        assert group.name() == "axgroup_name"

    def test_setName(self):
        group, _ = self._make_group("axgroup_rename_old", 1)
        group.setName("axgroup_rename_new")
        assert group.name() == "axgroup_rename_new"

    # --- count ---

    def test_count(self):
        group, _ = self._make_group("axgroup_count", 10)
        assert group.count() == 10

    def test_count_empty(self):
        group = self.axDoc.groups().add("axgroup_count_empty")
        assert group.count() == 0

    # --- appendItems ---

    def test_appendItems(self):
        group, _ = self._make_group("axgroup_append", 5)
        assert group.count() == 5
        more = self._add_points(5)
        group.appendItems(more)
        assert group.count() == 10

    # --- removeItems ---

    def test_removeItems(self):
        group, points = self._make_group("axgroup_remove", 10)
        left, _ = _split_list(points)
        group.removeItems(left)
        assert group.count() == 5

    # --- item / items / __getitem__ / __iter__ ---

    def test_item(self):
        group, _ = self._make_group("axgroup_item", 10)
        ent = group.item(0)
        assert ent.objectName() == "AcDbPoint"

    def test_item_out_of_range(self):
        group, _ = self._make_group("axgroup_item_oob", 10)
        with pytest.raises(IndexError):
            group.item(group.count())

    def test_getitem(self):
        group, _ = self._make_group("axgroup_getitem", 10)
        ent = group[0]
        assert ent.objectName() == "AcDbPoint"

    def test_getitem_out_of_range(self):
        group, _ = self._make_group("axgroup_getitem_oob", 10)
        with pytest.raises(IndexError):
            group[group.count()]

    def test_items(self):
        group, _ = self._make_group("axgroup_items", 10)
        items = group.items()
        assert len(items) == 10
        assert all(e.objectName() == "AcDbPoint" for e in items)

    def test_iter(self):
        group, _ = self._make_group("axgroup_iter", 10)
        ents = [e for e in group]
        assert len(ents) == 10
        assert all(e.objectName() == "AcDbPoint" for e in ents)

    # --- cast ---

    def test_cast(self):
        group, _ = self._make_group("axgroup_cast", 1)
        casted = Ax.AcadGroup.cast(group)
        assert casted.name() == "axgroup_cast"

    # --- property setters (verify on entities) ---

    def test_setLayer(self):
        self.axDoc.layers().add("axgroup_layer")
        group, _ = self._make_group("axgroup_setlayer", 3)
        group.setLayer("axgroup_layer")
        for ent in group:
            assert ent.layer() == "axgroup_layer"

    def test_setLinetype(self):
        group, _ = self._make_group("axgroup_setlinetype", 3)
        group.setLinetype("Continuous")
        for ent in group:
            assert ent.linetype() == "Continuous"

    def test_setLinetypeScale(self):
        group, _ = self._make_group("axgroup_setscale", 3)
        group.setLinetypeScale(2.5)
        for ent in group:
            assert ent.linetypeScale() == 2.5

    def test_setTrueColor(self):
        group, _ = self._make_group("axgroup_settruecolor", 3)
        axColor = Ax.AcadAcCmColor(255, 0, 0)
        group.setTrueColor(axColor)
        for ent in group:
            tc = ent.trueColor()
            assert tc.red() == 255
            assert tc.green() == 0
            assert tc.blue() == 0

    def test_setVisible(self):
        group, _ = self._make_group("axgroup_setvisible", 3)
        group.setVisible(False)
        for ent in group:
            assert ent.isVisible() is False
        group.setVisible(True)
        for ent in group:
            assert ent.isVisible() is True

    def test_setColor(self):
        group, _ = self._make_group("axgroup_setcolor", 3)
        group.setColor(Ax.AcColor.acRed)
        for ent in group:
            assert ent.color() == Ax.AcColor.acRed

    def test_setLineWeight(self):
        group, _ = self._make_group("axgroup_setlw", 3)
        group.setLineWeight(Ax.AcLineWeight.acLnWt070)
        for ent in group:
            assert ent.lineweight() == Ax.AcLineWeight.acLnWt070

    # --- highlight / update ---

    def test_highlight(self):
        group, _ = self._make_group("axgroup_highlight", 3)
        group.highlight(True)
        group.highlight(False)

    def test_update(self):
        group, _ = self._make_group("axgroup_update", 3)
        group.update()

    # --- the original known-failure test ---

    @pytest.mark.known_failure_IRX
    @pytest.mark.known_failure_GRX
    def test_add_remove(self):
        points = self._add_points(10)
        group = self.axDoc.groups().add("WOOHOO")
        group.appendItems(points)
        assert len(group.items()) == 10
        pleft, _ = _split_list(points)
        group.removeItems(pleft)
        assert len(group.items()) == 5
