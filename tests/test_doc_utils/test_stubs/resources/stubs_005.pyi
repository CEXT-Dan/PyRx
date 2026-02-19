# /*
# This block should be ignored by the generator
# */

from typing import overload

class Class(object):
    """
    Class docstring.
    """

    class_var: int
    class_var2: str = "class_var2_value"
    class_var_with_docstring: bool
    """
    Class variable with docstring.
    """

    @staticmethod
    def static_meth() -> None:
        """
        Static method docstring.
        """

    @classmethod
    def class_meth(cls) -> None:
        """
        Class method docstring.
        """

    def instance_meth(self) -> None:
        """
        Instance method docstring.
        """

    @overload
    def overloaded_meth(self, arg: int) -> None: ...
    @overload
    def overloaded_meth(self, arg: str) -> None: ...
    @overload
    def overloaded_meth(self, arg: float) -> None:
        """
        Overloaded method docstring.
        """

def func() -> None:
    """
    Function docstring.
    """

@overload
def overloaded_func(arg: int) -> None: ...
@overload
def overloaded_func(arg: str) -> None: ...
@overload
def overloaded_func(arg: float) -> None:
    """
    Overloaded function docstring.
    """
