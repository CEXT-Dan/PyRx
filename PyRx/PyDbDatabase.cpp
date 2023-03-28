#include "stdafx.h"
#include "PyDbDatabase.h"
#include "PyDbObjectId.h"

using namespace boost::python;

//---------------------------------------------------------------------------------------------------
// makeAcDbDatabaseWrapper
void makeAcDbDatabaseWrapper()
{
    static auto wrapper = class_<PyDbDatabase, bases<PyRxObject>>("DbDatabase")
        .def(init<>())
        //.def("abortDeepClone", &PyDbDatabase::dummy)
        //.def("addAcDbObject", &PyDbDatabase::dummy)
        //.def("addReactor", &PyDbDatabase::dummy)
        .def("angbase", &PyDbDatabase::angbase)
        .def("angdir", &PyDbDatabase::angdir)
        .def("annoAllVisible", &PyDbDatabase::annoAllVisible)
        .def("annotativeDwg", &PyDbDatabase::annotativeDwg)
        //.def("applyPartialOpenFilters", &PyDbDatabase::dummy)
        .def("approxNumObjects", &PyDbDatabase::approxNumObjects)

        .def("className", &PyDbDatabase::className)
        .def("create", &PyDbDatabase::create)
        .def("getFilename", &PyDbDatabase::getFilename)
        .def("readDwgFile", &PyDbDatabase::readDwgFile)
        .def("blockTableId", &PyDbDatabase::blockTableId)
        .def("modelspaceId", &PyDbDatabase::modelspaceId)
        ;
}

//---------------------------------------------------------------------------------------------------
// PyDbDatabase
PyDbDatabase::PyDbDatabase()
    :PyRxObject(acdbHostApplicationServices()->workingDatabase(), false)
{
}

PyDbDatabase::PyDbDatabase(AcDbDatabase* _pDb)
    : PyRxObject(_pDb, false)
{
}

PyDbDatabase::~PyDbDatabase()
{
}

double PyDbDatabase::angbase() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->angbase();
    return 0;
}

bool PyDbDatabase::angdir() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->angdir();
    return false;
}

bool PyDbDatabase::annoAllVisible() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->annoAllVisible();
    return false;
}

bool PyDbDatabase::annotativeDwg() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->annotativeDwg();
    return false;
}

int PyDbDatabase::approxNumObjects() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->approxNumObjects();
    return 0;
}

Acad::ErrorStatus PyDbDatabase::create(bool buildDefaultDrawing, bool noDocument)
{
    deleteNativeObject();
    m_bAutoDelete = true;
    m_pImp = new AcDbDatabase(buildDefaultDrawing, noDocument);
    return eOk;
}

Acad::ErrorStatus PyDbDatabase::readDwgFile(const char* fileName)
{
    std::wstring wsfileName{ utf8_to_wstr(fileName) };
    auto imp = impObj();
    if (imp != nullptr)
        return imp->readDwgFile(wsfileName.c_str());
    return eNullPtr;
}

std::string PyDbDatabase::getFilename()
{
    auto imp = impObj();
    if (imp != nullptr)
    {
        const TCHAR* path = nullptr;
        if (imp->getFilename(path) == eOk && path != nullptr)
            return std::string{ wstr_to_utf8(path) };
    }
    return std::string{ };
}

PyDbObjectId PyDbDatabase::blockTableId() const
{
    return PyDbObjectId(impObj()->blockTableId());
}

PyDbObjectId PyDbDatabase::modelspaceId() const
{
   return PyDbObjectId(acdbSymUtil()->blockModelSpaceId(impObj()));
}

std::string PyDbDatabase::className()
{
    return "AcDbDatabase";
}

AcDbDatabase* PyDbDatabase::impObj() const
{
    return static_cast<AcDbDatabase*>(m_pImp);
}

