//
//  GetRin1Dir.cpp
//  Simulation
//
//  Created by Ju on 10/18/15.
//  Copyright (c) 2015 Ju. All rights reserved.
//

#include "GetRin1Dir.h"
#include <vector>
#include <math.h>
#include <iostream>
using namespace std;
MatrixXd GetRin1Dir(const MatrixXd &RotationAxis, double RotationAngle){
	
    double ax=RotationAxis.row(0)[0];
    double ay=RotationAxis.row(0)[1];
    double az=RotationAxis.row(0)[2];
    double theta = RotationAngle;
    MatrixXd r(3,3);
    r<< cos(theta)+(1-cos(theta))*pow(ax,2) ,(1-cos(theta))*ax*ay-az*sin(theta) ,(1-cos(theta))*ax*az+ay*sin(theta),
        (1-cos(theta))*ax*ay+az*sin(theta) ,cos(theta)+(1-cos(theta))*pow(ay,2) ,(1-cos(theta))*ay*az-ax*sin(theta),
        (1-cos(theta))*ax*az-ay*sin(theta) ,(1-cos(theta))*ay*az+ax*sin(theta) ,cos(theta)+(1-cos(theta))*pow(az,2);
    return r;

}