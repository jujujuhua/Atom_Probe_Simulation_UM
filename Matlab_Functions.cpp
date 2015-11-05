//
//  Matlab_Functions.cpp
//  Simulation
//
//  Created by Ju on 10/18/15.
//  Copyright (c) 2015 Ju. All rights reserved.
//

#include "Matlab_Functions.h"
#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;
double norm_d1 (vector<double>& candidate){
    double sum = 0;
    for (int i = 0; i < candidate.size();i++){
        sum += candidate[i]*candidate[i];
    }
    return sqrt(sum);
}


