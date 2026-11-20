from __future__ import annotations

from pyrx import Ap, Ax, Ge


class TestAxDimOrdinate:
    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def _create_dim(self):
        axSpace = self.axDoc.modelSpace()
        return axSpace.addDimOrdinate(
            Ge.Point3d(0, 5, 0), Ge.Point3d(10, 5, 0), 1
        )

    def test_create(self):
        ent = self._create_dim()
        assert ent.objectName() == "AcDbOrdinateDimension"
        assert ent.entityType() == Ax.AcEntityName.acDimOrdinate

    def test_cast(self):
        ent = self._create_dim()
        casted = Ax.AcadDimOrdinate.cast(ent)
        assert casted is not None
        assert casted.objectName() == "AcDbOrdinateDimension"

    def test_className(self):
        assert Ax.AcadDimOrdinate.className() == "AcadDimOrdinate"

    def test_measurement(self):
        ent = self._create_dim()
        val = ent.measurement()
        assert isinstance(val, float)
        assert val > 0

    def test_altRoundDistance(self):
        ent = self._create_dim()
        assert isinstance(ent.altRoundDistance(), float)
        ent.setAltRoundDistance(1.0)
        assert ent.altRoundDistance() == 1.0

    def test_altSubUnitsFactor(self):
        ent = self._create_dim()
        assert isinstance(ent.altSubUnitsFactor(), float)
        ent.setAltSubUnitsFactor(12.0)
        assert ent.altSubUnitsFactor() == 12.0

    def test_altSubUnitsSuffix(self):
        ent = self._create_dim()
        assert isinstance(ent.altSubUnitsSuffix(), str)
        ent.setAltSubUnitsSuffix("ft")
        assert ent.altSubUnitsSuffix() == "ft"

    def test_altSuppressLeadingZeros(self):
        ent = self._create_dim()
        assert isinstance(ent.altSuppressLeadingZeros(), bool)
        ent.setAltSuppressLeadingZeros(True)
        assert ent.altSuppressLeadingZeros() is True
        ent.setAltSuppressLeadingZeros(False)
        assert ent.altSuppressLeadingZeros() is False

    def test_altSuppressTrailingZeros(self):
        ent = self._create_dim()
        assert isinstance(ent.altSuppressTrailingZeros(), bool)
        ent.setAltSuppressTrailingZeros(True)
        assert ent.altSuppressTrailingZeros() is True
        ent.setAltSuppressTrailingZeros(False)
        assert ent.altSuppressTrailingZeros() is False

    def test_altSuppressZeroFeet(self):
        ent = self._create_dim()
        assert isinstance(ent.altSuppressZeroFeet(), bool)
        ent.setAltSuppressZeroFeet(True)
        assert ent.altSuppressZeroFeet() is True
        ent.setAltSuppressZeroFeet(False)
        assert ent.altSuppressZeroFeet() is False

    def test_altSuppressZeroInches(self):
        ent = self._create_dim()
        ent.setAltUnits(True)
        ent.setAltUnitsFormat(Ax.AcDimUnits.acDimEngineering)
        assert isinstance(ent.altSuppressZeroInches(), bool)
        ent.setAltSuppressZeroInches(True)
        ent.setAltSuppressZeroInches(False)
        ent.setAltSuppressZeroInches(False)
        assert ent.altSuppressZeroInches() is False

    def test_altTextPrefix(self):
        ent = self._create_dim()
        assert isinstance(ent.altTextPrefix(), str)
        ent.setAltTextPrefix("<")
        assert ent.altTextPrefix() == "<"

    def test_altTextSuffix(self):
        ent = self._create_dim()
        assert isinstance(ent.altTextSuffix(), str)
        ent.setAltTextSuffix(">")
        assert ent.altTextSuffix() == ">"

    def test_altTolerancePrecision(self):
        ent = self._create_dim()
        assert isinstance(ent.altTolerancePrecision(), Ax.AcDimPrecision)
        ent.setAltTolerancePrecision(Ax.AcDimPrecision.acDimPrecisionThree)
        assert ent.altTolerancePrecision() == Ax.AcDimPrecision.acDimPrecisionThree
        ent.setAltTolerancePrecision(Ax.AcDimPrecision.acDimPrecisionZero)
        assert ent.altTolerancePrecision() == Ax.AcDimPrecision.acDimPrecisionZero

    def test_altToleranceSuppressLeadingZeros(self):
        ent = self._create_dim()
        ent.setAltUnits(True)
        ent.setAltUnitsFormat(Ax.AcDimUnits.acDimEngineering)
        assert isinstance(ent.altToleranceSuppressLeadingZeros(), bool)
        ent.setAltToleranceSuppressLeadingZeros(True)
        ent.setAltToleranceSuppressLeadingZeros(False)
        ent.setAltToleranceSuppressLeadingZeros(False)
        assert ent.altToleranceSuppressLeadingZeros() is False

    def test_altToleranceSuppressTrailingZeros(self):
        ent = self._create_dim()
        ent.setAltUnits(True)
        ent.setAltUnitsFormat(Ax.AcDimUnits.acDimEngineering)
        assert isinstance(ent.altToleranceSuppressTrailingZeros(), bool)
        ent.setAltToleranceSuppressTrailingZeros(True)
        ent.setAltToleranceSuppressTrailingZeros(False)
        ent.setAltToleranceSuppressTrailingZeros(False)
        assert ent.altToleranceSuppressTrailingZeros() is False

    def test_altToleranceSuppressZeroFeet(self):
        ent = self._create_dim()
        ent.setAltUnits(True)
        ent.setAltUnitsFormat(Ax.AcDimUnits.acDimEngineering)
        assert isinstance(ent.altToleranceSuppressZeroFeet(), bool)
        ent.setAltToleranceSuppressZeroFeet(True)
        ent.setAltToleranceSuppressZeroFeet(False)
        ent.setAltToleranceSuppressZeroFeet(False)
        assert ent.altToleranceSuppressZeroFeet() is False

    def test_altToleranceSuppressZeroInches(self):
        ent = self._create_dim()
        ent.setAltUnits(True)
        ent.setAltUnitsFormat(Ax.AcDimUnits.acDimEngineering)
        assert isinstance(ent.altToleranceSuppressZeroInches(), bool)
        ent.setAltToleranceSuppressZeroInches(True)
        ent.setAltToleranceSuppressZeroInches(False)
        ent.setAltToleranceSuppressZeroInches(False)
        assert ent.altToleranceSuppressZeroInches() is False

    def test_altUnits(self):
        ent = self._create_dim()
        assert isinstance(ent.altUnits(), bool)
        ent.setAltUnits(True)
        assert ent.altUnits() is True
        ent.setAltUnits(False)
        assert ent.altUnits() is False

    def test_altUnitsFormat(self):
        ent = self._create_dim()
        assert isinstance(ent.altUnitsFormat(), Ax.AcDimUnits)
        ent.setAltUnitsFormat(Ax.AcDimUnits.acDimDecimal)
        assert ent.altUnitsFormat() == Ax.AcDimUnits.acDimDecimal
        ent.setAltUnitsFormat(Ax.AcDimUnits.acDimEngineering)
        assert ent.altUnitsFormat() == Ax.AcDimUnits.acDimEngineering

    def test_altUnitsPrecision(self):
        ent = self._create_dim()
        assert isinstance(ent.altUnitsPrecision(), Ax.AcDimPrecision)
        ent.setAltUnitsPrecision(Ax.AcDimPrecision.acDimPrecisionThree)
        assert ent.altUnitsPrecision() == Ax.AcDimPrecision.acDimPrecisionThree
        ent.setAltUnitsPrecision(Ax.AcDimPrecision.acDimPrecisionZero)
        assert ent.altUnitsPrecision() == Ax.AcDimPrecision.acDimPrecisionZero

    def test_altUnitsScale(self):
        ent = self._create_dim()
        assert isinstance(ent.altUnitsScale(), float)
        ent.setAltUnitsScale(2.0)
        assert ent.altUnitsScale() == 2.0

    def test_arrowheadSize(self):
        ent = self._create_dim()
        assert isinstance(ent.arrowheadSize(), float)
        ent.setArrowheadSize(5.0)
        assert ent.arrowheadSize() == 5.0

    def test_extLineFixedLen(self):
        ent = self._create_dim()
        assert isinstance(ent.extLineFixedLen(), float)
        ent.setExtLineFixedLen(True)
        ent.setExtLineFixedLen(False)

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

    def test_fractionFormat(self):
        ent = self._create_dim()
        assert isinstance(ent.fractionFormat(), Ax.AcDimFractionType)
        ent.setFractionFormat(Ax.AcDimFractionType.acDiagonal)
        assert ent.fractionFormat() == Ax.AcDimFractionType.acDiagonal
        ent.setFractionFormat(Ax.AcDimFractionType.acHorizontal)
        assert ent.fractionFormat() == Ax.AcDimFractionType.acHorizontal

    def test_linearScaleFactor(self):
        ent = self._create_dim()
        assert isinstance(ent.linearScaleFactor(), float)
        ent.setLinearScaleFactor(2.0)
        assert ent.linearScaleFactor() == 2.0

    def test_primaryUnitsPrecision(self):
        ent = self._create_dim()
        assert isinstance(ent.primaryUnitsPrecision(), Ax.AcDimPrecision)
        ent.setPrimaryUnitsPrecision(Ax.AcDimPrecision.acDimPrecisionThree)
        assert ent.primaryUnitsPrecision() == Ax.AcDimPrecision.acDimPrecisionThree
        ent.setPrimaryUnitsPrecision(Ax.AcDimPrecision.acDimPrecisionZero)
        assert ent.primaryUnitsPrecision() == Ax.AcDimPrecision.acDimPrecisionZero

    def test_roundDistance(self):
        ent = self._create_dim()
        assert isinstance(ent.roundDistance(), float)
        ent.setRoundDistance(1.0)
        assert ent.roundDistance() == 1.0

    def test_subUnitsFactor(self):
        ent = self._create_dim()
        assert isinstance(ent.subUnitsFactor(), float)
        ent.setSubUnitsFactor(12.0)
        assert ent.subUnitsFactor() == 12.0

    def test_subUnitsSuffix(self):
        ent = self._create_dim()
        assert isinstance(ent.subUnitsSuffix(), str)
        ent.setSubUnitsSuffix("in")
        assert ent.subUnitsSuffix() == "in"

    def test_suppressZeroFeet(self):
        ent = self._create_dim()
        ent.setUnitsFormat(Ax.AcDimLUnits.acDimLEngineering)
        assert isinstance(ent.suppressZeroFeet(), bool)
        ent.setSuppressZeroFeet(True)
        ent.setSuppressZeroFeet(False)
        ent.setSuppressZeroFeet(False)
        assert ent.suppressZeroFeet() is False

    def test_suppressZeroInches(self):
        ent = self._create_dim()
        ent.setUnitsFormat(Ax.AcDimLUnits.acDimLEngineering)
        assert isinstance(ent.suppressZeroInches(), bool)
        ent.setSuppressZeroInches(True)
        ent.setSuppressZeroInches(False)
        ent.setSuppressZeroInches(False)
        assert ent.suppressZeroInches() is False

    def test_toleranceSuppressZeroFeet(self):
        ent = self._create_dim()
        ent.setUnitsFormat(Ax.AcDimLUnits.acDimLEngineering)
        assert isinstance(ent.toleranceSuppressZeroFeet(), bool)
        ent.setToleranceSuppressZeroFeet(True)
        ent.setToleranceSuppressZeroFeet(False)
        ent.setToleranceSuppressZeroFeet(False)
        assert ent.toleranceSuppressZeroFeet() is False

    def test_toleranceSuppressZeroInches(self):
        ent = self._create_dim()
        ent.setUnitsFormat(Ax.AcDimLUnits.acDimLEngineering)
        assert isinstance(ent.toleranceSuppressZeroInches(), bool)
        ent.setToleranceSuppressZeroInches(True)
        ent.setToleranceSuppressZeroInches(False)
        ent.setToleranceSuppressZeroInches(False)
        assert ent.toleranceSuppressZeroInches() is False

    def test_unitsFormat(self):
        ent = self._create_dim()
        assert isinstance(ent.unitsFormat(), Ax.AcDimLUnits)
        ent.setUnitsFormat(Ax.AcDimLUnits.acDimLDecimal)
        assert ent.unitsFormat() == Ax.AcDimLUnits.acDimLDecimal
        ent.setUnitsFormat(Ax.AcDimLUnits.acDimLEngineering)
        assert ent.unitsFormat() == Ax.AcDimLUnits.acDimLEngineering
