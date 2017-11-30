#ifndef __PSO_H_INCLUDED
#define __PSO_H_INCLUDED
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/linalg.h"

template <class UsedType>
class PSO
{
private:
    bool MinMax;
    int varNum, PopSize, GenSize;
    double phi1, phi2, omega, Stime;
    LinAlg::Matrix<UsedType> V, X, P, G, GGen, GnTimes,
                     Xfitness, Pfitness, Gfitness,
                     GfitnessGen, GfitnessnTime, RunTime, garra;
//    Model<UsedType> *model;


    LinAlg::Matrix<UsedType> Evaluation(LinAlg::Matrix<UsedType> Matrix2Evaluate);
    void ParticleUpdate();
    void ParticleEvaluation();
    void VelocityUpdate();
    void initAlgorithm();
    void FitnessUpdate();
    void FitnessUpdateMin();
    void FitnessUpdateMax();



public:
    PSO();
    PSO(int    varNum, int PopSize, int GenSize);
    PSO(int    varNum, int PopSize, int GenSize,
        double           phi1 , double phi2);
    PSO(int    varNum, int    PopSize, int  GenSize,
        double           phi1 , double phi2  , double omega  , bool MinMax);
//    ~PSO();

    LinAlg::Matrix<UsedType> Optimize(LinAlg::Matrix<UsedType> garra, LinAlg::Matrix<UsedType> gBest = UsedType(0.0) );
    void Run(int nTimes);

    void SetPopSize(int p);
    void SetGenSize(int p);
    void SetPhi1(double p);
    void SetPhi2(double p);
};

#include "SistemasdeControle/src/optimizationLibs/pso.hpp"
#endif // PSO_H
