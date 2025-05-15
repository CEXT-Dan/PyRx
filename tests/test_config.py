from __future__ import annotations

import importlib
import sys
from pathlib import Path

import pytest


@pytest.fixture
def appdata(tmp_path: Path, monkeypatch: pytest.MonkeyPatch) -> Path:
    """Fixture to create a temporary appdata directory."""
    appdata_dir = tmp_path / "appdata"
    appdata_dir.mkdir(parents=True, exist_ok=True)
    monkeypatch.setenv("APPDATA", str(appdata_dir))
    return appdata_dir


class TestPyRxSettings:
    @pytest.fixture
    def setup_env(self, monkeypatch: pytest.MonkeyPatch):
        """Setup method to ensure PYRX_DISABLE_ONLOAD are unset."""
        monkeypatch.delenv("PYRX_DISABLE_ONLOAD", False)

    def test_settings_order(
        self,
        setup_env,
        appdata: Path,
        monkeypatch: pytest.MonkeyPatch,
        caplog: pytest.LogCaptureFixture,
    ):
        if "pyrx.config" in sys.modules:
            importlib.reload(sys.modules["pyrx.config"])
        from pyrx.config import PyRxSettings

        default_settings = PyRxSettings()
        assert default_settings.disable_onload is False

        appdata_file = appdata / "pyrx/pyrx.toml"
        appdata_file.parent.mkdir(parents=True, exist_ok=True)
        with open(appdata_file, "w") as f:
            f.write("[user]\ndisable_onload = true\n")

        settings = PyRxSettings()
        assert settings.disable_onload is True

        monkeypatch.setenv("PYRX_DISABLE_ONLOAD", "0")

        settings = PyRxSettings()
        assert settings.disable_onload is False

        settings = PyRxSettings(disable_onload=True)
        assert settings.disable_onload is True

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
        monkeypatch.setenv("PYRX_DISABLE_ONLOAD", "invalid_value")

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

    def test_set_pyrx_settings(self):
        from pyrx import config
        from pyrx.config import PyRxSettings, set_pyrx_settings

        original_settings = config._pyrx_settings
        try:
            s1 = PyRxSettings(disable_onload=True)
            set_pyrx_settings(s1)
            assert config._pyrx_settings == s1
            assert config._pyrx_settings is not s1
        finally:
            config._pyrx_settings = original_settings  # Restore original settings

    def test_ignore_extra_values(self, setup_env, appdata: Path, monkeypatch: pytest.MonkeyPatch):
        if "pyrx.config" in sys.modules:
            importlib.reload(sys.modules["pyrx.config"])
        from pyrx.config import PyRxSettings

        # Test with appdata file
        appdata_file = appdata / "pyrx/pyrx.toml"
        appdata_file.parent.mkdir(parents=True, exist_ok=True)
        with open(appdata_file, "w") as f:
            f.write("[user]\ndisable_onload = true\nload_repl = false\n")

        settings = PyRxSettings()
        assert settings.disable_onload is True

        # Ensure extra values are ignored
        with pytest.raises(AttributeError):
            _ = settings.load_repl

        # Test with environment variables
        monkeypatch.setenv("PYRX_DISABLE_ONLOAD", "true")
        monkeypatch.setenv("PYRX_LOAD_REPL", "true")

        settings = PyRxSettings()
        assert settings.disable_onload is True

        # Ensure extra environment variables are ignored
        with pytest.raises(AttributeError):
            _ = settings.load_repl
