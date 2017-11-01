#include <QString>
#include <QtTest>
#include <complex>

#define testMatrix
#include "../../../../headers/primitiveLibs/LinAlg/linalg.h"

class LinAlgTest : public QObject
{
    Q_OBJECT

public:
    LinAlgTest(){}

private Q_SLOTS:

    void traceDouble ();
    void HessDoubleCase1 ();
    void HessDoubleCase2 ();
    void HessFormDoubleCase1 ();
    void HessFormDoubleCase2 ();
    void QR_Factorization_ModifiedGramSchmidtDouble ();
    void QR_FactorizationDouble ();
    void QRDouble ();
    void LU_FactorizationDouble ();
    void balanceDouble ();
    void eigenValuesDouble();
    void eigenVectorsDouble(); //Continuar daqui;
    void eigenValues_LUDouble ();
    void inv_numericDouble ();
    void caracteristicPolynomDouble ();
    void multPolyDouble ();
    void absDouble ();
    void sqrtMatrixDouble ();
    void powMatrixDouble ();
    void meanDoubleCase1 ();
    void meanDoubleCase2 ();
    void meanDoubleCase3 ();
};

void LinAlgTest::traceDouble (){
    LinAlg::Matrix<double> B = LinAlg::Ones<double>(10,10);
    double A;
    QBENCHMARK {
        A = LinAlg::trace(B);
    }
    QVERIFY2(A == 10, "Falhou ao calcular o traco da matriz com valor double");
}

void LinAlgTest::HessDoubleCase1 ()
{
    LinAlg::Matrix<double> A, B = "1, 8, -10; -4, 2, 4; -5, 2, 8";
    QBENCHMARK {
        A = LinAlg::Hess(B);
    }
    QVERIFY2(A.getNumberOfColumns() == 3 && A.getNumberOfRows() == 3, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(fabs(A(1,1) - 1) <= 0.001      && fabs(A(1,2) - 2.8111) <= 0.001   && abs(A(1,3) - (-12.4939)) <= 0.001  &&
             fabs(A(2,1) - 6.4031) <= 0.001 && fabs(A(2,2) - 8.5854) <= 0.001   && abs(A(2,3) - (-3.2683)) <= 0.001   &&
             fabs(A(3,1)) <= 0.001          && fabs(A(3,2) - (-1.2683)) <= 0.001 && abs(A(3,3) - 1.4146) <= 0.001,
    "Falhou ao verificar a forma de hessemberg");
}

void LinAlgTest::HessDoubleCase2 ()
{
    LinAlg::Matrix<double> A, B = "1,7,7,2,9;3,1,9,0,6;3,7,9,7,6;7,5,3,5,9;1,8,7,5,8";
    QBENCHMARK {
        A = LinAlg::Hess(B);
    }
    QVERIFY2(A.getNumberOfColumns() == 5 && A.getNumberOfRows() == 5, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(fabs(A(1,1) - 1)         <= 0.001      && fabs(A(1,2) - (-7.8824)) <= 0.001   && abs(A(1,3) - (-9.5752)) <= 0.001 && fabs(A(1,4) - (5.4014))  <= 0.001   && abs(A(1,5) - (0.0890))  <= 0.001 &&
             fabs(A(2,1) - (-8.2462)) <= 0.001      && fabs(A(2,2) - (14.4265)) <= 0.001   && abs(A(2,3) - (12.3793)) <= 0.001 && fabs(A(2,4) - (-4.7446)) <= 0.001   && abs(A(2,5) - (-2.0256)) <= 0.001 &&
             fabs(A(3,1) - 0)         <= 0.001      && fabs(A(3,2) - (12.1997)) <= 0.001   && abs(A(3,3) - ( 7.0241)) <= 0.001 && fabs(A(3,4) - (-4.2974)) <= 0.001   && abs(A(3,5) - (2.1237))  <= 0.001 &&
             fabs(A(4,1) - 0)         <= 0.001      && fabs(A(4,2) - (0))       <= 0.001   && abs(A(4,3) - (-6.3114)) <= 0.001 && fabs(A(4,4) - (-1.3976)) <= 0.001   && abs(A(4,5) - (-2.7984)) <= 0.001 &&
             fabs(A(5,1) - 0)         <= 0.001      && fabs(A(5,2) - (0))       <= 0.001   && abs(A(5,3) - (0))       <= 0.001 && fabs(A(5,4) - ( 2.7502)) <= 0.001   && abs(A(5,5) - (2.9470))  <= 0.001,
    "Falhou ao verificar a forma de hessemberg");
}

void LinAlgTest::HessFormDoubleCase1 ()
{
    LinAlg::Matrix<double> A, B = "1, 8, -10; -4, 2, 4; -5, 2, 8";
    QBENCHMARK {
        A = LinAlg::Hessemberg_Form(B);
    }
    QVERIFY2(A.getNumberOfColumns() == 3 && A.getNumberOfRows() == 3, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(fabs(A(1,1) - 1) <= 0.001      && fabs(A(1,2) - 2.8111) <= 0.001   && abs(A(1,3) - (-12.4939)) <= 0.001  &&
             fabs(A(2,1) - 6.4031) <= 0.001 && fabs(A(2,2) - 8.5854) <= 0.001   && abs(A(2,3) - (-3.2683)) <= 0.001   &&
             fabs(A(3,1)) <= 0.001          && fabs(A(3,2) - (-1.2683)) <= 0.001 && abs(A(3,3) - 1.4146) <= 0.001,
    "Falhou ao verificar a forma de hessemberg");
}

void LinAlgTest::HessFormDoubleCase2 ()
{
    LinAlg::Matrix<double> A, B = "1,7,7,2,9;3,1,9,0,6;3,7,9,7,6;7,5,3,5,9;1,8,7,5,8";
    QBENCHMARK {
        A = LinAlg::Hessemberg_Form(B);
    }
    QVERIFY2(A.getNumberOfColumns() == 5 && A.getNumberOfRows() == 5, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(fabs(A(1,1) - 1)         <= 0.001      && fabs(A(1,2) - (-7.8824)) <= 0.001   && abs(A(1,3) - (-9.5752)) <= 0.001 && fabs(A(1,4) - (5.4014))  <= 0.001   && abs(A(1,5) - (0.0890))  <= 0.001 &&
             fabs(A(2,1) - (-8.2462)) <= 0.001      && fabs(A(2,2) - (14.4265)) <= 0.001   && abs(A(2,3) - (12.3793)) <= 0.001 && fabs(A(2,4) - (-4.7446)) <= 0.001   && abs(A(2,5) - (-2.0256)) <= 0.001 &&
             fabs(A(3,1) - 0)         <= 0.001      && fabs(A(3,2) - (12.1997)) <= 0.001   && abs(A(3,3) - ( 7.0241)) <= 0.001 && fabs(A(3,4) - (-4.2974)) <= 0.001   && abs(A(3,5) - (2.1237))  <= 0.001 &&
             fabs(A(4,1) - 0)         <= 0.001      && fabs(A(4,2) - (0))       <= 0.001   && abs(A(4,3) - (-6.3114)) <= 0.001 && fabs(A(4,4) - (-1.3976)) <= 0.001   && abs(A(4,5) - (-2.7984)) <= 0.001 &&
             fabs(A(5,1) - 0)         <= 0.001      && fabs(A(5,2) - (0))       <= 0.001   && abs(A(5,3) - (0))       <= 0.001 && fabs(A(5,4) - ( 2.7502)) <= 0.001   && abs(A(5,5) - (2.9470))  <= 0.001,
    "Falhou ao verificar a forma de hessemberg");
}

void LinAlgTest::QR_Factorization_ModifiedGramSchmidtDouble (){
    LinAlg::Matrix<double> Q, R, B = "5,7,5;5,0,1;1,1,8";
    QBENCHMARK {
        *(Q,R) = LinAlg::QR_Factorization_ModifiedGramSchmidt(B);
    }
    QVERIFY2(Q.getNumberOfColumns() == 3 && Q.getNumberOfRows() == 3, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(fabs(Q(1,1) - 0.7001) <= 0.001 && fabs(Q(1,2) - (0.6999))  <= 0.001 && fabs(Q(1,3) - (-0.1412)) <= 0.001 &&
             fabs(Q(2,1) - 0.7001) <= 0.001 && fabs(Q(2,2) - (-0.7118)) <= 0.001 && fabs(Q(2,3) - (-0.0565)) <= 0.001 &&
             fabs(Q(3,1) - 0.1400) <= 0.001 && fabs(Q(3,2) - (0.0593))  <= 0.001 && fabs(Q(3,3) - (0.9884))  <= 0.001,
    "Falhou ao verificar o Q da Fatoração QR");

    QVERIFY2(R.getNumberOfColumns() == 3 && R.getNumberOfRows() == 3, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(fabs(R(1,1) - 7.141) <= 0.01 && fabs(R(1,2) - 5.041) <= 0.01 && fabs(R(1,3) - 5.321) <= 0.01 &&
             fabs(R(2,1) - 0)     <= 0.01 && fabs(R(2,2) - 4.959) <= 0.01 && fabs(R(2,3) - 3.262) <= 0.01 &&
             fabs(R(3,1) - 0)     <= 0.01 && fabs(R(3,2) - 0)     <= 0.01 && fabs(R(3,3) - 7.144) <= 0.01,
    "Falhou ao verificar o R da Fatoração QR");
}
void LinAlgTest::QR_FactorizationDouble ()
{
    LinAlg::Matrix<double> Q, R, B = "5,7,5;5,0,1;1,1,8";
    QBENCHMARK {
        *(Q,R) = LinAlg::QR_Factorization(B);
    }
    QVERIFY2(Q.getNumberOfColumns() == 3 && Q.getNumberOfRows() == 3, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(fabs(Q(1,1) - 0.7001) <= 0.001 && fabs(Q(1,2) - (0.6999))  <= 0.001 && fabs(Q(1,3) - (-0.1412)) <= 0.001 &&
             fabs(Q(2,1) - 0.7001) <= 0.001 && fabs(Q(2,2) - (-0.7118)) <= 0.001 && fabs(Q(2,3) - (-0.0565)) <= 0.001 &&
             fabs(Q(3,1) - 0.1400) <= 0.001 && fabs(Q(3,2) - (0.0593))  <= 0.001 && fabs(Q(3,3) - (0.9884))  <= 0.001,
    "Falhou ao verificar o Q da Fatoração QR");

    QVERIFY2(R.getNumberOfColumns() == 3 && R.getNumberOfRows() == 3, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(fabs(R(1,1) - 7.141) <= 0.01 && fabs(R(1,2) - 5.041) <= 0.01 && fabs(R(1,3) - 5.321) <= 0.01 &&
             fabs(R(2,1) - 0)     <= 0.01 && fabs(R(2,2) - 4.959) <= 0.01 && fabs(R(2,3) - 3.262) <= 0.01 &&
             fabs(R(3,1) - 0)     <= 0.01 && fabs(R(3,2) - 0)     <= 0.01 && fabs(R(3,3) - 7.144) <= 0.01,
    "Falhou ao verificar o R da Fatoração QR");
}
void LinAlgTest::QRDouble ()
{
    LinAlg::Matrix<double> Q, R, B = "5,7,5;5,0,1;1,1,8";
    QBENCHMARK {
        *(Q,R) = LinAlg::QR(B);
    }
    QVERIFY2(Q.getNumberOfColumns() == 3 && Q.getNumberOfRows() == 3, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(fabs(Q(1,1) - 0.7001) <= 0.001 && fabs(Q(1,2) - (0.6999))  <= 0.001 && fabs(Q(1,3) - (-0.1412)) <= 0.001 &&
             fabs(Q(2,1) - 0.7001) <= 0.001 && fabs(Q(2,2) - (-0.7118)) <= 0.001 && fabs(Q(2,3) - (-0.0565)) <= 0.001 &&
             fabs(Q(3,1) - 0.1400) <= 0.001 && fabs(Q(3,2) - (0.0593))  <= 0.001 && fabs(Q(3,3) - (0.9884))  <= 0.001,
    "Falhou ao verificar o Q da Fatoração QR");

    QVERIFY2(R.getNumberOfColumns() == 3 && R.getNumberOfRows() == 3, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(fabs(R(1,1) - 7.141) <= 0.01 && fabs(R(1,2) - 5.041) <= 0.01 && fabs(R(1,3) - 5.321) <= 0.01 &&
             fabs(R(2,1) - 0)     <= 0.01 && fabs(R(2,2) - 4.959) <= 0.01 && fabs(R(2,3) - 3.262) <= 0.01 &&
             fabs(R(3,1) - 0)     <= 0.01 && fabs(R(3,2) - 0)     <= 0.01 && fabs(R(3,3) - 7.144) <= 0.01,
    "Falhou ao verificar o R da Fatoração QR");
}

void LinAlgTest::LU_FactorizationDouble ()
{
    LinAlg::Matrix<double> L, U, B = "5,7,5;5,0,1;1,1,8";
    QBENCHMARK {
        *(L,U) = LinAlg::LU_Factorization(B);
    }
    QVERIFY2(U.getNumberOfColumns() == 3 && U.getNumberOfRows() == 3, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(fabs(U(1,1) - 5.0000) <= 0.001 && fabs(U(1,2) - (7.0000))  <= 0.001 && fabs(U(1,3) - (5.0000)) <= 0.001 &&
             fabs(U(2,1) - 0.0000) <= 0.001 && fabs(U(2,2) - (-7.0000)) <= 0.001 && fabs(U(2,3) - (-4.0000)) <= 0.001 &&
             fabs(U(3,1) - 0.0000) <= 0.001 && fabs(U(3,2) - (0.0000))  <= 0.001 && fabs(U(3,3) - (7.2286))  <= 0.001,
    "Falhou ao verificar o U da Fatoração LU");

    QVERIFY2(L.getNumberOfColumns() == 3 && L.getNumberOfRows() == 3, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(fabs(L(1,1) - 1.0000) <= 0.01 && fabs(L(1,2) - 0.000) <= 0.01 && fabs(L(1,3) - 0.000) <= 0.01 &&
             fabs(L(2,1) - 1.0000) <= 0.01 && fabs(L(2,2) - 1.000) <= 0.01 && fabs(L(2,3) - 0.000) <= 0.01 &&
             fabs(L(3,1) - 0.2000) <= 0.01 && fabs(L(3,2) - 0.057) <= 0.01 && fabs(L(3,3) - 1.000) <= 0.01,
    "Falhou ao verificar o L da Fatoração LU");
}

void LinAlgTest::balanceDouble ()
{
    LinAlg::Matrix<double> A = "5,7,5;5,0,1;1,1,8";
    QBENCHMARK {
       LinAlg::balance(A);
    }
    QVERIFY2(A.getNumberOfColumns() == 3 && A.getNumberOfRows() == 3, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(fabs(A(1,1) - 5.0000) <= 0.001 && fabs(A(1,2) - (7.0000))  <= 0.001 && fabs(A(1,3) - (2.5000)) <= 0.001 &&
             fabs(A(2,1) - 5.0000) <= 0.001 && fabs(A(2,2) - (0.0000))  <= 0.001 && fabs(A(2,3) - (0.5000)) <= 0.001 &&
             fabs(A(3,1) - 2.0000) <= 0.001 && fabs(A(3,2) - (2.0000))  <= 0.001 && fabs(A(3,3) - (8.000))  <= 0.001,
    "Falhou ao verificar a função balance");
}

void LinAlgTest::eigenValuesDouble()
{
    LinAlg::Matrix<double> Ava, A = "5,7,5;5,0,1;1,1,8";
    A = (~A)*A;
    QBENCHMARK {
        Ava = LinAlg::eigenValues(A);
    }
    QVERIFY2(Ava.getNumberOfColumns() == 2 && Ava.getNumberOfRows() == 3, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(fabs(Ava(1,1) - 145.589) <= 0.01 && fabs(Ava(1,2)) <= 0.01 &&
             fabs(Ava(2,1) - 13.994)  <= 0.01 && fabs(Ava(2,2)) <= 0.01 &&
             fabs(Ava(3,1) - 31.417)  <= 0.01 && fabs(Ava(3,2)) <= 0.01,
    "Falhou ao verificar os autovalores");
}

void LinAlgTest::eigenVectorsDouble()
{
    LinAlg::Matrix<double> Ave, A = "5,7,5;5,0,1;1,1,8";
    A = (~A)*A;
    QBENCHMARK {
        Ave = LinAlg::eigenVectors(A);
    }
    QVERIFY2(Ave.getNumberOfColumns() == 3 && Ave.getNumberOfRows() == 3, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(fabs(Ave(1,1) - 0.480) <= 0.001 && fabs(Ave(1,2) - (-0.618)) && fabs(Ave(1,3) - ( 0.622)) &&
             fabs(Ave(2,1) - 0.504) <= 0.001 && fabs(Ave(2,2) - (-0.386)) && fabs(Ave(2,3) - (-0.773)) &&
             fabs(Ave(3,1) - 0.718) <= 0.001 && fabs(Ave(3,2) - ( 0.685)) && fabs(Ave(3,3) - ( 0.126)),
    "Falhou ao verificar os autovalores");
}

void LinAlgTest::eigenValues_LUDouble ()
{
    LinAlg::Matrix<double> Ava, A = "5,7,5;5,0,1;1,1,8";
    A = (~A)*A;
    QBENCHMARK {
        Ava = LinAlg::eigenValues_LU(A);
    }
    QVERIFY2(Ava.getNumberOfColumns() == 3 && Ava.getNumberOfRows() == 3, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(fabs(Ava(1,1) - 145.589) <= 0.001 &&
             fabs(Ava(2,2) - 31.417)  <= 0.001 &&
             fabs(Ava(3,3) - 13.994)  <= 0.001,
    "Falhou ao verificar os autovalores");
}

void LinAlgTest::caracteristicPolynomDouble ()
{
    LinAlg::Matrix<double> A, B = "1, 8, -10; -4, 2, 4; -5, 2, 8";
    QBENCHMARK {
        A = LinAlg::characteristicPolynom(B);
    }
    QVERIFY2(A.getNumberOfColumns() == 4 && A.getNumberOfRows() == 1, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(fabs(A(1,1) - 1) <= 0.001 && fabs(A(1,2) - (-11)) <= 0.001 && fabs(A(1,3)) <= 0.001 && fabs(A(1,4) - (-84)) <= 0.001,
             "Falhou ao verificar os coeficientes do polinomio caracteristico");
}

void LinAlgTest::inv_numericDouble ()
{
    LinAlg::Matrix<double> Ave, A = "5,7,5;5,0,1;1,1,8";
    QBENCHMARK {
        Ave = LinAlg::inv_numeric(A);
    }
    QVERIFY2(Ave.getNumberOfColumns() == 3 && Ave.getNumberOfRows() == 3, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(fabs(Ave(1,1) - 0.0040)    <= 0.001 && fabs(Ave(1,2) - ( 0.2016)) && fabs(Ave(1,3) - (-0.0277)) &&
             fabs(Ave(2,1) - 0.1542)    <= 0.001 && fabs(Ave(2,2) - (-0.1383)) && fabs(Ave(2,3) - (-0.0791)) &&
             fabs(Ave(3,1) - (-0.0198)) <= 0.001 && fabs(Ave(3,2) - (-0.0079)) && fabs(Ave(3,3) - ( 0.1383)),
    "Falhou ao verificar os elementos da inversa matricial");
}

void LinAlgTest::multPolyDouble ()
{
    double *A;
    double *den1 = new double[3], *den2 = new double[3];
    den1[0] = 1;den1[1] = 2;den1[2] = 1;
    den2[0] = 1;den2[1] = 2;den2[2] = 1;
    unsigned sizeDen1 = 3, sizeDen2 = 3;
    QBENCHMARK {
        A = LinAlg::MultPoly(den1,den2,sizeDen1,sizeDen2);
    }
    QVERIFY2(A[0] == 1 && A[1] == 4 && A[2] == 6 && A[3] == 4 && A[4] == 1, "Falhou ao testar o resultado da multiplicação dos Polinomios");
}

void LinAlgTest::absDouble ()
{
    LinAlg::Matrix<double> Ave, A = "-5,7,-5;5,0,-1;1,-1,8";
    QBENCHMARK {
        Ave = LinAlg::abs(A);
    }
    QVERIFY2(Ave.getNumberOfColumns() == 3 && Ave.getNumberOfRows() == 3, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(Ave(1,1) == 5 && Ave(1,2) == 7 && Ave(1,3) == 5&&
             Ave(2,1) == 5 && Ave(2,2) == 0 && Ave(2,3) == 1&&
             Ave(3,1) == 1 && Ave(3,2) == 1 && Ave(3,3) == 8,
    "Falhou ao verificar os elementos do módulo da matriz");
}

void LinAlgTest::sqrtMatrixDouble ()
{
    LinAlg::Matrix<double> Ave, A = "5,7,5;5,0,1;1,1,8";
    QBENCHMARK {
        Ave = LinAlg::sqrtMatrix(A);
    }
    QVERIFY2(Ave.getNumberOfColumns() == 3 && Ave.getNumberOfRows() == 3, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(Ave(1,1) == sqrt(5) && Ave(1,2) == sqrt(7) && Ave(1,3) == sqrt(5) &&
             Ave(2,1) == sqrt(5) && Ave(2,2) == sqrt(0) && Ave(2,3) == sqrt(1) &&
             Ave(3,1) == sqrt(1) && Ave(3,2) == sqrt(1) && Ave(3,3) == sqrt(8),
    "Falhou ao verificar os elementos do módulo da matriz");
}

void LinAlgTest::powMatrixDouble ()
{
    LinAlg::Matrix<double> Ave, A = "5,7,5;5,0,1;1,1,8";
    QBENCHMARK {
        Ave = LinAlg::powMatrix(A,2.0);
    }
    QVERIFY2(Ave.getNumberOfColumns() == 3 && Ave.getNumberOfRows() == 3, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(Ave(1,1) == pow(5,2) && Ave(1,2) == pow(7,2) && Ave(1,3) == pow(5,2) &&
             Ave(2,1) == pow(5,2) && Ave(2,2) == pow(0,2) && Ave(2,3) == pow(1,2) &&
             Ave(3,1) == pow(1,2) && Ave(3,2) == pow(1,2) && Ave(3,3) == pow(8,2),
    "Falhou ao verificar os elementos da potência da matriz");
}

void LinAlgTest::meanDoubleCase1 ()
{
    LinAlg::Matrix<double> Ave, A = "5,7,5;5,0,1;1,1,8";
    QBENCHMARK {
        Ave = LinAlg::mean(A);
    }
    QVERIFY2(Ave.getNumberOfColumns() == 3 && Ave.getNumberOfRows() == 1, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(fabs(Ave(1,1) - 11.0/3.0) <= 0.001 && fabs(Ave(1,2) - 8.0/3.0) <= 0.001 && fabs(Ave(1,3) - 14.0/3.0) <= 0.001,
    "Falhou ao verificar os elementos da media da matriz");
}

void LinAlgTest::meanDoubleCase2 ()
{
    LinAlg::Matrix<double> Ave, A = "5,7,5;5,0,1;1,1,8";
    QBENCHMARK {
        Ave = LinAlg::mean(A,1);
    }
    QVERIFY2(Ave.getNumberOfColumns() == 3 && Ave.getNumberOfRows() == 1, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(fabs(Ave(1,1) - 11.0/3.0) <= 0.001 && fabs(Ave(1,2) - 8.0/3.0) <= 0.001 && fabs(Ave(1,3) - 14.0/3.0) <= 0.001,
    "Falhou ao verificar os elementos da media da matriz");
}

void LinAlgTest::meanDoubleCase3 ()
{
    LinAlg::Matrix<double> Ave, A = "5,7,5;5,0,1;1,1,8";
    QBENCHMARK {
        Ave = LinAlg::mean(A,2);
    }
    QVERIFY2(Ave.getNumberOfColumns() == 1 && Ave.getNumberOfRows() == 3, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(fabs(Ave(1,1) - 17.0/3.0) <= 0.001 && fabs(Ave(2,1) - 2) <= 0.001 && fabs(Ave(3,1) - 10.0/3.0) <= 0.001,
    "Falhou ao verificar os elementos da media da matriz");
}

QTEST_APPLESS_MAIN(LinAlgTest)

#include "tst_linalgtest.moc"
