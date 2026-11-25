from __future__ import annotations

import pytest

from pyrx import Ap, Ax, Ge


class TestAxUCS:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def _make_ucs(
        self,
        name: str,
        origin: Ge.Point3d | None = None,
        xdir: Ge.Vector3d | None = None,
        ydir: Ge.Vector3d | None = None,
    ) -> Ax.AcadUCS:
        origin = Ge.Point3d(0, 0, 0) if origin is None else origin
        xdir = Ge.Vector3d.kXAxis if xdir is None else xdir
        ydir = Ge.Vector3d.kYAxis if ydir is None else ydir
        return self.axDoc.userCoordinateSystems().add(origin, xdir, ydir, name)

    # --- static / class methods ---

    def test_className(self):
        assert Ax.AcadUCS.className() == "AcadUCS"

    def test_init_raises(self):
        with pytest.raises(Exception):
            Ax.AcadUCS()

    # --- name ---

    def test_name(self):
        ucs = self._make_ucs("axucs_name")
        assert ucs.name() == "axucs_name"

    def test_setName(self):
        ucs = self._make_ucs("axucs_rename_old")
        ucs.setName("axucs_rename_new")
        assert ucs.name() == "axucs_rename_new"

    # --- origin ---

    @pytest.mark.known_failure_ARX
    def test_origin(self):
        # Fails with "unknown error" from COM Add (PyIAcadUCSsImpl::Add) when the
        # origin is non-zero; add() with origin (0,0,0) succeeds. setOrigin works fine.
        origin = Ge.Point3d(10, 20, 30)
        ucs = self._make_ucs("axucs_origin", origin=origin)
        assert ucs.origin() == origin

    def test_setOrigin(self):
        ucs = self._make_ucs("axucs_setorigin")
        new_origin = Ge.Point3d(5, 15, 25)
        ucs.setOrigin(new_origin)
        assert ucs.origin() == new_origin

    # --- xVector ---

    def test_xVector(self):
        ucs = self._make_ucs("axucs_xvector")
        assert ucs.xVector() == Ge.Vector3d.kXAxis

    def test_setXVector(self):
        # A valid X axis must stay orthogonal to the current Z axis (0, 0, 1),
        # so pick a vector in the XY plane.
        ucs = self._make_ucs("axucs_setx")
        new_x = Ge.Vector3d(0, 1, 0)
        ucs.setXVector(new_x)
        assert ucs.xVector() == new_x

    # --- yVector ---

    def test_yVector(self):
        ucs = self._make_ucs("axucs_yvector")
        assert ucs.yVector() == Ge.Vector3d.kYAxis

    def test_setYVector(self):
        # A valid Y axis must stay orthogonal to the current Z axis (0, 0, 1),
        # so pick a vector in the XY plane.
        ucs = self._make_ucs("axucs_sety")
        new_y = Ge.Vector3d(1, 0, 0)
        ucs.setYVector(new_y)
        assert ucs.yVector() == new_y

    # --- ucsMatrix ---

    def test_ucsMatrix(self):
        ucs = self._make_ucs("axucs_matrix")
        mat = ucs.ucsMatrix()
        assert isinstance(mat, Ge.Matrix3d)

    # --- AcadObject inherited ---

    def test_isNull(self):
        ucs = self._make_ucs("axucs_isnull")
        assert ucs.isNull() is False

    # --- activeUCS / setActiveUCS (Document) ---

    @pytest.mark.known_failure_ARX
    def test_activeUCS(self):
        # Fails with "unknown error" from COM get_ActiveUCS (PyIAcadDocumentImpl::GetActiveUCS).
        ucs = self.axDoc.activeUCS()
        assert ucs.className() == "AcadUCS"

    @pytest.mark.known_failure_ARX
    def test_setActiveUCS(self):
        # Fails at the initial activeUCS() call (same root cause as test_activeUCS).
        original = self.axDoc.activeUCS()
        ucs = self._make_ucs("axucs_setactive")
        self.axDoc.setActiveUCS(ucs)
        assert self.axDoc.activeUCS().name() == "axucs_setactive"
        # Restore the original active UCS so we don't leak state to other tests.
        self.axDoc.setActiveUCS(original)

    # --- cast ---

    def test_cast(self):
        ucs = self._make_ucs("axucs_cast")
        casted = Ax.AcadUCS.cast(ucs)
        assert casted.name() == "axucs_cast"
