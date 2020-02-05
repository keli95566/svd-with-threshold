from distutils.core import setup, Extension
from Cython.Build import cythonize


setup(
    name="tSVD",
    version=" 0.1 ",
    ext_modules=cythonize(["cylib/tSVD.pyx"]),
)
