from __future__ import annotations

import pytest

from pyrx import Ap, Ax, Ge


class TestAxDim3PointAngular:
    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def _create_dim(self):
        axSpace = self.axDoc.modelSpace()
        return axSpace.addDim3PointAngular(
            Ge.Point3d(0, 5, 0),
            Ge.Point3d(1, 7, 0),
            Ge.Point3d(1, 3, 0),
            Ge.Point3d(3, 5, 0),
        )

    def test_create1(self):
        ent = self._create_dim()
        assert ent.objectName() == "AcDb3PointAngularDimension"
        assert ent.entityType() == Ax.AcEntityName.acDim3PointAngular

    def test_cast(self):
        ent = self._create_dim()
        casted = Ax.AcadDim3PointAngular.cast(ent)
        assert casted is not None
        assert casted.objectName() == "AcDb3PointAngularDimension"

    def test_className(self):
        assert Ax.AcadDim3PointAngular.className() == "AcadDim3PointAngular"

    def test_measurement(self):
        ent = self._create_dim()
        val = ent.measurement()
        assert isinstance(val, float)
        assert val > 0

    def test_angleFormat(self):
        ent = self._create_dim()
        assert isinstance(ent.angleFormat(), Ax.AcAngleUnits)
        ent.setAngleFormat(Ax.AcAngleUnits.acGrads)
        assert ent.angleFormat() == Ax.AcAngleUnits.acGrads
        ent.setAngleFormat(Ax.AcAngleUnits.acDegrees)
        assert ent.angleFormat() == Ax.AcAngleUnits.acDegrees

    def test_angleVertex(self):
        ent = self._create_dim()
        assert isinstance(ent.angleVertex(), Ge.Point3d)
        new_vertex = Ge.Point3d(2, 4, 0)
        ent.setAngleVertex(new_vertex)
        assert ent.angleVertex() == new_vertex

    def test_arrowhead1Block(self):
        ent = self._create_dim()
        assert isinstance(ent.arrowhead1Block(), str)

    def test_arrowhead2Block(self):
        ent = self._create_dim()
        assert isinstance(ent.arrowhead2Block(), str)

    def test_arrowhead1Type(self):
        ent = self._create_dim()
        assert isinstance(ent.arrowhead1Type(), Ax.AcDimArrowheadType)
        ent.setArrowhead1Type(Ax.AcDimArrowheadType.acArrowBoxFilled)
        assert ent.arrowhead1Type() == Ax.AcDimArrowheadType.acArrowBoxFilled
        ent.setArrowhead1Type(Ax.AcDimArrowheadType.acArrowDefault)
        assert ent.arrowhead1Type() == Ax.AcDimArrowheadType.acArrowDefault

    def test_arrowhead2Type(self):
        ent = self._create_dim()
        assert isinstance(ent.arrowhead2Type(), Ax.AcDimArrowheadType)
        ent.setArrowhead2Type(Ax.AcDimArrowheadType.acArrowBoxFilled)
        assert ent.arrowhead2Type() == Ax.AcDimArrowheadType.acArrowBoxFilled
        ent.setArrowhead2Type(Ax.AcDimArrowheadType.acArrowDefault)
        assert ent.arrowhead2Type() == Ax.AcDimArrowheadType.acArrowDefault

    def test_arrowheadSize(self):
        ent = self._create_dim()
        assert isinstance(ent.arrowheadSize(), float)
        ent.setArrowheadSize(5.0)
        assert ent.arrowheadSize() == 5.0

    def test_dimLine1Suppress(self):
        ent = self._create_dim()
        assert isinstance(ent.dimLine1Suppress(), bool)
        ent.setDimLine1Suppress(True)
        assert ent.dimLine1Suppress() is True
        ent.setDimLine1Suppress(False)
        assert ent.dimLine1Suppress() is False

    def test_dimLine2Suppress(self):
        ent = self._create_dim()
        assert isinstance(ent.dimLine2Suppress(), bool)
        ent.setDimLine2Suppress(True)
        assert ent.dimLine2Suppress() is True
        ent.setDimLine2Suppress(False)
        assert ent.dimLine2Suppress() is False

    def test_dimLineInside(self):
        ent = self._create_dim()
        assert isinstance(ent.dimLineInside(), bool)
        ent.setDimLineInside(True)
        assert ent.dimLineInside() is True
        ent.setDimLineInside(False)
        assert ent.dimLineInside() is False

    def test_dimensionLineColor(self):
        ent = self._create_dim()
        assert isinstance(ent.dimensionLineColor(), Ax.AcColor)
        ent.setDimensionLineColor(Ax.AcColor.acRed)
        assert ent.dimensionLineColor() == Ax.AcColor.acRed
        ent.setDimensionLineColor(Ax.AcColor.acByBlock)
        assert ent.dimensionLineColor() == Ax.AcColor.acByBlock

    def test_dimensionLineWeight(self):
        ent = self._create_dim()
        assert isinstance(ent.dimensionLineWeight(), Ax.AcLineWeight)
        ent.setDimensionLineWeight(Ax.AcLineWeight.acLnWt070)
        assert ent.dimensionLineWeight() == Ax.AcLineWeight.acLnWt070

    def test_dimensionLinetype(self):
        ent = self._create_dim()
        assert isinstance(ent.dimensionLinetype(), str)
        ent.setDimensionLinetype("Continuous")
        assert ent.dimensionLinetype() == "Continuous"

    def test_extLine1EndPoint(self):
        ent = self._create_dim()
        assert isinstance(ent.extLine1EndPoint(), Ge.Point3d)
        new_point = Ge.Point3d(5, 5, 0)
        ent.setExtLine1EndPoint(new_point)
        assert ent.extLine1EndPoint() == new_point

    def test_extLine2EndPoint(self):
        ent = self._create_dim()
        assert isinstance(ent.extLine2EndPoint(), Ge.Point3d)
        new_point = Ge.Point3d(5, 3, 0)
        ent.setExtLine2EndPoint(new_point)
        assert ent.extLine2EndPoint() == new_point

    def test_extLine1Linetype(self):
        ent = self._create_dim()
        assert isinstance(ent.extLine1Linetype(), str)
        ent.setExtLine1Linetype("Continuous")
        assert ent.extLine1Linetype() == "Continuous"

    def test_extLine2Linetype(self):
        ent = self._create_dim()
        assert isinstance(ent.extLine2Linetype(), str)
        ent.setExtLine2Linetype("Continuous")
        assert ent.extLine2Linetype() == "Continuous"

    def test_extLine1Suppress(self):
        ent = self._create_dim()
        assert isinstance(ent.extLine1Suppress(), bool)
        ent.setExtLine1Suppress(True)
        assert ent.extLine1Suppress() is True
        ent.setExtLine1Suppress(False)
        assert ent.extLine1Suppress() is False

    def test_extLine2Suppress(self):
        ent = self._create_dim()
        assert isinstance(ent.extLine2Suppress(), bool)
        ent.setExtLine2Suppress(True)
        assert ent.extLine2Suppress() is True
        ent.setExtLine2Suppress(False)
        assert ent.extLine2Suppress() is False

    def test_extLineFixedLen(self):
        ent = self._create_dim()
        assert isinstance(ent.extLineFixedLen(), float)
        ent.setExtLineFixedLen(10.0)
        assert ent.extLineFixedLen() == 10.0

    def test_extLineFixedLenSuppress(self):
        ent = self._create_dim()
        assert isinstance(ent.extLineFixedLenSuppress(), bool)
        ent.setExtLineFixedLenSuppress(True)
        assert ent.extLineFixedLenSuppress() is True
        ent.setExtLineFixedLenSuppress(False)
        assert ent.extLineFixedLenSuppress() is False

    def test_extensionLineColor(self):
        ent = self._create_dim()
        assert isinstance(ent.extensionLineColor(), Ax.AcColor)
        ent.setExtensionLineColor(Ax.AcColor.acBlue)
        assert ent.extensionLineColor() == Ax.AcColor.acBlue
        ent.setExtensionLineColor(Ax.AcColor.acByBlock)
        assert ent.extensionLineColor() == Ax.AcColor.acByBlock

    def test_extensionLineExtend(self):
        ent = self._create_dim()
        assert isinstance(ent.extensionLineExtend(), float)
        ent.setExtensionLineExtend(2.5)
        assert ent.extensionLineExtend() == 2.5

    def test_extensionLineOffset(self):
        ent = self._create_dim()
        assert isinstance(ent.extensionLineOffset(), float)
        ent.setExtensionLineOffset(1.5)
        assert ent.extensionLineOffset() == 1.5

    def test_extensionLineWeight(self):
        ent = self._create_dim()
        assert isinstance(ent.extensionLineWeight(), Ax.AcLineWeight)
        ent.setExtensionLineWeight(Ax.AcLineWeight.acLnWt050)
        assert ent.extensionLineWeight() == Ax.AcLineWeight.acLnWt050

    def test_fit(self):
        ent = self._create_dim()
        assert isinstance(ent.fit(), Ax.AcDimFit)
        ent.setFit(Ax.AcDimFit.acTextOnly)
        assert ent.fit() == Ax.AcDimFit.acTextOnly
        ent.setFit(Ax.AcDimFit.acBestFit)
        assert ent.fit() == Ax.AcDimFit.acBestFit

    def test_forceLineInside(self):
        ent = self._create_dim()
        assert isinstance(ent.forceLineInside(), bool)
        ent.setForceLineInside(True)
        assert ent.forceLineInside() is True
        ent.setForceLineInside(False)
        assert ent.forceLineInside() is False

    def test_horizontalTextPosition(self):
        ent = self._create_dim()
        assert isinstance(ent.horizontalTextPosition(), Ax.AcDimHorizontalJustification)
        ent.setHorizontalTextPosition(Ax.AcDimHorizontalJustification.acHorzCentered)
        assert ent.horizontalTextPosition() == Ax.AcDimHorizontalJustification.acHorzCentered
        ent.setHorizontalTextPosition(Ax.AcDimHorizontalJustification.acOverFirstExtension)
        assert ent.horizontalTextPosition() == Ax.AcDimHorizontalJustification.acOverFirstExtension

    def test_textInside(self):
        ent = self._create_dim()
        assert isinstance(ent.textInside(), bool)
        ent.setTextInside(True)
        assert ent.textInside() is True
        ent.setTextInside(False)
        assert ent.textInside() is False

    def test_textInsideAlign(self):
        ent = self._create_dim()
        assert isinstance(ent.textInsideAlign(), bool)
        ent.setTextInsideAlign(True)
        assert ent.textInsideAlign() is True
        ent.setTextInsideAlign(False)
        assert ent.textInsideAlign() is False

    def test_textOutsideAlign(self):
        ent = self._create_dim()
        assert isinstance(ent.textOutsideAlign(), bool)
        ent.setTextOutsideAlign(True)
        assert ent.textOutsideAlign() is True
        ent.setTextOutsideAlign(False)
        assert ent.textOutsideAlign() is False

    def test_textPrecision(self):
        ent = self._create_dim()
        assert isinstance(ent.textPrecision(), Ax.AcDimPrecision)
        ent.setTextPrecision(Ax.AcDimPrecision.acDimPrecisionThree)
        assert ent.textPrecision() == Ax.AcDimPrecision.acDimPrecisionThree
        ent.setTextPrecision(Ax.AcDimPrecision.acDimPrecisionZero)
        assert ent.textPrecision() == Ax.AcDimPrecision.acDimPrecisionZero

    def test_dimConstrName(self):
        ent = self._create_dim()
        with pytest.raises(RuntimeError, match="Catastrophic failure"):
            ent.dimConstrName()

    def test_dimConstrExpression(self):
        ent = self._create_dim()
        with pytest.raises(RuntimeError, match="Catastrophic failure"):
            ent.dimConstrExpression()

    def test_dimConstrValue(self):
        ent = self._create_dim()
        with pytest.raises(RuntimeError, match="Catastrophic failure"):
            ent.dimConstrValue()

    def test_dimConstrDesc(self):
        ent = self._create_dim()
        with pytest.raises(RuntimeError, match="Catastrophic failure"):
            ent.dimConstrDesc()

    def test_dimConstrForm(self):
        ent = self._create_dim()
        assert isinstance(ent.dimConstrForm(), bool)

    def test_dimConstrReference(self):
        ent = self._create_dim()
        assert isinstance(ent.dimConstrReference(), bool)
