from __future__ import annotations

import pytest

from pyrx import Ap, Ax, Db


class TestAxMLeaderStyle:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def _get_style(self) -> Ax.AcadMLeaderStyle:
        # MLeaderStyles live in the ACAD_MLEADERSTYLE named-object dictionary.
        # AcadDictionaries.item() is index-only, so locate the dict by name.
        for item in self.axDoc.dictionaries():
            if item.objectId().isDerivedFrom(Db.Dictionary.desc()):
                d = Ax.AcadDictionary.cast(item)
                if d.name() == "ACAD_MLEADERSTYLE":
                    return Ax.AcadMLeaderStyle.cast(d.item(0))
        raise AssertionError("ACAD_MLEADERSTYLE dictionary not found")

    # --- static / access -------------------------------------------------

    def test_className(self):
        assert Ax.AcadMLeaderStyle.className() == "AcadMLeaderStyle"

    def test_init_raises(self):
        with pytest.raises(Exception):
            Ax.AcadMLeaderStyle()

    def test_get_style(self):
        style = self._get_style()
        assert style is not None
        assert style.objectName() == "AcDbMLeaderStyle"

    def test_cast(self):
        style = self._get_style()
        casted = Ax.AcadMLeaderStyle.cast(style)
        assert casted is not None
        assert casted.objectName() == "AcDbMLeaderStyle"

    def test_name(self):
        assert isinstance(self._get_style().name(), str)

    # --- getters ---------------------------------------------------------

    def test_BlockRotation(self):
        assert isinstance(self._get_style().BlockRotation(), float)

    def test_alignSpace(self):
        assert isinstance(self._get_style().alignSpace(), float)

    def test_annotative(self):
        assert isinstance(self._get_style().annotative(), bool)

    def test_arrowSize(self):
        assert isinstance(self._get_style().arrowSize(), float)

    def test_arrowSymbol(self):
        assert isinstance(self._get_style().arrowSymbol(), str)

    def test_bitFlags(self):
        assert isinstance(self._get_style().bitFlags(), int)

    def test_block(self):
        assert isinstance(self._get_style().block(), str)

    def test_blockConnectionType(self):
        assert isinstance(self._get_style().blockConnectionType(), Ax.AcBlockConnectionType)

    def test_blockScale(self):
        assert isinstance(self._get_style().blockScale(), float)

    def test_breakSize(self):
        assert isinstance(self._get_style().breakSize(), float)

    def test_contentType(self):
        assert isinstance(self._get_style().contentType(), Ax.AcMLeaderContentType)

    def test_description(self):
        assert isinstance(self._get_style().description(), str)

    def test_doglegLength(self):
        assert isinstance(self._get_style().doglegLength(), float)

    def test_drawLeaderOrderType(self):
        assert isinstance(self._get_style().drawLeaderOrderType(), Ax.AcDrawLeaderOrderType)

    def test_drawMLeaderOrderType(self):
        assert isinstance(self._get_style().drawMLeaderOrderType(), Ax.AcDrawMLeaderOrderType)

    def test_enableBlockRotation(self):
        assert isinstance(self._get_style().enableBlockRotation(), bool)

    def test_enableBlockScale(self):
        assert isinstance(self._get_style().enableBlockScale(), bool)

    def test_enableDogleg(self):
        assert isinstance(self._get_style().enableDogleg(), bool)

    def test_enableFrameText(self):
        assert isinstance(self._get_style().enableFrameText(), bool)

    def test_enableLanding(self):
        assert isinstance(self._get_style().enableLanding(), bool)

    def test_firstSegmentAngleConstraint(self):
        assert isinstance(self._get_style().firstSegmentAngleConstraint(), Ax.AcSegmentAngleType)

    def test_landingGap(self):
        assert isinstance(self._get_style().landingGap(), float)

    def test_leaderLineColor(self):
        assert isinstance(self._get_style().leaderLineColor(), Ax.AcadAcCmColor)

    def test_leaderLineType(self):
        assert isinstance(self._get_style().leaderLineType(), Ax.AcMLeaderType)

    def test_leaderLineTypeId(self):
        assert isinstance(self._get_style().leaderLineTypeId(), str)

    def test_leaderLineWeight(self):
        assert isinstance(self._get_style().leaderLineWeight(), Ax.AcLineWeight)

    def test_maxLeaderSegmentsPoints(self):
        assert isinstance(self._get_style().maxLeaderSegmentsPoints(), int)

    def test_overwritePropChanged(self):
        assert isinstance(self._get_style().overwritePropChanged(), bool)

    def test_scaleFactor(self):
        assert isinstance(self._get_style().scaleFactor(), float)

    def test_secondSegmentAngleConstraint(self):
        assert isinstance(self._get_style().secondSegmentAngleConstraint(), Ax.AcSegmentAngleType)

    def test_textAlignmentType(self):
        assert isinstance(self._get_style().textAlignmentType(), Ax.AcTextAlignmentType)

    def test_textAngleType(self):
        assert isinstance(self._get_style().textAngleType(), Ax.AcTextAngleType)

    def test_textAttachmentDirection(self):
        assert isinstance(self._get_style().textAttachmentDirection(), Ax.AcTextAttachmentDirection)

    def test_textBottomAttachmentType(self):
        assert isinstance(self._get_style().textBottomAttachmentType(), Ax.AcVerticalTextAttachmentType)

    def test_textColor(self):
        assert isinstance(self._get_style().textColor(), Ax.AcadAcCmColor)

    def test_textHeight(self):
        assert isinstance(self._get_style().textHeight(), float)

    def test_textLeftAttachmentType(self):
        assert isinstance(self._get_style().textLeftAttachmentType(), Ax.AcTextAttachmentType)

    def test_textRightAttachmentType(self):
        assert isinstance(self._get_style().textRightAttachmentType(), Ax.AcTextAttachmentType)

    def test_textString(self):
        assert isinstance(self._get_style().textString(), str)

    def test_textStyle(self):
        assert isinstance(self._get_style().textStyle(), str)

    def test_textTopAttachmentType(self):
        assert isinstance(self._get_style().textTopAttachmentType(), Ax.AcVerticalTextAttachmentType)

    # --- setters (set/get round-trip) ------------------------------------

    def test_setArrowSize(self):
        style = self._get_style()
        style.setArrowSize(4.0)
        assert style.arrowSize() == 4.0

    def test_setBreakSize(self):
        style = self._get_style()
        style.setBreakSize(2.0)
        assert style.breakSize() == 2.0

    def test_setDoglegLength(self):
        style = self._get_style()
        style.setDoglegLength(3.0)
        assert style.doglegLength() == 3.0

    def test_setLandingGap(self):
        style = self._get_style()
        style.setLandingGap(1.5)
        assert style.landingGap() == 1.5

    def test_setBlockScale(self):
        style = self._get_style()
        style.setBlockScale(2.0)
        assert style.blockScale() == 2.0

    def test_setScaleFactor(self):
        style = self._get_style()
        style.setScaleFactor(1.5)
        assert style.scaleFactor() == 1.5

    def test_setTextHeight(self):
        style = self._get_style()
        style.setTextHeight(3.5)
        assert style.textHeight() == 3.5

    def test_setDescription(self):
        style = self._get_style()
        style.setDescription("axmls_desc")
        assert style.description() == "axmls_desc"

    def test_setLeaderLineType(self):
        style = self._get_style()
        style.setLeaderLineType(Ax.AcMLeaderType.acSplineLeader)
        assert style.leaderLineType() == Ax.AcMLeaderType.acSplineLeader
        style.setLeaderLineType(Ax.AcMLeaderType.acStraightLeader)
        assert style.leaderLineType() == Ax.AcMLeaderType.acStraightLeader

    def test_setLeaderLineWeight(self):
        style = self._get_style()
        style.setLeaderLineWeight(Ax.AcLineWeight.acLnWt020)
        assert style.leaderLineWeight() == Ax.AcLineWeight.acLnWt020

    def test_setLeaderLineColor(self):
        style = self._get_style()
        style.setLeaderLineColor(Ax.AcadAcCmColor(Ax.AcColor.acRed))
        assert style.leaderLineColor().colorIndex() == Ax.AcColor.acRed

    def test_setAnnotative(self):
        style = self._get_style()
        style.setAnnotative(True)
        assert style.annotative() is True
        style.setAnnotative(False)
        assert style.annotative() is False

    def test_setEnableDogleg(self):
        style = self._get_style()
        style.setEnableDogleg(True)
        assert style.enableDogleg() is True
        style.setEnableDogleg(False)
        assert style.enableDogleg() is False

    def test_setEnableLanding(self):
        style = self._get_style()
        style.setEnableLanding(True)
        assert style.enableLanding() is True
        style.setEnableLanding(False)
        assert style.enableLanding() is False

    def test_setEnableFrameText(self):
        style = self._get_style()
        style.setEnableFrameText(True)
        assert style.enableFrameText() is True
        style.setEnableFrameText(False)
        assert style.enableFrameText() is False

    def test_setEnableBlockRotation(self):
        style = self._get_style()
        style.setEnableBlockRotation(True)
        assert style.enableBlockRotation() is True
        style.setEnableBlockRotation(False)
        assert style.enableBlockRotation() is False

    def test_setEnableBlockScale(self):
        style = self._get_style()
        style.setEnableBlockScale(True)
        assert style.enableBlockScale() is True
        style.setEnableBlockScale(False)
        assert style.enableBlockScale() is False

    def test_setFirstSegmentAngleConstraint(self):
        style = self._get_style()
        style.setFirstSegmentAngleConstraint(Ax.AcSegmentAngleType.acDegrees45)
        assert style.firstSegmentAngleConstraint() == Ax.AcSegmentAngleType.acDegrees45

    def test_setSecondSegmentAngleConstraint(self):
        style = self._get_style()
        style.setSecondSegmentAngleConstraint(Ax.AcSegmentAngleType.acDegrees90)
        assert style.secondSegmentAngleConstraint() == Ax.AcSegmentAngleType.acDegrees90

    def test_setDrawLeaderOrderType(self):
        style = self._get_style()
        style.setDrawLeaderOrderType(Ax.AcDrawLeaderOrderType.acDrawLeaderHeadFirst)
        assert style.drawLeaderOrderType() == Ax.AcDrawLeaderOrderType.acDrawLeaderHeadFirst

    def test_setDrawMLeaderOrderType(self):
        style = self._get_style()
        style.setDrawMLeaderOrderType(Ax.AcDrawMLeaderOrderType.acDrawContentFirst)
        assert style.drawMLeaderOrderType() == Ax.AcDrawMLeaderOrderType.acDrawContentFirst

    def test_setBlockConnectionType(self):
        style = self._get_style()
        style.setBlockConnectionType(Ax.AcBlockConnectionType.acConnectBase)
        assert style.blockConnectionType() == Ax.AcBlockConnectionType.acConnectBase

    def test_setMaxLeaderSegmentsPoints(self):
        style = self._get_style()
        style.setMaxLeaderSegmentsPoints(5)
        assert style.maxLeaderSegmentsPoints() == 5

    def test_setBitFlags(self):
        style = self._get_style()
        style.setBitFlags(1)
        assert style.bitFlags() == 1

    def test_setTextString(self):
        style = self._get_style()
        style.setTextString("axmls_text")
        assert style.textString() == "axmls_text"

    def test_setTextStyle(self):
        style = self._get_style()
        style.setTextStyle("Standard")
        assert style.textStyle() == "Standard"

    def test_setTextAlignmentType(self):
        style = self._get_style()
        style.setTextAlignmentType(Ax.AcTextAlignmentType.acCenterAlignment)
        assert style.textAlignmentType() == Ax.AcTextAlignmentType.acCenterAlignment

    def test_setTextAngleType(self):
        style = self._get_style()
        style.setTextAngleType(Ax.AcTextAngleType.acHorizontalAngle)
        assert style.textAngleType() == Ax.AcTextAngleType.acHorizontalAngle

    def test_setTextAttachmentDirection(self):
        style = self._get_style()
        style.setTextAttachmentDirection(Ax.AcTextAttachmentDirection.acAttachmentHorizontal)
        assert style.textAttachmentDirection() == Ax.AcTextAttachmentDirection.acAttachmentHorizontal

    def test_setTextColor(self):
        style = self._get_style()
        style.setTextColor(Ax.AcadAcCmColor(Ax.AcColor.acBlue))
        assert style.textColor().colorIndex() == Ax.AcColor.acBlue
