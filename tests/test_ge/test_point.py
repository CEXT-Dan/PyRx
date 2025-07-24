import pytest
from pyrx.ge.point import point_2d, point_3d
from pyrx import Ge


class Test_point_2d:
    """Tests for point_2d function."""
    def test_from_coords(self):
        """Test creating Point2d from individual coordinates."""
        pt = point_2d(1.5, 2.5)
        assert isinstance(pt, Ge.Point2d)
        assert pt.x == 1.5
        assert pt.y == 2.5


    def test_from_list(self):
        """Test creating Point2d from a list of coordinates."""
        pt = point_2d([3, 4])
        assert isinstance(pt, Ge.Point2d)
        assert pt.x == 3
        assert pt.y == 4


    def test_from_iterable(self):
        """Test creating Point2d from iterable."""
        pt = point_2d(iter((5.0, 6.0)))
        assert isinstance(pt, Ge.Point2d)
        assert pt.x == 5.0
        assert pt.y == 6.0


    def test_from_iterable_with_z(self):
        """Test creating Point2d from 3D coordinates (z is ignored)."""
        pt = point_2d([7, 8, 9])
        assert isinstance(pt, Ge.Point2d)
        assert pt.x == 7
        assert pt.y == 8


    def test_from_point3d(self):
        """Test creating Point2d from an existing Point3d (z is discarded)."""
        pt3d = Ge.Point3d(10, 11, 12)
        pt = point_2d(pt3d)
        assert isinstance(pt, Ge.Point2d)
        assert pt.x == 10
        assert pt.y == 11


    def test_from_point2d_returns_same(self):
        """Test that passing Point2d."""
        pt2d = Ge.Point2d(13, 14)
        pt = point_2d(pt2d)
        assert isinstance(pt, Ge.Point2d)
        assert pt.x == 13
        assert pt.y == 14
        assert pt is not pt2d  # Should return a different instance


    def test_from_point2d_with_extra_args_raises(self):
        """Test that providing extra arguments with Point2d raises ValueError."""
        pt2d = Ge.Point2d(1, 2)
        with pytest.raises(ValueError, match="If x_or_point is a Point2d, y and z should not be provided"):
            point_2d(pt2d, 3)


    def test_from_number_without_y_raises(self):
        """Test that providing only x coordinate raises ValueError."""
        with pytest.raises(ValueError, match="If x_or_point is a number, y must be provided"):
            point_2d(1.0)


    def test_with_not_enough_coords_raises(self):
        """Test that providing insufficient coordinates raises ValueError."""
        with pytest.raises(ValueError, match="Not enough coordinates provided"):
            point_2d([])

        with pytest.raises(ValueError, match="Not enough coordinates provided"):
            point_2d([1])


    def test_with_too_many_coords_raises(self):
        """Test that providing too many coordinates raises ValueError."""
        with pytest.raises(ValueError, match="Too many coordinates provided"):
            point_2d([1, 2, 3, 4])



class Test_point_3d:
    """Tests for point_3d function."""
    def test_from_coords(self):
        """Test creating Point3d from individual coordinates."""
        pt = point_3d(1.5, 2.5, 3.5)
        assert isinstance(pt, Ge.Point3d)
        assert pt.x == 1.5
        assert pt.y == 2.5
        assert pt.z == 3.5


    def test_from_coords_without_z(self):
        """Test creating Point3d from x,y coordinates (z defaults to 0)."""
        pt = point_3d(1.5, 2.5)
        assert isinstance(pt, Ge.Point3d)
        assert pt.x == 1.5
        assert pt.y == 2.5
        assert pt.z == 0.0


    def test_from_list(self):
        """Test creating Point3d from a list of coordinates."""
        pt = point_3d([3, 4, 5])
        assert isinstance(pt, Ge.Point3d)
        assert pt.x == 3
        assert pt.y == 4
        assert pt.z == 5


    def test_from_iterable(self):
        """Test creating Point3d from iterable of coordinates."""
        pt = point_3d(iter([5.0, 6.0, 7.0]))
        assert isinstance(pt, Ge.Point3d)
        assert pt.x == 5.0
        assert pt.y == 6.0
        assert pt.z == 7.0


    def test_from_point2d(self):
        """Test creating Point3d from an existing Point2d (z defaults to 0)."""
        pt2d = Ge.Point2d(10, 11)
        pt = point_3d(pt2d)
        assert isinstance(pt, Ge.Point3d)
        assert pt.x == 10
        assert pt.y == 11
        assert pt.z == 0.0


    def test_from_point3d_returns_same(self):
        """Test that passing Point3d."""
        pt3d = Ge.Point3d(13, 14, 15)
        pt = point_3d(pt3d)
        assert isinstance(pt, Ge.Point3d)
        assert pt.x == 13
        assert pt.y == 14
        assert pt.z == 15
        assert pt is not pt3d  # Should return a different instance


    def test_from_point3d_with_extra_args_raises(self):
        """Test that providing extra arguments with Point3d raises ValueError."""
        pt3d = Ge.Point3d(1, 2, 3)
        with pytest.raises(ValueError, match="If x_or_point is a Point3d, y and z should not be provided"):
            point_3d(pt3d, 4)


    def test_from_number_without_y_raises(self):
        """Test that providing only x coordinate raises ValueError."""
        with pytest.raises(ValueError, match="If x_or_point is a number, y must be provided"):
            point_3d(1.0)


    def test_with_not_enough_coords_raises(self):
        """Test that providing insufficient coordinates raises ValueError."""
        with pytest.raises(ValueError, match="Not enough coordinates provided"):
            point_3d([])

        with pytest.raises(ValueError, match="Not enough coordinates provided"):
            point_3d([1])


    def test_with_too_many_coords_raises(self):
        """Test that providing too many coordinates raises ValueError."""
        with pytest.raises(ValueError, match="Too many coordinates provided"):
            point_3d([1, 2, 3, 4])



    def test_from_2d_list(self):
        """Test creating Point3d from 2D list (z defaults to 0)."""
        pt = point_3d([1, 2])
        assert isinstance(pt, Ge.Point3d)
        assert pt.x == 1
        assert pt.y == 2
        assert pt.z == 0.0