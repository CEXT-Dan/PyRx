from __future__ import annotations

import pytest

from pyrx import Ap, Ax


class TestAxLayout:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def _add_layout(self, name: str) -> Ax.AcadLayout:
        return self.axDoc.layouts().add(name)

    def _find_layout(self, name: str) -> Ax.AcadLayout:
        layouts = self.axDoc.layouts()
        for i in range(layouts.count()):
            if layouts.item(i).name() == name:
                return layouts.item(i)
        raise LookupError(f"layout {name!r} not found")

    def _model_layout(self) -> Ax.AcadLayout:
        return self._find_layout("Model")

    # --- static / class methods ---

    def test_className(self):
        assert Ax.AcadLayout.className() == "AcadLayout"

    def test_init_raises(self):
        with pytest.raises(Exception):
            Ax.AcadLayout()

    def test_cast(self):
        layout = self._add_layout("axlayout_cast")
        casted = Ax.AcadLayout.cast(layout)
        assert casted.name() == "axlayout_cast"

    # --- name / setName ---

    def test_name(self):
        layout = self._add_layout("axlayout_name")
        assert layout.name() == "axlayout_name"

    def test_setName(self):
        layout = self._add_layout("axlayout_rename_old")
        layout.setName("axlayout_rename_new")
        assert layout.name() == "axlayout_rename_new"

    # --- modelType ---

    def test_modelType_model(self):
        # A model-space layout reports modelType() as True.
        assert self._model_layout().modelType() is True

    def test_modelType_paper(self):
        # A paper-space (layout) reports modelType() as False.
        layout = self._add_layout("axlayout_modeltype")
        assert layout.modelType() is False

    # --- block ---

    def test_block(self):
        layout = self._add_layout("axlayout_block")
        block = layout.block()
        assert block is not None
        assert isinstance(block.name(), str)

    def test_block_model_is_modelspace(self):
        # The Model layout's block is the modelspace block.
        model_block_id = self._model_layout().block().objectId().asOldId()
        modelspace_id = self.axDoc.modelSpace().objectId().asOldId()
        assert model_block_id == modelspace_id

    # --- tabOrder / setTabOrder ---

    def test_tabOrder(self):
        layout = self._add_layout("axlayout_taborder")
        assert isinstance(layout.tabOrder(), int)

    def test_setTabOrder(self):
        # Tab order 0 is reserved for the Model tab, so use a non-zero index.
        layout = self._add_layout("axlayout_settaborder")
        layout.setTabOrder(1)
        assert layout.tabOrder() == 1

    # --- inherited AcadObject identity ---

    def test_isNull(self):
        layout = self._add_layout("axlayout_isnull")
        assert layout.isNull() is False

    def test_objectId(self):
        layout = self._add_layout("axlayout_objectid")
        assert layout.objectId().isNull() is False

    def test_handle(self):
        layout = self._add_layout("axlayout_handle")
        handle = layout.handle()
        assert handle is not None
        assert len(handle.toString()) > 0

    def test_database(self):
        layout = self._add_layout("axlayout_database")
        assert layout.database().className() == "AcadDatabase"

    def test_objectName(self):
        layout = self._add_layout("axlayout_objectname")
        assert isinstance(layout.objectName(), str)
        assert len(layout.objectName()) > 0
