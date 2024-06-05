import os
import unittest
import testcfg

import PyRx as Rx
import PyGe as Ge
import PyGi as Gi
import PyDb as Db
import PyAp as Ap
import PyEd as Ed

host = Ap.Application.hostAPI()


class TestResbuf(unittest.TestCase):
    def __init__(self, *args, **kwargs):
        super(TestResbuf, self).__init__(*args, **kwargs)

    def test_invoke_list(self):
        args = [
            (Rx.LispType.kText, "C:ADDNUM"),
            (Rx.LispType.kInt16, 10),
            (Rx.LispType.kNone, 0),
        ]
        expected = [(5005, "C:ADDNUM"), (5003, 10)]
        result = Db.Core.resbufTest(args)
        self.assertEqual(expected, result)

    def test_invoke_rtdxf0(self):
        args = [(0, "LEADER")]
        expected = [(0, "LEADER")]
        result = Db.Core.resbufTest(args)
        self.assertEqual(expected, result)

    def test_ssfilters(self):
        args = [
            (0, "circle"),
            (-4, "<OR"),
            (40, 6.5),
            (40, 12.5),
            (40, 16.0),
            (-4, "OR>"),
        ]
        expected = [
            (0, "circle"),
            (-4, "<OR"),
            (40, 6.5),
            (40, 12.5),
            (40, 16.0),
            (-4, "OR>"),
        ]
        result = Db.Core.resbufTest(args)
        self.assertEqual(expected, result)

    def test_xdata(self):
        args = [
            (1002, "{"),
            (1070, 1),
            (1002, "{"),
            (1070, 2),
            (1070, 3),
            (1002, "}"),
            (1070, 4),
            (1002, "}"),
        ]
        expected = [
            (1002, "{"),
            (1070, 1),
            (1002, "{"),
            (1070, 2),
            (1070, 3),
            (1002, "}"),
            (1070, 4),
            (1002, "}"),
        ]
        result = Db.Core.resbufTest(args)
        self.assertEqual(expected, result)

    def test_nested(self):
        args = [
            (Rx.LispType.kListBegin, 0),
            (Rx.LispType.kText, "Hi"),
            (Rx.LispType.kListEnd, 0),
            (Rx.LispType.kListBegin, 0),
            (Rx.LispType.kText, "world"),
            (Rx.LispType.kListEnd, 0),
        ]
        
        expected = [
            (Rx.LispType.kListBegin, 0),
            (Rx.LispType.kText, "Hi"),
            (Rx.LispType.kListEnd, 0),
            (Rx.LispType.kListBegin, 0),
            (Rx.LispType.kText, "world"),
            (Rx.LispType.kListEnd, 0),
        ]

        result = Db.Core.resbufTest(args)
        self.assertEqual(result, expected)


def resbuftester():
    try:
        suite = unittest.TestLoader().loadTestsFromTestCase(TestResbuf)
        if testcfg.logToFile:
            with open(testcfg.logFileName, "a") as f:
                f.write("\n{:*^60s}\n".format("TestResbuf"))
                runner = unittest.TextTestRunner(f, verbosity=testcfg.testVerbosity)
                runner.run(suite)
        else:
            print("TestResbuf")
            print(unittest.TextTestRunner(verbosity=testcfg.testVerbosity).run(suite))
    except Exception as err:
        print(err)
