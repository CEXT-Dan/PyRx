from pyrx_imp import Rx
from pyrx_imp import Ge
from pyrx_imp import Gi
from pyrx_imp import Db
from pyrx_imp import Ap
from pyrx_imp import Ed
from pyrx_imp import Gs

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