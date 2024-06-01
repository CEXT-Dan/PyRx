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
        args = [(Rx.LispType.kText, "C:ADDNUM"),(Rx.LispType.kInt16,10),(Rx.LispType.kNone,0) ]
        expected = [(5005, 'C:ADDNUM'), (5003, 10)]
        result = Db.Core.resbufTest(args)
        self.assertEqual(expected,result)
        
    def test_invoke_rtdxf0(self):
        args = [(0 , "LEADER")]
        expected = [(0 , "LEADER")]
        result = Db.Core.resbufTest(args)
        self.assertEqual(expected,result)
        
def resbuftester():
    try:
        suite = unittest.TestLoader().loadTestsFromTestCase(TestResbuf)
        if testcfg.logToFile:
            with open(testcfg.logFileName, "a") as f:
                f.write("\n{:*^60s}\n".format("TestResbuf"))
                runner = unittest.TextTestRunner(f, verbosity=testcfg.testVerbosity)
                runner.run(suite)
        else:
            print('TestResbuf')
            print(unittest.TextTestRunner(verbosity=testcfg.testVerbosity).run(suite))
    except Exception as err:
        print(err)
