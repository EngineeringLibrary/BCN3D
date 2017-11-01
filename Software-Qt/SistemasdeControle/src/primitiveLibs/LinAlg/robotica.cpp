#include "SistemasdeControle/headers/primitiveLibs/LinAlg/robotica.h"


 LinAlg::Matrix<double> Robotica::Rx (double alfa){

    LinAlg::Matrix<double>aRb(3,3);
    aRb(1,1) = 1; aRb(1,2) = 0; aRb(1,3) = 0;
    aRb(2,1) = 0; aRb(2,2) = cos(alfa); aRb(2,3) = -sin(alfa);
    aRb(3,1) = 0; aRb(3,2) = sin(alfa); aRb(3,3) = cos(alfa);

    Rxx = aRb;
    return aRb;
}

LinAlg::Matrix<double> Robotica::Ry (double theta){

    LinAlg::Matrix<double> bR(3,3);
    bR(1,1) = cos(theta) ; bR(1,2) = 0         ; bR(1,3) = sin(theta);
    bR(2,1) = 0          ; bR(2,2) = 1         ; bR(2,3) = 0         ;
    bR(3,1) = -sin(theta); bR(3,2) = sin(theta); bR(3,3) = cos(theta);

    Ryy = bR;
    return bR;
}

LinAlg::Matrix<double> Robotica::Rz (double fi){

    LinAlg::Matrix<double> aPb(3,3);
    aPb(1,1) = cos(fi); aPb(1,2) = -sin(fi); aPb(1,3) = 0   ;
    aPb(2,1) = sin(fi); aPb(2,2) = cos(fi) ; aPb(2,3) = 0   ;
    aPb(3,1) = 0      ; aPb(3,2) = 0       ; aPb(3,3) = 1   ;

    Rzz = aPb;
    return aPb;
}

LinAlg::Matrix<double> Robotica::transformacao (double* vector){

    LinAlg::Matrix<double> T(4,4);

    double alfa = vector[0];
    double theta = vector[1];
     a = vector[2];
     d = vector[3];
     bool ok = false;

    T(1,1) = cos(theta)          ; T(1,2) = -sin(theta)         ; T(1,3) =  0        ; T(1 ,4) =  a.toDouble(&ok);
    T(2,1) = cos(alfa)*sin(theta); T(2,2) = cos(alfa)*sin(theta); T(2,3) = -sin(alfa); T(2,4) = -d.toDouble(&ok)*sin(alfa);
    T(3,1) = sin(alfa)*sin(theta); T(3,2) = sin(alfa)*cos(theta); T(3,3) =  cos(alfa); T(3,4) =  d.toDouble(&ok)*cos(alfa);
    T(4,1) = 0                   ; T(4,2) = 0                   ; T(4,3) =  0        ; T(4,4) =  1          ;

    T_transformacao = T;
    return T;
}

LinAlg::Matrix<double> Robotica::eulerAngles(LinAlg::Matrix<double> angles){//feito

    double thetaX = angles(1,1);
    double thetaY = angles(1,2);
    double thetaZ = angles(1,3);

    LinAlg::Matrix<double> R(3,3);
    R(1,1) = ((cos(thetaZ))*(cos(thetaY))); R(1,2) = (((cos(thetaZ))*(sin(thetaY))*(sin(thetaX)))-((sin(thetaZ))*(cos(thetaX)))); R(1,3) = (((cos(thetaZ))*(sin(thetaY))*(cos(thetaX)))+((sin(thetaZ))*(sin(thetaX))));
    R(2,1) = ((sin(thetaZ))*(cos(thetaY))); R(2,2) = (((sin(thetaZ))*(sin(thetaY))*(sin(thetaX)))+((cos(thetaZ))*(cos(thetaX)))); R(2,3) = (((sin(thetaZ))*(sin(thetaY))*(cos(thetaX)))-((cos(thetaZ))*(sin(thetaX))));
    R(3,1) = -sin(thetaY); R(3,2) = ((cos(thetaY))*(sin(thetaX))); R(3,3) = ((cos(thetaY))*(cos(thetaX)));

    R_eulerAngles = R;
    return R;
}

LinAlg::Matrix<double> Robotica::TbaCriarMatrizTransf(LinAlg::Matrix<double> Rba, LinAlg::Matrix<double> Pba){//feito

    int m = Rba.getNumberOfColumns();
    int n = Rba.getNumberOfRows();
    LinAlg::Matrix<double> R(n,m);
    if( m == n){
        LinAlg::Matrix<double> zeros(1,m+1);
        zeros(1,m+1) = 1;
        R = (Rba|Pba)||zeros;

        R_TbaCriarMatrizTransf = R;
        return R;
    }else{
        return 1;
    }
}

LinAlg::Matrix<double> Robotica::CriarMatrizTransfInv(LinAlg::Matrix<double> Rba, LinAlg::Matrix<double> Pba){

    int m = Rba.getNumberOfColumns();
    int n = Rba.getNumberOfRows();
    LinAlg::Matrix<double> R(n,m);
    LinAlg::Matrix<double> zeros(1,m+1);
     if(m==n){

         zeros = LinAlg::Zeros<double>(1,m+1);
         zeros(1,m+1) = 1;
         R = (~Rba | -(~Rba) * Pba)||zeros;
         R_CriarMatrizTransfInv = R;
         return R;
     }else{
        return 1;
     }
}
