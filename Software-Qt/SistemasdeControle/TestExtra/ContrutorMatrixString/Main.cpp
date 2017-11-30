#include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"

using namespace std;
using namespace LinAlg;

int main()
{
  Matrix<double> A("1,2,3;4,5,6;7,8,9");
  cout<<A;

  return 0;
}
