import traceback
from pyrx import Ap, Db, Ed, Ge, Rx
import os
import wx


# (setq ufiles (dos_getfilem "Select Drawings" "c:\\drawings\\" "Drawing Files (*.DWG)|*.DWG"))
# (setq pyfiles (py_getfilem "Select Drawings" "c:\\drawings\\" "Drawing Files (*.DWG)|*.DWG"))
  
@Ap.LispFunction()
def py_getfilem(args):
    try:
        if not args or len(args) < 3:
            print("\nError: py_getfilem requires 3 arguments: title, path, filter")
            return None

        title = str(args[0][1])
        default_dir = str(args[1][1])
        wildcard = str(args[2][1])
        
        if wildcard.endswith("||"):
            wildcard = wildcard[:-2]

        wxapp: wx.App = wx.GetApp()
        wxwin = wxapp.GetTopWindow()
        result_lisp_list = None
        
        with wx.FileDialog(wxwin, message=title, defaultDir=default_dir, 
                           wildcard=wildcard, style=wx.FD_OPEN | wx.FD_MULTIPLE) as fileDialog:

            if fileDialog.ShowModal() == wx.ID_OK:
                directory = fileDialog.GetDirectory()
                filenames = fileDialog.GetFilenames()
                
                if not directory.endswith(os.sep):
                    directory += os.sep
                clean_filenames = [os.path.basename(f) for f in filenames]
                clean_filenames.sort()
                
                out_list = []
                out_list.append((Rx.LispType.kText, directory))
                for fname in clean_filenames:
                    out_list.append((Rx.LispType.kText, fname))
                    
                result_lisp_list = out_list

        return result_lisp_list

    except Exception as e:
        print(f"\nPyRx Error: {traceback.format_exc()}")
        return None
