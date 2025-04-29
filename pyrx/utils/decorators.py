from __future__ import annotations

import inspect
import typing as t
from functools import wraps

from pyrx import Db

_EMPTY = object()
_P = t.ParamSpec("_P")
_R = t.TypeVar("_R")


class _PassWorkingDb(t.Generic[_P, _R]):
    def __init__(self, func: t.Callable[_P, _R]):
        self.sig = inspect.signature(func)
        try:
            db_param = self.sig.parameters["db"]
        except KeyError:
            raise RuntimeError("Function must have a 'db' parameter") from None
        self.db_param_kind = db_param.kind
        if self.db_param_kind not in (
            inspect.Parameter.POSITIONAL_OR_KEYWORD,
            inspect.Parameter.KEYWORD_ONLY,
        ):
            raise RuntimeError("Function 'db' parameter must be positional or keyword")
        self.func = func

    def __call__(self, *args: _P.args, **kwargs: _P.kwargs) -> _R:
        # fix the parameters to include the working database
        args, kwargs = self.fix_params(args, kwargs)

        # call the function with the fixed parameters
        return self.func(*args, **kwargs)

    def fix_params(self, args, kwargs):
        db = kwargs.get("db", _EMPTY)
        if db is not _EMPTY:
            if db is None:
                kwargs["db"] = self.get_db()
            return args, kwargs

        if self.db_param_kind == inspect.Parameter.KEYWORD_ONLY:
            # db is a keyword-only parameter, so we can just add it to kwargs
            kwargs["db"] = self.get_db()
            return args, kwargs

        # db not in kwargs, check args
        db_param_index = tuple(inspect.signature(self.func).parameters).index("db")
        if not len(args) > db_param_index:
            # db not in args, add it to kwargs
            kwargs["db"] = self.get_db()
            return args, kwargs

        # db in args, check if it is None
        db = args[db_param_index]
        if db is None:
            args = (*args[:db_param_index], self.get_db(), *args[db_param_index + 1 :])
        return args, kwargs

    def get_db(self) -> Db.Database:
        return Db.workingDb()


def pass_working_db(func: t.Callable[_P, _R]) -> t.Callable[_P, _R]:
    """
    Decorator to ensure the working database is passed to the function.

    This decorator automatically injects the current working database
    (``Db.workingDb()``) into the `db` parameter of the decorated
    function if it is not explicitly provided or is set to ``None``. The
    function must have a ``db`` parameter, which can be positional or
    keyword-based.


    Using the decorator:

    ```
    @pass_working_db
    def func(db=None):
        assert db is not None
    ```

    is equivalent to:

    ```
    def func(db=None):
        if db is None:
            db = Db.workingDb()
    ```

    Raises:
        RuntimeError: If the decorated function does not have a `db`
            parameter or if the `db` parameter is not positional or
            keyword-based.

    """
    return wraps(func)(_PassWorkingDb(func))
