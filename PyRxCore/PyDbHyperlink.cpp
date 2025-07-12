#include "stdafx.h"
#include "PyDbHyperlink.h"
#include "PyDbObject.h"
#include "PyDbObjectId.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------------
//PyDbHyperlink
void makePyDbHyperlinkWrapper()
{
    PyDocString DS("Hyperlink");
    class_<PyDbHyperlink>("Hyperlink", boost::python::no_init)
        .def("name", &PyDbHyperlink::name, DS.ARGS())
        .def("setName", &PyDbHyperlink::setName, DS.ARGS({ "val: str" }))
        .def("description", &PyDbHyperlink::description, DS.ARGS())
        .def("setDescription", &PyDbHyperlink::setDescription, DS.ARGS({ "val: str" }))
        .def("subLocation", &PyDbHyperlink::subLocation, DS.ARGS())
        .def("setSubLocation", &PyDbHyperlink::setSubLocation, DS.ARGS({ "val: str" }))
        .def("getDisplayString", &PyDbHyperlink::getDisplayString, DS.ARGS())
        .def("isOutermostContainer", &PyDbHyperlink::isOutermostContainer, DS.ARGS())
        .def("getNestedLevel", &PyDbHyperlink::getNestedLevel, DS.ARGS())
        .def("flags", &PyDbHyperlink::flags, DS.ARGS())
        .def("setFlags", &PyDbHyperlink::setFlags, DS.ARGS({ "val: int" }))
        .def("className", &PyDbHyperlink::className, DS.SARGS()).staticmethod("className")
        ;
}

PyDbHyperlink::PyDbHyperlink(AcDbHyperlink* ptr, bool autoDelete)
    : m_pyImp(ptr, PySharedObjectDeleter<AcDbHyperlink>(autoDelete))
{
}

std::string PyDbHyperlink::name() const
{
    return wstr_to_utf8(impObj()->name());
}

void PyDbHyperlink::setName(const std::string& cName) const
{
    impObj()->setName(utf8_to_wstr(cName).c_str());
}

std::string PyDbHyperlink::description() const
{
    return wstr_to_utf8(impObj()->description());
}

void PyDbHyperlink::setDescription(const std::string& cDescription) const
{
    impObj()->setDescription(utf8_to_wstr(cDescription).c_str());
}

std::string PyDbHyperlink::subLocation() const
{
    return wstr_to_utf8(impObj()->subLocation());
}

void PyDbHyperlink::setSubLocation(const std::string& cSubLocation) const
{
    impObj()->setSubLocation(utf8_to_wstr(cSubLocation).c_str());
}

std::string PyDbHyperlink::getDisplayString() const
{
    return wstr_to_utf8(impObj()->getDisplayString());
}

bool PyDbHyperlink::isOutermostContainer() const
{
    return impObj()->isOutermostContainer();
}

int PyDbHyperlink::getNestedLevel() const
{
    return impObj()->getNestedLevel();
}

Adesk::Int32 PyDbHyperlink::flags() const
{
    return impObj()->flags();
}

void PyDbHyperlink::setFlags(const Adesk::Int32 lFlags) const
{
    impObj()->setFlags(lFlags);
}

std::string PyDbHyperlink::className()
{
    return "AcDbHyperlink";
}

AcDbHyperlink* PyDbHyperlink::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//-----------------------------------------------------------------------------------------
//PyDbHyperlinkCollection
void makePyDbHyperlinkCollectionWrapper()
{
    constexpr const std::string_view addAtOverloads = "Overloads:\n"
        "- index: int, sName: str, sDescription: str, sSubLocation: str = ...\n"
        "- index: int, pHLink: PyDb.Hyperlink\n";

    PyDocString DS("HyperlinkCollection");
    class_<PyDbHyperlinkCollection>("HyperlinkCollection", boost::python::no_init)
        .def("addHead", &PyDbHyperlinkCollection::addHead1)
        .def("addHead", &PyDbHyperlinkCollection::addHead2, DS.ARGS({ "sName: str","sDescription: str","sSubLocation: str = ..." }))
        .def("addTail", &PyDbHyperlinkCollection::addTail1)
        .def("addTail", &PyDbHyperlinkCollection::addTail2, DS.ARGS({ "sName: str","sDescription: str","sSubLocation: str = ..." }))
        .def("addAt", &PyDbHyperlinkCollection::addAt1)
        .def("addAt", &PyDbHyperlinkCollection::addAt2)
        .def("addAt", &PyDbHyperlinkCollection::addAt3, DS.OVRL(addAtOverloads))
        .def("removeHead", &PyDbHyperlinkCollection::removeHead, DS.ARGS())
        .def("removeTail", &PyDbHyperlinkCollection::removeTail, DS.ARGS())
        .def("removeAt", &PyDbHyperlinkCollection::removeAt, DS.ARGS({ "index: int" }))
        .def("count", &PyDbHyperlinkCollection::count, DS.ARGS())
        .def("item", &PyDbHyperlinkCollection::item, DS.ARGS({ "index: int" }))
        .def("className", &PyDbHyperlinkCollection::className, DS.SARGS()).staticmethod("className")
        ;
}

PyDbHyperlinkCollection::PyDbHyperlinkCollection(AcDbHyperlinkCollection* ptr, bool autoDelete)
    : m_pyImp(ptr, PySharedObjectDeleter<AcDbHyperlinkCollection>(autoDelete))
{
}

void PyDbHyperlinkCollection::addHead1(const std::string& sName, const std::string& sDescription) const
{
    impObj()->addHead(utf8_to_wstr(sName).c_str(), utf8_to_wstr(sDescription).c_str());
}

void PyDbHyperlinkCollection::addHead2(const std::string& sName, const std::string& sDescription, const std::string& sSubLocation) const
{
    impObj()->addHead(utf8_to_wstr(sName).c_str(), utf8_to_wstr(sDescription).c_str(), utf8_to_wstr(sSubLocation).c_str());
}

void PyDbHyperlinkCollection::addTail1(const std::string& sName, const std::string& sDescription) const
{
    impObj()->addTail(utf8_to_wstr(sName).c_str(), utf8_to_wstr(sDescription).c_str());
}

void PyDbHyperlinkCollection::addTail2(const std::string& sName, const std::string& sDescription, const std::string& sSubLocation) const
{
    impObj()->addTail(utf8_to_wstr(sName).c_str(), utf8_to_wstr(sDescription).c_str(), utf8_to_wstr(sSubLocation).c_str());
}

void PyDbHyperlinkCollection::addAt1(int nIndex, const std::string& sName, const std::string& sDescription) const
{
    impObj()->addAt(nIndex, utf8_to_wstr(sName).c_str(), utf8_to_wstr(sDescription).c_str());
}

void PyDbHyperlinkCollection::addAt2(int nIndex, const std::string& sName, const std::string& sDescription, const std::string& sSubLocation) const
{
    impObj()->addAt(nIndex, utf8_to_wstr(sName).c_str(), utf8_to_wstr(sDescription).c_str(), utf8_to_wstr(sSubLocation).c_str());
}

void PyDbHyperlinkCollection::addAt3(int index, const PyDbHyperlink& pHLink) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    impObj()->addAt(index, pHLink.impObj());
#endif
}

void PyDbHyperlinkCollection::removeHead() const
{
    impObj()->removeHead();
}

void PyDbHyperlinkCollection::removeTail() const
{
    impObj()->removeTail();
}

void PyDbHyperlinkCollection::removeAt(int nIndex) const
{
    impObj()->removeAt(nIndex);
}

int PyDbHyperlinkCollection::count() const
{
    return impObj()->count();
}

PyDbHyperlink PyDbHyperlinkCollection::item(int nIndex) const
{
    return PyDbHyperlink{ impObj()->item(nIndex), false };
}

std::string PyDbHyperlinkCollection::className()
{
    return "AcDbHyperlinkCollection";
}

AcDbHyperlinkCollection* PyDbHyperlinkCollection::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//-----------------------------------------------------------------------------------------
//PyDbEntityHyperlinkPE
void makePyDbEntityHyperlinkPEWrapper()
{
    constexpr const std::string_view getHyperlinkCollectionOverloads = "Overloads:\n"
        "- obj: PyDb.DbObject, bOneOnly: bool = False, bIgnoreBlockDefinition: bool=True\n"
        "- ids: list[PyDb.ObjectId], bOneOnly: bool = False, bIgnoreBlockDefinition: bool=True\n";

    constexpr const std::string_view getHyperlinkCountOverloads = "Overloads:\n"
        "- obj: PyDb.DbObject, bIgnoreBlockDefinition: bool=True\n"
        "- ids: list[PyDb.ObjectId], bIgnoreBlockDefinition: bool=True\n";

    constexpr const std::string_view hasHyperlinkOverloads = "Overloads:\n"
        "- obj: PyDb.DbObject, bIgnoreBlockDefinition: bool=True\n"
        "- ids: list[PyDb.ObjectId], bIgnoreBlockDefinition: bool=True\n";

    PyDocString DS("EntityHyperlinkPE");
    class_<PyDbEntityHyperlinkPE, bases<PyRxObject>>("EntityHyperlinkPE", boost::python::no_init)
        .def(init<const PyRxObject&>(DS.ARGS({ "obj: PyRx.RxObject" })))
        .def("getHyperlinkCollection", &PyDbEntityHyperlinkPE::getHyperlinkCollection1)
        .def("getHyperlinkCollection", &PyDbEntityHyperlinkPE::getHyperlinkCollection2)
        .def("getHyperlinkCollection", &PyDbEntityHyperlinkPE::getHyperlinkCollection3)
        .def("getHyperlinkCollection", &PyDbEntityHyperlinkPE::getHyperlinkCollection4, DS.OVRL(getHyperlinkCollectionOverloads))
        .def("setHyperlinkCollection", &PyDbEntityHyperlinkPE::setHyperlinkCollection, DS.ARGS({ "db: PyDb.DbObject" ,"pcHCL: PyDb.HyperlinkCollection" }))
        .def("getHyperlinkCount", &PyDbEntityHyperlinkPE::getHyperlinkCount1)
        .def("getHyperlinkCount", &PyDbEntityHyperlinkPE::getHyperlinkCount2)
        .def("getHyperlinkCount", &PyDbEntityHyperlinkPE::getHyperlinkCount3)
        .def("getHyperlinkCount", &PyDbEntityHyperlinkPE::getHyperlinkCount4, DS.OVRL(getHyperlinkCountOverloads))
        .def("hasHyperlink", &PyDbEntityHyperlinkPE::hasHyperlink1)
        .def("hasHyperlink", &PyDbEntityHyperlinkPE::hasHyperlink2)
        .def("hasHyperlink", &PyDbEntityHyperlinkPE::hasHyperlink3)
        .def("hasHyperlink", &PyDbEntityHyperlinkPE::hasHyperlink4, DS.OVRL(hasHyperlinkOverloads))
        .def("desc", &PyDbEntityHyperlinkPE::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("className", &PyDbEntityHyperlinkPE::className, DS.SARGS()).staticmethod("className")
        ;
}

PyDbEntityHyperlinkPE::PyDbEntityHyperlinkPE(const PyRxObject& PE)
    :PyDbEntityHyperlinkPE((AcDbEntityHyperlinkPE*)PE.impObj(), false)
{
}

PyDbEntityHyperlinkPE::PyDbEntityHyperlinkPE(AcDbEntityHyperlinkPE* ptr, bool autoDelete)
    :PyRxObject(ptr, autoDelete, false)
{
}

PyDbHyperlinkCollection PyDbEntityHyperlinkPE::getHyperlinkCollection1(const PyDbObject& obj) const
{
    return getHyperlinkCollection2(obj, false, true);
}

PyDbHyperlinkCollection PyDbEntityHyperlinkPE::getHyperlinkCollection2(const PyDbObject& obj, bool bOneOnly, bool bIgnoreBlockDefinition) const
{
    AcDbHyperlinkCollection* pcHCL = nullptr;
    PyThrowBadEs(impObj()->getHyperlinkCollection(obj.impObj(), pcHCL, bOneOnly, bIgnoreBlockDefinition));
    return PyDbHyperlinkCollection{ pcHCL , true };
}

PyDbHyperlinkCollection PyDbEntityHyperlinkPE::getHyperlinkCollection3(const boost::python::list& idContainers) const
{
    return getHyperlinkCollection4(idContainers, false, true);
}

PyDbHyperlinkCollection PyDbEntityHyperlinkPE::getHyperlinkCollection4(const boost::python::list& idContainers, bool bOneOnly, bool bIgnoreBlockDefinition) const
{
    AcDbHyperlinkCollection* pcHCL = nullptr;
    const AcDbObjectIdArray ids(PyListToObjectIdArray(idContainers));
    const AcDbObjectIdArray* pids = std::addressof(ids);
    PyThrowBadEs(impObj()->getHyperlinkCollection(pids, pcHCL, bOneOnly, bIgnoreBlockDefinition));
    return PyDbHyperlinkCollection{ pcHCL , true };
}

void PyDbEntityHyperlinkPE::setHyperlinkCollection(PyDbObject& obj, const PyDbHyperlinkCollection& pcHCL) const
{
    PyThrowBadEs(impObj()->setHyperlinkCollection(obj.impObj(), pcHCL.impObj()));
}

uint32_t PyDbEntityHyperlinkPE::getHyperlinkCount1(const PyDbObject& obj) const
{
    return getHyperlinkCount2(obj, true);
}

uint32_t PyDbEntityHyperlinkPE::getHyperlinkCount2(const PyDbObject& obj, bool bIgnoreBlockDefinition) const
{
    uint32_t count = 0;
    PyThrowBadEs(impObj()->getHyperlinkCount(obj.impObj(), count, bIgnoreBlockDefinition));
    return count;
}

uint32_t PyDbEntityHyperlinkPE::getHyperlinkCount3(const boost::python::list& idContainers) const
{
    return getHyperlinkCount4(idContainers, true);
}

uint32_t PyDbEntityHyperlinkPE::getHyperlinkCount4(const boost::python::list& idContainers, bool bIgnoreBlockDefinition) const
{
    uint32_t count = 0;
    const AcDbObjectIdArray ids(PyListToObjectIdArray(idContainers));
    const AcDbObjectIdArray* pids = std::addressof(ids);
    PyThrowBadEs(impObj()->getHyperlinkCount(pids, count, bIgnoreBlockDefinition));
    return count;
}

bool PyDbEntityHyperlinkPE::hasHyperlink1(const PyDbObject& obj) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
 #else
    return hasHyperlink2(obj, true);
#endif
}

bool PyDbEntityHyperlinkPE::hasHyperlink2(const PyDbObject& obj, bool bIgnoreBlockDefinition) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    bool flag = false;
    PyThrowBadEs(impObj()->hasHyperlink(obj.impObj(), flag, bIgnoreBlockDefinition));
    return flag;
#endif
}

bool PyDbEntityHyperlinkPE::hasHyperlink3(const boost::python::list& idContainers) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return hasHyperlink4(idContainers, true);
#endif
}

bool PyDbEntityHyperlinkPE::hasHyperlink4(const boost::python::list& idContainers, bool bIgnoreBlockDefinition) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    bool flag = false;
    const AcDbObjectIdArray ids(PyListToObjectIdArray(idContainers));
    const AcDbObjectIdArray* pids = std::addressof(ids);
    PyThrowBadEs(impObj()->hasHyperlink(pids, flag, bIgnoreBlockDefinition));
    return flag;
#endif
}

PyRxClass PyDbEntityHyperlinkPE::desc()
{
    return PyRxClass(AcDbEntityHyperlinkPE::desc(), false);
}

std::string PyDbEntityHyperlinkPE::className()
{
    return "AcDbEntityHyperlinkPE";
}

AcDbEntityHyperlinkPE* PyDbEntityHyperlinkPE::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbEntityHyperlinkPE*>(m_pyImp.get());
}
