from datetime import date
import PyRx  
import PyGe  
import PyGi 
import PyDb as Db 
import PyAp as Ap
import PyEd  

host = Ap.Application.hostAPI()

showSkipped = False
testVerbosity = 2
logToFile = True
logFileName = "tout-{}-{}.{}".format(host, date.today(), 'txt')
