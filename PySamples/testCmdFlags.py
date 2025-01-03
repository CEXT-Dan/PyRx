import traceback
from pyrx_imp import Rx, Ge, Gi, Db, Ap, Ed

# MODAL           
# TRANSPARENT     
# USEPICKSET      
# REDRAW          
# NOPERSPECTIVE   
# NOMULTIPLE      
# NOTILEMODE      
# NOPAPERSPACE    
# NOOEM           
# UNDEFINED       
# INPROGRESS      
# DEFUN           
# NOINTERNALLOCK  
# DOCREADLOCK     
# DOCEXCLUSIVELOCK
# SESSION         
# INTERRUPTIBLE   
# NOHISTORY       
# NO_UNDO_MARKER  
# NOBEDIT         


#not case sensitive
def PyRxCmd_pynohist(CmDFlags = Ap.CmdFlags.NOHISTORY):
    try:
        print(CmDFlags)
    except Exception as err:
        print(err)
     
# or them up   
def PyRxCmd_pynobedit(CmdFlags = Ap.CmdFlags.NOHISTORY | Ap.CmdFlags.NOBEDIT):
    try:
        print(CmdFlags)
    except Exception as err:
        print(err)
        
# or them up   
def PyRxCmd_pynopaper(CmdFlags = Ap.CmdFlags.TRANSPARENT | Ap.CmdFlags.NOPAPERSPACE):
    try:
        print(CmdFlags)
    except Exception as err:
        print(err)
        
#session 
def PyRxCmd_session(CmdFlags = Ap.CmdFlags.SESSION):
    try:
        print(CmdFlags)
    except Exception as err:
        print(err)
        
#new way     
@Ap.Command("foo", Ap.ICmdFlags.kMODAL)
def foo():
    try:
        print("cmdfoo")
    except Exception as err:
        traceback.print_exception(err)
        
@Ap.Command("far")
def far():
    try:
        print("cmdfar")
    except Exception as err:
        traceback.print_exception(err)
