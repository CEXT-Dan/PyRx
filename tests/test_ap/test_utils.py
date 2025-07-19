import subprocess
import threading
import time
from pathlib import Path

import pytest
from pytest import FixtureRequest

from pyrx import Ax
from pyrx import Ed
from pyrx.ap.utils import call_in_main_thread, queue_command

BASE_DIR = Path(__file__).parent

@pytest.mark.known_failure_BRX
class Test_call_in_main_thread_and_call_after:
    def test_call_from_main_thread(self):
        assert threading.current_thread() == threading.main_thread()

        @call_in_main_thread
        def func(a, b):
            return a + b

        assert func(1, 2) == 3

    @pytest.mark.slow
    def test_call_from_other_thread(self, tmp_path: Path, request: FixtureRequest):
        host_exe = Ax.AcadApplication().fullName()
        python_module_path = BASE_DIR / "_test_call_in_main_thread.py"
        test_res_path = tmp_path / "test_res.txt"
        scr_content = (
            '(prompt "\n\n'
            + "*" * 50
            + f"\nHost instance for test:\n{request.node.nodeid}\n"
            + "*" * 50
            + '\n\n")\n'
            f'(adspyload "{python_module_path.as_posix()}")\n'
            "TEST_CALL_IN_MAIN_THREAD\n"
            f"{test_res_path.as_posix()}\n"
        )
        scr_file = tmp_path / "test.scr"
        scr_file.write_text(scr_content, encoding="ansi")
        process = subprocess.Popen(
            args=[host_exe, "/b", str(scr_file)],
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True,
        )
        res = None
        TIMEOUT = 20
        start = time.time()
        while process.poll() is None:
            if time.time() - start > TIMEOUT:
                break
            try:
                with open(test_res_path, "r") as f:
                    res = f.read().strip()
                if not res:
                    continue
            except IOError:
                time.sleep(0.1)
            else:
                break
        process.terminate()

        assert res is not None, f"{process.stdout=}\n{process.stderr=}"
        assert res.strip() == "True"

def test_queue_command():
    queue_command("100,200\n")
    status, point = Ed.Editor.getPoint(f"\n[{__name__}.test_queue_command] Enter point: ")
    assert status == Ed.PromptStatus.eOk
    assert tuple(point) == (100, 200, 0)

