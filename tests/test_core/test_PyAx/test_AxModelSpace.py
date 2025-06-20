from __future__ import annotations

import pytest

from pyrx import Ap, Db
from tests import MEDIA_DIR


# modelspace is derived from Block
@pytest.mark.known_failure_GRX
class TestAxModelSpace:
    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDocs = self.axApp.documents()
        self.axDoc = self.axDocs.open(str(MEDIA_DIR / "06457.dwg"), True)

    def teardown_class(self):
        self.axDoc.close(False)

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

    def test_count(self):
        axSpace = self.axDoc.modelSpace()
        assert axSpace.count() != 0

    def test_iter(self):
        axSpace = self.axDoc.modelSpace()
        count = 0
        for item in axSpace:
            count += 1
        assert axSpace.count() == count

    def test_isLayout(self):
        axSpace = self.axDoc.modelSpace()
        assert axSpace.isLayout() == True

    def test_isDynamicBlock(self):
        axSpace = self.axDoc.modelSpace()
        assert axSpace.isDynamicBlock() == False
