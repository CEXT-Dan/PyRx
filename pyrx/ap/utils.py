from __future__ import annotations

import enum
import queue
import threading
import typing as t
from functools import wraps

from pyrx import Ap


class _ResultEnum(enum.Enum):
    RESULT = enum.auto()
    EXCEPTION = enum.auto()


class _Result(t.NamedTuple):
    type: _ResultEnum
    value: t.Any


def call_after(func, args=(), kwargs={}, *, wait=False):
    """
    Calls the specified function after the application becomes idle.

    If the current thread is the main thread, the function is called
    immediately. Otherwise, the function is registered to be called when
    the application is idle.

    Arguments:
        func: The function to be called.
        args: The positional arguments to pass to the function.
        kwargs: The keyword arguments to pass to the function.
        wait: If ``True``, waits for the function to complete and
            returns its result. If ``False``, the function is called
            asynchronously.
    """
    if threading.current_thread() == threading.main_thread():
        return func(*args, **kwargs)

    if wait:
        # TODO: Check if host is in command ctx - deadlock
        q: queue.Queue[_Result] = queue.Queue(1)

        def wrapper():
            Ap.Application.removeOnIdleWinMsg(wrapper)
            try:
                res = func(*args, **kwargs)
            except BaseException as e:
                q.put_nowait(_Result(_ResultEnum.EXCEPTION, e))
            else:
                q.put_nowait(_Result(_ResultEnum.RESULT, res))

        Ap.Application.registerOnIdleWinMsg(wrapper)

        res = q.get()
        if res.type == _ResultEnum.EXCEPTION:
            raise res.value
        else:
            return res.value

    else:

        def wrapper():
            Ap.Application.removeOnIdleWinMsg(wrapper)
            func(*args, **kwargs)

        Ap.Application.registerOnIdleWinMsg(wrapper)


def call_in_main_thread(func):
    """
    A decorator for functions that must always be called in the main
    thread.
    """

    @wraps(func)
    def wrapper(*args, **kwargs):
        return call_after(func, args, kwargs, wait=True)

    return wrapper
