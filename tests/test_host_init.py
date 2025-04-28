import io
from contextlib import contextmanager, redirect_stdout
from pathlib import Path
from unittest.mock import MagicMock, patch

from pytest import LogCaptureFixture, MonkeyPatch

from pyrx import Ed
from tests._utils import get_unique_command_name


@contextmanager
def _test_output():
    """Redirect stdout to a string stream."""
    res_sio = io.StringIO()
    with redirect_stdout(res_sio):
        yield res_sio


class Test_pyrx_onload:
    def test_load_pyrx_onload(self, tmp_path: Path):
        tmp_module = tmp_path / "pyrx_onload.py"
        res_file = tmp_path / "result.txt"
        tmp_module.write_text(
            f"with open({str(res_file)!r}, 'w') as f:\n"  #
            "    f.write('Hello from pyrx_onload')\n"
        )
        from pyrx._host_init import load_pyrx_onload

        assert not res_file.exists()
        load_pyrx_onload(tmp_module)
        assert res_file.exists()
        assert res_file.read_text() == "Hello from pyrx_onload"

    def test_load_pyrx_onload_with_commands(self, tmp_path: Path, caplog: LogCaptureFixture):
        tmp_module = tmp_path / "pyrx_onload.py"
        res_file = tmp_path / "result.txt"
        command_name = get_unique_command_name()
        tmp_module.write_text(
            "from pyrx import command\n"
            "@command\n"
            f"def {command_name}():\n"
            f"    with open({str(res_file)!r}, 'w') as f:\n"
            f"        f.write('Hello from pyrx_onload')\n"
        )
        from pyrx._host_init import load_pyrx_onload

        assert not res_file.exists()
        caplog.clear()
        load_pyrx_onload(tmp_module)
        Ed.Core.cmdS(f"{command_name}")
        assert res_file.exists()
        assert res_file.read_text() == "Hello from pyrx_onload"

    def test_debug_onload_always_loading(
        self, monkeypatch: MonkeyPatch, tmp_path: Path, caplog: LogCaptureFixture
    ):
        debug_onload_file = tmp_path / "debug" / "pyrx_onload.py"
        debug_onload_file.parent.mkdir(parents=True, exist_ok=True)
        debug_onload_file.touch()
        monkeypatch.setattr("pyrx._host_init.find_pyrx_onload_debug", lambda: [debug_onload_file])
        from pyrx.config import PyRxSettings

        monkeypatch.setattr(
            "pyrx._host_init.get_pyrx_settings", lambda: PyRxSettings(disable_onload=True)
        )
        from pyrx._host_init import pyrx_onload

        with patch("pyrx._host_init.load_pyrx_onload") as m:
            pyrx_onload()
            m.assert_called_once_with(debug_onload_file)

    def test_onload_order(
        self, monkeypatch: MonkeyPatch, tmp_path: Path, caplog: LogCaptureFixture
    ):
        debug_onload_file = tmp_path / "debug" / "pyrx_onload.py"
        debug_onload_file.parent.mkdir(parents=True, exist_ok=True)
        local_onload_file = tmp_path / "local" / "pyrx_onload.py"
        local_onload_file.parent.mkdir(parents=True, exist_ok=True)
        user_onload_file = tmp_path / "user" / "pyrx_onload.py"
        user_onload_file.parent.mkdir(parents=True, exist_ok=True)

        monkeypatch.setattr("pyrx._host_init.find_pyrx_onload_debug", lambda: [debug_onload_file])
        monkeypatch.setattr("pyrx._host_init.find_pyrx_onload_local", lambda: [local_onload_file])
        monkeypatch.setattr("pyrx._host_init.find_pyrx_onload_user", lambda: [user_onload_file])

        debug_onload_file.touch()
        local_onload_file.touch()
        user_onload_file.touch()

        from pyrx.config import PyRxSettings

        monkeypatch.setattr(
            "pyrx.config.get_pyrx_settings", lambda: PyRxSettings(disable_onload=False)
        )
        from pyrx._host_init import pyrx_onload

        with patch("pyrx._host_init.load_pyrx_onload") as m:
            pyrx_onload()
            assert m.call_count == 3
            assert m.mock_calls[0].args == (debug_onload_file,)
            assert m.mock_calls[1].args == (local_onload_file,)
            assert m.mock_calls[2].args == (user_onload_file,)

    @patch("pyrx.config._pyrx_settings")
    def test_skipping_next_onload_file(
        self,
        _pyrx_settings_mock: MagicMock,
        monkeypatch: MonkeyPatch,
        tmp_path: Path,
    ):
        debug_onload_file = tmp_path / "debug" / "pyrx_onload.py"
        debug_onload_file.parent.mkdir(parents=True, exist_ok=True)
        local_onload_file = tmp_path / "local" / "pyrx_onload.py"
        local_onload_file.parent.mkdir(parents=True, exist_ok=True)
        user_onload_file = tmp_path / "user" / "pyrx_onload.py"
        user_onload_file.parent.mkdir(parents=True, exist_ok=True)

        monkeypatch.setattr("pyrx._host_init.find_pyrx_onload_debug", lambda: [debug_onload_file])
        monkeypatch.setattr("pyrx._host_init.find_pyrx_onload_local", lambda: [local_onload_file])
        monkeypatch.setattr("pyrx._host_init.find_pyrx_onload_user", lambda: [user_onload_file])

        from pyrx._host_init import pyrx_onload
        from pyrx.config import PyRxSettings, set_pyrx_settings

        set_pyrx_settings(PyRxSettings(disable_onload=False))

        user_onload_file.write_text("print('User onload loaded')\n")
        with _test_output() as res_sio:
            pyrx_onload()
        assert "User onload loaded" in res_sio.getvalue()

        local_onload_file.write_text(
            "from pyrx.config import get_pyrx_settings, set_pyrx_settings\n"
            "s = get_pyrx_settings()\n"
            "s.disable_onload = True\n"
            "set_pyrx_settings(s)\n"
            "print('Local onload loaded')\n"
        )
        with _test_output() as res_sio:
            pyrx_onload()
        assert "Local onload loaded" in res_sio.getvalue()
        assert "User onload loaded" not in res_sio.getvalue()

        debug_onload_file.write_text(
            "from pyrx.config import get_pyrx_settings, set_pyrx_settings\n"
            "s = get_pyrx_settings()\n"
            "s.disable_onload = True\n"
            "set_pyrx_settings(s)\n"
            "print('Debug onload loaded')\n"
        )
        with _test_output() as res_sio:
            pyrx_onload()
        assert "Debug onload loaded" in res_sio.getvalue()
        assert "Local onload loaded" not in res_sio.getvalue()
        assert "User onload loaded" not in res_sio.getvalue()

    def test_onload_file_not_found(self, monkeypatch: MonkeyPatch, tmp_path: Path):
        debug_onload_file = tmp_path / "debug" / "pyrx_onload.py"
        local_onload_file = tmp_path / "local" / "pyrx_onload.py"
        user_onload_file = tmp_path / "user" / "pyrx_onload.py"

        debug_onload_file.parent.mkdir(parents=True, exist_ok=True)
        local_onload_file.parent.mkdir(parents=True, exist_ok=True)
        user_onload_file.parent.mkdir(parents=True, exist_ok=True)

        monkeypatch.setattr("pyrx._host_init.find_pyrx_onload_debug", lambda: [debug_onload_file])
        monkeypatch.setattr("pyrx._host_init.find_pyrx_onload_local", lambda: [local_onload_file])
        monkeypatch.setattr("pyrx._host_init.find_pyrx_onload_user", lambda: [user_onload_file])

        from pyrx._host_init import pyrx_onload
        from pyrx.config import PyRxSettings

        monkeypatch.setattr(
            "pyrx._host_init.get_pyrx_settings", lambda: PyRxSettings(disable_onload=False)
        )

        with patch("pyrx._host_init.load_pyrx_onload") as m:
            pyrx_onload()
            m.assert_not_called()

        user_onload_file.touch()
        with patch("pyrx._host_init.load_pyrx_onload") as m:
            pyrx_onload()
            m.assert_called_once_with(user_onload_file)

        user_onload_file.unlink()
        local_onload_file.touch()
        with patch("pyrx._host_init.load_pyrx_onload") as m:
            pyrx_onload()
            m.assert_called_once_with(local_onload_file)

        local_onload_file.unlink()
        debug_onload_file.touch()
        with patch("pyrx._host_init.load_pyrx_onload") as m:
            pyrx_onload()
            m.assert_called_once_with(debug_onload_file)
