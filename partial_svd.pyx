import numpy as np

#distutils: sources = power_method.cpp
#distutils: language = c++
#cython: language_level = 3
#cython: wraparound = False
#cython: boundscheck = False


cdef extern from "power_method.h":
    struct usv_native:
        double* U
        double* S
        double* V
        int num_eign
        int row
        int col
        

    #void free_svd_result(struct usv_native* r)
    
    usv_native* power_method_with_deflation(double* A, int row, int col, 
                                          double threshold, double eigen_acurracy)
    

def partial_svd(double[:,::1] A, double threshold, double eigen_acurracy ):
    

    cdef usv_native * res = power_method_with_deflation(&A[0,0], A.shape[0], A.shape[1], threshold, eigen_acurracy)
    
    # cdef int row = res[0].row , num_eigen = res[0].num_eigen , col = res[0].col
    
    # U  = np.empty(shape=(num_eigen, row), dtype = np.double)
    # s  = np.empty(shape=(num_eigen), dtype = np.double)
    # VT = np.empty(shape=(num_eigen,  col), dtype = np.double)
    
    # if(k > 0):
    #     U[:,:] = <double[:num_eigen, :row]> res[0].U_n
    #     s[:] = <double[:num_eigen]> res[0].S_n
    #     VT[:,:] = <double[:num_eigen, :col]> res[0].V_n
    a = np.arange(1,16).reshape(3,5)
    return a, a, a

