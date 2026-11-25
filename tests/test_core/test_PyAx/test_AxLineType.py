from __future__ import annotations

import pytest

from pyrx import Ap, Ax


class TestAxLineType:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def _make_linetype(self, name: str) -> Ax.AcadLineType:
        return self.axDoc.lineTypes().add(name)

    # --- static / class methods ---

    def test_className(self):
        assert Ax.AcadLineType.className() == "AcadLineType"

    def test_init_raises(self):
        with pytest.raises(Exception):
            Ax.AcadLineType()

    # --- name ---

    def test_name(self):
        linetype = self._make_linetype("axlinetype_name")
        assert linetype.name() == "axlinetype_name"

    def test_setName(self):
        linetype = self._make_linetype("axlinetype_rename_old")
        linetype.setName("axlinetype_rename_new")
        assert linetype.name() == "axlinetype_rename_new"

    # --- description ---

    def test_description(self):
        linetype = self._make_linetype("axlinetype_desc")
        # A freshly created linetype should report a string description.
        assert isinstance(linetype.description(), str)

    def test_setDescription(self):
        linetype = self._make_linetype("axlinetype_setdesc")
        linetype.setDescription("axlinetype description")
        assert linetype.description() == "axlinetype description"

    # --- AcadObject inherited ---

    def test_isNull(self):
        linetype = self._make_linetype("axlinetype_isnull")
        assert linetype.isNull() is False

    # --- cast ---

    def test_cast(self):
        linetype = self._make_linetype("axlinetype_cast")
        casted = Ax.AcadLineType.cast(linetype)
        assert casted.name() == "axlinetype_cast"
