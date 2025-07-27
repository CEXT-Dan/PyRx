from __future__ import annotations

import typing as t
from pathlib import Path

from pyrx import Db, Ed, Ge
from pyrx.ge.point import point_3d
from pyrx.utils.decorators import pass_working_db

if t.TYPE_CHECKING:
    from pyrx.typing import UPoint


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


@pass_working_db
def get_block_reference(
    btr_id_or_name: Db.ObjectId[Db.BlockTableRecord] | str,
    position: UPoint = (0, 0, 0),
    rotation: t.SupportsFloat = 0.0,
    scale: t.SupportsFloat | Ge.Scale3d = 1.0,
    attributes: dict[str, str] | None = None,
    dyn_properties: dict[str, t.Any] | None = None,
    scale_dyn_properties: bool = False,
    db: Db.Database = ...,
) -> Db.ObjectId[Db.BlockReference]:
    """
    Create a block reference (insert) in the database.

    Note:
        The reference is added to the database, so if subsequent
        operations fail, you should remove the returned ID from the
        database. The object is NOT added to any layout (e.g.,
        modelspace).

    Args:
        btr_id_or_name: BlockTableRecord ObjectId or block name. If a name is given,
            the block is searched in the database and in search paths.
        position: Insertion coordinates for the block. Default is (0, 0, 0).
        rotation: Block rotation angle in radians. Default is 0.0.
        scale: Block scale factor or Ge.Scale3d object. Default is 1.0.
        attributes: Dictionary of attribute values to set in the block reference.
            Default is None.
        dyn_properties: Dictionary of dynamic property values to set in the block reference.
            Default is None.
        scale_dyn_properties: If True, dynamic properties are scaled according to the block scale.
            Requires uniform scale (sx == sy == sz). Default is False.
        db: Database in which the block reference will be created. Defaults to the working database.

    Returns:
        Db.ObjectId: The ObjectId of the newly created BlockReference.

    Raises:
        BlockNotFoundError: If the block is not found in the database.
        TypeError: If btr_id_or_name is not a string or Db.ObjectId.
        ValueError: If scale_dyn_properties is True and scale is not uniform.

    Example:
        >>> # Create a simple block reference
        >>> bref_id = get_block_reference("door", position=(10, 20, 0), scale=2.0)
        >>> bref = Db.BlockReference(bref_id)
        >>> Db.curDb().addToModelspace(bref)
        >>>
        >>> # Create block reference with attributes
        >>> attrs = {"TAG1": "Value1", "TAG2": "Value2"}
        >>> bref_id = get_block_reference("door", attributes=attrs)
    """
    # Resolve block table record ID from name or ObjectId
    if isinstance(btr_id_or_name, str):
        btr_id = get_block_by_name(btr_id_or_name, must_exists=False, db=db)
    elif not isinstance(btr_id_or_name, Db.ObjectId):
        raise TypeError(
            f"btr_id_or_name must be a string or Db.ObjectId, not {type(btr_id_or_name).__name__}"
        )
    else:
        btr_id = btr_id_or_name

    # Convert position to 3D point
    position = point_3d(position)

    # Convert scale to Ge.Scale3d if needed
    if not isinstance(scale, Ge.Scale3d):
        scale = Ge.Scale3d(float(scale))

    # Check for uniform scale if scaling dynamic properties
    if scale_dyn_properties and not (scale.sx == scale.sy == scale.sz):
        raise ValueError("scale_dyn_properties requires uniform scale")

    # Create BlockReference object
    block_ref = Db.BlockReference(position, btr_id)
    block_ref.setScaleFactors(scale)
    block_ref.setRotation(rotation)

    # Start transaction for safe object creation
    tmr = db.transactionManager()
    _ = tmr.startTransaction()
    bref_id = db.addObject(block_ref)
    tmr.addNewlyCreatedDBRObject(block_ref)

    try:
        block_def = Db.BlockTableRecord(btr_id)
        is_dynamic = block_def.isDynamicBlock()

        # Handle attribute definitions
        if block_def.hasAttributeDefinitions():
            for att_def_id in block_def.objectIds(Db.AttributeDefinition.desc()):
                att_def = Db.AttributeDefinition(att_def_id)
                if att_def.isConstant():
                    att_def.dispose()
                    continue
                att_ref = Db.AttributeReference()
                block_ref.appendAttribute(att_ref)
                att_ref.setAttributeFromBlock(att_def, block_ref.blockTransform())
                attr_value: str | None = None
                if attributes:
                    attr_value = attributes.get(att_def.tag(), None)
                if attr_value is not None:
                    att_ref.setTextString(attr_value)
                elif att_def.hasFields():
                    # Handle field attributes
                    att_def_field = Db.Field(att_def.getField())
                    flag = Db.FieldCodeFlag(
                        Db.FieldCodeFlag.kAddMarkers | Db.FieldCodeFlag.kFieldCode
                    )
                    field_code = att_def_field.getFieldCode(flag)
                    obj_code = f"%<\\_ObjId {block_ref.objectId().asOldId()}>%"
                    field_code = field_code.replace("?BlockRefId", obj_code)
                    att_ref_field = Db.Field(field_code)
                    att_ref_field.setOwnerId(bref_id)
                    att_ref_field.evaluate()
                    att_ref.setField(att_ref_field)
                    att_def_field.dispose()
                    att_ref_field.dispose()
                att_def.dispose()
                att_ref.dispose()

        block_def.dispose()
        block_ref.dispose()

        # Handle dynamic block properties
        if is_dynamic and dyn_properties:
            dyn_bref = Db.DynBlockReference(bref_id)
            if dyn_bref.isDynamicBlock():
                props = {prop.propertyName(): prop for prop in dyn_bref.getBlockProperties()}
                for prop_name, prop_value in dyn_properties.items():
                    try:
                        try:
                            prop = props[prop_name]
                        except KeyError:
                            continue
                        if prop.readOnly():
                            continue
                        unit_type = prop.unitsType()
                        # Scale dynamic properties if requested
                        if scale_dyn_properties:
                            if unit_type == Db.DynUnitsType.kDistance:
                                prop_value = prop_value * scale.sx
                            elif unit_type == Db.DynUnitsType.kArea:
                                prop_value = prop_value * (scale.sx**2)
                        if isinstance(prop_value, Db.EvalVariant):
                            value_eval = prop_value
                        else:
                            value_eval = Db.EvalVariant(prop_value)
                        prop.setValue(value_eval)
                    except Exception as err:
                        err.add_note(
                            f"Failed to set dynamic property '{prop_name}' "
                            f"with value '{prop_value}'"
                        )
                        raise
    except Exception:
        # Abort transaction on error
        tmr.abortTransaction()
        raise
    else:
        # Commit transaction
        tmr.endTransaction()
        return bref_id
