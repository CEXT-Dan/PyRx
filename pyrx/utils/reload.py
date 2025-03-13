from __future__ import annotations

import collections.abc as c
import importlib
import inspect
import sys
from contextlib import suppress


class Reloader:
    """
    A class that manages module reloading.

    Examples::

        from pyrx.utils.reload import Reloader
        import my_package.my_module
        import my_module_2

        def on_reload():
            print("Reloaded")

        reloader = Reloader("my_package", "my_module_2", func=on_reload)
        reloader.register()
    """

    def __init__(self, *module_names: str, func: c.Callable[[], None] | None = None) -> None:
        self._module_names_to_reload = module_names
        self._reload_func = func

    @property
    def modules_to_reload(self):
        chunks_list = tuple(name.split(".") for name in self._module_names_to_reload)
        count_list = tuple(len(c) for c in chunks_list)
        for name in sys.modules:
            module_chunks = name.split(".")
            for chunks, count in zip(chunks_list, count_list):
                if module_chunks[:count] == chunks:
                    yield name
                    break

    def reload_modules(self):
        to_reload = set(self.modules_to_reload)
        for name in to_reload:
            sys.modules.pop(name)
        for name in to_reload:
            with suppress(ModuleNotFoundError):
                importlib.import_module(name)

    def reload(self) -> None:
        if self._module_names_to_reload:
            self.reload_modules()
        if self._reload_func is not None:
            self._reload_func()

    def register(self, context=1):
        caller_frame = inspect.stack()[context].frame
        caller_frame.f_globals["OnPyReload"] = self.reload


def reload(*module_names: str) -> None:
    """
    Register a function that reloads the specified modules/packages when
    calling the command ``PYRELOAD`` / ``(adspyreload ...)`` or the
    ``Ap.Application.reloadPythonModule`` method. Nested
    modules/packages are also reloaded.

    Examples::

        from pyrx import reload
        import my_package.my_module
        import my_module_2

        reload("my_package", "my_module_2")
        # ...
    """
    reloader = Reloader(*module_names)
    reloader.register(context=2)
