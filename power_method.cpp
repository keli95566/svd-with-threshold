//
// Created by Ke Li on 12/11/19.
//

#include <iostream>
#include <Eigen/Dense>
#include <math.h>
#include <cstdlib>
#include "power_method.h"

using Eigen::MatrixXf;
using Eigen::VectorXf;


// compute the eigen value of from the matrix and the eigen vector
// formula: v*(Av)^T/(v_T*v)
float eigen_value(MatrixXf A, VectorXf v){

    int M_col_size = A.cols();
    VectorXf x(M_col_size);
    x = A*v;
    return v.dot(x);

}
eigen_pair power_method_single_value(MatrixXf M_U, double eigen_acurracy){

    int M_col_size = M_U.cols();

    // start an initial guess
    VectorXf v_0(M_col_size);
    for(int j=0; j< M_col_size; j++){
        v_0(j) = j;
    }

   // float n = std::sqrt(M_col_size);
    VectorXf v(M_col_size);
   // v = v_0/n;
    v = v_0;

    float ev = eigen_value(M_U,v);
    float ev_new;

    VectorXf v_new(M_col_size);
    VectorXf Mv(M_col_size);
    int i = 1;

    while (true)
    {

        Mv = M_U * v;
        v_new = Mv/ Mv.norm();

        ev_new = eigen_value(M_U, v_new);

        if (std::abs(ev_new - ev) < eigen_acurracy){
            break;
        };

        v = v_new;
        ev = ev_new;
        //std::cout<<i <<"th iteration: " <<ev_new << std::endl;
        ++i;
    };

    eigen_pair e;
    e.eigen_vector = v_new;
    e.eigen_value = ev_new;
    return e;
}

usv power_method_with_deflation(MatrixXf M, double threshold, double eigen_acurracy){


// TODO: Further refactor of the code
// TODO: Vectorization of the code

    const int M_col_size = M.cols();
    const int M_row_size = M.rows();

    usv res;
    MatrixXf U(M_row_size, M_row_size);
    MatrixXf V(M_col_size, M_col_size);
    VectorXf S(M_row_size);

    MatrixXf M_T(M_col_size,M_row_size);
    MatrixXf M_U(M_row_size,M_col_size);
    M_T = M.transpose();
    M_U =  M*M_T;


    int i = 1;
    while (true){

        eigen_pair ui = power_method_single_value(M_U,eigen_acurracy);
        float sigma = std::sqrt(ui.eigen_value);

        S(i-1) = sigma;
        U.block(0,i-1,M_row_size,1) = ui.eigen_vector;

        // Compute U from V: ui*sigma = M*vi
        VectorXf vi(M_col_size);
        vi = (1/sigma)*M_T*ui.eigen_vector;
        V.block(i-1,0, 1, M_col_size) = vi.transpose();


        if (sigma < threshold or ui.eigen_value < eigen_acurracy){
            break;
        }
        MatrixXf M_new(M_col_size, M_row_size);
        M_new = M_U - ui.eigen_value*(ui.eigen_vector*ui.eigen_vector.transpose());
        M_U = M_new;
        i++;
    }


    res.U = U;
    res.S = S;
    res.V = V;

    return res;

}

