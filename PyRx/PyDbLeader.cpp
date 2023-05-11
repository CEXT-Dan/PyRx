#include "stdafx.h"
#include "PyDbLeader.h"
#include "PyDbObjectId.h"
#include "PyGePlane.h"


using namespace boost::python;

//----------------------------------------------------------------------------------
//PyDbLeader
void makePyDbLeaderWrapper()
{
    class_<PyDbLeader, bases<PyDbCurve>>("Leader")
        .def(init<>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("setPlane", &PyDbLeader::setPlane)
        .def("normal", &PyDbLeader::normal)
        .def("numVertices", &PyDbLeader::numVertices)
        .def("appendVertex", &PyDbLeader::appendVertex)
        .def("removeLastVertex", &PyDbLeader::removeLastVertex)
        .def("firstVertex", &PyDbLeader::firstVertex)
        .def("lastVertex", &PyDbLeader::lastVertex)
        .def("vertexAt", &PyDbLeader::vertexAt)
        .def("setVertexAt", &PyDbLeader::setVertexAt)
        .def("hasArrowHead", &PyDbLeader::hasArrowHead)
        .def("disableArrowHead", &PyDbLeader::disableArrowHead)
        .def("setHasArrowHead", &PyDbLeader::setHasArrowHead)
        .def("hasHookLine", &PyDbLeader::hasHookLine)
        .def("setToSplineLeader", &PyDbLeader::setToSplineLeader)
        .def("setToStraightLeader", &PyDbLeader::setToStraightLeader)
        .def("isSplined", &PyDbLeader::isSplined)
        .def("setSplined", &PyDbLeader::setSplined)
        .def("dimensionStyle", &PyDbLeader::dimensionStyle)
        .def("setDimensionStyle", &PyDbLeader::setDimensionStyle)
        .def("setDimstyleData", &PyDbLeader::setDimstyleData)
        .def("attachAnnotation", &PyDbLeader::attachAnnotation)
        .def("detachAnnotation", &PyDbLeader::detachAnnotation)
        .def("annotationObjId", &PyDbLeader::annotationObjId)
        .def("setAnnotationObjId", &PyDbLeader::setAnnotationObjId)
        .def("evaluateLeader", &PyDbLeader::evaluateLeader)
        .def("annotationOffset", &PyDbLeader::annotationOffset)
        .def("setAnnotationOffset", &PyDbLeader::setAnnotationOffset)
        .def("annoType", &PyDbLeader::annoType)
        .def("annoHeight", &PyDbLeader::annoHeight)
        .def("annoWidth", &PyDbLeader::annoWidth)
        .def("dimasz", &PyDbLeader::dimasz)
        .def("dimclrd", &PyDbLeader::dimclrd)
        .def("dimgap", &PyDbLeader::dimgap)
        .def("dimlwd", &PyDbLeader::dimlwd)
        .def("dimsah", &PyDbLeader::dimsah)
        .def("dimscale", &PyDbLeader::dimscale)
        .def("dimtad", &PyDbLeader::dimtad)
        .def("dimtxsty", &PyDbLeader::dimtxsty)
        .def("dimtxt", &PyDbLeader::dimtxt)
        .def("setDimasz", &PyDbLeader::setDimasz)
        .def("setDimclrd", &PyDbLeader::setDimclrd)
        .def("setDimgap", &PyDbLeader::setDimgap)
        .def("setDimldrblk", &PyDbLeader::setDimldrblk1)
        .def("setDimldrblk", &PyDbLeader::setDimldrblk2)
        .def("setDimlwd", &PyDbLeader::setDimlwd)
        .def("setDimsah", &PyDbLeader::setDimsah)
        .def("setDimscale", &PyDbLeader::setDimscale)
        .def("setDimtad", &PyDbLeader::setDimtad)
        .def("setDimtxsty", &PyDbLeader::setDimtxsty)
        .def("setDimtxt", &PyDbLeader::setDimtxt)
        .def("modified", &PyDbLeader::modified)
        .def("erased", &PyDbLeader::erased1)
        .def("erased", &PyDbLeader::erased2)
        .def("goodbye", &PyDbLeader::goodbye)
        .def("copied", &PyDbLeader::copied)
        .def("setColorIndex", &PyDbLeader::setColorIndex1)
        .def("setColorIndex", &PyDbLeader::setColorIndex2)
        .def("className", &PyDbLeader::className).staticmethod("className")
        .def("desc", &PyDbLeader::desc).staticmethod("desc")
        ;

    enum_<AcDbLeader::AnnoType>("AnnoType")
        .value("kMText", AcDbLeader::AnnoType::kMText)
        .value("kFcf", AcDbLeader::AnnoType::kFcf)
        .value("kBlockRef", AcDbLeader::AnnoType::kBlockRef)
        .value("kNoAnno", AcDbLeader::AnnoType::kNoAnno)
        .export_values()
        ;
}

PyDbLeader::PyDbLeader()
    : PyDbCurve(new AcDbLeader(), true)
{
}

PyDbLeader::PyDbLeader(AcDbLeader* ptr, bool autoDelete)
    : PyDbCurve(ptr, autoDelete)
{
}

PyDbLeader::PyDbLeader(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbCurve(nullptr, false)
{
    AcDbLeader* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbLeader>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
}

void PyDbLeader::setPlane(const PyGePlane& plane)
{
    impObj()->setPlane(*plane.impObj());
}

AcGeVector3d PyDbLeader::normal() const
{
    return impObj()->normal();
}

int PyDbLeader::numVertices() const
{
    return impObj()->numVertices();
}

Adesk::Boolean PyDbLeader::appendVertex(const AcGePoint3d& val)
{
    return impObj()->appendVertex(val);
}

void PyDbLeader::removeLastVertex()
{
    return impObj()->removeLastVertex();
}

AcGePoint3d PyDbLeader::firstVertex() const
{
    return impObj()->firstVertex();
}

AcGePoint3d PyDbLeader::lastVertex() const
{
    return impObj()->lastVertex();
}

AcGePoint3d PyDbLeader::vertexAt(int idx) const
{
    return impObj()->vertexAt(idx);
}

Adesk::Boolean PyDbLeader::setVertexAt(int idx, const AcGePoint3d& val)
{
    return impObj()->setVertexAt(idx, val);
}

Adesk::Boolean PyDbLeader::hasArrowHead() const
{
    return impObj()->hasArrowHead();
}

void PyDbLeader::enableArrowHead()
{
    return impObj()->enableArrowHead();
}

void PyDbLeader::disableArrowHead()
{
    return impObj()->disableArrowHead();
}

void PyDbLeader::setHasArrowHead(Adesk::Boolean bEnable)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setHasArrowHead(bEnable);
#endif
}

Adesk::Boolean PyDbLeader::hasHookLine() const
{
    return impObj()->hasHookLine();
}

void PyDbLeader::setToSplineLeader()
{
    return impObj()->setToSplineLeader();
}

void PyDbLeader::setToStraightLeader()
{
    return impObj()->setToStraightLeader();
}

Adesk::Boolean PyDbLeader::isSplined() const
{
    return impObj()->isSplined();
}

void PyDbLeader::setSplined(Adesk::Boolean bSplined)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setSplined(bSplined);
#endif
}

PyDbHardPointerId PyDbLeader::dimensionStyle() const
{
    return PyDbHardPointerId(impObj()->dimensionStyle());
}

void PyDbLeader::setDimensionStyle(const PyDbHardPointerId& val)
{
    return impObj()->setDimensionStyle(val.m_id);
}

Acad::ErrorStatus PyDbLeader::setDimstyleData(const PyDbObjectId& newDataId)
{
    return impObj()->setDimstyleData(newDataId.m_id);
}

Acad::ErrorStatus PyDbLeader::attachAnnotation(const PyDbObjectId& annoId)
{
    return impObj()->attachAnnotation(annoId.m_id);
}

Acad::ErrorStatus PyDbLeader::detachAnnotation()
{
    return impObj()->detachAnnotation();
}

PyDbObjectId PyDbLeader::annotationObjId() const
{
    return PyDbObjectId(impObj()->annotationObjId());
}

Acad::ErrorStatus PyDbLeader::setAnnotationObjId(const PyDbObjectId& annoId)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setAnnotationObjId(annoId.m_id);
#endif
}

Acad::ErrorStatus PyDbLeader::evaluateLeader()
{
    return impObj()->evaluateLeader();
}

AcGeVector3d PyDbLeader::annotationOffset() const
{
    return impObj()->annotationOffset();
}

Acad::ErrorStatus PyDbLeader::setAnnotationOffset(const AcGeVector3d& offset)
{
    return impObj()->setAnnotationOffset(offset);
}

AcDbLeader::AnnoType PyDbLeader::annoType() const
{
    return impObj()->annoType();
}

double PyDbLeader::annoHeight() const
{
    return impObj()->annoHeight();
}

double PyDbLeader::annoWidth() const
{
    return impObj()->annoWidth();
}

double PyDbLeader::dimasz() const
{
    return impObj()->dimasz();
}

AcCmColor PyDbLeader::dimclrd() const
{
    return impObj()->dimclrd();
}

double PyDbLeader::dimgap() const
{
    return impObj()->dimgap();
}

AcDb::LineWeight PyDbLeader::dimlwd() const
{
    return impObj()->dimlwd();
}

PyDbObjectId PyDbLeader::dimldrblk() const
{
    return PyDbObjectId(impObj()->dimldrblk());
}

bool PyDbLeader::dimsah() const
{
    return impObj()->dimsah();
}

double PyDbLeader::dimscale() const
{
    return impObj()->dimscale();
}

int PyDbLeader::dimtad() const
{
    return impObj()->dimtad();
}

PyDbObjectId PyDbLeader::dimtxsty() const
{
    return PyDbObjectId(impObj()->dimtxsty());
}

double PyDbLeader::dimtxt() const
{
    return impObj()->dimtxt();
}

Acad::ErrorStatus PyDbLeader::setDimasz(double val)
{
    return impObj()->setDimasz(val);
}

Acad::ErrorStatus PyDbLeader::setDimclrd(AcCmColor& val)
{
    return impObj()->setDimclrd(val);
}

Acad::ErrorStatus PyDbLeader::setDimgap(double val)
{
    return impObj()->setDimgap(val);
}

Acad::ErrorStatus PyDbLeader::setDimldrblk1(const PyDbObjectId& val)
{
    return impObj()->setDimldrblk(val.m_id);
}

Acad::ErrorStatus PyDbLeader::setDimldrblk2(const std::string& val)
{
    return impObj()->setDimldrblk(utf8_to_wstr(val).c_str());
}

Acad::ErrorStatus PyDbLeader::setDimlwd(AcDb::LineWeight val)
{
    return impObj()->setDimlwd(val);
}

Acad::ErrorStatus PyDbLeader::setDimsah(bool val)
{
    return impObj()->setDimsah(val);
}

Acad::ErrorStatus PyDbLeader::setDimscale(double val)
{
    return impObj()->setDimscale(val);
}

Acad::ErrorStatus PyDbLeader::setDimtad(int val)
{
    return impObj()->setDimtad(val);
}

Acad::ErrorStatus PyDbLeader::setDimtxsty(const PyDbObjectId& val)
{
    return impObj()->setDimtxsty(val.m_id);
}

Acad::ErrorStatus PyDbLeader::setDimtxt(double val)
{
    return impObj()->setDimtxt(val);
}

void PyDbLeader::modified(const PyDbObject& obj)
{
    return impObj()->modified(obj.impObj());
}

void PyDbLeader::erased1(const PyDbObject& obj)
{
    return impObj()->erased(obj.impObj());
}

void PyDbLeader::erased2(const PyDbObject& obj, Adesk::Boolean val)
{
    return impObj()->erased(obj.impObj(), val);
}

void PyDbLeader::goodbye(const PyDbObject& obj)
{
    return impObj()->goodbye(obj.impObj());
}

void PyDbLeader::copied(const PyDbObject& objA, const PyDbObject& objB)
{
    return impObj()->copied(objA.impObj(), objB.impObj());
}

Acad::ErrorStatus PyDbLeader::setColorIndex1(Adesk::UInt16 val)
{
    return impObj()->setColorIndex(val);
}

Acad::ErrorStatus PyDbLeader::setColorIndex2(Adesk::UInt16 val, Adesk::Boolean doSubents)
{
    return impObj()->setColorIndex(val, doSubents);
}

std::string PyDbLeader::className()
{
    return "AcDbLeader";
}

PyRxClass PyDbLeader::desc()
{
    return PyRxClass(AcDbLeader::desc(), false);
}

AcDbLeader* PyDbLeader::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbLeader*>(m_pImp.get());
}
