import time
import random
import traceback
from array import array
from pyrx import Ap, Db, Ed, Ge
from concurrent.futures import InterpreterPoolExecutor

# -----------------------------------------------------------
# Worker
# -----------------------------------------------------------
def tsp_3opt_worker(path_data: array):
    import math

    def total_distance(flat_floats: array) -> float:
        dist = 0.0
        n = len(flat_floats) // 3
        for i in range(n):
            idx1 = i * 3
            j = i + 1
            if j == n:
                j = 0
            idx2 = j * 3
            a0 = flat_floats[idx1]
            a1 = flat_floats[idx1 + 1]
            a2 = flat_floats[idx1 + 2]
            b0 = flat_floats[idx2]
            b1 = flat_floats[idx2 + 1]
            b2 = flat_floats[idx2 + 2]
            dx = a0 - b0
            dy = a1 - b1
            dz = a2 - b2
            dist += math.sqrt(dx * dx + dy * dy + dz * dz)
        return dist

    def swap_3opt(arr: array, i: int, j: int, k: int, case: int) -> array:
        i3 = i * 3
        j3 = j * 3
        k3 = k * 3
        part1 = arr[:i3]
        part2 = arr[i3:j3]
        part3 = arr[j3:k3]
        part4 = arr[k3:]
        
        if case == 0:
            pts = len(part3) // 3
            for idx in range(pts // 2):
                s1 = idx * 3
                s2 = (pts - idx - 1) * 3
                tmp = part3[s1 : s1 + 3]
                part3[s1 : s1 + 3] = part3[s2 : s2 + 3]
                part3[s2 : s2 + 3] = tmp
            return part1 + part2 + part3 + part4
        elif case == 1:
            pts = len(part2) // 3
            for idx in range(pts // 2):
                s1 = idx * 3
                s2 = (pts - idx - 1) * 3
                tmp = part2[s1 : s1 + 3]
                part2[s1 : s1 + 3] = part2[s2 : s2 + 3]
                part2[s2 : s2 + 3] = tmp
            return part1 + part2 + part3 + part4
        else:
            return part1 + part3 + part2 + part4

    n_points = len(path_data) // 3
    best_path = path_data
    best_dist = total_distance(best_path)
    improved = True

    while improved:
        improved = False
        for i in range(n_points - 2):
            for j in range(i + 1, n_points - 1):
                for k in range(j + 1, n_points):
                    for case in range(3):

                        candidate = swap_3opt(
                            best_path,
                            i,
                            j,
                            k,
                            case,
                        )
                        candidate_dist = total_distance(candidate)

                        if candidate_dist < best_dist:
                            best_dist = candidate_dist
                            best_path = candidate
                            improved = True
                            break

                    if improved:
                        break
                if improved:
                    break
            if improved:
                break

    return (best_dist, best_path)


# -----------------------------------------------------------
# Driver
# -----------------------------------------------------------
def tsp_3opt_driver(pnts: list[Ge.Point3d]):

    flat_base_points = [(p.x, p.y, p.z) for p in pnts]
    inputs = []
    for _ in range(16):
        shuffled = list(flat_base_points)
        random.shuffle(shuffled)
        arr = array("d")
        for pt in shuffled:
            arr.extend(pt)
        inputs.append(arr)

    print("Running InterpreterPoolExecutor...")
    start_time = time.perf_counter()
    with InterpreterPoolExecutor(max_workers=16) as executor:
        results = list(
            executor.map(
                tsp_3opt_worker,
                inputs,
            )
        )
    elapsed = time.perf_counter() - start_time
    shortest_distance, best_flat_coords = min(results, key=lambda x: x[0])
    longest_distance, best_flat_coords = max(results, key=lambda x: x[0])
    final_points = []

    for i in range(0, len(best_flat_coords), 3):
        final_points.append(
            Ge.Point3d(
                best_flat_coords[i],
                best_flat_coords[i + 1],
                best_flat_coords[i + 2],
            )
        )
        
    db = Db.curDb()
    pl = Db.Polyline(final_points)
    pl.setColorIndex(3)
    pl.setClosed(True)
    db.addToCurrentspace(pl)

    print(f"Execution Time: {elapsed:.4f} sec")
    print(f"Shortest Distance: {shortest_distance:.4f}")
    print(f"Longest Distance: {longest_distance:.4f}")
    print(f"Returned Points: {len(final_points)}")


# -----------------------------------------------------------
# Command
# -----------------------------------------------------------
@Ap.Command()
def doit():
    try:
        ps, ss = Ed.Editor.select([(0, "POINT")])
        if ps != Ed.PromptStatus.eOk:
            raise RuntimeError("Selection failed.")
        pnts = [Db.Point(objid).position() for objid in ss.objectIds()]
        tsp_3opt_driver(pnts)
    except Exception:
        print(traceback.format_exc())
