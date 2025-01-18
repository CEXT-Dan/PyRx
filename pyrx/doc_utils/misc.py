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
_RETURN_TYPES_JSON_PATH = _RESOURCES / "return_types.json"


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


class ReturnTypeRow(t.NamedTuple):
    module: str | None
    cls: str | None
    func: str
    value: str


class ReturnTypesManager:
    def __init__(self, rows: c.Iterable[ReturnTypeRow]):
        self.rows = tuple(rows)

    @classmethod
    def from_json(cls, file: _t.StrPath | None = None):
        if file is None:
            file = _RETURN_TYPES_JSON_PATH
        file = Path(file)
        if not file.exists():
            raise FileNotFoundError(str(file))
        raw_json = file.read_text(encoding="utf-8")
        rows = json.loads(raw_json)["rows"]

        def parse_row(row: tuple[str, str]):
            key, value = row
            chunks = tuple(chunk.strip() for chunk in key.split(("::")))
            count = len(chunks)
            if count == 3:
                module = chunks[0]
                cls = chunks[1]
                func = chunks[2]
            elif count == 2:
                module = chunks[0]
                cls = None
                func = chunks[1]
            elif count == 1:
                module = None
                cls = None
                func = chunks[0]
            else:
                raise ValueError
            return ReturnTypeRow(module, cls, func, value)

        parsed_rows = (parse_row(row) for row in rows)
        return cls(parsed_rows)
