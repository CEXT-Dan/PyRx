from __future__ import annotations

from pyrx import Ap, Ax


class TestDocument:

    def test_get_acad_app(self):
        doc = Ap.curDoc()
        axDoc: Ax.AcadDocument = doc.acadDocument()
        assert doc.database().modelSpaceId() == axDoc.modelSpace().objectId()
