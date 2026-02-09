from __future__ import annotations

import pytest

from pyrx import Db, Ge


class TestDbHelix:
    
    def test_create_1(self):
        obj = Db.Helix()
        val = Ge.Point3d(10, 10, 0)
        obj.setAxisPoint(val)
        assert val == obj.axisPoint()

    def test_axis_vector(self):
        obj = Db.Helix()
        vec = Ge.Vector3d(0, 0, 1)
        obj.setAxisVector(vec)
        assert vec == obj.axisVector()

    def test_base_radius(self):
        obj = Db.Helix()
        radius = 5.5
        obj.setBaseRadius(radius)
        assert obj.baseRadius() == radius

    def test_top_radius(self):
        obj = Db.Helix()
        radius = 10.0
        obj.setTopRadius(radius)
        assert obj.topRadius() == radius

    def test_height(self):
        obj = Db.Helix()
        height = 100.0
        obj.setHeight(height)
        assert obj.height() == height

    def test_turns(self):
        obj = Db.Helix()
        turns = 5.0
        obj.setTurns(turns)
        assert obj.turns() == turns

    def test_turn_height(self):
        obj = Db.Helix()
        turn_height = 2.0
        obj.setTurnHeight(turn_height)
        assert obj.turnHeight() == turn_height

    def test_constrain(self):
        obj = Db.Helix()
        constrain_type = Db.HelixConstrainType.kTurnHeight
        obj.setConstrain(constrain_type)
        assert obj.constrain() == constrain_type

    @pytest.mark.known_failure_ZRX
    def test_reverse_curve(self):
        obj = Db.Helix()
        obj.reverseCurve()
        assert True

    def test_set_start_point(self):
        obj = Db.Helix()
        start_pt = Ge.Point3d(0, 0, 0)
        obj.setStartPoint(start_pt)
        assert start_pt == obj.startPoint()
