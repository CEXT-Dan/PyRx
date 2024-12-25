from setuptools import setup

setup(
    name="pyrx",
    version="2.1.4",
    description="Python ObjectArx Wrappers",
    author="PyRx Dev Team",
    author_email="daniel@cadext.com",
    packages=["pyrx"],
    include_package_data=True,
    python_requires=">=3.12.0,<3.13.0",
    package_data={"pyrx": ["*.arx", "*.brx", "*.grx", "*.zrx"]},
    install_requires=["wxPython>=4.2.2", "debugpy>=1.8.0", 'pywin32'],
)
