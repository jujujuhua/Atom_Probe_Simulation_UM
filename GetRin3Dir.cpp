//
//  GetRin3Dir.cpp
//  Simulation
//
//  Created by Ju on 10/18/15.
//  Copyright (c) 2015 Ju. All rights reserved.
//

#include "GetRin3Dir.h"
#include <stdio.h>
#include <utility>
#include <iostream>
#include <vector>
#include <math.h>
#include <iostream>
#include <cmath>
#include <stdio.h>
#include <Eigen/Dense>
using Eigen::MatrixXd;
using namespace::Eigen;

using namespace std;

MatrixXd GetRin3Dir(MatrixXd &InitialVector,MatrixXd &TargetVector ){


    RowVector3d UnitIniVec1= InitialVector.row(0);
    RowVector3d UnitIniVec2= InitialVector.row(1);
    double norm1 = UnitIniVec1.norm();
    double norm2 = UnitIniVec2.norm();
    UnitIniVec1 /= norm1;
    UnitIniVec2 /= norm2;
    



    RowVector3d UnitTarVec1= TargetVector.row(0);
    RowVector3d UnitTarVec2= TargetVector.row(1);
    double norm_t1 = UnitTarVec1.norm();
    double norm_t2 = UnitTarVec1.norm();
    
    UnitTarVec1 /= norm_t1;
    UnitTarVec2 /= norm_t2;
    //find out axes and angles to match the first vector in InitialVector to TargetVector

    cout << "InitialVector: \n";
    cout << InitialVector<<endl<<endl;

    cout <<"TargetVector: \n";
    cout << TargetVector<<endl<<endl;

    cout <<"UnitTarVec1\n";
    cout <<UnitTarVec1<<endl<<endl;

    cout <<"UnitTarVec2\n";
    cout <<UnitTarVec2<<endl<<endl;

    cout <<"UnitIniVec1\n";
    cout <<UnitIniVec1<<endl<<endl;

    cout <<"UnitIniVec2\n";
    cout <<UnitIniVec2<<endl<<endl;


    MatrixXd Axis1 = UnitIniVec1.cross(UnitTarVec1);
    double Theta1=acos(UnitIniVec1.dot(UnitTarVec1));
    
    MatrixXd UnitAxis1 = Axis1;
    
    double norm_Axis1 =Axis1.norm();
    if (norm_Axis1 != 0){
        UnitAxis1 /=norm_Axis1;
    }

    cout <<"Axis1\n";
    cout <<Axis1<<endl<<endl;

    cout<<"UnitAxis1\n";
    cout<<UnitAxis1<<endl<<endl;


    //get the rotation matrix to match the first vector in InitialVector to TargetVector

    MatrixXd R1 = GetRin1Dir(UnitAxis1, Theta1);
    
    cout << "R1\n";
    cout <<R1<<endl<<endl;
    //update UnitIniVec2 after rotation

    RowVector3d UpdatedUnitIniVec2=(R1*UnitIniVec2.transpose()).transpose();
    
    cout <<"UpdatedUnitIniVec2\n";
    cout << UpdatedUnitIniVec2<<endl<<endl;

    cout <<"UnitTarVec2\n";
    cout <<UnitTarVec2<<endl<<endl;
    //Find the axis and angle to match the UpdateUnitIniVec2 to UnitTarVec2
    
    RowVector3d Axis2 = UpdatedUnitIniVec2.cross(UnitTarVec2);
    
    cout <<"Axis2\n";
    cout <<Axis2<<endl<<endl;

    double Theta2 = acos(UpdatedUnitIniVec2.dot(UnitTarVec2));

    MatrixXd UnitAxis2 = Axis2;
    double norm_Axis2 =Axis2.norm();
    if (norm_Axis2 != 0){
        UnitAxis2 /= norm_Axis2;
    }    

    cout <<"UnitAxis2\n";
    cout <<UnitAxis2<<endl<<endl;

    MatrixXd R2 = GetRin1Dir(UnitAxis2,Theta2);

    MatrixXd R = R2*R1;

    cout <<"R2\n";
    cout <<R2<<endl<<endl;

    cout <<"R\n";
    cout <<R<<endl<<endl;

    return R;
};