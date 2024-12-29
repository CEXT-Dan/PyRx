from setuptools import setup

def read_text(file_name: str):
    with open(file_name, "r") as fh:
        return fh.read()
setup(
    name="cad-pyrx",
    version="2.1.7",
    description="Python API for CAD",
    author="PyRx Dev Team",
    author_email="daniel@cadext.com",
    license="LGPLV3",
    url="https://github.com/CEXT-Dan/PyRx",
    packages=["pyrx"],
    python_requires=">=3.12.0,<3.13.0",
    include_package_data=True,
    package_data={"pyrx": ["*.arx", "*.brx", "*.grx", "*.zrx"]},
    install_requires=["wxPython>=4.2.2", "debugpy>=1.8.0", "pywin32"],
    long_description = read_text("CADPyRx.md"),
    long_description_content_type="text/markdown",
    keywords=[
        "AutoCAD",
        "BricsCAD",
        "GStarCAD",
        "ZwCAD",
        "CAD",
        "PYTHON",
        "Wrappers",
        "ARX",
    ],
    classifiers=[
        "Development Status :: 5 - Production/Stable",
        "License :: OSI Approved :: GNU Lesser General Public License v3 (LGPLv3)",
        "Programming Language :: Python :: 3.12",
        'Topic :: Software Development :: Libraries :: Python Modules',
    ],
)
