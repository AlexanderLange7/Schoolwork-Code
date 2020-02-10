#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double D, V;
    while(cin >> D && cin >> V && D && V !=0 ){
        double bsv = D*M_PI*pow(D/2,2);
        double hc = M_PI*pow(D/2,2)*(D/3);
        double cu = bsv-V-hc;
        double cyl = cu*1.5;
        double rad = pow((cyl/(2*M_PI)),(1.0/3.0));
        
        cout.precision(10);
        
        cout << rad*2 << endl;
        
        
        
    }
    return 0;
}