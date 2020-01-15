
#ifndef POWER_H
#define POWER_H
#include <Eigen/Dense>
#include <vector>
using Eigen::MatrixXf;
using Eigen::VectorXf;

// computes dominat eigen value of a n*n matrix M
// MatrixXf is a matrix created using eigen library.
struct eigen_pair{
    VectorXf eigen_vector;
    float eigen_value;
};

struct usv{
    std::vector<VectorXf> U;
    std::vector<double> S;
    std::vector<VectorXf> V;
};

eigen_pair power_method_single_value(MatrixXf M, double eigen_acurracy);

// compute a series of eigne values with a threshold using
// power method and deflation techniques.
usv power_method_with_deflation(MatrixXf M, double threshold = -1, double eigen_acurracy = 0.0001);

// compute the eigen value based on the eigen vector and the given matrix
// MatrixXf and VectorXf are based on the eigen library.

float eigen_value(MatrixXf A, VectorXf v);
#endif  // POWER_H%