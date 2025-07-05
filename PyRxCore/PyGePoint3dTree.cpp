#include "stdafx.h"
#include "PyGePoint3dTree.h"
#include "nanoflann.hpp"

using namespace boost::python;

typedef std::vector<AcGePoint3d> PyGePoint3dArray;

//-----------------------------------------------------------------------------------------
//PyGePoint3dTreeAdapter
struct PyGePoint3dTreeAdapter
{
    PyGePoint3dTreeAdapter(const PyGePoint3dArray& points);
    ~PyGePoint3dTreeAdapter() = default;

    size_t kdtree_get_point_count() const;
    double kdtree_get_pt(const size_t idx, const size_t dim) const;

    template <class BBOX>
    inline bool kdtree_get_bbox(BBOX&) const
    {
        return false;
    }

    PyGePoint3dArray mpoints;
};

//-----------------------------------------------------------------------------------------
//PyGePoint3dTree
class PyGePoint3dTree
{
    using kd_tree3d_t = nanoflann::KDTreeSingleIndexAdaptor<
        nanoflann::L2_Simple_Adaptor<double, PyGePoint3dTreeAdapter>, PyGePoint3dTreeAdapter, 3>;

public:
    PyGePoint3dTree(const PyGePoint3dArray& points);
    PyGePoint3dTree(const  boost::python::list& points);
    ~PyGePoint3dTree() = default;

    boost::python::tuple radiusSearch(const AcGePoint3d& point, double radius) const;
    boost::python::tuple knnSearch(const AcGePoint3d& point, int num_closest) const;
    static std::string   className();

    PyGePoint3dTreeAdapter adapter;
    std::shared_ptr< kd_tree3d_t> pTree;
};


PyGePoint3dTreeAdapter::PyGePoint3dTreeAdapter(const PyGePoint3dArray& points)
    : mpoints(points)
{
}

size_t PyGePoint3dTreeAdapter::kdtree_get_point_count() const
{
    return mpoints.size();
}

double PyGePoint3dTreeAdapter::kdtree_get_pt(const size_t idx, const size_t dim) const
{
    switch (dim)
    {
        case 0:
            return mpoints.at(idx).x;
        case 1:
            return mpoints.at(idx).y;
        default:
            return mpoints.at(idx).z;
    }
}

//-----------------------------------------------------------------------------------------
//PyGePoint3dTree wrapper
void makePyGePoint3dTreeWrapper()
{
    PyDocString DS("Point3dTree");
    class_<PyGePoint3dTree>("Point3dTree", boost::python::no_init)
        .def(init<PyGePoint3dArray&>())
        .def(init<boost::python::list&>(DS.ARGS({ "points : Collection[PyGe.Point3d]" })))
        .def("radiusSearch", &PyGePoint3dTree::radiusSearch, DS.ARGS({ "point: PyGe.Point3d", "radius: float" }))
        .def("knnSearch", &PyGePoint3dTree::knnSearch, DS.ARGS({ "point: PyGe.Point3d", "num_closest: int" }))
        .def("className", &PyGePoint3dTree::className, DS.SARGS()).staticmethod("className")
        ;
}

PyGePoint3dTree::PyGePoint3dTree(const PyGePoint3dArray& points)
    : adapter(points)
{
    pTree.reset(new kd_tree3d_t(3, adapter, { 10 }));
    pTree->buildIndex();
}

PyGePoint3dTree::PyGePoint3dTree(const boost::python::list& points)
    : adapter(py_list_to_std_vector<AcGePoint3d>(points))
{
    pTree.reset(new kd_tree3d_t(3, adapter, { 10 }));
    pTree->buildIndex();
}

boost::python::tuple PyGePoint3dTree::radiusSearch(const AcGePoint3d& point, double radius) const
{
    PyAutoLockGIL lock;
    nanoflann::SearchParameters params;
    std::vector<nanoflann::ResultItem<uint32_t, double>> ret_matches;
    const size_t num_matches = pTree->radiusSearch(asDblArray(point), radius, ret_matches, params);

    boost::python::list inds, dists;
    for (size_t idx = 0; idx < num_matches; idx++)
    {
        inds.append(ret_matches.at(idx).first);
        dists.append(ret_matches.at(idx).second);
    }
    return boost::python::make_tuple(inds, dists);
}

boost::python::tuple PyGePoint3dTree::knnSearch(const AcGePoint3d& point, int num_closest) const
{
    PyAutoLockGIL lock;
    std::vector<uint32_t> ret_index(num_closest);
    std::vector<double> out_dist_sqr(num_closest);
    const size_t num_matches = pTree->knnSearch(asDblArray(point), num_closest, &ret_index[0], &out_dist_sqr[0]);

    boost::python::list inds, dists;
    for (size_t idx = 0; idx < num_matches; idx++)
    {
        inds.append(ret_index.at(idx));
        dists.append(out_dist_sqr.at(idx));
    }
    return boost::python::make_tuple(inds, dists);
}

std::string PyGePoint3dTree::className()
{
    return "Point3dTree";
}
