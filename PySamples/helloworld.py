import traceback
from pyrx_imp import Rx, Ge, Gi, Db, Ap, Ed

print("Added new command helloworld, type helloworld at the prompt: ")

def PyRxCmd_helloworld() -> None:
    try:
        print("whats up!: ")
    except Exception as err:
        traceback.print_exception(err)
        
