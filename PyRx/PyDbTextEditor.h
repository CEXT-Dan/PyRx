#pragma once

#ifdef PYRX_IN_PROGRESS_INPLACE_TEXT_EDITOR
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

public:
    PyDbTextEditorSelectable(AcDbTextEditorSelectable* ptr);
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
    explicit PyDbTextEditorSelectionBase(AcDbTextEditorSelectionBase* ptr);
    virtual ~PyDbTextEditorSelectionBase() = default;
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
    explicit PyDbTextEditorSelection(AcDbTextEditorSelection* ptr);
    virtual ~PyDbTextEditorSelection() override = default;
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

//-----------------------------------------------------------------------------------------
//PyDbTextEditorParagraphTab
void makePyDbTextEditorParagraphTabWrapper();
class PyDbTextEditorParagraphTab
{
public:
    PyDbTextEditorParagraphTab();
    ~PyDbTextEditorParagraphTab() = default;

public:
    static std::string className();
    inline AcDbTextEditorParagraphTab* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<AcDbTextEditorParagraphTab> m_pyImp;
};

//-----------------------------------------------------------------------------------------
//PyDbTextEditorParagraph
void makePyDbTextEditorParagraphWrapper();
class PyDbTextEditorParagraph : public PyDbTextEditorSelectable
{
public:
    explicit PyDbTextEditorParagraph(AcDbTextEditorSelectable* ptr);
    virtual ~PyDbTextEditorParagraph() override = default;
    static std::string className();
    inline AcDbTextEditorParagraph* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//AcDbTextEditorColumn
void makePyDbTextEditorColumnWrapper();
class PyDbTextEditorColumn : public PyDbTextEditorSelectable
{
public:
    explicit PyDbTextEditorColumn(AcDbTextEditorColumn* ptr);
    virtual ~PyDbTextEditorColumn() override = default;
    static std::string className();
    inline AcDbTextEditorColumn* impObj(const std::source_location& src = std::source_location::current()) const;
};

#endif//PYRX_IN_PROGRESS_INPLACE_TEXT_EDITOR