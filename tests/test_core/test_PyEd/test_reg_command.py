from __future__ import annotations

from pyrx import Ap, Ed, command


@command
def regcmd1():
    Ed.Core.setVar("USERS1", "SUCCESS_1")


@Ap.Command()
def regcmd2():
    Ed.Core.setVar("USERS1", "SUCCESS_2")


def PyRxCmd_regcmd3():
    Ed.Core.setVar("USERS1", "SUCCESS_3")


@command
def regcmd4():
    Ed.Core.setVar("USERS1", "SUCCESS_4")


@Ap.Command()
def regcmd5():
    Ed.Core.setVar("USERS1", "SUCCESS_5")


def PyRxCmd_regcmd6():
    Ed.Core.setVar("USERS1", "SUCCESS_6")


class TestRegCommands:
    def setup_class(self):
        Ap.Application.loadPythonModule(str(__file__))

    def test_cmdtotestStr1(self):
        assert Ed.Core.setVar("USERS1", "FAIL") == True
        assert Ed.Core.getVar("USERS1") == "FAIL"
        assert Ed.Core.cmdS("regcmd1") == True
        assert Ed.Core.getVar("USERS1") == "SUCCESS_1"

    def test_cmdtotestStr2(self):
        assert Ed.Core.setVar("USERS1", "FAIL") == True
        assert Ed.Core.getVar("USERS1") == "FAIL"
        assert Ed.Core.cmdS("regcmd2") == True
        assert Ed.Core.getVar("USERS1") == "SUCCESS_2"

    def test_cmdtotestStr3(self):
        assert Ed.Core.setVar("USERS1", "FAIL") == True
        assert Ed.Core.getVar("USERS1") == "FAIL"
        assert Ed.Core.cmdS("regcmd3") == True
        assert Ed.Core.getVar("USERS1") == "SUCCESS_3"

    def test_cmdtotestStr4(self):
        assert Ed.Core.setVar("USERS1", "FAIL") == True
        assert Ed.Core.getVar("USERS1") == "FAIL"
        assert Ed.Core.cmdS("regcmd4") == True
        assert Ed.Core.getVar("USERS1") == "SUCCESS_4"

    def test_cmdtotestStr5(self):
        assert Ed.Core.setVar("USERS1", "FAIL") == True
        assert Ed.Core.getVar("USERS1") == "FAIL"
        assert Ed.Core.cmdS("regcmd5") == True
        assert Ed.Core.getVar("USERS1") == "SUCCESS_5"

    def test_cmdtotestStr6(self):
        assert Ed.Core.setVar("USERS1", "FAIL") == True
        assert Ed.Core.getVar("USERS1") == "FAIL"
        assert Ed.Core.cmdS("regcmd6") == True
        assert Ed.Core.getVar("USERS1") == "SUCCESS_6"


class TestReloadCommands:
    def setup_class(self):
        Ap.Application.loadPythonModule(str(__file__))
        Ap.Application.reloadPythonModule(str(__file__))

    def test_cmdtotestStr1(self):
        assert Ed.Core.setVar("USERS1", "FAIL") == True
        assert Ed.Core.getVar("USERS1") == "FAIL"
        assert Ed.Core.cmdS("regcmd1") == True
        assert Ed.Core.getVar("USERS1") == "SUCCESS_1"

    def test_cmdtotestStr2(self):
        assert Ed.Core.setVar("USERS1", "FAIL") == True
        assert Ed.Core.getVar("USERS1") == "FAIL"
        assert Ed.Core.cmdS("regcmd2") == True
        assert Ed.Core.getVar("USERS1") == "SUCCESS_2"

    def test_cmdtotestStr3(self):
        assert Ed.Core.setVar("USERS1", "FAIL") == True
        assert Ed.Core.getVar("USERS1") == "FAIL"
        assert Ed.Core.cmdS("regcmd3") == True
        assert Ed.Core.getVar("USERS1") == "SUCCESS_3"

    def test_cmdtotestStr4(self):
        assert Ed.Core.setVar("USERS1", "FAIL") == True
        assert Ed.Core.getVar("USERS1") == "FAIL"
        assert Ed.Core.cmdS("regcmd4") == True
        assert Ed.Core.getVar("USERS1") == "SUCCESS_4"

    def test_cmdtotestStr5(self):
        assert Ed.Core.setVar("USERS1", "FAIL") == True
        assert Ed.Core.getVar("USERS1") == "FAIL"
        assert Ed.Core.cmdS("regcmd5") == True
        assert Ed.Core.getVar("USERS1") == "SUCCESS_5"

    def test_cmdtotestStr6(self):
        assert Ed.Core.setVar("USERS1", "FAIL") == True
        assert Ed.Core.getVar("USERS1") == "FAIL"
        assert Ed.Core.cmdS("regcmd6") == True
        assert Ed.Core.getVar("USERS1") == "SUCCESS_6"
