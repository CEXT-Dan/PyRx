import re
import subprocess
from pathlib import Path

from setuptools import setup
from setuptools_scm import ScmVersion

BASE_DIR = Path(__file__).parent
BASE_VERSION_FILE = BASE_DIR / "Version/version.txt"
BASE_VERSION_PATTERN = re.compile(r"^(\d+)\.(\d+)\.(\d+)$")


def get_base_version() -> str:
    version = BASE_VERSION_FILE.read_text("utf-8").strip()
    if not BASE_VERSION_PATTERN.fullmatch(version):
        raise ValueError(f"Invalid version format: {version}")
    return version


def get_revision_number() -> str:
    number = subprocess.check_output(
        ["git", "rev-list", "--count", "--first-parent", "main"], text=True
    ).strip()
    if not number.isdigit():
        raise ValueError(f"Revision number is not a digit: {number}")
    return number


def version_scheme(version: ScmVersion) -> str:
    base_version = get_base_version()
    try:
        revision = get_revision_number()
    except Exception:
        revision = "0"
    return f"{base_version}.{revision}"


setup(
    use_scm_version={
        "version_scheme": version_scheme,
        "local_scheme": "no-local-version",
        "write_to": "pyrx/_version.py",
    }
)
