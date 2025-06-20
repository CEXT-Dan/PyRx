from pyrx import Ap


# lock the document using AutoDocLock default ctor
# is curdoc
def test1():
    lock = Ap.AutoDocLock()
    
    #get the doc from the lock
    doc = lock.doc()
    print(doc == Ap.curDoc())


# lock the document using AutoDocLock other doc ctor
def test2():
    lock = Ap.AutoDocLock(Ap.curDoc())
    doc = lock.doc()
    print(doc == Ap.curDoc())


# get an autolock from the document manager
def test3():
    man = Ap.DocManager()
    mdidoc = man.mdiActiveDocument()
    lock = man.autoLock(mdidoc)
    doc = lock.doc()
    print(doc == mdidoc)


# get an autolock from the document class
def test4():
    man = Ap.DocManager()
    mdidoc = man.mdiActiveDocument()
    lock = mdidoc.autoLock()
    print(mdidoc == lock.doc())


# lock with no autolock
def test5():
    try:
        # Arx
        man = Ap.DocManager()
        mdidoc = man.mdiActiveDocument()
        man.lockDocument(mdidoc, Ap.DocLockMode.kProtectedAutoWrite)
    finally:
        man.unlockDocument(mdidoc)


@Ap.Command()
def doit():
    try:
        test1()
        test2()
        test3()
        test4()
        test5()
    except Exception as e:
        print(e)
