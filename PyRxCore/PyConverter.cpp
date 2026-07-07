#include "stdafx.h"
#include "PyConverter.h"

AcGePoint3d PyListToAcGePoint3d(const boost::python::object& iterable)
{
    PyAutoLockGIL lock;
    const size_t size = boost::python::len(iterable);
    if (size >= 3)
    {
        return AcGePoint3d(
            boost::python::extract<double>(iterable[0]),
            boost::python::extract<double>(iterable[1]),
            boost::python::extract<double>(iterable[2])
        );
    }
    else if (size == 2)
    {
        return AcGePoint3d(
            boost::python::extract<double>(iterable[0]),
            boost::python::extract<double>(iterable[1]),
            0.0
        );
    }
    throw PyErrorStatusException(eInvalidInput);
}

AcGePoint2d PyListToAcGePoint2d(const boost::python::object& iterable)
{
    PyAutoLockGIL lock;
    if (boost::python::len(iterable) < 2) [[unlikely]]
        throw PyErrorStatusException(eInvalidInput);
    return AcGePoint2d(
        boost::python::extract<double>(iterable[0]),
        boost::python::extract<double>(iterable[1])
    );
}

AcGeVector3d PyListToAcGeVector3d(const boost::python::object& iterable)
{
    PyAutoLockGIL lock;
    const size_t size = boost::python::len(iterable);
    if (size >= 3)
    {
        return AcGeVector3d(
            boost::python::extract<double>(iterable[0]),
            boost::python::extract<double>(iterable[1]),
            boost::python::extract<double>(iterable[2])
        );
    }
    else if (size == 2)
    {
        return AcGeVector3d(
            boost::python::extract<double>(iterable[0]),
            boost::python::extract<double>(iterable[1]),
            0.0
        );
    }
    throw PyErrorStatusException(eInvalidInput);
}

AcGeVector2d PyListToAcGeVector2d(const boost::python::object& iterable)
{
    PyAutoLockGIL lock;
    if (boost::python::len(iterable) < 2) [[unlikely]]
        throw PyErrorStatusException(eInvalidInput);
    return AcGeVector2d(
        boost::python::extract<double>(iterable),
        boost::python::extract<double>(iterable)
    );
}

boost::python::list IntArrayToPyList(const AcDbIntArray& arr)
{
    PyAutoLockGIL lock;
    boost::python::list pyPyList;
    for (auto item : arr)
        pyPyList.append(item);
    return pyPyList;
}

boost::python::list Int32ArrayToPyList(const AcArray<Adesk::Int32>& arr)
{
    PyAutoLockGIL lock;
    boost::python::list pyPyList;
    for (auto item : arr)
        pyPyList.append(item);
    return pyPyList;
}

boost::python::list IntU64ArrayToPyList(const AcArray<Adesk::UInt64>& arr)
{
    PyAutoLockGIL lock;
    boost::python::list pyPyList;
    for (auto item : arr)
        pyPyList.append(item);
    return pyPyList;
}

boost::python::list DoubleArrayToPyList(const AcGeDoubleArray& arr)
{
    PyAutoLockGIL lock;
    boost::python::list pyPyList;
    for (auto item : arr)
        pyPyList.append(item);
    return pyPyList;
}

boost::python::list Point3dArrayToPyList(const std::vector<AcGePoint3d>& arr)
{
    PyAutoLockGIL lock;
    boost::python::list pyPyList;
    for (const auto& item : arr)
        pyPyList.append(item);
    return pyPyList;
}

boost::python::list Point3dArrayToPyList(const AcGePoint3dArray& arr)
{
    PyAutoLockGIL lock;
    boost::python::list pyPyList;
    for (const auto& item : arr)
        pyPyList.append(item);
    return pyPyList;
}

boost::python::list Vector3dArrayToPyList(const AcGeVector3dArray& arr)
{
    PyAutoLockGIL lock;
    boost::python::list pyPyList;
    for (const auto& item : arr)
        pyPyList.append(item);
    return pyPyList;
}

boost::python::list Vector3dArrayToPyList(const std::vector<AcGeVector3d>& arr)
{
    PyAutoLockGIL lock;
    boost::python::list pyPyList;
    for (const auto& item : arr)
        pyPyList.append(item);
    return pyPyList;
}

boost::python::list Point2dArrayToPyList(const AcGePoint2dArray& arr)
{
    PyAutoLockGIL lock;
    boost::python::list pyPyList;
    for (const auto& item : arr)
        pyPyList.append(item);
    return pyPyList;
}

boost::python::list Point2dArrayToPyList(const std::vector<AcGePoint2d>& arr)
{
    PyAutoLockGIL lock;
    boost::python::list pyPyList;
    for (const auto& item : arr)
        pyPyList.append(item);
    return pyPyList;
}

boost::python::list AcStringArrayToPyList(const AcStringArray& arr)
{
    PyAutoLockGIL lock;
    boost::python::list pyPyList;
    for (const auto& item : arr)
        pyPyList.append(wstr_to_utf8(item).c_str());
    return pyPyList;
}

AcGeDoubleArray PyListToDoubleArray(const boost::python::object& iterable)
{
    using Iter = boost::python::stl_input_iterator<double>;
    PyAutoLockGIL lock;
    AcGeDoubleArray arr;
    int length = boost::python::len(iterable);
    arr.setPhysicalLength(length);
    for (Iter it(iterable), end; it != end; ++it) {
        arr.append(*it);
    }
    return arr;
}

AcGePoint2dArray PyListToPoint2dArray(const boost::python::object& iterable)
{
    using Iter = boost::python::stl_input_iterator<AcGePoint2d>;
    PyAutoLockGIL lock;
    AcGePoint2dArray arr;
    int length = boost::python::len(iterable);
    arr.setPhysicalLength(length);
    for (Iter it(iterable), end; it != end; ++it) {
        arr.append(*it);
    }
    return arr;
}

AcGePoint3dArray PyListToPoint3dArray(const boost::python::object& iterable)
{
    using Iter = boost::python::stl_input_iterator<AcGePoint3d>;
    PyAutoLockGIL lock;
    AcGePoint3dArray arr;
    int length = boost::python::len(iterable);
    arr.setPhysicalLength(length);
    for (Iter it(iterable), end; it != end; ++it) {
        arr.append(*it);
    }
    return arr;
}

AcGeVector3dArray PyListToVector3dArray(const boost::python::object& iterable)
{
    using Iter = boost::python::stl_input_iterator<AcGeVector3d>;
    PyAutoLockGIL lock;
    AcGeVector3dArray arr;
    int length = boost::python::len(iterable);
    arr.setPhysicalLength(length);
    for (Iter it(iterable), end; it != end; ++it) {
        arr.append(*it);
    }
    return arr;
}

AcGeVector2dArray PyListToVector2dArray(const boost::python::object& iterable)
{
    using Iter = boost::python::stl_input_iterator<AcGeVector2d>;
    PyAutoLockGIL lock;
    AcGeVector2dArray arr;
    int length = boost::python::len(iterable);
    arr.setPhysicalLength(length);
    for (Iter it(iterable), end; it != end; ++it) {
        arr.append(*it);
    }
    return arr;
}

AcArray<int> PyListToIntArray(const boost::python::object& iterable)
{
    using Iter = boost::python::stl_input_iterator<int>;
    PyAutoLockGIL lock;
    AcArray<int> arr;
    int length = boost::python::len(iterable);
    arr.setPhysicalLength(length);
    for (Iter it(iterable), end; it != end; ++it) {
        arr.append(*it);
    }
    return arr;
}

AcArray<Adesk::Int32> PyListToInt32Array(const boost::python::object& iterable)
{
    using Iter = boost::python::stl_input_iterator<Adesk::Int32>;
    PyAutoLockGIL lock;
    AcArray<Adesk::Int32> arr;
    int length = boost::python::len(iterable);
    arr.setPhysicalLength(length);
    for (Iter it(iterable), end; it != end; ++it) {
        arr.append(*it);
    }
    return arr;
}

AcArray<Adesk::UInt64> PyListToUInt64Array(const boost::python::object& iterable)
{
    using Iter = boost::python::stl_input_iterator<Adesk::UInt64>;
    PyAutoLockGIL lock;
    AcArray<Adesk::UInt64> arr;
    int length = boost::python::len(iterable);
    arr.setPhysicalLength(length);
    for (Iter it(iterable), end; it != end; ++it) {
        arr.append(*it);
    }
    return arr;
}

AcStringArray PyListToAcStringArray(const boost::python::object& iterable)
{
    using Iter = boost::python::stl_input_iterator<std::string>;
    PyAutoLockGIL lock;
    AcStringArray arr;
    int length = boost::python::len(iterable);
    arr.setPhysicalLength(length);
    for (Iter it(iterable), end; it != end; ++it) {
        arr.append(utf8_to_wstr(*it).c_str());
    }
    return arr;
}

COLORREF PyTupleToColorRef(const boost::python::tuple& val)
{
    namespace py = boost::python;
    if (py::len(val) == 3)
    {
        const Adesk::Int32 r = py::extract<Adesk::Int32>(val[0]);
        const Adesk::Int32 g = py::extract<Adesk::Int32>(val[1]);
        const Adesk::Int32 b = py::extract<Adesk::Int32>(val[2]);
        return RGB(r, g, b);
    }
    return 0;
}

boost::python::tuple ColorRefToPyTuple(COLORREF val)
{
    PyAutoLockGIL lock;
    return boost::python::make_tuple(GetRValue(val), GetGValue(val), GetBValue(val));
}
