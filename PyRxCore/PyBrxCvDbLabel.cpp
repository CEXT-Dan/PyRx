#include "stdafx.h"


#ifdef BRXAPP
#include "PyBrxCvDbLabel.h"
#include "PyDbObjectId.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------
//PyBrxCvDbStyle
void makePyBrxCvDbStyleWrapper()
{
    {
        PyDocString DS("CvDbStyle");
        class_<PyBrxCvDbStyle, bases<PyBrxCvDbObject>>("CvDbStyle", boost::python::no_init)
            .def(init<const PyDbObjectId&>())
            .def(init<const PyDbObjectId&, AcDb::OpenMode>())
            .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: ObjectId", "mode: PyDb.OpenMode=PyDb.OpenMode.kForRead", "erased: bool=False" })))

            .def("displaySetting", &PyBrxCvDbStyle::displaySetting, DS.ARGS())
            .def("displaySettings", &PyBrxCvDbStyle::displaySettings, DS.ARGS())
            .def("createdDate", &PyBrxCvDbStyle::createdDate, DS.ARGS())
            .def("createdBy", &PyBrxCvDbStyle::createdBy, DS.ARGS())
            .def("lastEditedDate", &PyBrxCvDbStyle::lastEditedDate, DS.ARGS())
            .def("lastEditedBy", &PyBrxCvDbStyle::lastEditedBy, DS.ARGS())
            .def("setCreatedBy", &PyBrxCvDbStyle::setCreatedBy, DS.ARGS({ "filter : str" }))

            .def("className", &PyBrxCvDbStyle::className, DS.SARGS()).staticmethod("className")
            .def("desc", &PyBrxCvDbStyle::desc, DS.SARGS(15560)).staticmethod("desc")
            .def("cloneFrom", &PyBrxCvDbStyle::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
            .def("cast", &PyBrxCvDbStyle::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
            ;
    }
}

PyBrxCvDbStyle::PyBrxCvDbStyle(const PyDbObjectId& id)
    : PyBrxCvDbStyle(openAcDbObject<BrxCvDbStyle>(id), false)
{
}

PyBrxCvDbStyle::PyBrxCvDbStyle(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyBrxCvDbStyle(openAcDbObject<BrxCvDbStyle>(id, mode), false)
{
}

PyBrxCvDbStyle::PyBrxCvDbStyle(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyBrxCvDbStyle(openAcDbObject<BrxCvDbStyle>(id, mode, erased), false)
{
}

BrxCvDbStylePartDisplaySettingsPtr PyBrxCvDbStyle::displaySetting(DisplayOrientation orientation, const AcString& partName) const
{
    return BrxCvDbStylePartDisplaySettingsPtr();
}

boost::python::list PyBrxCvDbStyle::displaySettings(BrxCvDbLabelStyle::DisplayOrientation orientation) const
{
    PyAutoLockGIL lock;
    boost::python::list _pylist;
    for (auto item : impObj()->displaySettings(orientation))
        _pylist.append(BrxCvDbStylePartDisplaySettingsPtr(item));
    return _pylist;
}

PyDbDate PyBrxCvDbStyle::createdDate() const
{
    return PyDbDate();
}

const std::string PyBrxCvDbStyle::createdBy() const
{
    return wstr_to_utf8(impObj()->createdBy());
}

PyDbDate PyBrxCvDbStyle::lastEditedDate() const
{
    return PyDbDate();
}

const std::string PyBrxCvDbStyle::lastEditedBy() const
{
    return wstr_to_utf8(impObj()->lastEditedBy());
}

void PyBrxCvDbStyle::setCreatedBy(const AcString& value)
{
    PyThrowBadEs(impObj()->setCreatedBy(value));
    return;
}

PyBrxCvDbStyle::PyBrxCvDbStyle(BrxCvDbStyle* ptr, bool autoDelete)
    : PyBrxCvDbObject(ptr, autoDelete)
{
}

BrxCvDbStyle* PyBrxCvDbStyle::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<BrxCvDbStyle*>(m_pyImp.get());
}

#endif//BRXAPP