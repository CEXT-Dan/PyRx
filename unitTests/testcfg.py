from datetime import date
import PyAp as Ap

host = Ap.Application.hostAPI()

showSkipped = False
testVerbosity = 2
logToFile = True
logFileName = "tout-{}-{}.{}".format(host, date.today(), 'txt')
