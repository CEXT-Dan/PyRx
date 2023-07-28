#pragma once

enum class LispType
{
    kAngle = 5004,
    kDottedPair = 5018,
    kDouble = 5001,
    kInt16 = 5003,
    kInt32 = 5010,
    kListBegin = 5016,
    kListEnd = 5017,
    kNil = 5019,
    kNone = 5000,
    kObjectId = 5006,
    kOrientation = 5008,
    kPoint2d = 5002,
    kPoint3d = 5009,
    kSelectionSet = 5007,
    kT_atom = 5021,
    kText = 5005,
    kVoid = 5014
};


void initPyRxModule();
