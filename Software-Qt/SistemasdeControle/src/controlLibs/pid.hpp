#ifdef testControl
    #include "../../../headers/controlLibs/pid.h"
#else
    #include "SistemasdeControle/headers/controlLibs/pid.h"
#endif

template<typename Type>
ControlHandler::PID<Type>::PID()
{
    this->kd = 0;
    this->ki = 0;
    this->kp = 0;

    this->Error = 0;
    this->derivativeError = 0;
    this->pastError = 0;
    this->integralError = 0;

    this->Step = 0.1;
    this->upperLimit = 200;
    this->lowerLimit = -200;

    //------------
//    e = LinAlg::Matrix<Type>(1,3);
}

template<typename Type>
ControlHandler::PID<Type>::PID(const LinAlg::Matrix<Type> &PIDsParameters)
{
    this->kp = PIDsParameters(1,1);
    this->ki = PIDsParameters(1,2);
    this->kd = PIDsParameters(1,3);

    this->Error = 0;
    this->derivativeError = 0;
    this->pastError = 0;
    this->integralError = 0;

    this->Step = 0.1;
    this->upperLimit = 200;
    this->lowerLimit = -200;
}

template<typename Type>
void ControlHandler::PID<Type>::errorLimitation()
{
    if(this->PIDout >= this->upperLimit)
    {
        this->checkUpLim = true;
        this->PIDout = this->upperLimit;
    }
    else
        this->checkUpLim = false;

    if(this->PIDout <= this->lowerLimit)
    {
        this->checkLowLim = true;
        this->PIDout = this->lowerLimit;
    }
    else
        this->checkLowLim = false;
}

template<typename Type>
void ControlHandler::PID<Type>::intError()
{
    this->errorLimitation();

    if(!this->checkUpLim && !this->checkLowLim)
        this->integralError += this->Error*this->Step;
}

template<typename Type>
void ControlHandler::PID<Type>::difError()
{
    this->derivativeError = ((this->Error - this->pastError)/this->Step);
    this->pastError = this->Error;
}

template<typename Type>
void ControlHandler::PID<Type>::setLimits(Type lowerLimit, Type upperLimit)
{
    this->upperLimit = upperLimit;
    this->lowerLimit = lowerLimit;
}

template<typename Type>
void ControlHandler::PID<Type>::setSampleTime(Type Time)
{
    this->Step = Time;
}

template<typename Type>
void ControlHandler::PID<Type>::setParams(Type kp, Type ki, Type kd)
{
    this->kp = kp;
    this->ki = ki;
    this->kd = kd;
}

template<typename Type>
void ControlHandler::PID<Type>::setParams(const LinAlg::Matrix<Type> &PIDsParameters)
{
    this->kp = PIDsParameters(1,1);
    this->ki = PIDsParameters(1,2);
    this->kd = PIDsParameters(1,3);
}

template<typename Type>
Type ControlHandler::PID<Type>::OutputControl(Type Reference, Type SignalInput)
{
    this->Error = Reference - SignalInput;

    difError();
    intError();
    this->PIDout = (this->kp*this->Error + this->ki*this->integralError + this->kd*this->derivativeError);
    errorLimitation();

//    e.removeColumn(3);
//    e = LinAlg::Matrix<Type>(this->Error)|e;
//    K1 = kp + this->Step*ki + kd/this->Step;
//    K2 = -kp - 2*kd/this->Step;
//    K3 = kd/this->Step;
//    this->PIDout = this->PIDout + (K1*e(1,1) + K2*e(1,2) + K3*e(1,3));
    return this->PIDout;
}

template<typename Type>
LinAlg::Matrix<Type> ControlHandler::PID<Type>::getLimits() const
{
    LinAlg::Matrix<Type> limits(1,2);

    limits(1,1) = this->lowerLimit;
    limits(1,2) = this->upperLimit;

    return limits;
}

template<typename Type>
LinAlg::Matrix<Type> ControlHandler::PID<Type>::getParams() const
{
    LinAlg::Matrix<Type> params(1,3);

    params(1,1) = this->kp;
    params(1,2) = this->ki;
    params(1,3) = this->kd;

    return params;
}

template<typename Type> // ok
std::ostream& ControlHandler::operator<< (std::ostream& output, ControlHandler::PID<Type> controller)
{
    std::string str; str << controller;
    output << str;
    return output;
}
#include <string>
template<typename Type> //ok
std::string&  ControlHandler::operator<< (std::string& output,  const ControlHandler::PID<Type> &controller)
{
    LinAlg::Matrix<Type> parameters = controller.getParams();

    output = "U(s) = ";
    if(parameters(1,1) != 0)
    {
        std::stringstream ss;
        if(parameters(1,1) != 1)
        {
            ss << parameters(1,1);
            output += ss.str();
        }
        output += " E(s)";
    }
    if(parameters(1,2) != 0)
    {
        output += " + ";
        std::stringstream ss;
        if(parameters(1,2) != 1)
        {
            ss << parameters(1,2);
            output += ss.str();
        }
        output += " (E(s)/s)";
    }
    if(parameters(1,3) != 0)
    {
        output += " + ";
        std::stringstream ss;
        if(parameters(1,3) != 1)
        {
            ss << parameters(1,3);
            output += ss.str();
        }
        output += " s E(s) ";
    }
    return output;
}

template <typename Type>
ControlHandler::PID<Type> ControlHandler::tunningZieglerNichols(const ModelHandler::TransferFunction<Type> &FOPDT, const std::string &controllerType)
{
    LinAlg::Matrix<Type> num = FOPDT(1,1).getNum();
    LinAlg::Matrix<Type> den = FOPDT(1,1).getDen();
    num /= den(1,2);
    den /= den(1,2);
    Type tau = den(1,1), K = num(1,1), theta = FOPDT.getTransportDelay();

    ControlHandler::PID<Type> controller;
    controller.setSampleTime(FOPDT.getSampleTime());
    if(controllerType == "P")
    {
        Type Kp = tau/(K*theta);
        controller.setParams(Kp,0.0,0.0);
    }
    else if(controllerType == "PI")
    {
        Type Kp = 0.9*tau/(K*theta);
        controller.setParams(Kp,Kp/(3.33*theta),0.0);
    }
    else if(controllerType == "PID")
    {
        Type Kp = 1.2*tau/(K*theta);
        controller.setParams(Kp,Kp/(2*theta),Kp*0.5*theta);
    }
    else
        std::cout << "Controlador nao encontrado" << std::endl;
    return controller;
}

template <typename Type>
ControlHandler::PID<Type> ControlHandler::tunningCHRServo0OV(const ModelHandler::TransferFunction<Type> &FOPDT, const std::string &controllerType)
{
    LinAlg::Matrix<Type> num = FOPDT(1,1).getNum();
    LinAlg::Matrix<Type> den = FOPDT(1,1).getDen();
    num /= den(1,2);
    den /= den(1,2);
    Type tau = den(1,1), K = num(1,1), theta = FOPDT.getTransportDelay();

    ControlHandler::PID<Type> controller;
    controller.setSampleTime(FOPDT.getSampleTime());
    if(controllerType == "P")
    {
        Type Kp = 0.3*tau/(K*theta);
        controller.setParams(Kp,0.0,0.0);
    }
    else if(controllerType == "PI")
    {
        Type Kp = 0.35*tau/(K*theta);
        controller.setParams(Kp,Kp/(1.16*tau),0.0);
    }
    else if(controllerType == "PID")
    {
        Type Kp = 1.2*tau/(K*theta);
        controller.setParams(Kp,Kp/tau,Kp*0.5*theta);
    }
    else
        std::cout << "Controlador nao encontrado" << std::endl;
    return controller;
}

template <typename Type>
ControlHandler::PID<Type> ControlHandler::tunningCHRServo20OV(const ModelHandler::TransferFunction<Type> &FOPDT, const std::string &controllerType)
{
    LinAlg::Matrix<Type> num = FOPDT(1,1).getNum();
    LinAlg::Matrix<Type> den = FOPDT(1,1).getDen();
    num /= den(1,2);
    den /= den(1,2);
    Type tau = den(1,1), K = num(1,1), theta = FOPDT.getTransportDelay();

    ControlHandler::PID<Type> controller;
    controller.setSampleTime(FOPDT.getSampleTime());
    if(controllerType == "P")
    {
        Type Kp = 0.7*tau/(K*theta);
        controller.setParams(Kp,0.0,0.0);
    }
    else if(controllerType == "PI")
    {
        Type Kp = 0.6*tau/(K*theta);
        controller.setParams(Kp,Kp/(tau),0.0);
    }
    else if(controllerType == "PID")
    {
        Type Kp = 0.95*tau/(K*theta);
        controller.setParams(Kp,Kp/(1.357*tau),Kp*0.473*theta);
    }
    else
        std::cout << "Controlador nao encontrado" << std::endl;
    return controller;
}

template <typename Type>
ControlHandler::PID<Type> ControlHandler::tunningCHRRegulatorio(const ModelHandler::TransferFunction<Type> &FOPDT, const std::string &controllerType)
{
    LinAlg::Matrix<Type> num = FOPDT(1,1).getNum();
    LinAlg::Matrix<Type> den = FOPDT(1,1).getDen();
    num /= den(1,2);
    den /= den(1,2);
    Type tau = den(1,1), K = num(1,1), theta = FOPDT.getTransportDelay();

    ControlHandler::PID<Type> controller;
    controller.setSampleTime(FOPDT.getSampleTime());
    if(controllerType == "P")
    {
        Type Kp = 0.3*tau/(K*theta);
        controller.setParams(Kp,0.0,0.0);
    }
    else if(controllerType == "PI")
    {
        Type Kp = 0.6*tau/(K*theta);
        controller.setParams(Kp,Kp/(4*theta),0.0);
    }
    else if(controllerType == "PID")
    {
        Type Kp = 1.2*tau/(K*theta);
        controller.setParams(Kp,Kp/(2.375*theta),Kp*0.421*theta);
    }
    else
        std::cout << "Controlador nao encontrado" << std::endl;
    return controller;
}

template <typename Type>
ControlHandler::PID<Type> ControlHandler::tunningCohenCoon(const ModelHandler::TransferFunction<Type> &FOPDT, const std::string &controllerType)
{
    LinAlg::Matrix<Type> num = FOPDT(1,1).getNum();
    LinAlg::Matrix<Type> den = FOPDT(1,1).getDen();
    num /= den(1,2);
    den /= den(1,2);
    Type tau = den(1,1), K = num(1,1), theta = FOPDT.getTransportDelay();

    ControlHandler::PID<Type> controller;
    controller.setSampleTime(FOPDT.getSampleTime());
    if(controllerType == "P")
    {
        Type Kp = (1.03+0.35*tau/theta)*(tau/(K*theta));
        controller.setParams(Kp,0.0,0.0);
    }
    else if(controllerType == "PI")
    {
        Type Kp = (0.9+0.083*tau/theta)*(tau/(K*theta));
        Type Ti = ((0.9+0.083*tau/theta)/(1.27+0.6*(tau/theta)))*theta;
        controller.setParams(Kp,Kp/Ti,0.0);
    }
    else if(controllerType == "PID")
    {
        Type Kp = (1.35+0.25*tau/theta)*(tau/(K*theta));
        Type Ti = ((1.35+0.25*tau/theta)/(0.54+0.6*(tau/theta)))*theta;
        Type Td = ((0.5*theta)/(1.35+0.25*(theta/tau)));
        controller.setParams(Kp,Kp/Ti,Kp*Td);
    }
    else
        std::cout << "Controlador nao encontrado" << std::endl;
    return controller;
}

template <typename Type>
ControlHandler::PID<Type> ControlHandler::tunningIAELopes(const ModelHandler::TransferFunction<Type> &FOPDT, const std::string &controllerType)
{
    LinAlg::Matrix<Type> num = FOPDT(1,1).getNum();
    LinAlg::Matrix<Type> den = FOPDT(1,1).getDen();
    num /= den(1,2);
    den /= den(1,2);
    Type tau = den(1,1), K = num(1,1), theta = FOPDT.getTransportDelay();

    ControlHandler::PID<Type> controller;
    controller.setSampleTime(theta);
    if(controllerType == "PI")
    {
        Type Kp = ((0.984/K)*pow(tau/theta,0.986));
        Type Ti = tau/(0.608*pow(tau/theta,0.707));
        controller.setParams(Kp,Kp/Ti,0.0);
    }
    else if(controllerType == "PID")
    {
        Type Kp = ((1.435/K)*pow(tau/theta,0.921));
        Type Ti = tau/(0.878*pow(tau/theta,0.749));
        Type Td = tau*(0.482*pow(theta/tau,1.137));
        controller.setParams(Kp,Kp/Ti,Kp*Td);
    }
    else
        std::cout << "Controlador nao encontrado" << std::endl;
    return controller;
}

template <typename Type>
ControlHandler::PID<Type> ControlHandler::tunningITAELopes(const ModelHandler::TransferFunction<Type> &FOPDT, const std::string &controllerType)
{
    LinAlg::Matrix<Type> num = FOPDT(1,1).getNum();
    LinAlg::Matrix<Type> den = FOPDT(1,1).getDen();
    num /= den(1,2);
    den /= den(1,2);
    Type tau = den(1,1), K = num(1,1), theta = FOPDT.getTransportDelay();

    ControlHandler::PID<Type> controller;
    controller.setSampleTime(theta);
    if(controllerType == "PI")
    {
        Type Kp = ((0.959/K)*pow(tau/theta,0.977));
        Type Ti = tau/(0.674*pow(tau/theta,0.68));
        controller.setParams(Kp,Kp/Ti,0.0);
    }
    else if(controllerType == "PID")
    {
        Type Kp = ((1.357/K)*pow(tau/theta,0.947));
        Type Ti = tau/(0.842*pow(tau/theta,0.738));
        Type Td = tau*(0.381*pow(theta/tau,0.995));
        controller.setParams(Kp,Kp/Ti,Kp*Td);
    }
    else
        std::cout << "Controlador nao encontrado" << std::endl;
    return controller;
}

template <typename Type>
ControlHandler::PID<Type> ControlHandler::tunningIAERovira(const ModelHandler::TransferFunction<Type> &FOPDT, const std::string &controllerType)
{
    LinAlg::Matrix<Type> num = FOPDT(1,1).getNum();
    LinAlg::Matrix<Type> den = FOPDT(1,1).getDen();
    num /= den(1,2);
    den /= den(1,2);
    Type tau = den(1,1), K = num(1,1), theta = FOPDT.getTransportDelay();

    ControlHandler::PID<Type> controller;
    controller.setSampleTime(theta);
    if(controllerType == "PI")
    {
        Type Kp = ((0.758/K)*pow(tau/theta,0.861));
        Type Ti = tau/(1.02-0.323*(theta/tau));
        controller.setParams(Kp,Kp/Ti,0.0);
    }
    else if(controllerType == "PID")
    {
        Type Kp = ((1.086/K)*pow(tau/theta,0.869));
        Type Ti = tau/(0.74-0.130*(theta/tau));
        Type Td = tau*(0.348*pow(theta/tau,0.914));
        controller.setParams(Kp,Kp/Ti,Kp*Td);
    }
    else
        std::cout << "Controlador nao encontrado" << std::endl;
    return controller;
}

template <typename Type>
ControlHandler::PID<Type> ControlHandler::tunningITAERovira(const ModelHandler::TransferFunction<Type> &FOPDT, const std::string &controllerType)
{
    LinAlg::Matrix<Type> num = FOPDT(1,1).getNum();
    LinAlg::Matrix<Type> den = FOPDT(1,1).getDen();
    num /= den(1,2);
    den /= den(1,2);
    Type tau = den(1,1), K = num(1,1), theta = FOPDT.getTransportDelay();

    ControlHandler::PID<Type> controller;
    controller.setSampleTime(theta);
    if(controllerType == "PI")
    {
        Type Kp = ((0.586/K)*pow(tau/theta,0.916));
        Type Ti = tau/(1.03-0.165*(theta/tau));
        controller.setParams(Kp,Kp/Ti,0.0);
    }
    else if(controllerType == "PID")
    {
        Type Kp = ((0.965/K)*pow(tau/theta,0.850));
        Type Ti = tau/(0.796-0.147*(theta/tau));
        Type Td = tau*(0.308*pow(theta/tau,0.929));
        controller.setParams(Kp,Kp/Ti,Kp*Td);
    }
    else
        std::cout << "Controlador nao encontrado" << std::endl;
    return controller;
}

template <typename Type>
ControlHandler::PID<Type> ControlHandler::tunningIMC(const ModelHandler::TransferFunction<Type> &FOPDT, const std::string &controllerType, const Type &lambda)
{
    LinAlg::Matrix<Type> num = FOPDT(1,1).getNum();
    LinAlg::Matrix<Type> den = FOPDT(1,1).getDen();
    num /= den(1,2);
    den /= den(1,2);
    Type tau = den(1,1), K = num(1,1), theta = FOPDT.getTransportDelay();

    ControlHandler::PID<Type> controller;
    controller.setSampleTime(FOPDT.getSampleTime());

    if(controllerType == "PI")
    {
        if(lambda < 0.8*theta)
            std::cout << "Valor de lambda menor que o esperado" << std::endl;
        Type Kp = (2*tau+theta)/(2*K*lambda);
        Type Ti = tau+(theta/2);
        controller.setParams(Kp,Kp/Ti,0.0);
    }
    else if(controllerType == "PID")
    {
        if(lambda < 1.7*theta)
            std::cout << "Valor de lambda menor que o esperado" << std::endl;

        Type Kp = (2*tau+theta)/(K*(2*lambda+theta));
        Type Ti = tau+(theta/2);
        Type Td = tau*theta/(2*tau+theta);
        controller.setParams(Kp,Kp/Ti,Kp*Td);
    }
    else
        std::cout << "Controlador nao encontrado" << std::endl;
    return controller;
}
