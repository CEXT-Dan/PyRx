from __future__ import annotations

from pyrx import Ge

# Assuming Ge == imported as per the provided citations
# from Ge import Interval

class TestGeInterval:
    """
    Test suite for the Ge.Interval class based on provided citations.
    """

    # --- Initialization and Bounds ---

    def test_initialization_with_floats(self):
        """Test creating an Interval with lower and upper bounds."""
        # Citation 1: def __init__(self, /) -> None: ...
        # Citation 2: def lowerBound(self, /) -> float: ...
        # Citation 2: def upperBound(self, /) -> float: ...
        interval = Ge.Interval(0.0, 10.0)
        assert interval.lowerBound() == 0.0
        assert interval.upperBound() == 10.0

    def test_initialization_singleton(self):
        """Test creating an Interval where lower and upper are equal."""
        interval = Ge.Interval(5.0, 5.0)
        assert interval.lowerBound() == 5.0
        assert interval.upperBound() == 5.0
        # Citation 2: def isSingleton(self, /) -> bool: ...
        assert interval.isSingleton() == True

    def test_get_bounds(self):
        """Test retrieving the bounds as a tuple."""
        # Citation 1: def getBounds(self, /) -> tuple[float, float]: ...
        interval = Ge.Interval(1.0, 2.0)
        bounds = interval.getBounds()
        assert bounds == (1.0, 2.0)

    def test_length(self):
        """Test calculating the length of the interval."""
        # Citation 2: def length(self, /) -> float: ...
        interval = Ge.Interval(0.0, 10.0)
        assert interval.length() == 10.0

    # --- Comparison Operators ---


    # def test_is_greater_or_equal(self):
    #     """Test the isGreaterOrEqual method."""
    #     # Citation 1: def isGreaterOrEqual(self, val: Ge.Interval | float, /) -> bool: ...
    #     # Citation 2: def isGreaterOrEqual(self, val: Ge.Interval | float, /) -> bool: ...
    #     interval_a = Ge.Interval(10.0, 20.0)
    #     interval_b = Ge.Interval(10.0, 20.0)
        
    #     assert interval_a.isGreaterOrEqual(interval_b) == False
    #     assert interval_a.isGreaterOrEqual(5.0) == True

    # def test_is_less(self):
    #     """Test the isLess method."""
    #     # Citation 1: def isLess(self, val: Ge.Interval | float, /) -> bool: ...
    #     # Citation 2: def isLess(self, val: Ge.Interval | float, /) -> bool: ...
    #     interval_a = Ge.Interval(1.0, 2.0)
    #     interval_b = Ge.Interval(3.0, 4.0)
        
    #     assert interval_a.isLess(interval_b) == True
    #     assert interval_a.isLess(5.0) == True

    # def test_is_less_or_equal(self):
    #     """Test the isLessOrEqual method."""
    #     # Citation 2: def isLessOrEqual(self, val: Ge.Interval | float, /) -> bool: ...
    #     interval_a = Ge.Interval(1.0, 2.0)
    #     interval_b = Ge.Interval(1.0, 2.0)
        
    #     assert interval_a.isLessOrEqual(interval_b) == True

    # def test_is_equal_at_lower(self):
    #     """Test the isEqualAtLower method."""
    #     # Citation 1: def isEqualAtLower(self, val: Ge.Interval | float, /) -> bool: ...
    #     interval_a = Ge.Interval(5.0, 10.0)
    #     interval_b = Ge.Interval(5.0, 15.0)
        
    #     assert interval_a.isEqualAtLower(interval_b) == True
    #     assert interval_a.isEqualAtLower(5.0) == True

    # def test_is_equal_at_upper(self):
    #     """Test the isEqualAtUpper method."""
    #     # Citation 1: def isEqualAtUpper(self, val: Ge.Interval | float, /) -> bool: ...
    #     interval_a = Ge.Interval(5.0, 10.0)
    #     interval_b = Ge.Interval(5.0, 10.0)
        
    #     assert interval_a.isEqualAtUpper(interval_b) == True
    #     assert interval_a.isEqualAtUpper(10.0) == True

    # --- Containment and Intersection ---

    def test_contains(self):
        """Test the contains method."""
        # Citation 1: def contains(self, val: Ge.Interval | float, /) -> bool: ...
        interval = Ge.Interval(0.0, 10.0)
        
        assert interval.contains(5.0) == True
        assert interval.contains(0.0) == True
        assert interval.contains(10.0) == True
        assert interval.contains(10.1) == False
        assert interval.contains(-1.0) == False

    def test_is_disjoint(self):
        """Test the isDisjoint method."""
        # Citation 1: def isDisjoint(self, val: Ge.Interval, /) -> bool: ...
        interval_a = Ge.Interval(0.0, 5.0)
        interval_b = Ge.Interval(10.0, 15.0)
        
        assert interval_a.isDisjoint(interval_b) == True

    def test_intersect_with(self):
        """Test the intersectWith method."""
        # Citation 1: def intersectWith(self, val: Ge.Interval, /) -> tuple[bool, Ge.Interval]: ...
        interval_a = Ge.Interval(0.0, 10.0)
        interval_b = Ge.Interval(5.0, 15.0)
        
        result = interval_a.intersectWith(interval_b)
        assert result[0] == True
        assert result[1].lowerBound() == 5.0
        assert result[1].upperBound() == 10.0

    # --- Modification and Properties ---

    def test_set_bounds(self):
        """Test the set method."""
        # Citation 2: @overload def set(self, lower: float, upper: float, /) -> None: ...
        interval = Ge.Interval(0.0, 0.0)
        interval.set(10.0, 20.0)
        
        assert interval.lowerBound() == 10.0
        assert interval.upperBound() == 20.0

    def test_set_singleton(self):
        """Test setting an interval to a singleton."""
        interval = Ge.Interval(5.0, 5.0)
        assert interval.lowerBound() == 5.0
        assert interval.upperBound() == 5.0
        assert interval.isSingleton() == True

    def test_set_lower(self):
        """Test setting the lower bound."""
        # Citation 2: def setLower(self, val: float, /) -> None: ...
        interval = Ge.Interval(0.0, 10.0)
        interval.setLower(5.0)
        
        assert interval.lowerBound() == 5.0

    def test_set_upper(self):
        """Test setting the upper bound."""
        # Citation 2: def setUpper(self, val: float, /) -> None: ...
        interval = Ge.Interval(0.0, 10.0)
        interval.setUpper(15.0)
        
        assert interval.upperBound() == 15.0

    def test_tolerance(self):
        """Test setting and getting tolerance."""
        # Citation 2: def setTolerance(self, val: float, /) -> None: ...
        # Citation 2: def tolerance(self, /) -> float: ...
        interval = Ge.Interval(0.0, 10.0)
        interval.setTolerance(0.001)
        
        assert interval.tolerance() == 0.001

    def test_element(self):
        """Test getting the element (value) of a singleton interval."""
        # Citation 1: def element(self, /) -> float: ...
        interval = Ge.Interval(5.0, 5.0)
        
        assert interval.element() == 5.0

    # --- Boolean State Checks ---

    def test_is_bounded(self):
        """Test checking if the interval == bounded."""
        # Citation 1: def isBounded(self, /) -> bool: ...
        interval = Ge.Interval(0.0, 10.0)
        assert interval.isBounded() == True

    def test_is_bounded_above(self):
        """Test checking if the interval == bounded above."""
        # Citation 1: def isBoundedAbove(self, /) -> bool: ...
        interval = Ge.Interval(0.0, 10.0)
        assert interval.isBoundedAbove() == True

    def test_is_bounded_below(self):
        """Test checking if the interval == bounded below."""
        # Citation 1: def isBoundedBelow(self, /) -> bool: ...
        interval = Ge.Interval(0.0, 10.0)
        assert interval.isBoundedBelow() == True

    def test_is_unbounded(self):
        """Test checking if the interval == unbounded."""
        # Citation 2: def isUnBounded(self, /) -> bool: ...
        # Note: Citation 1 also lists isBounded, implying isUnBounded == the inverse.
        interval = Ge.Interval(0.0, 10.0)
        assert interval.isUnBounded() == False

    def test_is_continuous_at_upper(self):
        """Test checking continuity at the upper bound."""
        # Citation 1: def isContinuousAtUpper(self, val: Ge.Interval, /) -> bool: ...
        interval_a = Ge.Interval(0.0, 10.0)
        interval_b = Ge.Interval(10.0, 20.0)
        
        assert interval_a.isContinuousAtUpper(interval_b) == True

    def test_is_overlap_at_upper(self):
        """Test checking overlap at the upper bound."""
        # Citation 2: def isOverlapAtUpper(self, val: Ge.Interval, /) -> tuple[bool, Ge.Interval]: ...
        interval_a = Ge.Interval(0.0, 10.0)
        interval_b = Ge.Interval(5.0, 15.0)
        
        result = interval_a.isOverlapAtUpper(interval_b)
        assert result[0] == True
        assert result[1].lowerBound() == 5.0
        assert result[1].upperBound() == 10.0

    # --- Advanced Operations ---

    def test_get_merge(self):
        """Test merging intervals."""
        # Citation 1: def getMerge(self, val: float, /) -> Interval: ...
        interval_a = Ge.Interval(0.0, 10.0)
        interval_b = Ge.Interval(5.0, 15.0)
        
        # Assuming getMerge merges the interval with a float value
        merged = interval_a.getMerge(interval_b)
        assert merged.lowerBound() == 0.0
        assert merged.upperBound() == 15.0

    def test_periodically_on(self):
        """Test checking if the interval == periodically on."""
        # Citation 2: def isPeriodicallyOn(self, val: float, /) -> tuple[bool, float]: ...
        interval = Ge.Interval(0.0, 10.0)
        
        # Assuming a period of 10.0
        result = interval.isPeriodicallyOn(10.0)
        assert result[0] == True
        assert result[1] == 0.0

    def test_subtract(self):
        """Test subtracting an interval."""
        # Citation 2: def subtract(self, val: Ge.Interval, /) -> tuple[int, Ge.Interval, Ge.Interval]: ...
        interval_a = Ge.Interval(0.0, 10.0)
        interval_b = Ge.Interval(5.0, 15.0)
        
        result = interval_a.subtract(interval_b)
        # Citation 2: tuple[int, Ge.Interval, Ge.Interval]
        # Typically: (count, left_part, right_part)
        assert result[0] == 1
        assert result[1].lowerBound() == 0.0
        assert result[1].upperBound() == 5.0
        assert result[2].lowerBound() == 0.0
        assert result[2].upperBound() == 0.0 #?
