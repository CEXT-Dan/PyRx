import os
import PyRxApp
import psutil


#requires psutil
#proof that we are running in process

def PyRxCmd_curproc():
	PyRxApp.Printf(psutil.Process(os.getpid()).name())


		
		

