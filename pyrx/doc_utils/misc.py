from __future__ import annotations

import collections.abc as c
import json
import typing as t
from pathlib import Path

if t.TYPE_CHECKING:
    import _typeshed as _t

_BASE_DIR = Path(__file__).parent
_RESOURCES = _BASE_DIR / "resources"
_DOCSTRINGS_JSON_PATH = _RESOURCES / "docstrings.json"


class DocstringRow(t.NamedTuple):
    id: int
    name: str
    value: str


class DocstringsManager:
    def __init__(self, rows: c.Iterable[DocstringRow]):
        self.rows = tuple(rows)

    @classmethod
    def from_json(cls, file: _t.StrPath | None = None):
        if file is None:
            file = _DOCSTRINGS_JSON_PATH
        file = Path(file)
        if not file.exists():
            raise FileNotFoundError(str(file))
        raw_json = file.read_text(encoding="windows-1250").replace("\xa0", "")
        rows = (DocstringRow(*row) for row in json.loads(raw_json)["rows"])
        return cls(rows)
