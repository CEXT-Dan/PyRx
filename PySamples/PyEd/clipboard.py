import traceback
from pyrx import Ap, Db, Ed, Ge
import win32clipboard
import win32con

def set_clipboard_text(text):
    win32clipboard.OpenClipboard(0)
    try:
        win32clipboard.EmptyClipboard()
        win32clipboard.SetClipboardText(text, win32con.CF_UNICODETEXT)
    finally:
        win32clipboard.CloseClipboard()

def get_clipboard_text():
    text = ""
    win32clipboard.OpenClipboard(0)
    try:
        if win32clipboard.IsClipboardFormatAvailable(win32con.CF_UNICODETEXT):
            text = win32clipboard.GetClipboardData(win32con.CF_UNICODETEXT)
    finally:
        win32clipboard.CloseClipboard()
    return text


@Ap.Command()
def doit1():
    try:
        set_clipboard_text("Hello from PyRx and AutoCAD!")
        # Writes directly to the AutoCAD Command Line history
        print("\n--> Text successfully copied to clipboard.\n")
    except Exception as e:
        traceback.print_exc()


@Ap.Command()
def doit2():
    try:
        text = get_clipboard_text()
        print(f"\n--> Clipboard content: {text}\n")
    except Exception as e:
        traceback.print_exc()
