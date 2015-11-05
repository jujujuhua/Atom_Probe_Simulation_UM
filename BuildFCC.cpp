//
//  BuildFCC.cpp
//  Simulation
//
//  Created by Ju on 10/15/15.
//  Copyright (c) 2015 Ju. All rights reserved.
//

#include "BuildFCC.h"
using namespace std;
#include <vector>
#include <math.h>

#include <iostream>
#include <stdio.h>

vector< vector<double>>* BuildFCC(int  CubicSize, int LatticeSpacing, int x0,int  y0, int z0 ){
    
    int g_size2 = CubicSize/LatticeSpacing +1;
    int nOfsites = floor (CubicSize*2/LatticeSpacing)+1;
    int g_size3 = nOfsites;
    double diff = LatticeSpacing*1.0/2;
    cout << g_size2 <<" "<<nOfsites<<" "<<diff<<" "<<g_size2*g_size3<<endl;
    int total = g_size2*g_size3*g_size3;
    int total2 = g_size2*g_size3;
    cout <<total<<endl;
    vector<vector<double>> *result = new vector<vector<double>>;
    result->resize(total , vector<double>( 3 , 0 ) );
    
    for ( int i = 0 ; i < total;i++){
        (*result)[i][1] = (i % total2)/g_size2 * diff;
        (*result)[i][2] = (i / total2) * diff;
        int d_size = 3* g_size2;
        int out_loc = (i*1.0/d_size);
        int in_loc = ((i%(3*g_size2))*1.0/g_size2);
        int r = (-CubicSize / 2 + LatticeSpacing * (i % nOfsites));
        
        cout <<r<<" "<<(*result)[i][1] <<" "<<(*result)[i][2]<<endl;
    
    }
    
    
    return nullptr;
};