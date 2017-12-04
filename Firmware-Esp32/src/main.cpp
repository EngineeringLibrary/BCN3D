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

//Está função aguarda o recebimento de dados wifi, caso tenha dados ela será executada.
void testeReceberWifi(const char* dadosRecebidos){

  M = dadosRecebidos; // Matrix de dados recebidos, declarada como global em move.h

   for(linha = 0; linha < M.getNumberOfRows(); ++linha){
     stepControlMotor01();
     stepControlMotor02();
     stepControlMotor03();
     stepControlMotor04();
     stepControlMotor05();
   }
   linha = 0; // zera a linha para que no proximo encio de dados recomece do zero.
}

//Cadastro das funções que vão trabalhar em paralelo
extern "C" void app_main()
{
     wifi_TCP_server_init(testeReceberWifi); // inicia wifi e aguarda o recebimento de dados.
}
