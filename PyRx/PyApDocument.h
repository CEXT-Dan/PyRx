#pragma once

#include "PyDbDatabase.h "

class PyAcEditor;

void makeAcApDocumentWrapper();

//-----------------------------------------------------------------------------------------
//PyApDocument
class PyApDocument : public PyRxObject
{
public:
    enum class SaveFormat
    {
        kUnknown = AcApDocument::SaveFormat::kUnknown,
        kR12_dxf = AcApDocument::SaveFormat::kR12_dxf,
        kR13_dwg = AcApDocument::SaveFormat::kR13_dwg,
        kR13_dxf = AcApDocument::SaveFormat::kR13_dxf,
        kR14_dwg = AcApDocument::SaveFormat::kR14_dwg,
        kR14_dxf = AcApDocument::SaveFormat::kR14_dxf,
        k2000_dwg = AcApDocument::SaveFormat::k2000_dwg,
        k2000_dxf = AcApDocument::SaveFormat::k2000_dxf,
        k2000_Template = AcApDocument::SaveFormat::k2000_Template,
        k2000_Standard = AcApDocument::SaveFormat::k2000_Standard,
        k2000_xml = AcApDocument::SaveFormat::k2000_xml,
        k2004_dwg = AcApDocument::SaveFormat::k2004_dwg,
        k2004_dxf = AcApDocument::SaveFormat::k2004_dxf,
        k2004_Template = AcApDocument::SaveFormat::k2004_Template,
        k2004_Standard = AcApDocument::SaveFormat::k2004_Standard,
        k2007_dwg = AcApDocument::SaveFormat::k2007_dwg,
        k2007_dxf = AcApDocument::SaveFormat::k2007_dxf,
        k2007_Template = AcApDocument::SaveFormat::k2007_Template,
        k2007_Standard = AcApDocument::SaveFormat::k2007_Standard,
        k2010_dwg = AcApDocument::SaveFormat::k2010_dwg,
        k2010_dxf = AcApDocument::SaveFormat::k2010_dxf,
        k2010_Template = AcApDocument::SaveFormat::k2010_Template,
        k2010_Standard = AcApDocument::SaveFormat::k2010_Standard,
        k2013_dwg = AcApDocument::SaveFormat::k2013_dwg,
        k2013_dxf = AcApDocument::SaveFormat::k2013_dxf,
        k2013_Template = AcApDocument::SaveFormat::k2013_Template,
        k2013_Standard = AcApDocument::SaveFormat::k2013_Standard,
        k2018_dwg = AcApDocument::SaveFormat::k2018_dwg,
        k2018_dxf = AcApDocument::SaveFormat::k2018_dxf,
        k2018_Template = AcApDocument::SaveFormat::k2018_Template,
        k2018_Standard = AcApDocument::SaveFormat::k2018_Standard,
        kNative = AcApDocument::SaveFormat::kNative,
        kNative_Template = AcApDocument::SaveFormat::kNative_Template,
    };
public:
    PyApDocument(AcApDocument* ptr, bool autoDelete);
    virtual ~PyApDocument() override = default;
    PyAcEditor editor();
    PyDbDatabase database() const;
    std::string fileName() const;
    AcApDocument::SaveFormat formatForSave() const;

    AcAp::DocLockMode lockMode1() const;
    AcAp::DocLockMode lockMode2(bool bIncludeMyLocks) const;
    AcAp::DocLockMode myLockMode() const;
    bool    isQuiescent() const;

    std::string docTitle() const;
    void setDocTitle(const std::string& title);

    bool isReadOnly() const;

    int getCountOfLispList() const;
    boost::python::tuple getItemOfLispList(int nIndex) const;

    bool isCommandInputInactive() const;

    void              pushDbmod();
    Acad::ErrorStatus popDbmod();

    Acad::ErrorStatus upgradeDocOpen();
    Acad::ErrorStatus downgradeDocOpen(bool bPromptForSave);

    static std::string className();
public:
    AcApDocument* impObj(const std::source_location& src = std::source_location::current()) const;
};

