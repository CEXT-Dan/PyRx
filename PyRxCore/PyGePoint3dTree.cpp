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
// CDT wrapper
enum class CDTinatorOpt : int32_t
{
    None = 0,
    kEraseSuperTriangle = 1 << 0,
    kEraseOuterTriangles = 1 << 1,
    kEraseOuterTrianglesAndHoles = 1 << 2,
    kInsertEdges = 1 << 3,
    kConformToEdges = 1 << 4,
};

struct CDTEdgeHash
{
    std::size_t operator()(const CDT::Edge& e) const
    {
        std::size_t seed = 0;
        boost::hash_combine(seed, e.v1());
        boost::hash_combine(seed, e.v2());
        return seed;
    }
};

struct CDTinator
{
    static boost::python::tuple triangulate1(const PyGePoint3dArray& points, const boost::python::list& edges, CDTinatorOpt opts)
    {
        namespace bp = boost::python;

        PyAutoLockGIL lock;

        constexpr size_t kInvalidIndex = std::numeric_limits<size_t>::max();

        const double tol = AcGeContext::gTol.equalPoint();
        const double tolSq = tol * tol;

        const bool useInsert = GETBIT(int32_t(opts), int32_t(CDTinatorOpt::kInsertEdges));
        const bool useConform = GETBIT(int32_t(opts), int32_t(CDTinatorOpt::kConformToEdges));
        const bool eraseOuter = GETBIT(int32_t(opts), int32_t(CDTinatorOpt::kEraseOuterTriangles));
        const bool eraseOuterHoles = GETBIT(int32_t(opts), int32_t(CDTinatorOpt::kEraseOuterTrianglesAndHoles));
        const bool eraseSuperTriangle = GETBIT(int32_t(opts), int32_t(CDTinatorOpt::kEraseSuperTriangle));

        if (useInsert && useConform)
            PyThrowBadEs(eInvalidInput);

        //--------------------------------------------------------------------------
        // Project vertices to 2D
        //--------------------------------------------------------------------------
        std::vector<CDT::V2d<double>> cdtVertices;
        cdtVertices.reserve(points.size());

        for (const auto& pt : points)
            cdtVertices.emplace_back(CDT::V2d<double>{ pt.x, pt.y });

        //--------------------------------------------------------------------------
        // Parse edges
        //--------------------------------------------------------------------------
        std::vector<CDT::Edge> cdtEdges;
        const size_t edgeCount = static_cast<size_t>(bp::len(edges));
        cdtEdges.reserve(edgeCount);

        for (size_t i = 0; i < edgeCount; ++i)
        {
            bp::extract<bp::tuple> tupleCheck(edges[i]);
            if (!tupleCheck.check())
                PyThrowBadEs(eInvalidInput);

            bp::tuple edgeTuple = tupleCheck();
            if (bp::len(edgeTuple) < 2)
                PyThrowBadEs(eInvalidInput);

            bp::extract<size_t> ex1(edgeTuple[0]);
            bp::extract<size_t> ex2(edgeTuple[1]);
            if (!ex1.check() || !ex2.check())
                PyThrowBadEs(eInvalidInput);

            const size_t v1 = ex1();
            const size_t v2 = ex2();
            if (v1 >= points.size() ||
                v2 >= points.size())
            {
                PyThrowBadEs(eInvalidInput);
            }
            cdtEdges.emplace_back(v1, v2);
        }

        //--------------------------------------------------------------------------
        // Remove duplicates
        //--------------------------------------------------------------------------
        CDT::DuplicatesInfo di = CDT::RemoveDuplicatesAndRemapEdges(cdtVertices, cdtEdges);
        std::vector<size_t> inverseMapping(cdtVertices.size(), kInvalidIndex);

        for (size_t originalIdx = 0; originalIdx < di.mapping.size(); ++originalIdx)
        {
            const size_t newIdx = di.mapping[originalIdx];

            if (newIdx == kInvalidIndex)
                continue;

            if (newIdx >= inverseMapping.size())
                continue;

            if (inverseMapping[newIdx] == kInvalidIndex)
                inverseMapping[newIdx] = originalIdx;
        }

        //--------------------------------------------------------------------------
        // Create CDT
        //--------------------------------------------------------------------------
        CDT::Triangulation<double> cdt(
            CDT::VertexInsertionOrder::Auto,
            CDT::IntersectingConstraintEdges::TryResolve,
            tol);

        cdt.insertVertices(cdtVertices);

        //--------------------------------------------------------------------------
        // Remove degenerate edges
        //--------------------------------------------------------------------------
        std::vector<CDT::Edge> validEdges;
        validEdges.reserve(cdtEdges.size());

        for (const auto& e : cdtEdges)
        {
            if (e.v1() != e.v2())
                validEdges.push_back(e);
        }

        //--------------------------------------------------------------------------
        // Execute triangulation
        //--------------------------------------------------------------------------
        if (useConform)
            cdt.conformToEdges(validEdges);
        else
            cdt.insertEdges(validEdges);

        //--------------------------------------------------------------------------
        // Cleanup
        //--------------------------------------------------------------------------
        if (eraseSuperTriangle)
            cdt.eraseSuperTriangle();

        if (eraseOuter)
            cdt.eraseOuterTriangles();

        if (eraseOuterHoles)
            cdt.eraseOuterTrianglesAndHoles();

        //--------------------------------------------------------------------------
        // Build adjacency
        //--------------------------------------------------------------------------
        std::unordered_map<size_t, std::unordered_set<size_t>> vertexAdjacency;
        vertexAdjacency.reserve(cdt.vertices.size());

        for (const auto& tri : cdt.triangles)
        {
            const size_t a = tri.vertices[0];
            const size_t b = tri.vertices[1];
            const size_t c = tri.vertices[2];

            vertexAdjacency[a].insert(b);
            vertexAdjacency[a].insert(c);

            vertexAdjacency[b].insert(a);
            vertexAdjacency[b].insert(c);

            vertexAdjacency[c].insert(a);
            vertexAdjacency[c].insert(b);
        }

        //--------------------------------------------------------------------------
        // Restore 3D vertices
        //--------------------------------------------------------------------------
        PyGePoint3dArray outPoints;
        outPoints.reserve(cdt.vertices.size());

        for (size_t i = 0; i < cdt.vertices.size(); ++i)
        {
            AcGePoint3d pt{ cdt.vertices[i].x ,cdt.vertices[i].y , 0.0 };

            if (i < inverseMapping.size() && inverseMapping[i] != kInvalidIndex)
            {
                pt.z = points[inverseMapping[i]].z;
            }
            else
            {
                double zSum = 0.0;
                size_t zCount = 0;
                auto adjIt = vertexAdjacency.find(i);

                if (adjIt != vertexAdjacency.end())
                {
                    const auto& neighbors = adjIt->second;
                    std::unordered_set<CDT::Edge, CDTEdgeHash> processedParentEdges;

                    for (size_t neighbor : neighbors)
                    {
                        CDT::Edge subEdgeKey(i, neighbor);
                        auto pieceIt = cdt.pieceToOriginals.find(subEdgeKey);
                        if (pieceIt == cdt.pieceToOriginals.end())
                            continue;

                        for (const auto& postDupOrigEdge : pieceIt->second)
                        {
                            if (processedParentEdges.find(postDupOrigEdge) != processedParentEdges.end())
                                continue;
                            else
                                processedParentEdges.insert(postDupOrigEdge);

                            if (postDupOrigEdge.v1() >= inverseMapping.size())
                                continue;

                            if (postDupOrigEdge.v2() >= inverseMapping.size())
                                continue;

                            const size_t origV1 = inverseMapping[postDupOrigEdge.v1()];
                            const size_t origV2 = inverseMapping[postDupOrigEdge.v2()];

                            if (origV1 == kInvalidIndex)
                                continue;

                            if (origV2 == kInvalidIndex)
                                continue;

                            const auto& pA = points[origV1];
                            const auto& pB = points[origV2];

                            const double dx = pB.x - pA.x;
                            const double dy = pB.y - pA.y;
                            const double lenSq = dx * dx + dy * dy;

                            if (lenSq <= tolSq)
                                continue;

                            double t = ((pt.x - pA.x) * dx + (pt.y - pA.y) * dy) / lenSq;
                            t = std::clamp(t, 0.0, 1.0);
                            zSum += pA.z + t * (pB.z - pA.z);
                            ++zCount;
                        }
                    }
                }
                if (zCount > 0)
                {
                    pt.z = zSum / static_cast<double>(zCount);
                }
                else
                {
                    pt.z = 0.0;
                }
            }
            outPoints.push_back(pt);
        }

        //--------------------------------------------------------------------------
        // Mesh indices
        //--------------------------------------------------------------------------
        bp::list meshIndices;
        for (const auto& tri : cdt.triangles)
        {
            const size_t a = tri.vertices[0];
            const size_t b = tri.vertices[1];
            const size_t c = tri.vertices[2];

            if (a >= outPoints.size() ||
                b >= outPoints.size() ||
                c >= outPoints.size())
            {
                PyThrowBadEs(eInvalidInput);
            }
            meshIndices.append(bp::make_tuple(a, b, c));
        }
        return bp::make_tuple(outPoints, meshIndices);
    }

    static boost::python::tuple triangulate2(
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
        .value("kNone", CDTinatorOpt::None)
        .value("KEraseSuperTriangle", CDTinatorOpt::kEraseSuperTriangle)
        .value("kEraseOuterTriangles", CDTinatorOpt::kEraseOuterTriangles)
        .value("kEraseOuterTrianglesAndHoles", CDTinatorOpt::kEraseOuterTrianglesAndHoles)
        .value("KInsertEdges", CDTinatorOpt::kInsertEdges)
        .value("KConformToEdges", CDTinatorOpt::kConformToEdges)
        .export_values()
        ;
#endif
}
