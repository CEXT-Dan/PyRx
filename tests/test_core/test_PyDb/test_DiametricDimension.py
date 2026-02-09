from __future__ import annotations

import pytest

from pyrx import Db, Ge


class TestDbDiametricDimension:

    def test_create_1(self):
        """Test basic creation with chord points and leader length."""
        chordPoint = Ge.Point3d(0, 0, 0)
        farChordPoint = Ge.Point3d(0, 50, 0)
        leaderLength = 1.0
        dim = Db.DiametricDimension(chordPoint, farChordPoint, leaderLength)

        assert dim.chordPoint() == chordPoint
        assert dim.farChordPoint() == farChordPoint
        assert dim.leaderLength() == leaderLength

    @pytest.mark.known_failure_BRX 
    @pytest.mark.known_failure_GRX  
    @pytest.mark.known_failure_ZRX
    def test_create_with_text(self):
        """Test creation with dimension text."""
        chordPoint = Ge.Point3d(10, 10, 0)
        farChordPoint = Ge.Point3d(10, 60, 0)
        leaderLength = 2.5
        dimText = "DIA 50 <>"
        dim = Db.DiametricDimension(chordPoint, farChordPoint, leaderLength, dimText)
        assert "DIA 50" in dim.formatMeasurement(50)

    def test_set_chord_point(self):
        """Test setting the chord point."""
        dim = Db.DiametricDimension()
        new_point = Ge.Point3d(5, 5, 0)
        dim.setChordPoint(new_point)
        assert dim.chordPoint() == new_point

    def test_set_far_chord_point(self):
        """Test setting the far chord point."""
        dim = Db.DiametricDimension()
        new_point = Ge.Point3d(5, 55, 0)
        dim.setFarChordPoint(new_point)
        assert dim.farChordPoint() == new_point

    def test_set_leader_length(self):
        """Test setting the leader length."""
        dim = Db.DiametricDimension()
        new_length = 10.5
        dim.setLeaderLength(new_length)
        assert dim.leaderLength() == new_length

    @pytest.mark.known_failure_BRX 
    def test_set_ext_arc_angles(self):
        """Test setting extension arc start and end angles."""
        dim = Db.DiametricDimension()
        start_angle = 45.0
        end_angle = 135.0
        dim.setExtArcStartAngle(start_angle)
        dim.setExtArcEndAngle(end_angle)
        assert dim.extArcStartAngle() == start_angle
        assert dim.extArcEndAngle() == end_angle

    def test_static_methods(self):
        """Test static utility methods."""
        # Test className
        class_name = Db.DiametricDimension.className()
        assert isinstance(class_name, str)
        assert "AcDbDiametricDimension" in class_name
        class_desc = Db.DiametricDimension.desc()
        assert class_desc.isDerivedFrom(Db.DiametricDimension.desc())
