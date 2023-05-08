
import PyRxApp
import PyRx
import PyAp

inst = None  # global scope


#Check if the doc is null, it can happen, i.e. on the start tab


def OnPyInitApp():
  global inst
  inst = DocReactor()


class DocReactor(PyAp.DocManagerReactor):
    def __init__(self):
        PyAp.DocManagerReactor.__init__(self)

    def documentCreateStarted(self, dwgdoc):
        if dwgdoc.isNull() == False:
            print("\ndocumentCreateStarted-{}".format(dwgdoc.docTitle()))

    def documentCreated(self, dwgdoc):
        if dwgdoc.isNull() == False:
            print("\ndocumentCreated-{}".format(dwgdoc.docTitle()))

    def documentToBeDestroyed(self, dwgdoc):
        if dwgdoc.isNull() == False:
            print("\ndocumentToBeDestroyed-{}".format(dwgdoc.docTitle()))

    def documentDestroyed(self, filename):
        print("\ndocumentDestroyed-{}".format(filename))

    def documentCreateCanceled(self, dwgdoc):
        if dwgdoc.isNull() == False:
            print("\ndocumentCreateCanceled-{}".format(dwgdoc.docTitle()))

    def documentLockModeWillChange(self, dwgdoc, myCurrentMode, myNewMode, currentMode, pGlobalCmdName):
        if dwgdoc.isNull() == False:
            print("\ndocumentLockModeWillChange-{} {} {} {} {}".format(dwgdoc.docTitle(),
                myCurrentMode, myNewMode, currentMode, pGlobalCmdName))

    def documentLockModeChangeVetoed(self, dwgdoc, pGlobalCmdName):
        if dwgdoc.isNull() == False:
            print("\ndocumentLockModeChangeVetoed-{} {}".format(dwgdoc.docTitle(), pGlobalCmdName))

    def documentLockModeChanged(self, dwgdoc, myPreviousMode, myCurrentMode, currentMode, pGlobalCmdName):
        if dwgdoc.isNull() == False:
            print("\ndocumentLockModeChanged-{} {} {} {} {}".format(dwgdoc.docTitle(),
              myCurrentMode, myPreviousMode, currentMode, pGlobalCmdName))

    def documentBecameCurrent(self, dwgdoc):
        if dwgdoc.isNull() == False:
            print("\ndocumentBecameCurrent-{}".format(dwgdoc.docTitle()))

    def documentToBeActivated(self, dwgdoc):
        if dwgdoc.isNull() == False:
            print("\ndocumentToBeActivated-{}".format(dwgdoc.docTitle()))

    def documentToBeDeactivated(self, dwgdoc):
        if dwgdoc.isNull() == False:
            print("\ndocumentToBeDeactivated-{}".format(dwgdoc.docTitle()))

    def documentActivationModified(self, bActivation):
        print("\ndocumentToBeDeactivated-{}".format(bActivation))

    def documentToBeDeactivated(self, dwgdoc):
        if dwgdoc.isNull() == False:
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
