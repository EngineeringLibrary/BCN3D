#include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"

using namespace std;
using namespace LinAlg;

int main()
{
    Matrix<double>A;
    Matrix<double>B;
    A = ("1,2,3;4,5,6;7,8,9");
    B = ("3,2,1;6,5,4;9,8,7");

    cout << A <<endl;
    cout << B <<endl;
    cout << A-B;

    return 0;
}

