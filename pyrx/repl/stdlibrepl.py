from __future__ import annotations

from code import InteractiveConsole
from typing import TextIO

from pyrx.console import console

from .base import WARNING_CLOSE_CONSOLE, ReplMixin, call_in_main_thread


class StdLibRepl(ReplMixin, InteractiveConsole):
    def __init__(
        self, *, stdin: TextIO | None = None, stdout: TextIO | None = None, stderr: TextIO | None = None, locals=None, filename="<console>"
    ) -> None:
        ReplMixin.__init__(self, stdin=stdin, stdout=stdout, stderr=stderr)
        InteractiveConsole.__init__(
            self, locals=(locals or self.default_namespace), filename=filename
        )

    # override InteractiveConsole.runcode
    @call_in_main_thread
    def runcode(self, code):
        with self.redirect(), self.activate_host_window():
            return InteractiveConsole.runcode(self, code)

    # override InteractiveConsole.raw_input
    def raw_input(self, prompt: str = "") -> str:
        if prompt:
            self.stdout.write(prompt)
            self.stdout.flush()
        return self.stdin.readline()

    # override InteractiveConsole.write
    def write(self, data) -> None:
        self.stdout.write(data)


def run_stdlib_repl():
    with console(
        stdin_redirect=False,
        stdout_redirect=False,
        stderr_redirect=False,
    ) as (conin, conout):
        print(WARNING_CLOSE_CONSOLE, file=conout)
        repl = StdLibRepl(stdin=conin, stdout=conout, stderr=conout)
        repl.interact()
