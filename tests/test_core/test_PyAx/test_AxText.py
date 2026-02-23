from __future__ import annotations

import pytest
import math

from pyrx import Ap, Ge, Ax


class TestAcadText:

    def setup_class(self):
        # Initialize the AutoCAD application and document
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def test_create_text(self):
        """Test creating a new text entity."""
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addText("HELLO", Ge.Point3d(0, 0, 0), 1.0)

        # Verify object type
        assert ent.objectName() == "AcDbText"

        # Verify basic properties
        assert ent.textString() == "HELLO"
        assert ent.height() == 1.0
        assert ent.insertionPoint() == Ge.Point3d(0, 0, 0)

    def test_modify_text_string(self):
        """Test modifying the text string."""
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addText("OLD", Ge.Point3d(0, 0, 0), 1.0)

        ent.setTextString("NEW")
        assert ent.textString() == "NEW"

    def test_modify_height(self):
        """Test modifying the text height."""
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addText("TEST", Ge.Point3d(0, 0, 0), 1.0)

        ent.setHeight(2.5)
        assert ent.height() == 2.5

    def test_modify_rotation(self):
        """Test modifying the rotation angle."""
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addText("TEST", Ge.Point3d(0, 0, 0), 1.0)

        ent.setRotation(math.radians(45.0))
        assert ent.rotation() ==math.radians(45.0)

    def test_modify_oblique_angle(self):
        """Test modifying the oblique angle."""
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addText("TEST", Ge.Point3d(0, 0, 0), 1.0)

        ent.setObliqueAngle(math.radians(15.0))
        assert ent.obliqueAngle() == math.radians(15.0)

    def test_modify_scale_factor(self):
        """Test modifying the scale factor."""
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addText("TEST", Ge.Point3d(0, 0, 0), 1.0)

        ent.setScaleFactor(1.5)
        assert ent.scaleFactor() == 1.5

    def test_modify_thickness(self):
        """Test modifying the thickness."""
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addText("TEST", Ge.Point3d(0, 0, 0), 1.0)

        ent.setThickness(0.5)
        assert ent.thickness() == 0.5

    def test_modify_insertion_point(self):
        """Test modifying the insertion point."""
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addText("TEST", Ge.Point3d(0, 0, 0), 1.0)

        new_point = Ge.Point3d(10, 10, 0)
        ent.setInsertionPoint(new_point)
        assert ent.insertionPoint() == new_point

    def test_modify_normal_vector(self):
        """Test modifying the normal vector (defines the plane of the text)."""
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addText("TEST", Ge.Point3d(0, 0, 0), 1.0)

        # Set normal to Z-axis (0, 0, 1)
        normal_vec = Ge.Vector3d(0, 0, 1)
        ent.setNormal(normal_vec)
        assert ent.normal() == normal_vec

    def test_modify_alignment(self):
        """Test modifying horizontal and vertical alignment."""
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addText("TEST", Ge.Point3d(0, 0, 0), 1.0)

        # Set horizontal alignment to Center
        ent.setHorizontalAlignment(Ax.AcHorizontalAlignment.acHorizontalAlignmentCenter)
        assert (
            ent.horizontalAlignment()
            == Ax.AcHorizontalAlignment.acHorizontalAlignmentCenter
        )

        # Set vertical alignment to Middle
        ent.setVerticalAlignment(Ax.AcVerticalAlignment.acVerticalAlignmentMiddle)
        assert (
            ent.verticalAlignment() == Ax.AcVerticalAlignment.acVerticalAlignmentMiddle
        )

    def test_modify_text_alignment_point(self):
        """Test setting the text alignment point (where the text is anchored)."""
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addText("TEST", Ge.Point3d(0, 0, 0), 1.0)
        
        # must not be acAlignmentLeft
        ent.setAlignment(Ax.AcAlignment.acAlignmentRight)

        # Set a specific alignment point
        align_point = Ge.Point3d(5, 5, 0)
        ent.setTextAlignmentPoint(align_point)
        assert ent.textAlignmentPoint() == align_point

    def test_modify_style_name(self):
        """Test modifying the text style name."""
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addText("TEST", Ge.Point3d(0, 0, 0), 1.0)

        # Note: This test assumes a style named "Standard" exists in the drawing
        # If not, you might need to create it or skip this test
        try:
            ent.setStyleName("Standard")
            assert ent.styleName() == "Standard"
        except Exception:
            pytest.skip("Standard text style not found in drawing")

    def test_generation_flags(self):
        """Test setting text generation flags (Upside Down, Backward)."""
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addText("TEST", Ge.Point3d(0, 0, 0), 1.0)

        # Set Upside Down
        ent.setUpsideDown(True)
        assert ent.upsideDown() is True

        # Set Backward
        ent.setBackward(True)
        assert ent.backward() is True

    def test_text_generation_flag(self):
        """Test setting the text generation flag (Bitwise)."""
        axSpace = self.axDoc.modelSpace()
        ent = axSpace.addText("TEST", Ge.Point3d(0, 0, 0), 1.0)

        flag = 2 #mirrored in X
        ent.setTextGenerationFlag(flag)
        assert ent.textGenerationFlag() == flag
