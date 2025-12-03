from __future__ import annotations

from pyrx import Db


class TestDbObjectId:
    def test_property_ids(self):
        id = Db.HostApplicationServices().workingDatabase().blockTableId()
        assert id.isNull() == False
        assert not id.asOldId() == 0
        assert id.isResident() == True
        assert id.isValid() == True
        assert id.database().className() == "AcDbDatabase"
        assert id.database() !=  None
        assert id.objectClass().name() == "AcDbBlockTable"
        assert id.isDerivedFrom(Db.BlockTable.desc())
        assert id.acadObject() != None
                
    def test_handle(self):
        db = Db.HostApplicationServices().workingDatabase()
        id = db.blockTableId()
        bt = Db.BlockTable(id, Db.OpenMode.ForRead)
        hn = bt.getHandle()
        assert hn.isNull() == False
        id2 = db.getObjectId(False,hn)
        assert id == id2
        assert id.isValid() == True
        assert id2.isValid() == True
        #bt.close() crashes icad
        
    def test_ObjectIdArray_clear(self):
        db = Db.curDb()
        ms = db.modelSpace()
        ids = ms.objectIdArray()
        ids.append(db.modelSpaceId())
        assert len(ids) != 0
        ids.clear()
        assert len(ids) == 0
        
    def test_ObjectIdArray_filter(self):
        db = Db.curDb()
        ms = db.modelSpace()
        ids = ms.objectIdArray()
        ids.append(db.modelSpaceId())
        filteredIds = ids.getIdsOfType(Db.BlockTableRecord.desc())
        assert len(filteredIds) == 1
        
    def test_ObjectIdArray_filter2(self):
        db = Db.curDb()
        ms = db.modelSpace()
        ids = ms.objectIdArray()
        ids.append(db.modelSpaceId())
        filteredIds = ids.getIdsOfType([Db.BlockTableRecord.desc()])
        assert len(filteredIds) == 1

        

        
                
                
