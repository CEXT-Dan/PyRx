from __future__ import annotations
import pytest
from tests import MEDIA_DIR
from pyrx import Ap, Ge, Db, Ax, Ed


# modelspace is derived from Block
class TestAxModelSpace:

    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDocs = self.axApp.documents()
        self.axDoc = self.axDocs.open(str(MEDIA_DIR / "06457.dwg"), True)

    def teardown_class(self):
        pass

    # we can't set this to the active doccument here becuse
    # we are in a command context, the doument is locked
    def test_objectId(self):
        docMan = Ap.DocManager()
        id1 = self.axDoc.modelSpace().objectId()
        id2 = Db.ObjectId()
        for doc in docMan.documents():
            if self.axDoc.name() in doc.fileName():
                id2 = doc.database().modelSpaceId()
                break
        assert id2 == id1
