
#pragma once


struct usv_native {

    double *U;
    double *S;
    double *V;
    int num_eign;
    int row;
    int col;
};


// compute a series of eigne values with a threshold using
// power method and deflation techniques.
usv_native power_method_with_deflation(
        double* A, int row, int col,
        double threshold, double eigen_acurracy);


void free_svd_result(struct usv_native* r);
// compute the eigen value based on the eigen vector and the given matrix
// MatrixXf and VectorXf are based on the eigen library.
