#include "void S3_AssignIniVoltage.h"
#include <iostream>
using namespace std;

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

	//Points=importdata(FileNamePoints);
	//SOI_Atoms=importdata(FileNameSOIatoms);
}