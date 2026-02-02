import traceback
from contextlib import redirect_stderr, redirect_stdout
from pathlib import Path

import pytest

from pyrx import Ap, Ed
from pyrx.PyRxDebug import startListener as PyRxCmd_debug  # noqa
from tests import HOST, TESTS_DIR, TESTS_OUTPUT_DIR
from tests.config import TestConfig, get_log_filename


def _get_known_failures_markers() -> list[str]:
    markers = []
    if HOST is not None:
        markers.append(f"known_failure_{HOST[:3]}")
    return markers


def _get_markers_arg(markers: list[str], not_markers: list[str]) -> str:
    return " and ".join(markers + [f"not {marker}" for marker in not_markers])


def run_tests(cfg: TestConfig):
    STANDARD_PYTEST_ARGS = ("-vv", str(TESTS_DIR))
    log_filename = TESTS_OUTPUT_DIR / get_log_filename()
    log_filename.parent.mkdir(parents=True, exist_ok=True)
    pytest_args = [*STANDARD_PYTEST_ARGS]
    if cfg.pytest_args:
        pytest_args.extend(cfg.pytest_args)
    if "-m" not in pytest_args:
        not_markers = []
        if cfg.known_failures is False:
            not_markers.extend(_get_known_failures_markers())
        if cfg.slow_tests is False:
            not_markers.append("slow")
        pytest_args_cmdctx = pytest_args.copy()
        pytest_args_appctx = pytest_args.copy()
        markers_arg_cmdctx = _get_markers_arg(  # without appctx
            markers=[],
            not_markers=(not_markers + ["appctx"]),
        )
        markers_arg_appctx = _get_markers_arg(  # only appctx
            markers=["appctx"],
            not_markers=not_markers,
        )
        pytest_args_cmdctx.extend(("-m", markers_arg_cmdctx))
        pytest_args_appctx.extend(("-m", markers_arg_appctx))

        with (
            open(log_filename, "a", encoding="utf-8") as log_file,
            redirect_stdout(log_file),
            redirect_stderr(log_file),
        ):
            print("Running tests in command context")
            pytest.main(pytest_args_cmdctx)
            print("\nRunning tests in application context")
            Ap.DocManager().executeInApplicationContext(pytest.main, pytest_args_appctx)


@Ap.Command("RUN_TESTS", Ap.CmdFlags.NO_UNDO_MARKER | Ap.CmdFlags.NOHISTORY)
def run_tests_cmd():
    try:
        # config
        cmdecho = Ed.AutoSysVar("CMDECHO", 0) # noqa: F841
        status, cfg_file = Ed.Editor.getString("\nconfig file: ")
        if not status == Ed.PromptStatus.eOk:
            raise RuntimeError(str(status))
        cfg_file = Path(cfg_file)
        if not cfg_file.exists():
            raise FileNotFoundError(str(cfg_file))
        cfg = TestConfig.load(cfg_file)
        run_tests(cfg)
    except Exception:
        traceback.print_exc()
