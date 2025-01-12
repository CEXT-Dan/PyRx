import pytest

from tests import HOST


@pytest.mark.known_failure_BRX
def test_failure_in_brx():
    if "BRX" in HOST:
        assert False


@pytest.mark.known_failure_GRX
def test_failure_in_grx():
    if "GRX" in HOST:
        assert False


@pytest.mark.known_failure_ZRX
def test_failure_in_zrx():
    if "ZRX" in HOST:
        assert False


def test_success():
    assert 1 == 1


def test_failure():
    assert 1 == 0


@pytest.mark.slow
def test_slow():
    assert True
