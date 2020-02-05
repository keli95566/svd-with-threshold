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

TEST_CASE("should use power method properly for basic operations", "[POWER]"){


    std::cout << "test finished" << std::endl;

}

TEST_CASE("should halt if threshold is 0", "[EDGE CASE]"){

    REQUIRE(true);
    MatrixXf A_U_TEST(3,3);


}