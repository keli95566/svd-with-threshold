#include <iostream>
#include <vector>
#include "power_method.h"
#include <Eigen/Dense>
using Eigen::MatrixXf;
using Eigen::VectorXf;


void print_matrix(double* A, int row, int col){

    for(int i = 0; i < row; i++){
        for(int j = 0; j< col; j++){
            std::cout << A[i*col + j] << "  " << std::endl;
        }
        std::cout << "\n" ;
    }
}


void print_result(usv_native res){

    std::cout << "Found " << res.num_eign << " eigen values above threshold" << std::endl;

    print_matrix(res.S, 1, res.num_eign);

    std::cout << "U : "<< std::endl;
    print_matrix(res.U, res.num_eign, res.row);

    std::cout << "V : " << std::endl;
    print_matrix(res.V, res.num_eign, res.col);

}

int main() {

    int num_row = 3;
    int num_col = 5;
    double A[15] = { 1,2,3,4,5,
                     6,7,8,9,10,
                     11,12,13,14,15};

    // std::cout << "original matrix: "<<std::endl<< A << std::endl;
    // std::cout<< A.block<3,1>(0,0) << std::endl; //output: 1,5,9
    // std::cout<< A.block<3,1>(0,1) << std::endl; //output: 2,6,10

    usv_native res = power_method_with_deflation(A, num_row, num_col, 2, 0.00001);
    print_result(res);

// TODO: handle the threshold = 0 case, it won't stop calculation.
// TODO: test the result to see if it combines to the original array


}