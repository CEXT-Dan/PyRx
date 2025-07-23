# TODO: I would like to test the prompting functions using
# queue_command, but BricsCAD does not yet work with queue_command.

import math
import re
from unittest.mock import patch

import pytest

from pyrx import Db, Ed, Ge
from pyrx.ed.prompt import (
    PromptException,
    _ent_type_to_desc,
    _prompt,
    entsel,
    get_angle,
    get_corner,
    get_dist,
    get_double,
    get_integer,
    get_point,
    get_string,
    raise_for_status, Kwords, InitGetCtx, InitGetFlags,
    PromptExceptionKword, init_get, get_kword, PromptExceptionError
)


class Test_raise_for_status:
    def test_ok_status(self):
        res_1 = (Ed.PromptStatus.eOk, "result")
        assert raise_for_status(res_1) == "result"

        res_2 = (Ed.PromptStatus.eOk, "args1", "args2")
        assert raise_for_status(res_2) == ("args1", "args2")

    def test_error_status(self):
        res = (Ed.PromptStatus.eError, "error message")
        with pytest.raises(
            PromptExceptionError, match=re.escape("Prompt rejected with status: eError (-5001)")
        ):
            raise_for_status(res)


class Test_ent_type_to_desc:
    def test_rx_class(self):
        desc = Db.Line.desc()
        assert _ent_type_to_desc(desc) == desc

    def test_db_entity_subclass(self):
        res = _ent_type_to_desc(Db.Line)
        assert res == Db.Line.desc()

    def test_invalid_type(self):
        with pytest.raises(TypeError, match="Invalid type: int"):
            _ent_type_to_desc(123)


class Test_entsel:
    def test_select_entity_without_type(self):
        line = Db.Line()
        db = Db.Database()
        line_id = db.addToModelspace(line)
        line.close()
        with patch("pyrx.ed.prompt.Ed.Editor.entSel") as mock_entSel:
            mock_entSel.return_value = (Ed.PromptStatus.eOk, line_id, Ge.Point3d())
            result = entsel("Select line: ")
            assert isinstance(result, Db.ObjectId)

    def test_select_entity_with_single_type(self):
        line = Db.Line()
        db = Db.Database()
        line_id = db.addToModelspace(line)
        line.close()
        with patch("pyrx.ed.prompt.Ed.Editor.entSel") as mock_entSel:
            mock_entSel.return_value = (Ed.PromptStatus.eOk, line_id, Ge.Point3d())
            result = entsel("Select line: ", Db.Line)
            assert isinstance(result, Db.ObjectId)

    def test_select_entity_with_multiple_types(self):
        line = Db.Line()
        db = Db.Database()
        line_id = db.addToModelspace(line)
        line.close()
        with patch("pyrx.ed.prompt.Ed.Editor.entSel") as mock_entSel:
            mock_entSel.return_value = (Ed.PromptStatus.eOk, line_id, Ge.Point3d())
            result = entsel("Select entity: ", [Db.Line, Db.Circle])
            assert isinstance(result, Db.ObjectId)

class Test_get_point:
    def test_get_point_without_base_point(self):
        point = Ge.Point3d(1, 2, 3)
        with patch("pyrx.ed.prompt.Ed.Editor.getPoint") as mock_getPoint:
            mock_getPoint.return_value = (Ed.PromptStatus.eOk, point)
            prompt = "Select point: "
            result = get_point(prompt)
            mock_getPoint.assert_called_once_with(prompt)
            assert isinstance(result, Ge.Point3d)
            assert result == point

    def test_get_point_with_base_point(self):
        base_point = Ge.Point3d(0, 0, 0)
        point = Ge.Point3d(1, 2, 3)
        prompt = "Select point: "
        with patch("pyrx.ed.prompt.Ed.Editor.getPoint") as mock_getPoint:
            mock_getPoint.return_value = (Ed.PromptStatus.eOk, point)
            result = get_point(prompt, base_point)
            mock_getPoint.assert_called_once_with(base_point, prompt)
            assert isinstance(result, Ge.Point3d)
            assert result == point


class Test_get_angle:
    def test_get_angle_in_radians(self):
        base_point = Ge.Point3d(0, 0, 0)
        angle = math.pi / 4  # 45 degrees in radians
        prompt = "Specify angle: "
        with patch("pyrx.ed.prompt.Ed.Editor.getAngle") as mock_getAngle:
            mock_getAngle.return_value = (Ed.PromptStatus.eOk, angle)
            result = get_angle(prompt, base_point)
            mock_getAngle.assert_called_once_with(base_point, prompt)
            assert isinstance(result, float)
            assert result == angle

    def test_get_angle_in_degrees(self):
        base_point = Ge.Point3d(0, 0, 0)
        angle = math.pi / 4  # 45 degrees in radians
        prompt = "Specify angle: "
        with patch("pyrx.ed.prompt.Ed.Editor.getAngle") as mock_getAngle:
            mock_getAngle.return_value = (Ed.PromptStatus.eOk, angle)
            result = get_angle(prompt, base_point, degrees=True)
            mock_getAngle.assert_called_once_with(base_point, prompt)
            assert isinstance(result, float)
            assert result == pytest.approx(45.0)

    def test_get_angle_with_default_base_point(self):
        angle = math.pi / 2  # 90 degrees in radians
        prompt = "Specify angle: "
        with patch("pyrx.ed.prompt.Ed.Editor.getAngle") as mock_getAngle:
            mock_getAngle.return_value = (Ed.PromptStatus.eOk, angle)
            result = get_angle(prompt)
            mock_getAngle.assert_called_once_with(Ge.Point3d(), prompt)
            assert isinstance(result, float)
            assert result == angle


class Test_get_corner:
    def test_get_corner_with_default_base_point(self):
        corner_point = Ge.Point3d(5, 5, 0)
        prompt = "Specify corner: "
        with patch("pyrx.ed.prompt.Ed.Editor.getCorner") as mock_getCorner:
            mock_getCorner.return_value = (Ed.PromptStatus.eOk, corner_point)
            result = get_corner(prompt)
            mock_getCorner.assert_called_once_with(Ge.Point3d(), prompt)
            assert isinstance(result, Ge.Point3d)
            assert result == corner_point

    def test_get_corner_with_custom_base_point(self):
        base_point = Ge.Point3d(1, 1, 0)
        corner_point = Ge.Point3d(5, 5, 0)
        prompt = "Specify corner: "
        with patch("pyrx.ed.prompt.Ed.Editor.getCorner") as mock_getCorner:
            mock_getCorner.return_value = (Ed.PromptStatus.eOk, corner_point)
            result = get_corner(prompt, base_point)
            mock_getCorner.assert_called_once_with(base_point, prompt)
            assert isinstance(result, Ge.Point3d)
            assert result == corner_point


class Test_get_dist:
    def test_get_dist_with_base_point(self):
        base_point = Ge.Point3d(0, 0, 0)
        distance = 10.0
        prompt = "Specify distance: "
        with patch("pyrx.ed.prompt.Ed.Editor.getDist") as mock_getDist:
            mock_getDist.return_value = (Ed.PromptStatus.eOk, distance)
            result = get_dist(prompt, base_point)
            mock_getDist.assert_called_once_with(base_point, prompt)
            assert isinstance(result, float)
            assert result == distance

    def test_get_dist_without_base_point(self):
        base_point = Ge.Point3d(1, 1, 1)
        distance = 15.0
        prompt = "Specify distance: "
        with (
            patch("pyrx.ed.prompt.get_point") as mock_get_point,
            patch("pyrx.ed.prompt.Ed.Editor.getDist") as mock_getDist,
        ):
            mock_get_point.return_value = base_point
            mock_getDist.return_value = (Ed.PromptStatus.eOk, distance)
            result = get_dist(prompt)
            mock_get_point.assert_called_once_with(_prompt("Specify base point"))
            mock_getDist.assert_called_once_with(base_point, prompt)
            assert isinstance(result, float)
            assert result == distance


class Test_get_double:
    def test_get_double_without_condition(self):
        value = 42.0
        prompt = "Enter a real number: "
        with patch("pyrx.ed.prompt.Ed.Editor.getDouble") as mock_getDouble:
            mock_getDouble.return_value = (Ed.PromptStatus.eOk, value)
            result = get_double(prompt)
            mock_getDouble.assert_called_once_with(prompt)
            assert isinstance(result, float)
            assert result == value

    def test_get_double_with_condition_as_enum(self):
        value = 3.14
        prompt = "Enter a real number: "
        condition = Ed.PromptCondition.eNoZero
        with patch("pyrx.ed.prompt.Ed.Editor.getDouble") as mock_getDouble:
            mock_getDouble.return_value = (Ed.PromptStatus.eOk, value)
            result = get_double(prompt, condition)
            mock_getDouble.assert_called_once_with(prompt, condition)
            assert isinstance(result, float)
            assert result == value

    def test_get_double_with_condition_as_int(self):
        value = 7.89
        prompt = "Enter a real number: "
        condition = Ed.PromptCondition.eNoNegitive | Ed.PromptCondition.eNoZero
        assert isinstance(condition, int)
        with patch("pyrx.ed.prompt.Ed.Editor.getDouble") as mock_getDouble:
            mock_getDouble.return_value = (Ed.PromptStatus.eOk, value)
            result = get_double(prompt, condition)
            mock_getDouble.assert_called_once_with(prompt, Ed.PromptCondition(condition))
            assert isinstance(result, float)
            assert result == value


class Test_get_integer:
    def test_get_integer_without_condition(self):
        value = 42
        prompt = "Enter an integer: "
        with patch("pyrx.ed.prompt.Ed.Editor.getInteger") as mock_getInteger:
            mock_getInteger.return_value = (Ed.PromptStatus.eOk, value)
            result = get_integer(prompt)
            mock_getInteger.assert_called_once_with(prompt)
            assert isinstance(result, int)
            assert result == value

    def test_get_integer_with_condition_as_enum(self):
        value = 7
        prompt = "Enter an integer: "
        condition = Ed.PromptCondition.eNoZero
        with patch("pyrx.ed.prompt.Ed.Editor.getInteger") as mock_getInteger:
            mock_getInteger.return_value = (Ed.PromptStatus.eOk, value)
            result = get_integer(prompt, condition)
            mock_getInteger.assert_called_once_with(prompt, condition)
            assert isinstance(result, int)
            assert result == value

    def test_get_integer_with_condition_as_int(self):
        value = 15
        prompt = "Enter an integer: "
        condition = Ed.PromptCondition.eNoNegitive | Ed.PromptCondition.eNoZero
        assert isinstance(condition, int)
        with patch("pyrx.ed.prompt.Ed.Editor.getInteger") as mock_getInteger:
            mock_getInteger.return_value = (Ed.PromptStatus.eOk, value)
            result = get_integer(prompt, condition)
            mock_getInteger.assert_called_once_with(prompt, Ed.PromptCondition(condition))
            assert isinstance(result, int)
            assert result == value


class Test_get_string:
    def test_get_string_without_condition(self):
        value = "test"
        prompt = "Enter a string: "
        cronly = False
        with patch("pyrx.ed.prompt.Ed.Editor.getString") as mock_getString:
            mock_getString.return_value = (Ed.PromptStatus.eOk, value)
            result = get_string(prompt, cronly=cronly)
            mock_getString.assert_called_once_with(cronly, prompt)
            assert isinstance(result, str)
            assert result == value

    def test_get_string_with_condition_as_enum(self):
        value = "valid string"
        prompt = "Enter a string: "
        cronly = True
        condition = Ed.PromptCondition.eNoZero
        with patch("pyrx.ed.prompt.Ed.Editor.getString") as mock_getString:
            mock_getString.return_value = (Ed.PromptStatus.eOk, value)
            result = get_string(prompt, condition, cronly)
            mock_getString.assert_called_once_with(cronly, prompt, condition)
            assert isinstance(result, str)
            assert result == value

    def test_get_string_with_condition_as_int(self):
        value = "another string"
        prompt = "Enter a string: "
        cronly = False
        condition = Ed.PromptCondition.eNoNegitive | Ed.PromptCondition.eNoZero
        assert isinstance(condition, int)
        with patch("pyrx.ed.prompt.Ed.Editor.getString") as mock_getString:
            mock_getString.return_value = (Ed.PromptStatus.eOk, value)
            result = get_string(prompt, condition, cronly)
            mock_getString.assert_called_once_with(cronly, prompt, Ed.PromptCondition(condition))
            assert isinstance(result, str)
            assert result == value
class Test_Kwords:
    def test_init_with_empty_keywords(self):
        Kwords([])

    def test_init_with_invalid_keywords_type(self):
        with pytest.raises(
            ValueError,
            match=re.escape(
                "kwords must be an iterable of strings or tuples of "
                "(localized, lang-independent) strings"),
        ):
            Kwords([123, 456])

    def test_init_with_mixed_keywords(self):
        with pytest.raises(
            ValueError,
            match=re.escape(
                "kwords must be an iterable of strings or tuples of "
                "(localized, lang-independent) strings"),
        ):
            Kwords(["valid", (123, "invalid")])

    def test_init_with_localized_only_keywords(self):
        kwords = ["keyword1", "keyword2", "keyword3"]
        obj = Kwords(kwords)
        assert obj._kwords == tuple(kwords)
        assert obj._kwords_type == 1

    def test_init_with_localized_and_lang_independent_keywords(self):
        kwords = [("localized1", "independent1"), ("localized2", "independent2")]
        obj = Kwords(kwords)
        assert obj._kwords == tuple(kwords)
        assert obj._kwords_type == 2

    def test_as_init_get_localized_only(self):
        kwords = ["keyword1", "keyword2", "keyword3"]
        obj = Kwords(kwords)
        result = obj.as_init_get()
        assert result == "keyword1 keyword2 keyword3"

    def test_as_init_get_localized_and_lang_independent(self):
        kwords = [("localized1", "independent1"), ("localized2", "independent2")]
        obj = Kwords(kwords)
        result = obj.as_init_get()
        assert result == "localized1 localized2 _independent1 independent2"
class Test_InitGetCtx:
    def test_init_with_int_flags_and_kwords_list(self):
        ctx = InitGetCtx(InitGetFlags.RSG_NONULL, ["A", "B"])
        assert ctx.flags == InitGetFlags.RSG_NONULL
        assert isinstance(ctx.kwords, Kwords)
        assert ctx.kwords._kwords == ("A", "B")

    def test_init_with_enum_flags_and_Kwords_instance(self):
        kwords = Kwords(["A", "B"])
        ctx = InitGetCtx(InitGetFlags.RSG_NOZERO, kwords)
        assert ctx.flags == InitGetFlags.RSG_NOZERO
        assert isinstance(ctx.kwords, Kwords)
        assert tuple(ctx.kwords) == tuple(kwords)

    def test_init_with_none_kwords(self):
        ctx = InitGetCtx(0, None)
        assert isinstance(ctx.kwords, Kwords)
        assert tuple(ctx.kwords) == ()

    def test_call_invokes_initGet_and_raises_for_status(self):
        kwords = Kwords(["A", "B"])
        with patch("pyrx.ed.prompt.Ed.Editor.initGet") as mock_initGet, patch("pyrx.ed.prompt.raise_for_status") as mock_raise_for_status:
            mock_initGet.return_value = Ed.PromptStatus.eOk
            ctx = InitGetCtx(InitGetFlags.RSG_NONULL, kwords)
            ctx.call()
            mock_initGet.assert_called_once_with(int(InitGetFlags.RSG_NONULL), "A B")
            mock_raise_for_status.assert_called_once_with(mock_initGet.return_value)

    def test_enter_calls_call_and_returns_self(self):
        with patch.object(InitGetCtx, "call") as mock_call:
            ctx = InitGetCtx(0, None)
            result = ctx.__enter__()
            mock_call.assert_called_once()
            assert result is ctx

    def test_exit_keyword_exception_raises_KwordPromptException(self):
        with patch("pyrx.ed.prompt.Ed.Editor.getInput") as mock_getInput:
            mock_getInput.return_value = "KW"
            with pytest.raises(PromptExceptionKword) as excinfo:
                with InitGetCtx():
                    raise PromptException(Ed.PromptStatus.eKeyword)
            assert excinfo.value.kword == "KW"

    def test_exit_non_keyword_exception_does_nothing(self):
        with pytest.raises(PromptException) as excinfo:
            with InitGetCtx():
                raise PromptExceptionError()
        assert excinfo.value.status == Ed.PromptStatus.eError
def test_init_get():
    with patch ("pyrx.ed.prompt.Ed.Editor.initGet") as mock_initGet:
        mock_initGet.return_value = Ed.PromptStatus.eOk
        res = init_get(2, ["A", "B"])
        assert isinstance(res, InitGetCtx)
        mock_initGet.assert_called_once_with(2, "A B")


class Test_get_kword:
    def test_get_kword_with_explicit_prompt(self):
        prompt = "Choose option: "
        with patch("pyrx.ed.prompt.init_get") as mock_init_get,patch("pyrx.ed.prompt.Ed.Editor.getKword") as mock_getKword:
            mock_init_get.return_value = Ed.PromptStatus.eOk
            mock_getKword.return_value = (Ed.PromptStatus.eOk, "Yes")
            get_kword(prompt)
            mock_init_get.assert_called_once()
            mock_getKword.assert_called_once_with(prompt)

    def test_get_kword_with_default_prompt_and_no_kwords(self):
        with patch("pyrx.ed.prompt.init_get") as mock_init_get,patch("pyrx.ed.prompt.Ed.Editor.getKword") as mock_getKword:
            mock_getKword.return_value = (Ed.PromptStatus.eOk, "B")
            result = get_kword()
            mock_init_get.assert_called_once()
            mock_getKword.assert_called_once_with("\nSelect a keyword: ")
            assert result == "B"

    def test_get_kword_with_default_prompt_and_kwords(self):
        with patch("pyrx.ed.prompt.init_get") as mock_init_get,patch("pyrx.ed.prompt.Ed.Editor.getKword") as mock_getKword:
            mock_getKword.return_value = (Ed.PromptStatus.eOk, "Yes")
            result = get_kword(kwords=["Yes", "No"])
            mock_init_get.assert_called_once()
            mock_getKword.assert_called_once_with("\nSelect a keyword [Yes/No]: ")
            assert result == "Yes"

