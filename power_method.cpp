//
// Created by Ke Li on 12/11/19.
//

#include <iostream>
#include <Eigen/Dense>
#include <math.h>
#include <cstdlib>
#include <vector>
#include "power_method.h"

using Eigen::MatrixXf;
using Eigen::VectorXf;

struct eigen_pair{
    VectorXf eigen_vector;
    float eigen_value;
};

struct usv{
    std::vector<VectorXf> U;
    std::vector<double> S;
    std::vector<VectorXf> V;
};

void free_svd_result(usv_native* r){

    free(const_cast<double *>(r->U));
    free(const_cast<double *>(r->S));
    free(const_cast<double *>(r->V));
    free( &r->num_eign);
    free( &r->row);
    free( &r->col);
}

usv_native* eigne_to_native(usv const &eigen_mat, int row, int col){

    // TODO: add a free memory function
    int num_eigen = eigen_mat.S.size();
    double* u = (double*)malloc(row*num_eigen* sizeof(double));
    double* v = (double*)malloc(num_eigen*col* sizeof(double));
    double* s = (double*)malloc(num_eigen* sizeof(double));


    for(int i = 0; i< num_eigen; i++){

        s[i] = eigen_mat.S.at(i);
    }

    for(int i =0; i < num_eigen; i++){
        for(int j=0; j< row; j++){
            u[i*num_eigen + j] = eigen_mat.U.at(i)(j);
        }
    }

    for(int i = 0; i < num_eigen; i ++) {
        for(int j = 0; j< col; j++) {

            v[i*col +j] = eigen_mat.V.at(i)(j);
        }
    }


    // res.U = u;
    // res.S = s;
    // res.V = v;
    // res.num_eign = num_eigen;
    // res.row = row;
    // res.col = col;


    return new usv_native = {u,s,v, num_eigen, row, col};

}

MatrixXf native_to_eigen_mat(double* A, int row, int col){

    MatrixXf A_e(row, col);
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            A_e(i, j) = A[i*col + j] ;
        }
    }

    return A_e;
}

// compute the eigen value of from the matrix and the eigen vector
// formula: v*(Av)^T/(v_T*v)
float compute_eigen_value(MatrixXf A, VectorXf v){

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

    float ev = compute_eigen_value(M_U,v);
    float ev_new;

    VectorXf v_new(M_col_size);
    VectorXf Mv(M_col_size);
    int i = 1;

    while (true)
    {



        Mv = M_U * v;
        v_new = Mv/ Mv.norm();

        ev_new = compute_eigen_value(M_U, v_new);

        if (std::abs(ev_new - ev) < eigen_acurracy || i > 999 ){
            break;
        };

        v = v_new;
        ev = ev_new;
        ++i;
    };

    eigen_pair e;
    e.eigen_vector = v_new;
    e.eigen_value = ev_new;
    return e;
}

usv_native* power_method_with_deflation(double* A, int row, int col, double threshold, double eigen_acurracy){


    MatrixXf M = native_to_eigen_mat(A, row, col);

    // TODO: refractor
    const int M_col_size = M.cols();
    const int M_row_size = M.rows();

    //std::cout << M_col_size << std::endl;
    //std::cout<< M_row_size << std::endl;
    //std::cout << M << std::endl;

    usv res;
    std::vector<VectorXf> res_u;
    std::vector<double> res_s;
    std::vector<VectorXf> res_v;

    MatrixXf M_T(M_col_size,M_row_size);
    MatrixXf M_U(M_row_size,M_col_size);
    M_T = M.transpose();
    M_U =  M*M_T;


    int i = 1;
    while (true){

        eigen_pair ui = power_method_single_value(M_U,eigen_acurracy);
        float sigma = std::sqrt(ui.eigen_value);

        if (sigma > threshold) {

            res_s.push_back(sigma);
            res_u.push_back(ui.eigen_vector);

            // Compute U from V: ui*sigma = M*vi
            VectorXf vi(M_col_size);
            vi = (1/sigma)*M_T*ui.eigen_vector;
            res_v.push_back(vi.transpose());

        }


        if (sigma < threshold or ui.eigen_value < eigen_acurracy){
            break;
        }
        MatrixXf M_new(M_col_size, M_row_size);
        M_new = M_U - ui.eigen_value*(ui.eigen_vector*ui.eigen_vector.transpose());
        M_U = M_new;
        i++;
    }


    res.U = res_u;
    res.S = res_s;
    res.V = res_v;

    usv_native* res_f = eigne_to_native(res, row, col);
    return res_f;

}


