//
//  GetRin3Dir.h
//  Simulation
//
//  Created by Ju on 10/18/15.
//  Copyright (c) 2015 Ju. All rights reserved.
//

#ifndef __Simulation__GetRin3Dir__
#define __Simulation__GetRin3Dir__

#include "GetRin1Dir.h"
#include <stdio.h>
#include <vector>
#include <Eigen/Dense>
using Eigen::MatrixXd; 
using namespace std;
//function [ R ] = GetRin3Dir( InitialVector, TargetVector )


MatrixXd  GetRin3Dir(MatrixXd &InitialVector,MatrixXd &TargetVector );


#endif /* defined(__Simulation__GetRin3Dir__) */
