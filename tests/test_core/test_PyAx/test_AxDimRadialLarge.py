from __future__ import annotations

import pytest

from pyrx import Ap, Ax, Ge


class TestAcadDimRadialLarge:
    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def _create_dim(self):
        axSpace = self.axDoc.modelSpace()
        return axSpace.addDimRadialLarge(
            Ge.Point3d(0, 0, 0),
            Ge.Point3d(50, 0, 0),
            Ge.Point3d(0, 0, 0),
            Ge.Point3d(25, 0, 0),
            0.5,
        )

    def test_create(self):
        ent = self._create_dim()
        assert ent.objectName() == "AcDbRadialDimensionLarge"
        assert ent.entityType() == Ax.AcEntityName.acDimRadialLarge

    def test_cast(self):
        ent = self._create_dim()
        casted = Ax.AcadDimRadialLarge.cast(ent)
        assert casted is not None
        assert casted.objectName() == "AcDbRadialDimensionLarge"

    def test_className(self):
        assert Ax.AcadDimRadialLarge.className() == "AcadDimRadialLarge"

    def test_measurement(self):
        ent = self._create_dim()
        val = ent.measurement()
        assert isinstance(val, float)
        assert val > 0

    def test_center(self):
        ent = self._create_dim()
        assert isinstance(ent.center(), Ge.Point3d)
        new_center = Ge.Point3d(10, 10, 0)
        ent.setCenter(new_center)
        assert ent.center() == new_center

    def test_chordPoint(self):
        ent = self._create_dim()
        assert isinstance(ent.chordPoint(), Ge.Point3d)
        new_chord = Ge.Point3d(60, 0, 0)
        ent.setChordPoint(new_chord)
        assert ent.chordPoint() == new_chord

    def test_overrideCenter(self):
        ent = self._create_dim()
        assert isinstance(ent.overrideCenter(), Ge.Point3d)
        new_center = Ge.Point3d(5, 5, 0)
        ent.setOverrideCenter(new_center)
        assert ent.overrideCenter() == new_center

    def test_jogLocation(self):
        ent = self._create_dim()
        assert isinstance(ent.jogLocation(), Ge.Point3d)
        new_loc = Ge.Point3d(30, 0, 0)
        ent.setJogLocation(new_loc)
        assert ent.jogLocation() == new_loc

    def test_jogAngle(self):
        ent = self._create_dim()
        assert isinstance(ent.jogAngle(), float)
        ent.setJogAngle(1.0)
        assert ent.jogAngle() == 1.0

    def test_altRoundDistance(self):
        ent = self._create_dim()
        assert isinstance(ent.altRoundDistance(), float)
        ent.setAltRoundDistance(1.0)
        assert ent.altRoundDistance() == 1.0

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

    def test_arrowheadBlock(self):
        ent = self._create_dim()
        assert isinstance(ent.arrowheadBlock(), str)

    def test_arrowheadType(self):
        ent = self._create_dim()
        assert isinstance(ent.arrowheadType(), Ax.AcDimArrowheadType)
        ent.setArrowheadType(Ax.AcDimArrowheadType.acArrowBoxFilled)
        assert ent.arrowheadType() == Ax.AcDimArrowheadType.acArrowBoxFilled
        ent.setArrowheadType(Ax.AcDimArrowheadType.acArrowDefault)
        assert ent.arrowheadType() == Ax.AcDimArrowheadType.acArrowDefault

    def test_arrowheadSize(self):
        ent = self._create_dim()
        assert isinstance(ent.arrowheadSize(), float)
        ent.setArrowheadSize(5.0)
        assert ent.arrowheadSize() == 5.0

    def test_centerMarkSize(self):
        ent = self._create_dim()
        assert isinstance(ent.centerMarkSize(), float)
        ent.setCenterMarkSize(5.0)
        assert ent.centerMarkSize() == 5.0

    def test_centerType(self):
        ent = self._create_dim()
        assert isinstance(ent.centerType(), Ax.AcDimCenterType)
        ent.setCenterType(Ax.AcDimCenterType.acCenterMark)
        assert ent.centerType() == Ax.AcDimCenterType.acCenterMark
        ent.setCenterType(Ax.AcDimCenterType.acCenterLine)
        assert ent.centerType() == Ax.AcDimCenterType.acCenterLine
        ent.setCenterType(Ax.AcDimCenterType.acCenterNone)
        assert ent.centerType() == Ax.AcDimCenterType.acCenterNone

    def test_dimLineSuppress(self):
        ent = self._create_dim()
        assert isinstance(ent.dimLineSuppress(), bool)
        ent.setDimLineSuppress(True)
        assert ent.dimLineSuppress() is True
        ent.setDimLineSuppress(False)
        assert ent.dimLineSuppress() is False

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
