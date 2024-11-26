import datetime
import PyRx as Rx
import PyGe as Ge
import PyGi as Gi
import PyDb as Db
import PyAp as Ap
import PyEd as Ed
from enum import IntFlag

host = Ap.Application.hostAPI()


def makeLogFileName():
    fname = "tout-{}-{}-{}".format(
        host, datetime.datetime.today(), datetime.datetime.now()
    )
    fname = fname.replace(".", "_")
    fname = fname.replace(":", "_")
    fname = fname.replace("-", "_")
    name = "testResults/{}.{}".format(fname, "txt")
    return name


# settings
testVerbosity = 2  # 2 for logfile, 0 for on screan
logToFile = True
logFileName = makeLogFileName()
TEST_LEVEL = 0

class ETFlags(IntFlag):
    eNone = 0
    eARX = 1
    eBRX = 2
    eGRX = 4
    eZRX = 8

def makeSkip(flags: ETFlags):
    if TEST_LEVEL == 1:
        return (False, "Full test")
    if ETFlags.eARX & flags:
        return (True, "known failure in ARX")
    if ETFlags.eBRX & flags:
        return (True, "known failure in BRX")
    if ETFlags.eGRX & flags:
        return (True, "known failure in GRX")
    if ETFlags.eZRX & flags:
        return (True, "known failure in ZRX")
