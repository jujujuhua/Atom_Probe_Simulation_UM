//
//  ConvertToCartesianFromSpheric.h
//  Simulation
//
//  Created by Ju on 10/18/15.
//  Copyright (c) 2015 Ju. All rights reserved.
//


#include <stdio.h>
#include <utility>
#include <iostream>
#include <Eigen/Dense>

using Eigen::MatrixXd;
using namespace Eigen;
using namespace std;



RowVector3d ConvertToCartesianFromSpheric(int SphericPos_x, int SphericPos_y);
