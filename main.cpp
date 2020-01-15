#include <iostream>
#include <vector>
#include "power_method.h"
#include <Eigen/Dense>
using Eigen::MatrixXf;
using Eigen::VectorXf;


void print_vector(std::vector<double> const &input){

    for(int i = 0 ; i < input.size() ; i ++) {
        std::cout << input.at(i) << " ";
    }
    std::cout<< "\n" << "";

}

// TODO: Now printing with strided access, will be slow, find a way to fix it.

// TODO: U needs to be transposed.

void print_matrix(std::vector<std::vector<double>> const &input){
    for (int i = 0; i< input.size() ; i ++ ){
        for (int j = 0 ; j < input.at(i).size(); j++){
            std::cout << input.at(i).at(j)<< ' ';
        }
        std::cout<< "\n" ;
    }
}

void print_result(usv_native res){

    std::cout << "Found " << res.S_n.size() << " eigen values above threshold" << std::endl;
    print_vector(res.S_n);

    std::cout << "U : "<< std::endl;
    print_matrix(res.U_n);

    std::cout << "V : " << std::endl;
    print_matrix(res.V_n);

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

    usv_native res = power_method_with_deflation(A, num_row, num_col, 1, 0);
    print_result(res);

// TODO: handle the threshold = 0 case, it won't stop calculation.
// TODO: test the result to see if it combines to the original array


}