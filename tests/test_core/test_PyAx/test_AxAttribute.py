from __future__ import annotations

import math
from pyrx import Ap, Ax, Ge


class TestAxAttribute:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def test_setMtext_attribute(self):
        """Tests setting an attribute to be an MText attribute."""
        axSpace = self.axDoc.modelSpace()

        # Create a standard attribute definition
        ent = axSpace.addAttribute(
            1,
            Ax.AcAttributeMode.acAttributeModeNormal,
            "prompt",
            Ge.Point3d(0, 0, 0),
            "tag",
            "value",
        )

        ent.setNormal(Ge.Vector3d.kYAxis)

        assert ent.objectName() == "AcDbAttributeDefinition"
        assert ent.isMTextAttribute() == False

        # Set the attribute to be an MText attribute
        ent.setIsMTextAttribute(True)

        assert ent.isMTextAttribute() == True
        assert ent.normal() == Ge.Vector3d.kYAxis

    def test_text_properties(self):
        """Tests setting standard text properties like height, rotation, and string."""
        axSpace = self.axDoc.modelSpace()

        ent = axSpace.addAttribute(
            2,
            Ax.AcAttributeMode.acAttributeModeNormal,
            "height_prompt",
            Ge.Point3d(10, 10, 0),
            "height_tag",
            "height_val",
        )

        # Set text properties
        ent.setTextString("Test String")
        ent.setHeight(5.0)
        ent.setRotation(math.radians(45.0))
        ent.setStyleName("Standard")

        # Verify properties
        assert ent.textString() == "Test String"
        assert ent.height() == 5.0
        assert ent.rotation() == math.radians(45.0)
        assert ent.styleName() == "Standard"

    def test_alignment_and_position(self):
        """Tests alignment points and alignment modes."""
        axSpace = self.axDoc.modelSpace()

        ent = axSpace.addAttribute(
            3,
            Ax.AcAttributeMode.acAttributeModeNormal,
            "align_prompt",
            Ge.Point3d(20, 20, 0),
            "align_tag",
            "align_val",
        )

        # must not be acAlignmentLeft
        ent.setAlignment(Ax.AcAlignment.acAlignmentRight)
        # Set alignment point
        point = Ge.Point3d(25, 25, 0)
        ent.setTextAlignmentPoint(point)

        # Verify alignment point
        assert ent.textAlignmentPoint() == point

    def test_mtext_specific_properties(self):
        """Tests properties specific to MText attributes."""
        axSpace = self.axDoc.modelSpace()

        ent = axSpace.addAttribute(
            4,
            Ax.AcAttributeMode.acAttributeModeNormal,
            "mtext_prompt",
            Ge.Point3d(30, 30, 0),
            "mtext_tag",
            "mtext_val",
        )

        # Set MText specific properties
        ent.setIsMTextAttribute(True)
        ent.setMTextAttributeContent("MText Content")
        ent.setMTextBoundaryWidth(10.0)

        # Verify MText properties
        assert ent.isMTextAttribute() == True
        assert ent.mtextAttributeContent() == "MText Content"
        assert ent.mtextBoundaryWidth() == 10.0

    def test_behavior_flags(self):
        """Tests boolean flags like constant (locked), invisible, and preset."""
        axSpace = self.axDoc.modelSpace()

        ent = axSpace.addAttribute(
            5,
            Ax.AcAttributeMode.acAttributeModeNormal,
            "flag_prompt",
            Ge.Point3d(40, 40, 0),
            "flag_tag",
            "flag_val",
        )

        # Set flags
        ent.setConstant(True)  # Lock the attribute
        ent.setInvisible(True)  # Hide the attribute
        ent.setPreset(True)  # Use preset value
        ent.setUpsideDown(True)

        # Verify flags
        assert ent.constant() == True
        assert ent.invisible() == True
        assert ent.preset() == True
        assert ent.upsideDown() == True

    def test_tag_and_prompt(self):
        """Tests setting and getting tag and prompt strings."""
        axSpace = self.axDoc.modelSpace()

        ent = axSpace.addAttribute(
            6,
            Ax.AcAttributeMode.acAttributeModeNormal,
            "new_prompt",
            Ge.Point3d(50, 50, 0),
            "new_tag",
            "new_val",
        )

        # Verify initial values
        assert ent.promptString() == "new_prompt"
        assert ent.tagString() == "new_tag"

        # Modify values
        ent.setPromptString("Updated Prompt")
        ent.setTagString("Updated Tag")

        # Verify modifications
        assert ent.promptString() == "Updated Prompt"
        assert ent.tagString() == "Updated Tag"

    def test_insertion_point(self):
        """Tests setting and retrieving the insertion point of an attribute."""
        axSpace = self.axDoc.modelSpace()

        # Create an attribute definition
        ent = axSpace.addAttribute(
            7,
            Ax.AcAttributeMode.acAttributeModeNormal,
            "point_prompt",
            Ge.Point3d(0, 0, 0),
            "point_tag",
            "point_val",
        )

        new_point = Ge.Point3d(100.5, 200.75, 0)
        ent.setInsertionPoint(new_point)
        retrieved_point = ent.insertionPoint()
        assert new_point == retrieved_point
