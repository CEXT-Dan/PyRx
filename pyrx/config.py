import logging
import os
import typing as t
from functools import reduce
from operator import or_
from pathlib import Path

from pydantic_settings import BaseSettings, SettingsConfigDict, TomlConfigSettingsSource

logger = logging.getLogger(__name__)

TOML_CONFIG_FILENAME = "pyrx.toml"


def _get_toml_settings_files():
    first = None
    if (_appdata := os.getenv("APPDATA", None)) is not None:
        file = Path(_appdata) / "pyrx" / TOML_CONFIG_FILENAME
        if file.is_file():
            if not first:
                yield file
                first = file
            else:
                logger.warning(
                    f"Skipping pyrx configuration file ({file}) "
                    f"as it is not the first one found ({first})"
                )


class TomlConfigPyRxSettingsSource(TomlConfigSettingsSource):
    def _read_file(self, file_path) -> dict[str, t.Any]:
        vars: dict[str, dict[str, t.Any]] = super()._read_file(file_path)
        squashed_vars = reduce(or_, vars.values())
        return squashed_vars


class PyRxSettings(BaseSettings):
    # [system]
    optimization_level: int = 2

    # [user]
    disable_onload: bool = False
    onload_path: Path | None = None
    top_window_title: str | None = None

    model_config = SettingsConfigDict(env_prefix="PYRX_", extra="ignore")

    @classmethod
    def settings_customise_sources(
        cls, settings_cls, init_settings, env_settings, dotenv_settings, file_secret_settings
    ):
        return (
            init_settings,
            env_settings,
            dotenv_settings,
            TomlConfigPyRxSettingsSource(settings_cls, tuple(_get_toml_settings_files())),
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
    return _pyrx_settings.model_copy()  # settings are mutable, so return a copy


def set_pyrx_settings(settings: PyRxSettings | None) -> None:
    global _pyrx_settings
    if settings is None:
        _pyrx_settings = None
    else:
        _pyrx_settings = settings.model_copy()  # settings are mutable, so store a copy


if __name__ == "__main__":
    settings = get_pyrx_settings()
    for k, v in settings.model_dump().items():
        print(f"{k} = {v}")
