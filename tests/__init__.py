from pathlib import Path

from pyrx import Ap

HOST = Ap.Application.hostAPI() if Ap is not None else None

TESTS_DIR = Path(__file__).parent
TESTS_OUTPUT_DIR = TESTS_DIR / "output"
