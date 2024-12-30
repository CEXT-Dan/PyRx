from pathlib import Path

from setuptools import setup

this_directory = Path(__file__).parent
long_description = (this_directory / "GitResources/long_description.md").read_text()

setup(
    long_description=long_description,
    long_description_content_type="text/markdown",
)
