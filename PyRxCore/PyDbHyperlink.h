#pragma once

#include "PyRxObject.h"
#include "achapi.h"

#pragma pack (push, 8)
class PyDbObject;

//-----------------------------------------------------------------------------------------
//PyDbHyperlink
void makePyDbHyperlinkWrapper();

class PyDbHyperlink
{
public:
    PyDbHyperlink(AcDbHyperlink* ptr, bool autoDelete);
    virtual ~PyDbHyperlink() = default;
    std::string     name() const;
    void            setName(const std::string& cName);
    std::string     description() const;
    void            setDescription(const std::string& cDescription);
    std::string     subLocation() const;
    void            setSubLocation(const std::string& cSubLocation);
    std::string     getDisplayString() const;
    bool            isOutermostContainer() const;
    int             getNestedLevel() const;
    Adesk::Int32    flags() const;
    void            setFlags(const Adesk::Int32 lFlags);
    static std::string  className();
public:
    AcDbHyperlink* impObj(const std::source_location& src = std::source_location::current()) const;

public:
    std::shared_ptr<AcDbHyperlink> m_pyImp;
};

//-----------------------------------------------------------------------------------------
//PyDbHyperlinkCollection
void makePyDbHyperlinkCollectionWrapper();

class PyDbHyperlinkCollection
{
public:
    PyDbHyperlinkCollection(AcDbHyperlinkCollection* ptr, bool autoDelete);
    virtual ~PyDbHyperlinkCollection() = default;
    void            addHead1(const std::string& sName, const std::string& sDescription);
    void            addHead2(const std::string& sName, const std::string& sDescription, const std::string& sSubLocation);
    void            addTail1(const std::string& sName, const std::string& sDescription);
    void            addTail2(const std::string& sName, const std::string& sDescription, const std::string& sSubLocation);
    void            addAt1(int nIndex, const std::string& sName, const std::string& sDescription);
    void            addAt2(int nIndex, const std::string& sName, const std::string& sDescription, const std::string& sSubLocation);
    void            addAt3(int index, const PyDbHyperlink& pHLink);
    void            removeHead();
    void            removeTail();
    void            removeAt(int nIndex);
    int             count() const;
    PyDbHyperlink   item(int nIndex) const;
    static std::string  className();
public:
    AcDbHyperlinkCollection* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<AcDbHyperlinkCollection> m_pyImp;
};

//-----------------------------------------------------------------------------------------
//PyDbEntityHyperlinkPE
void makePyDbEntityHyperlinkPEWrapper();

class PyDbEntityHyperlinkPE : public PyRxObject
{
public:
    PyDbEntityHyperlinkPE(const PyRxObject& PE);
    PyDbEntityHyperlinkPE(AcDbEntityHyperlinkPE* ptr, bool autoDelete);
    virtual ~PyDbEntityHyperlinkPE() override = default;
    PyDbHyperlinkCollection getHyperlinkCollection1(const PyDbObject& obj);
    PyDbHyperlinkCollection getHyperlinkCollection2(const PyDbObject& obj, bool bOneOnly, bool bIgnoreBlockDefinition);
    PyDbHyperlinkCollection getHyperlinkCollection3(const boost::python::list& idContainers);
    PyDbHyperlinkCollection getHyperlinkCollection4(const boost::python::list& idContainers, bool bOneOnly, bool bIgnoreBlockDefinition);
    void                    setHyperlinkCollection(PyDbObject& obj, const PyDbHyperlinkCollection& pcHCL);
    uint32_t                getHyperlinkCount1(const PyDbObject& obj);
    uint32_t                getHyperlinkCount2(const PyDbObject& obj, bool bIgnoreBlockDefinition);
    uint32_t                getHyperlinkCount3(const boost::python::list& idContainers);
    uint32_t                getHyperlinkCount4(const boost::python::list& idContainers, bool bIgnoreBlockDefinition);
    bool                    hasHyperlink1(const PyDbObject& obj);
    bool                    hasHyperlink2(const PyDbObject& obj, bool bIgnoreBlockDefinition);
    bool                    hasHyperlink3(const boost::python::list& idContainers);
    bool                    hasHyperlink4(const boost::python::list& idContainers, bool bIgnoreBlockDefinition);
    static PyRxClass        desc();
    static std::string      className();
public:
    AcDbEntityHyperlinkPE* impObj(const std::source_location& src = std::source_location::current()) const;
};

#pragma pack (pop)
