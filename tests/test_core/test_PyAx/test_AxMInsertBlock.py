from __future__ import annotations

import pytest

from pyrx import Ap, Ax, Ge


class TestAxMInsertBlock:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def _add(self, name, pnt=None, scale=None, rotation=0.0, rows=2, cols=3,
             rowSpacing=100, colSpacing=100):
        axSpace = self.axDoc.modelSpace()
        if pnt is None:
            pnt = Ge.Point3d(0, 0, 0)
        if scale is None:
            scale = Ge.Scale3d(1, 1, 1)
        axBlocks = self.axDoc.blocks()
        if not axBlocks.has(name):
            axBlocks.add(Ge.Point3d(0, 0, 0), name)
        return axSpace.addMInsertBlock(
            pnt, name, scale, rotation, rows, cols, rowSpacing, colSpacing
        )

    def test_add_type(self):
        ent = self._add("MIB_TYPE")
        assert isinstance(ent, Ax.AcadMInsertBlock)
        assert ent.objectName() == "AcDbMInsertBlock"
        assert ent.entityType() == Ax.AcEntityName.acMInsertBlock

    def test_rows(self):
        ent = self._add("MIB_ROWS", rows=2)
        assert ent.rows() == 2

    def test_columns(self):
        ent = self._add("MIB_COLS", cols=3)
        assert ent.columns() == 3

    def test_rowSpacing(self):
        ent = self._add("MIB_ROWSP", rowSpacing=100)
        assert ent.rowSpacing() == 100.0

    def test_columnSpacing(self):
        ent = self._add("MIB_COLSP", colSpacing=100)
        assert ent.columnSpacing() == 100.0

    def test_setRows(self):
        ent = self._add("MIB_SETROWS")
        ent.setRows(5)
        assert ent.rows() == 5

    def test_setColumns(self):
        ent = self._add("MIB_SETCOLS")
        ent.setColumns(7)
        assert ent.columns() == 7

    def test_setRowSpacing(self):
        ent = self._add("MIB_SETROWSP")
        ent.setRowSpacing(200.0)
        assert ent.rowSpacing() == 200.0

    def test_setColumnSpacing(self):
        ent = self._add("MIB_SETCOLSP")
        ent.setColumnSpacing(300.0)
        assert ent.columnSpacing() == 300.0

    def test_cast(self):
        ent = self._add("MIB_CAST")
        casted = Ax.AcadMInsertBlock.cast(ent)
        assert isinstance(casted, Ax.AcadMInsertBlock)

    def test_className(self):
        assert Ax.AcadMInsertBlock.className() == "AcadMInsertBlock"
