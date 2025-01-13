#pragma once
//For the Python side, avoid adding eeeww ActiveX stuff

enum PyAcBoolean
{
    pyacFalse = 0,
    pyacTrue = 1
};

enum PyAcOnOff
{
    pyacOff = 0,
    pyacOn = 1
};

enum PyAcEntityName
{
    pyac3dFace = 1,
    pyac3dPolyline = 2,
    pyac3dSolid = 3,
    pyacArc = 4,
    pyacAttribute = 5,
    pyacAttributeReference = 6,
    pyacBlockReference = 7,
    pyacCircle = 8,
    pyacDimAligned = 9,
    pyacDimAngular = 10,
    pyacDimDiametric = 12,
    pyacDimOrdinate = 13,
    pyacDimRadial = 14,
    pyacDimRotated = 15,
    pyacEllipse = 16,
    pyacHatch = 17,
    pyacLeader = 18,
    pyacLine = 19,
    pyacMtext = 21,
    pyacPoint = 22,
    pyacPolyline = 23,
    pyacPolylineLight = 24,
    pyacPolymesh = 25,
    pyacRaster = 26,
    pyacRay = 27,
    pyacRegion = 28,
    pyacShape = 29,
    pyacSolid = 30,
    pyacSpline = 31,
    pyacText = 32,
    pyacTolerance = 33,
    pyacTrace = 34,
    pyacPViewport = 35,
    pyacXline = 36,
    pyacGroup = 37,
    pyacMInsertBlock = 38,
    pyacPolyfaceMesh = 39,
    pyacMLine = 40,
    pyacDim3PointAngular = 41,
    pyacExternalReference = 42,
    pyacTable = 43,
    pyacDimArcLength = 44,
    pyacDimRadialLarge = 45,
    pyacDwfUnderlay = 46,
    pyacDgnUnderlay = 47,
    pyacMLeader = 48,
    pyacSubDMesh = 49,
    pyacPdfUnderlay = 50,
    pyacNurbSurface = 51
};

enum PyAcActiveSppyace
{
    pyacPaperSpace = 0,
    pyacModelSpace = 1
};

enum PyAcKeyboardAccelerator
{
    pyacPreferenceClassic = 0,
    pyacPreferenceCustom = 1
};

enum PyAcPlotOrientation
{
    pyacPlotOrientationPortrait = 0,
    pyacPlotOrientationLandscape = 1
};

enum PyAcColor
{
    pyacByBlock = 0,
    pyacRed = 1,
    pyacYellow = 2,
    pyacGreen = 3,
    pyacCyan = 4,
    pyacBlue = 5,
    pyacMagenta = 6,
    pyacWhite = 7,
    pyacByLayer = 256
};

enum PyAcAttpyachmentPoint
{
    pyacAttachmentPointTopLeft = 1,
    pyacAttachmentPointTopCenter = 2,
    pyacAttachmentPointTopRight = 3,
    pyacAttachmentPointMiddleLeft = 4,
    pyacAttachmentPointMiddleCenter = 5,
    pyacAttachmentPointMiddleRight = 6,
    pyacAttachmentPointBottomLeft = 7,
    pyacAttachmentPointBottomCenter = 8,
    pyacAttachmentPointBottomRight = 9
};

enum PyAcDrawingDirection
{
    pyacLeftToRight = 1,
    pyacRightToLeft = 2,
    pyacTopToBottom = 3,
    pyacBottomToTop = 4,
    pyacByStyle = 5
};

enum PyAcLeaderType
{
    pyacLineNoArrow = 0,
    pyacSplineNoArrow = 1,
    pyacLineWithArrow = 2,
    pyacSplineWithArrow = 3
};

enum PyAcAttributeMode
{
    pyacAttributeModeNormal = 0,
    pyacAttributeModeInvisible = 1,
    pyacAttributeModeConstant = 2,
    pyacAttributeModeVerify = 4,
    pyacAttributeModePreset = 8,
    pyacAttributeModeLockPosition = 16,
    pyacAttributeModeMultipleLine = 32
};

enum PyAcHorizontalAlignment
{
    pyacHorizontalAlignmentLeft = 0,
    pyacHorizontalAlignmentCenter = 1,
    pyacHorizontalAlignmentRight = 2,
    pyacHorizontalAlignmentAligned = 3,
    pyacHorizontalAlignmentMiddle = 4,
    pyacHorizontalAlignmentFit = 5
};

enum PyAcVerticalAlignment
{
    pyacVerticalAlignmentBaseline = 0,
    pyacVerticalAlignmentBottom = 1,
    pyacVerticalAlignmentMiddle = 2,
    pyacVerticalAlignmentTop = 3
};

enum PyAcTextGenerationFlag
{
    pyacTextFlagBackward = 2,
    pyacTextFlagUpsideDown = 4
};

enum PyAcSelect
{
    pyacSelectionSetWindow = 0,
    pyacSelectionSetCrossing = 1,
    pyacSelectionSetFence = 2,
    pyacSelectionSetPrevious = 3,
    pyacSelectionSetLast = 4,
    pyacSelectionSetAll = 5,
    pyacSelectionSetWindowPolygon = 6,
    pyacSelectionSetCrossingPolygon = 7
};

enum PyAcPatternType
{
    pyacHatchPatternTypeUserDefined = 0,
    pyacHatchPatternTypePreDefined = 1,
    pyacHatchPatternTypeCustomDefined = 2
};

enum PyAcLoopType
{
    pyacHatchLoopTypeDefault = 0,
    pyacHatchLoopTypeExternal = 1,
    pyacHatchLoopTypePolyline = 2,
    pyacHatchLoopTypeDerived = 4,
    pyacHatchLoopTypeTextbox = 8
};

enum PyAcHatchStyle
{
    pyacHatchStyleNormal = 0,
    pyacHatchStyleOuter = 1,
    pyacHatchStyleIgnore = 2
};

enum PyAcPolylineType
{
    pyacSimplePoly = 0,
    pyacFitCurvePoly = 1,
    pyacQuadSplinePoly = 2,
    pyacCubicSplinePoly = 3
};

enum PyAc3DPolylineType
{
    pyacSimple3DPoly = 0,
    pyacQuadSpline3DPoly = 1,
    pyacCubicSpline3DPoly = 2
};

enum PyAcViewportSplitType
{
    pyacViewport2Horizontal = 0,
    pyacViewport2Vertical = 1,
    pyacViewport3Left = 2,
    pyacViewport3Right = 3,
    pyacViewport3Horizontal = 4,
    pyacViewport3Vertical = 5,
    pyacViewport3Above = 6,
    pyacViewport3Below = 7,
    pyacViewport4 = 8
};

enum PyAcRegenType
{
    pyacActiveViewport = 0,
    pyacAllViewports = 1
};

enum PyAcBooleanType
{
    pyacUnion = 0,
    pyacIntersection = 1,
    pyacSubtraction = 2
};

enum PyAcExtendOption
{
    pyacExtendNone = 0,
    pyacExtendThisEntity = 1,
    pyacExtendOtherEntity = 2,
    pyacExtendBoth = 3
};

enum PyAcAngleUnits
{
    pyacDegrees = 0,
    pyacDegreeMinuteSeconds = 1,
    pyacGrads = 2,
    pyacRadians = 3
};

enum PyAcUnits
{
    pyacDefaultUnits = -1,
    pyacScientific = 1,
    pyacDecimal = 2,
    pyacEngineering = 3,
    pyacArchitectural = 4,
    pyacFractional = 5
};

enum PyAcCoordinateSystem
{
    pyacWorld = 0,
    pyacUCS = 1,
    pyacDisplayDCS = 2,
    pyacPaperSpaceDCS = 3,
    pyacOCS = 4
};

enum PyAcMeasurementUnits
{
    pyacEnglish = 0,
    pyacMetric = 1
};

enum PyAcXRefDemandLoad
{
    pyacDemandLoadDisabled = 0,
    pyacDemandLoadEnabled = 1,
    pyacDemandLoadEnabledWithCopy = 2
};

enum PyAcPreviewMode
{
    pyacPartialPreview = 0,
    pyacFullPreview = 1
};

enum PyAcPolymeshType
{
    pyacSimpleMesh = 0,
    pyacQuadSurfaceMesh = 5,
    pyacCubicSurfaceMesh = 6,
    pyacBezierSurfaceMesh = 8
};

enum PyAcZoomScaleType
{
    pyacZoomScaledAbsolute = 0,
    pyacZoomScaledRelative = 1,
    pyacZoomScaledRelativePSpace = 2
};

enum PyAcDragDisplayMode
{
    pyacDragDoNotDisplay = 0,
    pyacDragDisplayOnRequest = 1,
    pyacDragDisplayAutomatically = 2
};

enum PyAcARXDemandLoad
{
    pyacDemanLoadDisable = 0,
    pyacDemandLoadOnObjectDetect = 1,
    pyacDemandLoadCmdInvoke = 2
};

enum PyAcTextFontStyle
{
    pyacFontRegular = 0,
    pyacFontItalic = 1,
    pyacFontBold = 2,
    pyacFontBoldItalic = 3
};

enum PyAcProxyImage
{
    pyacProxyNotShow = 0,
    pyacProxyShow = 1,
    pyacProxyBoundingBox = 2
};

enum PyAcKeyboardPriority
{
    pyacKeyboardRunningObjSnap = 0,
    pyacKeyboardEntry = 1,
    pyacKeyboardEntryExceptScripts = 2
};

enum PyAcMenuGroupType
{
    pyacBaseMenuGroup = 0,
    pyacPartialMenuGroup = 1
};

enum PyAcMenuFileType
{
    pyacMenuFileCompiled = 0,
    pyacMenuFileSource = 1
};

enum PyAcMenuItemType
{
    pyacMenuItem = 0,
    pyacMenuSeparator = 1,
    pyacMenuSubMenu = 2
};

enum PyAcToolbarItemType
{
    pyacToolbarButton = 0,
    pyacToolbarSeparator = 1,
    pyacToolbarControl = 2,
    pyacToolbarFlyout = 3
};

enum PyAcToolbarDockStatus
{
    pyacToolbarDockTop = 0,
    pyacToolbarDockBottom = 1,
    pyacToolbarDockLeft = 2,
    pyacToolbarDockRight = 3,
    pyacToolbarFloating = 4
};

enum PyAcLineWeight
{
    pyacLnWt000 = 0,
    pyacLnWt005 = 5,
    pyacLnWt009 = 9,
    pyacLnWt013 = 13,
    pyacLnWt015 = 15,
    pyacLnWt018 = 18,
    pyacLnWt020 = 20,
    pyacLnWt025 = 25,
    pyacLnWt030 = 30,
    pyacLnWt035 = 35,
    pyacLnWt040 = 40,
    pyacLnWt050 = 50,
    pyacLnWt053 = 53,
    pyacLnWt060 = 60,
    pyacLnWt070 = 70,
    pyacLnWt080 = 80,
    pyacLnWt090 = 90,
    pyacLnWt100 = 100,
    pyacLnWt106 = 106,
    pyacLnWt120 = 120,
    pyacLnWt140 = 140,
    pyacLnWt158 = 158,
    pyacLnWt200 = 200,
    pyacLnWt211 = 211,
    pyacLnWtByLayer = -1,
    pyacLnWtByBlock = -2,
    pyacLnWtByLwDefault = -3
};

enum PyAcWindowState
{
    pyacNorm = 1,
    pyacMin = 2,
    pyacMax = 3,
};

enum PyAcPlotPaperUnits
{
    pyacInches = 0,
    pyacMillimeters = 1,
    pyacPixels = 2
};

enum PyAcPlotRotation
{
    pyac0degrees = 0,
    pyac90degrees = (pyac0degrees + 1),
    pyac180degrees = (pyac90degrees + 1),
    pyac270degrees = (pyac180degrees + 1)
};

enum PyAcPlotType
{
    pyacDisplay = 0,
    pyacExtents = (pyacDisplay + 1),
    pyacLimits = (pyacExtents + 1),
    pyacView = (pyacLimits + 1),
    pyacWindow = (pyacView + 1),
    pyacLayout = (pyacWindow + 1)
};

enum PyAcPlotScale
{
    pyacScaleToFit = 0,
    pyac1_128in_1ft = (pyacScaleToFit + 1),
    pyac1_64in_1ft = (pyac1_128in_1ft + 1),
    pyac1_32in_1ft = (pyac1_64in_1ft + 1),
    pyac1_16in_1ft = (pyac1_32in_1ft + 1),
    pyac3_32in_1ft = (pyac1_16in_1ft + 1),
    pyac1_8in_1ft = (pyac3_32in_1ft + 1),
    pyac3_16in_1ft = (pyac1_8in_1ft + 1),
    pyac1_4in_1ft = (pyac3_16in_1ft + 1),
    pyac3_8in_1ft = (pyac1_4in_1ft + 1),
    pyac1_2in_1ft = (pyac3_8in_1ft + 1),
    pyac3_4in_1ft = (pyac1_2in_1ft + 1),
    pyac1in_1ft = (pyac3_4in_1ft + 1),
    pyac3in_1ft = (pyac1in_1ft + 1),
    pyac6in_1ft = (pyac3in_1ft + 1),
    pyac1ft_1ft = (pyac6in_1ft + 1),
    pyac1_1 = (pyac1ft_1ft + 1),
    pyac1_2 = (pyac1_1 + 1),
    pyac1_4 = (pyac1_2 + 1),
    pyac1_5 = (pyac1_4 + 1),
    pyac1_8 = (pyac1_5 + 1),
    pyac1_10 = (pyac1_8 + 1),
    pyac1_16 = (pyac1_10 + 1),
    pyac1_20 = (pyac1_16 + 1),
    pyac1_30 = (pyac1_20 + 1),
    pyac1_40 = (pyac1_30 + 1),
    pyac1_50 = (pyac1_40 + 1),
    pyac1_100 = (pyac1_50 + 1),
    pyac2_1 = (pyac1_100 + 1),
    pyac4_1 = (pyac2_1 + 1),
    pyac8_1 = (pyac4_1 + 1),
    pyac10_1 = (pyac8_1 + 1),
    pyac100_1 = (pyac10_1 + 1)
};

enum PyAcAlignment
{
    pyacAlignmentLeft = 0,
    pyacAlignmentCenter = (pyacAlignmentLeft + 1),
    pyacAlignmentRight = (pyacAlignmentCenter + 1),
    pyacAlignmentAligned = (pyacAlignmentRight + 1),
    pyacAlignmentMiddle = (pyacAlignmentAligned + 1),
    pyacAlignmentFit = (pyacAlignmentMiddle + 1),
    pyacAlignmentTopLeft = (pyacAlignmentFit + 1),
    pyacAlignmentTopCenter = (pyacAlignmentTopLeft + 1),
    pyacAlignmentTopRight = (pyacAlignmentTopCenter + 1),
    pyacAlignmentMiddleLeft = (pyacAlignmentTopRight + 1),
    pyacAlignmentMiddleCenter = (pyacAlignmentMiddleLeft + 1),
    pyacAlignmentMiddleRight = (pyacAlignmentMiddleCenter + 1),
    pyacAlignmentBottomLeft = (pyacAlignmentMiddleRight + 1),
    pyacAlignmentBottomCenter = (pyacAlignmentBottomLeft + 1),
    pyacAlignmentBottomRight = (pyacAlignmentBottomCenter + 1)
};

enum PyAcLineSpacingStyle
{
    pyacLineSpacingStyleAtLeast = 1,
    pyacLineSpacingStyleExactly = 2
};

enum PyAcDimPrecision
{
    pyacDimPrecisionZero = 0,
    pyacDimPrecisionOne = (pyacDimPrecisionZero + 1),
    pyacDimPrecisionTwo = (pyacDimPrecisionOne + 1),
    pyacDimPrecisionThree = (pyacDimPrecisionTwo + 1),
    pyacDimPrecisionFour = (pyacDimPrecisionThree + 1),
    pyacDimPrecisionFive = (pyacDimPrecisionFour + 1),
    pyacDimPrecisionSix = (pyacDimPrecisionFive + 1),
    pyacDimPrecisionSeven = (pyacDimPrecisionSix + 1),
    pyacDimPrecisionEight = (pyacDimPrecisionSeven + 1)
};

enum PyAcDimUnits
{
    pyacDimScientific = 1,
    pyacDimDecimal = (pyacDimScientific + 1),
    pyacDimEngineering = (pyacDimDecimal + 1),
    pyacDimArchitecturalStacked = (pyacDimEngineering + 1),
    pyacDimFractionalStacked = (pyacDimArchitecturalStacked + 1),
    pyacDimArchitectural = (pyacDimFractionalStacked + 1),
    pyacDimFractional = (pyacDimArchitectural + 1),
    pyacDimWindowsDesktop = (pyacDimFractional + 1)
};

enum PyAcDimLUnits
{
    pyacDimLScientific = 1,
    pyacDimLDecimal = (pyacDimLScientific + 1),
    pyacDimLEngineering = (pyacDimLDecimal + 1),
    pyacDimLArchitectural = (pyacDimLEngineering + 1),
    pyacDimLFractional = (pyacDimLArchitectural + 1),
    pyacDimLWindowsDesktop = (pyacDimLFractional + 1)
};

enum PyAcDimArrowheadType
{
    pyacArrowDefault = 0,
    pyacArrowClosedBlank = 1,
    pyacArrowClosed = 2,
    pyacArrowDot = 3,
    pyacArrowArchTick = 4,
    pyacArrowOblique = 5,
    pyacArrowOpen = 6,
    pyacArrowOrigin = 7,
    pyacArrowOrigin2 = 8,
    pyacArrowOpen90 = 9,
    pyacArrowOpen30 = 10,
    pyacArrowDotSmall = 11,
    pyacArrowDotBlank = 12,
    pyacArrowSmall = 13,
    pyacArrowBoxBlank = 14,
    pyacArrowBoxFilled = 15,
    pyacArrowDatumBlank = 16,
    pyacArrowDatumFilled = 17,
    pyacArrowIntegral = 18,
    pyacArrowNone = 19,
    pyacArrowUserDefined = 20
};

enum PyAcDimCenterType
{
    pyacCenterMark = 0,
    pyacCenterLine = (pyacCenterMark + 1),
    pyacCenterNone = (pyacCenterLine + 1)
};

enum PyAcDimFit
{
    pyacTextAndArrows = 0,
    pyacArrowsOnly = (pyacTextAndArrows + 1),
    pyacTextOnly = (pyacArrowsOnly + 1),
    pyacBestFit = (pyacTextOnly + 1)
};

enum PyAcDimFractionType
{
    pyacHorizontal = 0,
    pyacDiagonal = (pyacHorizontal + 1),
    pyacNotStacked = (pyacDiagonal + 1)
};

enum PyAcDimArcLengthSymbol
{
    pyacSymInFront = 0,
    pyacSymAbove = (pyacSymInFront + 1),
    pyacSymNone = (pyacSymAbove + 1)
};

enum PyAcDimHorizontalJustification
{
    pyacHorzCentered = 0,
    pyacFirstExtensionLine = (pyacHorzCentered + 1),
    pyacSecondExtensionLine = (pyacFirstExtensionLine + 1),
    pyacOverFirstExtension = (pyacSecondExtensionLine + 1),
    pyacOverSecondExtension = (pyacOverFirstExtension + 1)
};

enum PyAcDimVerticalJustification
{
    pyacVertCentered = 0,
    pyacAbove = (pyacVertCentered + 1),
    pyacOutside = (pyacAbove + 1),
    pyacJIS = (pyacOutside + 1),
    pyacUnder = (pyacJIS + 1)
};

enum PyAcDimTextMovement
{
    pyacDimLineWithText = 0,
    pyacMoveTextAddLeader = (pyacDimLineWithText + 1),
    pyacMoveTextNoLeader = (pyacMoveTextAddLeader + 1)
};

enum PyAcDimToleranceMethod
{
    pyacTolNone = 0,
    pyacTolSymmetrical = (pyacTolNone + 1),
    pyacTolDeviation = (pyacTolSymmetrical + 1),
    pyacTolLimits = (pyacTolDeviation + 1),
    pyacTolBasic = (pyacTolLimits + 1)
};

enum PyAcDimToleranceJustify
{
    pyacTolBottom = 0,
    pyacTolMiddle = (pyacTolBottom + 1),
    pyacTolTop = (pyacTolMiddle + 1)
};

enum PyAcViewportScale
{
    pyacVpScaleToFit = 0,
    pyacVpCustomScale = (pyacVpScaleToFit + 1),
    pyacVp1_1 = (pyacVpCustomScale + 1),
    pyacVp1_2 = (pyacVp1_1 + 1),
    pyacVp1_4 = (pyacVp1_2 + 1),
    pyacVp1_5 = (pyacVp1_4 + 1),
    pyacVp1_8 = (pyacVp1_5 + 1),
    pyacVp1_10 = (pyacVp1_8 + 1),
    pyacVp1_16 = (pyacVp1_10 + 1),
    pyacVp1_20 = (pyacVp1_16 + 1),
    pyacVp1_30 = (pyacVp1_20 + 1),
    pyacVp1_40 = (pyacVp1_30 + 1),
    pyacVp1_50 = (pyacVp1_40 + 1),
    pyacVp1_100 = (pyacVp1_50 + 1),
    pyacVp2_1 = (pyacVp1_100 + 1),
    pyacVp4_1 = (pyacVp2_1 + 1),
    pyacVp8_1 = (pyacVp4_1 + 1),
    pyacVp10_1 = (pyacVp8_1 + 1),
    pyacVp100_1 = (pyacVp10_1 + 1),
    pyacVp1_128in_1ft = (pyacVp100_1 + 1),
    pyacVp1_64in_1ft = (pyacVp1_128in_1ft + 1),
    pyacVp1_32in_1ft = (pyacVp1_64in_1ft + 1),
    pyacVp1_16in_1ft = (pyacVp1_32in_1ft + 1),
    pyacVp3_32in_1ft = (pyacVp1_16in_1ft + 1),
    pyacVp1_8in_1ft = (pyacVp3_32in_1ft + 1),
    pyacVp3_16in_1ft = (pyacVp1_8in_1ft + 1),
    pyacVp1_4in_1ft = (pyacVp3_16in_1ft + 1),
    pyacVp3_8in_1ft = (pyacVp1_4in_1ft + 1),
    pyacVp1_2in_1ft = (pyacVp3_8in_1ft + 1),
    pyacVp3_4in_1ft = (pyacVp1_2in_1ft + 1),
    pyacVp1in_1ft = (pyacVp3_4in_1ft + 1),
    pyacVp1and1_2in_1ft = (pyacVp1in_1ft + 1),
    pyacVp3in_1ft = (pyacVp1and1_2in_1ft + 1),
    pyacVp6in_1ft = (pyacVp3in_1ft + 1),
    pyacVp1ft_1ft = (pyacVp6in_1ft + 1)
};

enum PyAcISOPenWidth
{
    pyacPenWidth013 = 13,
    pyacPenWidth018 = 18,
    pyacPenWidth025 = 25,
    pyacPenWidth035 = 35,
    pyacPenWidth050 = 50,
    pyacPenWidth070 = 70,
    pyacPenWidth100 = 100,
    pyacPenWidth140 = 140,
    pyacPenWidth200 = 200,
    pyacPenWidthUnk = -1
};

enum PyAcSaveAsType
{
    pyacUnknown = -1,
    pyacR12_dxf = 1,
    pyacR13_dwg = 4,
    pyacR13_dxf = 5,
    pyacR14_dwg = 8,
    pyacR14_dxf = 9,
    pyac2000_dwg = 12,
    pyac2000_dxf = 13,
    pyac2000_Template = 14,
    pyac2004_dwg = 24,
    pyac2004_dxf = 25,
    pyac2004_Template = 26,
    pyac2007_dwg = 36,
    pyac2007_dxf = 37,
    pyac2007_Template = 38,
    pyac2010_dwg = 48,
    pyac2010_dxf = 49,
    pyac2010_Template = 50,
    pyac2013_dwg = 60,
    pyac2013_dxf = 61,
    pyac2013_Template = 62,
    pyac2018_dwg = 64,
    pyac2018_dxf = 65,
    pyac2018_Template = 66,
    pyacNative = pyac2018_dwg,
    pyacR15_dwg = pyac2000_dwg,
    pyacR15_dxf = pyac2000_dxf,
    pyacR15_Template = pyac2000_Template,
    pyacR18_dwg = pyac2004_dwg,
    pyacR18_dxf = pyac2004_dxf,
    pyacR18_Template = pyac2004_Template
};

enum PyAcPrinterSpoolAlert
{
    pyacPrinterAlwaysAlert = 0,
    pyacPrinterAlertOnce = (pyacPrinterAlwaysAlert + 1),
    pyacPrinterNeverAlertLogOnce = (pyacPrinterAlertOnce + 1),
    pyacPrinterNeverAlert = (pyacPrinterNeverAlertLogOnce + 1)
};

enum PyAcPlotPolicyForNewDwgs
{
    pyacPolicyNewDefault = 0,
    pyacPolicyNewLegacy = (pyacPolicyNewDefault + 1)
};

enum PyAcPlotPolicyForLegacyDwgs
{
    pyacPolicyLegacyDefault = 0,
    pyacPolicyLegacyQuery = (pyacPolicyLegacyDefault + 1),
    pyacPolicyLegacyLegacy = (pyacPolicyLegacyQuery + 1)
};

enum PyAcOleQuality
{
    pyacOQLineArt = 0,
    pyacOQText = (pyacOQLineArt + 1),
    pyacOQGraphics = (pyacOQText + 1),
    pyacOQPhoto = (pyacOQGraphics + 1),
    pyacOQHighPhoto = (pyacOQPhoto + 1)
};

enum PyAcLoadPalette
{
    pyacPaletteByDrawing = 0,
    pyacPaletteBySession = (pyacPaletteByDrawing + 1)
};

enum PyAcInsertUnits
{
    pyacInsertUnitsUnitless = 0,
    pyacInsertUnitsInches = (pyacInsertUnitsUnitless + 1),
    pyacInsertUnitsFeet = (pyacInsertUnitsInches + 1),
    pyacInsertUnitsMiles = (pyacInsertUnitsFeet + 1),
    pyacInsertUnitsMillimeters = (pyacInsertUnitsMiles + 1),
    pyacInsertUnitsCentimeters = (pyacInsertUnitsMillimeters + 1),
    pyacInsertUnitsMeters = (pyacInsertUnitsCentimeters + 1),
    pyacInsertUnitsKilometers = (pyacInsertUnitsMeters + 1),
    pyacInsertUnitsMicroinches = (pyacInsertUnitsKilometers + 1),
    pyacInsertUnitsMils = (pyacInsertUnitsMicroinches + 1),
    pyacInsertUnitsYards = (pyacInsertUnitsMils + 1),
    pyacInsertUnitsAngstroms = (pyacInsertUnitsYards + 1),
    pyacInsertUnitsNanometers = (pyacInsertUnitsAngstroms + 1),
    pyacInsertUnitsMicrons = (pyacInsertUnitsNanometers + 1),
    pyacInsertUnitsDecimeters = (pyacInsertUnitsMicrons + 1),
    pyacInsertUnitsDecameters = (pyacInsertUnitsDecimeters + 1),
    pyacInsertUnitsHectometers = (pyacInsertUnitsDecameters + 1),
    pyacInsertUnitsGigameters = (pyacInsertUnitsHectometers + 1),
    pyacInsertUnitsAstronomicalUnits = (pyacInsertUnitsGigameters + 1),
    pyacInsertUnitsLightYears = (pyacInsertUnitsAstronomicalUnits + 1),
    pyacInsertUnitsParsecs = (pyacInsertUnitsLightYears + 1),
    pyacInsertUnitsUSSurveyFeet = (pyacInsertUnitsParsecs + 1),
    pyacInsertUnitsUSSurveyInch = (pyacInsertUnitsUSSurveyFeet + 1),
    pyacInsertUnitsUSSurveyYard = (pyacInsertUnitsUSSurveyInch + 1),
    pyacInsertUnitsUSSurveyMile = (pyacInsertUnitsUSSurveyYard + 1)
};

enum PyAcAlignmentPointAcquisition
{
    pyacAlignPntAcquisitionAutomatic = 0,
    pyacAlignPntAcquisitionShiftToAcquire = (pyacAlignPntAcquisitionAutomatic + 1)
};

enum PyAcInsertUnitsAction
{
    pyacInsertUnitsPrompt = 0,
    pyacInsertUnitsAutoAssign = (pyacInsertUnitsPrompt + 1)
};

enum PyAcPlotPolicy
{
    pyacPolicyNamed = 0,
    pyacPolicyLegacy = (pyacPolicyNamed + 1)
};

enum PyAcDrawingAreaShortCutMenu
{
    pyacNoDrawingAreaShortCutMenu = 0,
    pyacUseDefaultDrawingAreaShortCutMenu = (pyacNoDrawingAreaShortCutMenu + 1)
};

enum PyAcDrawingAreaSCMDefault
{
    pyacRepeatLastCommand = 0,
    pyacSCM = (pyacRepeatLastCommand + 1)
};

enum PyAcDrawingAreaSCMEdit
{
    pyacEdRepeatLastCommand = 0,
    pyacEdSCM = (pyacEdRepeatLastCommand + 1)
};

enum PyAcDrawingAreaSCMCommand
{
    pyacEnter = 0,
    pyacEnableSCMOptions = (pyacEnter + 1),
    pyacEnableSCM = (pyacEnableSCMOptions + 1)
};

enum PyAcLayerStateMask
{
    pyacLsNone = 0,
    pyacLsOn = 0x1,
    pyacLsFrozen = 0x2,
    pyacLsLocked = 0x4,
    pyacLsPlot = 0x8,
    pyacLsNewViewport = 0x10,
    pyacLsColor = 0x20,
    pyacLsLineType = 0x40,
    pyacLsLineWeight = 0x80,
    pyacLsPlotStyle = 0x100,
    pyacLsAll = 0xffff
};

enum PyAcShadePlot
{
    pyacShadePlotAsDisplayed = 0,
    pyacShadePlotWireframe = (pyacShadePlotAsDisplayed + 1),
    pyacShadePlotHidden = (pyacShadePlotWireframe + 1),
    pyacShadePlotRendered = (pyacShadePlotHidden + 1)
};

enum PyAcHatchObjectType
{
    pyacHatchObject = 0,
    pyacGradientObject = 1
};

enum PyAcGradientPatternType
{
    pyacPreDefinedGradient = 0,
    pyacUserDefinedGradient = 1
};

enum PyAcTableDirection
{
    pyacTableTopToBottom = 0,
    pyacTableBottomToTop = 1
};

enum PyAcCellAlignment
{
    pyacTopLeft = 1,
    pyacTopCenter = 2,
    pyacTopRight = 3,
    pyacMiddleLeft = 4,
    pyacMiddleCenter = 5,
    pyacMiddleRight = 6,
    pyacBottomLeft = 7,
    pyacBottomCenter = 8,
    pyacBottomRight = 9
};

enum PyAcRowType
{
    pyacUnknownRow = 0,
    pyacDataRow = 1,
    pyacTitleRow = 2,
    pyacHeaderRow = 4
};

enum PyAcValueDataType
{
    pyacUnknownDataType = 0,
    pyacLong = (0x1 << 0),
    pyacDouble = (0x1 << 1),
    pyacString = (0x1 << 2),
    pyacDate = (0x1 << 3),
    pyacPoint2d = (0x1 << 4),
    pyacPoint3d = (0x1 << 5),
    pyacObjectId = (0x1 << 6),
    pyacBuffer = (0x1 << 7),
    pyacResbuf = (0x1 << 8),
    pyacGeneral = (0x1 << 9)
};

enum PyAcValueUnitType
{
    pyacUnitless = 0,
    pyacUnitDistance = (0x1 << 0),
    pyacUnitAngle = (0x1 << 1),
    pyacUnitArea = (0x1 << 2),
    pyacUnitVolume = (0x1 << 3)
};

enum PyAcParseOption
{
    pyacParseOptionNone = 0,
    pyacSetDefaultFormat = (0x1 << 0),
    pyacPreserveMtextFormat = (0x1 << 1)
};

enum PyAcFormatOption
{
    pykFormatOptionNone = 0,
    pyacForEditing = (0x1 << 0),
    pyacForExpression = (0x1 << 1),
    pyacUseMaximumPrecision = (0x1 << 2),
    pyacIgnoreMtextFormat = (0x1 << 3)
};

enum PyAcGridLineType
{
    pyacInvalidGridLine = 0,
    pyacHorzTop = 1,
    pyacHorzInside = 2,
    pyacHorzBottom = 4,
    pyacVertLeft = 8,
    pyacVertInside = 0x10,
    pyacVertRight = 0x20
};

enum PyAcCellType
{
    pyacUnknownCell = 0,
    pyacTextCell = 1,
    pyacBlockCell = 2
};

enum PyAcCellEdgeMask
{
    pyacTopMask = 1,
    pyacRightMask = 2,
    pyacBottomMask = 4,
    pyacLeftMask = 8
};

enum PyAcRotationAngle
{
    pyacDegreesUnknown = -1,
    pyacDegrees000 = 0,
    pyacDegrees090 = 1,
    pyacDegrees180 = 2,
    pyacDegrees270 = 3
};

enum PyAcMergeCellStyleOption
{
    pyacMergeCellStyleNone = 0,
    pyacMergeCellStyleCopyDuplicates = 0x1,
    pyacMergeCellStyleOverwriteDuplicates = 0x2,
    pyacMergeCellStyleConvertDuplicatesToOverrides = 0x4,
    pyacMergeCellStyleIgnoreNewStyles = 0x8
};

enum PyAcSelectType
{
    pyacTableSelectWindow = 1,
    pyacTableSelectCrossing = 2
};

enum PyAcOleType
{
    pyacOTLink = 1,
    pyacOTEmbedded = 2,
    pyacOTStatic = 3
};

enum PyAcOlePlotQuality
{
    pyacOPQMonochrome = 0,
    pyacOPQLowGraphics = (pyacOPQMonochrome + 1),
    pyacOPQHighGraphics = (pyacOPQLowGraphics + 1)
};

enum PyAcTableStyleOverrides
{
    pyacTitleSuppressed = 1,
    pyacHeaderSuppressed = 2,
    pyacFlowDirection = 3,
    pyacHorzCellMargin = 4,
    pyacVertCellMargin = 5,
    pyacTitleRowColor = 6,
    pyacHeaderRowColor = 7,
    pyacDataRowColor = 8,
    pyacTitleRowFillNone = 9,
    pyacHeaderRowFillNone = 10,
    pyacDataRowFillNone = 11,
    pyacTitleRowFillColor = 12,
    pyacHeaderRowFillColor = 13,
    pyacDataRowFillColor = 14,
    pyacTitleRowAlignment = 15,
    pyacHeaderRowAlignment = 16,
    pyacDataRowAlignment = 17,
    pyacTitleRowTextStyle = 18,
    pyacHeaderRowTextStyle = 19,
    pyacDataRowTextStyle = 20,
    pyacTitleRowTextHeight = 21,
    pyacHeaderRowTextHeight = 22,
    pyacDataRowTextHeight = 23,
    pyacTitleRowDataType = 24,
    pyacHeaderRowDataType = 25,
    pyacDataRowDataType = 26,
    pyacTitleHorzTopColor = 40,
    pyacTitleHorzInsideColor = 41,
    pyacTitleHorzBottomColor = 42,
    pyacTitleVertLeftColor = 43,
    pyacTitleVertInsideColor = 44,
    pyacTitleVertRightColor = 45,
    pyacHeaderHorzTopColor = 46,
    pyacHeaderHorzInsideColor = 47,
    pyacHeaderHorzBottomColor = 48,
    pyacHeaderVertLeftColor = 49,
    pyacHeaderVertInsideColor = 50,
    pyacHeaderVertRightColor = 51,
    pyacDataHorzTopColor = 52,
    pyacDataHorzInsideColor = 53,
    pyacDataHorzBottomColor = 54,
    pyacDataVertLeftColor = 55,
    pyacDataVertInsideColor = 56,
    pyacDataVertRightColor = 57,
    pyacTitleHorzTopLineWeight = 70,
    pyacTitleHorzInsideLineWeight = 71,
    pyacTitleHorzBottomLineWeight = 72,
    pyacTitleVertLeftLineWeight = 73,
    pyacTitleVertInsideLineWeight = 74,
    pyacTitleVertRightLineWeight = 75,
    pyacHeaderHorzTopLineWeight = 76,
    pyacHeaderHorzInsideLineWeight = 77,
    pyacHeaderHorzBottomLineWeight = 78,
    pyacHeaderVertLeftLineWeight = 79,
    pyacHeaderVertInsideLineWeight = 80,
    pyacHeaderVertRightLineWeight = 81,
    pyacDataHorzTopLineWeight = 82,
    pyacDataHorzInsideLineWeight = 83,
    pyacDataHorzBottomLineWeight = 84,
    pyacDataVertLeftLineWeight = 85,
    pyacDataVertInsideLineWeight = 86,
    pyacDataVertRightLineWeight = 87,
    pyacTitleHorzTopVisibility = 100,
    pyacTitleHorzInsideVisibility = 101,
    pyacTitleHorzBottomVisibility = 102,
    pyacTitleVertLeftVisibility = 103,
    pyacTitleVertInsideVisibility = 104,
    pyacTitleVertRightVisibility = 105,
    pyacHeaderHorzTopVisibility = 106,
    pyacHeaderHorzInsideVisibility = 107,
    pyacHeaderHorzBottomVisibility = 108,
    pyacHeaderVertLeftVisibility = 109,
    pyacHeaderVertInsideVisibility = 110,
    pyacHeaderVertRightVisibility = 111,
    pyacDataHorzTopVisibility = 112,
    pyacDataHorzInsideVisibility = 113,
    pyacDataHorzBottomVisibility = 114,
    pyacDataVertLeftVisibility = 115,
    pyacDataVertInsideVisibility = 116,
    pyacDataVertRightVisibility = 117,
    pyacCellAlign = 130,
    pyacCellBackgroundFillNone = 131,
    pyacCellBackgroundColor = 132,
    pyacCellContentColor = 133,
    pyacCellTextStyle = 134,
    pyacCellTextHeight = 135,
    pyacCellTopGridColor = 136,
    pyacCellRightGridColor = 137,
    pyacCellBottomGridColor = 138,
    pyacCellLeftGridColor = 139,
    pyacCellTopGridLineWeight = 140,
    pyacCellRightGridLineWeight = 141,
    pyacCellBottomGridLineWeight = 142,
    pyacCellLeftGridLineWeight = 143,
    pyacCellTopVisibility = 144,
    pyacCellRightVisibility = 145,
    pyacCellBottomVisibility = 146,
    pyacCellLeftVisibility = 147,
    pyacCellDataType = 148
};

enum PyAcMLineJustification
{
    pyacTop = 0,
    pyacZero = 1,
    pyacBottom = 2
};

enum PyAcBlockScaling
{
    pyacAny = 0,
    pyacUniform = 1
};

enum PyAcDynamicBlockReferencePropertyUnitsType
{
    pyacNoUnits = 0,
    pyacAngular = 1,
    pyacDistance = 2,
    pyacArea = 3
};

enum PyAcSectionState
{
    pyacSectionStatePlane = (0x1 << 0),
    pyacSectionStateBoundary = (0x1 << 1),
    pyacSectionStateVolume = (0x1 << 2)
};

enum PyAcSectionState2
{
    pyacSectionState2Plane = (0x1 << 0),
    pyacSectionState2Slice = (0x1 << 1),
    pyacSectionState2Boundary = (0x1 << 2),
    pyacSectionState2Volume = (0x1 << 3)
};

enum PyAcSectionSubItem
{
    pyacSectionSubItemkNone = 0,
    pyacSectionSubItemSectionLine = (0x1 << 0),
    pyacSectionSubItemSectionLineTop = (0x1 << 1),
    pyacSectionSubItemSectionLineBottom = (0x1 << 2),
    pyacSectionSubItemBackLine = (0x1 << 3),
    pyacSectionSubItemBackLineTop = (0x1 << 4),
    pyacSectionSubItemBackLineBottom = (0x1 << 5),
    pyacSectionSubItemVerticalLineTop = (0x1 << 6),
    pyacSectionSubItemVerticalLineBottom = (0x1 << 7)
};

enum PyAcSectionType
{
    pyacSectionTypeLiveSection = (0x1 << 0),
    pyacSectionType2dSection = (0x1 << 1),
    pyacSectionType3dSection = (0x1 << 2)
};

enum PyAcSectionGeneration
{
    pyacSectionGenerationSourceAllObjects = (0x1 << 0),
    pyacSectionGenerationSourceSelectedObjects = (0x1 << 1),
    pyacSectionGenerationDestinationNewBlock = (0x1 << 4),
    pyacSectionGenerationDestinationReplaceBlock = (0x1 << 5),
    pyacSectionGenerationDestinationFile = (0x1 << 6)
};

enum PyAcHelixConstrainType
{
    pyacTurnHeight = 0,
    pyacTurns = 1,
    pyacHeight = 2
};

enum PyAcShadowDisplayType
{
    pyacCastsAndReceivesShadows = 0,
    pyacCastsShadows = 1,
    pyacReceivesShadows = 2,
    pyacIgnoreShadows = 3
};

enum PyAcLoftedSurfaceNormalType
{
    pyacRuled = 0,
    pyacSmooth = 1,
    pyacFirstNormal = 2,
    pyacLastNormal = 3,
    pyacEndsNormal = 4,
    pyacAllNormal = 5,
    pyacUseDraftAngles = 6
};

enum PyAcHelixTwistType
{
    pyacCCW = 0,
    pyacCW = 1
};

enum PyAcUnderlayLayerOverrideType
{
    pyacNoOverrides = 0,
    pyacApplied = 1
};

enum PyAcTableFlowDirection
{
    pyacTableFlowRight = 0x1,
    pyacTableFlowDownOrUp = 0x2,
    pyacTableFlowLeft = 0x4
};

enum PyAcCellMargin
{
    pyacCellMarginTop = 0x1,
    pyacCellMarginLeft = 0x2,
    pyacCellMarginBottom = 0x4,
    pyacCellMarginRight = 0x8,
    pyacCellMarginHorzSpacing = 0x10,
    pyacCellMarginVertSpacing = 0x20
};

enum PyAcCellContentLayout
{
    pyacCellContentLayoutFlow = 0x1,
    pyacCellContentLayoutStackedHorizontal = 0x2,
    pyacCellContentLayoutStackedVertical = 0x4
};

enum PyAcCellProperty
{
    pyacInvalidCellProperty = 0,
    pyacLock = (0x1 << 0),
    pyacDataType = (0x1 << 1),
    pyacDataFormat = (0x1 << 2),
    pyacRotation = (0x1 << 3),
    pyacScale = (0x1 << 4),
    pyacAlignmentProperty = (0x1 << 5),
    pyacContentColor = (0x1 << 6),
    pyacBackgroundColor = (0x1 << 7),
    pyacTextStyle = (0x1 << 8),
    pyacTextHeight = (0x1 << 9),
    pyacMarginLeft = (0x1 << 10),
    pyacMarginTop = (0x1 << 11),
    pyacMarginRight = (0x1 << 12),
    pyacMarginBottom = (0x1 << 13),
    pyacEnableBackgroundColor = (0x1 << 14),
    pyacAutoScale = (0x1 << 15),
    pyacMergeAll = (0x1 << 16),
    pyacFlowDirBtoT = (0x1 << 17),
    pyacContentLayout = (0x1 << 18),
    pyacDataTypeAndFormat =6,
    pyacContentProperties = 33662,
    pyacBitProperties = 245760,
    pyacAllCellProperties = 524287
};

enum PyAcGridLineStyle
{
    pyacGridLineStyleSingle = 1,
    pyacGridLineStyleDouble = 2
};

enum PyAcDataLinkUpdateDirection
{
    pyacUpdateDataFromSource = 0x1,
    pyacUpdateSourceFromData = 0x2
};

enum PyAcDataLinkUpdateOption
{
    pyacUpdateOptionNone = 0,
    pyacUpdateOptionOverwriteContentModifiedAfterUpdate = 0x20000,
    pyacUpdateOptionOverwriteFormatModifiedAfterUpdate = 0x40000,
    pyacUpdateOptionUpdateFullSourceRange = 0x80000,
    pyacUpdateOptionIncludeXrefs = 0x100000
};

enum PyAcCellContentType
{
    pyacCellContentTypeUnknown = 0,
    pyacCellContentTypeValue = (0x1 << 0),
    pyacCellContentTypeField = (0x1 << 1),
    pyacCellContentTypeBlock = (0x1 << 2)
};

enum PyAcCellState
{
    pyacCellStateNone = 0,
    pyacCellStateContentLocked = 0x1,
    pyacCellStateContentReadOnly = 0x2,
    pyacCellStateFormatLocked = 0x4,
    pyacCellStateFormatReadOnly = 0x8,
    pyacCellStateLinked = 0x10,
    pyacCellStateContentModified = 0x20,
    pyacCellStateFormatModified = 0x40
};

enum PyPyAcCellOption
{
    pypykCellOptionNone = 0,
    pypykInheritCellFormat = 0x1
};

enum PyAcTextAttachmentType
{
    pyacAttachmentTopOfTop = 0,
    pyacAttachmentMiddleOfTop = 1,
    pyacAttachmentBottomOfTop = 2,
    pyacAttachmentBottomOfTopLine = 3,
    pyacAttachmentMiddle = 4,
    pyacAttachmentMiddleOfBottom = 5,
    pyacAttachmentBottomOfBottom = 6,
    pyacAttachmentBottomLine = 7,
    pyacAttachmentAllLine = 8
};

enum PyAcMLeaderType
{
    pyacStraightLeader = 1,
    pyacSplineLeader = 2,
    pyacInVisibleLeader = 0
};

enum PyAcMLeaderContentType
{
    pyacNoneContent = 0,
    pyacBlockContent = 1,
    pyacMTextContent = 2
};

enum PyAcTextAlignmentType
{
    pyacLeftAlignment = 0,
    pyacCenterAlignment = 1,
    pyacRightAlignment = 2
};

enum PyAcTextAngleType
{
    pyacInsertAngle = 0,
    pyacHorizontalAngle = 1,
    pyacAlwaysRightReadingAngle = 2
};

enum PyAcBlockConnectionType
{
    pyacConnectExtents = 0,
    pyacConnectBase = 1
};

enum PyAcPredefBlockType
{
    pyacBlockImperial = 0,
    pyacBlockSlot = 1,
    pyacBlockCircle = 2,
    pyacBlockBox = 3,
    pyacBlockHexagon = 4,
    pyacBlockTriangle = 5,
    pyacBlockUserDefined = 6
};

enum PyAcDrawLeaderOrderType
{
    pyacDrawLeaderHeadFirst = 0,
    pyacDrawLeaderTailFirst = 1
};

enum PyAcDrawMLeaderOrderType
{
    pyacDrawContentFirst = 0,
    pyacDrawLeaderFirst = 1
};

enum PyAcSegmentAngleType
{
    pyacDegreesAny = 0,
    pyacDegrees15 = 1,
    pyacDegrees30 = 2,
    pyacDegrees45 = 3,
    pyacDegrees60 = 4,
    pyacDegrees90 = 6,
    pyacDegreesHorz = 12
};

enum PyAcTextAttachmentDirection
{
    pyacAttachmentHorizontal = 0,
    pyacAttachmentVertical = 1
};

enum PyAcVerticalTextAttachmentType
{
    pyacAttachmentCenter = 0,
    pyacAttachmentLinedCenter = 1
};

enum PyAcMeshCreaseType
{
    pyacNoneCrease = 0,
    pyacAlwaysCrease = 1,
    pyacCreaseByLevel = 2
};

enum PyAcWireframeType
{
    pyacIsolines = 0,
    pyacIsoparms = 1
};

enum PyAcSplineKnotParameterizationType
{
    pyacChord = 0,
    pyacSqrtChord = 1,
    pyacUniformParam = 2,
    pyacCustomParameterization = 15
};

enum PyAcSplineFrameType
{
    pyacShow = 0,
    pyacHide = 1
};

enum PyAcSplineMethodType
{
    pyacFit = 0,
    pyacControlVertices = 1
};

enum PyAcPointCloudColorType
{
    pyacTrueColor = 0,
    pyacByColor = 1
};

enum PyAcPointCloudStylizationType
{
    pyacScanColor = 0,
    pyacObjectColor = 1,
    pyacNormal = 2,
    pyacIntensity = 3
};

enum PyAcPointCloudIntensityStyle
{
    pyacIntensityGrayscale = 0,
    pyacIntensityRainbow = 1,
    pyacIntensityRed = 2,
    pyacIntensityGreen = 3,
    pyacIntensityBlue = 4,
    pyacIntensityEditableFlag = 5
};

enum PyAcPointCloudExStylizationType
{
    pyacRGB = 0,
    pyacObject = 1,
    pyacNormals = 2,
    pyacIntensities = 3,
    pyacElevation = 4,
    pyacClassification = 5
};

enum PyAcColorMethod
{
    pyacColorMethodByLayer = 192,
    pyacColorMethodByBlock = 193,
    pyacColorMethodByRGB = 194,
    pyacColorMethodByACI = 195,
    pyacColorMethodForeground = 197
};

enum PyAcadSecurityParamsType
{
    pyACADSECURITYPARAMS_ENCRYPT_DATA = 0x1,
    pyACADSECURITYPARAMS_ENCRYPT_PROPS = 0x2,
    pyACADSECURITYPARAMS_SIGN_DATA = 0x10,
    pyACADSECURITYPARAMS_ADD_TIMESTAMP = 0x20
};

enum PyAcadSecurityParamsConstants
{
    pyACADSECURITYPARAMS_ALGID_RC4 = 0x6801
};
