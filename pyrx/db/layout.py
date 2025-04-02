from __future__ import annotations

from pyrx import Db
from pyrx.utils.decorators import pass_working_db


@pass_working_db
def get_layouts(db: Db.Database = ..., model=False) -> list[Db.ObjectId]:
    """
    Retrieve layouts from the specified database, optionally excluding
    model space layout.

    Arguments:
        db: The database to retrieve layouts from. Defaults to ``None``,
            in which case the working database is used.
        model: If ``False``, exclude the layout associated with model space. Defaults to ``False``.
    """

    ld = Db.Dictionary(db.layoutDictionaryId())
    ids = sorted((id for id in ld.asDict().values()), key=lambda id: Db.Layout(id).getTabOrder())
    if not model:
        return ids[1:]
    return ids
