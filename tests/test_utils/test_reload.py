from __future__ import annotations

import importlib
import shutil
import sys
from contextlib import contextmanager, suppress
from pathlib import Path

import pytest

from pyrx import Ap, Ed
from pyrx.utils.reload import Reloader

BASE_DIR = Path(__file__).parent
PACKAGE = "tests.test_utils"
RESOURCES = BASE_DIR / "resources/reload"


@contextmanager
def create_temp_module(name: str, is_package=False):
    try:
        _paths: list[Path] = []
        abs_module_name = f"{PACKAGE}.{name}"
        assert abs_module_name not in sys.modules
        name_chunks = name.split(".")
        if is_package:
            package_it = iter(name_chunks)
        else:
            package_it = iter(name_chunks[:-1])
        package_path = BASE_DIR
        while True:
            package = next(package_it, None)
            if package is None:
                break
            package_path = package_path / package
            if not package_path.exists():
                package_path.mkdir()
                _paths.append(package_path)
            package_init_path = package_path / "__init__.py"
            if not package_init_path.exists():
                package_init_path.touch()
                _paths.append(package_init_path)
        if not is_package:
            module_path = package_path / f"{name_chunks[-1]}.py"
            if not module_path.exists():
                module_path.touch()
                _paths.append(module_path)
            else:
                module_path.write_text("", encoding="utf-8")
        yield abs_module_name, module_path
    finally:
        for path in reversed(_paths):
            with suppress(OSError):
                if path.is_file():
                    path.unlink()
                else:
                    pycache_path = path / "__pycache__"
                    if pycache_path.exists():
                        shutil.rmtree(pycache_path)
                    path.rmdir()

@pytest.mark.known_failure_IRX #no evaluateLisp
class Test_Reload:
    @pytest.mark.slow
    def test_reload(self):
        reloader = Reloader(f"{PACKAGE}.package1", f"{PACKAGE}.package2")
        with create_temp_module("package2.module1") as (m21_name, m21_path):
            with create_temp_module("package1.module1.module2") as (m112_name, m112_path):
                with create_temp_module("package1.module2") as (m12_name, m12_path):
                    with create_temp_module("package2.module2") as (m22_name, m22_path):
                        m112 = importlib.import_module(m112_name)
                        m12 = importlib.import_module(m12_name)
                        m21 = importlib.import_module(m21_name)
                        m22 = importlib.import_module(m22_name)
                        to_reload = set(reloader.modules_to_reload)
                        assert len(to_reload) == 7
                        assert m112_name in to_reload
                        assert m21_name in to_reload
                        assert m12_name in to_reload
                        assert m22_name in to_reload
                        modules = set(sys.modules.keys())
                        modules_count = len(modules)
                        assert getattr(m112, "ATTR", None) is None
                        m112_path.write_text("ATTR = 1\n", encoding="utf-8")
                        reloader.reload_modules()
                        m112 = importlib.import_module(m112_name)
                        assert m112.ATTR == 1
                        assert not modules.symmetric_difference(set(sys.modules.keys()))
                    reloader.reload_modules()
                    modules_1 = set(sys.modules.keys())
                    assert modules_count - len(modules_1) == 1, str(modules.difference(modules_1))
                reloader.reload_modules()
                modules_2 = set(sys.modules.keys())
                assert modules_count - len(modules_2) == 2, str(modules.difference(modules_2))
            reloader.reload_modules()
            modules_3 = set(sys.modules.keys())
            assert modules_count - len(modules_3) == 5, str(modules.difference(modules_3))
        reloader.reload_modules()
        modules_4 = set(sys.modules.keys())
        assert modules_count - len(modules_4) == 7, str(modules.difference(modules_4))

    def test_reload_with_reload_False(self):
        with create_temp_module("package1.module1") as (m11_name, m11_path):
            assert m11_name not in sys.modules
            importlib.import_module(m11_name)
            assert m11_name in sys.modules
            reloader = Reloader(m11_name, reload=False)
            reloader.reload_modules()
            assert m11_name not in sys.modules

    def test_register(self, capsys: pytest.CaptureFixture[str]):
        with create_temp_module("test_register_module_1") as (m1_name, m1_path):
            assert Ed.Core.setVar("USERS1", "FAIL") is True
            module_src = (
                "from pyrx.utils.reload import Reloader\n"
                "Reloader(func=lambda: print('{msg}')).register()\n"
            )
            m1_path.write_text(
                module_src.format(msg="reloaded"),
                encoding="utf-8",
            )
            Ap.Application.loadPythonModule(str(m1_path))
            assert not capsys.readouterr().out
            Ap.Application.reloadPythonModule(str(m1_path))
            assert capsys.readouterr().out == "reloaded\n"

    def test_register_func_with_exception(self, capsys: pytest.CaptureFixture[str]):
        module_path = RESOURCES / "m_test_reload_with_exception.py"
        Ed.Core.evaluateLisp(f'(adspyload "{module_path.as_posix()}")\n')
        assert capsys.readouterr().out == ""
        Ed.Core.evaluateLisp(f'(adspyreload "{module_path.as_posix()}")\n')
        stderr = capsys.readouterr().err
        assert (
            stderr.startswith("Traceback (most recent call last):\n")
            and str(RuntimeError("Reload exception")) in stderr
        )


@pytest.mark.known_failure_IRX #no evaluateLisp
class Test_reload_func:
    def test_valid(self, tmp_path: Path):
        with (
            create_temp_module("Test_reload_func_module_1") as (m1_name, m1_path),
            create_temp_module("Test_reload_func_module_2") as (m2_name, m2_path),
        ):
            log_file = tmp_path / "log.txt"
            m1_path.write_text(
                "from pyrx.utils.reload import reload\n"  #
                f"import {m2_name}\n"
                f"reload('{m2_name}')\n",
                encoding="utf-8",
            )
            m2_path.write_text(
                f"with open({str(log_file)!r}, 'a', encoding='utf-8') as f:\n"
                "    print('executed', file=f)\n",
                encoding="utf-8",
            )
            Ed.Core.evaluateLisp(f'(adspyload "{m1_path.as_posix()}") ')
            Ed.Core.evaluateLisp(f'(adspyreload "{m1_path.as_posix()}") ')
            assert log_file.read_text(encoding="utf-8") == "executed\nexecuted\n"


if __name__ == "__main__":
    pytest.main([__file__])
