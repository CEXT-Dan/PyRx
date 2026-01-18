from __future__ import annotations

import pytest

from pyrx import Db, Ge

# Note, three point Arc is not in ARX, p1 might not be the start point if the Arc is computed
# by direction, as in this case

class TestDbCurve:
    
    def test_get_dist_at_param(self):
        """Test getDistAtParam method with proper tolerance"""
        arc = Db.Arc(Ge.Point3d(0, 0, 0), Ge.Point3d(50, 50, 0), Ge.Point3d(100, 0, 0))
        end_param = arc.getEndParam()
        distance = arc.getDistAtParam(end_param)
        
        expected_distance = 157.07963267948966
        assert abs(distance - expected_distance) < 1e-10
    
    def test_get_area(self):
        """Test getArea method with proper tolerance"""
        arc = Db.Arc(Ge.Point3d(0, 0, 0), Ge.Point3d(50, 50, 0), Ge.Point3d(100, 0, 0))
        area = arc.getArea()
        expected_area = 3926.9908169872415
        assert abs(area - expected_area) < 1e-10
    
    def test_get_end_param(self):
        """Test getEndParam method"""
        arc = Db.Arc(Ge.Point3d(0, 0, 0), Ge.Point3d(50, 50, 0), Ge.Point3d(100, 0, 0))
        end_param = arc.getEndParam()
        assert isinstance(end_param, float)
    
    def test_get_start_param(self):
        """Test getStartParam method"""
        arc = Db.Arc(Ge.Point3d(0, 0, 0), Ge.Point3d(50, 50, 0), Ge.Point3d(100, 0, 0))
        start_param = arc.getStartParam()
        assert isinstance(start_param, float)
    
    def test_get_end_point(self):
        """Test getEndPoint method"""
        arc = Db.Arc(Ge.Point3d(0, 0, 0), Ge.Point3d(50, 50, 0), Ge.Point3d(100, 0, 0))
        end_point = arc.getEndPoint()
        expected_end = Ge.Point3d(0, 0, 0)
        assert expected_end == end_point
    
    def test_get_start_point(self):
        """Test getStartPoint method"""
        arc = Db.Arc(Ge.Point3d(0, 0, 0), Ge.Point3d(50, 50, 0), Ge.Point3d(100, 0, 0))
        start_point = arc.getStartPoint()
        expected_start = Ge.Point3d(100, 0, 0)
        assert start_point == expected_start
    
    def test_is_closed(self):
        """Test isClosed method for an Arc (should be False)"""
        arc = Db.Arc(Ge.Point3d(0, 0, 0), Ge.Point3d(50, 50, 0), Ge.Point3d(100, 0, 0))
        assert not arc.isClosed()
    
    def test_get_point_at_param(self):
        """Test getPointAtParam method with proper tolerance"""
        arc = Db.Arc(Ge.Point3d(0, 0, 0), Ge.Point3d(50, 50, 0), Ge.Point3d(100, 0, 0))
        start_param = arc.getStartParam()
        end_param = arc.getEndParam()
        
        # Test start point
        start_point = arc.getPointAtParam(start_param)
        expected_start = Ge.Point3d(100, 0, 0)
        assert expected_start == start_point
        
        # Test end point
        end_point = arc.getPointAtParam(end_param)
        expected_end = Ge.Point3d(0, 0, 0)
        assert end_point == expected_end
    
    def test_get_param_at_point(self):
        """Test getParamAtPoint method with proper tolerance"""
        arc = Db.Arc(Ge.Point3d(0, 0, 0), Ge.Point3d(50, 50, 0), Ge.Point3d(100, 0, 0))
        start_param = arc.getStartParam()
        
        # Test with start point
        param_at_start = arc.getParamAtPoint(Ge.Point3d(100, 0, 0))
        assert param_at_start == start_param
    
    def test_get_point_at_dist(self):
        """Test getPointAtDist method"""
        arc = Db.Arc(Ge.Point3d(0, 0, 0), Ge.Point3d(50, 50, 0), Ge.Point3d(100, 0, 0))
        end_param = arc.getEndParam()
        total_length = arc.getDistAtParam(end_param)
        
        # Test with half the length
        half_length = total_length / 2.0
        point_at_half = arc.getPointAtDist(half_length)
        assert isinstance(point_at_half, Ge.Point3d)
    
    def test_get_dist_at_point(self):
        """Test getDistAtPoint method"""
        arc = Db.Arc(Ge.Point3d(0, 0, 0), Ge.Point3d(50, 50, 0), Ge.Point3d(100, 0, 0))
        
        # Test with start point
        dist_start = arc.getDistAtPoint(Ge.Point3d(0, 0, 0))
        assert abs(dist_start - 157.07963267948966) < 1e-10
    
    def test_get_first_deriv(self):
        """Test getFirstDeriv method"""
        arc = Db.Arc(Ge.Point3d(0, 0, 0), Ge.Point3d(50, 50, 0), Ge.Point3d(100, 0, 0))
        start_param = arc.getStartParam()
        
        # Get derivative at start
        deriv = arc.getFirstDeriv(start_param)
        assert isinstance(deriv, Ge.Vector3d)
    
    def test_get_second_deriv(self):
        """Test getSecondDeriv method"""
        arc = Db.Arc(Ge.Point3d(0, 0, 0), Ge.Point3d(50, 50, 0), Ge.Point3d(100, 0, 0))
        start_param = arc.getStartParam()
        
        # Get second derivative at start
        deriv = arc.getSecondDeriv(start_param)
        assert isinstance(deriv, Ge.Vector3d)
    
    def test_is_periodic(self):
        """Test isPeriodic method for an Arc (should be False)"""
        arc = Db.Arc(Ge.Point3d(0, 0, 0), Ge.Point3d(50, 50, 0), Ge.Point3d(100, 0, 0))
        assert not arc.isPeriodic()
    
    def test_get_ac_ge_curve(self):
        """Test getAcGeCurve method"""
        arc = Db.Arc(Ge.Point3d(0, 0, 0), Ge.Point3d(50, 50, 0), Ge.Point3d(100, 0, 0))
        
        # Should return a curve object
        ac_ge_curve = arc.getAcGeCurve()
        assert ac_ge_curve is not None
    
    def test_get_closest_point_to(self):
        """Test getClosestPointTo method"""
        arc = Db.Arc(Ge.Point3d(0, 0, 0), Ge.Point3d(50, 50, 0), Ge.Point3d(100, 0, 0))
        
        # Test with a point near the curve
        test_point = Ge.Point3d(25, 25, 0)
        closest_point = arc.getClosestPointTo(test_point)
        assert isinstance(closest_point, Ge.Point3d)
