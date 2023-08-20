import PyRx
import PyAp
import PyGi
import PyDb
import PyGe
import PyEd

def OnPyInitApp():
    print("\nadded command pyregedreactor")
    print("\nadded command pyunregedreactor")

def OnPyUnloadApp():
    PyRxCmd_pyunregedreactor()
    
class EdReactor(PyEd.EditorReactor):
    def __init__(self):
        PyEd.EditorReactor.__init__(self)

    def commandWillStart(self, cmdstr):
        print("\ncommandWillStart-{}".format(cmdstr))
        
    def lispWillStart(self, firstLine):
        print("\ncommandWillStart-{}".format(firstLine))
        
    def beginDwgOpen(self, fileName):
        print("\nbeginDwgOpen-{}".format(fileName))
        
    def beginSave(self, db , fileName):
        print("\nbeginSave-{} {}".format(db.getFilename(), fileName))

def PyRxCmd_pyregedreactor():
    try:
        global inst
        inst = EdReactor()
        inst.addReactor()
    except Exception as err:
        print(err)

def PyRxCmd_pyunregedreactor():
    try:
        global inst
        if inst == None:
            return
        inst.removeReactor()
        del(inst)
    except Exception as err:
        print(err)
