#ifndef MOVE_H
#define MOVE_H

#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "stepperA4988.h"
#include "servomotor.h"

//Variavel Global
gpio_num_t  stepPinMotor1 = GPIO_NUM_22, directionPinMotor1 = GPIO_NUM_21,
            stepPinMotor2 = GPIO_NUM_19, directionPinMotor2 = GPIO_NUM_18,
            stepPinMotor3 = GPIO_NUM_17, directionPinMotor3 = GPIO_NUM_16,
            stepPinMotor4 = GPIO_NUM_25, directionPinMotor4 = GPIO_NUM_26,
            stepPinMotor5 = GPIO_NUM_32, directionPinMotor5 = GPIO_NUM_33,
            servoPin = GPIO_NUM_14;

bool horario = 1, antihorario = 0;

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

  return kp*E + ki*Ei + kd*Ed;
}

double PIDM2 (double step, double setepRef)
{
  double kp = 2, ki = 0, kd = 0.5, Dt = 1, Ea = 0, Ei = 0;
  double E = setepRef - step;
  double Ed = (E-Ea)/Dt;
  Ea = E;
  Ei += Dt * E;

  return kp*E + ki*Ei + kd*Ed;
}

double PIDM3 (double step, double setepRef)
{
  double kp = 2, ki = 0, kd = 0.5, Dt = 1, Ea = 0, Ei = 0;
  double E = setepRef - step;
  double Ed = (E-Ea)/Dt;
  Ea = E;
  Ei += Dt * E;

  return kp*E + ki*Ei + kd*Ed;
}

double PIDM4 (double step, double setepRef)
{
  double kp = 2, ki = 0, kd = 0.5, Dt = 1, Ea = 0, Ei = 0;
  double E = setepRef - step;
  double Ed = (E-Ea)/Dt;
  Ea = E;
  Ei += Dt * E;

  return kp*E + ki*Ei + kd*Ed;
}

double PIDM5 (double step, double setepRef)
{
  double kp = 2, ki = 0, kd = 0.5, Dt = 1, Ea = 0, Ei = 0;
  double E = setepRef - step;
  double Ed = (E-Ea)/Dt;
  Ea = E;
  Ei += Dt * E;

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
       motor1->newStep(PIDM1(10, 15), horario,15);
       vTaskDelay(1000 / portTICK_PERIOD_MS);
       motor1->newStep(PIDM1(10, 15), antihorario,15);
       vTaskDelay(1000 / portTICK_PERIOD_MS);

   }
   vTaskDelay(portMAX_DELAY);

}

void stepControlMotor02(void *pvParameter)
{
   while(true){
       motor2->newStep(PIDM2(10, 15), antihorario, 15);
       vTaskDelay(1000 / portTICK_PERIOD_MS);
       motor2->newStep(PIDM2(10, 15), horario, 15);
       vTaskDelay(1000 / portTICK_PERIOD_MS);

   }

   vTaskDelay(portMAX_DELAY);
}

void stepControlMotor03(void *pvParameter)
{
   while(true){
       motor3->newStep(PIDM3(10, 15), horario, 15);
       vTaskDelay(1000 / portTICK_PERIOD_MS);
       motor3->newStep(PIDM3(10, 15), antihorario, 15);
       vTaskDelay(1000 / portTICK_PERIOD_MS);

   }
   vTaskDelay(portMAX_DELAY);
}

void stepControlMotor04(void *pvParameter)
{
   while(true){
       motor4->newStep(PIDM4(10, 15), horario, 15);
       vTaskDelay(1000 / portTICK_PERIOD_MS);
       motor4->newStep(PIDM4(10, 15), antihorario, 15);
       vTaskDelay(1000 / portTICK_PERIOD_MS);

   }
   vTaskDelay(portMAX_DELAY);
}

void stepControlMotor05(void *pvParameter)
{
   while(true){
       motor5->newStep(PIDM5(10, 15), horario, 15);
       vTaskDelay(1000 / portTICK_PERIOD_MS);
       motor5->newStep(PIDM5(10, 15), antihorario, 15);
       vTaskDelay(1000 / portTICK_PERIOD_MS);

   }
   vTaskDelay(portMAX_DELAY);
}

#endif
