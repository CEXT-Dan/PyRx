from __future__ import annotations

from pyrx import Db, Ge


class TestDbPoint:
    
    def test_create_1(self):
        """Test creating a Point from a Ge.Point3d."""
        pos = Ge.Point3d(1, 2, 3)
        point = Db.Point(pos)
        assert point.position() == pos

    def test_create_2(self):
        """Test creating a Point with a specific thickness."""
        pos = Ge.Point3d(0, 0, 0)
        point = Db.Point(pos)
        
        # Set thickness
        point.setThickness(5.0)
        
        # Verify thickness
        assert point.thickness() == 5.0

    def test_create_3(self):
        """Test creating a Point with a specific normal vector."""
        pos = Ge.Point3d(0, 0, 0)
        normal = Ge.Vector3d(0, 1, 0) # Y-axis normal
        point = Db.Point(pos)
        
        # Set normal
        point.setNormal(normal)
        
        # Verify normal
        assert point.normal() == normal

    def test_create_4(self):
        """Test creating a Point with a specific ECS rotation."""
        pos = Ge.Point3d(0, 0, 0)
        point = Db.Point(pos)
        
        # Set rotation angle (radians)
        angle = 1.5708 # 90 degrees
        point.setEcsRotation(angle)
        
        # Verify rotation
        assert point.ecsRotation() == angle

    def test_set_position(self):
        """Test setting the position of an existing Point."""
        pos = Ge.Point3d(1, 2, 3)
        point = Db.Point(pos)
        
        new_pos = Ge.Point3d(10, 20, 30)
        point.setPosition(new_pos)
        
        assert point.position() == new_pos

    def test_set_normal(self):
        """Test setting the normal vector of an existing Point."""
        pos = Ge.Point3d(0, 0, 0)
        point = Db.Point(pos)
        
        new_normal = Ge.Vector3d(1, 0, 0) # X-axis normal
        point.setNormal(new_normal)
        
        assert point.normal() == new_normal

    def test_set_thickness(self):
        """Test setting the thickness of an existing Point."""
        pos = Ge.Point3d(0, 0, 0)
        point = Db.Point(pos)
        
        point.setThickness(10.5)
        
        assert point.thickness() == 10.5

    def test_set_ecs_rotation(self):
        """Test setting the ECS rotation of an existing Point."""
        pos = Ge.Point3d(0, 0, 0)
        point = Db.Point(pos)
        
        angle = 3.14159 # 180 degrees
        point.setEcsRotation(angle)
        
        assert point.ecsRotation() == angle
