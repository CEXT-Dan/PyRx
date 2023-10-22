(defun c:testload (/)
    (pyload "M:/Dev/Projects/PyRxGit/PySamples/_doit.py")
)

(defun c:testisloaded (/)
    (ispyloaded "M:/Dev/Projects/PyRxGit/PySamples/_doit.py")
)


(defun c:testloaded (/)
    (pyloaded)
)

