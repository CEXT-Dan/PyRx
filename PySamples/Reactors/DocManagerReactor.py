from pyrx_imp import Rx
from pyrx_imp import Ge
from pyrx_imp import Gi
from pyrx_imp import Db
from pyrx_imp import Ap
from pyrx_imp import Ed
from pyrx_imp import Gs


def OnPyInitApp():
    print("\nadded command pyregdocreactor")
    print("\nadded command pyunregdocreactor")


def OnPyUnloadApp():
    PyRxCmd_pyunregdocreactor()


class DocReactor(Ap.DocManagerReactor):
    def __init__(self):
        Ap.DocManagerReactor.__init__(self)

    def documentCreateStarted(self, dwgdoc: Ap.Document):
        if dwgdoc.isNullObj() == False:
            print("\ndocumentCreateStarted-{}".format(dwgdoc.docTitle()))

    def documentCreated(self, dwgdoc: Ap.Document):
        if dwgdoc.isNullObj() == False:
            print("\ndocumentCreated-{}".format(dwgdoc.docTitle()))

    def documentToBeDestroyed(self, dwgdoc: Ap.Document):
        if dwgdoc.isNullObj() == False:
            print("\ndocumentToBeDestroyed-{}".format(dwgdoc.docTitle()))

    def documentDestroyed(self, filename: str):
        print("\ndocumentDestroyed-{}".format(filename))

    def documentCreateCanceled(self, dwgdoc: Ap.Document):
        if dwgdoc.isNullObj() == False:
            print("\ndocumentCreateCanceled-{}".format(dwgdoc.docTitle()))

    def documentLockModeWillChange(self, dwgdoc: Ap.Document,
                                   myCurrentMode, myNewMode, currentMode, pGlobalCmdName):
        if dwgdoc.isNullObj() == False:
            print("\ndocumentLockModeWillChange-{} {} {} {} {}".format(
                dwgdoc.docTitle(), myCurrentMode, myNewMode, currentMode, pGlobalCmdName))

    def documentLockModeChangeVetoed(self, dwgdoc: Ap.Document, pGlobalCmdName):
        if dwgdoc.isNullObj() == False:
            print("\ndocumentLockModeChangeVetoed-{} {}".format(
                dwgdoc.docTitle(), pGlobalCmdName))

    def documentLockModeChanged(self, dwgdoc: Ap.Document,
                                myPreviousMode, myCurrentMode, currentMode, pGlobalCmdName):
        if dwgdoc.isNullObj() == False:
            print("\ndocumentLockModeChanged-{} {} {} {} {}".format(
                dwgdoc.docTitle(), myCurrentMode, myPreviousMode, currentMode, pGlobalCmdName))

    def documentBecameCurrent(self, dwgdoc: Ap.Document):
        if dwgdoc.isNullObj() == False:
            print("\ndocumentBecameCurrent-{}".format(dwgdoc.docTitle()))

    def documentToBeActivated(self, dwgdoc: Ap.Document):
        if dwgdoc.isNullObj() == False:
            print("\ndocumentToBeActivated-{}".format(dwgdoc.docTitle()))

    def documentToBeDeactivated(self, dwgdoc: Ap.Document):
        if dwgdoc.isNullObj() == False:
            print("\ndocumentToBeDeactivated-{}".format(dwgdoc.docTitle()))

    def documentActivationModified(self, bActivation: bool):
        print("\ndocumentToBeDeactivated-{}".format(bActivation))

    def documentToBeDeactivated(self, dwgdoc: Ap.Document):
        if dwgdoc.isNullObj() == False:
            print("\ndocumentToBeDeactivated-{}".format(dwgdoc.docTitle()))


def PyRxCmd_pyregdocreactor():
    try:
        global docReactorInstance
        docReactorInstance = DocReactor()
        docReactorInstance.addReactor()
    except Exception as err:
        print(err)


def PyRxCmd_pyunregdocreactor():
    try:
        global docReactorInstance
        if docReactorInstance == None:
            return
        docReactorInstance.removeReactor()
        del (docReactorInstance)
    except Exception as err:
        print(err)
