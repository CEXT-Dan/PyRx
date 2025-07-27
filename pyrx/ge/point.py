from __future__ import annotations

import typing as t

from pyrx import Ge

if t.TYPE_CHECKING:
    from pyrx.typing import UPoint


def point_3d(
    x_or_point: t.SupportsFloat | UPoint,
    y: t.SupportsFloat | None = None,
    z: t.SupportsFloat | None = None,
) -> Ge.Point3d:
    """
    Create a 3D point from various input formats.

    Args:
        x_or_point: Either a single x-coordinate (number), an existing Point3d,
            Point2d, or an iterable of coordinates (list, tuple, etc.)
        y: Y-coordinate (required if x_or_point is a number)
        z: Z-coordinate (optional, defaults to 0.0 if x_or_point is a number)

    Returns:
        Ge.Point3d: A 3D point object

    Raises:
        ValueError: If invalid combination of arguments is provided

    Examples:
        >>> point_3d(1.0, 2.0, 3.0)  # From individual coordinates
        >>> point_3d([1.0, 2.0, 3.0])  # From list
        >>> point_3d(existing_point)  # From existing point
    """
    # If input is already a Point3d, return a copy of it
    if isinstance(x_or_point, Ge.Point3d):
        if y is not None or z is not None:
            raise ValueError("If x_or_point is a Point3d, y and z should not be provided.")
        return Ge.Point3d(*x_or_point)  # return a copy

    # Handle individual coordinate input (x, y, z)
    if isinstance(x_or_point, t.SupportsFloat):
        if y is None:
            raise ValueError("If x_or_point is a number, y must be provided.")
        return Ge.Point3d(float(x_or_point), float(y), float(z or 0.0))

    # Handle iterable input (list, tuple, Point2d, etc.)
    coords_iter = iter(x_or_point)
    try:
        x = next(coords_iter)  # Extract x coordinate
        y = next(coords_iter)  # Extract y coordinate
    except StopIteration:
        raise ValueError("Not enough coordinates provided.")

    z = next(coords_iter, 0.0)  # Extract z coordinate, default to 0.0 if not provided

    # Check for extra coordinates (more than 3)
    try:
        next(coords_iter)  # Try to get a 4th coordinate
    except StopIteration:
        pass  # Good, no extra coordinates
    else:
        raise ValueError("Too many coordinates provided.")

    return Ge.Point3d(x, y, z)


def point_2d(
    x_or_point: t.SupportsFloat | UPoint,
    y: t.SupportsFloat | None = None,
    z: t.SupportsFloat | None = None,
) -> Ge.Point2d:
    """
    Create a 2D point from various input formats.

    Args:
        x_or_point: Either a single x-coordinate (number), an existing Point2d,
            Point3d, or an iterable of coordinates (list, tuple, etc.)
        y: Y-coordinate (required if x_or_point is a number)
        z: Z-coordinate (ignored for 2D points, kept for API consistency)

    Returns:
        Ge.Point2d: A 2D point object

    Raises:
        ValueError: If invalid combination of arguments is provided

    Examples:
        >>> point_2d(1.0, 2.0)  # From individual coordinates
        >>> point_2d([1.0, 2.0])  # From list (z ignored if present)
        >>> point_2d(existing_point_3d)  # From 3D point (z discarded)
    """
    # If input is already a Point2d, return a new Point2d object that is a copy of the input
    if isinstance(x_or_point, Ge.Point2d):
        if y is not None or z is not None:
            raise ValueError("If x_or_point is a Point2d, y and z should not be provided.")
        return Ge.Point2d(*x_or_point)  # return a copy

    # Handle individual coordinate input (x, y)
    if isinstance(x_or_point, t.SupportsFloat):
        if y is None:
            raise ValueError("If x_or_point is a number, y must be provided.")
        return Ge.Point2d(float(x_or_point), float(y))

    # Handle iterable input (list, tuple, Point3d, etc.)
    coords_iter = iter(x_or_point)
    try:
        x = next(coords_iter)  # Extract x coordinate
        y = next(coords_iter)  # Extract y coordinate
    except StopIteration:
        raise ValueError("Not enough coordinates provided.")

    # Extract z coordinate if present (will be ignored for 2D point)
    z = next(coords_iter, None)

    # Check for extra coordinates (more than 3)
    try:
        next(coords_iter)  # Try to get a 4th coordinate
    except StopIteration:
        pass  # Good, no extra coordinates
    else:
        raise ValueError("Too many coordinates provided.")

    return Ge.Point2d(x, y)
