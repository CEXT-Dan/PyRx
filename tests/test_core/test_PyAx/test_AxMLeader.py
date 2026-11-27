from __future__ import annotations

import pytest

from pyrx import Ap, Ax, Ge


class TestAxMLeader:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def _create_mleader(self):
        axSpace = self.axDoc.modelSpace()
        pnts = [
            Ge.Point3d(0, 0, 0),
            Ge.Point3d(1, 2, 0),
            Ge.Point3d(2, 2, 0),
            Ge.Point3d(3, 3, 0),
            Ge.Point3d(4, 4, 0),
        ]
        return axSpace.addMLeader(pnts)

    def test_create(self):
        ent = self._create_mleader()
        assert ent.objectName() == "AcDbMLeader"
        assert ent.entityType() == Ax.AcEntityName.acMLeader

    def test_cast(self):
        ent = self._create_mleader()
        casted = Ax.AcadMLeader.cast(ent)
        assert casted is not None
        assert casted.objectName() == "AcDbMLeader"

    def test_className(self):
        assert Ax.AcadMLeader.className() == "AcadMLeader"

    def test_leaderCount(self):
        ent = self._create_mleader()
        assert ent.leaderCount() == 1

    def test_vertexCount(self):
        ent = self._create_mleader()
        assert ent.vertexCount(0) == 5

    def test_leaderLineVertices(self):
        ent = self._create_mleader()
        verts = ent.leaderLineVertices(0)
        assert len(verts) == 5
        assert verts[0] == Ge.Point3d(0, 0, 0)
        assert verts[4] == Ge.Point3d(4, 4, 0)

    def test_arrowheadSize(self):
        ent = self._create_mleader()
        assert isinstance(ent.arrowheadSize(), float)
        ent.setArrowheadSize(5.0)
        assert ent.arrowheadSize() == 5.0

    def test_arrowheadType(self):
        ent = self._create_mleader()
        assert isinstance(ent.arrowheadType(), Ax.AcDimArrowheadType)
        ent.setArrowheadType(Ax.AcDimArrowheadType.acArrowDot)
        assert ent.arrowheadType() == Ax.AcDimArrowheadType.acArrowDot
        ent.setArrowheadType(Ax.AcDimArrowheadType.acArrowDefault)
        assert ent.arrowheadType() == Ax.AcDimArrowheadType.acArrowDefault

    def test_arrowheadBlock(self):
        ent = self._create_mleader()
        assert isinstance(ent.arrowheadBlock(), str)

    def test_contentType(self):
        ent = self._create_mleader()
        assert isinstance(ent.contentType(), Ax.AcMLeaderContentType)
        # addMLeader creates the leader with MText content by default
        assert ent.contentType() == Ax.AcMLeaderContentType.acMTextContent

    def test_leaderType(self):
        ent = self._create_mleader()
        assert isinstance(ent.leaderType(), Ax.AcMLeaderType)
        ent.setLeaderType(Ax.AcMLeaderType.acSplineLeader)
        assert ent.leaderType() == Ax.AcMLeaderType.acSplineLeader
        ent.setLeaderType(Ax.AcMLeaderType.acStraightLeader)
        assert ent.leaderType() == Ax.AcMLeaderType.acStraightLeader

    def test_dogLegged(self):
        ent = self._create_mleader()
        assert isinstance(ent.dogLegged(), bool)
        ent.setDogLegged(True)
        assert ent.dogLegged() is True
        ent.setDogLegged(False)
        assert ent.dogLegged() is False

    def test_doglegLength(self):
        ent = self._create_mleader()
        assert isinstance(ent.doglegLength(), float)
        ent.setDoglegLength(2.0)
        assert ent.doglegLength() == 2.0

    def test_landingGap(self):
        ent = self._create_mleader()
        assert isinstance(ent.landingGap(), float)
        ent.setLandingGap(1.0)
        assert ent.landingGap() == 1.0

    def test_leaderLineColor(self):
        ent = self._create_mleader()
        assert isinstance(ent.leaderLineColor(), Ax.AcadAcCmColor)
        ent.setLeaderLineColor(Ax.AcadAcCmColor(Ax.AcColor.acRed))
        assert ent.leaderLineColor().colorIndex() == Ax.AcColor.acRed
        ent.setLeaderLineColor(Ax.AcadAcCmColor(Ax.AcColor.acByBlock))
        assert ent.leaderLineColor().colorIndex() == Ax.AcColor.acByBlock

    def test_leaderLineWeight(self):
        ent = self._create_mleader()
        assert isinstance(ent.leaderLineWeight(), Ax.AcLineWeight)
        ent.setLeaderLineWeight(Ax.AcLineWeight.acLnWt020)
        assert ent.leaderLineWeight() == Ax.AcLineWeight.acLnWt020

    def test_leaderLinetype(self):
        ent = self._create_mleader()
        assert isinstance(ent.leaderLinetype(), str)
        ent.setLeaderLinetype("Continuous")
        assert ent.leaderLinetype() == "Continuous"

    def test_scaleFactor(self):
        ent = self._create_mleader()
        assert isinstance(ent.scaleFactor(), float)
        ent.setScaleFactor(2.0)
        assert ent.scaleFactor() == 2.0

    def test_textBackgroundFill(self):
        ent = self._create_mleader()
        assert isinstance(ent.textBackgroundFill(), bool)
        ent.setTextBackgroundFill(True)
        assert ent.textBackgroundFill() is True
        ent.setTextBackgroundFill(False)
        assert ent.textBackgroundFill() is False

    def test_textFrameDisplay(self):
        ent = self._create_mleader()
        assert isinstance(ent.textFrameDisplay(), bool)
        ent.setTextFrameDisplay(True)
        assert ent.textFrameDisplay() is True
        ent.setTextFrameDisplay(False)
        assert ent.textFrameDisplay() is False

    def test_textHeight(self):
        ent = self._create_mleader()
        assert isinstance(ent.textHeight(), float)
        ent.setTextHeight(3.5)
        assert ent.textHeight() == 3.5

    def test_textRotation(self):
        ent = self._create_mleader()
        assert isinstance(ent.textRotation(), float)
        # rotation is in radians (values are normalized modulo 2*pi)
        ent.setTextRotation(1.0)
        assert ent.textRotation() == 1.0

    def test_textString(self):
        ent = self._create_mleader()
        assert isinstance(ent.textString(), str)

    def test_textStyleName(self):
        ent = self._create_mleader()
        assert isinstance(ent.textStyleName(), str)

    def test_textWidth(self):
        ent = self._create_mleader()
        assert isinstance(ent.textWidth(), float)

    def test_textLineSpacingDistance(self):
        ent = self._create_mleader()
        assert isinstance(ent.textLineSpacingDistance(), float)

    def test_textLineSpacingFactor(self):
        ent = self._create_mleader()
        assert isinstance(ent.textLineSpacingFactor(), float)

    def test_textLineSpacingStyle(self):
        ent = self._create_mleader()
        assert isinstance(ent.textLineSpacingStyle(), Ax.AcLineSpacingStyle)

    def test_textDirection(self):
        ent = self._create_mleader()
        assert isinstance(ent.textDirection(), Ax.AcDrawingDirection)

    def test_textAttachmentDirection(self):
        ent = self._create_mleader()
        assert isinstance(ent.textAttachmentDirection(), Ax.AcTextAttachmentDirection)

    def test_textJustify(self):
        ent = self._create_mleader()
        assert isinstance(ent.textJustify(), Ax.AcAttachmentPoint)

    def test_textLeftAttachmentType(self):
        ent = self._create_mleader()
        assert isinstance(ent.textLeftAttachmentType(), Ax.AcTextAttachmentType)

    def test_textRightAttachmentType(self):
        ent = self._create_mleader()
        assert isinstance(ent.textRightAttachmentType(), Ax.AcTextAttachmentType)

    def test_textTopAttachmentType(self):
        ent = self._create_mleader()
        assert isinstance(ent.textTopAttachmentType(), Ax.AcVerticalTextAttachmentType)

    def test_textBottomAttachmentType(self):
        ent = self._create_mleader()
        assert isinstance(ent.textBottomAttachmentType(), Ax.AcVerticalTextAttachmentType)

    def test_blockScale(self):
        ent = self._create_mleader()
        assert isinstance(ent.blockScale(), float)

    def test_blockConnectionType(self):
        ent = self._create_mleader()
        assert isinstance(ent.blockConnectionType(), Ax.AcBlockConnectionType)

    def test_contentBlockName(self):
        ent = self._create_mleader()
        assert isinstance(ent.contentBlockName(), str)

    def test_contentBlockType(self):
        ent = self._create_mleader()
        assert isinstance(ent.contentBlockType(), Ax.AcPredefBlockType)

    def test_styleName(self):
        ent = self._create_mleader()
        assert isinstance(ent.styleName(), str)

    def test_addLeaderLineEx(self):
        ent = self._create_mleader()
        before = ent.leaderCount()
        pnts = [Ge.Point3d(10, 0, 0), Ge.Point3d(11, 2, 0), Ge.Point3d(12, 2, 0)]
        index = ent.addLeaderLineEx(pnts)
        assert isinstance(index, int)
        assert ent.leaderCount() == before + 1

    def test_doglegDirection(self):
        ent = self._create_mleader()
        assert isinstance(ent.doglegDirection(0), Ge.Vector3d)
