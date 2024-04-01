(defun c:testadsload (/)
    (adspyload "M:/Dev/Projects/PyRxGit/PySamples/_doit.py")
)

(defun c:testload (/)
    (pyload "M:/Dev/Projects/PyRxGit/PySamples/_doit.py")
    (pyload "M:/Dev/Projects/PyRxGit/unit tests/UnitTestAll.py")
)

(defun c:testloaded (/)
    (pyloaded)
)

