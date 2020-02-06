//
// Created by Ke Li on 12/11/19.
//

#include "catch.h"
#include "../cylib/power_method.h"
#include <Eigen/Dense>
#include <vector>
#include <math.h>
#include <iostream>

using Eigen::MatrixXf;
using Eigen::VectorXf;

TEST_CASE("should recombine to the original matrix", "[POWER]"){

    int r, c = 3,3;
    double A[9] = {1,2,3,4,5,6,7,8,9};
    usv_native res = power_method_with_deflation(A, 3, 3 , 0.001, 0.0001);


}

TEST_CASE("should halt if threshold is 0", "[EDGE CASE]"){

    REQUIRE(true);
    MatrixXf A_U_TEST(3,3);


}