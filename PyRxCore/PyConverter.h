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

//-------------------------------------------------------------------------------------
// py_list_to_std_vector / std_vector_to_py_list
template<typename T>
inline std::vector< T > py_list_to_std_vector(const boost::python::object& iterable)
{
    PyAutoLockGIL lock;
    std::vector< T > result;

    if (PySequence_Check(iterable.ptr())) {
        Py_ssize_t size = PySequence_Size(iterable.ptr());
        if (size > 0) {
            result.reserve(static_cast<size_t>(size));
        }
    }
    result.assign(boost::python::stl_input_iterator< T >(iterable),
        boost::python::stl_input_iterator< T >());
    return result;
}

template <class T>
inline boost::python::list std_vector_to_py_list(std::vector<T> vector)
{
    PyAutoLockGIL lock;
    boost::python::list list;
    typename std::vector<T>::iterator iter;
    for (iter = vector.begin(); iter != vector.end(); ++iter)
        list.append(*iter);
    return list;
}

#pragma pack (pop)
