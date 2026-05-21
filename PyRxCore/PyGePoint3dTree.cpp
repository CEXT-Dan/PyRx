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
    kEraseSuperTriangle = 1 << 0,          // 1
    kEraseOuterTriangles = 1 << 1,         // 2
    kEraseOuterTrianglesAndHoles = 1 << 2, // 4 
    kInsertEdges = 1 << 3,                 // 8
    kConformToEdges = 1 << 4,              // 16
};

struct CDTinator
{
    static boost::python::tuple triangulate1(
        const PyGePoint3dArray& points,
        const boost::python::list& edges,
        CDTinatorOpt opts)
    {
        namespace bp = boost::python;
        PyAutoLockGIL lock;

        bool useInsert = GETBIT(int32_t(opts), int32_t(CDTinatorOpt::kInsertEdges));
        bool useConform = GETBIT(int32_t(opts), int32_t(CDTinatorOpt::kConformToEdges));

        // 1. Project 3D points down to 2D for the triangulation engine
        std::vector<CDT::V2d<double>> cdtVertices;
        cdtVertices.reserve(points.size());
        for (const auto& pt : points) {
            cdtVertices.push_back({ pt.x, pt.y });
        }

        // 2. Parse constraint edge indices from Python safely
        std::vector<CDT::Edge> cdtEdges;
        size_t edgeCount = bp::len(edges);
        cdtEdges.reserve(edgeCount);
        for (size_t i = 0; i < edgeCount; ++i)
        {
            bp::extract<bp::tuple> tupleCheck(edges[i]);
            if (!tupleCheck.check()) {
                PyThrowBadEs(eInvalidInput);
            }
            bp::tuple edgeTuple = tupleCheck();
            if (bp::len(edgeTuple) < 2) {
                PyThrowBadEs(eInvalidInput);
            }
            size_t v1 = bp::extract<size_t>(edgeTuple[0]);
            size_t v2 = bp::extract<size_t>(edgeTuple[1]);
            cdtEdges.push_back(CDT::Edge(v1, v2));
        }

        // 3. Filter out point duplicates
        CDT::DuplicatesInfo di = CDT::RemoveDuplicatesAndRemapEdges(cdtVertices, cdtEdges);

        // Build inverse vertex map: [Post-Duplication ID] -> [Original 3D Point Array ID]
        const size_t kInvalidIndex = static_cast<size_t>(-1);
        std::vector<size_t> inverseMapping(cdtVertices.size(), kInvalidIndex);
        for (size_t originalIdx = 0; originalIdx < di.mapping.size(); ++originalIdx)
        {
            size_t newIdx = di.mapping[originalIdx];
            if (newIdx != kInvalidIndex && newIdx < inverseMapping.size())
            {
                if (inverseMapping[newIdx] == kInvalidIndex) {
                    inverseMapping[newIdx] = originalIdx;
                }
            }
        }

        // 4. Construct Triangulation Space with Intersecting Edge Resolution
        CDT::Triangulation<double> cdt(
            CDT::VertexInsertionOrder::Auto,
            CDT::IntersectingConstraintEdges::TryResolve, // Correctly tracking crossing constraints
            AcGeContext::gTol.equalPoint());

        cdt.insertVertices(cdtVertices);

        // Clean out degenerate zero-length structural constraint edges
        std::vector<CDT::Edge> validEdges;
        validEdges.reserve(cdtEdges.size());
        for (const auto& e : cdtEdges)
        {
            if (e.v1() != e.v2())
                validEdges.push_back(e);
        }

        // Run triangulation execution
        if (useConform)
            cdt.conformToEdges(validEdges);
        else
            cdt.insertEdges(validEdges);

        // 5. Clean boundary artifacts
        if (GETBIT(int32_t(opts), int32_t(CDTinatorOpt::kEraseSuperTriangle)))
            cdt.eraseSuperTriangle();
        if (GETBIT(int32_t(opts), int32_t(CDTinatorOpt::kEraseOuterTriangles)))
            cdt.eraseOuterTriangles();
        if (GETBIT(int32_t(opts), int32_t(CDTinatorOpt::kEraseOuterTrianglesAndHoles)))
            cdt.eraseOuterTrianglesAndHoles();

        // 6. Reconstruct complete, updated 3D Point cloud array
        PyGePoint3dArray outPoints;
        outPoints.reserve(cdt.vertices.size());

        // Build a temporary adjacency map to quickly find edges sharing any Steiner vertex
        std::map<size_t, std::vector<size_t>> vertexAdjacency;
        for (const auto& tri : cdt.triangles) {
            size_t a = tri.vertices[0];
            size_t b = tri.vertices[1];
            size_t c = tri.vertices[2];
            vertexAdjacency[a].push_back(b); vertexAdjacency[a].push_back(c);
            vertexAdjacency[b].push_back(a); vertexAdjacency[b].push_back(c);
            vertexAdjacency[c].push_back(a); vertexAdjacency[c].push_back(b);
        }

        for (size_t i = 0; i < cdt.vertices.size(); ++i)
        {
            AcGePoint3d pt;
            pt.x = cdt.vertices[i].x;
            pt.y = cdt.vertices[i].y;

            if (i < inverseMapping.size() && inverseMapping[i] != kInvalidIndex)
            {
                // Unchanged base vertex position
                pt.z = points[inverseMapping[i]].z;
            }
            else
            {
                // Steiner Point / Intersection found. Linearly interpolate and average Z values.
                double zSum = 0.0;
                size_t zCount = 0;
                const auto& neighbors = vertexAdjacency[i];

                // Track unique parent constraint edges processed for this specific vertex to avoid duplicate weightings
                std::vector<CDT::Edge> processedParentEdges;

                for (size_t neighbor : neighbors)
                {
                    CDT::Edge subEdgeKey(i, neighbor);
                    auto it = cdt.pieceToOriginals.find(subEdgeKey);

                    if (it != cdt.pieceToOriginals.end())
                    {
                        // Iterate through all parent constraints that this piece belongs to
                        for (const auto& postDupOrigEdge : it->second)
                        {
                            // Avoid counting the same parent constraint line twice
                            if (std::find(processedParentEdges.begin(), processedParentEdges.end(), postDupOrigEdge) != processedParentEdges.end()) {
                                continue;
                            }
                            processedParentEdges.push_back(postDupOrigEdge);

                            // Convert post-duplication vertex indices back to original 3D indices
                            size_t origV1 = inverseMapping[postDupOrigEdge.v1()];
                            size_t origV2 = inverseMapping[postDupOrigEdge.v2()];

                            if (origV1 != kInvalidIndex && origV2 != kInvalidIndex)
                            {
                                AcGePoint3d pA = points[origV1];
                                AcGePoint3d pB = points[origV2];

                                double dx = pB.x - pA.x;
                                double dy = pB.y - pA.y;
                                double dLengthSq = dx * dx + dy * dy;

                                if (dLengthSq > 1e-11)
                                {
                                    // Calculate 2D linear projection parameter (t)
                                    double t = ((pt.x - pA.x) * dx + (pt.y - pA.y) * dy) / dLengthSq;
                                    t = std::max(0.0, std::min(1.0, t)); // Keep bounds safe

                                    zSum += (pA.z + t * (pB.z - pA.z));
                                    zCount++;
                                }
                            }
                        }
                    }
                }

                // Apply the averaged calculation or use fallback if it's an isolated Steiner point
                if (zCount > 0) {
                    pt.z = zSum / static_cast<double>(zCount);
                }
                else {
                    pt.z = 0.0;
                }
            }
            outPoints.push_back(pt);
        }

        // 7. Map final Mesh output indices referencing our new outPoints indices
        bp::list mesh_indices;
        for (const auto& triangle : cdt.triangles)
        {
            size_t idxA = triangle.vertices[0];
            size_t idxB = triangle.vertices[1];
            size_t idxC = triangle.vertices[2];

            if (idxA >= outPoints.size() || idxB >= outPoints.size() || idxC >= outPoints.size()) {
                PyThrowBadEs(eInvalidInput);
            }

            mesh_indices.append(bp::make_tuple(idxA, idxB, idxC));
        }

        return bp::make_tuple(outPoints, mesh_indices);
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
