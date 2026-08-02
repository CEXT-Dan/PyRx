from __future__ import annotations


import pytest

from pyrx import Ed, Ge, Rx


def autoSysVarOSMODE():
    var = Ed.Core.autoSetVar("OSMODE", 0) # noqa: F841


def autoSysVarANGBASE():
    var = Ed.Core.autoSetVar("ANGBASE", 90) # noqa: F841


def autoSysVarHPORIGIN():
    var = Ed.Core.autoSetVar("HPORIGIN", Ge.Point2d(100, 100)) # noqa: F841


class TestEditor:

    def test_get_setvar(self):  # just test possible types
        Ed.Core.setVar("OSMODE", 191)
        assert Ed.Core.getVar("OSMODE") == 191
        assert Ed.Core.getVar("HPORIGIN") == Ge.Point2d(0, 0)
        assert Ed.Core.getVar("UCSORG") == Ge.Point3d(0, 0, 0)
        assert Ed.Core.getVar("DIMTXSTY") == "Standard"

    def test_autosysvar(self):
        Ed.Core.setVar("OSMODE", 191)
        autoSysVarOSMODE()
        assert Ed.Core.getVar("OSMODE") == 191
        autoSysVarHPORIGIN()
        assert Ed.Core.getVar("HPORIGIN") == Ge.Point2d(0, 0)
        Ed.Core.setVar("ANGBASE", 0)
        autoSysVarANGBASE()
        assert Ed.Core.getVar("ANGBASE") == 0

    def test_ed_core_trans(self):
        rbfrom = [(Rx.LispType.kInt16, 0)]  # wcs
        rbto = [(Rx.LispType.kInt16, 1)]  # ucs
        ucs = Ed.Editor.getCurrentUCS()
        ucs.setToRotation(3.14159, Ge.Vector3d.kZAxis)
        Ed.Editor.setCurrentUCS(ucs)
        pt = Ge.Point3d(1, 2, 3)
        out = Ed.Core.trans(pt, rbfrom, rbto, False)
        assert out[0] < 0
        assert out[1] < 0
        assert out[2] > 0
        Ed.Editor.setCurrentUCS(Ge.Matrix3d())

    @pytest.mark.known_failure_BRX
    @pytest.mark.known_failure_GRX
    @pytest.mark.known_failure_ZRX
    @pytest.mark.known_failure_IRX
    def test_evaluateDiesel(self):
        val = Ed.Core.evaluateDiesel('$(eval,"Current layer: "$(getvar,clayer))')
        assert val == "Current layer: 0"

    def test_ed_core_grDrawPoly2d(self):
        p2d = [Ge.Point2d(100, 100), Ge.Point2d(200, 100), Ge.Point2d(200, 200)]
        res = Ed.Core.grDrawPoly2d(p2d, 2)
        assert res == 5100

    def test_ed_core_grDrawPoly3d(self):
        p3d = [Ge.Point3d(0, 0, 0), Ge.Point3d(100, 0, 0), Ge.Point3d(100, 100, 0)]
        res = Ed.Core.grDrawPoly3d(p3d, 3)
        assert res == 5100

    @pytest.mark.known_failure_GRX
    @pytest.mark.known_failure_ZRX
    def test_ed_core_getSysVars(self):
        vars = Ed.Core.getSysVars()
        assert vars is not None
