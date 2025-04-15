from __future__ import annotations

import typing as t

from pyrx import Db


class BlockReference(Db.BlockReference):
    @t.overload
    def attributes(
        self, rt: t.Literal["id"] = "id", open_mode: Db.OpenMode | None = None
    ) -> dict[str, Db.ObjectId]: ...
    @t.overload
    def attributes(
        self, rt: t.Literal["obj"] = "obj", open_mode: Db.OpenMode = Db.OpenMode.kForRead
    ) -> dict[str, Db.AttributeReference]: ...
    def attributes(
        self,
        rt: t.Literal["id", "obj"] = "id",
        open_mode: Db.OpenMode | None = Db.OpenMode.kForRead,
    ) -> dict[str, Db.ObjectId | Db.AttributeReference]:
        """
        Get the attributes of the block reference.

        Parameters:

            rt: return type, either "id" for ObjectId or "obj" for AttributeReference.

            open_mode: the open mode for the attribute references. Default is kForRead.
        """
        attrs = self.attributeIds()
        if rt == "id":
            return {Db.AttributeReference(id).tag(): id for id in attrs}
        elif rt == "obj":
            return {
                attr.tag(): attr for attr in (Db.AttributeReference(id, open_mode) for id in attrs)
            }
        else:
            raise ValueError(f"Invalid return type: {rt}")

    def get_attribute(
        self, tag: str, open_mode: Db.OpenMode = Db.OpenMode.kForRead
    ) -> Db.AttributeReference | None:
        """
        Get a specific attribute by its tag.
        Returns None if the attribute is not found.

        Parameters:

            tag: the tag of the attribute to get.

            open_mode: the open mode for the attribute reference. Default is kForRead.
        """
        attr_id = self.attributes().get(tag, None)
        if attr_id is None:
            return None
        return Db.AttributeReference(attr_id, open_mode)
