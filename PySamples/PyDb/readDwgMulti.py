import traceback
from collections import defaultdict
from timeit import default_timer as timer

from pyrx import Ap, Db


def processDb(db : Db.Database, srch : dict[str,int]):
    for id in db.objectIdArray(Db.Entity.desc()):
        if(id.isDerivedFrom(Db.Text.desc())):
            e = Db.Text(id)
            srch[e.textString()] += 1
        elif(id.isDerivedFrom(Db.MText.desc())):
            e = Db.MText(id)
            srch[e.contents()] += 1
            
def worker(path : str, srch : dict[str,int]):
    try:
        db = Db.Database(False, True)
        db.readDwgFile(path)
        db.closeInput(True)
        processDb(db, srch)
    except Exception as e:
        print(f"Error processing {path}: {e}")
        
@Ap.Command()
def doit():
    try:
        start = timer()
        data = defaultdict(int)
        paths =  Ap.Application.listFilesInPath("c:\\drawings", ".dwg")
        for path in paths:
            worker(path, data)
        elapsed_time = timer() - start 
        print(f"Found {len(paths)} paths.")
        print(f"Done processing! Found {len(data)} unique strings.")
        print(f"Total execution time: {elapsed_time:.2f} seconds.")
        
    except Exception:
        print(traceback.format_exc())
