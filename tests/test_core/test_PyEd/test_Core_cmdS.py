from __future__ import annotations

from pyrx import Ap, Ed, Rx, command


@command
def cmdtotest1():
    Ed.Core.setVar("USERS1", "SUCCESS")


@Ap.Command()
def cmdtotest2():
    Ed.Core.setVar("USERS1", "SUCCESS")


def PyRxCmd_cmdtotest3():
    Ed.Core.setVar("USERS1", "SUCCESS")


class TestAcedCmdS:

    def setup_class(self):
        Ap.Application.loadPythonModule(str(__file__))

    def test_cmdtotestRb1(self):
        assert Ed.Core.setVar("USERS1", "FAIL") == True
        assert Ed.Core.getVar("USERS1") == "FAIL"
        resbuf = [
            (Rx.LispType.kText, "cmdtotest1"),
            (Rx.LispType.kNone, 0),
        ]
        assert Ed.Core.cmdS(resbuf) == True
        assert Ed.Core.getVar("USERS1") == "SUCCESS"

    def test_cmdtotestRb2(self):
        assert Ed.Core.setVar("USERS1", "FAIL") == True
        assert Ed.Core.getVar("USERS1") == "FAIL"
        resbuf = [
            (Rx.LispType.kText, "cmdtotest2"),
            (Rx.LispType.kNone, 0),
        ]
        assert Ed.Core.cmdS(resbuf) == True
        assert Ed.Core.getVar("USERS1") == "SUCCESS"

    def test_cmdtotestRb3(self):
        assert Ed.Core.setVar("USERS1", "FAIL") == True
        assert Ed.Core.getVar("USERS1") == "FAIL"
        resbuf = [
            (Rx.LispType.kText, "cmdtotest3"),
            (Rx.LispType.kNone, 0),
        ]
        assert Ed.Core.cmdS(resbuf) == True
        assert Ed.Core.getVar("USERS1") == "SUCCESS"

    def test_cmdtotestStr1(self):
        assert Ed.Core.setVar("USERS1", "FAIL") == True
        assert Ed.Core.getVar("USERS1") == "FAIL"
        assert Ed.Core.cmdS("cmdtotest1") == True
        assert Ed.Core.getVar("USERS1") == "SUCCESS"

    def test_cmdtotestStr2(self):
        assert Ed.Core.setVar("USERS1", "FAIL") == True
        assert Ed.Core.getVar("USERS1") == "FAIL"
        assert Ed.Core.cmdS("cmdtotest2") == True
        assert Ed.Core.getVar("USERS1") == "SUCCESS"

    def test_cmdtotestStr3(self):
        assert Ed.Core.setVar("USERS1", "FAIL") == True
        assert Ed.Core.getVar("USERS1") == "FAIL"
        assert Ed.Core.cmdS("cmdtotest3") == True
        assert Ed.Core.getVar("USERS1") == "SUCCESS"
