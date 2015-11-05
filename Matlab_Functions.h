//
//  Matlab_Functions.h
//  Simulation
//
//  Created by Ju on 10/18/15.
//  Copyright (c) 2015 Ju. All rights reserved.
//

#ifndef __Simulation__Matlab_Functions__
#define __Simulation__Matlab_Functions__
#include <vector>
#include <iostream>
using namespace std;

double norm_d1(vector<double>& candidate);

template<typename T>
void print_2d_matrix(const vector<vector<T>> &u){
    for (int i = 0; i < u.size();i++){
        for(int j = 0; j <u[0].size();j++){
            cout<<u[i][j]<<" ";
        }
        cout<<"\n";
    }
    
};

template<typename T>
vector<T> cross_d1(const vector<T> &u,const vector<T> &v){
    return {u[1]*v[2]-u[2]*v[1],  u[2]*v[0]-u[0]*v[2],  u[0]*v[1]-u[1]*v[0]};
    
};

template<typename T>
vector<vector<T>> matrix_multi(const vector<vector<T>> &u,const  vector<vector<T>> &v){
    int row_u = u.size();
    int col_u = u[0].size();
    int row_v = v.size();
    int col_v = v[0].size();
    if (col_u != row_v){
        cout <<"Matrix Multiplication Impossible!\n";
    }
    vector<vector<T>> result(row_u,vector<T>(col_v,0));
    
    for(int i=0;i<row_u;i++)
    {
        for(int j=0;j<col_v;j++)
        {
            result[i][j]=0;
            for(int k=0;k<row_v;k++)
            {
                result[i][j]=result[i][j]+u[i][k]*v[k][j];
            }
        }
    }
    
    
    return result;
    
};

template<typename T>
double dot_d1(const vector<T> &u,const vector<T> &v){
    T sum = 0.0;
    for ( int i = 0; i < u.size();i++){
        sum += u[i]*v[i];
    }
    return sum;
    
};

#endif /* defined(__Simulation__Matlab_Functions__) */
