import pyximport
pyximport.install()


# distutils: language = c++
# distutils: source = power_method.cpp
# cython: language_level = 3
# cython: boundscheck = False
# cython: wraparound = False


import numpy as np 

cdef extern from "power_method.h":

