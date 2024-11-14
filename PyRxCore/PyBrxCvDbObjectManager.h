#pragma once

#ifdef BRXAPP
#include "PyBrxCvObject.h"
#include "BrxCvDbObjectManager.h"
#include "BrxCvDbFileFormatManager.h"
#include "BrxCvDbStyleManager.h"
#include "BrxCvDbPointGroupManager.h"
class PyDbObjectId;

//-----------------------------------------------------------------------------------
//PyBrxCvDbObjectManager
void makePyBrxCvDbObjectManagerWrapper();

class PyBrxCvDbObjectManager : public PyBrxCvDbObject
{
public:
    PyBrxCvDbObjectManager(const PyDbObjectId& id);
    PyBrxCvDbObjectManager(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyBrxCvDbObjectManager(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyBrxCvDbObjectManager(BrxCvDbObjectManager* ptr, bool autoDelete);
    virtual ~PyBrxCvDbObjectManager() override = default;

    Adesk::UInt32       elementCount();
    boost::python::list ids();
    boost::python::list names();
    PyDbObjectId        idAt1(const Adesk::UInt32 index);
    PyDbObjectId        idAt2(const std::string& szName);
    std::string         nameAt(const Adesk::UInt32 index);
    bool                has1(const PyDbObjectId& id);
    bool                has2(const  std::string& szName);
    bool                remove1(const PyDbObjectId& id);
    bool                remove2(const std::string& szName);

    static std::string          className();
    static PyRxClass            desc();
    static PyBrxCvDbObjectManager      cloneFrom(const PyRxObject& src);
    static PyBrxCvDbObjectManager      cast(const PyRxObject& src);

public:
    inline BrxCvDbObjectManager* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
// PyBrxCvDbFileFormatManager
void makePyBrxCvDbFileFormatManagerWrapper();

class PyBrxCvDbFileFormatManager : public PyBrxCvDbObjectManager
{
public:
    PyBrxCvDbFileFormatManager(const PyDbObjectId& id);
    PyBrxCvDbFileFormatManager(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyBrxCvDbFileFormatManager(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyBrxCvDbFileFormatManager(BrxCvDbFileFormatManager* ptr, bool autoDelete);
    virtual ~PyBrxCvDbFileFormatManager() override = default;

    boost::python::list                 applicableFileFormats(const std::string& fileName);
    boost::python::list                 allFileFormats();

    static PyDbObjectId                 getManager(PyDbDatabase& db);
    static PyBrxCvDbFileFormatManager   openManager(PyDbDatabase& db, AcDb::OpenMode mode);

    static std::string                  className();
    static PyRxClass                    desc();
    static PyBrxCvDbFileFormatManager   cloneFrom(const PyRxObject& src);
    static PyBrxCvDbFileFormatManager   cast(const PyRxObject& src);

public:
    inline BrxCvDbFileFormatManager* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
// PyBrxCvDbStyleManager
void makePyBrxCvDbStyleManagerWrapper();

class PyBrxCvDbStyleManager : public PyBrxCvDbObjectManager
{
public:
    enum EStyleManagerType
    {
        eSymbolStyle,
        eLineLabel,
        eCurveLabel,
        ePointLabel,
        eContourLabel,
        eSurfaceSlopeLabel,
        eSurfaceElevationLabel,
    };

public:
    PyBrxCvDbStyleManager(const PyDbObjectId& id);
    PyBrxCvDbStyleManager(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyBrxCvDbStyleManager(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyBrxCvDbStyleManager(BrxCvDbStyleManager* ptr, bool autoDelete);
    virtual ~PyBrxCvDbStyleManager() override = default;

    static PyDbObjectId                 getManager(PyDbDatabase& db, EStyleManagerType styleType);
    static PyBrxCvDbObjectManager       openManager(PyDbDatabase& db, AcDb::OpenMode mode, EStyleManagerType styleType);

    static std::string                  className();
    static PyRxClass                    desc();
    static PyBrxCvDbStyleManager        cloneFrom(const PyRxObject& src);
    static PyBrxCvDbStyleManager        cast(const PyRxObject& src);

public:
    inline BrxCvDbStyleManager* impObj(const std::source_location& src = std::source_location::current()) const;
};


//-----------------------------------------------------------------------------------
// PyBrxCvDbPointGroupManager
void makePyBrxCvDbPointGroupManagerWrapper();

class PyBrxCvDbPointGroupManager : public PyBrxCvDbObjectManager
{
public:
    PyBrxCvDbPointGroupManager(const PyDbObjectId& id);
    PyBrxCvDbPointGroupManager(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyBrxCvDbPointGroupManager(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyBrxCvDbPointGroupManager(BrxCvDbPointGroupManager* ptr, bool autoDelete);
    virtual ~PyBrxCvDbPointGroupManager() override = default;

    PyDbObjectId                        createPointGroup(const std::string& szName);
    boost::python::list                 groupsWithPoint(Adesk::UInt32 number) const;
    Adesk::UInt32                       updatePointGroups();

    Adesk::UInt32                       nextPointNumber() const;
    bool                                setNextPointNumber(Adesk::UInt32 number);

    static PyDbObjectId                 getManagerId(PyDbDatabase& db);
    static PyBrxCvDbPointGroupManager   openManager(PyDbDatabase& db, AcDb::OpenMode mode);

    static std::string                  className();
    static PyRxClass                    desc();
    static PyBrxCvDbPointGroupManager   cloneFrom(const PyRxObject& src);
    static PyBrxCvDbPointGroupManager   cast(const PyRxObject& src);

public:
    inline BrxCvDbPointGroupManager* impObj(const std::source_location& src = std::source_location::current()) const;
};

#if !defined(_BRXTARGET240)
//-----------------------------------------------------------------------------------
// PyBrxCvDbSymbolStyleManager
void makePyBrxCvDbSymbolStyleManagerWrapper();

class PyBrxCvDbSymbolStyleManager : public PyBrxCvDbStyleManager
{
public:
    PyBrxCvDbSymbolStyleManager(const PyDbObjectId& id);
    PyBrxCvDbSymbolStyleManager(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyBrxCvDbSymbolStyleManager(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyBrxCvDbSymbolStyleManager(BrxCvDbSymbolStyleManager* ptr, bool autoDelete);
    virtual ~PyBrxCvDbSymbolStyleManager() override = default;
    PyDbObjectId                         createSymbolStyle(const std::string& szName);

    static std::string                   managerId();
    static PyDbObjectId                  getManagerId(PyDbDatabase& db);
    static PyBrxCvDbSymbolStyleManager   openManager(PyDbDatabase& db, AcDb::OpenMode mode);
    static std::string                   className();
    static PyRxClass                     desc();
    static PyBrxCvDbSymbolStyleManager   cloneFrom(const PyRxObject& src);
    static PyBrxCvDbSymbolStyleManager   cast(const PyRxObject& src);

public:
    inline BrxCvDbSymbolStyleManager* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
// PyBrxCvDbLineLabelStyleManager
void makePyBrxCvDbLineLabelStyleManagerWrapper();

class PyBrxCvDbLineLabelStyleManager : public PyBrxCvDbStyleManager
{
public:
    PyBrxCvDbLineLabelStyleManager(const PyDbObjectId& id);
    PyBrxCvDbLineLabelStyleManager(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyBrxCvDbLineLabelStyleManager(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyBrxCvDbLineLabelStyleManager(BrxCvDbLineLabelStyleManager* ptr, bool autoDelete);
    virtual ~PyBrxCvDbLineLabelStyleManager() override = default;
    PyDbObjectId                         createLabelStyle(const std::string& szName);

    static std::string                   managerId();
    static PyDbObjectId                  getManagerId(PyDbDatabase& db);
    static PyBrxCvDbLineLabelStyleManager   openManager(PyDbDatabase& db, AcDb::OpenMode mode);
    static std::string                   className();
    static PyRxClass                     desc();
    static PyBrxCvDbLineLabelStyleManager   cloneFrom(const PyRxObject& src);
    static PyBrxCvDbLineLabelStyleManager   cast(const PyRxObject& src);

public:
    inline BrxCvDbLineLabelStyleManager* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
// PyBrxCvDbCurveLabelStyleManager
void makePyBrxCvDbCurveLabelStyleManagerWrapper();

class PyBrxCvDbCurveLabelStyleManager : public PyBrxCvDbStyleManager
{
public:
    PyBrxCvDbCurveLabelStyleManager(const PyDbObjectId& id);
    PyBrxCvDbCurveLabelStyleManager(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyBrxCvDbCurveLabelStyleManager(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyBrxCvDbCurveLabelStyleManager(BrxCvDbCurveLabelStyleManager* ptr, bool autoDelete);
    virtual ~PyBrxCvDbCurveLabelStyleManager() override = default;
    PyDbObjectId                         createLabelStyle(const std::string& szName);

    static std::string                   managerId();
    static PyDbObjectId                  getManagerId(PyDbDatabase& db);
    static PyBrxCvDbCurveLabelStyleManager   openManager(PyDbDatabase& db, AcDb::OpenMode mode);
    static std::string                   className();
    static PyRxClass                     desc();
    static PyBrxCvDbCurveLabelStyleManager   cloneFrom(const PyRxObject& src);
    static PyBrxCvDbCurveLabelStyleManager   cast(const PyRxObject& src);

public:
    inline BrxCvDbCurveLabelStyleManager* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
// PyBrxCvDbPointLabelStyleManager
void makePyBrxCvDbPointLabelStyleManagerWrapper();

class PyBrxCvDbPointLabelStyleManager : public PyBrxCvDbStyleManager
{
public:
    PyBrxCvDbPointLabelStyleManager(const PyDbObjectId& id);
    PyBrxCvDbPointLabelStyleManager(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyBrxCvDbPointLabelStyleManager(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyBrxCvDbPointLabelStyleManager(BrxCvDbPointLabelStyleManager* ptr, bool autoDelete);
    virtual ~PyBrxCvDbPointLabelStyleManager() override = default;
    PyDbObjectId                         createLabelStyle(const std::string& szName);

    static std::string                   managerId();
    static PyDbObjectId                  getManagerId(PyDbDatabase& db);
    static PyBrxCvDbPointLabelStyleManager   openManager(PyDbDatabase& db, AcDb::OpenMode mode);
    static std::string                   className();
    static PyRxClass                     desc();
    static PyBrxCvDbPointLabelStyleManager   cloneFrom(const PyRxObject& src);
    static PyBrxCvDbPointLabelStyleManager   cast(const PyRxObject& src);

public:
    inline BrxCvDbPointLabelStyleManager* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
// PyBrxCvDbSurfaceContourLabelStyleManager
void makePyBrxCvDbSurfaceContourLabelStyleManagerWrapper();

class PyBrxCvDbSurfaceContourLabelStyleManager : public PyBrxCvDbStyleManager
{
public:
    PyBrxCvDbSurfaceContourLabelStyleManager(const PyDbObjectId& id);
    PyBrxCvDbSurfaceContourLabelStyleManager(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyBrxCvDbSurfaceContourLabelStyleManager(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyBrxCvDbSurfaceContourLabelStyleManager(BrxCvDbSurfaceContourLabelStyleManager* ptr, bool autoDelete);
    virtual ~PyBrxCvDbSurfaceContourLabelStyleManager() override = default;
    PyDbObjectId                         createLabelStyle(const std::string& szName);

    static std::string                   managerId();
    static PyDbObjectId                  getManagerId(PyDbDatabase& db);
    static PyBrxCvDbSurfaceContourLabelStyleManager   openManager(PyDbDatabase& db, AcDb::OpenMode mode);
    static std::string                   className();
    static PyRxClass                     desc();
    static PyBrxCvDbSurfaceContourLabelStyleManager   cloneFrom(const PyRxObject& src);
    static PyBrxCvDbSurfaceContourLabelStyleManager   cast(const PyRxObject& src);

public:
    inline BrxCvDbSurfaceContourLabelStyleManager* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
// PyBrxCvDbSurfaceSlopeLabelStyleManager
void makePyBrxCvDbSurfaceSlopeLabelStyleManagerWrapper();

class PyBrxCvDbSurfaceSlopeLabelStyleManager : public PyBrxCvDbStyleManager
{
public:
    PyBrxCvDbSurfaceSlopeLabelStyleManager(const PyDbObjectId& id);
    PyBrxCvDbSurfaceSlopeLabelStyleManager(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyBrxCvDbSurfaceSlopeLabelStyleManager(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyBrxCvDbSurfaceSlopeLabelStyleManager(BrxCvDbSurfaceSlopeLabelStyleManager* ptr, bool autoDelete);
    virtual ~PyBrxCvDbSurfaceSlopeLabelStyleManager() override = default;
    PyDbObjectId                         createLabelStyle(const std::string& szName);

    static std::string                   managerId();
    static PyDbObjectId                  getManagerId(PyDbDatabase& db);
    static PyBrxCvDbSurfaceSlopeLabelStyleManager   openManager(PyDbDatabase& db, AcDb::OpenMode mode);
    static std::string                   className();
    static PyRxClass                     desc();
    static PyBrxCvDbSurfaceSlopeLabelStyleManager   cloneFrom(const PyRxObject& src);
    static PyBrxCvDbSurfaceSlopeLabelStyleManager   cast(const PyRxObject& src);

public:
    inline BrxCvDbSurfaceSlopeLabelStyleManager* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
// PyBrxCvDbSurfaceElevationLabelStyleManager
void makePyBrxCvDbSurfaceElevationLabelStyleManagerWrapper();

class PyBrxCvDbSurfaceElevationLabelStyleManager : public PyBrxCvDbStyleManager
{
public:
    PyBrxCvDbSurfaceElevationLabelStyleManager(const PyDbObjectId& id);
    PyBrxCvDbSurfaceElevationLabelStyleManager(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyBrxCvDbSurfaceElevationLabelStyleManager(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyBrxCvDbSurfaceElevationLabelStyleManager(BrxCvDbSurfaceElevationLabelStyleManager* ptr, bool autoDelete);
    virtual ~PyBrxCvDbSurfaceElevationLabelStyleManager() override = default;
    PyDbObjectId                         createLabelStyle(const std::string& szName);

    static std::string                   managerId();
    static PyDbObjectId                  getManagerId(PyDbDatabase& db);
    static PyBrxCvDbSurfaceElevationLabelStyleManager   openManager(PyDbDatabase& db, AcDb::OpenMode mode);
    static std::string                   className();
    static PyRxClass                     desc();
    static PyBrxCvDbSurfaceElevationLabelStyleManager   cloneFrom(const PyRxObject& src);
    static PyBrxCvDbSurfaceElevationLabelStyleManager   cast(const PyRxObject& src);

public:
    inline BrxCvDbSurfaceElevationLabelStyleManager* impObj(const std::source_location& src = std::source_location::current()) const;
};

#endif

#endif//BRXAPP
