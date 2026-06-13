#pragma once
#pragma pack (push, 8)

//always starts with RTLB, strip it if you don't need it
resbuf* listToResbuf(const boost::python::object& bpl);
boost::python::list resbufToList(const resbuf* pRb);

resbuf* AcGePoint3dArrayToResbuf(const AcGePoint3dArray& ptArrayWCS);
resbuf* PyGePoint3dArrayToResbuf(const PyGePoint3dArray& ptArrayWCS);
resbuf* PyDbObjectIdArrayToResbuf(const PyDbObjectIdArray& vec);
#pragma pack (pop)
