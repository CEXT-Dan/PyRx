import re
import subprocess
from pathlib import Path

from setuptools_scm._integration.dump_version import write_version_to_path

BASE_DIR = Path(__file__).parent
REPO_DIR = BASE_DIR / ".."
PYRX_VERSION_PY = BASE_DIR / "../pyrx/_version.py"
PYRX_VERSION_H_TPL = BASE_DIR / "pyrx_version.tpl"
PYRX_VERSION_H = BASE_DIR / "../pyrx_version.h"
BASE_VERSION_FILE = BASE_DIR / "version.txt"

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


def get_project_version() -> str:
    base_version = get_base_version()
    try:
        revision = get_revision_number()
    except Exception as err:
        err.add_note("Failed to get commit count from git.")
        raise err

    return f"{base_version}.{revision}"


def override_pyrx_version_h(version: str) -> str:
    _, _, _, revision = version.split(".")
    revision_inc = f"{int(revision) + 1}"
    content = PYRX_VERSION_H_TPL.read_text("utf-8").replace("{VERSION_REVISION}", revision_inc)
    PYRX_VERSION_H.write_text(content, "utf-8")
    return revision_inc


def override_pyrx_version_py(version: str) -> str:
    major, minor, build, revision = version.split(".")
    revision_inc = f"{int(revision) + 1}"
    version_inc = f"{major}.{minor}.{build}.{revision_inc}"
    write_version_to_path(PYRX_VERSION_PY, template=None, version=version_inc, scm_version=None)
    return version_inc


def main():
    version = get_project_version()
    revision_inc = override_pyrx_version_h(version)
    print(f"The revision number in the file {PYRX_VERSION_H.name} has been set to: {revision_inc}")
    version_inc = override_pyrx_version_py(version)
    print(f"The version in the file {PYRX_VERSION_PY.name} has been set to: {version_inc}")


if __name__ == "__main__":
    main()
