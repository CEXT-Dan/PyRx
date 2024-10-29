from pyrx_imp import Rx, Ge, Gs, Gi, Db, Ap, Ed

print("command = exeappctx")
print("command = exebappctx")
print("command = exebcmdctx")

class Data:
    def __init__(self, message):
        print("ctor")
        self.message = message

    def __del__(self):
        print("dtor")

    def classWorker(self, args=None):
        print(args.message)
        
    def doit(self):
        print(self.message)


def worker(args=None):
    #call Data.doit()
    args.doit()
    

def PyRxCmd_exeappctx():
    try:
        data = Data("executeInApplicationContext")
        man = Ap.DocManager()
        man.executeInApplicationContext(worker, data)
    except Exception as err:
        print(err)
        
def PyRxCmd_exebappctx():
    try:
        data = Data("beginExecuteInApplicationContext")
        man = Ap.DocManager()
        man.beginExecuteInApplicationContext(worker, data)
    except Exception as err:
        print(err)

#note the session context
def PyRxCmd_exebcmdctx(CmdFlags=Ap.CmdFlags.SESSION):
    try:
        data = Data("beginExecuteInCommandContext")
        man = Ap.DocManager()
        print(man.beginExecuteInCommandContext(worker, data))
    except Exception as err:
        print(err)
