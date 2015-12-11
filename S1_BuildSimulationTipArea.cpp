//
//  S1_BuildSimulationTipArea.cpp
//  Simulation
//
//  Created by Ju on 10/18/15.
//  Copyright (c) 2015 Ju. All rights reserved.
//

#include "S1_BuildSimulationTipArea.h"
#include "ConvertToCartesianFromSpheric.h"
#include "GetRin3Dir.h"
#include "BCC.h"
#include <Eigen/Dense>
#include "CutbySphere.h"

using Eigen::MatrixXd;
using namespace Eigen;
using namespace std;


void S1_BuildSimulationTipArea(){

	MatrixXd BuildBcc=BuildBCC(28,0.2741,0,0,9);
    RowVector3d vec1 =   ConvertToCartesianFromSpheric(118,57);
    RowVector3d vec2 = ConvertToCartesianFromSpheric(38,82);

	MatrixXd InitialVector(2,3);
	InitialVector(0,0) = 0;
	InitialVector(0,1) = 1;
	InitialVector(0,2) = 1;
	InitialVector(1,0) = 1;
	InitialVector(1,1) = 1;
	InitialVector(1,2) = 2;
    MatrixXd TargetVector(2,3);
	TargetVector << vec1,vec2;
   	MatrixXd R=GetRin3Dir(InitialVector,TargetVector);

   	MatrixXd temp_bcc = BuildBCC(28,0.2741,0,0,9);
    temp_bcc = (R*temp_bcc.transpose()).transpose();
    MatrixXd bcc(temp_bcc.rows(),3);
    int bcc_rows = 0;
    int bcc_size = 0;
    for (; bcc_rows < temp_bcc.rows();bcc_rows++){
        if ( temp_bcc(bcc_rows,2) >= 0){
            bcc.row(bcc_size++) = temp_bcc.row(bcc_rows);
        }
    }
    MatrixXd* Vacuum= (CutbySphere(bcc,10,0,0,10)).first;
    pair<MatrixXd*,MatrixXd*> result = CutbySphere(*Vacuum,8,0,0,10);
    MatrixXd* Materi = result.first;
    Vacuum = result.second;

    Vacuum->conservativeResize(Vacuum->rows(),5);
    Vacuum->col(3).fill(0);
    Vacuum->col(4).fill(1);
    Materi->conservativeResize(Materi->rows(),5);
    Materi->col(3).fill(10);
    Materi->col(4).fill(1000000);

    
    MatrixXd Points(Materi->rows()+ Vacuum->rows(), 6);

    Points.topLeftCorner(Materi->rows(),Materi->cols()) = Materi->leftCols(Materi->cols());
    Points.bottomLeftCorner(Vacuum->rows(),Vacuum->cols()) = Vacuum->leftCols(Vacuum->cols());
    
    for ( int i = 1; i < Points.rows()+1;i++){
        Points(i-1,5) = i;
    }    

    MatrixXd X = Points.leftCols(3);//  (Points.rows(),3);
    for(int i = 0; i < X.rows();i++){

        for(int j = 0 ; j < X.cols(); j++){
            cout << X(i,j)<<" ";
        }
        cout << endl;
    }

   	//DT=delaunayn(X);
    //[V,C] = voronoin(X);
}