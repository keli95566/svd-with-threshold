from setuptools import setup
from Cython.Build import cythonize

eigen_path = ['/usr/local/include/eigen3']

setup(
    name="tSVD",
    version=" 0.1 ",
    ext_modules=cythonize("cylib/tSVD.pyx",aliases= {"EIGEN_PATH": eigen_path}),
)

## TODO: change the imports in jupyer notebook