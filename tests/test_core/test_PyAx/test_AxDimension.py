from __future__ import annotations

from pyrx import Ap, Ax, Ge


class TestAxDimension:
    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def _create_dim(self):
        axSpace = self.axDoc.modelSpace()
        return axSpace.addDimAligned(
            Ge.Point3d(0, 0, 0), Ge.Point3d(100, 0, 0), Ge.Point3d(50, 10, 0)
        )

    def test_cast(self):
        ent = self._create_dim()
        casted = Ax.AcadDimension.cast(ent)
        assert casted is not None
        assert casted.objectName() == "AcDbAlignedDimension"

    def test_className(self):
        assert Ax.AcadDimension.className() == "AcadDimension"

    def test_decimalSeparator(self):
        ent = self._create_dim()
        assert isinstance(ent.decimalSeparator(), str)
        ent.setDecimalSeparator(",")
        assert ent.decimalSeparator() == ","

    def test_dimTxtDirection(self):
        ent = self._create_dim()
        assert isinstance(ent.dimTxtDirection(), bool)
        ent.setDimTxtDirection(True)
        assert ent.dimTxtDirection() is True
        ent.setDimTxtDirection(False)
        assert ent.dimTxtDirection() is False

    def test_normal(self):
        ent = self._create_dim()
        assert isinstance(ent.normal(), Ge.Vector3d)
        new_normal = Ge.Vector3d(0, 0, 1)
        ent.setNormal(new_normal)
        assert ent.normal() == new_normal

    def test_rotation(self):
        ent = self._create_dim()
        assert isinstance(ent.rotation(), float)
        ent.setRotation(1.0)
        assert ent.rotation() == 1.0

    def test_scaleFactor(self):
        ent = self._create_dim()
        assert isinstance(ent.scaleFactor(), float)
        ent.setScaleFactor(2.0)
        assert ent.scaleFactor() == 2.0

    def test_styleName(self):
        ent = self._create_dim()
        assert isinstance(ent.styleName(), str)
        ent.setStyleName("Standard")
        assert ent.styleName() == "Standard"

    def test_suppressLeadingZeros(self):
        ent = self._create_dim()
        assert isinstance(ent.suppressLeadingZeros(), bool)
        ent.setSuppressLeadingZeros(True)
        assert ent.suppressLeadingZeros() is True
        ent.setSuppressLeadingZeros(False)
        assert ent.suppressLeadingZeros() is False

    def test_suppressTrailingZeros(self):
        ent = self._create_dim()
        assert isinstance(ent.suppressTrailingZeros(), bool)
        ent.setSuppressTrailingZeros(True)
        assert ent.suppressTrailingZeros() is True
        ent.setSuppressTrailingZeros(False)
        assert ent.suppressTrailingZeros() is False

    def test_textColor(self):
        ent = self._create_dim()
        assert isinstance(ent.textColor(), Ax.AcColor)
        ent.setTextColor(Ax.AcColor.acRed)
        assert ent.textColor() == Ax.AcColor.acRed
        ent.setTextColor(Ax.AcColor.acByBlock)
        assert ent.textColor() == Ax.AcColor.acByBlock

    def test_textFill(self):
        ent = self._create_dim()
        assert isinstance(ent.textFill(), bool)
        ent.setTextFill(True)
        assert ent.textFill() is True
        ent.setTextFill(False)
        assert ent.textFill() is False

    def test_textFillColor(self):
        ent = self._create_dim()
        assert isinstance(ent.textFillColor(), Ax.AcColor)
        ent.setTextFillColor(Ax.AcColor.acBlue)
        assert ent.textFillColor() == Ax.AcColor.acBlue
        ent.setTextFillColor(Ax.AcColor.acByBlock)
        assert ent.textFillColor() == Ax.AcColor.acByBlock

    def test_textGap(self):
        ent = self._create_dim()
        assert isinstance(ent.textGap(), float)
        ent.setTextGap(0.5)
        assert ent.textGap() == 0.5

    def test_textHeight(self):
        ent = self._create_dim()
        assert isinstance(ent.textHeight(), float)
        ent.setTextHeight(2.5)
        assert ent.textHeight() == 2.5

    def test_textMovement(self):
        ent = self._create_dim()
        assert isinstance(ent.textMovement(), Ax.AcDimTextMovement)
        ent.setTextMovement(Ax.AcDimTextMovement.acDimLineWithText)
        assert ent.textMovement() == Ax.AcDimTextMovement.acDimLineWithText
        ent.setTextMovement(Ax.AcDimTextMovement.acMoveTextAddLeader)
        assert ent.textMovement() == Ax.AcDimTextMovement.acMoveTextAddLeader

    def test_textOverride(self):
        ent = self._create_dim()
        assert isinstance(ent.textOverride(), str)
        ent.setTextOverride("<100>")
        assert ent.textOverride() == "<100>"

    def test_textPosition(self):
        ent = self._create_dim()
        assert isinstance(ent.textPosition(), Ge.Point3d)
        new_point = Ge.Point3d(50, 20, 0)
        ent.setTextPosition(new_point)
        assert ent.textPosition() == new_point

    def test_textPrefix(self):
        ent = self._create_dim()
        assert isinstance(ent.textPrefix(), str)
        ent.setTextPrefix("<")
        assert ent.textPrefix() == "<"

    def test_textRotation(self):
        ent = self._create_dim()
        assert isinstance(ent.textRotation(), float)
        ent.setTextRotation(1.0)
        assert ent.textRotation() == 1.0

    def test_textStyle(self):
        ent = self._create_dim()
        assert isinstance(ent.textStyle(), str)
        ent.setTextStyle("Standard")
        assert ent.textStyle() == "Standard"

    def test_textSuffix(self):
        ent = self._create_dim()
        assert isinstance(ent.textSuffix(), str)
        ent.setTextSuffix(">")
        assert ent.textSuffix() == ">"

    def test_toleranceDisplay(self):
        ent = self._create_dim()
        assert isinstance(ent.toleranceDisplay(), Ax.AcDimToleranceMethod)
        ent.setToleranceDisplay(Ax.AcDimToleranceMethod.acTolNone)
        assert ent.toleranceDisplay() == Ax.AcDimToleranceMethod.acTolNone
        ent.setToleranceDisplay(Ax.AcDimToleranceMethod.acTolSymmetrical)
        assert ent.toleranceDisplay() == Ax.AcDimToleranceMethod.acTolSymmetrical

    def test_toleranceHeightScale(self):
        ent = self._create_dim()
        assert isinstance(ent.toleranceHeightScale(), float)
        ent.setToleranceHeightScale(1.0)
        assert ent.toleranceHeightScale() == 1.0

    def test_toleranceJustification(self):
        ent = self._create_dim()
        assert isinstance(ent.toleranceJustification(), Ax.AcDimToleranceJustify)
        ent.setToleranceJustification(Ax.AcDimToleranceJustify.acTolBottom)
        assert ent.toleranceJustification() == Ax.AcDimToleranceJustify.acTolBottom
        ent.setToleranceJustification(Ax.AcDimToleranceJustify.acTolMiddle)
        assert ent.toleranceJustification() == Ax.AcDimToleranceJustify.acTolMiddle

    def test_toleranceLowerLimit(self):
        ent = self._create_dim()
        assert isinstance(ent.toleranceLowerLimit(), float)
        ent.setToleranceLowerLimit(-1.0)
        assert ent.toleranceLowerLimit() == -1.0

    def test_tolerancePrecision(self):
        ent = self._create_dim()
        assert isinstance(ent.tolerancePrecision(), Ax.AcDimPrecision)
        ent.setTolerancePrecision(Ax.AcDimPrecision.acDimPrecisionThree)
        assert ent.tolerancePrecision() == Ax.AcDimPrecision.acDimPrecisionThree
        ent.setTolerancePrecision(Ax.AcDimPrecision.acDimPrecisionZero)
        assert ent.tolerancePrecision() == Ax.AcDimPrecision.acDimPrecisionZero

    def test_toleranceSuppressLeadingZeros(self):
        ent = self._create_dim()
        assert isinstance(ent.toleranceSuppressLeadingZeros(), bool)
        ent.setToleranceSuppressLeadingZeros(True)
        assert ent.toleranceSuppressLeadingZeros() is True
        ent.setToleranceSuppressLeadingZeros(False)
        assert ent.toleranceSuppressLeadingZeros() is False

    def test_toleranceSuppressTrailingZeros(self):
        ent = self._create_dim()
        assert isinstance(ent.toleranceSuppressTrailingZeros(), bool)
        ent.setToleranceSuppressTrailingZeros(True)
        assert ent.toleranceSuppressTrailingZeros() is True
        ent.setToleranceSuppressTrailingZeros(False)
        assert ent.toleranceSuppressTrailingZeros() is False

    def test_toleranceUpperLimit(self):
        ent = self._create_dim()
        assert isinstance(ent.toleranceUpperLimit(), float)
        ent.setToleranceUpperLimit(1.0)
        assert ent.toleranceUpperLimit() == 1.0

    def test_verticalTextPosition(self):
        ent = self._create_dim()
        assert isinstance(ent.verticalTextPosition(), Ax.AcDimVerticalJustification)
        ent.setVerticalTextPosition(Ax.AcDimVerticalJustification.acVertCentered)
        assert ent.verticalTextPosition() == Ax.AcDimVerticalJustification.acVertCentered
        ent.setVerticalTextPosition(Ax.AcDimVerticalJustification.acAbove)
        assert ent.verticalTextPosition() == Ax.AcDimVerticalJustification.acAbove
