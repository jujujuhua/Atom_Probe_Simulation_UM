#include "S3_AssignIniVoltage.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <Eigen/Dense>
using namespace std;
using Eigen::MatrixXd;
using namespace Eigen;

void S3_AssignIniVoltage(){
	double x0 = 0;
	double y0 = 0;
	double z0 = 9.5; 	//center of the sphere 10 or 9.5 (moved down 0.5)
	double Radi=8; 		//radius of the tip
	double Distance=2;  //Thickness of Vacuum layer.
	double Voltage=1000;

	string basename="BCC_W_tip_20nm";
	//basename='BCC_W_tip_20nm_011+112_11857+3882';
	string FileNamePoints = basename + ".mat";
	//FileNameSOIatoms=[basename '_SOI_Atom.mat'];
	ifstream infile;
	infile.open(basename);
	double in = 0.0;
	string line;
	vector<string> v;
	int i = 0;
	while(getline(infile,line)){
		v[i] = line;
	}

	MatrixXd Points(v.size(),7);
	MatrixXd VacuumPoints(v.size(),7);
	int j = 0;
	
	
	for(i = 0; i < v.size();i++){
		stringstream ss;
		ss << v[i];
		for(int j = 0; j < 6; j ++){
			ss >> Points(i,j);
		}
		if(Points(i,3) == 0){
			Points(i,6) = Voltage;
			VacuumPoints.row(j) = Points.row(j).array();
		}
	}
	j+=1;
	VacuumPoints.resize(j,VacuumPoints.cols());
	MatrixXd VoltageInVacuum(j,1);
	VoltageInVacuum.fill(0);
	double x = 0, y = 0, z = 0;
	double d2 = 0.0, dmin = 0.0;
	for(i = 0; i < VoltageInVacuum.rows();i++){
		x = VacuumPoints(i,0);
		y = VacuumPoints(i,1);
		z = VacuumPoints(i,2);

		if (z > z0){
			d2 = pow(x0-x,2)+pow(y0-y,2)+pow(z0-z,2);
		}else{
			d2 = pow(x0-x,2)+pow(y0-y,2);
		}
		dmin = pow(d2,0.5)-Radi;

		VoltageInVacuum(i,0) = (Distance-dmin)*Voltage/Distance;
		if(VoltageInVacuum(i,0) < 0){
			VoltageInVacuum(i,0) = 0;
		}

	}	
	
	for( i =0;i<VacuumPoints.rows();i++){
		Points(VacuumPoints(i,5),6) = 1;
	}

//save([basename '_iniVoltageAssigned9.5.mat'],'Points');

}