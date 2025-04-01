from pyrx import Db
from pyrx.db.layout import get_layouts


class Test_get_layouts:
    def test_with_modelspace(self, db_06457: Db.Database):
        res = get_layouts(db_06457, model=True)
        assert len(res) == 12

        for id, expected_name in zip(
            res,
            ["Model", "14.0", "14.1", "14.2", "30.1", "S1", "S2", "S3", "S4", "S5", "S6", "S7"],
        ):
            assert Db.Layout(id).getLayoutName() == expected_name

    def test_without_modelspace(self, db_06457: Db.Database):
        res = get_layouts(db_06457, model=False)
        assert len(res) == 11
        for id, expected_name in zip(
            res,
            ["14.0", "14.1", "14.2", "30.1", "S1", "S2", "S3", "S4", "S5", "S6", "S7"],
        ):
            assert Db.Layout(id).getLayoutName() == expected_name
