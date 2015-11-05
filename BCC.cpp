#include <vector>
#include <iostream>
#include <getopt.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <fstream>
#include <inttypes.h>

#include <Eigen/Dense>
using Eigen::MatrixXd;
using namespace Eigen;
using namespace std;

ofstream myFile;
string minus_binary;
string float_binary;

void ConvertToBinary_plus(int n)
{
    if (n / 2 != 0) 
    {
        ConvertToBinary_plus(n / 2);
    }
    myFile << n % 2;
}

void ConvertToBinary_minus(int n)
{
    if (n / 2 != 0)
    {
        ConvertToBinary_minus(n / 2);
    }
    int temp = n % 2;
    minus_binary += to_string(temp);
}

void floatToBinary(float f, string& str)
{
    union { float f; uint32_t i; } u;
    u.f = f;
    str.clear();

    for (int i = 0; i < 32; i++)
    {
        if (u.i % 2)  str.push_back('1');
        else str.push_back('0');
        u.i >>= 1;
    }

    string temp(str.rbegin(), str.rend());
    str = temp;
}


MatrixXd BuildBCC(double CubicSize,double LatticeSpacing,double x_0,double y_0,double z_0)
{
    struct option long_option[] =
    {
        {"help", no_argument, NULL, 'h'}
    };

    string mode;
    int opt = 0;
    int index = 0;
    mode = "t";
    // exam the mode
    if (mode == "b")
    {
        myFile.open("data.bin", ios::out | ios::binary);
    }
    // Get the number of sites & number of layers
    int nOfsites = floor(CubicSize/LatticeSpacing) + 1;
    int nOflayers = floor(CubicSize * 2 / LatticeSpacing);
    int nOfatoms_per_layer = nOfsites * nOfsites;
    int nOfatoms = nOfsites * nOfsites * (nOflayers + 1);

    //nOfatoms = 10000;

    int const height = nOfatoms;
    int const width = 3;
   
    // Construct Atoms using 2-D vector
    MatrixXd Atoms(height, width);
    cout << nOfatoms<<endl;
    //cout << Atoms.size()<<" "<<Atoms[0].size()<<endl;
    
    for (int i = 0; i < nOfatoms; i++)
    {
        int layer_count = i / nOfatoms_per_layer + 1;
        if (layer_count % 2)
        {
            Atoms(i,0) = (-CubicSize / 2 + LatticeSpacing * (i % nOfsites));
            Atoms(i,1) = (i % nOfatoms_per_layer) / nOfsites * LatticeSpacing;
            Atoms(i,2) = ((layer_count - 1) * LatticeSpacing / 2);
        }
        else
        {
            Atoms(i,0) = (-CubicSize / 2 + LatticeSpacing * (i % nOfsites) + LatticeSpacing / 2);
            Atoms(i,1) = (i % nOfatoms_per_layer) / nOfsites * LatticeSpacing + LatticeSpacing / 2;
            Atoms(i,2) = ((layer_count - 1) * LatticeSpacing / 2);
        }

    }

    // Calculate the means of each column
    double x_total = 0;
    double y_total = 0;
    double z_total = 0;

    for (int i = 0; i < nOfatoms; i++)
    {
        x_total += Atoms(i,0);
        y_total += Atoms(i,1);
        z_total += Atoms(i,2);
    }

    double x_means = x_total / nOfatoms;
    double y_means = y_total / nOfatoms;
    double z_means = z_total / nOfatoms;

    // Do the shifting
    for (int i = 0; i < nOfatoms; i++)
    {
        Atoms(i,0) = Atoms(i,0) - x_means + x_0;
        Atoms(i,1) = Atoms(i,1) - y_means + y_0;
        Atoms(i,2) = Atoms(i,2) - z_means + z_0;
    }
    
    //=================//

    

    //=================//


    // test output with mode "t"
    if (mode == "t")
    {
    for (int i = 0; i < nOfatoms; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            //result[i][j] = Atoms[i][j];
            //cout << Atoms[i][j] << "    ";
        }
        //cout << endl;
    }
    }
    /*
    // test output with mode "b"
    if (mode == "b")
    {
    for (int i = 0; i < nOfatoms; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // if it is float number
            if (Atoms[i][j] != round(Atoms[i][j]))
            {
                floatToBinary(Atoms[i][j], float_binary);
                myFile << float_binary;
                float_binary.clear();
            }
            // if it is integers
            else
            {
                // For positive int numbers
                if (Atoms[i][j] >= 0)
                {
                    ConvertToBinary_plus(Atoms[i][j]);
                }
                // For negative int numbers
                else
                {
                    ConvertToBinary_minus(-1 * Atoms[i][j]);
                    int temp = ~(std::stoi(minus_binary)) + 1;
                    myFile << to_string(temp);
                    minus_binary.clear();
                }
            }
        }
  //      myFile << endl;
    }
    }
    */
    return Atoms;
}
