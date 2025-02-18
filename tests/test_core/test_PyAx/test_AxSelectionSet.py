from __future__ import annotations
import pytest
from tests import MEDIA_DIR
from pyrx import Ap, Ge, Db, Ax, Ed


class TestAxSelectionSet:
    def setup_class(self):
        self.axApp = Ap.Application.acadApplication()
        self.axDoc =  self.axApp.activeDocument()
        self.axSpace =  self.axDoc.modelSpace()
        for idx1 in range(1,49):
            for idx2 in range(1,49):
                self.axSpace.addPoint(Ge.Point3d(idx1,idx2,0))   
        for idx1 in range(1,49):
            self.axSpace.addLine(Ge.Point3d(0,idx1,0),Ge.Point3d(0,idx1,0))
            
    def test_sscount(self):
        axSets = self.axDoc.selectionSets()
        sscount = axSets.count()# brx has in not zero?
        axSet = axSets.add("PYRX1")
        assert axSets.count() == sscount + 1
        axSet.delete()
        assert axSets.count() == sscount
        
    def test_selectAllFilter(self):
        axSets = self.axDoc.selectionSets()
        axSet = axSets.add("PYRX2")
        axSet.selectAll([(0, "POINT")])
        count = axSet.count()
        cnt1 = 0
        for ent in axSet.entities():
            cnt1 += 1
        cnt2 = 0
        for ent in axSet:
            cnt2 += 1
        ent : Ax.AcadEntity 
        for ent in axSet:
            assert ent.objectName() == "AcDbPoint"
        axSet.delete()
        assert count >= 2304
        assert cnt1 >= 2304
        assert cnt2 >= 2304