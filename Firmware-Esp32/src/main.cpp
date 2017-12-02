#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "stepperA4988.h"
#include "servomotor.h"
#include "matrix.h"
#include "wifi.h"
#include "pid.h"
#include "move.h"
#include <cmath>
#include <time.h>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <typeinfo>
#include <algorithm>

void testeReceberWifi(const char* dadosRecebidos){

  M = dadosRecebidos;

   for(linha = 0; linha < M.getNumberOfRows(); ++linha ){
     stepControlMotor01();
     stepControlMotor02();
     stepControlMotor03();
     stepControlMotor04();
     stepControlMotor05();
     // vTaskDelay(1000 / portTICK_PERIOD_MS);
   }
}

//Cadastro das funções que vão trabalhar em paralelo
extern "C" void app_main()
{
     wifi_TCP_server_init(testeReceberWifi);

    // xTaskCreate(stepControlMotor01, "stepControlMotor01", 1024*2, NULL, 5, NULL);
    // xTaskCreate(stepControlMotor02, "stepControlMotor02", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
    // xTaskCreate(stepControlMotor03, "stepControlMotor03", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
    // xTaskCreate(stepControlMotor04, "stepControlMotor04", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
    // xTaskCreate(stepControlMotor05, "stepControlMotor05", configMINIMAL_STACK_SIZE, NULL, 1, NULL);

    // xTaskCreate(controlMotorGarra, "controlMotorGarra", configMINIMAL_STACK_SIZE, NULL, 5, NULL);

}
