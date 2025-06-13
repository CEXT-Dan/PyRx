from __future__ import annotations

import collections.abc as c

from pyrx import Db, Ed, Ge, command


@command
def vppoly() -> None:
    db = Db.curDb()
    lm = Db.LayoutManager()
    active_layout = Db.Layout(lm.getLayouts()[lm.getActiveLayoutName(True)])
    if active_layout.modelType():
        raise RuntimeError("Must be in paper space")
    vpid = Ed.Editor.activeViewportId()
    if vpid == active_layout.getViewportArray()[0]:
        raise RuntimeError("No active viewport")
    vp = Db.Viewport(vpid)
    points = get_viewport_visible_polygon(
        vp,
        # plane=None,
        plane=Ge.Plane(Ge.Point3d.kOrigin, Ge.Vector3d.kZAxis),
    )
    pline = Db.Polyline3d(Db.Poly3dType.k3dSimplePoly, list(points), True)
    db.addToModelspace(pline)


def get_viewport_visible_polygon(
    vp: Db.Viewport, plane: Ge.Plane | None = None
) -> tuple[Ge.Point3d, ...]:
    """
    Returns a polygon representing the portion of the model visible in
    the viewport. If the ``plane`` is provided, the polygon is projected
    onto this plane; otherwise, the polygon is in the viewport's DCS
    coordinate system.
    """
    boundary: c.Sequence[Ge.Point3d]
    if vp.isNonRectClipOn():
        clip_ent = Db.DbObject(vp.nonRectClipEntityId())
        if not clip_ent.isDerivedFrom(Db.Polyline.desc()):
            raise RuntimeError(
                "Only viewports clipped by a polyline are supported, "
                f"used {clip_ent.isA().dxfName()}"
            )

        boundary = Db.Polyline.cast(clip_ent).toPoint3dList()
    else:
        vp_cp = vp.centerPoint()
        vp_w_vec = Ge.Vector3d(vp.width() / 2, 0.0, 0.0)
        vp_h_vec = Ge.Vector3d(0.0, vp.height() / 2, 0.0)
        boundary = (
            vp_cp - vp_w_vec - vp_h_vec,
            vp_cp + vp_w_vec - vp_h_vec,
            vp_cp + vp_w_vec + vp_h_vec,
            vp_cp - vp_w_vec + vp_h_vec,
        )

    m = DCS2WCS(vp, plane) * PSDCS2DCS(vp)
    return tuple(m * point for point in boundary)


def DCS2WCS(vp: Db.Viewport, plane: Ge.Plane | None = None) -> Ge.Matrix3d:
    """
    Returns a transformation matrix from the viewport's DCS (Display
    Coordinate System) to WCS (World Coordinate System). If the
    ``plane`` is provided, the transformation is additionally projected
    onto this plane.
    """
    m1 = Ge.Matrix3d.projection(plane, vp.viewDirection()) if plane is not None else Ge.Matrix3d()
    m2 = Ge.Matrix3d.rotation(-vp.twistAngle(), vp.viewDirection(), vp.viewTarget())
    m3 = Ge.Matrix3d.translation(vp.viewTarget().asVector())
    m4 = Ge.Matrix3d.planeToWorld(vp.viewDirection())
    m = m1 * m2 * m3 * m4
    return m


def PSDCS2DCS(vp: Db.Viewport) -> Ge.Matrix3d:
    """
    Returns a transformation matrix from the viewport's PSDCS (Paper
    Space Display Coordinate System) to DCS (Display Coordinate System).
    """
    m1 = Ge.Matrix3d.translation(Ge.Point3d(*vp.viewCenter(), 0.0) - vp.centerPoint())
    m2 = Ge.Matrix3d.scaling(1.0 / vp.customScale(), vp.centerPoint())
    m = m1 * m2
    return m


print("added command VPPOLY")
