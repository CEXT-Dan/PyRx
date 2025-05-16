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
    void            setName(const std::string& cName) const;
    std::string     description() const;
    void            setDescription(const std::string& cDescription) const;
    std::string     subLocation() const;
    void            setSubLocation(const std::string& cSubLocation) const;
    std::string     getDisplayString() const;
    bool            isOutermostContainer() const;
    int             getNestedLevel() const;
    Adesk::Int32    flags() const;
    void            setFlags(const Adesk::Int32 lFlags) const;
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
    void            addHead1(const std::string& sName, const std::string& sDescription) const;
    void            addHead2(const std::string& sName, const std::string& sDescription, const std::string& sSubLocation) const;
    void            addTail1(const std::string& sName, const std::string& sDescription) const;
    void            addTail2(const std::string& sName, const std::string& sDescription, const std::string& sSubLocation) const;
    void            addAt1(int nIndex, const std::string& sName, const std::string& sDescription) const;
    void            addAt2(int nIndex, const std::string& sName, const std::string& sDescription, const std::string& sSubLocation) const;
    void            addAt3(int index, const PyDbHyperlink& pHLink) const;
    void            removeHead() const;
    void            removeTail() const;
    void            removeAt(int nIndex) const;
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
    PyDbHyperlinkCollection getHyperlinkCollection1(const PyDbObject& obj) const;
    PyDbHyperlinkCollection getHyperlinkCollection2(const PyDbObject& obj, bool bOneOnly, bool bIgnoreBlockDefinition) const;
    PyDbHyperlinkCollection getHyperlinkCollection3(const boost::python::list& idContainers) const;
    PyDbHyperlinkCollection getHyperlinkCollection4(const boost::python::list& idContainers, bool bOneOnly, bool bIgnoreBlockDefinition) const;
    void                    setHyperlinkCollection(PyDbObject& obj, const PyDbHyperlinkCollection& pcHCL) const;
    uint32_t                getHyperlinkCount1(const PyDbObject& obj) const;
    uint32_t                getHyperlinkCount2(const PyDbObject& obj, bool bIgnoreBlockDefinition) const;
    uint32_t                getHyperlinkCount3(const boost::python::list& idContainers) const;
    uint32_t                getHyperlinkCount4(const boost::python::list& idContainers, bool bIgnoreBlockDefinition) const;
    bool                    hasHyperlink1(const PyDbObject& obj) const;
    bool                    hasHyperlink2(const PyDbObject& obj, bool bIgnoreBlockDefinition) const;
    bool                    hasHyperlink3(const boost::python::list& idContainers) const;
    bool                    hasHyperlink4(const boost::python::list& idContainers, bool bIgnoreBlockDefinition) const;
    static PyRxClass        desc();
    static std::string      className();
public:
    AcDbEntityHyperlinkPE* impObj(const std::source_location& src = std::source_location::current()) const;
};

#pragma pack (pop)
