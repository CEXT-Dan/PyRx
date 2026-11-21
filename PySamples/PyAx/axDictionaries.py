import traceback

from pyrx import Ap, Ax, Db


@Ap.Command()
def doit():
    try:
        axapp = Ap.Application.acadApplication()
        axdoc = axapp.activeDocument()
        _dicts = axdoc.dictionaries()
        for item in _dicts:
            if item.objectId().isDerivedFrom(Db.Dictionary.desc()):
                _dict = Ax.AcadDictionary.cast(item)
                print((_dict.objectName(), _dict.name()))
            elif item.objectId().isDerivedFrom(Db.Xrecord.desc()):
                _rec = Ax.AcadXRecord.cast(item)
                print((_rec.objectName(), _rec.name())) 
    except Exception as err:
        traceback.print_exception(err)


@Ap.Command()
def dump_nod():
    try:
        db = Db.curDb()
        nod = Db.Dictionary(db.namedObjectsDictionaryId())
        
        for key_name, obj_id in nod.asDict().items():
            class_name = obj_id.objectClass().name()
            print((class_name, key_name))
            
    except Exception as err:
        traceback.print_exception(err)
