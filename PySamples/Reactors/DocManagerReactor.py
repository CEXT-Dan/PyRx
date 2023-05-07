
import PyRxApp 
import PyRx
import PyAp

inst = None #global scope

def OnPyInitApp():
  global inst
  inst = DocReactor()

#TODO check doc.isNull()

class DocReactor(PyAp.DocManagerReactor):
    def __init__(self):
        PyAp.DocManagerReactor.__init__(self)

    def documentCreateStarted(self, dwgdoc):
        print("\ndocumentCreateStarted-{}".format(dwgdoc.docTitle()))

    def documentCreated(self, dwgdoc):
        print("\ndocumentCreated-{}".format(dwgdoc.docTitle()))

    def documentToBeDestroyed(self, dwgdoc):
        print("\ndocumentToBeDestroyed-{}".format(dwgdoc.docTitle()))

    def documentDestroyed(self, filename):
        print("\ndocumentDestroyed-{}".format(filename))

    def documentCreateCanceled(self, dwgdoc):
        print("\ndocumentCreateCanceled-{}".format(dwgdoc.docTitle()))

    def documentLockModeWillChange(self, dwgdoc, myCurrentMode, myNewMode, currentMode, pGlobalCmdName):
        print("\ndocumentLockModeWillChange-{} {} {} {} {}".format(dwgdoc.docTitle(),
              myCurrentMode, myNewMode, currentMode, pGlobalCmdName))

    def documentLockModeChangeVetoed(self, dwgdoc, pGlobalCmdName):
        print("\ndocumentLockModeChangeVetoed-{} {}".format(dwgdoc.docTitle(), pGlobalCmdName))

    def documentLockModeChanged(self, dwgdoc, myPreviousMode, myCurrentMode, currentMode, pGlobalCmdName):
        print("\ndocumentLockModeChanged-{} {} {} {} {}".format(dwgdoc.docTitle(),
              myCurrentMode, myPreviousMode, currentMode, pGlobalCmdName))

    def documentBecameCurrent(self, dwgdoc):
        print("\ndocumentBecameCurrent-{}".format(dwgdoc.docTitle()))

    def documentToBeActivated(self, dwgdoc):
        print("\ndocumentToBeActivated-{}".format(dwgdoc.docTitle()))

    def documentToBeDeactivated(self, dwgdoc):
        print("\ndocumentToBeDeactivated-{}".format(dwgdoc.docTitle()))

    def documentActivationModified(self, bActivation):
        print("\ndocumentToBeDeactivated-{}".format(bActivation))

    def documentToBeDeactivated(self, dwgdoc):
        print("\ndocumentToBeDeactivated-{}".format(dwgdoc.docTitle()))

def PyRxCmd_pyregdocreactor():
    try:
       inst.addReactor()
    except Exception as err:
        PyRxApp.Printf(err)

def PyRxCmd_pyunregdocreactor():
    try:
        inst.removeReactor()
    except Exception as err:
        PyRxApp.Printf(err)
