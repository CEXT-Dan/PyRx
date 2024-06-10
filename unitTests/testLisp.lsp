(defun c:testadsload (/)
    (adspyload "M:/Dev/Projects/PyRxGit/PySamples/_doit.py")
)

(defun c:testload (/)
    (pyload "M:/Dev/Projects/PyRxGit/PySamples/_doit.py")
    (pyload "M:/Dev/Projects/PyRxGit/unittests/UnitTestAll.py")
)

(defun c:testloaded (/)
    (pyloaded)
)

(defun c:testLispInvoke (args)
    args
)

(defun c:LispInvokeSStest()
   (pyrxlispsstest (ssget "X"))
)

(setq PYRXGLOBALVAR 1)
"True"


(defun c:LispRetStr()
   "Hello World"
)

(defun c:LispRetInt()
   42
)

(defun c:LispRetDouble()
   94.1
)

(defun c:LispRetId()
   (namedobjdict)
)

