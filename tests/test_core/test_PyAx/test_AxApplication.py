from __future__ import annotations

# from pyrx import Ap, Ax -- no autocomplete
from pyrx_imp import Ap, Ax, Ed

def active_document(self):
    axApp = Ap.Application.acadApplication()
    odoc = axApp.activeDocument()
    docs = axApp.documents()
    axDoc1 = docs.add()
    axDoc2 = docs.add()
    axApp.setActiveDocument(axDoc2)
    axDoc3 = axApp.activeDocument()
    assert axDoc2.name() == axDoc3.name()
    axApp.setActiveDocument(odoc)



class TestAxApplication:
    def test_getinstance(self):
        axApp = Ap.Application.acadApplication()
        assert axApp.getHWND != 0
        assert axApp.isVisible()

    def test_get_acadState(self):
        axApp = Ap.Application.acadApplication()
        appState = axApp.acadState()
        assert appState.isQuiescent() == False
        
    def test_get_listArx(self):
        axApp = Ap.Application.acadApplication()
        apps = axApp.listArx()
        assert len(apps) != 0
        
    def test_getset_active_document(self):
        Ap.DocManager().executeInApplicationContext(active_document,None)
        
    def test_window(self):
        axApp = Ap.Application.acadApplication()
        axApp.setWindowState(Ax.AcWindowState.acMax)
        assert axApp.getWindowState() == Ax.AcWindowState.acMax

        
        
        

        
