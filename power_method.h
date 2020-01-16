
#ifndef POWER_H
#define POWER_H
#include <Eigen/Dense>
#include <vector>
using Eigen::MatrixXf;
using Eigen::VectorXf;


struct usv_native{

    double *U;
    double *S;
    double *V;
    int num_eign;
    int row;
    int col;
};


// compute a series of eigne values with a threshold using
// power method and deflation techniques.
usv_native power_method_with_deflation(double* A, int row, int col, double threshold = -1, double eigen_acurracy = 0.0001);


void free_svd_result(usv_native* r);
// compute the eigen value based on the eigen vector and the given matrix
// MatrixXf and VectorXf are based on the eigen library.
#endif