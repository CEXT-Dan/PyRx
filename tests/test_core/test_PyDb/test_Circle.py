from __future__ import annotations

from pyrx import Db, Ge

class TestDbCircle:
    def test_create(self):
        """Test constructor with center, normal, and radius"""
        circle = Db.Circle(Ge.Point3d(0, 0, 0), Ge.Vector3d.kZAxis, 10)
        assert circle.center() == Ge.Point3d(0, 0, 0)
        assert circle.radius() == 10
        assert circle.normal() == Ge.Vector3d.kZAxis

    def test_create_with_object_id(self):
        """Test constructor with object ID (placeholder - actual implementation depends on context)"""
        # This would require a valid ObjectId which is typically created within an AutoCAD session
        # For testing purposes, we'll just verify the method signature can be called
        pass  # Actual implementation requires access to active document

    def test_center(self):
        """Test center property getter and setter"""
        circle = Db.Circle(Ge.Point3d(0, 0, 0), Ge.Vector3d.kZAxis, 10)
        
        # Test initial center
        assert circle.center() == Ge.Point3d(0, 0, 0)
        
        # Test setting new center
        new_center = Ge.Point3d(5, 5, 0)
        circle.setCenter(new_center)
        assert circle.center() == new_center

    def test_radius(self):
        """Test radius property getter and setter"""
        circle = Db.Circle(Ge.Point3d(0, 0, 0), Ge.Vector3d.kZAxis, 10)
        
        # Test initial radius
        assert circle.radius() == 10
        
        # Test setting new radius
        new_radius = 15.0
        circle.setRadius(new_radius)
        assert circle.radius() == new_radius

    def test_normal(self):
        """Test normal property getter and setter"""
        circle = Db.Circle(Ge.Point3d(0, 0, 0), Ge.Vector3d.kZAxis, 10)
        
        # Test initial normal
        assert circle.normal() == Ge.Vector3d.kZAxis
        
        # Test setting new normal
        new_normal = Ge.Vector3d.kYAxis
        circle.setNormal(new_normal)
        assert circle.normal() == new_normal

    def test_diameter(self):
        """Test diameter property getter and setter"""
        circle = Db.Circle(Ge.Point3d(0, 0, 0), Ge.Vector3d.kZAxis, 10)
        
        # Test initial diameter
        assert circle.diameter() == 20.0
        
        # Test setting new diameter
        new_diameter = 30.0
        circle.setDiameter(new_diameter)
        assert circle.radius() == new_diameter / 2

    def test_circumference(self):
        """Test circumference property getter and setter"""
        circle = Db.Circle(Ge.Point3d(0, 0, 0), Ge.Vector3d.kZAxis, 10)
        
        # Test initial circumference
        expected_circumference = 2 * 3.141592653589793 * 10
        assert abs(circle.circumference() - expected_circumference) < 1e-10
        
        # Test setting new circumference (will adjust radius)
        new_circumference = 62.83185307179586  # 2 * pi * 10
        circle.setCircumference(new_circumference)
        assert abs(circle.radius() - 10) < 1e-10

    def test_thickness(self):
        """Test thickness property getter and setter"""
        circle = Db.Circle(Ge.Point3d(0, 0, 0), Ge.Vector3d.kZAxis, 10)
        
        # Test initial thickness
        assert circle.thickness() == 0.0
        
        # Test setting new thickness
        new_thickness = 5.0
        circle.setThickness(new_thickness)
        assert circle.thickness() == new_thickness

    def test_class_name(self):
        """Test className static method"""
        class_name = Db.Circle.className()
        assert isinstance(class_name, str)
        assert len(class_name) > 0

    def test_desc(self):
        """Test desc static method (returns RxClass object)"""
        rx_class = Db.Circle.desc()
        # Just verify it returns something that looks like an RxClass
        assert rx_class is not None
        
    def test_clone_from(self):
        """Test cloneFrom static method (requires existing circle)"""
        original_circle = Db.Circle(Ge.Point3d(0, 0, 0), Ge.Vector3d.kZAxis, 10)
        
        # Test that it returns a Circle object
        cloned_circle = Db.Circle.cloneFrom(original_circle)
        assert isinstance(cloned_circle, Db.Circle)
