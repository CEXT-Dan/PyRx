from __future__ import annotations

import unittest

from pyrx import Db, Gi, Rx


class TestRxObject:
    def setup_class(self):
        self.assertions = unittest.TestCase("__init__")
        self.assertEqual = self.assertions.assertEqual
        self.assertNotEqual = self.assertions.assertNotEqual
        self.assertGreater = self.assertions.assertGreater
        self.assertFalse = self.assertions.assertFalse
        self.assertTrue = self.assertions.assertTrue

    def test_isA(self):
        line1 = Db.Line()
        line2 = Db.Line()
        circle = Db.Circle()
        self.assertEqual(line1.isA(), line2.isA())
        self.assertEqual(line1.isA(), line2.isA())
        self.assertNotEqual(line1.isA(), circle.isA())

    def test_isKindOf(self):
        line1 = Db.Line()
        self.assertTrue(line1.isKindOf(Db.Line.desc()))
        self.assertTrue(line1.isKindOf(Db.Curve.desc()))
        self.assertTrue(line1.isKindOf(Db.Entity.desc()))
        self.assertTrue(line1.isKindOf(Db.DbObject.desc()))
        self.assertTrue(line1.isKindOf(Gi.Drawable.desc()))
        self.assertTrue(line1.isKindOf(Rx.RxObject.desc()))
        self.assertFalse(line1.isKindOf(Db.Circle.desc()))
        self.assertFalse(line1.isKindOf(Db.BlockReference.desc()))

    # RxClass tests
    def test_isDerivedFrom(self):
        line1 = Db.Line()
        clss = line1.isA()
        self.assertTrue(clss.isDerivedFrom(Db.Line.desc()))
        self.assertTrue(clss.isDerivedFrom(Db.Curve.desc()))
        self.assertTrue(clss.isDerivedFrom(Db.Entity.desc()))
        self.assertTrue(clss.isDerivedFrom(Db.DbObject.desc()))
        self.assertTrue(clss.isDerivedFrom(Gi.Drawable.desc()))
        self.assertTrue(clss.isDerivedFrom(Rx.RxObject.desc()))
        self.assertFalse(clss.isDerivedFrom(Db.Circle.desc()))
        self.assertFalse(clss.isDerivedFrom(Db.BlockReference.desc()))

    def test_myParent(self):
        pline = Db.Polyline()
        clss = pline.isA()
        line = Db.Line()
        clss2 = line.isA()
        self.assertEqual(clss.myParent(), Db.Curve.desc())
        self.assertEqual(clss.myParent(), clss2.myParent())

    def test_name(self):
        pline = Db.Polyline()
        clss = pline.isA()
        name = clss.name()
        appname = clss.appName()
        dxfName = clss.dxfName()
        self.assertEqual(name, "AcDbPolyline")
        self.assertEqual(appname, "ObjectDBX Classes")
        self.assertEqual(dxfName, "LWPOLYLINE")

    def test_equals_hash(self):
        self.assertTrue(Db.Line.desc() == Db.Line.desc())
        self.assertTrue(Db.Circle.desc() != Db.Line.desc())
        pline1 = Db.Line()
        pline2 = Db.Line()
        self.assertTrue(pline1 != pline2)
        self.assertTrue(pline1.__hash__() != pline2.__hash__())
        self.assertTrue(pline1.intPtr() != pline2.intPtr())
        # cast
        line3 = Db.Line()
        obj3 = Db.Line.cast(line3)
        self.assertTrue(obj3 == line3)
        self.assertTrue(obj3.__hash__() == line3.__hash__())
        self.assertTrue(obj3.intPtr() == line3.intPtr())
