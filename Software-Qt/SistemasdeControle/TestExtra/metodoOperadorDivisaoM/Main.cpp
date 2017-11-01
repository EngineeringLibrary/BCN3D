#include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"

using namespace std;
using namespace LinAlg;


//A "divisão" matricial equivale a multiplicação com uma das matrizes (a direita do operador /) invertida (matriz^-1).
int main()
{
    Matrix<double>A;
    A = ("1,0,3;4,5,6;1,8,9");
    cout << A <<endl;
    cout << A/A;

    return 0;
}

