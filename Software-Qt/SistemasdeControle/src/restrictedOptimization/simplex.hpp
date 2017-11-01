#ifdef testModel
    #include "../../../headers/restrictedOptimization/simplex.h"
#else
    #include "SistemasdeControle/headers/restrictedOptimization/simplex.h"
#endif

template <typename Type>
void restrictedOptimizationHandler::simplex<Type>::optimize()
{
    if(this->N.A.getNumberOfColumns() != 0 && this->N.A.getNumberOfRows() != 0)
    {
        this->P.A = (this->P.A | LinAlg::Eye<Type>(this->P.A.getNumberOfRows())                               | LinAlg::Zeros<Type>(this->N.A.getNumberOfRows(),this->N.A.getNumberOfRows())) ||
                  (this->N.A | LinAlg::Zeros<Type>(this->P.A.getNumberOfRows(),this->P.A.getNumberOfRows()) | -LinAlg::Eye<Type>(this->N.A.getNumberOfRows()));
//        std::cout << this->A << "\n";
        this->P.b = this->P.b || this->N.b;
        this->A = this->P.A   | LinAlg::Eye<Type>(this->P.A.getNumberOfRows())||
                  this->E.A | LinAlg::Zeros<Type>(this->E.A.getNumberOfRows(),this->P.A.getNumberOfRows());
        this->b = this->P.b || this->E.b;
//        LinAlg::Matrix<Type> c = this->function2Optimize || LinAlg::Zeros<Type>(1,this->P.b.getNumberOfRows() - this->E.b.getNumberOfRows() + this->N.b.getNumberOfRows());
        LinAlg::Matrix<Type> w = LinAlg::Zeros<Type>(this->A.getNumberOfColumns() - this->P.A.getNumberOfRows(),1)||
                                 LinAlg::Ones<Type>(this->P.A.getNumberOfRows(),1);
        LinAlg::Matrix<Type> B = LinAlg::LineVector<Type>(this->A.getNumberOfColumns() - this->P.A.getNumberOfRows() +1, this->A.getNumberOfColumns());
        LinAlg::Matrix<Type> n = LinAlg::LineVector<Type>(1,this->A.getNumberOfColumns() - this->P.A.getNumberOfRows());
        simplexOptimization(w,this->A,this->b,B,n);
        this->x = this->x(1,from(1)-->this->x.getNumberOfRows()-this->P.A.getNumberOfRows());
        this->A = this->A(from(1)-->this->A.getNumberOfRows(),from(1)-->this->A.getNumberOfColumns()-this->P.A.getNumberOfRows());
        LinAlg::Matrix<Type> c = this->function2Optimize ||
                                 LinAlg::Zeros<Type>(this->b.getNumberOfRows(),1);
        n = n(1,from(1)-->n.getNumberOfColumns()-this->P.A.getNumberOfRows());
        simplexOptimization(c,this->A,this->b,B,n);
        this->set = B;
    }
    else
    {
        this->A = (this->P.A | LinAlg::Eye<Type>(this->P.A.getNumberOfRows()))||
                  (this->E.A | LinAlg::Zeros<Type>(this->E.A.getNumberOfRows(),this->P.A.getNumberOfRows()));
        this->b = this->P.b || this->E.b;

        LinAlg::Matrix<Type> c = this->function2Optimize ||
                                 LinAlg::Zeros<Type>(this->b.getNumberOfColumns(), 1);

        LinAlg::Matrix<Type> B = LinAlg::LineVector<Type>(this->A.getNumberOfColumns() - this->P.A.getNumberOfRows() +1, this->A.getNumberOfColumns(),1);
        LinAlg::Matrix<Type> n = LinAlg::LineVector<Type>(1,this->A.getNumberOfColumns() - this->P.A.getNumberOfRows());
        simplexOptimization(c,this->A,this->b,B,n);
        this->set = B;
    }
//    std::cout << this->x << "\n\n";
}

template <typename Type>
void restrictedOptimizationHandler::simplex<Type>::simplexOptimization(const LinAlg::Matrix<Type> &c,
                                                                       const LinAlg::Matrix<Type> &A,
                                                                       const LinAlg::Matrix<Type> &b,
                                                                       LinAlg::Matrix<Type> &B,
                                                                       LinAlg::Matrix<Type> &N)
{
//    %% selecione uma base B e calcule B^-1
    LinAlg::Matrix<Type> An = A(from(1)-->A.getNumberOfRows(),N);
    LinAlg::Matrix<Type> Ab = A(from(1)-->A.getNumberOfRows(),B);
//    std::cout << N << "\n";
    LinAlg::Matrix<Type> Abinv = LinAlg::inv_numeric(Ab);
//    LinAlg::Matrix<Type> Abinv = (Ab^-1);
    LinAlg::Matrix<Type> xb;
//    %% Verifique o vetor dos custos reduzidos
    for(unsigned terminate = 1; terminate <= 100; ++terminate)
    {
        LinAlg::Matrix<Type> cn = c(N,1);
        LinAlg::Matrix<Type> cb = c(B,1);
        LinAlg::Matrix<Type>An = A(from(1)-->A.getNumberOfRows(),N);
        Ab = A(from(1)-->A.getNumberOfRows(),B);
        LinAlg::Matrix<Type> r = (~cn) - (~cb)*Abinv*An;
        this->cost = ((~cb)*Abinv*b)(1,1);
        xb = Abinv*b;
        unsigned contFlag = 0;
        for (unsigned i=1; i <= r.getNumberOfColumns(); ++i)
           if(r(1,i) >= 0)
           {
               contFlag = contFlag + 1;
//%               break;
           }
        if(contFlag == r.getNumberOfColumns())
            break;
        //%determine o vetor de chegada
        LinAlg::Matrix<Type> maxValue, maxIndice;
        *(maxValue, maxIndice) = LinAlg::max(~r);
        unsigned indMinD = maxIndice(1,1);
//        unsigned indMinD = LinAlg::lineOfMinValue(~r);

        this->x = Abinv*An(from(1)-->An.getNumberOfRows(),indMinD);
        LinAlg::Matrix<Type> d = LinAlg::divPoint(xb,this->x);
        Type dMin = INFINITY;
        unsigned indMinB = 1;
        for (unsigned i = 1; i <= d.getNumberOfRows(); ++i)
           if(this->x(i,1) > 0 && d(i,1) < dMin)
           {
               dMin = d(i,1);
               indMinB = i;
           }

        Abinv = EscalSimplex((Abinv | xb | this->x),indMinB);
        Type Bout = B(1,indMinB);
        Type Nout = N(1,indMinD);
        N = N(1,from(1)-->(indMinD-1)) | Bout | N(1, from(indMinD+1)-->(N.getNumberOfColumns()));
        B = B(1,from(1)-->(indMinB-1)) | Nout | B(1,from(indMinB+1)-->(B.getNumberOfColumns()));
    }

    this->x = xb || LinAlg::Zeros<Type>(An.getNumberOfColumns(),1);
//    LinAlg::Matrix<Type> ind = LinAlg::sortColumnVectorIndices<Type>(B|N);
    LinAlg::Matrix<Type> ind = LinAlg::sort<Type>(B|N);
    this->x = this->x(ind,1);
//    std::cout << "\n\n" << ind << "\n\n";
    N = LinAlg::sort<Type>(N);
    B = LinAlg::sort<Type>(B);
//    N = LinAlg::sortColumnVector<Type>(N);
//    B = LinAlg::sortColumnVector<Type>(B);
}

template <typename Type>
LinAlg::Matrix<Type> restrictedOptimizationHandler::simplex<Type>::EscalSimplex(LinAlg::Matrix<Type> A,
                                                                                unsigned index)
{
    for(unsigned i = 1; i <= A.getNumberOfColumns(); ++i)
        A(index,i) = A(index,i)/A(index,A.getNumberOfColumns());

    for (unsigned i = 1; i <= A.getNumberOfRows(); ++i)
        if(i != index)
        {
            Type m = A(i,A.getNumberOfColumns())/A(index,A.getNumberOfColumns());
            for(unsigned j = 1; j <= A.getNumberOfColumns(); ++j)
                A(i,j)=A(i,j)-m*A(index,j);
        }

//    Xb   = A(from(1)-->A.getNumberOfRows(),A.getNumberOfColumns()-1);
    LinAlg::Matrix<Type> Binv = A(from(1)-->A.getNumberOfRows(),from(1)-->A.getNumberOfColumns()-2);
//    X    = A(from(1)--> A.getNumberOfRows(),A.getNumberOfColumns());
    return Binv;
}
