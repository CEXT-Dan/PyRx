import logging
import os
from pathlib import Path

from pydantic_settings import BaseSettings, SettingsConfigDict, TomlConfigSettingsSource

logger = logging.getLogger(__name__)


def _get_settings_file_dirs():
    if (_appdata := os.getenv("APPDATA", None)) is not None:
        yield Path(_appdata) / "pyrx"
    yield Path.cwd()


class PyRxSettings(BaseSettings):
    disable_onload: bool = False
    load_repl: bool = False

    model_config = SettingsConfigDict(
        env_prefix="PYRX_",
        toml_file=tuple(dir_ / "pyrx.toml" for dir_ in _get_settings_file_dirs()),
    )

    @classmethod
    def settings_customise_sources(
        cls, settings_cls, init_settings, env_settings, dotenv_settings, file_secret_settings
    ):
        return (
            init_settings,
            env_settings,
            dotenv_settings,
            TomlConfigSettingsSource(settings_cls),
            file_secret_settings,
        )


_pyrx_settings: PyRxSettings | None = None


def get_pyrx_settings() -> PyRxSettings:
    global _pyrx_settings
    if _pyrx_settings is None:
        try:
            _pyrx_settings = PyRxSettings()
        except Exception:
            logger.exception("Failed to load PyRx settings")
            _pyrx_settings = PyRxSettings.model_construct({})
    assert _pyrx_settings is not None
    return _pyrx_settings.model_copy()
