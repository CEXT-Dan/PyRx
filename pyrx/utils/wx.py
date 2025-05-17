from wx.lib.mixins.inspection import InspectionTool

from pyrx import Ap


def show_inspection_frame():
    InspectionTool().Show()


def set_top_window_title(title: str):
    Ap.Application.wxApp().TopWindow.SetTitle(title)
