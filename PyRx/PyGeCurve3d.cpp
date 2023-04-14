#include "stdafx.h"
#include "PyGeCurve3d.h"

using namespace boost::python;
//-----------------------------------------------------------------------------------
//PyGeCurve3d
void makPyGeCurve3dWrapper()
{
    static auto wrapper = class_<PyGeCurve3d, bases<PyGeEntity3d>>("Curve3d", boost::python::no_init)
        .def("className", &PyGeCurve3d::className).staticmethod("className")
        ;
}

PyGeCurve3d::PyGeCurve3d(AcGeEntity3d* pEnt)
    :PyGeEntity3d(pEnt)
{
}

std::string PyGeCurve3d::className()
{
    return "AcGeCurve3d";
}

AcGeCurve3d* PyGeCurve3d::impObj() const
{
    return static_cast<AcGeCurve3d*>(m_imp.get());
}

//-----------------------------------------------------------------------------------
//AcGeCircArc3d
void makAcGeCircArc3dWrapper()
{
    static auto wrapper = class_<PyGeCircArc3d, bases<PyGeCurve3d>>("CircArc3d")
        .def("className", &PyGeCircArc3d::className).staticmethod("className")
        ;
}


PyGeCircArc3d::PyGeCircArc3d()
    :PyGeCurve3d(new AcGeCircArc3d())
{
}

PyGeCircArc3d::PyGeCircArc3d(AcGeEntity3d* pEnt)
    : PyGeCurve3d(pEnt)
{
}

std::string PyGeCircArc3d::className()
{
    return "AcGeCircArc3d";
}

AcGeCircArc3d* PyGeCircArc3d::impObj() const
{
    return static_cast<AcGeCircArc3d*>(m_imp.get());
}

//-----------------------------------------------------------------------------------
//AcGeCompositeCurve3d
void makAcGeCompositeCurve3dWrapper()
{
    static auto wrapper = class_<PyGeCompositeCurve3d, bases<PyGeCurve3d>>("CompositeCurve3d")
        .def("className", &PyGeCompositeCurve3d::className).staticmethod("className")
        ;
}

PyGeCompositeCurve3d::PyGeCompositeCurve3d()
    :PyGeCurve3d(new AcGeCompositeCurve3d())
{
}

PyGeCompositeCurve3d::PyGeCompositeCurve3d(AcGeEntity3d* pEnt)
    : PyGeCurve3d(pEnt)
{
}

std::string PyGeCompositeCurve3d::className()
{
    return "AcGeCompositeCurve3d";
}

AcGeCompositeCurve3d* PyGeCompositeCurve3d::impObj() const
{
    return static_cast<AcGeCompositeCurve3d*>(m_imp.get());
}


//-----------------------------------------------------------------------------------------
//AcGeCircArc3d wrapper
void makeAcGeEllipArc3dWrapper()
{
    static auto wrapper = class_<PyGeEllipArc3d, bases<PyGeCurve3d>>("EllipArc3d")
        .def("className", &PyGeEllipArc3d::className).staticmethod("className")
        ;
}

PyGeEllipArc3d::PyGeEllipArc3d()
    :PyGeCurve3d(new AcGeEllipArc3d())
{
}

PyGeEllipArc3d::PyGeEllipArc3d(AcGeEntity3d* pEnt)
    : PyGeCurve3d(pEnt)
{
}

std::string PyGeEllipArc3d::className()
{
    return "AcGeCompositeCurve3d";
}

AcGeEllipArc3d* PyGeEllipArc3d::impObj() const
{
    return static_cast<AcGeEllipArc3d*>(m_imp.get());
}


//-----------------------------------------------------------------------------------------
//PyGeExternalCurve3d wrapper
void makeAcGeExternalCurve3dWrapper()
{
    static auto wrapper = class_<PyGeExternalCurve3d, bases<PyGeCurve3d>>("ExternalCurve3d", boost::python::no_init)
        .def("className", &PyGeExternalCurve3d::className).staticmethod("className")
        ;
}

PyGeExternalCurve3d::PyGeExternalCurve3d(AcGeEntity3d* pEnt)
    : PyGeCurve3d(pEnt)
{
}

std::string PyGeExternalCurve3d::className()
{
    return "AcGeExternalCurve3d";
}

AcGeExternalCurve3d* PyGeExternalCurve3d::impObj() const
{
    return static_cast<AcGeExternalCurve3d*>(m_imp.get());
}

//-----------------------------------------------------------------------------------------
//AcGeOffsetCurve3d wrapper
void makeAcGeOffsetCurve3dWrapper()
{
    static auto wrapper = class_<PyGeOffsetCurve3d, bases<PyGeCurve3d>>("OffsetCurve3d", boost::python::no_init)
        .def(init<const PyGeCurve3d&, const AcGeVector3d& ,double>())
        .def("className", &PyGeOffsetCurve3d::className).staticmethod("className")
        ;
}

PyGeOffsetCurve3d::PyGeOffsetCurve3d(const PyGeCurve3d& baseCurve, const AcGeVector3d& planeNormal, double offsetDistance)
    : PyGeCurve3d(new AcGeOffsetCurve3d(*baseCurve.impObj(), planeNormal, offsetDistance))
{
}

PyGeOffsetCurve3d::PyGeOffsetCurve3d(AcGeEntity3d* pEnt)
    : PyGeCurve3d(pEnt)
{
}

std::string PyGeOffsetCurve3d::className()
{
    return "AcGeOffsetCurve3d";
}

AcGeOffsetCurve3d* PyGeOffsetCurve3d::impObj() const
{
    return static_cast<AcGeOffsetCurve3d*>(m_imp.get());
}
