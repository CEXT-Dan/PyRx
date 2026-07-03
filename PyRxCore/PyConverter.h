#pragma once

#pragma pack (push, 8)

AcGePoint3d     PyListToAcGePoint3d(const boost::python::object& iterable);
AcGePoint2d     PyListToAcGePoint2d(const boost::python::object& iterable);
AcGeVector3d    PyListToAcGeVector3d(const boost::python::object& iterable);
AcGeVector2d    PyListToAcGeVector2d(const boost::python::object& iterable);

boost::python::list IntArrayToPyList(const AcDbIntArray& arr);
boost::python::list Int32ArrayToPyList(const AcArray<Adesk::Int32>& arr);
boost::python::list IntU64ArrayToPyList(const AcArray<Adesk::UInt64>& arr);
boost::python::list DoubleArrayToPyList(const AcGeDoubleArray& arr);
boost::python::list Point3dArrayToPyList(const std::vector<AcGePoint3d>& arr);
boost::python::list Point3dArrayToPyList(const AcGePoint3dArray& arr);
boost::python::list Vector3dArrayToPyList(const AcGeVector3dArray& arr);
boost::python::list Vector3dArrayToPyList(const std::vector<AcGeVector3d>& arr);
boost::python::list Point2dArrayToPyList(const AcGePoint2dArray& arr);
boost::python::list Point2dArrayToPyList(const std::vector<AcGePoint2d>& arr);
boost::python::list AcStringArrayToPyList(const AcStringArray& arr);

AcGeDoubleArray         PyListToDoubleArray(const boost::python::object& iterable);
AcGePoint2dArray        PyListToPoint2dArray(const boost::python::object& iterable);
AcGePoint3dArray        PyListToPoint3dArray(const boost::python::object& iterable);
AcGeVector3dArray       PyListToVector3dArray(const boost::python::object& iterable);
AcGeVector2dArray       PyListToVector2dArray(const boost::python::object& iterable);
AcArray<int>            PyListToIntArray(const boost::python::object& iterable);
AcArray<Adesk::Int32>   PyListToInt32Array(const boost::python::object& iterable);
AcArray<Adesk::UInt64>  PyListToUInt64Array(const boost::python::object& iterable);
AcStringArray           PyListToAcStringArray(const boost::python::object& iterable);
COLORREF                PyTupleToColorRef(const boost::python::tuple& val);
boost::python::tuple    ColorRefToPyTuple(COLORREF val);

#pragma pack (pop)
