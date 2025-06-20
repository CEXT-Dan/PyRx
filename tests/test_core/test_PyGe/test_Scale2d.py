from __future__ import annotations

import pytest

from pyrx import Ge


class TestScale2d:
    def test_repr(self):
        val = Ge.Scale2d(1.2, 2.3)
        assert val.__repr__() == "PyGe.Scale2d(1.20000000000000,2.30000000000000)"

    def test_scale2_default_ctor(self):
        scale = Ge.Scale2d()
        assert scale.sx == 1
        assert scale.sy == 1

    def test_scale2_ctor1(self):
        scale = Ge.Scale2d(3)
        assert scale.sx == 3
        assert scale.sy == 3

    def test_scale2_ctor2(self):
        scale = Ge.Scale2d(4, 4)
        assert scale.sx == 4
        assert scale.sy == 4

    @pytest.mark.known_failure_BRX
    def test_scale2_preMultBy(self):
        scaleL = Ge.Scale2d(2, 2)
        scaleR = Ge.Scale2d(4, 4)
        scaleL.preMultBy(scaleR)
        assert scaleL.sx == 8
        assert scaleL.sy == 8

    @pytest.mark.known_failure_BRX
    def test_scale2_postMultBy(self):
        scaleL = Ge.Scale2d(2, 2)
        scaleR = Ge.Scale2d(4, 4)
        scaleL.postMultBy(scaleR)
        assert scaleL.sx == 8
        assert scaleL.sy == 8

    @pytest.mark.known_failure_BRX
    def test_scale2_setToProduct1(self):
        scale1 = Ge.Scale2d()
        scale2 = Ge.Scale2d(2, 2)
        scale1.setToProduct(scale2, 2)
        assert scale1.sx == 4
        assert scale1.sy == 4
