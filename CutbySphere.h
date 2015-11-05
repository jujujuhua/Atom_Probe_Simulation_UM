
#include <Eigen/Dense>
using Eigen::MatrixXd;
using namespace Eigen;
using namespace std;

pair<MatrixXd*,MatrixXd*> CutbySphere(MatrixXd &Atoms, double Radius, double x0,double y0,double z0 );