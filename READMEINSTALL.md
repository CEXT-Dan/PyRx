Install python (64 bit) python3.12.X with the :exclamation:PATH checkbox:exclamation: set to true.

![Python install](https://github.com/CEXT-Dan/PyRx/blob/main/GitResources/images/pyinstall.png), 

Environment paths should look like this

![Environment](https://github.com/CEXT-Dan/PyRx/blob/main/GitResources/images/env.png)

python -m pip install "pyrx @ git+https://github.com/CEXT-Dan/PyRx.git#subdirectory=pyrx"
python -m pip uninstall "pyrx @ git+https://github.com/CEXT-Dan/PyRx.git#subdirectory=pyrx"

use appload, or the startup suite to load the module, example
appload C:\Users\Dan\AppData\Local\Programs\Python\Python312\Lib\site-packages\pyrx\RxLoaderV25.0.brx
