/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
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
             stepPinMotor4 = GPIO_NUM_35, directionPinMotor4 = GPIO_NUM_34,
             stepPinMotor5 = GPIO_NUM_26, directionPinMotor5 = GPIO_NUM_25,
             servoPin = GPIO_NUM_23;

bool horario = 1, antihorario = 0;

stepperA4988 *motor1=new stepperA4988(stepPinMotor1, directionPinMotor1);
stepperA4988 *motor2=new stepperA4988(stepPinMotor2, directionPinMotor2);
stepperA4988 *motor3=new stepperA4988(stepPinMotor3, directionPinMotor3);
stepperA4988 *motor4=new stepperA4988(stepPinMotor4, directionPinMotor4);
stepperA4988 *motor5=new stepperA4988(stepPinMotor5, directionPinMotor5);

servomotor garra(servoPin);

//Função para controlar o servo motor
// void controlMotorGarra(void*arg)
// {
//     while(1)
//         garra.setPosition(500);
// }

//Funçãos para controlar os motores de passo
void stepControlMotor01(void*arg)

  for(int i = 0; i < step1; ++i){
                motor1.newStep();
      }

void stepControlMotor02(void*arg)

  for(int i = 0; i < step2; ++i){
                motor2.newStep();
      }

void stepControlMotor03(void*arg)

  for(int i = 0; i < step3; ++i){
                motor3.newStep();
      }
void stepControlMotor04(void*arg)

  for(int i = 0; i < step4; ++i){
                motor4.newStep();
      }

void stepControlMotor05(void*arg)

  for(int i = 0; i < step5; ++i){
                motor5.newStep();
      }


//Cadastro das funções que vão trabalhar em paralelo
extern "C" void app_main()
{
    xTaskCreate(controlMotor, "controlMotorGarra", 1024 * 2, NULL, 5, NULL);

    while( true){
         xTaskCreate(stepControlMotor01, "stepControlMotor01", 1024 * 2, NULL, 5, NULL);
         xTaskCreate(stepControlMotor02, "stepControlMotor02", 1024 * 2, NULL, 5, NULL);
         xTaskCreate(stepControlMotor03, "stepControlMotor03", 1024 * 2, NULL, 5, NULL);
         xTaskCreate(stepControlMotor04, "stepControlMotor04", 1024 * 2, NULL, 5, NULL);
         xTaskCreate(stepControlMotor05, "stepControlMotor05", 1024 * 2, NULL, 5, NULL); 
      sdk_os_delay_ms(10);
    }


}
