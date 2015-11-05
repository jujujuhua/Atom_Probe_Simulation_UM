
#include <stdio.h>
#include <utility>
#include <iostream>
using namespace std;

struct CartesianPos{
    double x;
    double y;
    double z;
    
    CartesianPos(double a,double b,double c):x(a),y(b),z(c){};
    
    
    void print(){
        cout << x<<" "<<y<<" "<<z<<endl;
    }
};

void ConvertToCartesianFromSpheric(int SphericPos_x, int SphericPos_y);

void fuc();