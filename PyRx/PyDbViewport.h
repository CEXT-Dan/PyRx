#pragma once
#include "PyDbEntity.h"

class PyDbObjectId;
class PyDbXrefObjectId;

void makePyDbViewportWrapper();

class PyDbViewport : public PyDbEntity
{
public:
    PyDbViewport();
    PyDbViewport(AcDbViewport* ptr, bool autoDelete);
    PyDbViewport(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbViewport() override = default;

    Acad::ErrorStatus   setModelView(const PyDbXrefObjectId& xrefObjId);
    PyDbXrefObjectId    getModelView() const;
    Acad::ErrorStatus   removeModelView(void);

    Acad::ErrorStatus   setSheetView(PyDbObjectId objId);
    PyDbObjectId        getSheetView()const;
    Acad::ErrorStatus   removeSheetView(void);
    Acad::ErrorStatus   setLabelBlock(PyDbObjectId& objId);
    PyDbObjectId        getLabelBlock() const;
    Acad::ErrorStatus   removeLabelBlock(void);
    Acad::ErrorStatus   syncModelView(void);

    double              height() const;
    Acad::ErrorStatus   setHeight(double val);
    double              width() const;
    Acad::ErrorStatus   setWidth(double val);
    AcGePoint3d         centerPoint() const;
    Acad::ErrorStatus   setCenterPoint(const AcGePoint3d& val);
    Adesk::Int16        number() const;
    bool                isOn() const;
    Acad::ErrorStatus   setOn();
    Acad::ErrorStatus   setOff();
    Acad::ErrorStatus   setIsOn(bool bOn);
    AcGePoint3d         viewTarget() const;
    Acad::ErrorStatus   setViewTarget(const AcGePoint3d& val);
    AcGeVector3d        viewDirection() const;
    Acad::ErrorStatus   setViewDirection(const AcGeVector3d& val);
    double              viewHeight() const;
    Acad::ErrorStatus   setViewHeight(double ht);
    AcGePoint2d         viewCenter() const;
    Acad::ErrorStatus   setViewCenter(const AcGePoint2d& pt);
    double              twistAngle() const;
    Acad::ErrorStatus   setTwistAngle(double val);
    double              lensLength() const;
    Acad::ErrorStatus   setLensLength(double val);
    bool                isFrontClipOn() const;
    Acad::ErrorStatus   setFrontClipOn1();
    Acad::ErrorStatus   setFrontClipOff();
    Acad::ErrorStatus   setFrontClipOn2(bool bOn);
    bool                isBackClipOn() const;
    Acad::ErrorStatus   setBackClipOn1();
    Acad::ErrorStatus   setBackClipOff();
    Acad::ErrorStatus   setBackClipOn2(bool bOn);
    bool                isFrontClipAtEyeOn() const;
    Acad::ErrorStatus   setFrontClipAtEyeOn1();
    Acad::ErrorStatus   setFrontClipAtEyeOff();
    Acad::ErrorStatus   setFrontClipAtEyeOn2(bool bOn);
    double              frontClipDistance() const;
    Acad::ErrorStatus   setFrontClipDistance(double newVal);
    double              backClipDistance() const;
    Acad::ErrorStatus   setBackClipDistance(double newVal);
    bool                isPerspectiveOn() const;
    Acad::ErrorStatus   setPerspectiveOn1();
    Acad::ErrorStatus   setPerspectiveOff();
    Acad::ErrorStatus   setPerspectiveOn2(bool bOn);
    bool                isUcsFollowModeOn() const;
    Acad::ErrorStatus   setUcsFollowModeOn1();
    Acad::ErrorStatus   setUcsFollowModeOff();
    Acad::ErrorStatus   setUcsFollowModeOn2(bool bOn);
    bool                isUcsIconVisible() const;
    Acad::ErrorStatus   setUcsIconVisible1();
    Acad::ErrorStatus   setUcsIconInvisible();
    Acad::ErrorStatus   setUcsIconVisible2(bool bOn);
    bool                isUcsIconAtOrigin() const;
    Acad::ErrorStatus   setUcsIconAtOrigin1();
    Acad::ErrorStatus   setUcsIconAtCorner();
    Acad::ErrorStatus   setUcsIconAtOrigin2(bool);
    bool                isFastZoomOn() const;
    Acad::ErrorStatus   setFastZoomOn1();
    Acad::ErrorStatus   setFastZoomOff();
    Acad::ErrorStatus   setFastZoomOn2(bool bOn);
    Adesk::UInt16       circleSides() const;
    Acad::ErrorStatus   setCircleSides(Adesk::UInt16 val);
    bool                isSnapOn() const;
    Acad::ErrorStatus   setSnapOn1();
    Acad::ErrorStatus   setSnapOff();
    Acad::ErrorStatus   setSnapOn2(bool bOn);

    static std::string      className();
    static PyRxClass        desc();
    static PyDbViewport     cloneFrom(const PyRxObject& src);
    static PyDbViewport     cast(const PyRxObject& src);
public:
    AcDbViewport* impObj(const std::source_location& src = std::source_location::current()) const;
};

