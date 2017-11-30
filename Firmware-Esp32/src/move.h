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

//Variavel Global
bool horario = 1, antihorario = 0;
double THETA1 = 10, THETA2 = 10, THETA3 = 10, THETA4 = 10, THETA5 = 10;
double setepRef1 = 0, setepRef2 = 0, setepRef3 = 0, setepRef4 = 0, setepRef5 = 0;

gpio_num_t  stepPinMotor1 = GPIO_NUM_22, directionPinMotor1 = GPIO_NUM_21,
            stepPinMotor2 = GPIO_NUM_19, directionPinMotor2 = GPIO_NUM_18,
            stepPinMotor3 = GPIO_NUM_17, directionPinMotor3 = GPIO_NUM_16,
            stepPinMotor4 = GPIO_NUM_25, directionPinMotor4 = GPIO_NUM_26,
            stepPinMotor5 = GPIO_NUM_32, directionPinMotor5 = GPIO_NUM_33,
            servoPin = GPIO_NUM_14;

stepperA4988 *motor1=new stepperA4988(stepPinMotor1, directionPinMotor1);
stepperA4988 *motor2=new stepperA4988(stepPinMotor2, directionPinMotor2);
stepperA4988 *motor3=new stepperA4988(stepPinMotor3, directionPinMotor3);
stepperA4988 *motor4=new stepperA4988(stepPinMotor4, directionPinMotor4);
stepperA4988 *motor5=new stepperA4988(stepPinMotor5, directionPinMotor5);

servomotor garra(servoPin);

double PIDM1 (double step, double setepRef)
{
  double kp = 2, ki = 0, kd = 0.5, Dt = 1, Ea = 0, Ei = 0;
  double E = setepRef - step;
  double Ed = (E-Ea)/Dt;
  Ea = E;
  Ei += Dt * E;

  if(Ei > 200)
    Ei = 200;
  if(Ei< -200)
    Ei = -200;

  return kp*E + ki*Ei + kd*Ed;
}

double PIDM2 (double step, double setepRef)
{
  double kp = 2, ki = 0, kd = 0.5, Dt = 1, Ea = 0, Ei = 0;
  double E = setepRef - step;
  double Ed = (E-Ea)/Dt;
  Ea = E;
  Ei += Dt * E;

  if(Ei > 200)
    Ei = 200;
  if(Ei< -200)
    Ei = -200;

  return kp*E + ki*Ei + kd*Ed;
}

double PIDM3 (double step, double setepRef)
{
  double kp = 2, ki = 0, kd = 0.5, Dt = 1, Ea = 0, Ei = 0;
  double E = setepRef - step;
  double Ed = (E-Ea)/Dt;
  Ea = E;
  Ei += Dt * E;

  if(Ei > 200)
    Ei = 200;
  if(Ei< -200)
    Ei = -200;

  return kp*E + ki*Ei + kd*Ed;
}

double PIDM4 (double step, double setepRef)
{
  double kp = 2, ki = 0, kd = 0.5, Dt = 1, Ea = 0, Ei = 0;
  double E = setepRef - step;
  double Ed = (E-Ea)/Dt;
  Ea = E;
  Ei += Dt * E;

  if(Ei > 200)
    Ei = 200;
  if(Ei< -200)
    Ei = -200;

  return kp*E + ki*Ei + kd*Ed;
}

double PIDM5 (double step, double setepRef)
{
  double kp = 2, ki = 0, kd = 0.5, Dt = 1, Ea = 0, Ei = 0;
  double E = setepRef - step;
  double Ed = (E-Ea)/Dt;
  Ea = E;
  Ei += Dt * E;

  if(Ei > 200)
    Ei = 200;
  if(Ei< -200)
    Ei = -200;

  return kp*E + ki*Ei + kd*Ed;
}

//Função para controlar o servo motor
void controlMotorGarra(void*arg)
{
   while(1)
       garra.setPosition(500);
}

//Funçãos para controlar os motores de passo
void stepControlMotor01(void *pvParameter)
{
   while(true){
     if(THETA1 > 0){
       if(THETA1 > 800) THETA1 = 800;
       motor1->newStep(PIDM1(THETA1, setepRef1), horario,15);
       vTaskDelay(1000 / portTICK_PERIOD_MS);
     }
     if(THETA1 < 0){
       if(THETA1 < -800) THETA1 = -800;
       motor1->newStep(PIDM1(THETA1, setepRef1), antihorario,15);
       vTaskDelay(1000 / portTICK_PERIOD_MS);
     }
   }
   vTaskDelay(portMAX_DELAY);
}

void stepControlMotor02(void *pvParameter)
{
   while(true){
     if(THETA2 > 0){
       if(THETA2 > 1066) THETA2 = 1066;
       motor2->newStep(PIDM2(THETA2, setepRef2), antihorario, 15);
       vTaskDelay(1000 / portTICK_PERIOD_MS);
     }
     if(THETA2 < 0){
       if(THETA2 < -1066) THETA2 = -1066;
       motor2->newStep(PIDM2(THETA2, setepRef2), horario, 15);
       vTaskDelay(1000 / portTICK_PERIOD_MS);
     }
   }
   vTaskDelay(portMAX_DELAY);
}

void stepControlMotor03(void *pvParameter)
{
   while(true){
     if(THETA3 > 0){
       if(THETA3 > 1066) THETA3 = 1066;
       motor3->newStep(PIDM3(THETA3, setepRef3), horario, 15);
       vTaskDelay(1000 / portTICK_PERIOD_MS);
     }
     if(THETA3 < 0){
       if(THETA3 < -1066) THETA3 = -1066;
       motor3->newStep(PIDM3(THETA3, setepRef3), antihorario, 15);
       vTaskDelay(1000 / portTICK_PERIOD_MS);
     }
   }
   vTaskDelay(portMAX_DELAY);
}

void stepControlMotor04(void *pvParameter)
{
   while(true){
     if(THETA4 > 0){
       if(THETA4 > 3200) THETA4 = 3200;
       motor4->newStep(PIDM4(THETA4, setepRef4), horario, 15);
       vTaskDelay(1000 / portTICK_PERIOD_MS);
     }
     if(THETA4 < 0){
       if(THETA4 < -3200) THETA4 = -3200;
       motor4->newStep(PIDM4(THETA4, setepRef4), antihorario, 15);
       vTaskDelay(1000 / portTICK_PERIOD_MS);
     }
   }
   vTaskDelay(portMAX_DELAY);
}

void stepControlMotor05(void *pvParameter)
{
   while(true){
     if(THETA5 > 0){
       if(THETA5 > 800) THETA5 = 800;
       motor5->newStep(PIDM5(THETA5, setepRef5), horario, 15);
       vTaskDelay(1000 / portTICK_PERIOD_MS);
     }
     if(THETA5 < 0){
       if(THETA5 < -800) THETA5 = -800;
       motor5->newStep(PIDM5(THETA5, setepRef5), antihorario, 15);
       vTaskDelay(1000 / portTICK_PERIOD_MS);
     }
   }
   vTaskDelay(portMAX_DELAY);
}

void moveHndler(char *THETAS){
  //char len = strlen(THETAS);
  for(int i = 0; i < strlen(THETAS); ++i){
    if(THETAS[i] == 32){
      if(THETAS[i] != 32 && THETAS[i] != 44)
        THETA1 = THETAS[i];
    }
  }
}
#endif
