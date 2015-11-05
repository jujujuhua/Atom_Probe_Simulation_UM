
#include "S2_FindSOI.h"
#include "ConvertToCartesianFromSpheric.h"
#include "GetRin3Dir.h"
#include <Eigen/Dense>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using Eigen::MatrixXd;
using namespace Eigen;
using namespace std;



void S2_FindSOI(){
	string basename = "BCC_W_tip_20nm_011+112_11857+3882";
	string Filename1 = basename + ".txt";
	string Filename2 = basename + "_DT_info.txt";

	int n = 1;

	int pt_size_r = 0 , DTlist_size_r = 0;
	int pt_size_c = 0 , DTlist_size_c = 0;

	//row*6
	fstream pt_file;
	pt_file.open(Filename1);
	
	//row * 4
	fstream dt_file;
	dt_file.open(Filename2);

	if ( !pt_file.is_open()){
		cerr << "Open "<<Filename1 <<" failed\n";
		exit(0);
	}else{
		pt_file >> pt_size_r >> pt_size_c;
	}

	if ( !dt_file.is_open()){
		cerr << "Open "<<Filename2 <<" failed\n";
		exit(0);
	}else{
		dt_file >> DTlist_size_r >>DTlist_size_c ;
	}


	MatrixXd DTlist(DTlist_size_r,DTlist_size_c);
	//load DTList
	double temp  = 0.0;
	for (int i = 0 ; i < DTlist_size_r; i ++){
		for ( int j = 0; j < DTlist_size_c;j++){
		dt_file >> temp;
		DTlist(i,j) = temp;
		}
	}

	for (int i = 0 ; i < DTlist_size_r; i ++){
		RowVector3d TetrahedronIndices = DTlist.row(i);
	}








}