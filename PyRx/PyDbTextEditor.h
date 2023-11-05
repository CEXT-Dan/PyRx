#pragma once
#include "dbtexteditor.h"


//-----------------------------------------------------------------------------------------
//PyDbTextEditorLocation
void makePyDbTextEditorLocationWrapper();

class PyDbTextEditorLocation
{
public:
    PyDbTextEditorLocation(AcDbTextEditorLocation* ptr);
    static std::string className();
    inline AcDbTextEditorLocation* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<AcDbTextEditorLocation> m_pyImp;
};

//-----------------------------------------------------------------------------------------
//PyDbTextEditorSelectable
void makePyDbTextEditorSelectableWrapper();
class PyDbTextEditorSelectable
{
private:
    PyDbTextEditorSelectable() = default;
public:
    virtual ~PyDbTextEditorSelectable() = default;
    PyDbTextEditorLocation startOfText();
    PyDbTextEditorLocation endOfText();
public:
    static std::string  className();
public:
    inline AcDbTextEditorSelectable* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<AcDbTextEditorSelectable> m_pyImp;
};

//-----------------------------------------------------------------------------------------
//PyDbTextEditorSelectionBase
void makePyDbTextEditorSelectionBaseWrapper();

class PyDbTextEditorSelectionBase
{
public:
    PyDbTextEditorSelectionBase(AcDbTextEditorSelectionBase* ptr);
    static std::string className();
    inline AcDbTextEditorSelectionBase* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    AcDbTextEditorSelectionBase* m_pyImp = nullptr;
};

//-----------------------------------------------------------------------------------------
//PyDbTextEditorSelection
void makePyDbTextEditorSelectionWrapper();
class PyDbTextEditorSelection : public PyDbTextEditorSelectionBase
{
public:
    PyDbTextEditorSelection(AcDbTextEditorSelection* ptr);
    static std::string className();
    inline AcDbTextEditorSelection* impObj(const std::source_location& src = std::source_location::current()) const;
};


//-----------------------------------------------------------------------------------------
//PyDbTextEditorCursor
void makePyDbTextEditorCursorWrapper();
class PyDbTextEditorCursor : public PyDbTextEditorSelectionBase
{
public:
    PyDbTextEditorCursor(AcDbTextEditorCursor* ptr);
    static std::string className();
    inline AcDbTextEditorCursor* impObj(const std::source_location& src = std::source_location::current()) const;
};
