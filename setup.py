from distutils.core import setup, Extension
from Cython.Build import cythonize
import numpy


setup(
    name="partial_svd",
    ext_modules=cythonize("partial_svd.pyx",
                          include_path=[
                              numpy.get_include(),
                              "/usr/local/include"]),
)
