from unittest.mock import patch

import pytest

from pyrx.utils.decorators import pass_working_db


class Test_pass_working_db:
    def test_no_db_param_raise_RuntimeError(self):
        with pytest.raises(RuntimeError, match="Function must have a 'db' parameter"):

            @pass_working_db
            def func():
                pass

    def test_db_param_not_positional_or_keyword_raise_RuntimeError(self):
        with pytest.raises(
            RuntimeError, match="Function 'db' parameter must be positional or keyword"
        ):

            @pass_working_db
            def func1(db, /):
                pass

        with pytest.raises(
            RuntimeError, match="Function 'db' parameter must be positional or keyword"
        ):

            @pass_working_db
            def func2(*db):
                pass

        with pytest.raises(
            RuntimeError, match="Function 'db' parameter must be positional or keyword"
        ):

            @pass_working_db
            def func3(**db):
                pass

    def test_db_as_keyword_argument(self):
        """Test that the decorator correctly passes the working database as a keyword argument."""
        mock_db = object()

        @pass_working_db
        def func(*, other, db = ...):
            return other, db

        with patch("pyrx.Db.workingDb", return_value=mock_db):
            result = func(other=1)
            assert result == (1, mock_db)

    def test_db_as_positional_argument(self):
        """Test that the decorator correctly passes the working database as a positional argument."""
        mock_db = object()

        @pass_working_db
        def func(b, db, a):
            return b, db, a

        with patch("pyrx.Db.workingDb", return_value=mock_db):
            result = func(1, None, 2)
            assert result == (1, mock_db, 2)

    def test_existing_db_not_overwritten(self):
        """Test that the decorator does not overwrite an existing 'db' argument."""
        mock_db = object()

        @pass_working_db
        def func1(db):
            return db

        result = func1(mock_db)
        assert result == mock_db

        result = func1(db=mock_db)
        assert result == mock_db

        @pass_working_db
        def func2(*, db):
            return db

        result = func2(db=mock_db)
        assert result == mock_db

    def test_db_as_none_replaced_with_working_db(self):
        """Test that if 'db' is explicitly passed as None, it is replaced with the working database."""
        mock_db = object()

        @pass_working_db
        def func(db):
            return db

        with patch("pyrx.Db.workingDb", return_value=mock_db):
            result = func(db=None)
            assert result == mock_db

    def test_db_as_keyword_only_argument(self):
        """Test that the decorator works with 'db' as a keyword-only argument."""
        mock_db = object()

        @pass_working_db
        def func(*, db):
            return db

        with patch("pyrx.Db.workingDb", return_value=mock_db):
            result = func(db=None)
            assert result == mock_db
