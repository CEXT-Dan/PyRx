import os
import unittest
import testcfg

import PyRx as Rx
import PyGe as Ge
import PyGi as Gi
import PyDb as Db
import PyAp as Ap
import PyEd as Ed
import sqlite3


host = Ap.Application.hostAPI()

def lookupDocString(docstringkey, conn: sqlite3.Connection):
    try:
        if docstringkey != "-1":
            cur = conn.cursor()
            cur.execute("SELECT VALUE FROM DOCSTRINGS WHERE ID=?", (docstringkey,))
            ds = cur.fetchone()
            if len(ds) != 0:
                return ds[0].replace(u'\xa0', u'').strip()#oops
        return ''
    except:
        return ''
    
def lookupRowNumber(docstringkey, conn: sqlite3.Connection):
    try:
        if docstringkey != "-1":
            cur = conn.cursor()
            cur.execute("SELECT ROWID, ID FROM DOCSTRINGS WHERE ID=?", (docstringkey,))
            return cur.fetchone()
        return (-1, 1)
    except:
        return (-1, 1)


class TestDocString(unittest.TestCase):
    def __init__(self, *args, **kwargs):
        super(TestDocString, self).__init__(*args, **kwargs)
        self.conn = sqlite3.connect("..\\PyRxStubs\\DocString.db", isolation_level='DEFERRED') 
        
    def __del__(self):
        self.conn.close()


    def test_datbase_valid(self):
        self.assertEqual(lookupDocString("12", self.conn),'Description')
        self.assertEqual(lookupDocString("1035", self.conn),'Destructor.')
        self.assertEqual(lookupDocString("2024", self.conn),'Description')
        self.assertEqual(lookupDocString("4025", self.conn),'Destructor.')
        self.assertEqual(lookupDocString("5033", self.conn),'Destructor.')
        self.assertEqual(lookupDocString("6026", self.conn),'Destructor.')
        self.assertEqual(lookupDocString("7069", self.conn),'Destructor.')
        self.assertEqual(lookupDocString("8030", self.conn),'Destructor.')
        self.assertEqual(lookupDocString("9079", self.conn),'Destructor.')
        self.assertEqual(lookupDocString("10187", self.conn),'Destructor.')
        self.assertEqual(lookupDocString("10187", self.conn),'Destructor.')
        self.assertEqual(lookupDocString("12056", self.conn),'Destructor.')
        self.assertEqual(lookupDocString("14117", self.conn),'Destructor.')
        self.assertEqual(lookupDocString("16123", self.conn),'Destructor.')
        self.assertEqual(lookupDocString("18573", self.conn),'Destructor.')
        self.assertEqual(lookupDocString("19132", self.conn),'Description')
        
    def test_datbase_keys(self):
        for idx in range(1,19000,1000):
            self.assertEqual(lookupRowNumber("{}".format(idx), self.conn),(idx, idx))
        self.assertEqual(lookupRowNumber("19134", self.conn),(19134, 19134))

def docstringtester():
    try:
        suite = unittest.TestLoader().loadTestsFromTestCase(TestDocString)
        if testcfg.logToFile:
            with open(testcfg.logFileName, "a") as f:
                f.write("\n{:*^60s}\n".format("TestDocString"))
                runner = unittest.TextTestRunner(f, verbosity=testcfg.testVerbosity)
                runner.run(suite)
        else:
            print('TestDocString')
            print(unittest.TextTestRunner(verbosity=testcfg.testVerbosity).run(suite))
    except Exception as err:
        print(err)
