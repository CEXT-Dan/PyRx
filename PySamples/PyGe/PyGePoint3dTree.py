import random
from timeit import default_timer as timer

from pyrx import Ge, command


@command
def doit1():
    start = timer()

    # random point
    points = Ge.Point3dArray()
    for i in range(1000):
        rx = random.uniform(0.0, 100.0)
        ry = random.uniform(0.0, 100.0)
        rz = random.uniform(0.0, 100.0)
        points.append(Ge.Point3d(rx, ry, rz))

    # create the tree
    tree = Ge.Point3dTree(points)

    # the search is a sphere
    idxs, dists = tree.radiusSearch(Ge.Point3d(50, 50, 50), 200)

    end = timer()
    print(len(idxs), end - start)


@command
def doit2():
    start = timer()

    # random point
    points = Ge.Point3dArray()
    for i in range(1000):
        rx = random.uniform(0.0, 100.0)
        ry = random.uniform(0.0, 100.0)
        points.append(Ge.Point3d(rx, ry, 0))

    # create the tree
    tree = Ge.Point3dTree(points)

    # search the 5 nearest
    idxs, dists = tree.knnSearch(Ge.Point3d(50, 50, 0), 5)

    end = timer()
    print(idxs, dists, end - start)
