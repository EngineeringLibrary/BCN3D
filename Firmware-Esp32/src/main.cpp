#include <stdio.h>
#include <string.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "stepperA4988.h"
#include "servomotor.h"
#include "wifi.h"
#include "move.h"

//Cadastro das funções que vão trabalhar em paralelo
extern "C" void app_main()
{
      
      ESP_ERROR_CHECK( esp_event_loop_init(event_handler, NULL) );
      wifi_event_group = xEventGroupCreate();
      start_dhcp_server();
      initialise_wifi_in_ap();
      xTaskCreate(&print_sta_info,"print_sta_info",4096,NULL,5,NULL);
      xTaskCreate(&telnetTask,"telnetTask",4096,NULL,5,NULL);

      xTaskCreate(controlMotorGarra, "controlMotorGarra", configMINIMAL_STACK_SIZE, NULL, 5, NULL);

      xTaskCreate(stepControlMotor01, "stepControlMotor01", configMINIMAL_STACK_SIZE, NULL, 4, NULL);
      xTaskCreate(stepControlMotor02, "stepControlMotor02", configMINIMAL_STACK_SIZE, NULL, 4, NULL);
      xTaskCreate(stepControlMotor03, "stepControlMotor03", configMINIMAL_STACK_SIZE, NULL, 4, NULL);
      xTaskCreate(stepControlMotor04, "stepControlMotor04", configMINIMAL_STACK_SIZE, NULL, 4, NULL);
      xTaskCreate(stepControlMotor05, "stepControlMotor05", configMINIMAL_STACK_SIZE, NULL, 4, NULL);

}
