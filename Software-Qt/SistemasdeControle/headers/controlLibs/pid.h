#ifndef __PID_H_INCLUDED
#define __PID_H_INCLUDED

#include <cmath>
#ifdef testControl
    #include "../../../headers/modelLibs/transferfunction.h"
#else
    #include "SistemasdeControle/headers/modelLibs/transferfunction.h"
#endif

namespace ControlHandler{
    template <typename Type>
    class PID
    {
    private:
        bool checkUpLim, checkLowLim;
        Type Error, pastError, integralError, derivativeError, Step, kp, ki, kd, upperLimit, lowerLimit, PIDout;
//        Type K1, K2, K3;
//        LinAlg::Matrix<double> e;

        void errorLimitation();

        void intError();
        void difError();

    public:
        PID();
        PID(const LinAlg::Matrix<Type> &PIDsParameters);

        Type getSampleTime() const {return this->Step;}
        Type getErrorValue() const {return this->Error;}
        Type getDerivativeErrorValue() const {return this->derivativeError;}
        Type getIntegralErrorValue() const {return this->integralError;}
        LinAlg::Matrix<Type> getLimits() const;
        LinAlg::Matrix<Type> getParams() const;

        void setSampleTime(Type Time);
        void setLimits(Type upperLimit, Type lowerLimit);
        void setParams(Type kp, Type ki, Type kd);
        void setParams(const LinAlg::Matrix<Type> &PIDsParameters);

        Type OutputControl(Type Reference, Type SignalInput);
    };

    template<typename Type> // ok
    std::ostream& operator<< (std::ostream& output, ControlHandler::PID<Type> controller);
    template<typename Type> //ok
    std::string&  operator<< (std::string& output,  const ControlHandler::PID<Type> &controller);

    template <typename Type>
    PID<Type> tunningZieglerNichols(const ModelHandler::TransferFunction<Type> &FOPDT, const std::string &controllerType);
    template <typename Type>
    PID<Type> tunningCHRServo0OV(const ModelHandler::TransferFunction<Type> &FOPDT, const std::string &controllerType);
    template <typename Type>
    PID<Type> tunningCHRServo20OV(const ModelHandler::TransferFunction<Type> &FOPDT, const std::string &controllerType);
    template <typename Type>
    PID<Type> tunningCHRRegulatorio(const ModelHandler::TransferFunction<Type> &FOPDT, const std::string &controllerType);
    template <typename Type>
    PID<Type> tunningCohenCoon(const ModelHandler::TransferFunction<Type> &FOPDT, const std::string &controllerType);
    template <typename Type>
    PID<Type> tunningIAELopes(const ModelHandler::TransferFunction<Type> &FOPDT, const std::string &controllerType);
    template <typename Type>
    PID<Type> tunningITAELopes(const ModelHandler::TransferFunction<Type> &FOPDT, const std::string &controllerType);
    template <typename Type>
    PID<Type> tunningIAERovira(const ModelHandler::TransferFunction<Type> &FOPDT, const std::string &controllerType);
    template <typename Type>
    PID<Type> tunningITAERovira(const ModelHandler::TransferFunction<Type> &FOPDT, const std::string &controllerType);
    template <typename Type>
    PID<Type> tunningIMC(const ModelHandler::TransferFunction<Type> &FOPDT, const std::string &controllerType, const Type &lambda);

}

#ifdef testControl
    #include "../../../src/controlLibs/pid.hpp"
#else
    #include "SistemasdeControle/src/controlLibs/pid.hpp"
#endif

#endif // PID_H
