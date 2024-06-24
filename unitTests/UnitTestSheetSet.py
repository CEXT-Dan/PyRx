import os
import unittest
import testcfg

import PyRx as Rx
import PyGe as Ge
import PyGi as Gi
import PyDb as Db
import PyAp as Ap
import PyEd as Ed
import PySm as Sm

host = Ap.Application.hostAPI()


class TestSheetSet(unittest.TestCase):
    def __init__(self, *args, **kwargs):
        super(TestSheetSet, self).__init__(*args, **kwargs)

    def test_binary_chunk(self):
        args = [(Db.DxfCode.kDxfBinaryChunk, bytes(b'mystring1'))]
        expected = [(Db.DxfCode.kDxfBinaryChunk, bytes(b'mystring1'))]
        result = Db.Core.resbufTest(args)
        self.assertEqual(result, expected)
        
    def test_empty_string(self):
        args = [(Rx.LispType.kText, None)]
        expected = [(Rx.LispType.kText, "")]
        result = Db.Core.resbufTest(args)
        self.assertEqual(result, expected)


def sheetSetTester():
    try:
        suite = unittest.TestLoader().loadTestsFromTestCase(TestSheetSet)
        if testcfg.logToFile:
            with open(testcfg.logFileName, "a") as f:
                f.write("\n{:*^60s}\n".format("TestSheetSet"))
                runner = unittest.TextTestRunner(f, verbosity=testcfg.testVerbosity)
                runner.run(suite)
        else:
            print("TestSheetSet")
            print(unittest.TextTestRunner(verbosity=testcfg.testVerbosity).run(suite))
    except Exception as err:
        print(err)
