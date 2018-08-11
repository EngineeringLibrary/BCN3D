#include <stdio.h>
#include "driver/gpio.h"
#include "FreeRTOS.h"
#include "task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "stepperA4988.h"
#include "servomotor.h"
#include "wifi.h"

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
void controlMotorGarra(void*arg)
{
    while(1)
        garra.setPosition(500);
}

//Funçãos para controlar os motores de passo
void stepControlMotor01(void *pvParameter)
{
    while(true){
        motor1->newStep(200,horario,15);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        motor1->newStep(200,antihorario,15);
        vTaskDelay(1000 / portTICK_PERIOD_MS);

    }
    vTaskDelay(portMAX_DELAY);

}

void stepControlMotor02(void *pvParameter)
{
    while(true){
        motor2->newStep(200,antihorario,15);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        motor2->newStep(200,horario,15);
        vTaskDelay(1000 / portTICK_PERIOD_MS);

    }

    vTaskDelay(portMAX_DELAY);
}

void stepControlMotor01(void *pvParameter)
{
    while(true){
        motor3->newStep(200,horario,15);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        motor3->newStep(200,antihorario,15);
        vTaskDelay(1000 / portTICK_PERIOD_MS);

    }
    vTaskDelay(portMAX_DELAY);
}

void stepControlMotor01(void *pvParameter)
{
    while(true){
        motor4->newStep(200,horario,15);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        motor4->newStep(200,antihorario,15);
        vTaskDelay(1000 / portTICK_PERIOD_MS);

    }
    vTaskDelay(portMAX_DELAY);
}

void stepControlMotor01(void *pvParameter)
{
    while(true){
        motor5->newStep(200,horario,15);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        motor5->newStep(200,antihorario,15);
        vTaskDelay(1000 / portTICK_PERIOD_MS);

    }
    vTaskDelay(portMAX_DELAY);
}

//Cadastro das funções que vão trabalhar em paralelo
extern "C" void app_main()
{

    ESP_ERROR_CHECK( esp_event_loop_init(event_handler, NULL) );
    wifi_event_group = xEventGroupCreate();
    start_dhcp_server();
    initialise_wifi_in_ap();
    xTaskCreate(&print_sta_info,"print_sta_info",4096,NULL,5,NULL);
    xTaskCreate(&telnetTask,"telnetTask",4096,NULL,5,NULL);

    xTaskCreate(controlMotor, "controlMotorGarra", 1024 * 2, NULL, 5, NULL);

    while( true){
      xTaskCreate(stepControlMotor01, "stepControlMotor01", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
      xTaskCreate(stepControlMotor02, "stepControlMotor02", configMINIMAL_STACK_SIZE, NULL, 2, NULL);
      xTaskCreate(stepControlMotor03, "stepControlMotor03", configMINIMAL_STACK_SIZE, NULL, 3, NULL);
      xTaskCreate(stepControlMotor04, "stepControlMotor04", configMINIMAL_STACK_SIZE, NULL, 4, NULL);
      xTaskCreate(stepControlMotor05, "stepControlMotor05", configMINIMAL_STACK_SIZE, NULL, 5, NULL);
      //sdk_os_delay_ms(10);
    }
}
