#pragma once


//allways starts with RTLB, strip it if you dont need it
resbuf* listToResbuf(const boost::python::list& bpl);
boost::python::list resbufToList(resbuf* pRb);

resbuf* acGePoint3dArrayToResbuf(const AcGePoint3dArray& ptArrayWCS);