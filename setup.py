import subprocess

from setuptools import setup
from setuptools_scm import ScmVersion


def version_scheme(version: ScmVersion) -> str:
    base_version = version.format_with("{tag}")
    try:
        count = subprocess.check_output(
            ["git", "rev-list", "--count", "--first-parent", "main"], text=True
        ).strip()
    except Exception:
        count = "0"
    return f"{base_version}.{count}"


setup(
    use_scm_version={
        "version_scheme": version_scheme,
        "local_scheme": "no-local-version",
        "write_to": "pyrx/_version.py",
    }
)
