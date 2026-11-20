from __future__ import annotations

from pyrx import Ap, Ax, Ge


class TestAxDimArcLength:
    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def _create_dim(self):
        axSpace = self.axDoc.modelSpace()
        return axSpace.addDimArc(
            Ge.Point3d(0, 0, 0),
            Ge.Point3d(100, 0, 0),
            Ge.Point3d(0, 100, 0),
            Ge.Point3d(70.71, 70.71, 0)
        )

    def test_create(self):
        ent = self._create_dim()
        assert ent.objectName() == "AcDbArcDimension"
        assert ent.entityType() == Ax.AcEntityName.acDimArcLength

    def test_cast(self):
        ent = self._create_dim()
        casted = Ax.AcadDimArcLength.cast(ent)
        assert casted is not None
        assert casted.objectName() == "AcDbArcDimension"

    def test_className(self):
        assert Ax.AcadDimArcLength.className() == "AcadDimArcLength"

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

    def test_arcEndParam(self):
        ent = self._create_dim()
        assert isinstance(ent.arcEndParam(), float)

    def test_arcPoint(self):
        ent = self._create_dim()
        assert isinstance(ent.arcPoint(), Ge.Point3d)

    def test_arcStartParam(self):
        ent = self._create_dim()
        assert isinstance(ent.arcStartParam(), float)

    def test_arrowhead1Block(self):
        ent = self._create_dim()
        assert isinstance(ent.arrowhead1Block(), str)

    def test_arrowhead1Type(self):
        ent = self._create_dim()
        assert isinstance(ent.arrowhead1Type(), Ax.AcDimArrowheadType)
        ent.setArrowhead1Type(Ax.AcDimArrowheadType.acArrowBoxFilled)
        assert ent.arrowhead1Type() == Ax.AcDimArrowheadType.acArrowBoxFilled
        ent.setArrowhead1Type(Ax.AcDimArrowheadType.acArrowDefault)
        assert ent.arrowhead1Type() == Ax.AcDimArrowheadType.acArrowDefault

    def test_arrowhead2Block(self):
        ent = self._create_dim()
        assert isinstance(ent.arrowhead2Block(), str)

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

    def test_centerPoint(self):
        ent = self._create_dim()
        assert isinstance(ent.centerPoint(), Ge.Point3d)

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

    def test_dimensionLineExtend(self):
        ent = self._create_dim()
        assert isinstance(ent.dimensionLineExtend(), float)
        ent.setDimensionLineExtend(1.5)
        assert ent.dimensionLineExtend() == 1.5

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

    def test_extLine1Linetype(self):
        ent = self._create_dim()
        assert isinstance(ent.extLine1Linetype(), str)
        ent.setExtLine1Linetype("Continuous")
        assert ent.extLine1Linetype() == "Continuous"

    def test_extLine1Point(self):
        ent = self._create_dim()
        assert isinstance(ent.extLine1Point(), Ge.Point3d)
        new_point = Ge.Point3d(1, 1, 0)
        ent.setExtLine1Point(new_point)
        assert ent.extLine1Point() == new_point

    def test_extLine1Suppress(self):
        ent = self._create_dim()
        assert isinstance(ent.extLine1Suppress(), bool)
        ent.setExtLine1Suppress(True)
        assert ent.extLine1Suppress() is True
        ent.setExtLine1Suppress(False)
        assert ent.extLine1Suppress() is False

    def test_extLine2Linetype(self):
        ent = self._create_dim()
        assert isinstance(ent.extLine2Linetype(), str)
        ent.setExtLine2Linetype("Continuous")
        assert ent.extLine2Linetype() == "Continuous"

    def test_extLine2Point(self):
        ent = self._create_dim()
        assert isinstance(ent.extLine2Point(), Ge.Point3d)
        new_point = Ge.Point3d(99, 1, 0)
        ent.setExtLine2Point(new_point)
        assert ent.extLine2Point() == new_point

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

    def test_fractionFormat(self):
        ent = self._create_dim()
        assert isinstance(ent.fractionFormat(), Ax.AcDimFractionType)
        ent.setFractionFormat(Ax.AcDimFractionType.acDiagonal)
        assert ent.fractionFormat() == Ax.AcDimFractionType.acDiagonal
        ent.setFractionFormat(Ax.AcDimFractionType.acHorizontal)
        assert ent.fractionFormat() == Ax.AcDimFractionType.acHorizontal

    def test_hasLeader(self):
        ent = self._create_dim()
        assert isinstance(ent.hasLeader(), bool)

    def test_horizontalTextPosition(self):
        ent = self._create_dim()
        assert isinstance(ent.horizontalTextPosition(), Ax.AcDimHorizontalJustification)
        ent.setHorizontalTextPosition(Ax.AcDimHorizontalJustification.acHorzCentered)
        assert ent.horizontalTextPosition() == Ax.AcDimHorizontalJustification.acHorzCentered
        ent.setHorizontalTextPosition(Ax.AcDimHorizontalJustification.acOverFirstExtension)
        assert ent.horizontalTextPosition() == Ax.AcDimHorizontalJustification.acOverFirstExtension

    def test_isPartial(self):
        ent = self._create_dim()
        assert isinstance(ent.isPartial(), bool)

    def test_leader1Point(self):
        ent = self._create_dim()
        assert isinstance(ent.leader1Point(), Ge.Point3d)

    def test_leader2Point(self):
        ent = self._create_dim()
        assert isinstance(ent.leader2Point(), Ge.Point3d)

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

    def test_symbolPosition(self):
        ent = self._create_dim()
        assert isinstance(ent.symbolPosition(), Ax.AcDimArcLengthSymbol)
        ent.setSymbolPosition(Ax.AcDimArcLengthSymbol.acSymAbove)
        assert ent.symbolPosition() == Ax.AcDimArcLengthSymbol.acSymAbove
        ent.setSymbolPosition(Ax.AcDimArcLengthSymbol.acSymNone)
        assert ent.symbolPosition() == Ax.AcDimArcLengthSymbol.acSymNone

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
