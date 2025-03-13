from __future__ import annotations
from pyrx import Ap, Ed, Rx, command


@command
def regcmd1():
    Ed.Core.setVar("USERS1", "SUCCESS")


@Ap.Command()
def regcmd2():
    Ed.Core.setVar("USERS1", "SUCCESS")


def PyRxCmd_regcmd3():
    Ed.Core.setVar("USERS1", "SUCCESS")


class TestRegCommands:
    def setup_class(self):
        Ap.Application.loadPythonModule(str(__file__))

    def test_cmdtotestStr1(self):
        assert Ed.Core.setVar("USERS1", "FAIL") == True
        assert Ed.Core.getVar("USERS1") == "FAIL"
        assert Ed.Core.cmdS("regcmd1") == True
        Ed.Core.getVar("USERS1") == "SUCCESS"

    def test_cmdtotestStr2(self):
        assert Ed.Core.setVar("USERS1", "FAIL") == True
        assert Ed.Core.getVar("USERS1") == "FAIL"
        assert Ed.Core.cmdS("regcmd2") == True
        Ed.Core.getVar("USERS1") == "SUCCESS"

    def test_cmdtotestStr3(self):
        assert Ed.Core.setVar("USERS1", "FAIL") == True
        assert Ed.Core.getVar("USERS1") == "FAIL"
        assert Ed.Core.cmdS("regcmd1") == True
        Ed.Core.getVar("USERS1") == "SUCCESS"


class TestReloadCommands:
    def setup_class(self):
        Ap.Application.loadPythonModule(str(__file__))
        Ap.Application.reloadPythonModule(str(__file__))

    def test_cmdtotestStr1(self):
        assert Ed.Core.setVar("USERS1", "FAIL") == True
        assert Ed.Core.getVar("USERS1") == "FAIL"
        assert Ed.Core.cmdS("regcmd1") == True
        Ed.Core.getVar("USERS1") == "SUCCESS"

    def test_cmdtotestStr2(self):
        assert Ed.Core.setVar("USERS1", "FAIL") == True
        assert Ed.Core.getVar("USERS1") == "FAIL"
        assert Ed.Core.cmdS("regcmd2") == True
        Ed.Core.getVar("USERS1") == "SUCCESS"

    def test_cmdtotestStr3(self):
        assert Ed.Core.setVar("USERS1", "FAIL") == True
        assert Ed.Core.getVar("USERS1") == "FAIL"
        assert Ed.Core.cmdS("regcmd1") == True
        Ed.Core.getVar("USERS1") == "SUCCESS"
