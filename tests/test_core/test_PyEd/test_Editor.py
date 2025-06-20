from __future__ import annotations

import unittest

import pytest

from pyrx import Ed, Ge, Rx


def autoSysVarOSMODE():
    var = Ed.Core.autoSetVar("OSMODE", 0)


def autoSysVarANGBASE():
    var = Ed.Core.autoSetVar("ANGBASE", 90)


def autoSysVarHPORIGIN():
    var = Ed.Core.autoSetVar("HPORIGIN", Ge.Point2d(100, 100))


class TestEditor:
    def setup_class(self):
        self.assertions = unittest.TestCase("__init__")
        self.assertEqual = self.assertions.assertEqual
        self.assertNotEqual = self.assertions.assertNotEqual
        self.assertGreater = self.assertions.assertGreater
        self.assertFalse = self.assertions.assertFalse
        self.assertTrue = self.assertions.assertTrue
        self.assertIsNotNone = self.assertions.assertIsNotNone

    def test_get_setvar(self):  # just test possible types
        Ed.Core.setVar("OSMODE", 191)
        self.assertEqual(Ed.Core.getVar("OSMODE"), 191)
        self.assertEqual(Ed.Core.getVar("HPORIGIN"), Ge.Point2d(0, 0))
        self.assertEqual(Ed.Core.getVar("UCSORG"), Ge.Point3d(0, 0, 0))
        self.assertEqual(Ed.Core.getVar("DIMTXSTY"), "Standard")

    def test_autosysvar(self):
        Ed.Core.setVar("OSMODE", 191)
        autoSysVarOSMODE()
        self.assertEqual(Ed.Core.getVar("OSMODE"), 191)
        autoSysVarHPORIGIN()
        self.assertEqual(Ed.Core.getVar("HPORIGIN"), Ge.Point2d(0, 0))
        Ed.Core.setVar("ANGBASE", 0)
        autoSysVarANGBASE()
        self.assertEqual(Ed.Core.getVar("ANGBASE"), 0)

    def test_ed_core_trans(self):
        rbfrom = [(Rx.LispType.kInt16, 0)]  # wcs
        rbto = [(Rx.LispType.kInt16, 1)]  # ucs
        ucs = Ed.Editor.getCurrentUCS()
        ucs.setToRotation(3.14159, Ge.Vector3d.kZAxis)
        Ed.Editor.setCurrentUCS(ucs)
        pt = Ge.Point3d(1, 2, 3)
        out = Ed.Core.trans(pt, rbfrom, rbto, False)
        self.assertTrue(out[0] < 0)
        self.assertTrue(out[1] < 0)
        self.assertTrue(out[2] > 0)
        Ed.Editor.setCurrentUCS(Ge.Matrix3d())

    @pytest.mark.known_failure_BRX
    @pytest.mark.known_failure_GRX
    @pytest.mark.known_failure_ZRX
    def test_evaluateDiesel(self):
        val = Ed.Core.evaluateDiesel('$(eval,"Current layer: "$(getvar,clayer))')
        self.assertEqual(val, "Current layer: 0")

    def test_ed_core_grDrawPoly2d(self):
        p2d = [Ge.Point2d(100, 100), Ge.Point2d(200, 100), Ge.Point2d(200, 200)]
        res = Ed.Core.grDrawPoly2d(p2d, 2)
        self.assertEqual(res, 5100)

    def test_ed_core_grDrawPoly3d(self):
        p3d = [Ge.Point3d(0, 0, 0), Ge.Point3d(100, 0, 0), Ge.Point3d(100, 100, 0)]
        res = Ed.Core.grDrawPoly3d(p3d, 3)
        self.assertEqual(res, 5100)

    @pytest.mark.known_failure_GRX
    @pytest.mark.known_failure_ZRX
    def test_ed_core_getSysVars(self):
        vars = Ed.Core.getSysVars()
        self.assertIsNotNone(vars)
