#ifndef MOVE_H
#define MOVE_H

#include <stdio.h>
#include <string.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "stepperA4988.h"
#include "servomotor.h"
#include "Matrix.h"
#include "pid.h"
#include <cmath>
#include <time.h>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <typeinfo>
#include <algorithm>

//Variavel Global
//ControlHandler::PID<double> pid("1.0,0.0,0.5");
LinAlg::Matrix<int> M;
volatile static int ref1 = 0, ref2 = 0, ref3 = 0, ref4 = 0, ref5 = 0, linha = 0;

bool horario = 1, antihorario = 0;
volatile static bool flagStartTask[5] = {0, 0, 0, 0, 0};

gpio_num_t  stepPinMotor1 = GPIO_NUM_22, directionPinMotor1 = GPIO_NUM_21,
            stepPinMotor2 = GPIO_NUM_19, directionPinMotor2 = GPIO_NUM_18,
            stepPinMotor3 = GPIO_NUM_17, directionPinMotor3 = GPIO_NUM_16,
            stepPinMotor4 = GPIO_NUM_26, directionPinMotor4 = GPIO_NUM_27,
            stepPinMotor5 = GPIO_NUM_32, directionPinMotor5 = GPIO_NUM_33,
            servoPin = GPIO_NUM_14;

stepperA4988 *motor1=new stepperA4988(stepPinMotor1, directionPinMotor1);
stepperA4988 *motor2=new stepperA4988(stepPinMotor2, directionPinMotor2);
stepperA4988 *motor3=new stepperA4988(stepPinMotor3, directionPinMotor3);
stepperA4988 *motor4=new stepperA4988(stepPinMotor4, directionPinMotor4);
stepperA4988 *motor5=new stepperA4988(stepPinMotor5, directionPinMotor5);

servomotor garra(servoPin);

//Função para controlar o servo motor
void controlMotorGarra(void*arg)
{
   while(1)
       garra.setPosition(500);
}

//Funçãos para controlar os motores de passo
void stepControlMotor01(void)
{
  int u = M(linha,0);
    if(u > 0)
      motor1->newStep(u, horario, 15);
    if(u < 0)
      motor1->newStep(abs(u), antihorario, 15);
}

void stepControlMotor02(void)
{
  int u = M(linha,1);
     if(u > 0)
       motor2->newStep(u, horario, 15);
     if(u < 0)
       motor2->newStep(abs(u), antihorario, 15);
}

void stepControlMotor03(void)
{
  double u = M(linha,2);
    if(u > 0)
      motor3->newStep(u, horario, 15);
    if(u < 0)
      motor3->newStep(abs(u), antihorario, 15);
}

void stepControlMotor04(void)
{
   double u = M(linha,3);
     if(u > 0)
       motor4->newStep(u, horario, 15);
     if(u < 0)
       motor4->newStep(abs(u), antihorario, 15);
}

void stepControlMotor05(void)
{
   double u = M(linha,4);
     if(u > 0)
       motor5->newStep(u, horario, 15);
     if(u < 0)
       motor5->newStep(abs(u), antihorario,15);
}

#endif
