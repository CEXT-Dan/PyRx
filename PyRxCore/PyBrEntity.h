#pragma once

#include "PyDbEntity.h"
#pragma pack (push, 8)

class PyGeBoundBlock3d;
class PyGeLinearEnt3d;


//-----------------------------------------------------------------------------------------
//PyBrEntity
void makePyBrEntityWrapper();

class PyBrEntity : public PyRxObject
{
public:
    PyBrEntity(const AcRxObject* ptr);
    PyBrEntity(AcRxObject* ptr, bool autoDelete);
    inline virtual ~PyBrEntity() = default;

    Adesk::Boolean              isEqualTo(const PyRxObject& other) const;
    Adesk::Boolean              isNull() const;

    PyDbFullSubentPath          getSubentPath() const;
    void                        setSubentPath(PyDbFullSubentPath& subpath);

    Adesk::Boolean		        checkEntity() const;
    PyGeBoundBlock3d            getBoundBlock() const;

    boost::python::tuple        getPointContainment(const AcGePoint3d& point);
    boost::python::tuple        getLineContainment(const PyGeLinearEnt3d& line, const Adesk::UInt32 numHitsWanted);

    //AcBr::ErrorStatus   getBrep(AcBrBrep& brep) const;

    void	                    setValidationLevel(const AcBr::ValidationLevel level);
    AcBr::ValidationLevel	    getValidationLevel() const;

    Adesk::Boolean		        brepChanged() const;

    //AcBr::ErrorStatus	getMassProps(AcBrMassProps& massProps,
    //    const double& density = *(double*)NULL,
    //    const double& tolRequired = *(double*)NULL,
    //    double& tolAchieved = *(double*)NULL) const;
    //AcBr::ErrorStatus	getVolume(double& volume,
    //    const double& tolRequired = *(double*)NULL,
    //    double& tolAchieved = *(double*)NULL) const;
    //AcBr::ErrorStatus	getSurfaceArea(double& area,
    //    const double& tolRequired = *(double*)NULL,
    //    double& tolAchieved = *(double*)NULL) const;
    //AcBr::ErrorStatus	getPerimeterLength(double& length,
    //    const double& tolRequired = *(double*)NULL,
    //    double& tolAchieved = *(double*)NULL) const;


    static PyRxClass            desc();
    static std::string          className();
public:
    inline AcBrEntity* impObj(const std::source_location& src = std::source_location::current()) const;
};


#pragma pack (pop)