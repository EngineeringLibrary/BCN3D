#include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"

using namespace std;
using namespace LinAlg;

int main()
{
    Matrix<double>A(3,3);
    Ones<double>(A);
    A = A*3;
    cout << A<<endl;
    cout << (A^2);//simbolo substituido de > para ^

    return 0;
}

