from __future__ import annotations

import os
import sys
import types
import typing as t

from prompt_toolkit.input import create_input
from prompt_toolkit.output import create_output
from ptpython.repl import PythonRepl

from pyrx.console import console

from .base import WARNING_CLOSE_CONSOLE, ReplMixin, call_in_main_thread, redirect_stdin


class PtPythonRepl(ReplMixin, PythonRepl):
    def __init__(
        self,
        *,
        stdin=None,
        stdout=None,
        stderr=None,
        input=None,
        output=None,
        globals=None,
        locals=None,
        **kwargs,
    ) -> None:
        if globals is None:
            globals = self.default_namespace

        locals = locals or globals

        def get_globals():
            return globals

        def get_locals():
            return locals

        ReplMixin.__init__(self, stdin=stdin, stdout=stdout, stderr=stderr)
        with self.redirect():
            PythonRepl.__init__(
                self,
                get_globals=get_globals,
                get_locals=get_locals,
                input=input,
                output=output,
                **kwargs,
            )

    @call_in_main_thread
    def _eval(self, code: types.CodeType) -> None:
        with self.redirect(), self.activate_host_window():
            return eval(code, self.get_globals(), self.get_locals())

    # override PythonRepl.eval
    def eval(self, line: str) -> t.Any:
        # WORKAROUND: Due to a bug in Jedi, the current directory is removed
        # from sys.path. See: https://github.com/davidhalter/jedi/issues/1148
        if "" not in sys.path:
            sys.path.insert(0, "")

        if line.lstrip().startswith("!"):
            # Run as shell command
            os.system(line[1:])
        else:
            # Try eval first
            try:
                code = self._compile_with_flags(line, "eval")
            except SyntaxError:
                pass
            else:
                # No syntax errors for eval. Do eval.
                result = self._eval(code)  # override !

                self._store_eval_result(result)
                return result

            # If not a valid `eval` expression, run using `exec` instead.
            # Note that we shouldn't run this in the `except SyntaxError` block
            # above, then `sys.exc_info()` would not report the right error.
            # See issue: https://github.com/prompt-toolkit/ptpython/issues/435
            code = self._compile_with_flags(line, "exec")
            result = self._eval(code)  # override !

        return None


def run_ptpython_repl():
    with console(
        stdin_redirect=False,
        stdout_redirect=False,
        stderr_redirect=False,
    ) as (conin, conout):
        print(WARNING_CLOSE_CONSOLE, file=conout)
        con_output = create_output(conout)
        with redirect_stdin(conin):
            con_input = create_input()
        repl = PtPythonRepl(
            stdin=conin, stdout=conout, stderr=conout, input=con_input, output=con_output
        )
        repl.run()
