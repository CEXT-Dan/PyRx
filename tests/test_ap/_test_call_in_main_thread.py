import queue
import threading

from pyrx import Ed
from pyrx.ap.utils import call_after, call_in_main_thread

A = "A"
B = "B"


@call_in_main_thread
def should_be_called_in_main_thread(a, b):
    return threading.current_thread() == threading.main_thread() and a is A and b is B


@call_in_main_thread
def should_be_called_in_main_thread2():
    raise RuntimeError


def test_call_after():
    assert not threading.current_thread() == threading.main_thread()

    def _test1(a, b):
        return threading.current_thread() == threading.main_thread() and not a == b

    res1 = call_after(_test1, args=(A,), kwargs={"b": B}, wait=True)

    def _test2():
        raise RuntimeError

    try:
        call_after(_test2, wait=True)
    except RuntimeError:
        res2 = True
    else:
        res2 = False

    def _test3(q):
        res = threading.current_thread() == threading.main_thread()
        q.put_nowait(res)
        return True

    q = queue.Queue(1)
    res3 = call_after(_test3, args=(q,), wait=False)
    assert res3 is None
    res3 = q.get()

    res4 = call_after(should_be_called_in_main_thread, (A, B), wait=True)

    return res1 and res2 and res3 and res4


def main(path):
    try:
        test_1 = not threading.current_thread() == threading.main_thread()
        test_2 = should_be_called_in_main_thread(A, b=B)
        try:
            should_be_called_in_main_thread2()
        except RuntimeError:
            test_3 = True
        else:
            test_3 = False
        test_4 = test_call_after()
    except Exception:
        import io
        import traceback

        sio = io.StringIO()
        traceback.print_exc(file=sio)
        res = sio.getvalue()
    else:
        res = test_1 and test_2 and test_3 and test_4
    with open(path, "w") as f:
        print(res, file=f)


def PyRxCmd_test_call_in_main_thread():
    status, path = Ed.Editor.getString("write_file_path: ")
    if not status == Ed.PromptStatus.eOk:
        raise RuntimeError(str(status))
    threading.Thread(target=main, args=(path,)).start()
