#include "stdafx.h"
#include "PyDbEntity.h"

using namespace boost::python;

//----------------------------------------------------------------------------------------------------
//wrapper
void makeAcDbEntityWrapper()
{
    static auto wrapper = class_<PyDbEntity, bases<PyDbObject>>("DbEntity", boost::python::no_init)
        .def("className", &PyDbObject::className)
        ;
}

//----------------------------------------------------------------------------------------------------
//PyDbEntity
PyDbEntity::PyDbEntity(AcDbEntity* ptr, bool autoDelete)
    : PyDbObject (ptr, autoDelete)
{
}

std::string PyDbEntity::className()
{
    return "AcDbEntity";
}

AcDbEntity* PyDbEntity::impObj() const
{
    return static_cast<AcDbEntity*>(m_pImp);
}
