from pyrx import Ap, Ax, Db, Ed, Ge, Rx
import traceback
import random


# Indices: Since Held-Karp returns a tour, indices[0] should be 0, 
# and the last index in the list will be the node that connects back to 0.

@Ap.Command()
def doit1():
    try:
        # Generate 10 random 3D points
        raw_pnts = [Ge.Point3d(random.uniform(0,100), random.uniform(0,100), 0) for _ in range(10)]
        pnts = Ge.Point3dArray(raw_pnts)
        
        print(f"\nComputing shortest tour for {len(pnts)} points...")
        
        # Call your new C++ function
        indices = pnts.shortestTourIndexes()
        
        print(f"Optimal Index Order: {indices}")
        
        # Verify the tour by printing the points in order
        print("\nReordered Path:")
        newPts = []
        for i in indices:
            p = pnts[i]
            newPts.append(pnts[i])
            print(f"Index {i}: ({p.x:.2f}, {p.y:.2f}, {p.z:.2f})")
        
        # create a poly
        db = Db.curDb()
        pl = Db.Polyline3d(Db.Poly3dType.k3dSimplePoly,newPts,True)
        db.addToCurrentspace(pl)
        
    except Exception:
        print(traceback.format_exc())
        
@Ap.Command()
def doit2():
    try:
        # Generate 10 random 3D points
        raw_pnts = [Ge.Point3d(random.uniform(0,100), random.uniform(0,100), 0) for _ in range(10)]
        inpnts = Ge.Point3dArray(raw_pnts)
        
        print(f"\nComputing shortest tour for {len(inpnts)} points...")
        
        # Call your new C++ function
        pnts = inpnts.shortestTour()
        
        # Verify the tour by printing the points in order
        print("\nReordered Path:")
        for p in pnts:
            print(f"({p.x:.2f}, {p.y:.2f}, {p.z:.2f})")
        
        # create a poly
        db = Db.curDb()
        pl = Db.Polyline3d(Db.Poly3dType.k3dSimplePoly,pnts,True)
        db.addToCurrentspace(pl)
        
    except Exception:
        print(traceback.format_exc())
        


@Ap.Command()
def doit3():
    try:
        # Generate 10 random 3D points
        raw_pnts = [Ge.Point3d(random.uniform(0,100), random.uniform(0,100), 0) for _ in range(100)]
        pnts = Ge.Point3dArray(raw_pnts)
        
        print(f"\nComputing shortest tour for {len(pnts)} points...")
        
        # Call your new C++ function
        indices = pnts.approxShortestTourIndexes()
        
        print(f"Optimal Index Order: {indices}")
        
        newPts = []
        for i in indices:
            newPts.append(pnts[i])
        
        # create a poly
        db = Db.curDb()
        pl = Db.Polyline3d(Db.Poly3dType.k3dSimplePoly,newPts,True)
        db.addToCurrentspace(pl)
        
    except Exception:
        print(traceback.format_exc())
        
@Ap.Command()
def doit4():
    try:
        # Generate 10 random 3D points
        raw_pnts = [Ge.Point3d(random.uniform(0,100), random.uniform(0,100), 0) for _ in range(100)]
        inpnts = Ge.Point3dArray(raw_pnts)
        
        print(f"\nComputing shortest tour for {len(inpnts)} points...")
        
        # Call your new C++ function
        pnts = inpnts.approxShortestTour()
        
        # create a poly
        db = Db.curDb()
        pl = Db.Polyline3d(Db.Poly3dType.k3dSimplePoly,pnts,True)
        db.addToCurrentspace(pl)
        
    except Exception:
        print(traceback.format_exc())
        