from __future__ import annotations
from pyrx import Ap, Ge, Ax

def split_list(a_list):
    half = len(a_list)//2
    return a_list[:half], a_list[half:]

class TestAxPoint:

    def test_add_remove(self):
        axApp = Ap.Application.acadApplication()
        axDoc = axApp.activeDocument()
        axModel = axDoc.modelSpace()
        points = []
        for i in range(0,10):
            points.append(axModel.addPoint(Ge.Point3d(i,i,0)))
        axGroups = axDoc.groups()
        axGroup =  axGroups.add("WOOHOO")
        axGroup.appendItems(points)
        assert len(axGroup.items()) == 10
        pleft, _ = split_list(points)
        axGroup.removeItems(pleft)
        assert len(axGroup.items()) == 5
        


