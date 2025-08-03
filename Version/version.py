import re
import subprocess
from pathlib import Path

from setuptools_scm._integration.dump_version import write_version_to_path

BASE_DIR = Path(__file__).parent
REPO_DIR = BASE_DIR / ".."
BASE_VERSION_FILE = BASE_DIR / "version.txt"
PYRX_VERSION_PY = BASE_DIR / "../pyrx/_version.py"
PYRX_VERSION_H_TPL = BASE_DIR / "pyrx_version.tpl"
PYRX_VERSION_H = BASE_DIR / "../pyrx_version.h"
PYRX_PACKAGE_CONTENTS_TPL = BASE_DIR / "PackageContents.tpl"
PYRX_PACKAGE_CONTENTS = BASE_DIR / "../PyRxAcSetup/Include/PackageContents.xml"

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


def get_project_version() -> tuple[str, tuple[str, str, str, str]]:
    base_version = get_base_version()
    try:
        revision = get_revision_number()
    except Exception as err:
        err.add_note("Failed to get commit count from git.")
        raise err
    version_tuple = parse_version(base_version)

    return f"{base_version}.{revision}", (*version_tuple, revision)


def parse_version(version: str) -> tuple:
    match = BASE_VERSION_PATTERN.fullmatch(version)
    if not match:
        raise ValueError(f"Invalid version format: {version}")
    return match.groups()


def override_pyrx_version_h(major: str, minor: str, revision: str, version_revision: str) -> None:
    content = PYRX_VERSION_H_TPL.read_text("utf-8")
    content = (
        content.replace("{MAJOR}", str(major))
        .replace("{MINOR}", str(minor))
        .replace("{REVISION}", str(revision))
        .replace("{VERSION_REVISION}", version_revision)
    )
    PYRX_VERSION_H.write_text(content, "utf-8")
    print(
        f"The version in the file {PYRX_VERSION_H.name} "
        f"has been set to: {major}.{minor}.{revision}.{version_revision}"
    )


def override_pyrx_version_py(major: str, minor: str, revision: str, version_revision: str) -> None:
    version = f"{major}.{minor}.{revision}.{version_revision}"
    write_version_to_path(PYRX_VERSION_PY, template=None, version=version, scm_version=None)
    print(f"The version in the file {PYRX_VERSION_PY.name} has been set to: {version}")


def override_package_contents(major: str, minor: str, revision: str) -> None:
    content = (
        PYRX_PACKAGE_CONTENTS_TPL.read_text("utf-8")
        .replace("{MAJOR}", str(major))
        .replace("{MINOR}", str(minor))
        .replace("{REVISION}", str(revision))
    )
    PYRX_PACKAGE_CONTENTS.write_text(content, "utf-8")
    print(
        f"The version in the file {PYRX_PACKAGE_CONTENTS.name} "
        f"has been set to: {major}.{minor}.{revision}"
    )


def main():
    _, version_tuple = get_project_version()
    major, minor, revision, version_revision = version_tuple
    version_revision_inc = f"{int(version_revision) + 1}"
    override_pyrx_version_h(major, minor, revision, version_revision_inc)
    override_pyrx_version_py(major, minor, revision, version_revision_inc)
    override_package_contents(major, minor, revision)


if __name__ == "__main__":
    main()
