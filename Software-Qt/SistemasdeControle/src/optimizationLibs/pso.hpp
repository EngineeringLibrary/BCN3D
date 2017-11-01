#include "SistemasdeControle/headers/optimizationLibs/pso.h"
//#include <ctime>

template <class UsedType>
PSO<UsedType>::PSO(Model<UsedType> *model)
{
    this->model   = model;
    this->varNum  = 1;
    this->PopSize = 80;
    this->GenSize = 2000;
    this->phi1    = 1;
    this->phi2    = 1;
    this->omega   = 1;
    this->MinMax  = false;
}

template <class UsedType>
PSO<UsedType>::PSO(Model<UsedType> *model  , int varNum,
                   int              PopSize, int GenSize)
{
    this->model   = model;
    this->varNum  = varNum;
    this->PopSize = PopSize;
    this->GenSize = GenSize;
    this->phi1    = 1;
    this->phi2    = 1;
    this->omega   = 1;
    this->MinMax  = false;
}

template <class UsedType>
PSO<UsedType>::PSO(Model<UsedType> *model, int varNum,
                   int    PopSize        , int GenSize,
                   double phi1           , double phi2)
{
    this->model   = model;
    this->varNum  = varNum;
    this->PopSize = PopSize;
    this->GenSize = GenSize;
    this->phi1    = phi1;
    this->phi2    = phi2;
    this->omega   = 1;
    this->MinMax  = false;
}

template <class UsedType>
PSO<UsedType>::PSO(Model<UsedType> *model  , int    varNum ,
                   int              PopSize, int    GenSize,
                   double           phi1   , double phi2   ,
                   double           omega  , bool   MinMax)
{
    this->model   = model;
    this->varNum  = varNum;
    this->PopSize = PopSize;
    this->GenSize = GenSize;
    this->phi1    = phi1;
    this->phi2    = phi2;
    this->omega   = omega;
    this->MinMax  = MinMax;
}

template <class UsedType>
PSO<UsedType>::~PSO()
{

}

template <class UsedType>
void PSO<UsedType>::initAlgorithm()
{
//    this->X.randU(this->PopSize, this->varNum);
//    X.print();
    this->X = this->X*(4.0)-2.0;
//    this->V.randU(this->PopSize, this->varNum);
    this->P = this->X;
//    this->G.randU(1, this->varNum);
    this->Xfitness = Evaluation(this->X);
//    Xfitness.print();
    this->Gfitness = Evaluation(this->G);
//    Gfitness.print();
    this->Pfitness = this->Xfitness;

}

template <class UsedType>
LinAlg::Matrix<UsedType> PSO<UsedType>::Evaluation(LinAlg::Matrix<UsedType> Matrix2Evaluate)
{
    LinAlg::Matrix<UsedType> ret(Matrix2Evaluate.getNumberOfRows(), 1);
    LinAlg::Matrix<UsedType> Y, Yest,Error;
    //TODO -> Tornar a função mais fléxivel.

    for(unsigned i = 1; i <= Matrix2Evaluate.getNumberOfRows(); i++)
    {
      model->setModelCoef(~Matrix2Evaluate.GetRow(i));
      Y = model->getOutputMatrix();
      Yest = model->sim(model->getInputMatrix());
      Error =  Y-Yest ;
      ret(i,1) = ((~Error)*Error)(1,1);
    }

    return ret;
}

template <class UsedType>
void PSO<UsedType>::ParticleUpdate()
{
    this->X = this->X + this->V;
}

template <class UsedType>
void PSO<UsedType>::VelocityUpdate()
{
//    srand((time(NULL)));
    double Rand1, Rand2;


    for(int i = 1; i <= this->PopSize; i++)
        for(int j = 1; j <= this->varNum; j++)
        {
            Rand1 = rand()*this->phi1/RAND_MAX;
            Rand2 = rand()*this->phi2/RAND_MAX;
            this->V(i, j) = (this->omega*this->V(i,j) + Rand1*(this->P(i,j) - this->X(i,j)) + Rand2*(this->G(1,j) - this->X(i,j)));
        }
}

template <class UsedType>
void PSO<UsedType>::ParticleEvaluation()
{
    this->Xfitness = Evaluation(this->X);
}

template <class UsedType>
void PSO<UsedType>::FitnessUpdate()
{
    if(this->MinMax == true)
        FitnessUpdateMax();
    else
        FitnessUpdateMin();
}

template <class UsedType>
void PSO<UsedType>::FitnessUpdateMin()
{
  for (int i = 1; i <= this->PopSize; i++)
  {
      if (this->Xfitness(i,1) < this->Pfitness(i,1))
      {
          this->Pfitness(i,1) = this->Xfitness(i,1);
          for(int j = 1; j <= this->varNum; j++)
            this->P(i, j) = this->X(i,j);
      }

      if (this->Pfitness(i,1) < this->Gfitness(1,1))
      {
          this->Gfitness(1,1) = this->Pfitness(i,1);
          for(int j = 1; j <= this->varNum; j++)
            this->G(1, j) = this->P(i,j);
      }
  }
}

template <class UsedType>
void PSO<UsedType>::FitnessUpdateMax()
{
    for (int i = 1; i <= this->PopSize; i++)
    {
        if (this->Xfitness(i,1) > this->Pfitness(i,1))
        {
            this->Pfitness(i,1) = this->Xfitness(i,1);
            for(int j = 1; j <= this->varNum; j++)
              this->P(i, j) = this->X(i,j);
        }

        if (this->Pfitness(i,1) > this->Gfitness(1,1))
        {
            this->Gfitness(1,1) = this->Pfitness(i,1);
            for(int j = 1; j <= this->varNum; j++)
                this->G(1, j) = this->P(i,j);
        }
    }
}

template <class UsedType>
void PSO<UsedType>::Optimize()
{
//    clock_t start, stop;


    initAlgorithm();

    for(int i = 0; i < this->GenSize; i++)
    {
        VelocityUpdate();
        ParticleUpdate();

//        start = clock();
        this->Xfitness = Evaluation(this->X);
//        stop = clock();
//        this->Stime = (double) (stop-start)/CLOCKS_PER_SEC;
//        cout << this->Stime << endl;

        FitnessUpdate();
//        Gfitness.print();
//        this->GGen = this->GGen||this->G; // função lenta
//        this->GfitnessGen = this->GfitnessnTime||this->Gfitness; // função lenta
    }
    this->OptimizatedVariable = this->G;
//    return this->G;

}

template <class UsedType>
void PSO<UsedType>::Run(int nTimes)
{
    this->GnTimes = LinAlg::Zeros<UsedType>(nTimes, this->G.getNumberOfColumns());
    this->GfitnessnTime = LinAlg::Zeros<UsedType>(nTimes, 1);
    for (int i = 1; i <= nTimes; i++)
    {
        this->Optimize();
//        this->GnTimes = this->GnTimes||this->G;
        this->GfitnessnTime(i, 1) = this->Gfitness(1,1);
        this->RunTime(i, 1) = this->Stime;
//        this->Gfitness.print();
//        this->G.print();
    }

//    this->GfitnessnTime.print();
}

template <class UsedType>
void PSO<UsedType>::setData(LinAlg::Matrix<UsedType> dataIn, LinAlg::Matrix<UsedType> dataOut)
{
    this->model->setIO(dataIn, dataOut);
}

template <class UsedType>
double PSO<UsedType>::getTime()
{
    return this->Stime;
}

//template class PSO<int>;
template class PSO<float>;
template class PSO<double>;
