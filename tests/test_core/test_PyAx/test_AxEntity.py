from __future__ import annotations

import pytest

from pyrx import Ap, Ax, Ge

class TestAxEntity:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def test_trueColore(self):
        axSpace = self.axDoc.modelSpace()
        axColor = Ax.AcadAcCmColor(100, 100, 100)
        ent = axSpace.addLine(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 0, 0))
        ent.setTrueColor(axColor)
        axColor2 = ent.trueColor()
        assert axColor.red() == axColor2.red()
        assert axColor.green() == axColor2.green()
        assert axColor.blue() == axColor2.blue()

    @pytest.mark.known_failure_IRX
    def test_intersectWith(self):
        axSpace = self.axDoc.modelSpace()
        axLine1 = axSpace.addLine(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 100, 0))
        axLine2 = axSpace.addLine(Ge.Point3d(100, 0, 0), Ge.Point3d(0, 100, 0))
        axCircle = axSpace.addCircle(Ge.Point3d(50, 50, 0), 50)
        inters1 = axLine1.intersectWith(axLine2, Ax.AcExtendOption.acExtendNone)
        inters2 = axLine1.intersectWith(axCircle, Ax.AcExtendOption.acExtendNone)
        inters3 = axLine2.intersectWith(axCircle, Ax.AcExtendOption.acExtendNone)
        assert len(inters1) == 1
        assert inters1[0] == Ge.Point3d(50, 50, 0)
        assert len(inters2) == 2
        assert len(inters3) == 2
        assert inters2[0].distanceTo(inters2[1]) == 100.0
        assert inters3[0].distanceTo(inters3[1]) == 100.0
        
    @pytest.mark.known_failure_ZRX
    @pytest.mark.known_failure_GRX
    def test_arrayPolar(self):
        axSpace = self.axDoc.modelSpace()
        axEnt = axSpace.addCircle(Ge.Point3d(2,2,0),1)
        axEnts: list[Ax.AcadEntity]
        axEnts = axEnt.arrayPolar(4,3.14,Ge.Point3d(3,3,0))
        assert len(axEnts) == 3

    def test_layer(self):
        """Test getting and setting entity layer"""
        axSpace = self.axDoc.modelSpace()
        line = axSpace.addLine(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 0, 0))
        
        # Get default layer
        original_layer = line.layer()
        assert original_layer is not None
        
        # Set layer
        line.setLayer("0")
        assert line.layer() == "0"
        
    def test_linetype(self):
        """Test getting and setting entity linetype"""
        axSpace = self.axDoc.modelSpace()
        line = axSpace.addLine(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 0, 0))
        
        # Get default linetype
        original_linetype = line.linetype()
        assert original_linetype is not None
        
        # Set linetype
        line.setLinetype("Continuous")
        assert line.linetype() == "Continuous"
        
    def test_lineweight(self):
        """Test getting and setting entity lineweight"""
        axSpace = self.axDoc.modelSpace()
        line = axSpace.addLine(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 0, 0))
        
        # Get default lineweight
        original_weight = line.lineweight()
        assert original_weight is not None
        
        # Set lineweight
        line.setLineweight(Ax.AcLineWeight.acLnWt070)
        assert line.lineweight() == Ax.AcLineWeight.acLnWt070
        
    def test_entity_handle(self):
        """Test getting entity handle"""
        axSpace = self.axDoc.modelSpace()
        line = axSpace.addLine(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 0, 0))
        
        # Get entity handle
        handle = line.handle()
        assert handle is not None
        assert len(handle.toString()) > 0
        
    def test_entity_id(self):
        """Test getting entity name (unique identifier)"""
        axSpace = self.axDoc.modelSpace()
        line = axSpace.addLine(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 0, 0))
        
        # Get entity name
        ename = line.objectId()
        assert ename.isNull() is False
        
    def test_copy(self):
        """Test copying an entity"""
        axSpace = self.axDoc.modelSpace()
        line = axSpace.addLine(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 0, 0))
        
        # Get initial entity count
        initial_count = axSpace.count()
        
        # Copy the entity to another location using vector displacement
        copied_line = line.copy()
        assert copied_line is not None
        
    def test_entity_deletion(self):
        """Test deleting an entity"""
        axSpace = self.axDoc.modelSpace()
        line = axSpace.addLine(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 0, 0))
        
        # Get initial count
        initial_count = axSpace.count()
        
        # Delete the entity
        line.erase()
        
        # Verify count decreased
        assert axSpace.count() == initial_count - 1
        
    def test_get_bounding_box(self):
        """Test getting entity bounding box"""
        axSpace = self.axDoc.modelSpace()
        line = axSpace.addLine(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 100, 0))
        
        # Get bounding box
        minpoint, maxpoint = line.boundingBox()
        assert minpoint is not None
        assert maxpoint is not None
        assert isinstance(minpoint, Ge.Point3d)
        assert isinstance(maxpoint, Ge.Point3d)
        
    def test_offset(self):
        """Test offsetting an entity"""
        axSpace = self.axDoc.modelSpace()
        line = axSpace.addLine(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 0, 0))
        
        # Offset the line
        offset_entities = line.offset(10)
        assert len(offset_entities) > 0
        
    def test_highlight(self):
        """Test highlighting and unhighlighting an entity"""
        axSpace = self.axDoc.modelSpace()
        line = axSpace.addLine(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 0, 0))
        
        # Highlight
        line.highlight(True)
        
        # Unhighlight
        line.highlight(False)
        
    def test_entity_visible(self):
        """Test entity visibility property"""
        axSpace = self.axDoc.modelSpace()
        line = axSpace.addLine(Ge.Point3d(0, 0, 0), Ge.Point3d(100, 0, 0))
        
        # Check initial visibility
        original_visible = line.isVisible()
        assert isinstance(original_visible, bool)
        
        # Set visibility
        line.setVisible(False)
        assert line.isVisible() == False
        
        line.setVisible(True)
        assert line.isVisible() == True

