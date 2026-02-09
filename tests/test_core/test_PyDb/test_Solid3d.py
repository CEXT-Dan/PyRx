from __future__ import annotations

from pyrx import Db, Ge


class TestDbSolid3d:
    
    def test_create_box(self):
        """Tests creating a standard box solid."""
        solid = Db.Solid3d()
        # Dimensions must be >= 1e-6
        solid.createBox(100, 100, 100)
        assert isinstance(solid, Db.Solid3d)

    def test_create_sphere(self):
        """Tests creating a sphere."""
        solid = Db.Solid3d()
        solid.createSphere(50.0)
        assert isinstance(solid, Db.Solid3d)

    def test_create_cylinder(self):
        """Tests creating a cylinder."""
        solid = Db.Solid3d()
        solid.createCylinder(100.0, 20.0)
        assert isinstance(solid, Db.Solid3d)


    def test_create_torus(self):
        """Tests creating a torus."""
        solid = Db.Solid3d()
        solid.createTorus(50.0, 10.0)
        assert isinstance(solid, Db.Solid3d)


    def test_boolean_operate_union(self):
        """Tests performing a Boolean Union operation."""
        solid1 = Db.Solid3d()
        solid1.createBox(100, 100, 100)
        
        solid2 = Db.Solid3d()
        solid2.createSphere(50.0)
        
        # Perform Union
        solid1.booleanOper(Db.BoolOperType.kBoolUnite, solid2)
        

    def test_boolean_operate_subtract(self):
        """Tests performing a Boolean Subtract operation."""
        solid1 = Db.Solid3d()
        solid1.createBox(100, 100, 100)
        
        solid2 = Db.Solid3d()
        solid2.createSphere(50.0)
        
        # Subtract solid2 from solid1
        solid1.booleanOper(Db.BoolOperType.kBoolSubtract, solid2)
        
    def test_get_area(self):
        """Tests retrieving the surface area of a solid."""
        solid = Db.Solid3d()
        solid.createBox(100, 100, 100)
        
        area = solid.getArea()
        
        # Area of a 100x100x100 box is 6 * 100 * 100 = 60000
        assert area == 60000.0

    def test_get_mass_properties(self):
        """Tests retrieving mass properties (Volume, Centroid, etc.)."""
        solid = Db.Solid3d()
        solid.createBox(100, 100, 100)
        
        props = solid.getMassProp()
        
        # props is a tuple. Based on standard AutoCAD API, 
        # index 0 is Volume, index 1 is Centroid.
        volume = props[0]
        centroid = props[1]
        
        assert volume == 1000000.0 # 100 * 100 * 100
        assert isinstance(centroid, Ge.Point3d)

    def test_check_interference(self):
        """Tests checking for interference between two solids."""
        solid1 = Db.Solid3d()
        solid1.createBox(100, 100, 100)
        
        solid2 = Db.Solid3d()
        solid2.createBox(50, 50, 50)
        
        # Place solid2 inside solid1
        solid2.transformBy(Ge.Matrix3d.translation(Ge.Vector3d(0, 0, 25)))
        
        # Check interference
        isInterfering, commonSolid = solid1.checkInterference(solid2, True)
        
        assert isInterfering == True
        # If interference exists and createNewSolid is True, commonSolid should not be null
        assert commonSolid is not None

