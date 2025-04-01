from pyrx import Db
from pyrx.db.database import working_db


class Test_working_db:
    def test_working_db(self):
        original_db = Db.workingDb()
        db = Db.Database(False, True)

        try:
            with working_db(db) as ctx_db:
                assert ctx_db is db
                assert Db.workingDb() == db
                assert Db.workingDb() is not original_db

                raise RuntimeError
        except RuntimeError:
            pass
        assert Db.workingDb() == original_db
        assert not Db.workingDb() == db
