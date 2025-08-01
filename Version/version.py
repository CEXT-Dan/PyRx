import subprocess
from pathlib import Path

from setuptools_scm import ScmVersion, get_version
from setuptools_scm._integration.dump_version import write_version_to_path

BASE_DIR = Path(__file__).parent
PYRX_VERSION_PY = BASE_DIR / "../pyrx/_version.py"
PYRX_VERSION_H_TPL = BASE_DIR / "pyrx_version.tpl"
PYRX_VERSION_H = BASE_DIR / "../pyrx_version.h"


def custom_version_scheme(version: ScmVersion) -> str:
    base_version = version.format_with("{tag}")
    try:
        count = subprocess.check_output(
            ["git", "rev-list", "--count", "--first-parent", "main"], text=True
        ).strip()
    except Exception as err:
        err.add_note("Failed to get commit count from git.")
        raise err

    return f"{base_version}.{count}"


def get_project_version():
    return get_version(
        version_scheme=custom_version_scheme,
        local_scheme="no-local-version",
    )


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
