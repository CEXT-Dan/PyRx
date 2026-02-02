from __future__ import annotations

import pytest

from pyrx import Db, Ge


class TestDbMText:

    def test_creation(self):
        """Test basic MText object creation and content setting"""
        mt = Db.MText()
        val = "123456"
        mt.setContents(val)
        assert mt.contents() == val

    def test_location(self):
        """Test location setting and retrieval"""
        mt = Db.MText()
        val = Ge.Point3d(10, 10, 0)
        mt.setLocation(val)
        assert mt.location() == val

    def test_normal(self):
        """Test normal vector setting and retrieval"""
        mt = Db.MText()
        val = Ge.Vector3d(0, 0, 1)
        mt.setNormal(val)
        assert mt.normal() == val

    def test_direction(self):
        """Test direction vector setting and retrieval"""
        mt = Db.MText()
        val = Ge.Vector3d(1, 0, 0)
        mt.setDirection(val)
        assert mt.direction() == val

    def test_rotation(self):
        """Test rotation setting and retrieval"""
        mt = Db.MText()
        val = 1.5708  # π/2 radians
        mt.setRotation(val)
        assert mt.rotation() == pytest.approx(val, rel=1e-6)

    def test_height(self):
        """Test height setting and retrieval"""
        mt = Db.MText()
        val = 5.0
        mt.setHeight(val)
        assert mt.height() == val

    def test_text_height(self):
        """Test text height setting and retrieval"""
        mt = Db.MText()
        val = 3.0
        mt.setTextHeight(val)
        assert mt.textHeight() == val

    def test_width(self):
        """Test width setting and retrieval"""
        mt = Db.MText()
        val = 100.0
        mt.setWidth(val)
        assert mt.width() == val

    def test_attachment_point(self):
        """Test attachment point setting and retrieval"""
        mt = Db.MText()
        val = Db.MTextAttachmentPoint.kMiddleCenter
        mt.setAttachment(val)
        assert mt.attachment() == val

    def test_flow_direction(self):
        """Test flow direction setting and retrieval"""
        mt = Db.MText()
        val = Db.MTextFlowDirection.kLtoR
        mt.setFlowDirection(val)
        assert mt.flowDirection() == val

    def test_line_spacing_style(self):
        """Test line spacing style setting and retrieval"""
        mt = Db.MText()
        val = Db.LineSpacingStyle.kExactly
        mt.setLineSpacingStyle(val)
        assert mt.lineSpacingStyle() == val

    def test_line_spacing_factor(self):
        """Test line spacing factor setting and retrieval"""
        mt = Db.MText()
        val = 1.5
        mt.setLineSpacingFactor(val)
        assert mt.lineSpacingFactor() == val

    @pytest.mark.known_failure_BRX
    def test_contents_rtf(self):
        """Test RTF content setting and retrieval"""
        mt = Db.MText()
        rtf_val = (
            "{\\rtf1\\ansi\\deff0{\\fonttbl{\\f0 Times New Roman;}}\\f0\\fs24 Test}"
        )
        mt.setContentsRTF(rtf_val)
        # Note: actual RTF content may be converted, so just verify it doesn't crash
        assert isinstance(mt.contentsRTF(), str)

    def test_background_fill(self):
        """Test background fill settings"""
        mt = Db.MText()
        # Test enabling background fill
        mt.setBackgroundFill(True)
        assert mt.backgroundFillOn() == True

        # Test disabling background fill
        mt.setBackgroundFill(False)
        assert mt.backgroundFillOn() == False

    def test_background_color(self):
        """Test background color settings"""
        mt = Db.MText()
        mt.setBackgroundFill(True)

        # Set background color
        color_val = Db.Color()
        color_val.setRGB(255, 0, 0)

        mt.setBackgroundFillColor(color_val)
        assert mt.useBackgroundColorOn() == True

    def test_background_transparency(self):
        """Test background transparency settings"""
        mt = Db.MText()
        mt.setBackgroundFill(True)

        transp_val = Db.Transparency(50)  # 50% transparent
        mt.setBackgroundTransparency(transp_val)

    def test_column_settings(self):
        """Test column-related functionality"""
        mt = Db.MText()

        # Test setting dynamic columns
        mt.setDynamicColumns(100.0, 10.0, True)
        assert mt.getColumnType() == Db.MTextColumnType.kDynamicColumns

        # Test static columns
        mt.setStaticColumns(80.0, 5.0, 3)
        assert mt.getColumnType() == Db.MTextColumnType.kStaticColumns

        # Test column settings
        assert mt.getColumnCount() == 3
        assert mt.getColumnWidth() == 80.0
        assert mt.getColumnGutterWidth() == 5.0

    def test_column_auto_height(self):
        """Test auto height for columns"""
        mt = Db.MText()
        mt.setDynamicColumns(100.0, 10.0, True)

        # Test getting column auto height
        assert mt.getColumnAutoHeight() == True

    def test_column_flow_reversed(self):
        """Test column flow reversal setting"""
        mt = Db.MText()
        mt.setDynamicColumns(100.0, 10.0, True)

        # Test getting column flow reversed
        assert mt.getColumnFlowReversed() == False

    def test_ascent_descent(self):
        """Test ascent and descent calculations"""
        mt = Db.MText()
        val = "Test Text"
        mt.setContents(val)

        # These should not throw exceptions, but values may be 0.0 for empty text
        assert isinstance(mt.ascent(), float)
        assert isinstance(mt.descent(), float)

    @pytest.mark.known_failure_BRX
    def test_hit_test(self):
        """Test hit testing functionality"""
        mt = Db.MText()
        val = Ge.Point3d(0, 0, 0)

        # Test with dummy point - should return boolean without error
        result = mt.hitTest(val)
        assert isinstance(result, bool)

    def test_get_bounding_points(self):
        """Test bounding points retrieval"""
        mt = Db.MText()
        val = "Test Text"
        mt.setContents(val)

        # Should return a list of Point3d objects without error
        points = mt.getBoundingPoints()
        assert isinstance(points, list)
        assert len(points) == 4

    @pytest.mark.known_failure_BRX
    def test_get_bounding_points_by_line(self):
        """Test bounding points by line retrieval"""
        mt = Db.MText()
        val = "Test Text"
        mt.setContents(val)

        # Should return a multidimensional array without error
        points_list = mt.getBoundingPointsByLine()
        assert isinstance(points_list, list)

    def test_class_name(self):
        """Test class name retrieval"""
        cls_name = Db.MText.className()
        assert isinstance(cls_name, str)
        assert len(cls_name) > 0

    def test_get_fragments(self):
        """Test fragment retrieval (should not crash)"""
        mt = Db.MText()
        val = "Test Text"
        mt.setContents(val)

        # Should return a list without error, though content may vary based on formatting
        fragments = mt.getFragments()
        assert isinstance(fragments, list)

    def test_text_contents(self):
        """Test text content retrieval"""
        mt = Db.MText()
        val = "Sample Text"
        mt.setContents(val)

        # Get text (should be same as contents but with formatting removed)
        txt_content = mt.text()
        assert isinstance(txt_content, str)

    def test_set_contents_with_special_chars(self):
        """Test setting content with special characters"""
        mt = Db.MText()
        val = "Special chars: \n\t\r\"'"
        mt.setContents(val)
        assert mt.contents() == val

    def test_empty_text(self):
        """Test behavior with empty text"""
        mt = Db.MText()
        mt.setContents("")

        assert mt.contents() == ""
        assert isinstance(mt.actualHeight(), float)
        assert isinstance(mt.actualWidth(), float)

    def test_set_contents_returns_status(self):
        """Test that setContents returns an integer status code"""
        mt = Db.MText()
        val = "Test Content"
        result = mt.setContents(val)
        # Should return 0 for success (based on documentation patterns)
        assert isinstance(result, int)
