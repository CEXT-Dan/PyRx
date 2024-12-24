Install python (64 bit) python3.12.X with the :exclamation:PATH checkbox:exclamation: set to true.

![Python install](https://github.com/CEXT-Dan/PyRx/blob/main/GitResources/images/pyinstall.png), 

Environment paths should look like this

![Environment](https://github.com/CEXT-Dan/PyRx/blob/main/GitResources/images/env.png)


<br>to install from a tag,where v2.1.2 is the target tag<br>
python -m pip install "pyrx @ git+https://github.com/CEXT-Dan/PyRx.git@v2.1.2"<br>

<br>to install from the trunk<br>
python -m pip install "pyrx @ git+https://github.com/CEXT-Dan/PyRx.git"<br>

<br>uninstall<br>
python -m pip uninstall pyrx<br>
<br>
use appload, or the startup suite to load the module, example<br>
appload C:\Users\Dan\AppData\Local\Programs\Python\Python312\Lib\site-packages\pyrx\RxLoaderV25.0.brx
