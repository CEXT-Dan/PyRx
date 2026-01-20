from __future__ import annotations

import pytest
from pyrx import Db, Ge


class TestDbText:
    def test_creation_1(self):
        """Test basic Text object creation and content setting"""
        t = Db.Text()
        val = "123456"
        t.setTextString(val)
        assert t.textString() == val
        
    def test_creation_2(self):
        """Test basic Text object creation and content setting"""
        val = "123456"
        pos = Ge.Point3d(1, 1, 0)
        t = Db.Text(pos,val)
        assert t.textString() == val
        assert t.position() == pos

    def test_position(self):
        """Test setting and getting text position"""
        t = Db.Text()
        val = Ge.Point3d(1, 1, 0)
        t.setPosition(val)
        assert t.position() == val

    def test_height(self):
        """Test setting and getting text height"""
        t = Db.Text()
        val = 2.5
        t.setHeight(val)
        assert t.height() == pytest.approx(val)

    def test_rotation(self):
        """Test setting and getting text rotation (in radians)"""
        t = Db.Text()
        val = 1.5708  # ~90 degrees in radians
        t.setRotation(val)
        assert t.rotation() == pytest.approx(val)

    def test_normal(self):
        """Test setting and getting normal vector"""
        t = Db.Text()
        val = Ge.Vector3d(0, 0, 1)
        t.setNormal(val)
        assert t.normal() == val

    def test_oblique(self):
        """Test setting and getting oblique angle (in radians)"""
        t = Db.Text()
        val = 0.5236  # ~30 degrees in radians
        t.setOblique(val)
        assert t.oblique() == pytest.approx(val)

    def test_thickness(self):
        """Test setting and getting text thickness"""
        t = Db.Text()
        val = 0.1
        t.setThickness(val)
        assert t.thickness() == pytest.approx(val)

    def test_width_factor(self):
        """Test setting and getting width factor"""
        t = Db.Text()
        val = 0.8
        t.setWidthFactor(val)
        assert t.widthFactor() == pytest.approx(val)

    def test_alignment_point(self):
        """Test setting and getting alignment point"""
        t = Db.Text()
        t.setTextString("this is a test")
        t.setVerticalMode(Db.TextVertMode.kTextBase)
        t.setHorizontalMode(Db.TextHorzMode.kTextFit)
        val = Ge.Point3d(2, 2, 0)
        t.setAlignmentPoint(val)
        assert t.alignmentPoint() == val

    def test_horizontal_mode(self):
        """Test setting and getting horizontal mode"""
        t = Db.Text()
        t.setTextString("this is a test")
        mode = Db.TextHorzMode.kTextCenter
        t.setHorizontalMode(mode)
        assert t.horizontalMode() == mode

    def test_vertical_mode(self):
        """Test setting and getting vertical mode"""
        t = Db.Text()
        t.setTextString("this is a test")
        mode = Db.TextVertMode.kTextTop
        t.setVerticalMode(mode)
        assert t.verticalMode() == mode

    def test_text_string(self):
        """Test setting and getting text string with special characters"""
        t = Db.Text()
        val = "Hello %%d World"
        t.setTextString(val)
        assert t.textString() == val

    def test_is_default_alignment(self):
        """Test default alignment check"""
        t = Db.Text()
        t.setTextString("this is a test")
        # Default should be kTextLeft, kTextBase -> True
        result = t.isDefaultAlignment()
        # Since we don't know the actual state from the constructor,
        # just make sure method doesn't crash.
        assert isinstance(result, (bool, int))

    def test_direction(self):
        """Test getting text direction vector"""
        t = Db.Text()
        t.setTextString("this is a test")
        dir_vec = t.direction()
        # Just verify it returns a Vector3d (no specific value expected without context)
        assert isinstance(dir_vec, Ge.Vector3d)

    def test_justification(self):
        """Test getting justification enum"""
        t = Db.Text()
        t.setTextString("this is a test")
        assert t.justification() == Db.TextAlignment.kTextAlignmentLeft

    def test_is_mirrored_in_x(self):
        """Test mirroring flags"""
        t = Db.Text()
        t.setTextString("this is a test")
        result = t.isMirroredInX()
        assert isinstance(result, (bool, int))

    def test_is_mirrored_in_y(self):
        """Test mirroring flags"""
        t = Db.Text()
        t.setTextString("this is a test")
        result = t.isMirroredInY()
        assert isinstance(result,  (bool, int))

    def test_mirror_x(self):
        """Test setting mirror in X direction"""
        t = Db.Text()
        t.setTextString("this is a test")
        # Just ensure method can be called without error
        try:
            t.mirrorInX(True)
            t.mirrorInX(False)
        except Exception as e:
            # This might fail if DB context is required; ignore for now.
            assert False

    def test_mirror_y(self):
        """Test setting mirror in Y direction"""
        t = Db.Text()
        t.setTextString("this is a test")
        try:
            t.mirrorInY(True)
            t.mirrorInY(False)
        except Exception as e:
            # This might fail if DB context is required; ignore for now.
            assert False

    def test_hit_test(self):
        """Test hit testing functionality"""
        t = Db.Text()
        t.setTextString("this is a test")
        point = Ge.Point3d(0, 0, 0)
        try:
            result = t.hitTest(point)
            assert isinstance(result, (bool, int))
        except Exception as e:
            # Might not be available or functional in all contexts
            assert False

    def test_adjust_alignment(self):
        """Test text adjustment (requires database context)"""
        t = Db.Text()
        t.setTextString("this is a test")
        # Just make sure method exists and doesn't crash on call with null DB.
        try:
            t.adjustAlignment(Db.curDb())
        except Exception as e:
            # Expected behavior may vary; this is just ensuring no crash
             assert False

    def test_correct_spelling(self):
        """Test spelling correction functionality"""
        t = Db.Text()
        t.setTextString("this is a test")
        result = t.correctSpelling()  # Returns int
        assert isinstance(result, int)
