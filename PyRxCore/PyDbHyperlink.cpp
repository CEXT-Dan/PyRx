#include "stdafx.h"
#include "PyDbHyperlink.h"
#include "PyDbObject.h"

//-----------------------------------------------------------------------------------------
//PyDbHyperlink
void makePyDbHyperlinkWrapper()
{

}

PyDbHyperlink::PyDbHyperlink(AcDbHyperlink* ptr, bool autoDelete)
    : m_pyImp(ptr, PySharedObjectDeleter<AcDbHyperlink>(autoDelete))
{
}

std::string PyDbHyperlink::name() const
{
    return wstr_to_utf8(impObj()->name());
}

void PyDbHyperlink::setName(const std::string& cName)
{
    impObj()->setName(utf8_to_wstr(cName).c_str());
}

std::string PyDbHyperlink::description() const
{
    return wstr_to_utf8(impObj()->description());
}

void PyDbHyperlink::setDescription(const std::string& cDescription)
{
    impObj()->setDescription(utf8_to_wstr(cDescription).c_str());
}

std::string PyDbHyperlink::subLocation() const
{
    return wstr_to_utf8(impObj()->subLocation());
}

void PyDbHyperlink::setSubLocation(const std::string& cSubLocation)
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

void PyDbHyperlink::setFlags(const Adesk::Int32 lFlags)
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

}

PyDbHyperlinkCollection::PyDbHyperlinkCollection(AcDbHyperlinkCollection* ptr, bool autoDelete)
    : m_pyImp(ptr, PySharedObjectDeleter<AcDbHyperlinkCollection>(autoDelete))
{
}

void PyDbHyperlinkCollection::addHead1(const std::string& sName, const std::string& sDescription)
{
    impObj()->addHead(utf8_to_wstr(sName).c_str(), utf8_to_wstr(sDescription).c_str());
}

void PyDbHyperlinkCollection::addHead2(const std::string& sName, const std::string& sDescription, const std::string& sSubLocation)
{
    impObj()->addHead(utf8_to_wstr(sName).c_str(), utf8_to_wstr(sDescription).c_str(), utf8_to_wstr(sSubLocation).c_str());
}

void PyDbHyperlinkCollection::addTail1(const std::string& sName, const std::string& sDescription)
{
    impObj()->addTail(utf8_to_wstr(sName).c_str(), utf8_to_wstr(sDescription).c_str());
}

void PyDbHyperlinkCollection::addTail2(const std::string& sName, const std::string& sDescription, const std::string& sSubLocation)
{
    impObj()->addTail(utf8_to_wstr(sName).c_str(), utf8_to_wstr(sDescription).c_str(), utf8_to_wstr(sSubLocation).c_str());
}

void PyDbHyperlinkCollection::addAt1(int nIndex, const std::string& sName, const std::string& sDescription)
{
    impObj()->addAt(nIndex, utf8_to_wstr(sName).c_str(), utf8_to_wstr(sDescription).c_str());
}

void PyDbHyperlinkCollection::addAt2(int nIndex, const std::string& sName, const std::string& sDescription, const std::string& sSubLocation)
{
    impObj()->addAt(nIndex,utf8_to_wstr(sName).c_str(), utf8_to_wstr(sDescription).c_str(), utf8_to_wstr(sSubLocation).c_str());
}

void PyDbHyperlinkCollection::addAt3(int index, const PyDbHyperlink& pHLink)
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    impObj()->addAt(index, pHLink.impObj());
#endif
}

void PyDbHyperlinkCollection::removeHead()
{
    impObj()->removeHead();
}

void PyDbHyperlinkCollection::removeTail()
{
    impObj()->removeTail();
}

void PyDbHyperlinkCollection::removeAt(int nIndex)
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

}
