from pathlib import Path
from unittest.mock import MagicMock, patch

from pytest import MonkeyPatch


class Test_pyrx_onload:
    @patch("pyrx.Ap.Application.loadPythonModule")
    def test_load_module(
        self, mock_loadPythonModule: MagicMock, monkeypatch: MonkeyPatch, tmp_path: Path
    ):
        from pyrx._host_init import _PyRxOnload

        monkeypatch.chdir(tmp_path)
        _PyRxOnload().load_module(Path("test.py"))
        abs_path = str(tmp_path / "test.py")
        mock_loadPythonModule.assert_called_once_with(abs_path)

    @patch("pyrx._host_init._PyRxOnload.load_module")
    @patch("pyrx._host_init.get_pyrx_settings")
    @patch("pyrx.Ed.Core.findFile")
    @patch("pyrx.Ap.Application.getPyRxModulePath")
    def test_load_local_pyrx_onload(
        self,
        mock_getPyRxModulePath: MagicMock,
        mock_findFile: MagicMock,
        mock_get_pyrx_settings: MagicMock,
        mock_load_module: MagicMock,
        tmp_path: Path,
        monkeypatch: MonkeyPatch,
    ):
        from pyrx._host_init import pyrx_onload
        from pyrx.config import PyRxSettings

        mock_get_pyrx_settings.return_value = PyRxSettings(disable_onload=False, onload_path=None)
        monkeypatch.setenv("APPDATA", str(tmp_path / "appdata"))
        mock_getPyRxModulePath.return_value = str(tmp_path / "pyrx")

        # findFile, .py
        onload_file = tmp_path / "pyrx_onload.py"
        onload_file.touch()
        mock_findFile.side_effect = (
            lambda path: str(onload_file) if path == "pyrx_onload.py" else ""
        )
        pyrx_onload()
        assert mock_findFile.call_count == 2
        assert mock_findFile.call_args_list[0].args == ("pyrx_onload.pyc",)
        assert mock_findFile.call_args_list[1].args == ("pyrx_onload.py",)
        assert mock_load_module.call_count == 1
        assert mock_load_module.call_args_list[0].args == (onload_file,)

        # findFile, .pyc
        onload_file = tmp_path / "pyrx_onload.pyc"
        onload_file.touch()
        mock_findFile.reset_mock()
        mock_load_module.reset_mock()
        mock_findFile.side_effect = lambda path: str(tmp_path / path)
        pyrx_onload()
        assert mock_findFile.call_count == 1
        assert mock_findFile.call_args_list[0].args == ("pyrx_onload.pyc",)
        assert mock_load_module.call_count == 1
        assert mock_load_module.call_args_list[0].args == (onload_file,)

        # from settings
        onload_file = tmp_path / "other_file.py"
        onload_file.touch()
        mock_get_pyrx_settings.return_value = PyRxSettings(
            disable_onload=False, onload_path=onload_file
        )
        mock_findFile.reset_mock()
        mock_load_module.reset_mock()
        mock_findFile.side_effect = lambda path: str(
            (tmp_path / path) if path.startswith("pyrx_onload") else path
        )
        pyrx_onload()
        assert mock_load_module.call_count == 1
        assert mock_load_module.call_args_list[0].args == (onload_file,)

        # disable onload
        mock_findFile.reset_mock()
        mock_load_module.reset_mock()
        mock_get_pyrx_settings.return_value = PyRxSettings(disable_onload=True)
        pyrx_onload()
        assert mock_findFile.call_count == 0
        assert mock_load_module.call_count == 0

    @patch("pyrx._host_init._PyRxOnload.load_module")
    @patch("pyrx._host_init.get_pyrx_settings")
    @patch("pyrx.Ed.Core.findFile")
    @patch("pyrx.Ap.Application.getPyRxModulePath")
    def test_load_appdata_pyrx_onload(
        self,
        mock_getPyRxModulePath: MagicMock,
        mock_findFile: MagicMock,
        mock_get_pyrx_settings: MagicMock,
        mock_load_module: MagicMock,
        monkeypatch: MonkeyPatch,
        tmp_path: Path,
    ):
        from pyrx._host_init import pyrx_onload
        from pyrx.config import PyRxSettings

        appdata_path = tmp_path / "appdata"
        appdata_path.mkdir(parents=True, exist_ok=True)
        monkeypatch.setenv("APPDATA", str(appdata_path))
        mock_get_pyrx_settings.return_value = PyRxSettings(disable_onload=False)
        mock_getPyRxModulePath.return_value = str(tmp_path / "pyrx")
        mock_findFile.return_value = ""

        # .py
        pyrx_base_onload_file = appdata_path / "pyrx/pyrx_base_onload.py"
        pyrx_base_onload_file.parent.mkdir(parents=True, exist_ok=True)
        pyrx_base_onload_file.touch()
        pyrx_onload()
        assert mock_load_module.call_count == 1
        assert mock_load_module.call_args_list[0].args == (pyrx_base_onload_file,)

        # .pyc
        pyrx_base_onload_file = appdata_path / "pyrx/pyrx_base_onload.pyc"
        pyrx_base_onload_file.touch()
        mock_load_module.reset_mock()
        pyrx_onload()
        assert mock_load_module.call_count == 1
        assert mock_load_module.call_args_list[0].args == (pyrx_base_onload_file,)

        # disable onload
        mock_load_module.reset_mock()
        mock_get_pyrx_settings.return_value = PyRxSettings(disable_onload=True)
        pyrx_onload()
        assert mock_load_module.call_count == 0

    def test_getPyRxModulePath(self):
        # test required by next test function (test_load_debug_pyrx_onload)
        from pyrx import Ap

        pyrx_module_path = Path(Ap.Application.getPyRxModulePath())
        assert pyrx_module_path.is_dir()

    @patch("pyrx._host_init._PyRxOnload.load_module")
    @patch("pyrx._host_init.get_pyrx_settings")
    @patch("pyrx.Ap.Application.getPyRxModulePath")
    def test_load_debug_pyrx_onload(
        self,
        mock_getPyRxModulePath: MagicMock,
        mock_get_pyrx_settings: MagicMock,
        mock_load_module: MagicMock,
        tmp_path: Path,
    ):
        from pyrx._host_init import pyrx_onload
        from pyrx.config import PyRxSettings

        pyrx_module_path = tmp_path / "pyrx"
        pyrx_module_path.mkdir(parents=True, exist_ok=True)
        onload_file = pyrx_module_path / "pyrx_onload.py"
        onload_file.touch()
        mock_getPyRxModulePath.return_value = str(pyrx_module_path)
        mock_get_pyrx_settings.return_value = PyRxSettings(disable_onload=True)  # sic!
        pyrx_onload()
        assert mock_load_module.call_count == 1
        assert mock_load_module.call_args_list[0].args == (onload_file,)

    @patch("pyrx._host_init._PyRxOnload.load_module")
    @patch("pyrx._host_init.get_pyrx_settings")
    @patch("pyrx.Ed.Core.findFile")
    @patch("pyrx.Ap.Application.getPyRxModulePath")
    def test_order(
        self,
        mock_getPyRxModulePath: MagicMock,
        mock_findFile: MagicMock,
        mock_get_pyrx_settings: MagicMock,
        mock_load_module: MagicMock,
        monkeypatch: MonkeyPatch,
        tmp_path: Path,
    ):
        from pyrx._host_init import pyrx_onload
        from pyrx.config import PyRxSettings

        mock_get_pyrx_settings.return_value = PyRxSettings(disable_onload=False, onload_path=None)
        mock_getPyRxModulePath.return_value = str(tmp_path / "pyrx")

        appdata_path = tmp_path / "appdata"
        monkeypatch.setenv("APPDATA", str(appdata_path))
        appdata_onload_file = appdata_path / "pyrx/pyrx_base_onload.py"
        appdata_onload_file.parent.mkdir(parents=True, exist_ok=True)
        appdata_onload_file.touch()

        cwd = tmp_path / "cwd"
        cwd_onload_file = cwd / "pyrx_onload.py"
        cwd_onload_file.parent.mkdir(parents=True, exist_ok=True)
        cwd_onload_file.touch()
        mock_findFile.side_effect = lambda path: str(cwd_onload_file)

        pyrx_onload()
        assert mock_load_module.call_count == 2
        assert mock_load_module.call_args_list[0].args == (appdata_onload_file,)
        assert mock_load_module.call_args_list[1].args == (cwd_onload_file,)
