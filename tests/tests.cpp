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

TEST_CASE("should use power method properly", "[POWER]"){

    REQUIRE(true);
    MatrixXf A_U_TEST(3,3);

    A_U_TEST << 30,70,110,70,174,278,110,278,446;
    std::cout << "test finished" << std::endl;

}