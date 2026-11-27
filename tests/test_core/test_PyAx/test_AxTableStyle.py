from __future__ import annotations

import pytest

from pyrx import Ap, Ax, Db


class TestAxTableStyle:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def _get_style(self) -> Ax.AcadTableStyle:
        # TableStyles live in the ACAD_TABLESTYLE named-object dictionary.
        # AcadDictionaries.item() is index-only, so locate the dict by name.
        for item in self.axDoc.dictionaries():
            if item.objectId().isDerivedFrom(Db.Dictionary.desc()):
                d = Ax.AcadDictionary.cast(item)
                if d.name() == "ACAD_TABLESTYLE":
                    return Ax.AcadTableStyle.cast(d.item(0))
        raise AssertionError("ACAD_TABLESTYLE dictionary not found")

    def _cell_style(self) -> str:
        return self._get_style().cellStyles()[0]

    # --- static / access -------------------------------------------------

    def test_className(self):
        assert Ax.AcadTableStyle.className() == "AcadTableStyle"

    def test_init_raises(self):
        with pytest.raises(Exception):
            Ax.AcadTableStyle()

    def test_get_style(self):
        style = self._get_style()
        assert style is not None
        assert style.objectName() == "AcDbTableStyle"

    def test_cast(self):
        style = self._get_style()
        casted = Ax.AcadTableStyle.cast(style)
        assert casted is not None
        assert casted.objectName() == "AcDbTableStyle"

    def test_name(self):
        assert isinstance(self._get_style().name(), str)

    # --- style-level getters --------------------------------------------

    def test_bitFlags(self):
        assert isinstance(self._get_style().bitFlags(), int)

    def test_description(self):
        assert isinstance(self._get_style().description(), str)

    def test_flowDirection(self):
        assert isinstance(self._get_style().flowDirection(), Ax.AcTableDirection)

    def test_headerSuppressed(self):
        assert isinstance(self._get_style().headerSuppressed(), bool)

    def test_horzCellMargin(self):
        assert isinstance(self._get_style().horzCellMargin(), float)

    def test_titleSuppressed(self):
        assert isinstance(self._get_style().titleSuppressed(), bool)

    def test_vertCellMargin(self):
        assert isinstance(self._get_style().vertCellMargin(), float)

    def test_cellStyles(self):
        assert isinstance(self._get_style().cellStyles(), list)

    def test_numCellStyles(self):
        assert isinstance(self._get_style().numCellStyles(), int)

    def test_templateId(self):
        assert isinstance(self._get_style().templateId(), Db.ObjectId)

    # --- cell-style-level getters ---------------------------------------

    def test_alignment(self):
        assert isinstance(self._get_style().alignment(self._cell_style()), Ax.AcCellAlignment)

    def test_backgroundColor(self):
        assert isinstance(self._get_style().backgroundColor(self._cell_style()), Ax.AcadAcCmColor)

    def test_cellClass(self):
        assert isinstance(self._get_style().cellClass(self._cell_style()), int)

    def test_color(self):
        assert isinstance(self._get_style().color(self._cell_style()), Ax.AcadAcCmColor)

    def test_dataType(self):
        dt = self._get_style().dataType(self._cell_style())
        assert isinstance(dt, tuple)
        assert len(dt) == 2

    def test_format(self):
        assert isinstance(self._get_style().format(self._cell_style()), str)

    def test_gridColor(self):
        assert isinstance(
            self._get_style().gridColor(self._cell_style(), Ax.AcGridLineType.acHorzTop),
            Ax.AcadAcCmColor,
        )

    def test_gridLineWeight(self):
        assert isinstance(
            self._get_style().gridLineWeight(self._cell_style(), Ax.AcGridLineType.acHorzTop),
            Ax.AcLineWeight,
        )

    def test_gridVisibility(self):
        assert isinstance(
            self._get_style().gridVisibility(self._cell_style(), Ax.AcGridLineType.acHorzTop),
            bool,
        )

    def test_isCellStyleInUse(self):
        assert isinstance(self._get_style().isCellStyleInUse(self._cell_style()), bool)

    def test_isMergeAllEnabled(self):
        assert isinstance(self._get_style().isMergeAllEnabled(self._cell_style()), bool)

    def test_rotation(self):
        assert isinstance(self._get_style().rotation(self._cell_style()), float)

    def test_textHeight(self):
        assert isinstance(self._get_style().textHeight(self._cell_style()), float)

    def test_textStyleId(self):
        assert isinstance(self._get_style().textStyleId(self._cell_style()), Db.ObjectId)

    # --- style-level setters (set/get round-trip) -----------------------

    def test_setBitFlags(self):
        style = self._get_style()
        style.setBitFlags(1)
        assert style.bitFlags() == 1

    def test_setDescription(self):
        style = self._get_style()
        style.setDescription("axts_desc")
        assert style.description() == "axts_desc"

    def test_setFlowDirections(self):
        style = self._get_style()
        style.setFlowDirections(Ax.AcTableDirection.acTableTopToBottom)
        assert style.flowDirection() == Ax.AcTableDirection.acTableTopToBottom

    def test_setHeaderSuppressed(self):
        style = self._get_style()
        style.setHeaderSuppressed(True)
        assert style.headerSuppressed() is True
        style.setHeaderSuppressed(False)
        assert style.headerSuppressed() is False

    def test_setHorzCellMargin(self):
        style = self._get_style()
        style.setHorzCellMargin(1.5)
        assert style.horzCellMargin() == 1.5

    def test_setTitleSuppressed(self):
        style = self._get_style()
        style.setTitleSuppressed(True)
        assert style.titleSuppressed() is True
        style.setTitleSuppressed(False)
        assert style.titleSuppressed() is False

    def test_setVertCellMargin(self):
        style = self._get_style()
        style.setVertCellMargin(1.5)
        assert style.vertCellMargin() == 1.5

    # --- cell-style-level setters (set/get round-trip) ------------------

    def test_setAlignment(self):
        style = self._get_style()
        cs = self._cell_style()
        style.setAlignment(cs, Ax.AcCellAlignment.acMiddleCenter)
        assert style.alignment(cs) == Ax.AcCellAlignment.acMiddleCenter

    def test_setBackgroundColor(self):
        style = self._get_style()
        cs = self._cell_style()
        style.setBackgroundColor(cs, Ax.AcadAcCmColor(Ax.AcColor.acRed))
        assert style.backgroundColor(cs).colorIndex() == Ax.AcColor.acRed

    def test_setCellClass(self):
        style = self._get_style()
        cs = self._cell_style()
        current = style.cellClass(cs)
        style.setCellClass(cs, current)
        assert style.cellClass(cs) == current

    def test_setColor(self):
        style = self._get_style()
        cs = self._cell_style()
        style.setColor(cs, Ax.AcadAcCmColor(Ax.AcColor.acBlue))
        assert style.color(cs).colorIndex() == Ax.AcColor.acBlue

    def test_setDataType(self):
        style = self._get_style()
        cs = self._cell_style()
        style.setDataType(cs, Ax.AcValueDataType.acString, Ax.AcValueUnitType.acUnitless)
        dt = style.dataType(cs)
        assert dt[0] == Ax.AcValueDataType.acString
        assert dt[1] == Ax.AcValueUnitType.acUnitless

    def test_setFormat(self):
        style = self._get_style()
        cs = self._cell_style()
        current = style.format(cs)
        style.setFormat(cs, current)
        assert style.format(cs) == current

    def test_setGridColor(self):
        style = self._get_style()
        cs = self._cell_style()
        style.setGridColor(cs, Ax.AcGridLineType.acHorzTop, Ax.AcadAcCmColor(Ax.AcColor.acRed))
        assert style.gridColor(cs, Ax.AcGridLineType.acHorzTop).colorIndex() == Ax.AcColor.acRed

    def test_setGridLineWeight(self):
        style = self._get_style()
        cs = self._cell_style()
        style.setGridLineWeight(cs, Ax.AcGridLineType.acHorzTop, Ax.AcLineWeight.acLnWt020)
        assert style.gridLineWeight(cs, Ax.AcGridLineType.acHorzTop) == Ax.AcLineWeight.acLnWt020

    def test_setGridVisibility(self):
        style = self._get_style()
        cs = self._cell_style()
        style.setGridVisibility(cs, Ax.AcGridLineType.acHorzTop, True)
        assert style.gridVisibility(cs, Ax.AcGridLineType.acHorzTop) is True

    def test_setRotation(self):
        style = self._get_style()
        cs = self._cell_style()
        style.setRotation(cs, 90)
        assert style.rotation(cs) == 90.0

    def test_setTextHeight(self):
        style = self._get_style()
        cs = self._cell_style()
        style.setTextHeight(cs, 2.5)
        assert style.textHeight(cs) == 2.5

    # --- cell-style management ------------------------------------------

    def test_createCellStyle(self):
        style = self._get_style()
        name = "axts_test"
        style.createCellStyle(name)
        assert name in style.cellStyles()
        style.deleteCellStyle(name)

    def test_deleteCellStyle(self):
        style = self._get_style()
        name = "axts_del"
        style.createCellStyle(name)
        assert name in style.cellStyles()
        style.deleteCellStyle(name)
        assert name not in style.cellStyles()

    def test_createCellStyleFromStyle(self):
        style = self._get_style()
        src = style.cellStyles()[0]
        name = "axts_copy"
        style.createCellStyleFromStyle(name, src)
        assert name in style.cellStyles()
        style.deleteCellStyle(name)

    def test_renameCellStyle(self):
        style = self._get_style()
        old = "axts_old"
        new = "axts_new"
        style.createCellStyle(old)
        style.renameCellStyle(old, new)
        assert old not in style.cellStyles()
        assert new in style.cellStyles()
        style.deleteCellStyle(new)

    def test_uniqueCellStyleName(self):
        style = self._get_style()
        assert isinstance(style.uniqueCellStyleName("axts"), str)

    def test_enableMergeAll(self):
        style = self._get_style()
        cs = self._cell_style()
        style.enableMergeAll(cs, True)
        assert style.isMergeAllEnabled(cs) is True
        style.enableMergeAll(cs, False)
        assert style.isMergeAllEnabled(cs) is False

    # --- tricky / id-based setters --------------------------------------

    def test_setName(self):
        style = self._get_style()
        original = style.name()
        try:
            style.setName("axts_renamed")
            assert style.name() == "axts_renamed"
        finally:
            style.setName(original)

    def test_setTextStyleId(self):
        style = self._get_style()
        cs = self._cell_style()
        current = style.textStyleId(cs)
        style.setTextStyleId(cs, current)

    def test_setTemplateId(self):
        style = self._get_style()
        current = style.templateId()
        style.setTemplateId(current)
