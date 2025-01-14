import traceback
from contextlib import redirect_stderr, redirect_stdout
from pathlib import Path

import pytest

from pyrx import Ap, Ed
from pyrx.PyRxDebug import startListener as PyRxCmd_debug  # noqa
from tests import HOST, TESTS_DIR, TESTS_OUTPUT_DIR
from tests.config import TestConfig, get_log_filename


def _get_known_failures_markers():
    return [f"known_failure_{HOST[:3]}"]


def run_tests(cfg: TestConfig):
    STANDARD_PYTEST_ARGS = ("-vv", str(TESTS_DIR))
    log_filename = TESTS_OUTPUT_DIR / get_log_filename()
    log_filename.parent.mkdir(parents=True, exist_ok=True)
    with open(log_filename, "w", encoding="utf-8") as log_file:
        with redirect_stdout(log_file), redirect_stderr(log_file):
            pytest_args = [*STANDARD_PYTEST_ARGS]
            if cfg.pytest_args:
                pytest_args.extend(cfg.pytest_args)
            if "-m" not in pytest_args:
                not_markers = []
                if cfg.known_failures is False:
                    not_markers.extend(_get_known_failures_markers())
                if cfg.slow_tests is False:
                    not_markers.append("slow")
                if not_markers:
                    markers_arg = "not " + " and not ".join(not_markers)
                    pytest_args.extend(("-m", markers_arg))
            pytest.main(pytest_args)


@Ap.Command("RUN_TESTS")
def run_tests_cmd():
    try:
        # config
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
