import collections.abc as c
from contextlib import contextmanager

from pyrx import Db


@contextmanager
def working_db(db: Db.Database) -> c.Generator[Db.Database, None, None]:
    """
    A context manager to temporarily set the working database.

    This function sets the specified database as the working database for the
    duration of the context. Once the context is exited, the original working
    database is restored.

    Arguments:
        db: The database to set as the working database.

    Yields:
        Db.Database: The database that was set as the working database.

    Examples::

        original_db = Db.workingDb()
        with working_db(Db.Database(False, True)) as db:
            # do something with the working database
            ...
        assert Db.workingDb() == original_db
    """
    original_db = Db.workingDb()
    Db.setWorkingDb(db)
    try:
        yield db
    finally:
        Db.setWorkingDb(original_db)
