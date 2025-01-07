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


def gethostflag():
    if "ARX" in host:
        return ETFlags.eARX
    elif "BRX" in host:
        return ETFlags.eBRX
    elif "GRX" in host:
        return ETFlags.eGRX
    elif "ZRX" in host:
        return ETFlags.eZRX
    return ETFlags.eNone

g_hostflag = gethostflag()

def makeSkip(flags: ETFlags):
    if TEST_LEVEL == 1:
        return (False, "Full test")
    if flags & g_hostflag:
        return (True, "known failure")
    return (False, "Ok")
