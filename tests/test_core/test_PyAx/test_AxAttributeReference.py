from __future__ import annotations

from pyrx import Ax, Db, Ge


# Note, we can't create a AcadAttributeReference directly
class TestAxAttributeReference:

    def _get_attr_ref(self, db: Db.Database) -> Ax.AcadAttributeReference:
        """
        Find an AcadAttributeReference already present in the database.

        This class cannot be instantiated from Python, so we locate one that
        lives inside a block reference (the only place attribute references
        exist). We prefer the first one we can find in model space and fall
        back to a known handle in this media file.
        """
        try:
            axSpace = db.acadDatabase().modelSpace()
            for ent in axSpace:
                if ent.objectName() != "AcDbBlockReference":
                    continue
                ref = Ax.AcadBlockReference.cast(ent)
                if ref.hasAttributes():
                    attrs = ref.attributes()
                    if attrs:
                        return attrs[0]
        except Exception:
            pass
        # Fallback: a known attribute reference handle in 06457.dwg.
        objId = db.getObjectId(False, Db.Handle("8705"))
        assert objId.isDerivedFrom(Db.AttributeReference.desc())
        return Ax.AcadAttributeReference.cast(objId.acadObject())

    def test_rotation(self, db_06457: Db.Database):
        objHnd = Db.Handle("8705")
        objId = db_06457.getObjectId(False, objHnd)
        assert objId.isDerivedFrom(Db.AttributeReference.desc())
        axRef = Ax.AcadAttributeReference.cast(objId.acadObject())
        old = axRef.rotation()
        try:
            axRef.setRotation(1.0)
            assert axRef.rotation() == 1.0
        finally:
            axRef.setRotation(old)

    def test_class_name(self, db_06457: Db.Database):
        axRef = self._get_attr_ref(db_06457)
        # The ATTRIB entity's real ObjectARX object name is "AcDbAttribute".
        assert axRef.objectName() == "AcDbAttribute"
        class_name = Ax.AcadAttributeReference.className()
        assert isinstance(class_name, str)
        assert len(class_name) > 0

    def test_read_properties(self, db_06457: Db.Database):
        axRef = self._get_attr_ref(db_06457)
        # Text/shape properties
        assert isinstance(axRef.height(), float)
        assert isinstance(axRef.rotation(), float)
        assert isinstance(axRef.scaleFactor(), float)
        assert isinstance(axRef.thickness(), float)
        assert isinstance(axRef.obliqueAngle(), float)
        # Boolean flags
        assert isinstance(axRef.backward(), bool)
        assert isinstance(axRef.invisible(), bool)
        assert isinstance(axRef.constant(), bool)
        assert isinstance(axRef.upsideDown(), bool)
        assert isinstance(axRef.isMTextAttribute(), bool)
        # Length / generation
        assert isinstance(axRef.fieldLength(), int)
        assert isinstance(axRef.textGenerationFlag(), int)
        # Strings
        assert isinstance(axRef.tagString(), str)
        assert isinstance(axRef.textString(), str)
        assert isinstance(axRef.styleName(), str)
        # Alignment enums
        assert isinstance(axRef.alignment(), Ax.AcAlignment)
        assert isinstance(axRef.horizontalAlignment(), Ax.AcHorizontalAlignment)
        assert isinstance(axRef.verticalAlignment(), Ax.AcVerticalAlignment)
        # Geometry
        assert isinstance(axRef.insertionPoint(), Ge.Point3d)
        assert isinstance(axRef.normal(), Ge.Vector3d)

    def test_set_height(self, db_06457: Db.Database):
        axRef = self._get_attr_ref(db_06457)
        old = axRef.height()
        try:
            axRef.setHeight(2.5)
            assert axRef.height() == 2.5
        finally:
            axRef.setHeight(old)

    def test_set_scale_factor(self, db_06457: Db.Database):
        axRef = self._get_attr_ref(db_06457)
        old = axRef.scaleFactor()
        try:
            axRef.setScaleFactor(1.5)
            assert axRef.scaleFactor() == 1.5
        finally:
            axRef.setScaleFactor(old)

    def test_set_thickness(self, db_06457: Db.Database):
        axRef = self._get_attr_ref(db_06457)
        old = axRef.thickness()
        try:
            axRef.setThickness(0.5)
            assert axRef.thickness() == 0.5
        finally:
            axRef.setThickness(old)

    def test_set_insertion_point(self, db_06457: Db.Database):
        axRef = self._get_attr_ref(db_06457)
        old = axRef.insertionPoint()
        new = Ge.Point3d(10.0, 20.0, 30.0)
        try:
            axRef.setInsertionPoint(new)
            assert axRef.insertionPoint() == new
        finally:
            axRef.setInsertionPoint(old)

    def test_set_normal(self, db_06457: Db.Database):
        axRef = self._get_attr_ref(db_06457)
        old = axRef.normal()
        try:
            axRef.setNormal(Ge.Vector3d.kZAxis)
            assert axRef.normal() == Ge.Vector3d.kZAxis
        finally:
            axRef.setNormal(old)

    def test_set_text_string(self, db_06457: Db.Database):
        axRef = self._get_attr_ref(db_06457)
        old = axRef.textString()
        try:
            axRef.setTextString("PyRx Test")
            assert axRef.textString() == "PyRx Test"
        finally:
            axRef.setTextString(old)

    def test_set_invisible(self, db_06457: Db.Database):
        axRef = self._get_attr_ref(db_06457)
        old = axRef.invisible()
        try:
            axRef.setInvisible(True)
            assert axRef.invisible() is True
        finally:
            axRef.setInvisible(old)

    def test_set_backward(self, db_06457: Db.Database):
        axRef = self._get_attr_ref(db_06457)
        old = axRef.backward()
        try:
            axRef.setBackward(True)
            assert axRef.backward() is True
        finally:
            axRef.setBackward(old)

    def test_set_upside_down(self, db_06457: Db.Database):
        axRef = self._get_attr_ref(db_06457)
        old = axRef.upsideDown()
        try:
            axRef.setUpsideDown(True)
            assert axRef.upsideDown() is True
        finally:
            axRef.setUpsideDown(old)

    def test_set_style_name(self, db_06457: Db.Database):
        axRef = self._get_attr_ref(db_06457)
        old = axRef.styleName()
        try:
            axRef.setStyleName("Standard")
            assert axRef.styleName() == "Standard"
        finally:
            axRef.setStyleName(old)
