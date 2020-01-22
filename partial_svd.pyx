# distutils: sources = power_method.cpp
# distutils: language = c++
# cython: language_level = 3
# cython: boundscheck = False
# cython: wraparound = False

import numpy as np

cdef extern from "power_method.h":
    struct usv_native:
        double* U
        double* S
        double* V
        int num_eign
        int row
        int col
        

    #void free_svd_result(usv_native* r)
    
    usv_native power_method_with_deflation(double* A, int row, int col,
                                          double threshold, double eigen_acurracy)
    

def compute_svd(double[:,::1] A, double threshold, double eigen_acurracy ):
    
    cdef usv_native res = power_method_with_deflation(&A[0,0], A.shape[0], A.shape[1], threshold, eigen_acurracy)
    
    cdef int row = res.row , num_eign = res.num_eign , col = res.col
    
    U  = np.empty(shape=(num_eign, row), dtype = np.double)
    s  = np.empty(shape=(num_eign), dtype = np.double)
    VT = np.empty(shape=(num_eign,  col), dtype = np.double)
    
    if( num_eign > 0):
        U[:,:] = <double[:num_eign, :row]> res.U
        s[:] = <double[:num_eign]> res.S
        VT[:,:] = <double[:num_eign, :col]> res.V

    return U, s, VT

