from __future__ import annotations


import pytest

from pyrx import Db, Gi, Rx


class TestRxObject:

    def test_isA(self):
        line1 = Db.Line()
        line2 = Db.Line()
        circle = Db.Circle()
        assert line1.isA() == line2.isA()
        assert line1.isA() == line2.isA()
        assert line1.isA() != circle.isA()

    def test_isKindOf(self):
        line1 = Db.Line()
        assert line1.isKindOf(Db.Line.desc())
        assert line1.isKindOf(Db.Curve.desc())
        assert line1.isKindOf(Db.Entity.desc())
        assert line1.isKindOf(Db.DbObject.desc())
        assert line1.isKindOf(Gi.Drawable.desc())
        assert line1.isKindOf(Rx.RxObject.desc())
        assert not line1.isKindOf(Db.Circle.desc())
        assert not line1.isKindOf(Db.BlockReference.desc())

    # RxClass tests
    def test_isDerivedFrom(self):
        line1 = Db.Line()
        clss = line1.isA()
        assert clss.isDerivedFrom(Db.Line.desc())
        assert clss.isDerivedFrom(Db.Curve.desc())
        assert clss.isDerivedFrom(Db.Entity.desc())
        assert clss.isDerivedFrom(Db.DbObject.desc())
        assert clss.isDerivedFrom(Gi.Drawable.desc())
        assert clss.isDerivedFrom(Rx.RxObject.desc())
        assert not clss.isDerivedFrom(Db.Circle.desc())
        assert not clss.isDerivedFrom(Db.BlockReference.desc())

    def test_myParent(self):
        pline = Db.Polyline()
        clss = pline.isA()
        line = Db.Line()
        clss2 = line.isA()
        assert clss.myParent() == Db.Curve.desc()
        assert clss.myParent() == clss2.myParent()

    @pytest.mark.known_failure_IRX
    def test_name(self):
        pline = Db.Polyline()
        clss = pline.isA()
        name = clss.name()
        appname = clss.appName()
        dxfName = clss.dxfName()
        assert name == "AcDbPolyline"
        assert appname == "ObjectDBX Classes"
        assert dxfName == "LWPOLYLINE"

    def test_equals_hash(self):
        assert Db.Line.desc() == Db.Line.desc()
        assert Db.Circle.desc() != Db.Line.desc()
        pline1 = Db.Line()
        pline2 = Db.Line()
        assert pline1 != pline2
        assert pline1.__hash__() != pline2.__hash__()
        assert pline1.intPtr() != pline2.intPtr()
        # cast
        line3 = Db.Line()
        obj3 = Db.Line.cast(line3)
        assert obj3 == line3
        assert obj3.__hash__() == line3.__hash__()
        assert obj3.intPtr() == line3.intPtr()
