from __future__ import annotations

from pyrx import Db, Ge


class TestDbLine:
    
    def test_property_ids(self):
        line = Db.Line(Ge.Point3d(0,0,0), Ge.Point3d(100,0,0))
        assert line.length() == 100
        
    def test_line_creation(self):
        line = Db.Line()
        start_point = Ge.Point3d(0, 0, 0)
        end_point = Ge.Point3d(100, 0, 0)
        line.setStartPoint(start_point)
        line.setEndPoint(end_point)
        assert line.startPoint() == start_point
        assert line.endPoint() == end_point
        assert line.length() == 100
        
    def test_line_creation_with_start_and_end_points(self):
        start_point = Ge.Point3d(0, 0, 0)
        end_point = Ge.Point3d(100, 0, 0)
        line = Db.Line(start_point, end_point)
        
        assert line.startPoint() == start_point
        assert line.endPoint() == end_point
        assert line.length() == 100
        
    def test_line_normal_vector(self):
        start_point = Ge.Point3d(0, 0, 0)
        end_point = Ge.Point3d(100, 0, 0)
        line = Db.Line(start_point, end_point)
        
        # Default normal vector should be (0, 0, 1) for XY plane
        expected_normal = Ge.Vector3d(0, 0, 1)
        assert line.normal() == expected_normal
        
    def test_line_midpoint(self):
        start_point = Ge.Point3d(0, 0, 0)
        end_point = Ge.Point3d(100, 0, 0)
        line = Db.Line(start_point, end_point)
        
        expected_midpoint = Ge.Point3d(50, 0, 0)
        assert line.midPoint() == expected_midpoint
        
    def test_line_direction(self):
        start_point = Ge.Point3d(0, 0, 0)
        end_point = Ge.Point3d(100, 0, 0)
        line = Db.Line(start_point, end_point)
        
        expected_direction = end_point - start_point
        assert line.direction() == expected_direction
        
    def test_line_thickness(self):
        start_point = Ge.Point3d(0, 0, 0)
        end_point = Ge.Point3d(100, 0, 0)
        line = Db.Line(start_point, end_point)
        
        # Default thickness should be 0
        assert line.thickness() == 0
        
    def test_line_set_thickness(self):
        start_point = Ge.Point3d(0, 0, 0)
        end_point = Ge.Point3d(100, 0, 0)
        line = Db.Line(start_point, end_point)
        
        new_thickness = 5.0
        line.setThickness(new_thickness)
        assert line.thickness() == new_thickness
        
    def test_line_set_start_point(self):
        start_point = Ge.Point3d(0, 0, 0)
        end_point = Ge.Point3d(100, 0, 0)
        line = Db.Line(start_point, end_point)
        
        new_start_point = Ge.Point3d(-100, 0, 0)
        line.setStartPoint(new_start_point)
        
        assert line.startPoint() == new_start_point
        assert line.length() == 200
        
    def test_line_set_end_point(self):
        start_point = Ge.Point3d(0, 0, 0)
        end_point = Ge.Point3d(100, 0, 0)
        line = Db.Line(start_point, end_point)
        
        new_end_point = Ge.Point3d(200, 0, 0)
        line.setEndPoint(new_end_point)
        
        assert line.endPoint() == new_end_point
        assert line.length() == 200
        
    def test_line_set_normal(self):
        start_point = Ge.Point3d(0, 0, 0)
        end_point = Ge.Point3d(100, 0, 0)
        line = Db.Line(start_point, end_point)
        
        new_normal = Ge.Vector3d(0, 1, 0)  # Y-axis normal
        line.setNormal(new_normal)
        
        assert line.normal() == new_normal
        
    def test_line_get_acge_curve(self):
        start_point = Ge.Point3d(0, 0, 0)
        end_point = Ge.Point3d(100, 0, 0)
        line = Db.Line(start_point, end_point)
        acge_curve = line.getAcGeCurve()
        assert acge_curve.type() == Ge.EntityId.kLineSeg3d
        assert acge_curve.startPoint() == start_point
        assert acge_curve.endPoint() == end_point
        
    def test_line_class_name(self):
        class_name = Db.Line.className()
        assert class_name == "AcDbLine"
        
    def test_line_get_offset_curves_given_plane_normal(self):
        """Test that getOffsetCurvesGivenPlaneNormal can be called without exceptions"""
        start_point = Ge.Point3d(0, 0, 0)
        end_point = Ge.Point3d(100, 0, 0)
        line = Db.Line(start_point, end_point)
        
        # Test with a normal vector and offset distance
        normal_vector = Ge.Vector3d(0, 0, 1)  # Z-axis normal
        offset_distance = 10.0
        
        # This should not raise any exceptions
        result = line.getOffsetCurvesGivenPlaneNormal(normal_vector, offset_distance)
        
        # The method returns a list of curves (may be empty or contain new curve objects)
        assert isinstance(result, list)
        
    def test_line_get_offset_curves(self):
        """Test that getOffsetCurves can be called without exceptions"""
        start_point = Ge.Point3d(0, 0, 0)
        end_point = Ge.Point3d(100, 0, 0)
        line = Db.Line(start_point, end_point)
        offset_distance = 10.0
        result = line.getOffsetCurves(offset_distance)
        assert isinstance(result, list)
        assert len(result) > 0
        crv =  result[0]
        assert crv.getDistAtParam(crv.getEndParam()) == 100
        
