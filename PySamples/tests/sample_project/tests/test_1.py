import pytest
from package.module import func_a, func_b


def test_func_a():
    assert func_a() == 1


def test_func_b():
    with pytest.raises(ValueError, match="This is a test exception"):
        func_b()
