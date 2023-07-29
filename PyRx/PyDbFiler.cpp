#include "stdafx.h"
#include "PyDbFiler.h"
//TODO

void makePyDbDwgFilerWrapper()
{

}

PyDbDwgFiler::PyDbDwgFiler(AcDbDwgFiler* ptr, bool autoDelete)
    : PyRxObject(ptr, autoDelete,false)
{
}

Acad::ErrorStatus PyDbDwgFiler::filerStatus() const
{
    return impObj()->filerStatus();
}

AcDb::FilerType PyDbDwgFiler::filerType() const
{
    return impObj()->filerType();
}

void PyDbDwgFiler::setFilerStatus(Acad::ErrorStatus es)
{
    return impObj()->setFilerStatus(es);
}

void PyDbDwgFiler::resetFilerStatus()
{
    return impObj()->resetFilerStatus();
}

boost::python::tuple PyDbDwgFiler::dwgVersion() const
{
    PyAutoLockGIL lock;
    AcDb::AcDbDwgVersion ver; 
    AcDb::MaintenanceReleaseVersion maintVer;
    PyThrowBadEs(impObj()->dwgVersion(ver, maintVer));
    return boost::python::make_tuple(ver, maintVer);
}

AcDb::MaintenanceReleaseVersion PyDbDwgFiler::extendedDwgMaintenanceReleaseVersion() const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    AcDb::MaintenanceReleaseVersion val;
    PyThrowBadEs(impObj()->extendedDwgMaintenanceReleaseVersion(val));
    return val;
#endif // !BRXAPP
}

PyRxClass PyDbDwgFiler::desc()
{
    return PyRxClass(AcDbDwgFiler::desc(), false);
}

std::string PyDbDwgFiler::className()
{
    return std::string{ "AcDbDwgFiler" };
}

AcDbDwgFiler* PyDbDwgFiler::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbDwgFiler*>(m_pyImp.get());
}
