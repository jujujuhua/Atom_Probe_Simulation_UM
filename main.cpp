//
//  main.cpp
//  Simulation
//
//  Created by Ju on 10/15/15.
//  Copyright (c) 2015 Ju. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <fstream>
#include <iostream>
#include <Eigen/Dense>
using Eigen::MatrixXd;
using namespace Eigen;
#include <cmath>
#include "BuildFCC.h"
#include "GetRin3Dir.h"
#include "S1_BuildSimulationTipArea.h"
int main(int argc, const char * argv[]) {
    //CartesianPos* vec1 = ConvertToCartesianFromSpheric(make_pair<int,int>(118,57));
    //CartesianPos* vec2 = ConvertToCartesianFromSpheric(make_pair<int,int>(38,82));
    

  MatrixXd TargetVector(2,3);
  TargetVector(0,0) = -0.2557;
  TargetVector(0,1) = 0.4809;
  TargetVector(0,2) = 0.8387;
  TargetVector(1,0) = 0.1097;
  TargetVector(1,1) = 0.0857;
  TargetVector(1,2) = 0.9903;

  MatrixXd InitialVector(4,4);
  InitialVector(0,0) = 0;
  InitialVector(0,1) = 1;
  InitialVector(0,2) = 1;
  InitialVector(1,0) = 1;
  InitialVector(1,1) = 1;
  InitialVector(1,2) = 2;

  //GetRin3Dir(InitialVector,TargetVector);
  ifstream infile;
  infile.open("input.txt");
  int r = 0 ,c = 0;
  infile >> r >> c;
  double temp = 0;
  cout << r <<" "<<c<<endl;
  MatrixXd t(r,c);
  for (int i = 0 ; i < r; i ++){
    for ( int  j = 0 ; j < c; j++){
    infile >> temp;
    cout << temp<<endl;
    t(i,j) = temp ;
  }
  }
  cout << t<<endl;
  return 0;
  }
