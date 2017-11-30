#include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"

using namespace std;
using namespace LinAlg;

int main()
{
    Matrix<double>A = ("1,2,3; 4,5,6; 7,8,9");
    Matrix<double>B = ("3,2,1; 6,5,4; 9,8,7");
    B =  A*2;
    cout << A<<endl;
    cout << B<<endl;


    return 0;
}
