"""
PyRx AutoCAD Command Module for 3D Point Tree Operations

This module demonstrates the use of KD-tree based point searching functionality
using PyRx's Point3dTree implementation, which is built on nanoflann library.
The module provides two commands that showcase different types of spatial queries
on randomly generated 3D points.

Functions:
    doit1: Performs radius-based searches in 3D space
    doit2: Performs k-nearest neighbor searches in 3D space

The Point3dTree implementation allows efficient spatial indexing and querying
of 3D point data, making it suitable for applications requiring fast proximity
calculations and neighborhood searches.
"""

import random
from timeit import default_timer as timer

from pyrx import Ge, command


@command
def doit1():
    """
    Perform radius-based search on 1000 randomly generated 3D points.
    
    This function generates 1000 random 3D points within a 100x100x100 space,
    builds a KD-tree for spatial indexing, and performs a radius search centered
    at (50, 50, 50) with a radius of 200 units.
    
    The radius search returns all points within the specified distance from
    the center point, along with their distances.
    
    Expected Output:
        - Number of points found within the search radius
        - Execution time in seconds
        
    Example Usage:
        Command line: doit1
        Output: [number_of_points_found] [execution_time_seconds]
        
    Performance Characteristics:
        - Time complexity: O(log n + k) where k is number of neighbors found
        - Space complexity: O(n log n) for tree construction
        - Suitable for large datasets requiring efficient spatial queries
        
    Note: The search radius (200) exceeds the bounds of the point cloud,
          so all points should be returned in this example.
    """
    start = timer()

    # Generate 1000 random 3D points within a 100x100x100 space
    points = Ge.Point3dArray()
    for i in range(1000):
        rx = random.uniform(0.0, 100.0)
        ry = random.uniform(0.0, 100.0)
        rz = random.uniform(0.0, 100.0)
        points.append(Ge.Point3d(rx, ry, rz))

    # Create KD-tree for efficient spatial indexing
    tree = Ge.Point3dTree(points)

    # Perform radius search: find all points within distance 200 of center (50,50,50)
    idxs, dists = tree.radiusSearch(Ge.Point3d(50, 50, 50), 200)

    end = timer()
    print(len(idxs), end - start)


@command
def doit2():
    """
    Perform k-nearest neighbor search on 1000 randomly generated 3D points using Point3dTree.
    
    This function generates 1000 random 3D points (z-coordinate set to 0) within
    a 100x100 space, builds a KD-tree for spatial indexing using Point3dTree,
    and performs a k-nearest neighbor search for the 5 closest points to 
    center (50, 50, 0).
    
    The knnSearch returns both the indices of nearest neighbors and their
    respective distances from the query point.
    
    Expected Output:
        - Array of indices of the 5 nearest points
        - Array of corresponding distances
        - Execution time in seconds
        
    Example Usage:
        Command line: doit2
        Output: [list_of_point_indices] [list_of_distances] [execution_time_seconds]
        
    Performance Characteristics:
        - Time complexity: O(log n + k) where k is number of neighbors requested
        - Space complexity: O(n log n) for tree construction
        - Optimized for fast nearest neighbor queries
        
    Note: This command demonstrates that Point3dTree can handle 3D points
          by setting z-coordinate to 0, showing the flexibility of the 3D tree
          implementation for both 3D and 3D spatial data.
    """
    start = timer()

    # Generate 1000 random 3D points within a 100x100 space (z=0)
    points = Ge.Point3dArray()
    for i in range(1000):
        rx = random.uniform(0.0, 100.0)
        ry = random.uniform(0.0, 100.0)
        points.append(Ge.Point3d(rx, ry, 0))

    # Create KD-tree for efficient spatial indexing
    tree = Ge.Point3dTree(points)

    # Perform k-nearest neighbor search: find 5 closest points to (50,50,0)
    idxs, dists = tree.knnSearch(Ge.Point3d(50, 50, 0), 5)

    end = timer()
    print(idxs, dists, end - start)
