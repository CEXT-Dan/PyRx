from __future__ import annotations

import re

_BASE_SIGNATURE_PATT = re.compile(r"!\[\((.*?)\)\]!")


def _get_docstring_section_from_pattern(docstring: str, pattern: re.Pattern) -> str | None:
    m = pattern.search(docstring)
    if m is None:
        return None
    return m.group(1)


def get_base_signature(docstring: str) -> str | None:
    return _get_docstring_section_from_pattern(docstring, _BASE_SIGNATURE_PATT)
