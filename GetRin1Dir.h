//
//  GetRin1Dir.h
//  Simulation
//
//  Created by Ju on 10/18/15.
//  Copyright (c) 2015 Ju. All rights reserved.
//

#ifndef __Simulation__GetRin1Dir__
#define __Simulation__GetRin1Dir__

#include <stdio.h>
#include <vector>
#include <Eigen/Dense>
using Eigen::MatrixXd;
using namespace std;

MatrixXd GetRin1Dir(const MatrixXd &RotationAxis, double RotationAngle);
#endif /* defined(__Simulation__GetRin1Dir__) */
