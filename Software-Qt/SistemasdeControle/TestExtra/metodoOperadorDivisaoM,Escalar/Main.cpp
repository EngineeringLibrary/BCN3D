#include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"

using namespace std;
using namespace LinAlg;

int main()
{
    Matrix<double>A;
    Matrix<double>B;
    A = ("2,4,6;8,10,12;14,16,18");
    B = A/2;
    cout << A <<endl;
    cout << B <<endl;

    return 0;
}

