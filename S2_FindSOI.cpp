
#include "S2_FindSOI.h"
#include "ConvertToCartesianFromSpheric.h"
#include "GetRin3Dir.h"
#include <Eigen/Dense>
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
using Eigen::MatrixXd;
using namespace Eigen;
using namespace std;



void S2_FindSOI(){
	string basename = "BCC_W_tip_20nm_011+112_11857+3882";
	string Filename1 = basename + ".txt";
	string Filename2 = basename + "_DT_info.txt";


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

	return ;

	MatrixXd Points(pt_size_r,pt_size_c);
	//load DTList
	double temp  = 0.0;
	for (int i = 0 ; i < pt_size_r; i ++){
		for ( int j = 0; j < pt_size_c;j++){
		pt_file >> temp;
		Points(i,j) = temp;
		}
	}

	MatrixXd DTlist(DTlist_size_r,DTlist_size_c);
	//load DTList
	
	for (int i = 0 ; i < DTlist_size_r; i ++){
		for ( int j = 0; j < DTlist_size_c;j++){
		dt_file >> temp;
		DTlist(i,j) = temp;
		}
	}

	int n = 0;
	int sa = 0, sv = 0;
	int row_in = 0;
	VectorXd SOIindices(Points.rows());
	MatrixXd SOI(Points.rows(),Points.cols());
	MatrixXd SOI_Atom(Points.rows(),Points.cols());
	MatrixXd SOI_Vacuum(Points.rows(),Points.cols());
	unordered_map<double,bool> un_soi;
	for (int i = 0 ; i < DTlist_size_r; i ++){
		RowVectorXd TetrahedronIndices = DTlist.row(i);
		double sum = 0.0;
		for (int j = 0; j <4; j ++){
			sum += Points(TetrahedronIndices(0,j),3);	
		}
		if (sum < 40.0 && sum > 0.0 ){
			for (int j = 0; j <4; j ++){
				row_in = TetrahedronIndices(0,j);
				if (un_soi.find(row_in) == un_soi.end()){
					SOIindices(n,0) = row_in;
					un_soi[row_in] = true;
					
					SOI.row(n).array() = Points.row(row_in);
					if (SOI(n,3) != 0){
						SOI_Atom.row(sa).array() = SOI.row(n);
					}else{
						SOI_Vacuum.row(sv).array() = SOI.row(n);
					}
					n++;
				}
			}
		}
	}
	//SOIindices.conservativeResize(n);
	//SOI.conservativeResize(n);
	//SOI_Atom.conservativeResize(sa,1);
	//SOI_Vacuum.conservativeResize(sv);







}