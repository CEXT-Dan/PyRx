from __future__ import annotations

import importlib
import sys
from pathlib import Path

import pytest


@pytest.fixture
def appdata(tmp_path: Path, monkeypatch):
    """Fixture to create a temporary appdata directory."""
    appdata_dir = tmp_path / "appdata"
    appdata_dir.mkdir(parents=True, exist_ok=True)
    monkeypatch.setenv("APPDATA", str(appdata_dir))
    return appdata_dir


@pytest.fixture
def cwd(tmp_path: Path, monkeypatch: pytest.MonkeyPatch):
    """Fixture to create a temporary current working directory."""
    cwd_dir = tmp_path / "cwd"
    cwd_dir.mkdir(parents=True, exist_ok=True)
    monkeypatch.chdir(cwd_dir)
    return cwd_dir


class TestPyRxSettings:
    @pytest.fixture
    def setup_env(self, monkeypatch: pytest.MonkeyPatch):
        """Setup method to ensure PYRX_DISABLE_ONLOAD and PYRX_LOAD_REPL are unset."""
        monkeypatch.delenv("PYRX_DISABLE_ONLOAD", False)
        monkeypatch.delenv("PYRX_LOAD_REPL", False)

    def test_settings_order(
        self,
        setup_env,
        appdata: Path,
        cwd: Path,
        monkeypatch: pytest.MonkeyPatch,
        caplog: pytest.LogCaptureFixture,
    ):
        if "pyrx.config" in sys.modules:
            importlib.reload(sys.modules["pyrx.config"])
        from pyrx.config import PyRxSettings

        default_settings = PyRxSettings()
        assert default_settings.disable_onload is False
        assert default_settings.load_repl is False

        appdata_file = appdata / "pyrx/pyrx.toml"
        appdata_file.parent.mkdir(parents=True, exist_ok=True)
        with open(appdata_file, "w") as f:
            f.write("[user]\ndisable_onload = true\nload_repl = true\n")

        settings = PyRxSettings()
        assert settings.disable_onload is True
        assert settings.load_repl is True

        cwd_file = cwd / "pyrx.toml"
        with open(cwd_file, "w") as f:
            f.write("[user]\nload_repl = false\n")

        caplog.clear()
        settings = PyRxSettings()
        assert len(caplog.messages) >= 1
        for message in caplog.messages:
            if (
                f"Skipping pyrx configuration file ({appdata_file}) "
                f"as it is not the first one found ({cwd_file})"
            ) in message:
                break
        else:
            pytest.fail("Failed to find expected log message")
        assert settings.disable_onload is False  # skip appdata
        assert settings.load_repl is False

        monkeypatch.setenv("PYRX_DISABLE_ONLOAD", "1")

        settings = PyRxSettings()
        assert settings.disable_onload is True

        settings = PyRxSettings(disable_onload=False, load_repl=True)
        assert settings.disable_onload is False
        assert settings.load_repl is True

    def test_get_pyrx_settings(
        self, setup_env, monkeypatch: pytest.MonkeyPatch, caplog: pytest.LogCaptureFixture
    ):
        if "pyrx.config" in sys.modules:
            importlib.reload(sys.modules["pyrx.config"])
        from pyrx.config import PyRxSettings, get_pyrx_settings

        settings_1 = get_pyrx_settings()
        settings_2 = get_pyrx_settings()

        assert isinstance(settings_1, PyRxSettings)
        assert isinstance(settings_2, PyRxSettings)

        assert settings_1 == settings_2
        assert settings_1 is not settings_2

        # load default if invalid settings
        assert settings_1.disable_onload is False
        assert settings_1.load_repl is False
        monkeypatch.setenv("PYRX_DISABLE_ONLOAD", "invalid_value")
        monkeypatch.setenv("PYRX_LOAD_REPL", "true")

        importlib.reload(sys.modules["pyrx.config"])

        from pyrx.config import _pyrx_settings, get_pyrx_settings

        assert _pyrx_settings is None
        caplog.clear()
        settings = get_pyrx_settings()
        assert len(caplog.messages) >= 1
        for message in caplog.messages:
            if "Failed to load PyRx settings" in message:
                break
        else:
            pytest.fail("Failed to find expected log message")
        assert settings.disable_onload is False
        assert settings.load_repl is False

    def test_set_pyrx_settings(self):
        from pyrx import config
        from pyrx.config import PyRxSettings, set_pyrx_settings

        original_settings = config._pyrx_settings
        try:
            s1 = PyRxSettings(disable_onload=True, load_repl=False)
            set_pyrx_settings(s1)
            assert config._pyrx_settings == s1
            assert config._pyrx_settings is not s1
        finally:
            config._pyrx_settings = original_settings  # Restore original settings
