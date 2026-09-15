import wx

from pyrx import Ap, Ed, Gs


@Ap.Command()
def doit() -> None:
    image_path = "C:\\Users\\Dan\\Pictures\\vibe_coding.png"
    viewport_id = Ed.Core.getVar("CVPORT")
    image = wx.Image(image_path)
    if image.IsOk():
        success = Gs.Core.displayImage(viewport_id, 0, 0, image)
        print(f"Image display status: {success}")
