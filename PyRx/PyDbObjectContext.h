#pragma once
#include "PyRxObject.h"
#include "dbObjContext.h"

//-----------------------------------------------------------------------------------------
//PyDbObjectContext
void makePyDbObjectContextWrapper();

class PyDbObjectContext : public PyRxObject
{
public:;
      PyDbObjectContext(AcDbObjectContext* pt);
      virtual ~PyDbObjectContext() = default;
      std::string           getName() const;
      Acad::ErrorStatus     setName(std::string& name);
      Adesk::LongPtr        uniqueIdentifier() const;
      std::string           collectionName() const;
      static PyRxClass      desc();
      static std::string    className();
public:
    AcDbObjectContext* impObj(const std::source_location& src = std::source_location::current()) const;
};

