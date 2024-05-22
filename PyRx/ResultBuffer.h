#pragma once
#pragma pack (push, 8)

//allways starts with RTLB, strip it if you dont need it
resbuf* listToResbuf(const boost::python::list& bpl);
boost::python::list resbufToList(resbuf* pRb);

resbuf* acGePoint3dArrayToResbuf(const AcGePoint3dArray& ptArrayWCS);
#pragma pack (pop)
