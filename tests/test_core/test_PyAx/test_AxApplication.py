from __future__ import annotations

# from pyrx import Ap, Ax -- no autocomplete
from pyrx_imp import Ap, Ax


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
        axApp = Ap.Application.acadApplication()
        axDoc1 = axApp.activeDocument()
        docs = axApp.documents()
        newdoc = docs.add()
        assert newdoc.name() != axDoc1.name()
        axDoc2 = axApp.activeDocument()
        assert axDoc2.name() != axDoc1.name()
        axApp.setActiveDocument(axDoc1)
        axDoc3 = axApp.activeDocument()
        assert axDoc3.name() == axDoc1.name()
        
        

        
