from __future__ import annotations

from pyrx import Db, Ed


class TestXrefGraph:

    def test_XrefGraph(self, db_xrefGraph: Db.Database):
        wdb = Db.AutoWorkingDatabase(db_xrefGraph)
        Db.Core.resolveCurrentXRefs(Db.workingDb(),True,False)
        gr = Ed.Core.curDwgXrefGraph()
        names = []
        for idx in range(gr.numNodes()):
            node = gr.xrefNode(idx)
            names.append(node.name())
            
        assert "06457" in names
