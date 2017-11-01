#include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"

using namespace std;
using namespace LinAlg;

int main()
{
    Matrix<double> A("4;7;10");
    cout << A<<  endl;
    Print (~A);

    return 0;
}
//Resultado
// 4.00000
// 7.00000
//10.00000


// 4.00000    7.00000   10.00000
