#pragma once
#pragma pack (push, 8)

//always starts with RTLB, strip it if you don't need it
resbuf* listToResbuf(const boost::python::object& bpl);
boost::python::list resbufToList(resbuf* pRb);

resbuf* AcGePoint3dArrayToResbuf(const AcGePoint3dArray& ptArrayWCS);
#pragma pack (pop)
