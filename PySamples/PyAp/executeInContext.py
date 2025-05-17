from pyrx import Rx, Ge, Gs, Gi, Db, Ap, Ed

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
    args.doit()


@Ap.Command()
def exeappctx():
    try:
        data = Data("executeInApplicationContext")
        man = Ap.DocManager()
        man.executeInApplicationContext(worker, data)
    except Exception as err:
        print(err)


@Ap.Command()
def exebappctx():
    try:
        data = Data("beginExecuteInApplicationContext")
        man = Ap.DocManager()
        man.beginExecuteInApplicationContext(worker, data)
    except Exception as err:
        print(err)


# note the session context
@Ap.Command("exebcmdctx", Ap.CmdFlags.SESSION)
def exebcmdctx():
    try:
        data = Data("beginExecuteInCommandContext")
        man = Ap.DocManager()
        print(man.beginExecuteInCommandContext(worker, data))
    except Exception as err:
        print(err)
