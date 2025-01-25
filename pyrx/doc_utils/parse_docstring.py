from __future__ import annotations

import collections.abc as c
import re

_BASE_SIGNATURE_PATT = re.compile(r"!\[\((.*?)\)\]!")
_OVERLOADS_PATT = re.compile(r"<\[\(Overloads:\n(.*)\)\]\>", re.IGNORECASE | re.DOTALL)
_DOCSTRING_ID_PATT = re.compile(r"<\[{(?P<id>-?\d+)}\]>", re.IGNORECASE)
_RETURN_TYPE_PATT = re.compile(r"->\s*(.*[^\s]+.*?)\s*:\s*")


def _get_docstring_section_from_pattern(docstring: str, pattern: re.Pattern) -> str | None:
    m = pattern.search(docstring)
    if m is None:
        return None
    return m.group(1)


def get_base_signature(docstring: str) -> str | None:
    return _get_docstring_section_from_pattern(docstring, _BASE_SIGNATURE_PATT)


def get_overloads(docstring: str) -> str | None:
    return _get_docstring_section_from_pattern(docstring, _OVERLOADS_PATT)


def get_docstring_id(docstring: str) -> str | None:
    return _get_docstring_section_from_pattern(docstring, _DOCSTRING_ID_PATT)


def get_return_type(docstring: str) -> str | None:
    return _get_docstring_section_from_pattern(docstring, _RETURN_TYPE_PATT)


def get_text_signatures(
    base_signature: str, overloads: str | None
) -> c.Generator[str, None, None]:
    base_signature = base_signature.rstrip(",/ ").strip()
    if overloads is None:
        yield base_signature
        return
    # else:
    for line in (line.strip() for line in overloads.splitlines(keepends=False)):
        if not line:
            continue
        line = line.lstrip("-").rstrip(",").strip()
        if line.startswith("None"):
            yield base_signature
        else:
            yield ", ".join(i for i in (base_signature, line) if i)
