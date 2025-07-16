from __future__ import annotations

import ast
import re
import types
import typing as t
from pathlib import Path

import asttokens

ASTType_T = t.TypeVar("ASTType_T", ast.Module, ast.ClassDef, ast.FunctionDef, ast.AnnAssign)

BASE_DIR = Path(__file__).parent

MARKER = "# pyrx-marker:"
HEADER_END_MARKER = f"{MARKER} HEADER_END"

COMMENT_SECTION_START = re.compile(r"^\s*" + re.escape("# /*") + r".*")
COMMENT_SECTION_END = re.compile(r"^\s*" + re.escape("# ") + r".*" + re.escape("*/") + r"\s*$")


class SrcParsingError(Exception):
    pass


class Node(t.Generic[ASTType_T]):
    def __init__(
        self, name: str | None, ast_node: ASTType_T, start_lineno: int, end_lineno: int
    ) -> None:
        self.name = name
        self.ast_node: ASTType_T = ast_node
        self.children: list[Node] = []
        self.start_line = start_lineno
        self.end_line = end_lineno

    @property
    def range(self) -> range:
        return range(self.start_line, self.end_line + 1)

    def __str__(self) -> str:
        return (
            (f"{self.name} " if self.name else "")
            + f"({self.ast_node.__class__.__name__})"
            + (f" [{self.start_line} - {self.end_line}]" if self.start_line else "")
            + ("\n" if self.children else "")
            + "\n".join(str(child) for child in self.children)
        )

    def __repr__(self) -> str:
        return f"<Node {self.name} ({self.ast_node.__class__.__name__})>"


class StubParser:
    def __init__(self, src: str):
        self.src = src
        self.atok = asttokens.ASTTokens(src, parse=True)

    def parse(self) -> Node:
        tree = self.atok.tree
        assert tree is not None, "Failed to parse the AST tree."
        return self.parse_module(tree)

    def parse_module(self, tree: ast.Module) -> Node:
        module_node = Node(None, tree, 0, 0)
        for child_idx, child in enumerate(tree.body):
            if isinstance(child, ast.ClassDef):
                child_node = self.parse_class(child)
                module_node.children.append(child_node)
            elif isinstance(child, ast.FunctionDef):
                child_node = self.parse_function(child)
                module_node.children.append(child_node)
            elif isinstance(child, ast.AnnAssign):
                try:
                    next_child = tree.body[child_idx + 1]
                except IndexError:
                    next_child = None
                child_node = self.parse_annotated_assign(child, next_child)
                module_node.children.append(child_node)
        return module_node

    def parse_class(self, tree: ast.ClassDef) -> Node:
        class_node = Node(tree.name, tree, *self.get_start_end_lineno(tree))
        for child_idx, child in enumerate(tree.body):
            if isinstance(child, ast.FunctionDef):
                child_node = self.parse_function(child)
                class_node.children.append(child_node)
            elif isinstance(child, ast.AnnAssign):
                try:
                    next_child = tree.body[child_idx + 1]
                except IndexError:
                    next_child = None
                child_node = self.parse_annotated_assign(child, next_child)
                class_node.children.append(child_node)
        return class_node

    def parse_function(self, tree: ast.FunctionDef) -> Node:
        return Node(tree.name, tree, *self.get_start_end_lineno(tree))

    def parse_annotated_assign(self, tree: ast.AnnAssign, next_tree: ast.AST | None) -> Node:
        assert isinstance(tree.target, ast.Name)
        name = tree.target.id
        assert tree.end_lineno is not None
        start_lineno, end_lineno = self.get_start_end_lineno(tree)
        if next_tree is not None:
            next_start_lineno, next_end_lineno = self.get_start_end_lineno(next_tree)
            if (
                isinstance(next_tree, ast.Expr)
                and isinstance(next_tree.value, ast.Constant)
                and isinstance(next_tree.value.value, str)
                and next_start_lineno == end_lineno + 1
            ):
                # docstring
                end_lineno = next_end_lineno
        return Node(name, tree, start_lineno, end_lineno)

    def get_start_end_lineno(self, node: ast.AST) -> tuple[int, int]:
        (start, _), (end, _) = self.atok.get_text_positions(node, True)
        return start, end


class StubSrcManager:
    class _MissingHeader(Exception):
        pass

    def __init__(self, src: str):
        self.src = src
        self.src_lines = self.src.splitlines(keepends=True)

        self.atok = asttokens.ASTTokens(src, parse=True)
        self.tree = StubParser(src).parse()
        self.tree.end_line = len(self.src_lines)

        try:
            self.header: str | None = "".join(self._get_header_lines())
        except self._MissingHeader:
            self.header = None

    @classmethod
    def for_module(cls, module: types.ModuleType) -> StubSrcManager | None:
        module_name = module.__name__
        stub_file = BASE_DIR / f"{module_name}.pyi"
        if not stub_file.exists():
            return None
        src = stub_file.read_text("utf-8")
        return StubSrcManager(src)

    def _get_header_lines(self):
        if HEADER_END_MARKER not in self.src:
            raise self._MissingHeader
        for lineno, line in self.iter_lines(skip_markers=False):
            if line.startswith(HEADER_END_MARKER):
                self._header_end_marker_lineno = lineno
                return
            yield line

    def iter_lines(
        self, start: int = 1, end: int | None = None, skip_comments=True, skip_markers=True
    ) -> t.Iterator[tuple[int, str]]:
        if end is not None and start > end:
            return
        comment_section = 0
        for lineno, line in enumerate(self.src_lines[slice(start - 1, end)], start=start):
            if skip_comments:
                if COMMENT_SECTION_START.match(line):
                    if not COMMENT_SECTION_END.match(line):
                        comment_section = lineno
                    continue
                if COMMENT_SECTION_END.match(line):
                    comment_section = 0
                    continue
                if comment_section:
                    continue
            if skip_markers and line.startswith(MARKER):
                continue
            yield lineno, line

        if comment_section:
            raise SrcParsingError(f"Unclosed comment section, started at line {comment_section}.")

    def iter_body_lines(
        self, start: int = 1, end: int | None = None, skip_comments=True, skip_markers=True
    ) -> t.Iterator[tuple[int, str]]:
        if hasattr(self, "_header_end_marker_lineno"):
            start = max(start, self._header_end_marker_lineno + 1)
        return self.iter_lines(start, end, skip_comments, skip_markers)

    def get_body_range(self, start: int, end: int | None) -> str:
        return "".join(line for _, line in self.iter_body_lines(start, end))
