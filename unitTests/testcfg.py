from datetime import date
import PyRx as Rx
import PyGe as Ge 
import PyGi as Gi
import PyDb as Db 
import PyAp as Ap
import PyEd as Ed 

host = Ap.Application.hostAPI()

#settings
testVerbosity = 2
logToFile = True
logFileName = "tout-{}-{}.{}".format(host, date.today(), 'txt')
