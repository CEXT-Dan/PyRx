import pytest

from pyrx.doc_utils.misc import DocstringsManager, ReturnTypesManager


@pytest.fixture(scope="session")
def docstrings() -> DocstringsManager:
    return DocstringsManager.from_json()


@pytest.fixture(scope="session")
def return_types() -> ReturnTypesManager:
    return ReturnTypesManager.from_json()
