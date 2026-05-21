#include "stdafx.h"
#include "PyGePoint3dTree.h"
#include "nanoflann.hpp"
#include "delaunator.h"

#define USE_CDT_FEATRE

#ifdef USE_CDT_FEATRE
#include "CDT.h" 
#endif

using namespace boost::python;

constexpr int leafSize = 12;

//----------------------------------------------------------------------------------------
//PyGePoint2dTreeAdapter
struct PyGePoint2dTreeAdapter
{
    PyGePoint2dTreeAdapter(const PyGePoint2dArray& points);
    PyGePoint2dTreeAdapter(PyGePoint2dArray&& points);
    ~PyGePoint2dTreeAdapter() = default;
    size_t kdtree_get_point_count() const;
    double kdtree_get_pt(const size_t idx, const size_t dim) const;
    template <class BBOX>
    inline bool kdtree_get_bbox(BBOX&) const
    {
        return false;
    }
    PyGePoint2dArray mpoints;
};

//-----------------------------------------------------------------------------------------
//PyGePoint2dTree
class PyGePoint2dTree
{
    using kd_tree2d_t = nanoflann::KDTreeSingleIndexAdaptor<
        nanoflann::L2_Simple_Adaptor<double, PyGePoint2dTreeAdapter>, PyGePoint2dTreeAdapter, 2>;
public:
    PyGePoint2dTree(const PyGePoint2dArray& points);
    PyGePoint2dTree(const boost::python::list& points);
    ~PyGePoint2dTree() = default;
    void                 create();
    boost::python::tuple radiusSearch(const AcGePoint2d& point, double radius) const;
    boost::python::tuple knnSearch(const AcGePoint2d& point, int num_closest) const;
    PyGePoint2dArray     inputPoints() const;
    static std::string   className();
    //
    PyGePoint2dTreeAdapter adapter;
    std::shared_ptr<kd_tree2d_t> pTree;
};

//-----------------------------------------------------------------------------------------
//PyGePoint2dTreeAdapter
PyGePoint2dTreeAdapter::PyGePoint2dTreeAdapter(const PyGePoint2dArray& points)
    : mpoints(points)
{
}

PyGePoint2dTreeAdapter::PyGePoint2dTreeAdapter(PyGePoint2dArray&& points)
    : mpoints(std::move(points))
{
}

size_t PyGePoint2dTreeAdapter::kdtree_get_point_count() const
{
    return mpoints.size();
}

double PyGePoint2dTreeAdapter::kdtree_get_pt(const size_t idx, const size_t dim) const
{
    switch (dim)
    {
        case 0:
            return mpoints.at(idx).x;
        default:
            return mpoints.at(idx).y;
    }
}

//-----------------------------------------------------------------------------------------
//PyGePoint2dTree wrapper
void makePyGePoint2dTreeWrapper()
{
    PyDocString DS("Point2dTree");
    class_<PyGePoint2dTree>("Point2dTree", boost::python::no_init)
        .def(init<const PyGePoint2dArray&>())
        .def(init<const boost::python::list&>(DS.ARGS({ "points : Collection[PyGe.Point2d]" })))
        .def("radiusSearch", &PyGePoint2dTree::radiusSearch, DS.ARGS({ "point: PyGe.Point2d", "radius: float" }))
        .def("knnSearch", &PyGePoint2dTree::knnSearch, DS.ARGS({ "point: PyGe.Point2d", "num_closest: int" }))
        .def("inputPoints", &PyGePoint2dTree::inputPoints, DS.ARGS())
        .def("className", &PyGePoint2dTree::className, DS.SARGS()).staticmethod("className")
        ;
}

PyGePoint2dTree::PyGePoint2dTree(const PyGePoint2dArray& points)
    : adapter(points)
{
    create();
}

PyGePoint2dTree::PyGePoint2dTree(const boost::python::list& points)
    : adapter(std::move(py_list_to_std_vector<AcGePoint2d>(points)))
{
    create();
}

void PyGePoint2dTree::create()
{
    nanoflann::KDTreeSingleIndexAdaptorParams params;
    params.leaf_max_size = leafSize;
    params.n_thread_build = 0;
    pTree.reset(new kd_tree2d_t(2, adapter, params));
    pTree->buildIndex();
}

boost::python::tuple PyGePoint2dTree::radiusSearch(const AcGePoint2d& point, double radius) const
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

boost::python::tuple PyGePoint2dTree::knnSearch(const AcGePoint2d& point, int num_closest) const
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

PyGePoint2dArray PyGePoint2dTree::inputPoints() const
{
    return adapter.mpoints;
}

std::string PyGePoint2dTree::className()
{
    return "Point2dTree";
}

//----------------------------------------------------------------------------------------
//PyGePoint3dTreeAdapter
struct PyGePoint3dTreeAdapter
{
    PyGePoint3dTreeAdapter(const PyGePoint3dArray& points);
    PyGePoint3dTreeAdapter(PyGePoint3dArray&& points);
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
    PyGePoint3dTree(const boost::python::list& points);
    ~PyGePoint3dTree() = default;
    void                 create();
    boost::python::tuple radiusSearch(const AcGePoint3d& point, double radius) const;
    boost::python::tuple knnSearch(const AcGePoint3d& point, int num_closest) const;
    PyGePoint3dArray     inputPoints() const;
    static std::string   className();
    //
    PyGePoint3dTreeAdapter adapter;
    std::shared_ptr<kd_tree3d_t> pTree;
};

//-----------------------------------------------------------------------------------------
//PyGePoint3dTreeAdapter
PyGePoint3dTreeAdapter::PyGePoint3dTreeAdapter(const PyGePoint3dArray& points)
    : mpoints(points)
{
}

PyGePoint3dTreeAdapter::PyGePoint3dTreeAdapter(PyGePoint3dArray&& points)
    : mpoints(std::move(points))
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
        .def(init<const PyGePoint3dArray&>())
        .def(init<const boost::python::list&>(DS.ARGS({ "points : Collection[PyGe.Point3d]" })))
        .def("radiusSearch", &PyGePoint3dTree::radiusSearch, DS.ARGS({ "point: PyGe.Point3d", "radius: float" }))
        .def("knnSearch", &PyGePoint3dTree::knnSearch, DS.ARGS({ "point: PyGe.Point3d", "num_closest: int" }))
        .def("inputPoints", &PyGePoint3dTree::inputPoints, DS.ARGS())
        .def("className", &PyGePoint3dTree::className, DS.SARGS()).staticmethod("className")
        ;
}

PyGePoint3dTree::PyGePoint3dTree(const PyGePoint3dArray& points)
    : adapter(points)
{
    create();
}

PyGePoint3dTree::PyGePoint3dTree(const boost::python::list& points)
    : adapter(std::move(py_list_to_std_vector<AcGePoint3d>(points)))
{
    create();
}

void PyGePoint3dTree::create()
{
    nanoflann::KDTreeSingleIndexAdaptorParams params;
    params.leaf_max_size = leafSize;
    params.n_thread_build = 0;
    pTree.reset(new kd_tree3d_t(3, adapter, params));
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

PyGePoint3dArray PyGePoint3dTree::inputPoints() const
{
    return adapter.mpoints;
}

std::string PyGePoint3dTree::className()
{
    return "Point3dTree";
}

//-----------------------------------------------------------------------------------------
//PyGeDelaunator
class PyGeDelaunator
{
public:
    PyGeDelaunator(const PyGePoint3dArray& points)
        : m_delaunator(create(points))
    {
    }
    PyGeDelaunator(const boost::python::list& points)
        : m_delaunator(create(py_list_to_std_vector<AcGePoint3d>(points)))
    {
    }

    ~PyGeDelaunator() = default;

    boost::python::list triangles() const
    {
        PyAutoLockGIL lock;
        boost::python::list pylist;
        for (auto i : m_delaunator.triangles)
            pylist.append(i);
        return pylist;
    }

    boost::python::list halfedges() const
    {
        boost::python::list pylist;
        for (auto i : m_delaunator.halfedges)
            pylist.append((i == delaunator::INVALID_INDEX) ? -1 : static_cast<int64_t>(i));
        return pylist;
    }

    static std::string className()
    {
        return "Delaunator";
    }

    static std::vector<double> create(const PyGePoint3dArray& points)
    {
        if (points.size() < 3)
            PyThrowBadEs(eInvalidInput);
        std::vector<double> coords;
        coords.reserve(points.size() * 2);
        for (const auto& item : points)
        {
            coords.emplace_back(item.x);
            coords.emplace_back(item.y);
        }
        return coords;
    }
    //
    delaunator::Delaunator m_delaunator;
};

//-----------------------------------------------------------------------------------------
//PyGeDelaunator wrapper
void makePyGeDelaunatorWrapper()
{
    PyDocString DS("Delaunator");
    class_<PyGeDelaunator>("Delaunator", boost::python::no_init)
        .def(init<const PyGePoint3dArray&>())
        .def(init<const boost::python::list&>(DS.ARGS({ "points : Collection[PyGe.Point3d]" })))
        .def("halfedges", &PyGeDelaunator::halfedges, DS.ARGS())
        .def("triangles", &PyGeDelaunator::triangles, DS.ARGS())
        .def("className", &PyGeDelaunator::className, DS.SARGS()).staticmethod("className")
        ;
}

#ifdef USE_CDT_FEATRE
//-----------------------------------------------------------------------------------------
//CDT wrapper
enum class CDTinatorOpt : int32_t {
    None = 0,
    KEraseSuperTriangle = 1 << 0, // 1
    kEraseOuterTriangles = 1 << 1, // 2
    kEaseOuterTrianglesAndHoles = 1 << 2, // 4
};

struct CDTinator
{
    static boost::python::list triangulate1(
        const PyGePoint3dArray& points,
        const boost::python::list& edges,
        CDTinatorOpt opts)
    {
        namespace bp = boost::python;

        PyAutoLockGIL lock;
        std::vector<CDT::V2d<double>> cdtVertices;
        cdtVertices.reserve(points.size());
        for (const auto& pt : points)
            cdtVertices.push_back({ pt.x, pt.y });

        std::vector<CDT::Edge> cdtEdges;
        size_t edgeCount = bp::len(edges);
        cdtEdges.reserve(edgeCount);
        for (size_t i = 0; i < edgeCount; ++i)
        {
            bp::tuple edgeTuple = bp::extract<bp::tuple>(edges[i]);
            size_t v1 = bp::extract<size_t>(edgeTuple[0]);
            size_t v2 = bp::extract<size_t>(edgeTuple[1]);
            cdtEdges.push_back(CDT::Edge(v1, v2));
        }

        CDT::DuplicatesInfo di = CDT::RemoveDuplicatesAndRemapEdges(cdtVertices, cdtEdges);

        CDT::Triangulation<double> cdt(
            CDT::VertexInsertionOrder::AsProvided,
            CDT::IntersectingConstraintEdges::NotAllowed,
            AcGeContext::gTol.equalPoint());

        cdt.insertVertices(cdtVertices);
        std::vector<CDT::Edge> validEdges;
        for (const auto& e : cdtEdges)
        {
            if (e.v1() != e.v2())
                validEdges.push_back(e);
        }

        cdt.insertEdges(validEdges);
        if (GETBIT(int32_t(opts), int32_t(CDTinatorOpt::KEraseSuperTriangle)))
            cdt.eraseSuperTriangle();
        if (GETBIT(int32_t(opts), int32_t(CDTinatorOpt::kEraseOuterTriangles)))
            cdt.eraseOuterTriangles();
        if (GETBIT(int32_t(opts), int32_t(CDTinatorOpt::kEaseOuterTrianglesAndHoles)))
            cdt.eraseOuterTrianglesAndHoles();

        bp::list mesh_indices;
        for (const auto& triangle : cdt.triangles)
        {
            size_t originalIdxA = di.mapping[triangle.vertices[0]];
            size_t originalIdxB = di.mapping[triangle.vertices[1]];
            size_t originalIdxC = di.mapping[triangle.vertices[2]];
            mesh_indices.append(bp::make_tuple(originalIdxA, originalIdxB, originalIdxC));
        }
        return mesh_indices;
    }

    static boost::python::list triangulate2(
        const boost::python::list& points,
        const boost::python::list& edges,
        CDTinatorOpt opts)
    {
        return triangulate1(py_list_to_std_vector<AcGePoint3d>(points), edges, opts);
    }
};
#endif

void makeCDTWrapper()
{
#ifdef USE_CDT_FEATRE
    PyDocString DS("CDT");
    class_<CDTinator>("CDT", no_init)
        .def("triangulate", &CDTinator::triangulate1)
        .def("triangulate", &CDTinator::triangulate2, DS.ARGS({ "points:Collection[PyGe.Point3d]","edges:Collection[tuple[int,int]]", "opts:PyGe.CDTOpts" })).staticmethod("triangulate")
        ;
    enum_<CDTinatorOpt>("CDTOpts")
        .value("None", CDTinatorOpt::None)
        .value("KEraseSuperTriangle", CDTinatorOpt::KEraseSuperTriangle)
        .value("kEraseOuterTriangles", CDTinatorOpt::kEraseOuterTriangles)
        .value("kEaseOuterTrianglesAndHoles", CDTinatorOpt::kEaseOuterTrianglesAndHoles)
        .export_values()
        ;
#endif
}
