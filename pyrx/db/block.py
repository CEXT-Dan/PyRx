from __future__ import annotations

import typing as t
from pathlib import Path

from pyrx import Db, Ed
from pyrx.utils.decorators import pass_working_db


class BlockNotFoundError(Exception):
    """Exception raised when a block does not exist in the database."""

    def __init__(self, block_name: str) -> None:
        super().__init__(f"Block definition '{block_name}' not found")
        self.block_name = block_name


class BlockAlreadyExistsError(Exception):
    """Exception raised when a block with the given name already exists in the database."""

    def __init__(self, block_name: str) -> None:
        super().__init__(f"Block definition '{block_name}' already exists")
        self.block_name = block_name


@pass_working_db
def add_block_definition(
    block_name: str,
    if_exists: t.Literal["skip", "replace", "raise"] = "raise",
    db: Db.Database = ...,
) -> Db.ObjectId[Db.BlockTableRecord]:
    """
    Add to database a new block definition from dwg or dxf file.

    Args:
        block_name: Name of the block definition to add. May be a
            file path or just the name. If a file path is provided, it
            should point to a .dwg or .dxf file. If only the name is
            provided, it will search for a file with that name in the
            search paths (with .dwg extension).
        if_exists: Action to take if the block name already exists in
            the database. If "skip", the existing block will be
            returned. If "replace", the existing block will be replaced
            with the new one. If "raise", a ``BlockAlreadyExistsError``
            exception will be raised if the block already exists.
        db: Database to which the block will be added. Defaults to the
            working database.

    Returns:
        Db.ObjectId: The ObjectId of the newly added block definition
            (BlockTableRecord).

    Raises:
        BlockAlreadyExistsError: If the block name already exists in
            the database and ``if_exists`` is set to "raise".
        FileNotFoundError: If the specified block file does not exist.
        ValueError: If ``if_exists`` is not one of the expected values.
    """
    block_path = Path(block_name)
    _block_name = block_path.stem

    # Handle existing block according to if_exists parameter
    try:
        btr_id = Db.BlockTable(db.blockTableId()).getAt(_block_name)
    except Db.ErrorStatusException as err:
        if not err.code == Db.ErrorStatus.eKeyNotFound:
            # If the error is not about key not found, re-raise it
            raise
        # if the block does not exist, continue with adding it
    else:
        # Block already exists, handle according to if_exists
        if if_exists == "skip":
            return btr_id
        elif if_exists == "replace":
            pass  # Continue with replacement logic
        elif if_exists == "raise":
            raise BlockAlreadyExistsError(_block_name)
        else:
            raise ValueError(f"Invalid if_exists value: {if_exists}")

    # Determine file path and validate existence
    if block_path.suffix not in (".dwg", ".dxf"):
        block_path = block_path.with_suffix(".dwg")

    if block_path.is_absolute():
        if not block_path.is_file():
            raise FileNotFoundError(f"Block file '{block_path}' does not exist")
        block_path_str = str(block_path)
    else:
        block_path_str = Ed.Core.findFile(str(block_path))
        if not block_path_str:
            raise FileNotFoundError(f"Block file '{block_path}' not found in search paths")

    # Load block from file
    block = Db.Database(False, True)
    if block_path.suffix == ".dxf":
        block.dxfIn(block_path_str)
    else:
        block.readDwgFile(block_path_str, Db.DatabaseOpenMode.kForReadAndAllShare, False, "")
        block.closeInput(True)

    # Insert block into target database
    block_id = Db.ObjectId()
    db.insert(block_id, _block_name, block, if_exists == "replace")
    return block_id


@pass_working_db
def get_block_by_name(
    block_name: str, must_exists: bool = False, db: Db.Database = ...
) -> Db.ObjectId[Db.BlockTableRecord]:
    """
    Retrieve a block definition by its name from the database.

    This function attempts to find an existing block definition in the database.
    If the block doesn't exist and `must_exists` is False, it will automatically
    try to load the block from a file with the same name found in the search paths.

    Args:
        block_name: Name of the block definition to retrieve. Can be
            just the block name (e.g., "my_block") or a file path. If
            only a name is provided, the function will search for a
            corresponding .dwg file in the AutoCAD search paths.
        must_exists: If True, raises ``BlockNotFoundError`` immediately
            when the block is not found in the database, without
            attempting to load from file. If False (default), tries to
            load the block from file if not found in database.
        db: Database to search in. Defaults to the working database.

    Returns:
        ObjectId: The ObjectId (BlockTableRecord) of the found or newly
            loaded block definition.

    Raises:
        BlockNotFoundError: If the block is not found in the database
            and either `must_exists` is True or the block file cannot be
            found/loaded.

    Example:
        >>> # Get existing block or load from file
        >>> block_id = get_block_by_name("door_symbol")
        >>>
        >>> # Only get if already exists in database
        >>> block_id = get_block_by_name("window", must_exists=True)
    """
    try:
        # Try to find the block in the current database
        return Db.BlockTable(db.blockTableId()).getAt(block_name)
    except Db.ErrorStatusException as err:
        # Re-raise any error that's not "key not found"
        if not err.code == Db.ErrorStatus.eKeyNotFound:
            raise

    # Block not found in database
    if must_exists:
        # User explicitly wants only existing blocks
        raise BlockNotFoundError(block_name)

    try:
        # Attempt to load block definition from file
        # This will search in AutoCAD's search paths for a .dwg file
        return add_block_definition(block_name, db=db)
    except FileNotFoundError:
        # Block file not found in search paths, convert to our custom exception
        raise BlockNotFoundError(block_name) from None
