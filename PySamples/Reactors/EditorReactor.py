
import PyRxApp 
import PyRx
import PyAp
import PyGi
import PyDb
import PyGe
import PyEd

inst = None #global scope

def OnPyInitApp():
  global inst
  inst = EdReactor()

#TODO check doc.isNull()

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

def PyRxCmd_pyreg_edreactor():
    try:
       inst.addReactor()
    except Exception as err:
        PyRxApp.Printf(err)

def PyRxCmd_pyunreg_edreactor():
    try:
        inst.removeReactor()
    except Exception as err:
        PyRxApp.Printf(err)
