#include "stdafx.h"
#include "PyDbObject.h"

using namespace boost::python;

void makeAcDbObjectWrapper()
{
    static auto wrapper = class_<PyDbObject, bases<PyGiDrawable>>("DbObject", boost::python::no_init)
        .def("className", &PyDbObject::className)
        .def("close", &PyDbObject::close)
        ;
}

//-----------------------------------------------------------------------------------------
//PyDbObject
PyDbObject::PyDbObject(AcDbObject* ptr, bool autoDelete)
    : PyGiDrawable(ptr, autoDelete)
{
}

PyDbObject::~PyDbObject()
{
    if (m_pImp != nullptr)
    {
        AcDbObject* pDbo = static_cast<AcDbObject*>(m_pImp);
        if (!pDbo->objectId().isNull())
        {
            pDbo->close();
            m_bAutoDelete = false;
        }
    }
}

Acad::ErrorStatus PyDbObject::close()
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->close();
    return eNullPtr;
}

std::string PyDbObject::className()
{
    return "AcDbObject";
}

AcDbObject* PyDbObject::impObj() const
{
    return static_cast<AcDbObject*>(m_pImp);
}
