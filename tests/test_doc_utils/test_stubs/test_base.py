from pathlib import Path

import pytest

from pyrx.doc_utils.stubs.base import Node, SrcParsingError, StubParser, StubSrcManager

RESOURCES = Path(__file__).parent / "resources"


class TestStubSrcManager:
    def test_comments(self):
        src = (RESOURCES / "stubs_001.pyi").read_text("utf-8")
        src_manager = StubSrcManager(src)
        assert len(src_manager.src_lines) == 20
        assert src_manager.tree.end_line == 20
        assert src_manager.header is None
        only_src_lines = tuple(src_manager.iter_lines())
        assert len(only_src_lines) == 3

    def test_missing_comment_end(self):
        src = (RESOURCES / "stubs_002.pyi").read_text("utf-8")
        src_manager = StubSrcManager(src)
        assert len(src_manager.src_lines) == 16
        with pytest.raises(SrcParsingError, match="Unclosed comment section, started at line 12"):
            tuple(src_manager.iter_lines())

    def test_iter_lines(self):
        src = (RESOURCES / "stubs_003.pyi").read_text("utf-8")
        src_manager = StubSrcManager(src)
        assert len(src_manager.src_lines) == 8
        assert src_manager.tree.end_line == 8
        assert src_manager.header is not None
        only_src_lines = tuple(src_manager.iter_lines())
        assert len(only_src_lines) == 6
        lines_with_markers = tuple(src_manager.iter_lines(skip_markers=False))
        assert len(lines_with_markers) == 7
        lines_with_comments = tuple(src_manager.iter_lines(skip_comments=False))
        assert len(lines_with_comments) == 7
        all_lines = tuple(src_manager.iter_lines(skip_comments=False, skip_markers=False))
        assert len(all_lines) == 8

    def test_iter_body_lines(self):
        src = (RESOURCES / "stubs_004.pyi").read_text("utf-8")
        src_manager = StubSrcManager(src)
        only_src_lines = tuple(src_manager.iter_body_lines())
        assert len(only_src_lines) == 8
        lines_with_markers = tuple(src_manager.iter_body_lines(skip_markers=False))
        assert len(lines_with_markers) == 8  # only header_end marker so it is not in the body
        lines_with_comments = tuple(src_manager.iter_body_lines(skip_comments=False))
        assert len(lines_with_comments) == 10
        range_lines = tuple(src_manager.iter_body_lines(5, 15))
        assert len(range_lines) == 7

    def test_get_body_range(self):
        src = (RESOURCES / "stubs_004.pyi").read_text("utf-8")
        src_manager = StubSrcManager(src)
        body_range = src_manager.get_body_range(1, 20)
        assert len(body_range.splitlines()) == 8
        body_range = src_manager.get_body_range(5, 15)
        assert len(body_range.splitlines()) == 7
        body_range = src_manager.get_body_range(14, None)
        assert len(body_range.splitlines()) == 3

    def test_for_module(self):
        from pyrx import Db

        src_manager = StubSrcManager.for_module(Db)
        assert isinstance(src_manager, StubSrcManager)


class TestStubParser:
    def test_parse(self):
        src = (RESOURCES / "stubs_005.pyi").read_text("utf-8")
        stub_parser = StubParser(src)
        node = stub_parser.parse()
        assert isinstance(node, Node)

        assert node.name is None
        assert len(node.children) == 5
        class_Class = node.children[0]
        assert class_Class.name == "Class"
        assert class_Class.start_line == 7
        assert class_Class.end_line == 44
        assert class_Class.range == range(7, 44)
        assert len(class_Class.children) == 9

        Class_class_var = class_Class.children[0]
        assert Class_class_var.name == "class_var"
        assert Class_class_var.start_line == 12
        assert Class_class_var.end_line == 12
        assert Class_class_var.range == range(12, 12)

        Class_class_var2 = class_Class.children[1]
        assert Class_class_var2.name == "class_var2"
        assert Class_class_var2.start_line == 13
        assert Class_class_var2.end_line == 13
        assert Class_class_var2.range == range(13, 13)

        Class_class_var_with_docstring = class_Class.children[2]
        assert Class_class_var_with_docstring.name == "class_var_with_docstring"
        assert Class_class_var_with_docstring.start_line == 14
        assert Class_class_var_with_docstring.end_line == 17
        assert Class_class_var_with_docstring.range == range(14, 17)

        Class_static_meth = class_Class.children[3]
        assert Class_static_meth.name == "static_meth"
        assert Class_static_meth.start_line == 19
        assert Class_static_meth.end_line == 23
        assert Class_static_meth.range == range(19, 23)

        Class_class_meth = class_Class.children[4]
        assert Class_class_meth.name == "class_meth"
        assert Class_class_meth.start_line == 25
        assert Class_class_meth.end_line == 29
        assert Class_class_meth.range == range(25, 29)

        Class_instance_meth = class_Class.children[5]
        assert Class_instance_meth.name == "instance_meth"
        assert Class_instance_meth.start_line == 31
        assert Class_instance_meth.end_line == 34
        assert Class_instance_meth.range == range(31, 34)

        Class_overloaded_meth1 = class_Class.children[6]
        assert Class_overloaded_meth1.name == "overloaded_meth"
        assert Class_overloaded_meth1.start_line == 36
        assert Class_overloaded_meth1.end_line == 37
        assert Class_overloaded_meth1.range == range(36, 37)

        Class_overloaded_meth2 = class_Class.children[7]
        assert Class_overloaded_meth2.name == "overloaded_meth"
        assert Class_overloaded_meth2.start_line == 38
        assert Class_overloaded_meth2.end_line == 39
        assert Class_overloaded_meth2.range == range(38, 39)

        Class_overloaded_meth3 = class_Class.children[8]
        assert Class_overloaded_meth3.name == "overloaded_meth"
        assert Class_overloaded_meth3.start_line == 40
        assert Class_overloaded_meth3.end_line == 44
        assert Class_overloaded_meth3.range == range(40, 44)

        func = node.children[1]
        assert func.name == "func"
        assert func.start_line == 46
        assert func.end_line == 49
        assert func.range == range(46, 49)

        overloaded_func1 = node.children[2]
        assert overloaded_func1.name == "overloaded_func"
        assert overloaded_func1.start_line == 51
        assert overloaded_func1.end_line == 52
        assert overloaded_func1.range == range(51, 52)

        overloaded_func2 = node.children[3]
        assert overloaded_func2.name == "overloaded_func"
        assert overloaded_func2.start_line == 53
        assert overloaded_func2.end_line == 54
        assert overloaded_func2.range == range(53, 54)

        overloaded_func3 = node.children[4]
        assert overloaded_func3.name == "overloaded_func"
        assert overloaded_func3.start_line == 55
        assert overloaded_func3.end_line == 59
        assert overloaded_func3.range == range(55, 59)
