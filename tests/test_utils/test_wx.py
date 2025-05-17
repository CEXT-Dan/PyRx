import re

import pytest
import wx

from pyrx.utils.wx import set_top_window_title

TITLE_PATTERN = re.compile(r"(.*) - \[[^\[\]]+\]")


@pytest.fixture
def setup_test_set_top_window_title():
    window = wx.GetApp().TopWindow
    full_title = window.Title
    m = TITLE_PATTERN.match(full_title)
    assert m is not None, f"Window title does not match expected pattern: {full_title}"
    title = m.group(1)
    yield
    window.Title = title


def test_set_top_window_title(setup_test_set_top_window_title):
    test_title = "Test Title"
    set_top_window_title(test_title)
    # host automatically adds the name of the current document
    full_title = wx.GetApp().TopWindow.Title
    m = TITLE_PATTERN.match(full_title)
    assert m is not None, f"Window title does not match expected pattern: {full_title}"
    assert m.group(1) == test_title, f"Window title does not match expected title: {full_title}"
