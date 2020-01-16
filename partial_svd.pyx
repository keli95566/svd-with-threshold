import pyximport
pyximport.install()

import numpy as np



from libcpp.vector cimport vector


cdef extern from "power_method.h":
    struct usv_native:
        double* U
        double* S
        double* V
        int num_eign
        int row
        int col
        

    void free_svd_result(usv_native* r)
    
    usv_native power_method_with_deflation(double* A, int row, int col, 
                                          double threshold, double eigen_acurracy)
    

def partial_svd(double[:,::1] A, double threshold = -1, double eigen_acurracy = 0.0001 ):
    
    print(A)
    # cdef usv_native res = power_method_with_deflation(&A[0,0], A.shape[0], A.shape[1], treshold, eigen_accuracy)
    
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

