#ifdef testModel
    #include "../../../headers/modelLibs/conversions.h"
#else
    #include "SistemasdeControle/headers/modelLibs/conversions.h"
#endif

template <typename Type>
ModelHandler::TransferFunction<Type> ModelHandler::ss2tf(const ModelHandler::StateSpace<Type> &SS)
{
    ModelHandler::TransferFunction<Type> TF(SS.getC().getNumberOfRows(), SS.getB().getNumberOfColumns(),SS.getSampleTime());
    for(unsigned i = 1; i <= TF.getNumberOfRows(); ++i){
        for(unsigned j = 1; j <= TF.getNumberOfColumns(); ++j){
            ModelHandler::StateSpace<Type> SStemp(SS.getA(),SS.getB().getColumn(j), SS.getC().getRow(i), SS.getD().getRow(i),SS.getSampleTime());
            TF(i,j) = ModelHandler::ss2tfSISO(SStemp)(1,1);
//            std::cout << TF << SStemp;
        }
    }
    TF.setContinuous(SS.isContinuous());
    return TF;
}

template <typename Type>
ModelHandler::TransferFunction<Type> ModelHandler::ss2tfSISO(const ModelHandler::StateSpace<Type> &SS)
{
    using namespace LinAlg;
    using namespace ModelHandler;
    using namespace PolynomHandler;

    Matrix<Type> A = SS.getA();
    Matrix<Type> B = SS.getB();
    Matrix<Type> C = SS.getC();
    Matrix<Type> D = SS.getD();

    TransferFunction<Type> TF = Polynom<Type>(characteristicPolynom(A - B*C) - characteristicPolynom(A), characteristicPolynom(A));
    TF.setContinuous(SS.isContinuous());
    if(!SS.isContinuous())
    {
        TF.setSampleTime(SS.getSampleTime());
    }
    return TF;
}

template <typename Type>
ModelHandler::TransferFunction<Type> ModelHandler::arx2tf(const ARX<Type> &Arx, double sampleTime)
{
    unsigned nuPar  = Arx.getNumberOfInputs();
    unsigned nyPar  = Arx.getNumberOfOutputs();
    unsigned nu     = Arx.getNumberOfInputDelays();
    unsigned ny     = Arx.getNumberOfOutputDelays();

    LinAlg::Matrix<Type> ArxParameters = Arx.getModelCoef();
    ModelHandler::TransferFunction<Type> TF(nyPar, nuPar);

    for(unsigned i = 1; i <= nyPar; ++i)
    {
        for(unsigned j = 1; j <= nuPar; ++j)
        {
            TF(i,j) = PolynomHandler::Polynom<Type>
            ( ~ArxParameters(from( nyPar*ny + (j-1)*nu + 1) --> nyPar*ny + j*nu, i), LinAlg::Matrix<Type>(1)|
              ~ArxParameters(from(1)             --> ny,i ) );
        }
    }
    TF.setContinuous(false);
    TF.setSampleTime(sampleTime);
    return TF;
}

template <typename Type>
ModelHandler::StateSpace<Type> ModelHandler::arx2SS(const ARX<Type> &Arx)
{
    LinAlg::Matrix<Type> Temp;
    LinAlg::Matrix<Type> ArxParameters = Arx.getModelCoef();

    double sampleTime = Arx.getStep();
    unsigned nuPar    = Arx.getNumberOfInputs();
    unsigned nyPar    = Arx.getNumberOfOutputs();
//    unsigned nArxPar  = Arx.getNumberOfVariables();
    unsigned nu       = Arx.getNumberOfInputDelays();
    unsigned ny       = Arx.getNumberOfOutputDelays();

    LinAlg::Matrix<Type> A;//(nyPar*ny, nyPar*ny);
    LinAlg::Matrix<Type> B;//(nyPar*ny, nuPar);
    LinAlg::Matrix<Type> C(nyPar, nyPar*ny);
    LinAlg::Matrix<Type> D(nyPar, nuPar);

//    std::cout << ArxParameters;//dispensável

    for(unsigned i = 1; i <= nyPar; ++i)
    {
        Temp = LinAlg::Zeros<Type>(nyPar*ny, 1);
        unsigned row = 1;
        for(unsigned j = 1; j <= nyPar; ++j)
            for(unsigned k = 1; k <= ny; ++k){
                Temp(row,1) = -ArxParameters((i-1)*ny + k, j);
                ++row;
            }
//        std::cout << Temp;
        A = A|Temp|(LinAlg::Zeros<Type>((i - 1)*ny, ny - 1)                        ||
                    LinAlg::Eye<Type>(ny-1)                                        ||
                    LinAlg::Zeros<Type>(nyPar*ny - (i - 1)*ny - (ny - 1), ny - 1));
//        std::cout << A;
    }

    for(unsigned i = 1; i <= nuPar; ++i)
    {
        Temp = LinAlg::Zeros<Type>(nyPar*ny, 1);
        unsigned row = 1;
        for(unsigned j = 1; j <= nyPar; ++j)
            for(unsigned k = 1; k <= nu; ++k){
//                std::cout << ArxParameters << std::cout;
                Temp(row,1) = ArxParameters((i-1)*nu + k + nyPar*ny, j);
                ++row;
            }
//        std::cout << Temp;
        B = B|Temp;
//        std::cout << B;
    }

    for(unsigned i = 1; i <= nyPar; ++i)
    {
        for(unsigned j = 1; j <= nyPar*ny; ++j)
        {
            if(j == (i-1)*ny + 1)
                C(i,j) = 1;
        }
    }
//    std::cout << C;

    return StateSpace<Type>(A,B,C,D,sampleTime);
}

template <typename Type>
ModelHandler::StateSpace<Type> ModelHandler::tf2ss(const ModelHandler::TransferFunction<Type> &TF)
{
    ModelHandler::TransferFunction<Type> TFtemp = TF(1,1);
    ModelHandler::StateSpace<Type> SS = ModelHandler::tf2ssSISO(TFtemp);
    LinAlg::Matrix<Type> ZeroDireita, ZeroAbaixo;

    for(unsigned i = 1; i <= TF.getNumberOfRows(); ++i)
    {
        LinAlg::Matrix<Type> Btemp;
        LinAlg::Matrix<Type> Ctemp;
        LinAlg::Matrix<Type> Dtemp;

        for(unsigned j = 1; j <= TF.getNumberOfColumns(); ++j)
        {
            TFtemp = TF(i,j);
            ModelHandler::StateSpace<Type> SStemp = ModelHandler::tf2ssSISO(TFtemp);
            if(i != 1 || j != 1)//monta A
            {
                ZeroDireita = LinAlg::Zeros<Type> (SS.getA().getNumberOfRows(),SStemp.getA().getNumberOfColumns());
                ZeroAbaixo  = LinAlg::Zeros<Type> (SStemp.getA().getNumberOfRows(),SS.getA().getNumberOfColumns());
                SS.setA((SS.getA()|ZeroDireita) || (ZeroAbaixo|SStemp.getA()));
            }

            if(j == 1) // Monta B, C e D
            {
                Btemp = SStemp.getB();
                Ctemp = SStemp.getC();
                Dtemp = SStemp.getD();
            }
            else
            {
                ZeroDireita = LinAlg::Zeros<Type> (Btemp.getNumberOfRows(),SStemp.getB().getNumberOfColumns());
                ZeroAbaixo  = LinAlg::Zeros<Type> (SStemp.getB().getNumberOfRows(),Btemp.getNumberOfColumns());
                Btemp = (Btemp|ZeroDireita) || (ZeroAbaixo|SStemp.getB());

                Ctemp = (Ctemp) | (SStemp.getC());
                Dtemp = (Dtemp) | (SStemp.getD());
            }
        }
        if(i == 1) // Monta B, C e D
        {
            SS.setB(Btemp);
            SS.setC(Ctemp);
            SS.setD(Dtemp);
        }
        else
        {
            SS.setB(SS.getB()||Btemp);

            ZeroDireita = LinAlg::Zeros<Type> (Ctemp.getNumberOfRows(),SS.getC().getNumberOfColumns());
            ZeroAbaixo  = LinAlg::Zeros<Type> (SS.getC().getNumberOfRows(),Ctemp.getNumberOfColumns());
            SS.setC((Ctemp|ZeroDireita) || (ZeroAbaixo|SS.getC()));

            ZeroDireita = LinAlg::Zeros<Type> (Dtemp.getNumberOfRows(),SS.getD().getNumberOfColumns());
            ZeroAbaixo  = LinAlg::Zeros<Type> (SS.getD().getNumberOfRows(),Dtemp.getNumberOfColumns());
            SS.setD((Dtemp|ZeroDireita) || (ZeroAbaixo|SS.getD()));
        }
    }

    return SS;
}

template <typename Type>
ModelHandler::StateSpace<Type> ModelHandler::tf2ssSISO(const ModelHandler::TransferFunction<Type> &TF)
{
    unsigned TFdenCols = TF(1,1).getDenSize() - 1;
    LinAlg::Matrix<Type> I = LinAlg::Eye<Type> (TFdenCols - 1);
    LinAlg::Matrix<Type> den(1, TFdenCols);
    LinAlg::Matrix<Type> ZeroVector = LinAlg::Zeros<Type> (TFdenCols - 1, 1);

    for (unsigned i = 1; i <= TFdenCols; ++i)
    {
        den(1, i) = -(TF(1,1).getDen()(1, TFdenCols + 2 - i));
    }

    LinAlg::Matrix<Type> A = (ZeroVector|I)||den;
    LinAlg::Matrix<Type> B = LinAlg::Zeros<Type>(A.getNumberOfRows() - 1, 1)||LinAlg::Matrix<Type>(1);

    LinAlg::Matrix<Type> D(1,1);
    if(TF(1,1).getNumSize() == TF(1,1).getDenSize())
        D(1,1) = TF(1,1).getNum()(1,1);

    LinAlg::Matrix<Type> C = LinAlg::Zeros<Type>(1, A.getNumberOfColumns());
    for(unsigned i = 1; i <= TF(1,1).getNumSize(); ++i)
        C(1,i) = TF(1,1).getNum()(1, TF(1,1).getNumSize() - i + 1);

    for (unsigned i = 1; i <= A.getNumberOfColumns(); ++i)
        C(1,i) = C(1,i) - (TF(1,1).getDen()(1, TFdenCols + 2 - i))* D(1,1);


    if(!TF.isContinuous())
    {
        return ModelHandler::StateSpace<Type>(A,B,C,D,TF.getSampleTime());
    }

    return ModelHandler::StateSpace<Type>(A,B,C,D);
}

template <typename Type>
ModelHandler::ARX<Type> ModelHandler::tf2arxSISO(const ModelHandler::TransferFunction<Type> &TF, const Type &step)
{
    ModelHandler::TransferFunction<Type> TFd;
    if(TF.isContinuous())
        TFd = ModelHandler::c2d(TF, step);
    else
        TFd = TF;

    unsigned inputSize  = TFd(1,1).getNum().getNumberOfColumns();
    unsigned outputSize = TFd(1,1).getDen().getNumberOfColumns();

    ModelHandler::ARX<Type> arx(outputSize-1,inputSize,0,1,1,step);
    LinAlg::Matrix<Type> ModelCoef = (TFd(1,1).getDen()(1,from(2)-->outputSize))|TFd(1,1).getNum();
    arx.setModelCoef(~ModelCoef);

    return arx;
}

//template <typename Type>
//ModelHandler::ARX<Type> ModelHandler::tf2arx(const ModelHandler::TransferFunction<Type> &TF, const Type &step)
//{
//    unsigned maxInputDelay  = 0;
//    unsigned maxOutputDelay = 0;
//    for(unsigned i = 1; i <= TF.getNumberOfRows(); ++i)
//    {
//        for(unsigned j = 1; j <= TF.getNumberOfColumns(); ++j)
//        {
//            ModelHandler::TransferFunction<Type> TFd;
//            if(TF.isContinuous())
//                TFd = ModelHandler::c2d(ModelHandler::TransferFunction<Type>(TF(i,j)), step);
//            else
//                TFd = TF(i,j);

//            if(TFd(1,1).getNum().getNumberOfColumns() > maxInputDelay)
//                maxInputDelay = TFd(1,1).getNum().getNumberOfColumns();
//            if(TFd(1,1).getDen().getNumberOfColumns() > maxOutputDelay)
//                maxOutputDelay = TFd(1,1).getDen().getNumberOfColumns()-1;
//        }
//    }
//    LinAlg::Matrix<Type> ModelCoef = LinAlg::Zeros<Type>(TF.getNumberOfRows(), TF.getNumberOfColumns()*(maxInputDelay+maxOutputDelay));

//    for(unsigned i = 1; i <= TF.getNumberOfRows(); ++i)
//    {
//        for(unsigned j = 1; j <= TF.getNumberOfColumns(); ++j)
//        {
//            ModelHandler::ARX<Type> arx = ModelHandler::tf2arxSISO(ModelHandler::TransferFunction<Type>(TF(i,j)), step);
//            LinAlg::Matrix<Type> tempModelCoef      = ~arx.getModelCoef();
//            for(unsigned k = 1; k <= maxOutputDelay; ++k)
//            {
//                ModelCoef(i,(j-1)*(maxOutputDelay+maxInputDelay)+k) = tempModelCoef(1,k);
//            }
//            for(unsigned k = 0; k <= maxInputDelay; ++k)
//            {
//                ModelCoef(i,(j-1)*(maxOutputDelay+maxInputDelay)+maxOutputDelay+k) = tempModelCoef(1,k+maxOutputDelay);
//            }
//        }
//    }
//    ModelHandler::ARX<Type> ret(maxOutputDelay,maxOutputDelay,0,TF.getNumberOfColumns(),TF.getNumberOfRows());
//    ret.setModelCoef(~ModelCoef);
//    return ret;
//}

template <typename Type>
ModelHandler::StateSpace<Type> ModelHandler::c2d(const ModelHandler::StateSpace<Type> &SS, Type SampleTime)
{
    ModelHandler::StateSpace<Type> ret = SS;
    ret.setSampleTime(SampleTime);
    ret.c2dConversion();
    ret.setContinuous(false);
    ret.setInitialState(SS.getActualState());
    return ret;
}

template<typename Type>
ModelHandler::TransferFunction<Type> ModelHandler::c2d(const TransferFunction<Type>& TF, Type sampleTime)
{
    StateSpace<Type> SS = tf2ss(TF);
//    std::cout << SS;
    SS = ModelHandler::c2d(SS, sampleTime);
//    std::cout << SS;
    TransferFunction<Type> TFr = ModelHandler::ss2tf(SS);

//    std::cout << TFr << std::endl;
    TFr.setContinuous(false);
    return TFr;
}


template <typename Type>
ModelHandler::StateSpace<Type> ModelHandler::d2c(const ModelHandler::StateSpace<Type> &discreteSS)
{
    ModelHandler::StateSpace<Type> ret = discreteSS;
    ret.d2cConversion();
    ret.setContinuous(true);
    return ret;
}

template<typename Type> //ok
ModelHandler::StateSpace<Type> ModelHandler::integrativeModel(const ModelHandler::StateSpace<Type> &SS)
{
    ModelHandler::StateSpace<Type> SSI;
    SSI.setContinuous(SS.isContinuous());
    if(SSI.isContinuous())
    {
        SSI.setA(LinAlg::Zeros<Type>(SS.getC().getNumberOfRows()+SS.getA().getNumberOfRows(),1)|(SS.getC()||SS.getA()));

        SSI.setB((LinAlg::Zeros<Type>(SS.getC().getNumberOfRows()+SS.getB().getNumberOfColumns()-1,1)||SS.getB()));
        //Retirado da apostila de meneghet
    }else{
        SSI.setA(( SS.getA()            | LinAlg::Zeros<Type>(SS.getA().getNumberOfRows(),SS.getC().getNumberOfRows()))
                || ((SS.getC()*SS.getA()) | LinAlg::Eye<Type>  (SS.getC().getNumberOfRows())));
//        Ba = [B; C*B];
        SSI.setB((SS.getB() || SS.getC()*SS.getB()));
    }

    SSI.setC((LinAlg::Zeros<Type>(SS.getC().getNumberOfRows(),SS.getA().getNumberOfColumns()) | LinAlg::Eye<Type>(SS.getC().getNumberOfRows())));
    SSI.setD(SS.getD());

    SSI.setSampleTime(SS.getSampleTime());
    SSI.setInitialState(LinAlg::Zeros<Type>(SSI.getA().getNumberOfRows(),1));
    SSI.setObserverParameters((LinAlg::Zeros<Type>(SSI.getA().getNumberOfRows(),1)));

    SSI.setTimeSimulation(SS.getTimeSimulation());

    return SSI;
}

template<typename Type> //ok
ModelHandler::StateSpace<Type> ModelHandler::predictionModel(const ModelHandler::StateSpace<Type> &SS_SSI,
                                                             const unsigned &minPredictionHorizon,
                                                             const unsigned &maxPredictionHorizon,
                                                             const unsigned &controlHorizon)
{
    ModelHandler::StateSpace<Type> SSP;
    SSP.setContinuous(SS_SSI.isContinuous());
    SSP.setControlHorizon(controlHorizon);
    SSP.setMinPredictionHorizon(minPredictionHorizon);
    SSP.setMaxPredictionHorizon(maxPredictionHorizon);

    if(SSP.isContinuous())
    {

    }else{

        for(unsigned i = minPredictionHorizon; i <= maxPredictionHorizon; ++i)
            SSP.setA((SSP.getA() || SS_SSI.getA()^i));

        for(unsigned j = 0; j <= controlHorizon - 1; ++j)
        {
            LinAlg::Matrix<Type> Btemp = LinAlg::Zeros<Type>(j*SS_SSI.getB().getNumberOfRows(),
                                                               SS_SSI.getB().getNumberOfColumns());

            for(unsigned i = minPredictionHorizon - 1 + j;  i <= maxPredictionHorizon - 1; ++i)
                Btemp = (Btemp || (SS_SSI.getA()^i)*SS_SSI.getB());

            SSP.setB(SSP.getB() | Btemp);
        }

        LinAlg::Matrix<Type> zerosC = LinAlg::Zeros<Type>(SS_SSI.getC().getNumberOfRows(), SS_SSI.getC().getNumberOfColumns());

        for(unsigned i = minPredictionHorizon; i <= maxPredictionHorizon; ++i)
        {
            LinAlg::Matrix<Type> Ctemp;
            for(unsigned j = minPredictionHorizon; j <= maxPredictionHorizon; ++j)
            {
                if(i == j)
                {
                    Ctemp = (Ctemp || SS_SSI.getC());
                }else
                {
                    Ctemp = (Ctemp || zerosC);
                }
            }
            SSP.setC(SSP.getC() | Ctemp);
        }
    }

    SSP.setD(SS_SSI.getD());

    SSP.setSampleTime(SS_SSI.getSampleTime());
    SSP.setInitialState(LinAlg::Zeros<Type>(SSP.getA().getNumberOfRows(),1));
    SSP.setObserverParameters((LinAlg::Zeros<Type>(SSP.getA().getNumberOfRows(),1)));
    SSP.setTimeSimulation(SS_SSI.getTimeSimulation());

    return SSP;
}
