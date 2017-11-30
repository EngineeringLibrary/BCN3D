#include "SistemasdeControle/headers/optimizationLibs/pso.h"

template <class UsedType>
PSO<UsedType>::PSO()
{
    //As únicas funções que vão lhe importar são essa e Evaluation
    this->varNum  = 5; // Aqui você vai colocar a quantidade de ângulos que deseja encontrar na cinemática inversa
    this->PopSize = 100;// esse é um parâmetro de ajuste, é como se o algoritmo fosse procurar a solução em paralelo;
    // quanto maior esse parâmetro, maior será o custo computacional
    this->GenSize = 1000;//esse é um parâmetro de ajuste, ele representa quantas vezes o algoritmo vai procurar pela solução
    // quanto maior esse parâmetro, maior será o custo computacional
    this->phi1    = 2.5;//Esse é outro parâmetro de ajuste, porém não influencia no custo computacional,
    //por isso, se a solução não estiver boa, sugiro mexer nesse parâmetro ou no próximo
    this->phi2    = 2.5;//Esse é outro parâmetro de ajuste, porém não influencia no custo computacional,
    //por isso, se a solução não estiver boa, sugiro mexer nesse parâmetro ou no anterior
    this->omega   = 1; //Esse é outro parâmetro de ajuste, também não interfere no custo computacional, pode ser ajustado,
    //mas sugiro fazer isso em phi1 e phi2.
    this->MinMax  = false;
    srand((time(NULL)));
    //Agora vá para Evaluation, linha 77
}

template <class UsedType>
PSO<UsedType>::PSO(int varNum, int PopSize, int GenSize)
{
    this->varNum  = varNum;
    this->PopSize = PopSize;
    this->GenSize = GenSize;
    this->phi1    = 1;
    this->phi2    = 1;
    this->omega   = 1;
    this->MinMax  = false;
    srand((time(NULL)));
}

template <class UsedType>
PSO<UsedType>::PSO(int varNum, int PopSize, int GenSize, double phi1, double phi2)
{
    this->varNum  = varNum;
    this->PopSize = PopSize;
    this->GenSize = GenSize;
    this->phi1    = phi1;
    this->phi2    = phi2;
    this->omega   = 1;
    this->MinMax  = false;
    srand((time(NULL)));
}

template <class UsedType>
PSO<UsedType>::PSO(int    varNum , int PopSize, int GenSize, double phi1, double phi2, double omega, bool MinMax)
{
    this->varNum  = varNum;
    this->PopSize = PopSize;
    this->GenSize = GenSize;
    this->phi1    = phi1;
    this->phi2    = phi2;
    this->omega   = omega;
    this->MinMax  = MinMax;
    srand((time(NULL)));
}

template <class UsedType>
void PSO<UsedType>::initAlgorithm()
{
    this->X = LinAlg::Random<UsedType>(this->PopSize, this->varNum)*2*M_PI;
    this->V = LinAlg::Random<UsedType>(this->PopSize, this->varNum)*0.1;
    this->P = this->X;
    this->G = LinAlg::Random<UsedType>(1, this->varNum);
    this->Xfitness = Evaluation(this->X);
    this->Gfitness = Evaluation(this->G);
    this->Pfitness = this->Xfitness;
    srand((time(NULL)));

}

template <class UsedType>
LinAlg::Matrix<UsedType> PSO<UsedType>::Evaluation(LinAlg::Matrix<UsedType> Matrix2Evaluate)
{
    LinAlg::Matrix<UsedType> ret(Matrix2Evaluate.getNumberOfRows(),1);
    for(unsigned i = 1; i <= Matrix2Evaluate.getNumberOfRows(); ++i)
    {
        // Este é um exemplo simples de como deve ser implementada a função:
        //Primeiramente você deve calcular os valores de x, y e z.
        //Depois, deve elevar esses valores ao quadrado e somar(x^2+y^2+z^2)
        //Como os ângulos podem ser infinitos você tem duas opções:
        //Ou normaliza os ângulos de 0 a 360° (1), ou utiliza os valores dos ângulos para forçar o parâmetro a não aumentar(2)
        //Sugiro normalizar, ou seja, optar pela solução (1)
        //OBS: não testei o código da solução (1), porque acabei de pensar nela, kkkk

        double O1 = Matrix2Evaluate(i,1), O2 = Matrix2Evaluate(i,2), O3 = Matrix2Evaluate(i,3), O4 = Matrix2Evaluate(i,4), O5 = Matrix2Evaluate(i,5);


        double x = garra(1,1) - (10*cos(O5)*(cos(O1)*cos(O2)*sin(O3) + cos(O1)*cos(O3)*sin(O2)) + 24*cos(O1)*cos(O2) + 10*sin(O5)*(cos(O4)*(cos(O1)*cos(O2)*cos(O3) - cos(O1)*sin(O2)*sin(O3)) + sin(O1)*sin(O4)) + 14*cos(O1)*cos(O2)*sin(O3) + 14*cos(O1)*cos(O3)*sin(O2));
        double y = garra(1,2) - (10*cos(O5)*(cos(O2)*sin(O1)*sin(O3) + cos(O3)*sin(O1)*sin(O2)) + 24*cos(O2)*sin(O1) + 10*sin(O5)*(cos(O4)*(cos(O2)*cos(O3)*sin(O1) - sin(O1)*sin(O2)*sin(O3)) - cos(O1)*sin(O4)) + 14*cos(O2)*sin(O1)*sin(O3) + 14*cos(O3)*sin(O1)*sin(O2));
        double z = garra(1,3) - (24*sin(O2) - 14*cos(O2 + O3) + 5*sin(O2 + O3)*sin(O4 + O5) - 10*cos(O2 + O3)*cos(O5) - 5*sin(O2 + O3)*sin(O4 - O5) + 8);

        //        double x = cos(Matrix2Evaluate(i,1)); //= cos(theta1)
        //        double y = sin(Matrix2Evaluate(i,2)); //= sen(theta2)


        ret(i,1) = 100*(x*x + y*y + z*z);//(1)

        //        ret(i,1) = x*x + y*y + Matrix2Evaluate(i,1)*Matrix2Evaluate(i,1) + Matrix2Evaluate(i,2)*Matrix2Evaluate(i,2);//(2)
    }

    return ret;
}

template <class UsedType>
void PSO<UsedType>::ParticleUpdate()
{
    this->X = this->X + this->V;
    for(unsigned i = 1; i <= this->X.getNumberOfRows();++i){
        // 0 < Theta1 < 90
        if(this->X(i,1) > M_PI/2)
            this->X(i,1) = (M_PI/4)*rand()/RAND_MAX + M_PI/4;
        else if (this->X(i,1) < 0)
            this->X(i,1) = (M_PI/4)*rand()/RAND_MAX;

        // 0 < Theta4 < 120
        if(this->X(i,2) > ((2*M_PI)/3))
            this->X(i,2) = ((2*M_PI)/6)*rand()/RAND_MAX + ((2*M_PI)/6);
        else if (this->X(i,2) < 0)
            this->X(i,2) = ((2*M_PI)/6)*rand()/RAND_MAX;

        // 0 < Theta4 < 120
        if(this->X(i,3) > ((2*M_PI)/3))
            this->X(i,3) = ((2*M_PI)/6)*rand()/RAND_MAX + ((2*M_PI)/6);
        else if (this->X(i,3) < 0)
            this->X(i,3) = ((2*M_PI)/6)*rand()/RAND_MAX;

        // 0 < Theta4 < 360
        if(this->X(i,4) > 2*M_PI)
            this->X(i,4) = M_PI*rand()/RAND_MAX + M_PI;
        else if (this->X(i,4) < 0)
            this->X(i,4) = M_PI*rand()/RAND_MAX;

        // 0 < Theta5 < 90
        if(this->X(i,5) > M_PI/2)
            this->X(i,5) = (M_PI/4)*rand()/RAND_MAX + M_PI/2;
        else if (this->X(i,5) < 0)
            this->X(i,5) = (M_PI/4)*rand()/RAND_MAX;

    }

    //        for(unsigned j = 1; j <= this->X.getNumberOfColumns(); ++j)
    //            if(this->X(i,j) > 2*M_PI)
    //                this->X(i,j) = M_PI*rand()/RAND_MAX + M_PI;
    //            else if (this->X(i,j) < 0)
    //                this->X(i,j) = M_PI*rand()/RAND_MAX;
}

template <class UsedType>
void PSO<UsedType>::VelocityUpdate()
{
    double Rand1, Rand2;

    for(unsigned i = 1; i <= this->PopSize; i++)
        for(unsigned j = 1; j <= this->varNum; j++)
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
LinAlg::Matrix<UsedType> PSO<UsedType>::Optimize(LinAlg::Matrix<UsedType> garra, LinAlg::Matrix<UsedType> gBest)
{

    this->garra = garra;
    initAlgorithm();
    if (gBest(1,1) != 0 && gBest.getNumberOfRows() != 1){
        this->X = (LinAlg::Random<UsedType>(this->PopSize, this->varNum)-0.5)*0.005;
        for (unsigned i = 1; i <= this->PopSize; ++i)
            for(unsigned j = 1; j <= this->varNum; ++j)
                this->X(i,j) += gBest(1,j);
    }


    for(int i = 0; i < this->GenSize; i++)
    {
        VelocityUpdate();
        ParticleUpdate();
        this->Xfitness = Evaluation(this->X);
        FitnessUpdate();
    }
    return this->G;
}

template <class UsedType>
void PSO<UsedType>::Run(int nTimes)
{
    this->GnTimes = LinAlg::Zeros<UsedType>(nTimes, this->G.getNumberOfColumns());
    this->GfitnessnTime = LinAlg::Zeros<UsedType>(nTimes, 1);
    for (int i = 1; i <= nTimes; i++)
    {
        this->Optimize();
        this->GfitnessnTime(i, 1) = this->Gfitness(1,1);
        this->RunTime(i, 1) = this->Stime;
    }
}

template <class UsedType>
void PSO<UsedType>::SetPopSize(int p)
{
    this->PopSize = p;
}

template <class UsedType>
void PSO<UsedType>::SetGenSize(int p)
{
    this->GenSize = p;
}

template <class UsedType>
void PSO<UsedType>::SetPhi1(double p)
{
    this->phi1 = p;
}

template <class UsedType>
void PSO<UsedType>::SetPhi2(double p)
{
    this->phi2 = p;
}
