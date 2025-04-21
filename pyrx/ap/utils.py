from __future__ import annotations

import queue
import threading
from functools import wraps

from pyrx import Ap


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
        q: queue.Queue[int | BaseException] = queue.Queue(1)

        def wrapper():
            Ap.Application.removeOnIdleWinMsg(wrapper)
            try:
                res = func(*args, **kwargs)
            except BaseException as e:
                q.put_nowait(e)
            else:
                q.put_nowait(res)

        Ap.Application.registerOnIdleWinMsg(wrapper)

        res = q.get()
        if isinstance(res, BaseException):
            raise res
        else:
            return res

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
