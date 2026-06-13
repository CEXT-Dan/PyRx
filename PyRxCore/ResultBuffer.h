#pragma once
#pragma pack (push, 8)


boost::python::list resbufToList(const resbuf* pRb);

//none of these have RTLB RTLE
resbuf* listToResbuf(const boost::python::object& bpl);
resbuf* AcGePoint3dArrayToResbuf(const AcGePoint3dArray& ptArrayWCS);
resbuf* PyGePoint3dArrayToResbuf(const PyGePoint3dArray& ptArrayWCS);
resbuf* PyDbObjectIdArrayToResbuf(const PyDbObjectIdArray& vec);
#pragma pack (pop)
