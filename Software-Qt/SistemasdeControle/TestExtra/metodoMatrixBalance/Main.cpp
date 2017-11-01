#include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/linalg.h"


using namespace std;
using namespace LinAlg;

int main()
{
    Matrix<double> A("1,2,3;4,5,6;7,8,9;3,2,2");
    cout << A<<endl;
    Balance<double>(A);
    cout << A<<endl;

    return 0;
}
// Resultado
//  1.00000    2.00000    3.00000
//  4.00000    5.00000    6.00000
//  7.00000    8.00000    9.00000
//  3.00000    2.00000    2.00000

//  1.00000    2.00000    3.00000
//  4.00000    5.00000    6.00000
//  7.00000    8.00000    9.00000
//  0.00000    0.00000    0.00000
