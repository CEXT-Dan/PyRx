#include "stdafx.h"
#include "PyGeLinearEnt2d.h"

using namespace boost::python;
//-----------------------------------------------------------------------------------------
//AcGeLinearEnt2d wrapper
void makeAcGeLinearEnt2dWrapper()
{
    static auto wrapper = class_<PyGeLinearEnt2d, bases<PyGeCurve2d>>("LinearEnt2d", boost::python::no_init)
        .def("intersectWith", &PyGeLinearEnt2d::intersectWith1)
        .def("intersectWith", &PyGeLinearEnt2d::intersectWith2)
        .def("overlap", &PyGeLinearEnt2d::overlap1)
        .def("overlap", &PyGeLinearEnt2d::overlap2)
        .def("isParallelTo", &PyGeLinearEnt2d::isParallelTo1)
        .def("isParallelTo", &PyGeLinearEnt2d::isParallelTo2)
        .def("isPerpendicularTo", &PyGeLinearEnt2d::isPerpendicularTo1)
        .def("isPerpendicularTo", &PyGeLinearEnt2d::isPerpendicularTo2)
        .def("isColinearTo", &PyGeLinearEnt2d::isColinearTo1)
        .def("isColinearTo", &PyGeLinearEnt2d::isColinearTo2)
        .def("getPerpLine", &PyGeLinearEnt2d::getPerpLine)
        .def("getLine", &PyGeLinearEnt2d::getLine)
        .def("pointOnLine", &PyGeLinearEnt2d::pointOnLine)
        .def("direction", &PyGeLinearEnt2d::direction)
        .def("className", &PyGeLinearEnt2d::className).staticmethod("className")
        ;
}

PyGeLinearEnt2d::PyGeLinearEnt2d(AcGeEntity2d* pEnt)
    : PyGeCurve2d(pEnt)
{
}

boost::python::tuple PyGeLinearEnt2d::intersectWith1(const PyGeLinearEnt2d& line)
{
    auto imp = impObj();
    if (imp == nullptr || line.isNull())
        throw PyNullObject();
    AcGePoint2d p1;
    bool flag = imp->intersectWith(*line.impObj(),p1);
    return make_tuple(flag, p1);
}

boost::python::tuple PyGeLinearEnt2d::intersectWith2(const PyGeLinearEnt2d& line, const AcGeTol& tol)
{
    auto imp = impObj();
    if (imp == nullptr || line.isNull())
        throw PyNullObject();
    AcGePoint2d p1;
    bool flag = imp->intersectWith(*line.impObj(), p1, tol);
    return make_tuple(flag, p1);
}

boost::python::tuple PyGeLinearEnt2d::overlap1(const PyGeLinearEnt2d& line) const
{
    auto imp = impObj();
    if (imp == nullptr || line.isNull())
        throw PyNullObject();
    AcGeLinearEnt2d* poverlap = nullptr;
    bool flag = imp->overlap(*line.impObj(), poverlap);
    return make_tuple(flag, PyGeLinearEnt2d(poverlap));
}

boost::python::tuple PyGeLinearEnt2d::overlap2(const PyGeLinearEnt2d& line, const AcGeTol& tol) const
{
    auto imp = impObj();
    if (imp == nullptr || line.isNull())
        throw PyNullObject();
    AcGeLinearEnt2d* poverlap = nullptr;
    bool flag = imp->overlap(*line.impObj(), poverlap, tol);
    return make_tuple(flag, PyGeLinearEnt2d(poverlap));
}

Adesk::Boolean PyGeLinearEnt2d::isParallelTo1(const PyGeLinearEnt2d& line) const
{
    auto imp = impObj();
    if (imp == nullptr || line.isNull())
        throw PyNullObject();
    return imp->isParallelTo(*line.impObj());
}

Adesk::Boolean PyGeLinearEnt2d::isParallelTo2(const PyGeLinearEnt2d& line, const AcGeTol& tol) const
{
    auto imp = impObj();
    if (imp == nullptr || line.isNull())
        throw PyNullObject();
    return imp->isParallelTo(*line.impObj(), tol);
}

Adesk::Boolean PyGeLinearEnt2d::isPerpendicularTo1(const PyGeLinearEnt2d& line) const
{
    auto imp = impObj();
    if (imp == nullptr || line.isNull())
        throw PyNullObject();
    return imp->isPerpendicularTo(*line.impObj());
}

Adesk::Boolean PyGeLinearEnt2d::isPerpendicularTo2(const PyGeLinearEnt2d& line, const AcGeTol& tol) const
{
    auto imp = impObj();
    if (imp == nullptr || line.isNull())
        throw PyNullObject();
    return imp->isPerpendicularTo(*line.impObj(),tol);
}

Adesk::Boolean PyGeLinearEnt2d::isColinearTo1(const PyGeLinearEnt2d& line) const
{
    auto imp = impObj();
    if (imp == nullptr || line.isNull())
        throw PyNullObject();
    return imp->isColinearTo(*line.impObj());
}

Adesk::Boolean PyGeLinearEnt2d::isColinearTo2(const PyGeLinearEnt2d& line, const AcGeTol& tol) const
{
    auto imp = impObj();
    if (imp == nullptr || line.isNull())
        throw PyNullObject();
    return imp->isColinearTo(*line.impObj(), tol);
}

PyGeLine2d PyGeLinearEnt2d::getPerpLine(const AcGePoint2d& pnt) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcGeLine2d perpLine;
    imp->getPerpLine(pnt, perpLine);
    return PyGeLine2d(perpLine);
}

PyGeLine2d PyGeLinearEnt2d::getLine() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcGeLine2d perpLine;
    imp->getLine( perpLine);
    return PyGeLine2d(perpLine);
}

AcGePoint2d PyGeLinearEnt2d::pointOnLine() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->pointOnLine();
}

AcGeVector2d PyGeLinearEnt2d::direction() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->direction();
}

std::string PyGeLinearEnt2d::className()
{
    return "AcGeLinearEnt2d";
}

AcGeLinearEnt2d* PyGeLinearEnt2d::impObj() const
{
    return static_cast<AcGeLinearEnt2d*>(m_imp.get());
}


//-----------------------------------------------------------------------------------------
//AcGeLine2d  wrapper
void makeAcGeLine2dWrapper()
{
    static auto wrapper = class_<PyGeLine2d, bases<PyGeLinearEnt2d>>("Line2d")
        .def("className", &PyGeLine2d::className).staticmethod("className")
        ;
}

PyGeLine2d::PyGeLine2d()
    : PyGeLinearEnt2d(new AcGeLine2d())
{
}


PyGeLine2d::PyGeLine2d(AcGeEntity2d* pEnt)
    : PyGeLinearEnt2d(pEnt)
{
}

PyGeLine2d::PyGeLine2d(const AcGeLine2d& pEnt)
    : PyGeLinearEnt2d(new AcGeLine2d(pEnt))
{

}

std::string PyGeLine2d::className()
{
    return "AcGeLine2d";
}

AcGeLine2d* PyGeLine2d::impObj() const
{
    return static_cast<AcGeLine2d*>(m_imp.get());
}

//-----------------------------------------------------------------------------------------
//AcGeLine2d  wrapper
void makePyGeLineSeg2dWrapper()
{
    static auto wrapper = class_<PyGeLineSeg2d, bases<PyGeLinearEnt2d>>("LineSeg2d")
        .def("className", &PyGeLineSeg2d::className).staticmethod("className")
        ;
}

PyGeLineSeg2d::PyGeLineSeg2d()
    : PyGeLinearEnt2d(new AcGeLineSeg2d())
{
}

PyGeLineSeg2d::PyGeLineSeg2d(AcGeEntity2d* pEnt)
    : PyGeLinearEnt2d(pEnt)
{
}

std::string PyGeLineSeg2d::className()
{
    return "AcGeLineSeg2d";
}

AcGeLineSeg2d* PyGeLineSeg2d::impObj() const
{
    return static_cast<AcGeLineSeg2d*>(m_imp.get());
}

//-----------------------------------------------------------------------------------------
//AcGeRay2d  wrapper
void makeAcGeRay2dWrapper()
{
    static auto wrapper = class_<PyGeRay2d, bases<PyGeLinearEnt2d>>("Ray2d")
        .def("className", &PyGeRay2d::className).staticmethod("className")
        ;
}

PyGeRay2d::PyGeRay2d()
    : PyGeLinearEnt2d(new AcGeRay2d())
{
}

PyGeRay2d::PyGeRay2d(AcGeEntity2d* pEnt)
    : PyGeLinearEnt2d(pEnt)
{
}

std::string PyGeRay2d::className()
{
    return "AcGeRay2d";
}

AcGeRay2d* PyGeRay2d::impObj() const
{
    return static_cast<AcGeRay2d*>(m_imp.get());
} 
