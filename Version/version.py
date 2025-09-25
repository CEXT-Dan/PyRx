import subprocess
from pathlib import Path

from setuptools_scm import ScmVersion, get_version

MAJOR = 2
MINOR = 2
REVISION= 28

BASE_DIR = Path(__file__).parent
REPO_DIR = BASE_DIR / ".."
PYRX_INIT_PY_TPL = BASE_DIR / "__init__.tpl"
PYRX_INIT_PY = BASE_DIR / "../pyrx/__init__.py"
PYRX_VERSION_H_TPL = BASE_DIR / "pyrx_version.tpl"
PYRX_VERSION_H = BASE_DIR / "../pyrx_version.h"
PYRX_PACKAGE_CONTENTS_TPL = BASE_DIR / "PackageContents.tpl"
PYRX_PACKAGE_CONTENTS = BASE_DIR / "../PyRxAcSetup/Include/PackageContents.xml"


def custom_version_scheme(version: ScmVersion) -> str:
    base_version = version.format_with("{tag}")
    try:
        count = subprocess.check_output(
            ["git", "rev-list", "--count", "--first-parent", "main"], text=True, cwd=REPO_DIR
        ).strip()
    except Exception as err:
        err.add_note("Failed to get commit count from git.")
        raise err

    return f"{base_version}.{count}"


def get_project_version():
    return get_version(
        root=REPO_DIR,
        version_scheme=custom_version_scheme,
        local_scheme="no-local-version",
    )

def override_pyrx_version_h(version: str) -> str:
    _, _, _, revision = version.split(".")
    revision_inc = f"{int(revision) + 1}"
    content = PYRX_VERSION_H_TPL.read_text("utf-8")
    content = content.replace("{MAJOR}", str(MAJOR))
    content = content.replace("{MINOR}", str(MINOR))
    content = content.replace("{REVISION}", str(REVISION))
    content = content.replace("{VERSION_REVISION}", revision_inc)
    PYRX_VERSION_H.write_text(content, "utf-8")
    return revision_inc


def override_pyrx_init_h(version: str) -> str:
    _, _, _, revision = version.split(".")
    revision_inc = f"{int(revision) + 1}"
    content = PYRX_INIT_PY_TPL.read_text("utf-8")
    content = content.replace("{MAJOR}", str(MAJOR))
    content = content.replace("{MINOR}", str(MINOR))
    content = content.replace("{REVISION}", str(REVISION))
    content = content.replace("{VERSION_REVISION}", revision_inc)
    PYRX_INIT_PY.write_text(content, "utf-8")
    return revision_inc

def override_package_contents(version: str) -> str:
    _, _, _, revision = version.split(".")
    revision_inc = f"{int(revision) + 1}"
    content = PYRX_PACKAGE_CONTENTS_TPL.read_text("utf-8")
    content = content.replace("{MAJOR}", str(MAJOR))
    content = content.replace("{MINOR}", str(MINOR))
    content = content.replace("{REVISION}", str(REVISION))
    PYRX_PACKAGE_CONTENTS.write_text(content, "utf-8")
    return revision_inc


def main():
    version = get_project_version()
    revision_inc = override_pyrx_version_h(version)
    print(f"The revision number in the file {PYRX_VERSION_H.name} has been set to: {revision_inc}")
    version_inc = override_pyrx_init_h(version)
    print(f"The version in the file {PYRX_INIT_PY.name} has been set to: {version_inc}")
    version_inc = override_package_contents(version)
    print(f"The version in the file {PYRX_PACKAGE_CONTENTS.name} has been set to: {version_inc}")


if __name__ == "__main__":
    main()
