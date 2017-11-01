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

gpio_num_t stepPinMotor1 = GPIO_NUM_22, directionPinMotor1 = GPIO_NUM_23, servoPin = GPIO_NUM_21;
stepperA4988 motor1(stepPinMotor1, directionPinMotor1);
servomotor garra(servoPin);

void controlMotor(void*arg)
{
    while(1)
        garra.setPosition(500);
}

void stepControlMotor(void*arg)
{
    while(1)
        motor1.newStep();
}

extern "C" void app_main()
{   
    xTaskCreate(controlMotor, "controlMotor", 1024 * 2, NULL, 5, NULL);
    xTaskCreate(stepControlMotor, "step", 1024 * 2, NULL, 5, NULL);    
}



