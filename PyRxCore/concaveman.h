// 
// Author: Stanislaw Adaszewski, 2019
// C++ port from https://github.com/mapbox/concaveman (js)
//
// Comments from js repo added by wheeled
//

#pragma once
//https://github.com/mapbox/concaveman
//https://github.com/sadaszewski/concaveman-cpp

namespace Concave
{
    inline std::vector<std::size_t> tag_sortX(const std::vector<AcGePoint3d>& v)
    {
        std::vector<std::size_t> result(v.size());
        std::iota(std::begin(result), std::end(result), 0);
        std::sort(std::execution::par, std::begin(result), std::end(result), [&v](const auto& lhs, const auto& rhs)
            {
                if (v[lhs].x == v[rhs].x)
                    return v[lhs].y < v[rhs].y;
                return v[lhs].x < v[rhs].x;
            }
        );
        return result;
    }

    inline const AcGePoint3d& PntAt(const std::vector<AcGePoint3d>& points, const std::vector<size_t>& IdxV, size_t IDX)
    {
        if (IDX < points.size() && IDX < IdxV.size())
            return points[IdxV[IDX]];
        return AcGePoint3d::kOrigin;
    }

    inline double ConvexCross(const AcGePoint3d& O, const AcGePoint3d& A, const AcGePoint3d& B)
    {
        return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
    }

    inline void ConvexHull(const std::vector<AcGePoint3d>& pnts, std::vector<size_t>& hullIdx)
    {
        const std::vector<size_t> pntIdxs = tag_sortX(pnts);

        if (pnts.size() < 3)
            return;

        size_t n = pnts.size(), k = 0;
        std::vector<size_t> H;

        for (int idx = 0; idx < n * 2; idx++)
            H.push_back(0);

        // Build lower hull
        for (int i = 0; i < n; ++i)
        {
            while (k >= 2 && ConvexCross(PntAt(pnts, pntIdxs, H[k - 2]), PntAt(pnts, pntIdxs, H[k - 1]), PntAt(pnts, pntIdxs, i)) <= 0)
                k--;
            H[k++] = i;
        }

        // Build upper hull
        for (int i = n - 2, t = k + 1; i >= 0; i--)
        {
            while (k >= t && ConvexCross(PntAt(pnts, pntIdxs, H[k - 2]), PntAt(pnts, pntIdxs, H[k - 1]), PntAt(pnts, pntIdxs, i)) <= 0)
                k--;
            H[k++] = i;
        }

        for (size_t idx = 0; idx < k - 1; idx++)
        {
            if (idx < H.size())
                hullIdx.push_back(pntIdxs[H[idx]]);
        }
    }

    template<typename T, typename... Args>
    inline std::unique_ptr<T> make_unique(Args&&... args)
    {
        return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
    }

    template<typename T, typename data_type, typename  bounds_type>
    inline std::unique_ptr<T> make_unique(data_type d, bounds_type b)
    {
        return std::unique_ptr<T>(new T(d, b));
    }

    template<class T> class compare_first
    {
    public:
        inline bool operator()(const T& a, const T& b)
        {
            return (std::get<0>(a) < std::get<0>(b));
        }
    };

    inline double orient2d(const AcGePoint3d& p1, const AcGePoint3d& p2, const AcGePoint3d& p3)
    {
        return (p2[1] - p1[1]) * (p3[0] - p2[0]) - (p2[0] - p1[0]) * (p3[1] - p2[1]);
    }

    // check if the edges (p1,q1) and (p2,q2) intersect
    inline bool intersects(const AcGePoint3d& p1, const AcGePoint3d& q1, const AcGePoint3d& p2, const AcGePoint3d& q2)
    {
        auto res = (p1[0] != q2[0] || p1[1] != q2[1]) && (q1[0] != p2[0] || q1[1] != p2[1]) &&
            (orient2d(p1, q1, p2) > 0) != (orient2d(p1, q1, q2) > 0) &&
            (orient2d(p2, q2, p1) > 0) != (orient2d(p2, q2, q1) > 0);
        return res;
    }

    // square distance between 2 points
    inline double getSqDist(const  AcGePoint3d& p1, const  AcGePoint3d& p2)
    {
        auto dx = p1[0] - p2[0];
        auto dy = p1[1] - p2[1];
        return dx * dx + dy * dy;
    }

    // square distance from a point to a segment
    double sqSegDist(const AcGePoint3d& p, const AcGePoint3d& p1, const AcGePoint3d& p2)
    {
        auto x = p1[0];
        auto y = p1[1];
        auto dx = p2[0] - x;
        auto dy = p2[1] - y;

        if (dx != 0 || dy != 0)
        {
            auto t = ((p[0] - x) * dx + (p[1] - y) * dy) / (dx * dx + dy * dy);
            if (t > 1) {
                x = p2[0];
                y = p2[1];
            }
            else if (t > 0)
            {
                x += dx * t;
                y += dy * t;
            }
        }

        dx = p[0] - x;
        dy = p[1] - y;

        return dx * dx + dy * dy;
    }

    // segment to segment distance, ported from http://geomalgorithms.com/a07-_distance.html by Dan Sunday
    double sqSegSegDist
    (
        double x0, double y0,
        double x1, double y1,
        double x2, double y2,
        double x3, double y3
    )
    {
        auto ux = x1 - x0;
        auto uy = y1 - y0;
        auto vx = x3 - x2;
        auto vy = y3 - y2;
        auto wx = x0 - x2;
        auto wy = y0 - y2;
        auto a = ux * ux + uy * uy;
        auto b = ux * vx + uy * vy;
        auto c = vx * vx + vy * vy;
        auto d = ux * wx + uy * wy;
        auto e = vx * wx + vy * wy;
        auto D = a * c - b * b;

        double sc, sN, tc, tN;
        auto sD = D;
        auto tD = D;

        if (D == 0) {
            sN = 0;
            sD = 1;
            tN = e;
            tD = c;
        }
        else {
            sN = b * e - c * d;
            tN = a * e - b * d;
            if (sN < 0) {
                sN = 0;
                tN = e;
                tD = c;
            }
            else if (sN > sD) {
                sN = sD;
                tN = e + b;
                tD = c;
            }
        }

        if (tN < 0) {
            tN = 0;
            if (-d < 0) sN = 0;
            else if (-d > a) sN = sD;
            else {
                sN = -d;
                sD = a;
            }
        }
        else if (tN > tD) {
            tN = tD;
            if (-d + b < 0) sN = 0;
            else if (-d + b > a) sN = sD;
            else {
                sN = -d + b;
                sD = a;
            }
        }

        sc = ((sN == 0) ? 0 : sN / sD);
        tc = ((tN == 0) ? 0 : tN / tD);

        auto cx = (1 - sc) * x0 + sc * x1;
        auto cy = (1 - sc) * y0 + sc * y1;
        auto cx2 = (1 - tc) * x2 + tc * x3;
        auto cy2 = (1 - tc) * y2 + tc * y3;
        auto dx = cx2 - cx;
        auto dy = cy2 - cy;

        return dx * dx + dy * dy;
    }

    template<int DIM, int MAX_CHILDREN, class DATA> class rtree
    {
    public:
        typedef rtree<DIM, MAX_CHILDREN, DATA> type;
        typedef const type const_type;
        typedef type* type_ptr;
        typedef const type* type_const_ptr;
        typedef std::array<double, DIM * 2> bounds_type;
        typedef DATA data_type;

        rtree() :
            m_is_leaf(false), m_data()
        {
            for (auto i = 0; i < DIM; i++) {
                m_bounds[i] = std::numeric_limits<double>::max();
                m_bounds[i + DIM] = std::numeric_limits<double>::min();
            }
        }

        rtree(data_type data, const bounds_type& bounds) :
            m_is_leaf(true), m_data(data), m_bounds(bounds)
        {
            for (auto i = 0; i < DIM; i++)
                if (bounds[i] > bounds[i + DIM])
                    throw std::runtime_error("Bounds minima have to be less than maxima");
        }

        void insert(data_type data, const bounds_type& bounds)
        {
            if (m_is_leaf)
                throw std::runtime_error("Cannot insert into leaves");

            m_bounds = updated_bounds(bounds);
            if (m_children.size() < MAX_CHILDREN) {
                auto r = make_unique<type>(data, bounds);
                m_children.push_back(std::move(r));
                return;
            }
            std::reference_wrapper<type> best_child = *m_children.begin()->get();
            auto best_volume = volume(best_child.get().updated_bounds(bounds));
            for (auto it = ++m_children.begin(); it != m_children.end(); it++) {
                auto v = volume((*it)->updated_bounds(bounds));
                if (v < best_volume) {
                    best_volume = v;
                    best_child = *it->get();
                }
            }
            if (!best_child.get().is_leaf())
            {
                best_child.get().insert(data, bounds);
                return;
            }

            auto leaf = make_unique<type>(best_child.get().data(),
                best_child.get().bounds());
            best_child.get().m_is_leaf = false;
            best_child.get().m_data = data_type();
            best_child.get().m_children.push_back(std::move(leaf));
            best_child.get().insert(data, bounds);
        }

        void intersection(const bounds_type& bounds, std::vector<std::reference_wrapper<const_type>>& res) const
        {
            if (!intersects(bounds))
                return;
            if (m_is_leaf) {
                res.push_back(*this);
                return;
            }
            for (auto& ch : m_children)
                ch->intersection(bounds, res);
        }

        std::vector<std::reference_wrapper<const_type>> intersection(const bounds_type& bounds) const
        {
            std::vector<std::reference_wrapper<const_type>> res;
            intersection(bounds, res);
            return res;
        }

        inline bool intersects(const bounds_type& bounds) const
        {
            for (auto i = 0; i < DIM; i++) {
                if (m_bounds[i] > bounds[i + DIM])
                    return false;
                if (m_bounds[i + DIM] < bounds[i])
                    return false;
            }
            return true;
        }

        void erase(data_type data, const bounds_type& bounds)
        {
            if (m_is_leaf)
                throw std::runtime_error("Cannot erase from leaves");

            if (!intersects(bounds))
                return;

            for (auto it = m_children.begin(); it != m_children.end(); ) {
                if (!(*it)->m_is_leaf) {
                    (*it)->erase(data, bounds);
                    it++;
                }
                else if ((*it)->m_data == data &&
                    (*it)->m_bounds == bounds) {
                    m_children.erase(it++);
                }
                else
                    it++;
            }
        }

        inline bounds_type updated_bounds(const bounds_type& child_bounds) const
        {
            bounds_type res;
            for (auto i = 0; i < DIM; i++)
            {
                res[i] = std::min(child_bounds[i], m_bounds[i]);
                res[i + DIM] = std::max(child_bounds[i + DIM], m_bounds[i + DIM]);
            }
            return res;
        }

        inline double volume(const bounds_type& bounds) const
        {
            double res = 1;
            for (auto i = 0; i < DIM; i++)
            {
                auto delta = bounds[i + DIM] - bounds[i];
                res *= delta;
            }
            return res;
        }

        inline const bounds_type& bounds() const
        {
            return m_bounds;
        }

        inline bool is_leaf() const
        {
            return m_is_leaf;
        }

        inline data_type data() const
        {
            return m_data;
        }

        inline const std::list<std::unique_ptr<type>>& children() const
        {
            return m_children;
        }
    private:
        bool m_is_leaf;
        data_type m_data;
        std::list<std::unique_ptr<type>> m_children;
        bounds_type m_bounds;
    };

    struct Node
    {
        explicit Node(const size_t& _p)
            : p(_p)
        {
        }
        size_t p = 0;
        double minX;
        double minY;
        double maxX;
        double maxY;
    };

    template <class T> class CircularList;
    template<class T> class CircularElement {
    public:
        typedef CircularElement<T> type;
        typedef type* ptr_type;

        template<class... Args> CircularElement<T>(Args&&... args) :
            m_data(std::forward<Args>(args)...) {

        }

        T& data() {
            return m_data;
        }

        template<class... Args> CircularElement<T>* insert(Args&&... args) {
            auto elem = new CircularElement<T>(std::forward<Args>(args)...);
            elem->m_prev = this;
            elem->m_next = m_next;
            m_next->m_prev = elem;
            m_next = elem;
            return elem;
        }

        inline CircularElement<T>* prev() {
            return m_prev;
        }

        inline CircularElement<T>* next() {
            return m_next;
        }

    private:
        T m_data;
        CircularElement<T>* m_prev;
        CircularElement<T>* m_next;

        friend class CircularList<T>;
    };

    template<class T> class CircularList {
    public:
        typedef CircularElement<T> element_type;

        inline CircularList() : m_last(nullptr) {

        }

        ~CircularList() {
            auto node = m_last;
            while (true)
            {
                auto tmp = node;
                node = node->m_next;
                delete tmp;
                if (node == m_last)
                    break;
            }
        }

        template<class... Args> CircularElement<T>* insert(element_type* prev, Args&&... args) {
            auto elem = new CircularElement<T>(std::forward<Args>(args)...);

            if (prev == nullptr && m_last != nullptr)
                throw std::runtime_error("Once the list is non-empty you must specify where to insert");

            if (prev == nullptr) {
                elem->m_prev = elem->m_next = elem;
            }
            else {
                elem->m_prev = prev;
                elem->m_next = prev->m_next;
                prev->m_next->m_prev = elem;
                prev->m_next = elem;
            }
            m_last = elem;
            return elem;
        }


    private:
        element_type* m_last;
    };

    // update the bounding box of a node's edge
    template<class T>
    inline void updateBBox(const std::vector<AcGePoint3d>& points, typename CircularElement<T>::ptr_type elem) {
        auto& node(elem->data());
        const auto& p1 = points[node.p];
        const auto& p2 = points[elem->next()->data().p];
        node.minX = std::min(p1[0], p2[0]);
        node.minY = std::min(p1[1], p2[1]);
        node.maxX = std::max(p1[0], p2[0]);
        node.maxY = std::max(p1[1], p2[1]);
    }

    template<int MAX_CHILDREN>
    std::vector<size_t> concaveman(const std::vector<AcGePoint3d>& points, double concavity = 2, double lengthThreshold = 0)
    {
        typedef CircularElement<Node> circ_elem_type;
        typedef CircularList<Node> circ_list_type;
        typedef circ_elem_type* circ_elem_ptr_type;

        // exit if hull includes all points already
        std::vector<size_t> hull;
        Concave::ConvexHull(points, hull);
        if (hull.size() == points.size())
        {
            std::vector<size_t> res;
            for (auto& i : hull)
                res.push_back(i);
            return res;
        }

        // index the points with an R-tree
        rtree<2, MAX_CHILDREN, size_t> tree;
        {
            size_t idx = 0;
            for (const auto& p : points)
            {
                tree.insert(idx, { p[0], p[1], p[0], p[1] });
                idx++;
            }
        }

        circ_list_type circList;
        circ_elem_ptr_type last = nullptr;
        std::list<circ_elem_ptr_type> queue;

        // turn the convex hull into a linked list and populate the initial edge queue with the nodes
        for (const auto& idx : hull)
        {
            auto& p = points[idx];
            tree.erase(idx, { p[0], p[1], p[0], p[1] });
            last = circList.insert(last, idx);
            queue.emplace_back(last);
        }

        // loops through the hull?  why?
        for (auto elem = last->next(); ; elem = elem->next())
        {
            if (elem == last)
                break;
        }

        // index the segments with an R-tree (for intersection checks)
        rtree<2, MAX_CHILDREN, circ_elem_ptr_type> segTree;
        for (const auto& elem : queue) {
            const auto& node(elem->data());
            updateBBox<Node>(points, elem);
            segTree.insert(elem, { node.minX,
                node.minY, node.maxX, node.maxY });
        }

        auto sqConcavity = concavity * concavity;
        auto sqLenThreshold = lengthThreshold * lengthThreshold;

        // process edges one by one
        while (!queue.empty()) {
            auto elem = *queue.begin();
            queue.pop_front();

            const auto& a = points[elem->prev()->data().p];
            const auto& b = points[elem->data().p];
            const auto& c = points[elem->next()->data().p];
            const auto& d = points[elem->next()->next()->data().p];

            // skip the edge if it's already short enough
            const auto sqLen = getSqDist(b, c);
            if (sqLen < sqLenThreshold)
                continue;

            const auto maxSqLen = sqLen / sqConcavity;

            // find the best connection point for the current edge to flex inward to
            bool ok = false;
            const auto& p = findCandidate(points, tree, a, b, c, d, maxSqLen, segTree, ok);
            const auto& pp = points[p];

            // if we found a connection and it satisfies our concavity measure
            if (ok && std::min(getSqDist(pp, b), getSqDist(pp, c)) <= maxSqLen)
            {
                // connect the edge endpoints through this point and add 2 new edges to the queue
                queue.emplace_back(elem);
                queue.emplace_back(elem->insert(p));

                // update point and segment indexes
                auto& node = elem->data();
                auto& next = elem->next()->data();
                tree.erase(p, { pp[0], pp[1], pp[0], pp[1] });
                segTree.erase(elem, { node.minX, node.minY, node.maxX, node.maxY });

                updateBBox<Node>(points, elem);
                updateBBox<Node>(points, elem->next());

                segTree.insert(elem, { node.minX, node.minY, node.maxX, node.maxY });
                segTree.insert(elem->next(), { next.minX, next.minY, next.maxX, next.maxY });
            }
        }

        // convert the resulting hull linked list to an array of points
        std::vector<size_t> concave;
        for (auto elem = last->next(); ; elem = elem->next()) {
            concave.push_back(elem->data().p);
            if (elem == last)
                break;
        }

        return concave;
    }

    template<int MAX_CHILDREN>
    size_t findCandidate
    (
        const std::vector<AcGePoint3d>& points,
        const rtree<2, MAX_CHILDREN, size_t>& tree,
        const AcGePoint3d& a,
        const AcGePoint3d& b,
        const AcGePoint3d& c,
        const AcGePoint3d& d,
        double maxDist,
        const rtree<2, MAX_CHILDREN, typename CircularElement<Node>::ptr_type>& segTree,
        bool& ok
    )
    {
        typedef CircularElement<Node> circ_elem_type;
        typedef rtree<2, MAX_CHILDREN, size_t> tree_type;
        typedef const tree_type const_tree_type;
        typedef std::reference_wrapper<const_tree_type> tree_ref_type;
        typedef std::tuple<double, tree_ref_type> tuple_type;

        ok = false;
        std::priority_queue<tuple_type, std::vector<tuple_type>, compare_first<tuple_type>> queue;
        std::reference_wrapper<const_tree_type> node = tree;

        // search through the point R-tree with a depth-first search using a priority queue
        // in the order of distance to the edge (b, c)
        while (true)
        {
            for (auto& child : node.get().children())
            {

                auto bounds = child->bounds();
                const AcGePoint3d pt = { bounds[0], bounds[1], 0 };

                auto dist = child->is_leaf() ? sqSegDist(pt, b, c) : sqSegBoxDist(b, c, *child);
                if (dist > maxDist)
                    continue;  // skip the node if it's farther than we ever need

                queue.push(tuple_type(-dist, *child));
            }

            while (!queue.empty() && std::get<1>(queue.top()).get().is_leaf())
            {
                auto item = queue.top();
                queue.pop();

                auto bounds = std::get<1>(item).get().bounds();
                const AcGePoint3d p{ bounds[0], bounds[1], 0 };

                // skip all points that are as close to adjacent edges (a,b) and (c,d),
                // and points that would introduce self-intersections when connected
                auto d0 = sqSegDist(p, a, b);
                auto d1 = sqSegDist(p, c, d);

                if (-std::get<0>(item) < d0 && -std::get<0>(item) < d1 &&
                    noIntersections(points, b, p, segTree) &&
                    noIntersections(points, c, p, segTree))
                {
                    ok = true;
                    return std::get<1>(item).get().data();
                }
            }

            if (queue.empty())
                break;

            node = std::get<1>(queue.top());
            queue.pop();
        }

        return size_t(0);
    }

    // square distance from a segment bounding box to the given one
    template<int MAX_CHILDREN, class USER_DATA>
    double sqSegBoxDist(const AcGePoint3d& a, const AcGePoint3d& b, const rtree<2, MAX_CHILDREN, USER_DATA>& bbox)
    {
        if (inside(a, bbox) || inside(b, bbox))
            return 0;

        const auto& bounds = bbox.bounds();
        auto minX = bounds[0];
        auto minY = bounds[1];
        auto maxX = bounds[2];
        auto maxY = bounds[3];

        auto d1 = sqSegSegDist(a[0], a[1], b[0], b[1], minX, minY, maxX, minY);
        if (d1 == 0) return 0;

        auto d2 = sqSegSegDist(a[0], a[1], b[0], b[1], minX, minY, minX, maxY);
        if (d2 == 0) return 0;

        auto d3 = sqSegSegDist(a[0], a[1], b[0], b[1], maxX, minY, maxX, maxY);
        if (d3 == 0) return 0;

        auto d4 = sqSegSegDist(a[0], a[1], b[0], b[1], minX, maxY, maxX, maxY);
        if (d4 == 0) return 0;

        return std::min(std::min(d1, d2), std::min(d3, d4));
    }

    template<int MAX_CHILDREN, class USER_DATA>
    inline bool inside(const AcGePoint3d& a, const rtree<2, MAX_CHILDREN, USER_DATA>& bbox)
    {
        auto& bounds = bbox.bounds();
        auto res =
            (a[0] >= bounds[0]) &&
            (a[0] <= bounds[2]) &&
            (a[1] >= bounds[1]) &&
            (a[1] <= bounds[3]);
        return res;
    }

    // check if the edge (a,b) doesn't intersect any other edges
    template<int MAX_CHILDREN>
    bool noIntersections(const std::vector<AcGePoint3d>& points, const AcGePoint3d& a, const AcGePoint3d& b, const rtree<2, MAX_CHILDREN, typename CircularElement<Node>::ptr_type>& segTree)
    {
        const auto& isect = segTree.intersection(
            {
                std::min(a[0], b[0]),
                std::min(a[1], b[1]),
                std::max(a[0], b[0]),
                std::max(a[1], b[1])
            });

        for (decltype(segTree)& ch : isect)
        {
            const auto& elem = ch.data();
            if (intersects(points[elem->data().p], points[elem->next()->data().p], a, b))
                return false;
        }

        return true;
    }
}// end namespace

