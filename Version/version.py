import subprocess

from setuptools_scm import ScmVersion, get_version


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


if __name__ == "__main__":
    print(get_project_version())
