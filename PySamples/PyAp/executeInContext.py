from pyrx_imp import Rx, Ge, Gs, Gi, Db, Ap, Ed

print("command = exeappctx")
print("command = execmdctx")

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
    args.doit()
    

def PyRxCmd_exeappctx():
    try:
        data = Data("executeInApplicationContext")
        man = Ap.DocManager()
        man.executeInApplicationContext(worker, data)
    except Exception as err:
        print(err)


def PyRxCmd_execmdctx(CmdFlags=Ap.CmdFlags.SESSION):
    try:
        data = Data("beginExecuteInCommandContext")
        man = Ap.DocManager()
        print(man.beginExecuteInCommandContext(worker, data))
    except Exception as err:
        print(err)
