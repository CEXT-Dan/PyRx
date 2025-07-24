import subprocess
from pathlib import Path

from setuptools_scm import ScmVersion, get_version

BASE_DIR = Path(__file__).parent
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


def override_pyrx_version_h(version: str) -> None:
    major, minor, build, revision = version.split(".")
    content = (
        PYRX_VERSION_H_TPL.read_text("utf-8")
        .replace("{VERSION_MAJOR}", major)
        .replace("{VERSION_MINOR}", minor)
        .replace("{VERSION_BUILD}", build)
        .replace("{VERSION_REVISION}", revision)
    )
    PYRX_VERSION_H.write_text(content, "utf-8")


def main():
    version = get_project_version()
    override_pyrx_version_h(version)
    print(f"PyRx version set to: {version}")


if __name__ == "__main__":
    main()
