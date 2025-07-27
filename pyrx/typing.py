from __future__ import annotations

import collections.abc as c
import typing as t

from pyrx import Ge

UPoint: t.TypeAlias = c.Iterable[t.SupportsFloat] | Ge.Point3d | Ge.Point2d
