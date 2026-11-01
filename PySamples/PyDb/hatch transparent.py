import traceback

from pyrx import Ap, Db, Ed, Ge

_index = 1

def makeBoundary(db: Db.Database, pnt: Ge.Point3d, tr: Db.Transparency):
    ids = []
    plines = Ed.Editor.traceBoundary(pnt, False)
    for pline in plines:
        pline.setColorIndex(_index) # Uses the global integer
        pline.setTransparency(tr)
        ids.append(db.addToModelspace(pline))
    return ids

@Ap.Command()
def doit():
    global _index
    try:
        db = Db.curDb()
        tr = Db.Transparency(0.5) #50%
        
        ps, pnt = Ed.Editor.getPoint("\nSelect internal point: ")
        if ps != Ed.PromptStatus.eOk:
            return
        
        # 1. Generate the boundary polylines
        ids = makeBoundary(db, pnt, tr)
        if not ids:
            print("\nNo boundary found.")
            return
        
        # 2. Create and configure the Hatch object
        hat = Db.Hatch()
        hat.setPattern(Db.HatchPatternType.kPreDefined, "SOLID")
        hat.setColorIndex(_index)
        hat.setTransparency(tr)
        
        # 3. Add hatch to model space BEFORE appending loops (AutoCAD requirement)
        db.addToModelspace(hat)
        
        # 4. Establish associativity and evaluate
        hat.setAssociative(True)
        hat.appendLoop(Db.HatchLoopType.kDefault, ids)
        hat.evaluateHatch(True)
        
        print(f"\nCreated boundary and hatch with Color Index: {_index}")
        
        # 5. Increment color index (Cycle back to 1 if it exceeds standard ACI 255)
        _index += 1
        if _index > 255:
            _index = 1
            
    except Exception:
        print("Error encountered:")
        traceback.print_exc()
