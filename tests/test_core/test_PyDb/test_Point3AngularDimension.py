from __future__ import annotations
from pyrx import Db, Ge
import math

class TestDbPoint3AngularDimension:
    
    def create_Point3AngularDimension_1(self):
        """
        Test basic instantiation and getter methods.
        """
        vertex = Ge.Point3d(5.0, 5.0, 0.0)
        firstPoint = Ge.Point3d(10.0, 5.0, 0.0)
        secondPoint = Ge.Point3d(5.0, 10.0, 0.0)
        arcPoint = Ge.Point3d(7.5, 7.5, 0.0)
        
        # Note: The constructor signature in the docs uses 'arcPnt' as the 4th argument
        pDim = Db.Point3AngularDimension(vertex, firstPoint, secondPoint, arcPoint)
        
        assert pDim.centerPoint() == vertex
        assert pDim.xLine1Point() == firstPoint
        assert pDim.xLine2Point() == secondPoint
        assert pDim.arcPoint() == arcPoint

    def create_Point3AngularDimension_with_text(self):
        """
        Test instantiation with custom dimension text.
        """
        vertex = Ge.Point3d(5.0, 5.0, 0.0)
        firstPoint = Ge.Point3d(10.0, 5.0, 0.0)
        secondPoint = Ge.Point3d(5.0, 10.0, 0.0)
        arcPoint = Ge.Point3d(7.5, 7.5, 0.0)
        
        customText = "45%%d"
        pDim = Db.Point3AngularDimension(vertex, firstPoint, secondPoint, arcPoint, customText)
        
        assert pDim.centerPoint() == vertex
        assert pDim.xLine1Point() == firstPoint
        assert pDim.xLine2Point() == secondPoint
        assert pDim.text() == customText

    def test_setter_methods(self):
        """
        Test the mutator methods for geometry points.
        """
        vertex = Ge.Point3d(0.0, 0.0, 0.0)
        firstPoint = Ge.Point3d(10.0, 0.0, 0.0)
        secondPoint = Ge.Point3d(0.0, 10.0, 0.0)
        arcPoint = Ge.Point3d(5.0, 5.0, 0.0)
        
        pDim = Db.Point3AngularDimension(vertex, firstPoint, secondPoint, arcPoint)
        
        # Define new points
        newVertex = Ge.Point3d(1.0, 1.0, 0.0)
        newFirst = Ge.Point3d(11.0, 1.0, 0.0)
        newSecond = Ge.Point3d(1.0, 11.0, 0.0)
        newArc = Ge.Point3d(6.0, 6.0, 0.0)
        
        pDim.setCenterPoint(newVertex)
        pDim.setXLine1Point(newFirst)
        pDim.setXLine2Point(newSecond)
        pDim.setArcPoint(newArc)
        
        assert pDim.centerPoint() == newVertex
        assert pDim.xLine1Point() == newFirst
        assert pDim.xLine2Point() == newSecond
        assert pDim.arcPoint() == newArc

    def test_extension_arc_toggle(self):
        """
        Test the toggle for the extension arc.
        """
        vertex = Ge.Point3d(5.0, 5.0, 0.0)
        firstPoint = Ge.Point3d(10.0, 5.0, 0.0)
        secondPoint = Ge.Point3d(5.0, 10.0, 0.0)
        arcPoint = Ge.Point3d(7.5, 7.5, 0.0)
        
        pDim = Db.Point3AngularDimension(vertex, firstPoint, secondPoint, arcPoint)
        
        # Initially, check if arc is on (default behavior usually assumes it is on)
        # Note: The docstring says "Returns true if extension arc is on"
        assert isinstance(pDim.extArcOn(), (bool, int))
        
        # Turn off the extension arc
        pDim.setExtArcOn(False)
        assert pDim.extArcOn() is False
        
        # Turn it back on
        pDim.setExtArcOn(True)
        assert pDim.extArcOn() is True

    def test_format_measurement(self):
        """
        Test formatting the measurement value.
        """
        vertex = Ge.Point3d(5.0, 5.0, 0.0)
        firstPoint = Ge.Point3d(10.0, 5.0, 0.0)
        secondPoint = Ge.Point3d(5.0, 10.0, 0.0)
        arcPoint = Ge.Point3d(7.5, 7.5, 0.0)
        
        pDim = Db.Point3AngularDimension(vertex, firstPoint, secondPoint, arcPoint)
        
        # Format a measurement value (converted to radians)
        formatted = pDim.formatMeasurement(math.radians(45.0))
        
        # The result should be a string containing the formatted number
        assert isinstance(formatted, str)
        
        # Check if the number 45 is in the string (formatting might add decimals or units)
        assert "45" in formatted
