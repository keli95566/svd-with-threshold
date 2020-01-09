#include <iostream>
#include "power_method.h"
#include <Eigen/Dense>
using Eigen::MatrixXf;
using Eigen::VectorXf;


int main() {

    int num_row = 5;
    int num_col = 3;
    MatrixXf A(num_row,num_col);
    A << 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15;

    // std::cout << "original matrix: "<<std::endl<< A << std::endl;
    // std::cout<< A.block<3,1>(0,0) << std::endl; //output: 1,5,9
    // std::cout<< A.block<3,1>(0,1) << std::endl; //output: 2,6,10

    usv v_d = power_method_with_deflation(A, 2, 0);

// TODO: restrict loop literation in case acurracy is 0
// TODO: test the result to see if it combines to the original array
// TODO: return a value that outputs how many eigen values is found in total.
// TODO:

    std::cout<<"U: "<< std::endl << v_d.U << std::endl;
    std::cout<<"S: "<< std::endl << v_d.S << std::endl;
    std::cout<<"V: "<< std::endl << v_d.V << std::endl;
}