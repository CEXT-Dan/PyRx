from __future__ import annotations

from pyrx import Ap
from tests import MEDIA_DIR


class TestApplication:

    def test_loadPythonModule(self):
        moddict = Ap.Application.loadPythonModule(str(MEDIA_DIR / "loadtest.py"))
        assert moddict["GLOBAL_VAL"] == 1
        func = moddict["loadtestfunc"]
        assert func() == "YIPPIE"

        dummydict = Ap.Application.loadPythonModule(str(MEDIA_DIR / "submedia/dummy.py"))
        assert dummydict["test253"]() == True

    def test_getLocalAppDataPath(self):
        path = Ap.Application.getLocalAppDataPath()
        assert path.find("PyRx") != -1
        assert path.find("Local") != -1
        assert path.find("AppData") != -1

    def test_getAppDataPath(self):
        path = Ap.Application.getAppDataPath()
        assert path.find("PyRx") != -1
        assert path.find("Roaming") != -1
        assert path.find("AppData") != -1

    def test_listFilesInPath(self):
        path = Ap.Application.listFilesInPath(str(MEDIA_DIR), ".dwg")
        assert len(path) == 13
        path = Ap.Application.listFilesInPath(str(MEDIA_DIR), ".dWg")
        assert len(path) == 13

    def test_listFilesInPathRecursive(self):
        path = Ap.Application.listFilesInPathRecursive(str(MEDIA_DIR), ".dwg")
        assert len(path) == 14
        path = Ap.Application.listFilesInPathRecursive(str(MEDIA_DIR), ".dWg")
        assert len(path) == 14
