from pyrx_imp import Ap

#WatchWinMsg
print("command = startWatch")
print("command = endWatch")

WM_MOUSEMOVE = 512

#messageId, hwnd, lParam, wParam, pt.x, pt.y,time));
def winMessage(msg):
        if msg[0] == WM_MOUSEMOVE:
            print(msg[4],msg[5])
            

def PyRxCmd_startWatch():
    try:
        Ap.Application.registerWatchWinMsg(winMessage)
    except Exception as err:
        print(err)
        
def PyRxCmd_endWatch():
    try:
        Ap.Application.removeWatchWinMsg(winMessage)
    except Exception as err:
        print(err)


