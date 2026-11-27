from __future__ import annotations

import pytest

from pyrx import Ap, Ax


class TestAxRegisteredApplication:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc = self.axApp.activeDocument()

    def _add_app(self, name: str = "PYRX_RA_TEST") -> Ax.AcadRegisteredApplication:
        return self.axDoc.registeredApplications().add(name)

    def test_className(self):
        assert Ax.AcadRegisteredApplication.className() == "AcadRegisteredApplication"

    def test_init_raises(self):
        with pytest.raises(Exception):
            Ax.AcadRegisteredApplication()

    def test_name(self):
        app = self._add_app(name="PYRX_RA_NAME")
        assert app.name() == "PYRX_RA_NAME"

    def test_setName(self):
        app = self._add_app(name="PYRX_RA_SETNAME")
        app.setName("PYRX_RA_RENAMED")
        assert app.name() == "PYRX_RA_RENAMED"

    def test_cast(self):
        app = self._add_app(name="PYRX_RA_CAST")
        casted = Ax.AcadRegisteredApplication.cast(app)
        assert isinstance(casted, Ax.AcadRegisteredApplication)
        assert casted.name() == app.name()
