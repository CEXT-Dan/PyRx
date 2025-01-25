from __future__ import annotations

import collections.abc as c
import json
import typing as t
from functools import cached_property
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
        raw_json = file.read_text(encoding="windows-1250").replace("\xa0", " ")
        rows = (
            DocstringRow(id, name, value.replace("\\", "\\\\"))
            for id, name, value in json.loads(raw_json)["rows"]
        )
        return cls(rows)

    def get(self, id: int) -> str | None:
        if not isinstance(id, int):
            raise TypeError(type(id).__name__)
        row = self._id_to_row_map.get(id, None)
        return row.value if row is not None else None

    @cached_property
    def _id_to_row_map(self) -> dict[int, DocstringRow]:
        return {row.id: row for row in self.rows}


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

    @cached_property
    def rows_dict(self) -> dict[tuple[str | None, str | None, str], str]:
        return {(row.module, row.cls, row.func): row.value for row in self.rows}

    def get(self, module: str, cls: str, func: str) -> str | None:
        try:
            return self.rows_dict[(module, cls, func)]
        except KeyError:
            pass
        try:
            return self.rows_dict[(module, None, func)]
        except KeyError:
            pass
        try:
            return self.rows_dict[(None, None, func)]
        except KeyError:
            return None
