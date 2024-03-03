import os
import PyRx
import psutil


#requires psutil
#proof that we are running in process

def PyRxCmd_curproc():
	print(psutil.Process(os.getpid()).name())


		
		

