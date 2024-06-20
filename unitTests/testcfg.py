import datetime
import PyRx as Rx
import PyGe as Ge 
import PyGi as Gi
import PyDb as Db 
import PyAp as Ap
import PyEd as Ed 

host = Ap.Application.hostAPI()

def makeLogFileName():
    fname = "tout-{}-{}-{}".format(host, datetime.datetime.today(), datetime.datetime.now())
    fname = fname.replace('.','_')
    fname = fname.replace(':','_')
    fname = fname.replace('-','_')
    name = "testResults/{}.{}".format(fname, 'txt')
    return name

#settings
testVerbosity = 2#2 for logfile, 0 for on screan
logToFile = True
logFileName = makeLogFileName()
