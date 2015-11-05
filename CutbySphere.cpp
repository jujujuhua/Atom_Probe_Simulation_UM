#include "CutbySphere.h"
#include <Eigen/Dense>
#include <utility>
#include <iostream>
using Eigen::MatrixXd;
using namespace Eigen;

using namespace std;
//function [ PickedAtoms,Unpicked ] = CutbySphere(Atoms, Radius, x0,y0,z0 )

pair<MatrixXd*,MatrixXd*> CutbySphere(MatrixXd &Atoms, double Radius, double x0,double y0,double z0 ){


	//return ;
	VectorXd Dx = Atoms.col(0).array() - x0;

	VectorXd Dy = Atoms.col(1).array() - y0;
	VectorXd Dz = Atoms.col(2).array() - z0;
	//d2space=Dx.^2+Dy.^2+Dz.^2;
	MatrixXd d2space = Dx.cwiseAbs2()+ Dy.cwiseAbs2() + Dz.cwiseAbs2();
	MatrixXd D2space = d2space.array() - Radius*Radius;
	MatrixXd d2plane = Dx.cwiseAbs2() + Dy.cwiseAbs2();
	MatrixXd D2plane = d2plane.array() - Radius*Radius;

	int range=Atoms.rows();
	int j = 0, k = 0;
	//need to improve here
	MatrixXd* PickedAtoms = new MatrixXd(range,Atoms.cols());
	MatrixXd* Unpicked = new MatrixXd(range,Atoms.cols());
	
	for ( int i = 0 ; i < range; i ++){
		//cout<<i<<" "<<Atoms(i,2)<<" "<<" "<<D2space(i,0)<<endl;
		if (Atoms(i,2) > z0 && D2space(i,0) <= 0){
			PickedAtoms->row(j) = Atoms.row(i);
			j++;
		}else if (Atoms(i,2) <= z0 && D2plane(i,0) <= 0){
			PickedAtoms->row(j) = Atoms.row(i);
			j++;
		}else{
			Unpicked->row(k) = Atoms.row(i);
			k++;
		}
	}
	PickedAtoms->conservativeResize(j,Atoms.cols());
	Unpicked->conservativeResize(k,Atoms.cols());
	return pair<MatrixXd*,MatrixXd*> (PickedAtoms,Unpicked);

}