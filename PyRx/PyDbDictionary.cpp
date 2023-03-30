#include "stdafx.h"
#include "PyDbDictionary.h"
#include "PyDbObjectId.h"

PyDbDictionary::PyDbDictionary(AcDbDictionary* ptr, bool autoDelete)
: PyDbObject(ptr, autoDelete)
{

}

PyDbDictionary::PyDbDictionary(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbObject(nullptr, true)
{
    AcDbObject* pobj = nullptr;
    acdbOpenObject<AcDbObject>(pobj, id.m_id, mode);
    m_pImp = pobj;
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
}

PyDbObjectId PyDbDictionary::getAt(const std::string& entryName)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcDbObjectId id;
    imp->getAt(utf8_to_wstr(entryName).c_str(), id);
    return PyDbObjectId(id);
}

AcDbDictionary* PyDbDictionary::impObj() const
{
    return static_cast<AcDbDictionary*>(m_pImp);
}
