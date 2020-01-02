#include <iostream>
#include "power_method.h"
#include <Eigen/Dense>
using Eigen::MatrixXf;
using Eigen::VectorXf;


int main() {

    int num_row = 3;
    int num_col = 4;
    MatrixXf A(num_row,num_col);
    A << 1,2,3,4,5,6,7,8,9,10,11,12;

    // std::cout << "original matrix: "<<std::endl<< A << std::endl;
    // std::cout<< A.block<3,1>(0,0) << std::endl; //output: 1,5,9
    // std::cout<< A.block<3,1>(0,1) << std::endl; //output: 2,6,10

    usv v_d = power_method_with_deflation(A, 0, 0.0000001);

    std::cout<<"U: "<< std::endl << v_d.U << std::endl;
    std::cout<<"S: "<< std::endl << v_d.S << std::endl;
    std::cout<<"V: "<< std::endl << v_d.V << std::endl;
}