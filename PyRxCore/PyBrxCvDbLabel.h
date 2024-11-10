#pragma once

#ifdef BRXAPP
#include "PyBrxCvObject.h"
#include "PyDbDate.h"

#include "BrxCvDbStylePartDisplaySettings.h" 
#include "BrxCvDbStyle.h"
#include "BrxCvDbLabelStyle.h"

class PyDbObjectId;
//class PyBrxCvDbStyle;

//-----------------------------------------------------------------------------------
//PyBrxCvDbStyle
void makePyBrxCvDbStyleWrapper();

class PyBrxCvDbStyle : public PyBrxCvDbObject
{
    using DisplayOrientation = BrxCvDbStyle::DisplayOrientation;
    using ScalingType = BrxCvDbStyle::ScalingType;
    using OrientationRef = BrxCvDbStyle::OrientationRef;
public:
    PyBrxCvDbStyle(const PyDbObjectId& id);
    PyBrxCvDbStyle(BrxCvDbStyle* ptr, bool autoDelete);
    PyBrxCvDbStyle(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyBrxCvDbStyle(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    virtual ~PyBrxCvDbStyle() override = default;

    BrxCvDbStylePartDisplaySettingsPtr displaySetting(DisplayOrientation orientation, const AcString& partName) const;
    boost::python::list displaySettings(BrxCvDbLabelStyle::DisplayOrientation orientation) const;

    PyDbDate            createdDate() const;
    const std::string   createdBy() const;

    PyDbDate            lastEditedDate() const;
    const std::string   lastEditedBy() const;

    void                setCreatedBy(const AcString& value);

public:
    inline BrxCvDbStyle* impObj(const std::source_location& src = std::source_location::current()) const;
};

#endif//BRXAPP
