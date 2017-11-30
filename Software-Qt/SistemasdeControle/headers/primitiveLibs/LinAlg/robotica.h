#ifndef ROBOTICA_H
#define ROBOTICA_H
#define SWAP

#include <complex>//numeros complexos
#include <cfloat>
#include <cmath>
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/linalg.h"
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"
#include "QString"

class Robotica {

private:


public:
    QString a,d;

    LinAlg::Matrix<double> R_TbaCriarMatrizTransf;

    LinAlg::Matrix<double> R_eulerAngles;

    LinAlg::Matrix<double> R_CriarMatrizTransfInv;

    LinAlg::Matrix<double> T_transformacao;

    LinAlg::Matrix<double> Rxx;

    LinAlg::Matrix<double> Ryy;

    LinAlg::Matrix<double> Rzz;

    LinAlg::Matrix<double> Rx (double angulo);

    LinAlg::Matrix<double> Ry (double angulo);

    LinAlg::Matrix<double> Rz (double angulo);

    LinAlg::Matrix<double>transformacao (double* vector);

    LinAlg::Matrix<double>CriarMatrizTransfInv(LinAlg::Matrix<double> Rba, LinAlg::Matrix<double> Pba);

    LinAlg::Matrix<double>TbaCriarMatrizTransf(LinAlg::Matrix<double> Rba, LinAlg::Matrix<double> Pba);

    LinAlg::Matrix<double>eulerAngles(LinAlg::Matrix<double> angles);

};


#endif // ROBOTICA_H
