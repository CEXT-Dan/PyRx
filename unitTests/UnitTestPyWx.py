import os
import unittest
import testcfg


import PyRx as Rx
import PyGe as Ge
import PyGi as Gi
import PyDb as Db
import PyAp as Ap
import PyEd as Ed
import wx

host = Ap.Application.hostAPI()


class TestWxPython(unittest.TestCase):

    def test_get_wxapp(self): #just test possible types 
        pyapp : wx.App = Ap.Application.wxApp()
        topWin : wx.Window = pyapp.TopWindow
        self.assertIsNotNone(topWin)

def pywx():
    try:
        suite = unittest.TestLoader().loadTestsFromTestCase(TestWxPython)
        if testcfg.logToFile:
            with open(testcfg.logFileName, "a") as f:
                f.write("\n{:*^60s}\n".format("TestWxPython"))
                runner = unittest.TextTestRunner(f, verbosity=testcfg.testVerbosity)
                runner.run(suite)
        else:
            print('TestWxPython')
            print(unittest.TextTestRunner(verbosity=testcfg.testVerbosity).run(suite))
    except Exception as err:
        print(err)
