#include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"

using namespace std;
using namespace LinAlg;

int main()
{
    Matrix<double> A("1,2,3;4,5,6;7,8,9");
    Matrix<double> B("10,11,12");//Se eu definir ("10;11;12") ele entede como coluna mesmo o operador sendo paralinha
    cout << A<<  endl ;
    cout << B << endl;
    Print (A||B);

    return 0;
}
//Resultado
//1.00000    2.00000    3.00000
//4.00000    5.00000    6.00000
//7.00000    8.00000    9.00000

//10.00000   11.00000   12.00000


//1.00000    2.00000    3.00000
//4.00000    5.00000    6.00000
//7.00000    8.00000    9.00000
//10.00000   11.00000   12.00000
