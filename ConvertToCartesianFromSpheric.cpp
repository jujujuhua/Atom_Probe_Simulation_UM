//
//  ConvertToCartesianFromSpheric.cpp
//  Simulation
//
//  Created by Ju on 10/18/15.
//  Copyright (c) 2015 Ju. All rights reserved.
//

#include "ConvertToCartesianFromSpheric.h"
#include <Eigen/Dense>
using Eigen::MatrixXd;
using namespace Eigen;
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <utility>

using namespace std;


//function CartesianPos = ConvertToCartesianFromSpheric( SphericPos )

RowVector3d ConvertToCartesianFromSpheric(int SphericPos_x, int SphericPos_y){
    double pi = M_PI;
    double Alpha=SphericPos_x;
    double Beta=SphericPos_y;
    RowVector3d result;
    result << cos((Alpha)/180.0*pi)*cos((Beta)/180.0*pi),sin((Alpha)/180.0*pi)*cos((Beta)/180.0*pi),sin((Beta)/180.0*pi);
    return result;
}
