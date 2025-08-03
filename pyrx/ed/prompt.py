# acedInitGet: https://help.autodesk.com/view/OARX/2025/ENU/?guid=OARX-RefGuide-acedInitGet_int_ACHAR__

"""
This module wraps user interaction functions, such as ``Ed.Editor.getPoint``,
``Ed.Editor.getDist``, etc.

The wrapper functions check the status returned by the functions and raise a ``PromptException`` if
the status is not ``eOk``, otherwise they return the function result omitting the status.

```
>>> get_point()
PyGe.Point3d(100.00000000000000,200.00000000000000,0.00000000000000)
```

If the user cancels the operation, a ``PromptException`` will be raised with the appropriate
status.

```
>>> get_point()
Traceback (most recent call last):
    ...
pyrx.ed.prompt.PromptExceptionCancel: Prompt rejected with status: eCancel (-5002)
```

``PromptException`` exceptions with statuses (``eRejected``, ``eNone``, ``eCancel``) are silenced
by the ``@command`` decorator, so they will not be reported in the console, but can still be caught
in code.

Functions containing the ``kwords`` argument can be interrupted by the user by entering a keyword,
which will raise a ``PromptExceptionKword`` exception with the entered keyword.

```
try:
    get_point(kwords=("Next", "Previous"))
except PromptExceptionKword as exc:
    # handle the case when user enters "Next"
    if exc.kword == "Next":
        ... # do something
    # handle the case when user enters "Previous"
    elif exc.kword == "Previous":
        ... # do something else
else:
    ... # handle the case when user selects a point
```

condition vs. flags
-------------------
For functions such as ``get_double``, ``get_integer``, etc., you can use the ``condition`` or
``flags`` argument to specify conditions that must be met by the entered value. With ``condition``,
an invalid value will raise an exception with status ``eError``, while with ``flags`` the value
will not be accepted until the user enters a valid value. The user can still cancel the operation,
which will raise an exception with status ``eCancel``.

Default values
--------------
Functions containing the ``default`` argument return this value if the user does not specify any
value (e.g., presses Enter)

```
>>> get_point(default=Ge.Point3d(0, 0, 0))
# the user presses Enter
PyGe.Point3d(0.00000000000000,0.00000000000000,0.00000000000000)
```
"""

from __future__ import annotations

import collections.abc as c
import enum
import math
import typing as t

from pyrx import Db, Ed, Ge, Rx

T = t.TypeVar("T")
_missing = object()


class PromptException(Exception):
    status: Ed.PromptStatus

    def __init__(self, status: Ed.PromptStatus):
        super().__init__(f"Prompt rejected with status: {status.name} ({int(status)})")
        self.status = status


class PromptExceptionNone(PromptException):
    def __init__(self):
        super().__init__(Ed.PromptStatus.eNone)


class PromptExceptionModeless(PromptException):
    def __init__(self):
        super().__init__(Ed.PromptStatus.eModeless)


class PromptExceptionError(PromptException):
    def __init__(self):
        super().__init__(Ed.PromptStatus.eError)


class PromptExceptionCancel(PromptException):
    def __init__(self):
        super().__init__(Ed.PromptStatus.eCancel)


class PromptExceptionRejected(PromptException):
    def __init__(self):
        super().__init__(Ed.PromptStatus.eRejected)


class PromptExceptionFailed(PromptException):
    def __init__(self):
        super().__init__(Ed.PromptStatus.eFailed)


class PromptExceptionDirect(PromptException):
    def __init__(self):
        super().__init__(Ed.PromptStatus.eDirect)


class PromptExceptionKword(PromptException):
    def __init__(self, kword: str):
        super().__init__(status=Ed.PromptStatus.eKeyword)
        self.kword = kword

    def __str__(self):
        return f"{self.__class__.__name__}: {self.kword}"


_status_to_exception: dict | None = None


def prompt_exception_from_status(status: Ed.PromptStatus) -> PromptException:
    global _status_to_exception
    if _status_to_exception is None:
        _status_to_exception = {
            Ed.PromptStatus.eNone: PromptExceptionNone,
            Ed.PromptStatus.eModeless: PromptExceptionModeless,
            Ed.PromptStatus.eError: PromptExceptionError,
            Ed.PromptStatus.eCancel: PromptExceptionCancel,
            Ed.PromptStatus.eRejected: PromptExceptionRejected,
            Ed.PromptStatus.eFailed: PromptExceptionFailed,
            Ed.PromptStatus.eDirect: PromptExceptionDirect,
        }
    try:
        return _status_to_exception[status]()
    except KeyError:
        return PromptException(status)


_Kwords_T: t.TypeAlias = c.Iterable[str] | c.Iterable[tuple[str, str]]


class Kwords:
    def __init__(self, kwords: _Kwords_T | Kwords | None = None) -> None:
        self._kwords = tuple(kwords) if kwords is not None else ()
        # 0 - not set, 1 - localized_only, 2 - localized_and_lang_independent
        self._kwords_type: int = 0
        self._check_kwords()

    def _check_kwords(self):
        kwords = self._kwords
        if not kwords:
            return
        err = ValueError(
            "kwords must be an iterable of strings or "
            "tuples of (localized, lang-independent) strings"
        )
        if isinstance(kwords[0], str):
            for item in kwords:
                if not isinstance(item, str):
                    raise err
            self._kwords_type = 1  # localized_only
        elif isinstance(kwords[0], tuple):
            for item in kwords:
                if (
                    not isinstance(item, tuple)
                    or len(item) != 2
                    or not all(isinstance(i, str) for i in item)
                ):
                    raise err
            self._kwords_type = 2  # localized_and_lang_independent
        else:
            raise err

    def as_init_get(self) -> str:
        kwords = self._kwords
        if not kwords:
            return ""
        if self._kwords_type == 1:  # localized_only
            kwords = t.cast(tuple[str, ...], kwords)
            return " ".join(kwords)
        else:  # localized_and_lang_independent
            kwords = t.cast(tuple[tuple[str, str], ...], kwords)
            return "{} _{}".format(*(" ".join(items) for items in zip(*kwords)))

    def as_prompt(self) -> str:
        kwords = self._kwords
        if not kwords:
            return ""
        if self._kwords_type == 1:  # localized_only
            kwords = t.cast(tuple[str, ...], kwords)
            return f"[{'/'.join(kwords)}]"
        else:  # localized_and_lang_independent
            kwords = t.cast(tuple[tuple[str, str], ...], kwords)
            return f"[{'/'.join(items[0] for items in kwords)}]"

    def __iter__(self):
        return iter(self._kwords)


class InitGetFlags(int, enum.Flag):  # type: ignore
    RSG_NONULL = 1
    """Prevents the user from responding to the request by entering only Enter."""
    RSG_NOZERO = 1 << 1
    """Prevents the user from responding to the request by entering zero."""
    RSG_NONEG = 1 << 2
    """Prevents the user from responding to the request by entering a negative value."""
    RSG_NOLIM = 1 << 3
    """
    Allows the user to enter a point outside the current drawing limits.
    This condition applies to the next user-input function even if the
    AutoCAD LIMCHECK system variable is currently set.
    """
    RSG_DASH = 1 << 5
    """
    Uses dashed lines when drawing a rubber-band line or box. For those
    functions with which the user can specify a point by selecting a
    location in the drawing area, this bit value causes the rubber-band
    line or box to be dashed instead of solid. (Some display drivers use
    a distinctive color instead of dashed lines.) If the AutoCAD POPUPS
    system variable is 0, AutoCAD ignores this bit.
    """
    RSG_2D = 1 << 6
    """
    Prohibits input of a Z coordinate to the getdist function; lets an
    application ensure that this function returns a 2D distance.
    """
    RSG_OTHER = 1 << 7
    """
    Allows arbitrary input as if it is a keyword, first honoring any
    other control bits and listed keywords. This bit takes precedence
    over bit 0; if bits 7 and 0 are set and the user presses Enter, a
    null string is returned.
    """
    RSG_DDISTFIRST = 1 << 8
    """
    Give direct distance input precedence over arbitrary input. For
    external applications, arbitrary input is given precedence over
    direct distance input by default. Set this bit if you wish to force
    AutoCAD to evaluate user input as direct distance input. Note that
    legal point input from the keyboard always takes precedence over
    either direct distance or arbitrary input.
    """
    RSG_TRACKUCS = 1 << 9
    """
    If set before a call to getpoint or getcorner, a temporary UCS will
    be established when the cursor crosses over the edge of a planar
    face of a solid. The temporary UCS is reset when the cursor moves
    off of a face. It is dynamically re-established when the cursor
    moves over a different face. After the point is acquired, the
    dynamic UCS is reset to the current UCS. This functionality is not
    enabled for non-planar faces such as the side of a cylinder.
    """
    RSG_NOORTHOZ = 1 << 10
    """
    When calling getdist, getangle, getorient, getpoint, or getcorner,
    you may not want the distance, angle, orient, point, or corner to be
    influenced by ortho, polar, or otracking in the Z direction. Setting
    this bit before calls to any of these functions will temporarily
    disable ortho, polar, and otracking in the Z direction. This is
    useful when you create 2D entities such as a polyline, arc, or
    circle, or when you use the AutoCAD ARRAY command, which creates
    only a 2D array. In 2D-only commands it can be confusing and
    error-prone to allow 3D points to be entered using ortho Z, polar Z,
    or otrack Z.
    """
    RSG_NOOSNAP = 1 << 11
    """
    Disables object snaps.
    """


class InitGetCtx:
    flags: InitGetFlags | int
    kwords: Kwords

    def __init__(self, flags: InitGetFlags | int = 0, kwords: _Kwords_T | Kwords | None = None):
        self.flags = InitGetFlags(flags)
        self.kwords = Kwords(kwords)

    def call(self):
        raise_for_status(Ed.Editor.initGet(int(self.flags), self.kwords.as_init_get()))

    def __enter__(self):
        self.call()
        return self

    def __exit__(self, exc_type, exc_value, traceback):
        if isinstance(exc_value, PromptException) and exc_value.status == Ed.PromptStatus.eKeyword:
            kword = Ed.Editor.getInput()
            raise PromptExceptionKword(kword) from None


def raise_for_status(__prompt_result: tuple | Ed.PromptStatus, default=_missing):
    if isinstance(__prompt_result, Ed.PromptStatus):
        status = __prompt_result
    else:
        status = __prompt_result[0]
    if status == Ed.PromptStatus.eNone and default is not _missing:
        return default
    if not status == Ed.PromptStatus.eOk:
        raise prompt_exception_from_status(status)
    if isinstance(__prompt_result, Ed.PromptStatus):
        return None
    else:
        res = __prompt_result[1:]  # Return the rest of the tuple
        return res[0] if len(res) == 1 else res


def _prompt(__prompt: str, /) -> str:
    return f"\n{__prompt}: "


def init_get(
    flags: InitGetFlags | int = 0, kwords: _Kwords_T | Kwords | None = None
) -> InitGetCtx:
    _init_get = InitGetCtx(flags, kwords)
    _init_get.call()
    return _init_get


@t.overload
def get_kword(
    prompt: str | None = None,
    flags: InitGetFlags | int = 0,
    kwords: _Kwords_T | Kwords | None = None,
    default: T = ...,
) -> str | T: ...
@t.overload
def get_kword(
    prompt: str | None = None,
    flags: InitGetFlags | int = 0,
    kwords: _Kwords_T | Kwords | None = None,
    default=_missing,
) -> str: ...
def get_kword(
    prompt: str | None = None,
    flags: InitGetFlags | int = 0,
    kwords: _Kwords_T | Kwords | None = None,
    default=_missing,
):
    """
    Prompts the user to enter a keyword from a predefined list.

    Args:
        prompt: The prompt message displayed to the user.
        kwords: An iterable of keywords or tuples of (localized,
        lang-independent) strings.
        flags: Flags controlling the behavior of the keyword input.
        default: The default value to return if the user does not enter a keyword.

    Returns:
        str: The keyword entered by the user. Note: If lang-independent
            keywords are passed, that keyword will be returned instead
            of the localized one.

    Raises:
        PromptException: If the selection operation fails or is canceled.
    """
    _kwords = Kwords(kwords) if kwords is not None else None
    init_get(flags, kwords)
    if prompt is None:
        if _kwords is None:
            prompt = _prompt("Select a keyword")
        else:
            prompt = _prompt(f"Select a keyword {_kwords.as_prompt()}")
    return raise_for_status(Ed.Editor.getKword(prompt), default=default)


def _ent_type_to_desc(ent_type_or_desc: Rx.RxClass | type[Db.Entity]):
    if isinstance(ent_type_or_desc, Rx.RxClass):
        return ent_type_or_desc
    elif isinstance(ent_type_or_desc, type) and issubclass(ent_type_or_desc, Db.Entity):
        return ent_type_or_desc.desc()  # type: ignore
    else:
        raise TypeError(f"Invalid type: {ent_type_or_desc.__class__.__name__}")


def entsel(
    prompt: str = _prompt("Select entity"),
    eType: Rx.RxClass
    | type[Db.Entity]
    | list[Rx.RxClass | type[Db.Entity]]
    | tuple[Rx.RxClass | type[Db.Entity], ...]
    | None = None,
    kwords: Kwords | None = None,
    flags: int | InitGetFlags = 0,
) -> Db.ObjectId[Db.Entity]:
    """
    Prompts the user to select an entity in the editor and returns the selected entity.

    Args:
        prompt: The prompt message displayed to the user.
        eType: Specifies the type(s) of entities that can be selected.
            All types are allowed if None.

    Returns:
        Db.Entity: The selected entity object. If a specific type is provided, it returns an
            instance of that type.

    Raises:
        PromptException: If the selection operation fails or is canceled.
        KwordPromptException: If the user selects a keyword instead of an entity.
    """
    with InitGetCtx(flags, kwords):
        ent_id = raise_for_status(
            Ed.Editor.entSel(prompt)
            if eType is None
            else Ed.Editor.entSel(prompt, [_ent_type_to_desc(et) for et in eType])
            if isinstance(eType, (list, tuple))
            else Ed.Editor.entSel(prompt, _ent_type_to_desc(eType))
        )[0]
        return ent_id


@t.overload
def get_point(
    prompt: str = ...,
    basePt: Ge.Point3d | None = None,
    kwords: Kwords | None = None,
    flags: int | InitGetFlags = 0,
    default: T = ...,
) -> Ge.Point3d | T: ...
@t.overload
def get_point(
    prompt: str = ...,
    basePt: Ge.Point3d | None = None,
    kwords: Kwords | None = None,
    flags: int | InitGetFlags = 0,
    default=_missing,
) -> Ge.Point3d: ...
def get_point(
    prompt: str = _prompt("Select point"),
    basePt: Ge.Point3d | None = None,
    kwords: Kwords | None = None,
    flags: int | InitGetFlags = 0,
    default=_missing,
):
    """
    Prompts the user to select a point.

    Args:
        prompt: The prompt message displayed to the user.
        basePt: An optional base point. If provided, a dashed helper
            line is displayed from the base point to the current cursor
            position during selection.
        default: The default value to return if the user does not
            specify a point (e.g., presses Enter).

    Returns:
        Ge.Point3d: The point selected by the user.

    Raises:
        PromptException: If the selection operation fails or is canceled.
    """
    with InitGetCtx(flags, kwords):
        if basePt is not None:
            res = Ed.Editor.getPoint(basePt, prompt)
        else:
            res = Ed.Editor.getPoint(prompt)
        return raise_for_status(res, default=default)


@t.overload
def get_angle(
    prompt: str = ...,
    basePt: Ge.Point3d | None = None,
    degrees: bool = False,
    kwords: Kwords | None = None,
    flags: int | InitGetFlags = 0,
    default: T = ...,
) -> float | T: ...
@t.overload
def get_angle(
    prompt: str = ...,
    basePt: Ge.Point3d | None = None,
    degrees: bool = False,
    kwords: Kwords | None = None,
    flags: int | InitGetFlags = 0,
    default=_missing,
) -> float: ...
def get_angle(
    prompt: str = _prompt("Specify angle"),
    basePt: Ge.Point3d | None = None,
    degrees: bool = False,
    kwords: Kwords | None = None,
    flags: int | InitGetFlags = 0,
    default=_missing,
):
    """
    Prompts the user to specify an angle and returns the angle value.

    Args:
        prompt: The prompt message displayed to the user.
        basePt: The base point for the angle measurement. Defaults to
            the origin (0, 0, 0).
        degrees: If True, the angle is returned in degrees. If False,
            the angle is returned in radians. Defaults to False.
        default: The default value to return if the user does not
            specify an angle (e.g., presses Enter).

    Returns:
        float: The angle value in radians or degrees, depending on the
            `degrees` parameter.

    Raises:
        PromptException: If the selection operation fails or is canceled.
    """
    if basePt is None:
        basePt = Ge.Point3d()
    with InitGetCtx(flags, kwords):
        angle = raise_for_status(Ed.Editor.getAngle(basePt, prompt), default=default)
        # If the returned value is the default, return it directly (do not convert to degrees)
        if default is not _missing and angle is default:
            return angle
        if degrees:
            return math.degrees(angle)
        else:
            return angle


@t.overload
def get_corner(
    prompt: str = ...,
    basePt: Ge.Point3d | None = None,
    kwords: Kwords | None = None,
    flags: int | InitGetFlags = 0,
    default: T = ...,
) -> Ge.Point3d | T: ...
@t.overload
def get_corner(
    prompt: str = ...,
    basePt: Ge.Point3d | None = None,
    kwords: Kwords | None = None,
    flags: int | InitGetFlags = 0,
    default=_missing,
) -> Ge.Point3d: ...
def get_corner(
    prompt: str = _prompt("Specify corner"),
    basePt: Ge.Point3d | None = None,
    kwords: Kwords | None = None,
    flags: int | InitGetFlags = 0,
    default=_missing,
):
    """
    Prompts the user to specify a corner point of a rectangle, opposite
    to the given base point. While the user selects the point, the
    rectangle is visually displayed on the screen.

    Args:
        prompt: The prompt message displayed to the user.
        basePt: The base point of the rectangle. Defaults to the origin (0, 0, 0).
        default: The default value to return if the user does not
            specify a corner point (e.g., presses Enter).

    Returns:
        Ge.Point3d: The corner point specified by the user.

    Raises:
        PromptException: If the selection operation fails or is canceled.
    """
    if basePt is None:
        basePt = Ge.Point3d()
    with InitGetCtx(flags, kwords):
        return raise_for_status(Ed.Editor.getCorner(basePt, prompt), default=default)


@t.overload
def get_dist(
    prompt: str = ...,
    basePt: Ge.Point3d | None = None,
    kwords: Kwords | None = None,
    flags: int | InitGetFlags = 0,
    default: T = ...,
) -> float | T: ...
@t.overload
def get_dist(
    prompt: str = ...,
    basePt: Ge.Point3d | None = None,
    kwords: Kwords | None = None,
    flags: int | InitGetFlags = 0,
    default=_missing,
) -> float: ...
def get_dist(
    prompt: str = _prompt("Specify distance"),
    basePt: Ge.Point3d | None = None,
    kwords: Kwords | None = None,
    flags: int | InitGetFlags = 0,
    default=_missing,
):
    """
    Prompts the user to specify a distance.

    Args:
        prompt: The prompt message displayed to the user.
        basePt: The base point from which the distance is measured.
            If None, the user is prompted to specify a base point.
        default: The default value to return if the user does not
            specify a distance (e.g., presses Enter).

    Returns:
        float: The distance specified by the user.

    Raises:
        PromptException: If the selection operation fails or is canceled.
    """
    with InitGetCtx(flags, kwords):
        if basePt is None:
            basePt = get_point(_prompt("Specify base point"))
        return raise_for_status(Ed.Editor.getDist(basePt, prompt), default=default)


@t.overload
def get_double(
    prompt: str = ...,
    condition: Ed.PromptCondition | None = None,
    kwords: Kwords | None = None,
    flags: int | InitGetFlags = 0,
    default: T = ...,
) -> float | T: ...
@t.overload
def get_double(
    prompt: str = ...,
    condition: Ed.PromptCondition | None = None,
    kwords: Kwords | None = None,
    flags: int | InitGetFlags = 0,
    default=_missing,
) -> float: ...
def get_double(
    prompt: str = _prompt("Enter a real number"),
    condition: Ed.PromptCondition | None = None,
    kwords: Kwords | None = None,
    flags: int | InitGetFlags = 0,
    default=_missing,
):
    """
    Prompts the user to enter a real number.

    Args:
        prompt: The prompt message displayed to the user.
        condition: An optional condition to validate the input.
        default: The default value to return if the user does not
            enter a number (e.g., presses Enter).

    Returns:
        float: The real number entered by the user.

    Raises:
        PromptException: If the selection operation fails or is canceled.
    """
    with InitGetCtx(flags, kwords):
        if condition is None:
            res = Ed.Editor.getDouble(prompt)
        else:
            if isinstance(condition, int):
                condition = Ed.PromptCondition(condition)
            res = Ed.Editor.getDouble(prompt, condition)
        return raise_for_status(res, default=default)


get_real = get_double  # Alias


@t.overload
def get_integer(
    prompt: str = ...,
    condition: Ed.PromptCondition | None = None,
    kwords: Kwords | None = None,
    flags: int | InitGetFlags = 0,
    default: T = ...,
) -> int | T: ...
@t.overload
def get_integer(
    prompt: str = ...,
    condition: Ed.PromptCondition | None = None,
    kwords: Kwords | None = None,
    flags: int | InitGetFlags = 0,
    default=_missing,
) -> int: ...
def get_integer(
    prompt: str = _prompt("Enter an integer"),
    condition: Ed.PromptCondition | None = None,
    kwords: Kwords | None = None,
    flags: int | InitGetFlags = 0,
    default=_missing,
):
    """
    Prompts the user to enter an integer.

    Args:
        prompt: The prompt message displayed to the user.
        condition: An optional condition to validate the input.
        default: The default value to return if the user does not
            enter an integer (e.g., presses Enter).

    Returns:
        int: The integer entered by the user.

    Raises:
        PromptException: If the selection operation fails or is canceled.
    """
    with InitGetCtx(flags, kwords):
        if condition is None:
            res = Ed.Editor.getInteger(prompt)
        else:
            if isinstance(condition, int):
                condition = Ed.PromptCondition(condition)
            res = Ed.Editor.getInteger(prompt, condition)
        return raise_for_status(res, default=default)


def get_string(
    prompt: str = _prompt("Enter a string"),
    condition: Ed.PromptCondition | None = None,
    cronly: bool = False,
) -> str:
    """Prompts the user to enter a string.
    Args:
        prompt: The prompt message displayed to the user.
        condition: An optional condition to validate the input.
        cronly: If True, the string can contain blanks and the user must
            terminate it by entering [Return]; if False, entering either
            a blank or [Return] terminates the string.

    Returns:
        str: The string entered by the user.

    Raises:
        PromptException: If the selection operation fails or is canceled.
    """
    if condition is None:
        res = Ed.Editor.getString(cronly, prompt)
    else:
        if isinstance(condition, int):
            condition = Ed.PromptCondition(condition)
        res = Ed.Editor.getString(cronly, prompt, condition)
    return raise_for_status(res)
