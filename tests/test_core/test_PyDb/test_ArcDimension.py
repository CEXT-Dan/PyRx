from __future__ import annotations
from pyrx import Db, Ge

class TestDbArcDimension:
    
    def test_create_1(self):
        """Tests the basic constructor with center, xLines, and arc point."""
        center = Ge.Point3d(0.0, 0.0, 0.0) # center
        xLine1 = Ge.Point3d(5.0, 0.0, 0.0); # Start of arc segment
        xLine2 = Ge.Point3d(3.53, 3.53, 0.0); # End of arc segment
        arcPoint = Ge.Point3d(0.0, 6.0, 0.0); # Location of the dimension line
        
        dim = Db.ArcDimension(center, xLine1, xLine2, arcPoint)
        
        assert dim.centerPoint() == center
        assert dim.xLine1Point() == xLine1
        assert dim.xLine2Point() == xLine2
        assert dim.arcPoint() == arcPoint

    def test_create_with_text(self):
        """Tests constructor with dimension text."""
        center = Ge.Point3d(0.0, 0.0, 0.0)
        xLine1 = Ge.Point3d(5.0, 0.0, 0.0)
        xLine2 = Ge.Point3d(3.53, 3.53, 0.0)
        arcPoint = Ge.Point3d(0.0, 6.0, 0.0)
        dimText = "TEST DIM"
        
        dim = Db.ArcDimension(center, xLine1, xLine2, arcPoint, dimText)
        
        # Verify object creation
        assert dim is not None


    def test_arc_parameters(self):
        """Tests arc start/end parameters."""
        center = Ge.Point3d(0.0, 0.0, 0.0)
        xLine1 = Ge.Point3d(5.0, 0.0, 0.0)
        xLine2 = Ge.Point3d(3.53, 3.53, 0.0)
        arcPoint = Ge.Point3d(0.0, 6.0, 0.0)
        
        dim = Db.ArcDimension(center, xLine1, xLine2, arcPoint)
        
        # Set parameters
        start_param = 0.5
        end_param = 1.0
        
        dim.setArcStartParam(start_param)
        dim.setArcEndParam(end_param)
        
        # Get parameters
        assert dim.arcStartParam() == start_param
        assert dim.arcEndParam() == end_param

    def test_arc_symbol_type(self):
        """Tests setting and getting the arc symbol type."""
        center = Ge.Point3d(0.0, 0.0, 0.0)
        xLine1 = Ge.Point3d(5.0, 0.0, 0.0)
        xLine2 = Ge.Point3d(3.53, 3.53, 0.0)
        arcPoint = Ge.Point3d(0.0, 6.0, 0.0)
        
        dim = Db.ArcDimension(center, xLine1, xLine2, arcPoint)
        
        # 0: Precedes text, 1: Above text, 2: No symbol
        symbol_type = 1
        dim.setArcSymbolType(symbol_type)
        
        assert dim.arcSymbolType() == symbol_type

    def test_has_leader(self):
        """Tests leader functionality."""
        center = Ge.Point3d(0.0, 0.0, 0.0)
        xLine1 = Ge.Point3d(5.0, 0.0, 0.0)
        xLine2 = Ge.Point3d(3.53, 3.53, 0.0)
        arcPoint = Ge.Point3d(0.0, 6.0, 0.0)
        
        dim = Db.ArcDimension(center, xLine1, xLine2, arcPoint)
        
        # Initially should be False
        assert dim.hasLeader() == False
        
        # Set to True
        dim.setHasLeader(True)
        assert dim.hasLeader() == True
        
        # Set to False
        dim.setHasLeader(False)
        assert dim.hasLeader() == False

    def test_extension_lines(self):
        """Tests extension line points."""
        center = Ge.Point3d(0.0, 0.0, 0.0)
        xLine1 = Ge.Point3d(5.0, 0.0, 0.0)
        xLine2 = Ge.Point3d(3.53, 3.53, 0.0)
        arcPoint = Ge.Point3d(0.0, 6.0, 0.0)
        
        dim = Db.ArcDimension(center, xLine1, xLine2, arcPoint)
        
        new_xLine1 = Ge.Point3d(10.0, 0.0, 0.0)
        new_xLine2 = Ge.Point3d(0.0, 10.0, 0.0)
        
        dim.setXLine1Point(new_xLine1)
        dim.setXLine2Point(new_xLine2)
        
        assert dim.xLine1Point() == new_xLine1
        assert dim.xLine2Point() == new_xLine2

    def test_leaders(self):
        """Tests extra leader points."""
        center = Ge.Point3d(0.0, 0.0, 0.0)
        xLine1 = Ge.Point3d(5.0, 0.0, 0.0)
        xLine2 = Ge.Point3d(3.53, 3.53, 0.0)
        arcPoint = Ge.Point3d(0.0, 6.0, 0.0)
        dim = Db.ArcDimension(center, xLine1, xLine2, arcPoint)

        # Set leader points
        l1 = Ge.Point3d(0.0, 10.0, 0.0)
        l2 = Ge.Point3d(0.0, 15.0, 0.0)
        
        dim.setLeader1Point(l1)
        dim.setLeader2Point(l2)
        
        assert dim.leader1Point() == l1
        assert dim.leader2Point() == l2

    def test_center_point(self):
        """Tests center point setter."""
        center = Ge.Point3d(0.0, 0.0, 0.0)
        xLine1 = Ge.Point3d(5.0, 0.0, 0.0)
        xLine2 = Ge.Point3d(3.53, 3.53, 0.0)
        arcPoint = Ge.Point3d(0.0, 6.0, 0.0)
        
        dim = Db.ArcDimension(center, xLine1, xLine2, arcPoint)
        
        new_center = Ge.Point3d(10.0, 10.0, 0.0)
        
        dim.setCenterPoint(new_center)
        
        assert dim.centerPoint() == new_center
