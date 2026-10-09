import traceback
import math
from pyrx import Ap, Db, Ge, Ed, Gi


def next_utf16_code_point(text: str, first: int) -> int:
    if first < len(text):
        return first + (2 if 0xD800 <= ord(text[first]) <= 0xDBFF else 1)
    return len(text)


def fragment_point_to_wcs(fragment, xAxis, yAxis, point):
    return fragment[Db.MTextFragmentType.kLocation] + xAxis * point.x + yAxis * point.y


def make_style(frag: list):
    font = frag[Db.MTextFragmentType.kFont]
    if font is None:
        font = ""

    bigFont = frag[Db.MTextFragmentType.kBigFont]
    if bigFont is None:
        bigFont = ""

    st = Gi.TextStyle(
        font,
        bigFont,
        frag[Db.MTextFragmentType.kCapsHeight],
        frag[Db.MTextFragmentType.kWidthFactor],
        frag[Db.MTextFragmentType.kObliqueAngle],
        frag[Db.MTextFragmentType.kTrackingFactor],
        False,
        False,
        False,
        frag[Db.MTextFragmentType.kOverlined],
        frag[Db.MTextFragmentType.kUnderlined],
    )

    st.setFont(
        frag[Db.MTextFragmentType.kFontname],
        frag[Db.MTextFragmentType.kBold],
        frag[Db.MTextFragmentType.kItalic],
        Gi.Charset.kDefaultCharset,
        Gi.FontPitch.kFixed,
        Gi.FontFamily.kDefault,
    )
    
    if (st.loadStyleRec() & 1) == 0:
        raise RuntimeError("loadStyleRec failed: ")
    return st


@Ap.Command()
def doit():
    try:
        
        target_search = "C=B"
        
        db = Db.curDb()
        ps, id, _ = Ed.Editor.entSel("\nPick MText: ", Db.MText.desc())
        if ps != Ed.PromptStatus.eOk:
            raise RuntimeError("Selection failed: {}".format(ps))

        mt = Db.MText(id)
    
        for frag in mt.getFragments():
            print(frag)
            st = make_style(frag)
            vx: Ge.Vector3d = frag[Db.MTextFragmentType.kDirection].normal()
            vz: Ge.Vector3d = frag[Db.MTextFragmentType.kNormal].normal()
            vy = vz.crossProduct(vx).normal()

            text = frag[Db.MTextFragmentType.kTextValue]
            first = 0
            character_index = 0

            while first < len(text):
                last = next_utf16_code_point(text, first)
                prefix = text[0:first]

                if text[first:].startswith(target_search):
                    lookahead_end = first
                    for _ in range(len(target_search)):
                        lookahead_end = next_utf16_code_point(text, lookahead_end)

                    full_match_string = text[first:lookahead_end]
                    advance = st.extents(prefix, True, len(prefix), False).x

                    localMin, localMax = st.extentsBox(
                        full_match_string, True, len(full_match_string), False
                    )
                    localMin.x += advance
                    localMax.x += advance

                    p0 = fragment_point_to_wcs(frag, vx, vy, localMin)
                    p1 = fragment_point_to_wcs(frag, vx, vy, Ge.Point2d(localMax.x, localMin.y))
                    p2 = fragment_point_to_wcs(frag, vx, vy, localMax)
                    p3 = fragment_point_to_wcs(frag, vx, vy, Ge.Point2d(localMin.x, localMax.y))

                    Ed.Core.grDraw(p0, p1, 3, 0)
                    Ed.Core.grDraw(p1, p2, 3, 0)
                    Ed.Core.grDraw(p2, p3, 3, 0)
                    Ed.Core.grDraw(p3, p0, 3, 0)
                    first = last
                else:
                    first+=1
                character_index += 1

    except Exception as e:
        traceback.print_exc()
