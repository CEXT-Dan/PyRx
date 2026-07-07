import traceback

from pyrx import Ap, Db


def validate_layout(source_db: Db.Database, target_db: Db.Database, layout_name: str):
    """Validates if the layout exists in source and is safe to write to target."""
    source_layout_dict = Db.Dictionary(source_db.layoutDictionaryId())
    if not source_layout_dict.has(layout_name):
        print(f"Layout '{layout_name}' not found in source drawing.")
        return False

    target_layout_dict = Db.Dictionary(target_db.layoutDictionaryId())
    if target_layout_dict.has(layout_name):
        print(f"Layout '{layout_name}' already exists in target drawing.")
        return False

    return True


def clone_layout_from_db(source_db: Db.Database, target_db: Db.Database, layout_name: str):
    """Clones a specified layout from a source database to a target database layout dictionary."""
    if not validate_layout(source_db, target_db, layout_name):
        return False

    try:
        source_layout_dict = Db.Dictionary(source_db.layoutDictionaryId())
        source_layout_id = source_layout_dict.getAt(layout_name)
        
        id_map = Db.IdMapping()
        id_map.setDestDb(target_db)
        
        source_db.wblockCloneObjects(
            [source_layout_id],
            target_db.layoutDictionaryId(),
            id_map,
            Db.DuplicateRecordCloning.kDrcIgnore,
        )
        return True
        
    except Exception as e:
        print(f"Error encountered during cloning: {e}")
        traceback.print_exc()
        return False


@Ap.Command()
def doit():
    layout_name = "S7"
    source_path = r"E:\Batch\06457 RE Submittal.dwg"

    target_db = Db.curDb()
    
    try:
        source_db = Db.Database.createFromDWG(source_path)
        
        if clone_layout_from_db(source_db, target_db, layout_name):
            print(f"Successfully cloned layout '{layout_name}'.")
            
            manager = Ap.LayoutManager()
            manager.updateLayoutTabs()
            
    except Exception as err:
        print(f"Failed to load or process source drawing: {err}")
