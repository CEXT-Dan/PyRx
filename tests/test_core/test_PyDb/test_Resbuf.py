from __future__ import annotations

from pyrx import Db, Rx


class TestResbuf:
    def test_invoke_list(self):
        args = [
            (Rx.LispType.kText, "C:ADDNUM"),
            (Rx.LispType.kInt16, 10),
            (Rx.LispType.kNone, 0),
        ]
        expected = [(5005, "C:ADDNUM"), (5003, 10)]
        result = Db.Core.resbufTest(args)
        assert expected == result

    def test_invoke_rtdxf0(self):
        args = [(0, "LEADER")]
        expected = [(0, "LEADER")]
        result = Db.Core.resbufTest(args)
        assert expected == result

    def test_ssfilters(self):
        args = [
            (0, "circle"),
            (-4, "<OR"),
            (40, 6.5),
            (40, 12.5),
            (40, 16.0),
            (-4, "OR>"),
        ]
        expected = [
            (0, "circle"),
            (-4, "<OR"),
            (40, 6.5),
            (40, 12.5),
            (40, 16.0),
            (-4, "OR>"),
        ]
        result = Db.Core.resbufTest(args)
        assert expected == result

    def test_xdata(self):
        args = [
            (1002, "{"),
            (1070, 1),
            (1002, "{"),
            (1070, 2),
            (1070, 3),
            (1002, "}"),
            (1070, 4),
            (1002, "}"),
        ]
        expected = [
            (1002, "{"),
            (1070, 1),
            (1002, "{"),
            (1070, 2),
            (1070, 3),
            (1002, "}"),
            (1070, 4),
            (1002, "}"),
        ]
        result = Db.Core.resbufTest(args)
        assert expected == result

    def test_nested(self):
        args = [
            (Rx.LispType.kListBegin, 0),
            (Rx.LispType.kText, "Hi"),
            (Rx.LispType.kListEnd, 0),
            (Rx.LispType.kListBegin, 0),
            (Rx.LispType.kText, "world"),
            (Rx.LispType.kListEnd, 0),
        ]

        expected = [
            (Rx.LispType.kListBegin, 0),
            (Rx.LispType.kText, "Hi"),
            (Rx.LispType.kListEnd, 0),
            (Rx.LispType.kListBegin, 0),
            (Rx.LispType.kText, "world"),
            (Rx.LispType.kListEnd, 0),
        ]

        result = Db.Core.resbufTest(args)
        assert expected == result

    def test_binary_chunk(self):
        args = [(Db.DxfCode.kDxfBinaryChunk, bytes(b"mystring1"))]
        expected = [(Db.DxfCode.kDxfBinaryChunk, bytes(b"mystring1"))]
        result = Db.Core.resbufTest(args)
        assert expected == result

    def test_empty_string(self):
        args = [(Rx.LispType.kText, None)]
        expected = [(Rx.LispType.kText, "")]
        result = Db.Core.resbufTest(args)
        assert expected == result
