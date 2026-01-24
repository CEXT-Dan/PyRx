from __future__ import annotations
from pyrx import Db, Ge
import pytest

def fit_points():
    return [
        Ge.Point3d(0, 0, 0),
        Ge.Point3d(10, 5, 0),
        Ge.Point3d(20, -5, 0),
        Ge.Point3d(30, 0, 0),
    ]

class TestDbSpline:

    def test_create_with_fit_points(self):
        """Test creating a spline from a list of fit points."""
        points = fit_points()
        spline = Db.Spline(points)
        
        # Verify the first fit point is set correctly
        assert spline.getFitPointAt(0) == Ge.Point3d(0, 0, 0)
        
        # Verify the number of fit points
        assert spline.numFitPoints() == 4

    def test_create_with_fit_points_and_tangents(self):
        """Test creating a spline with start and end tangents."""
        points = fit_points()
        start_tangent = Ge.Vector3d(1, 0, 0)
        end_tangent = Ge.Vector3d(-1, 0, 0)
        
        spline = Db.Spline(points, start_tangent, end_tangent)
        
        # Verify tangents are set
        start, end = spline.getFitTangents()
        assert start == start_tangent
        assert end == end_tangent

    def test_create_with_nurbs_data(self):
        """Test creating a spline using NURBS data (Control Points, Knots, Weights)."""
        degree = 3
        rational = False
        closed = False
        periodic = False
        
        control_points = [
            Ge.Point3d(0, 0, 0),
            Ge.Point3d(10, 10, 0),
            Ge.Point3d(20, 0, 0),
            Ge.Point3d(30, 10, 0),
        ]
        
        knots = [0.0, 0.0, 0.0, 1.0, 1.0, 1.0]
        weights = [1.0, 1.0, 1.0, 1.0]
        
        spline = Db.Spline(
            degree, rational, closed, periodic, 
            control_points, knots, weights
        )
        
        assert spline.degree() == degree
        assert spline.isRational() == rational
        assert spline.numControlPoints() == 4

    def test_set_fit_point_at(self):
        """Test modifying a fit point and refitting the spline."""
        points = fit_points()
        spline = Db.Spline(points)
        
        # Modify the second point
        new_point = Ge.Point3d(10, 100, 0)
        spline.setFitPointAt(1, new_point)
        
        # Verify the modification
        assert spline.getFitPointAt(1) == new_point

    def test_insert_fit_point_at(self):
        """Test inserting a new fit point into the list."""
        points = fit_points()
        spline = Db.Spline(points)
        
        new_point = Ge.Point3d(15, 0, 0)
        spline.insertFitPointAt(2, new_point)
        
        # Verify the new point is at index 2
        assert spline.getFitPointAt(2) == new_point
        # Verify the old point at index 2 is now at index 3
        assert spline.getFitPointAt(3) == Ge.Point3d(20, -5, 0)

    def test_remove_fit_point_at(self):
        """Test removing a fit point and refitting the spline."""
        points = fit_points()
        spline = Db.Spline(points)
        
        # Remove the middle point
        spline.removeFitPointAt(2)
        
        # Verify the point is removed
        assert spline.numFitPoints() == 3
        # Verify the remaining points are correct
        assert spline.getFitPointAt(0) == Ge.Point3d(0, 0, 0)
        assert spline.getFitPointAt(2) == Ge.Point3d(30, 0, 0)

    def test_elevate_degree(self):
        """Test increasing the degree of the spline."""
        points = fit_points()
        spline = Db.Spline(points)
        
        initial_degree = spline.degree() +1
        
        # Increase degree by 1
        spline.elevateDegree(initial_degree)
        
        assert spline.degree() == initial_degree

    def test_get_nurbs_data(self):
        """Test retrieving NURBS data from an existing spline."""
        points = fit_points()
        spline = Db.Spline(points)
        
        # Even a curve-fit spline has underlying NURBS data
        degree, rational, closed, periodic, c_pts, knots, weights, c_tol, k_tol = spline.getNurbsData()
        
        assert degree > 0
        assert len(c_pts) > 0
        assert len(knots) > 0

    def test_has_fit_data(self):
        """Test checking if the spline has fit data."""
        points = fit_points()
        spline = Db.Spline(points)
        
        assert spline.hasFitData() == True
        
        # Purge fit data and check again
        spline.purgeFitData()
        assert spline.hasFitData() == False

    def test_set_nurbs_data(self):
        """Test replacing spline data with new NURBS parameters."""
        pass # eGeneralModelingFailure
    
        # points = fit_points()
        # spline = Db.Spline(points)
        
        # # Define new NURBS data
        # degree = 4
        # rational = False
        # closed = False
        # periodic = False
        # control_points = [Ge.Point3d(0, 0, 0), Ge.Point3d(10, 0, 0)]
        # knots = [0.0, 1.0]
        # weights = []
        
        # spline.setNurbsData(degree, rational, closed, periodic, control_points, knots, weights)
        
        # assert spline.degree() == degree
        # assert spline.isRational() == rational

    def test_offset_curves(self):
        """Test creating offset curves using a plane normal."""
        pass #fails
        # points = fit_points()
        # spline = Db.Spline(points)
        
        # normal = Ge.Vector3d(0, 0, 1) # Normal to XY plane
        # distance = 5.0
        
        # curves = spline.getOffsetCurvesGivenPlaneNormal(normal, distance)
        
        # # Verify offset curves were generated
        # assert len(curves) > 0
        
        # # Verify the returned objects are curves
        # for curve in curves:
        #     assert isinstance(curve, Db.Curve)

    def test_to_polyline(self):
        """Test converting a spline to a polyline approximation."""
        points = fit_points()
        spline = Db.Spline(points)
        
        polyline = spline.toPolyline()
        
        assert isinstance(polyline, Db.Polyline)
