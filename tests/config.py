from __future__ import annotations

import dataclasses
import pickle
import typing as t
from datetime import datetime

from tests import HOST

if t.TYPE_CHECKING:
    import _typeshed as _t


@dataclasses.dataclass
class TestConfig:
    slow_tests: bool = True
    known_failures: bool = True

    def dump(self, file: _t.StrPath) -> None:
        with open(file, "wb") as f:
            pickle.dump(self, f)

    @classmethod
    def load(cls, file: _t.StrPath) -> t.Self:
        with open(file, "rb") as f:
            obj = pickle.load(f)
        return obj


def get_log_filename():
    return f"test_{HOST}_{datetime.now():%Y_%m_%d_%H_%M_%S}.log"
