#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "stepperA4988.h"
#include "servomotor.h"

#include "freertos/event_groups.h"
#include "esp_wifi.h"
#include "esp_event_loop.h"
#include "esp_log.h"

#define AP_SSID "DomingosNeto"
#define AP_PASSPHARSE "123456"
#define AP_SSID_HIDDEN 0
#define AP_MAX_CONNECTIONS 4
#define AP_AUTHMODE WIFI_AUTH_WPA2_PSK // the passpharese should be atleast 8 chars long
#define AP_BEACON_INTERVAL 100 // in milli seconds


static EventGroupHandle_t wifi_event_group;
const int CLIENT_CONNECTED_BIT = BIT0;
const int CLIENT_DISCONNECTED_BIT = BIT1;
static void telnetTask(void *pvParameters);

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

tatic esp_err_t event_handler(void *ctx, system_event_t *event)
{
    switch(event->event_id) {
    case SYSTEM_EVENT_AP_START:
		printf("Event:ESP32 is started in AP mode\n");
		break;

	case SYSTEM_EVENT_AP_STACONNECTED:
		xEventGroupSetBits(wifi_event_group, CLIENT_CONNECTED_BIT);
		break;

	case SYSTEM_EVENT_AP_STADISCONNECTED:
		xEventGroupSetBits(wifi_event_group, CLIENT_DISCONNECTED_BIT);
		break;
    default:
        break;
    }
    return ESP_OK;
}

static void start_dhcp_server(){

      	// initialize the tcp stack
  	    tcpip_adapter_init();
        // stop DHCP server
        ESP_ERROR_CHECK(tcpip_adapter_dhcps_stop(TCPIP_ADAPTER_IF_AP));
        // assign a static IP to the network interface
        tcpip_adapter_ip_info_t info;
        memset(&info, 0, sizeof(info));
        IP4_ADDR(&info.ip, 192, 168, 1, 1);
        IP4_ADDR(&info.gw, 192, 168, 1, 1);//ESP acts as router, so gw addr will be its own addr
        IP4_ADDR(&info.netmask, 255, 255, 255, 0);
        ESP_ERROR_CHECK(tcpip_adapter_set_ip_info(TCPIP_ADAPTER_IF_AP, &info));
        // start the DHCP server
        ESP_ERROR_CHECK(tcpip_adapter_dhcps_start(TCPIP_ADAPTER_IF_AP));
        printf("DHCP server started \n");
}
static void initialise_wifi_in_ap(void)
{
    esp_log_level_set("wifi", ESP_LOG_NONE); // disable wifi driver logging
    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK( esp_wifi_init(&cfg) );
    ESP_ERROR_CHECK(esp_wifi_set_storage(WIFI_STORAGE_RAM));
    ESP_ERROR_CHECK( esp_wifi_set_mode(WIFI_MODE_AP) );

    // configure the wifi connection and start the interface
	wifi_config_t ap_config = {
      .ap = {
        .ssid = AP_SSID,
        .password = AP_PASSPHARSE,
  			.ssid_len = 0,
  			.channel = 0,
  			.authmode = AP_AUTHMODE,
  			.ssid_hidden = AP_SSID_HIDDEN,
  			.max_connection = AP_MAX_CONNECTIONS,
  			.beacon_interval = AP_BEACON_INTERVAL,
      },
    };
	ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_AP, &ap_config));
    ESP_ERROR_CHECK( esp_wifi_start() );
    printf("ESP WiFi started in AP mode \n");
}

// print the list of connected stations
void printStationList()
{
	printf(" Connected stations:\n");
	printf("--------------------------------------------------\n");

	wifi_sta_list_t wifi_sta_list;
	tcpip_adapter_sta_list_t adapter_sta_list;

	memset(&wifi_sta_list, 0, sizeof(wifi_sta_list));
	memset(&adapter_sta_list, 0, sizeof(adapter_sta_list));

	ESP_ERROR_CHECK(esp_wifi_ap_get_sta_list(&wifi_sta_list));
	ESP_ERROR_CHECK(tcpip_adapter_get_sta_list(&wifi_sta_list, &adapter_sta_list));

	for(int i = 0; i < adapter_sta_list.num; i++) {

		tcpip_adapter_sta_info_t station = adapter_sta_list.sta[i];
        printf("%d - mac: %.2x:%.2x:%.2x:%.2x:%.2x:%.2x - IP: %s\n", i + 1,
				station.mac[0], station.mac[1], station.mac[2],
				station.mac[3], station.mac[4], station.mac[5],
				ip4addr_ntoa(&(station.ip)));
	}

	printf("\n");
}

void print_sta_info(void *pvParam){
    printf("print_sta_info task started \n");
    while(1) {
		EventBits_t staBits = xEventGroupWaitBits(wifi_event_group, CLIENT_CONNECTED_BIT | CLIENT_CONNECTED_BIT, pdTRUE, pdFALSE, portMAX_DELAY);
		if((staBits & CLIENT_CONNECTED_BIT) != 0) printf("New station connected\n\n");
        else printf("A station disconnected\n\n");
        printStationList();
	}
}

static void telnetTask(void *pvParameters)
{
  struct netconn *conn, *newconn;
  err_t err;
  conn = netconn_new(NETCONN_TCP);  //cria um novo identificador de conexão
  netconn_bind(conn,NULL,4000); //associa a conexão à porta 4000
  netconn_listen(conn); //começa a escutar a conexão
  while(1)
  {
    err = netconn_accept(conn, &newconn);
    if(err == ERR_OK) // processando a nova conexão
    {
      struct netbuf *buf; // criando um buffer para armazenar os dados recebidos via wifi
      void *data;
      char *data_char;
      u16_t len;
      while((err = netconn_recv(newconn, &buf)) == ERR_OK)//entrando na rotina se algum dado for recebido
      {
        do{
          netbuf_data(buf,&data,&len);//lê os dados recebidos e coloca no buffer
          data_char = (char*)data; //convertendo os dados recebidos para caracter
          printf("%s\n", data_char);
          //é aqui que vocês recebem o sinal do wifi e convertem em controle para o robô

          err = netconn_write(newconn,  "hello world",12,NETCONN_COPY);//envia um dado via wifi
        }while(netbuf_next(buf) >= 0);//enquanto tiver dados recebidos, continua a executar
      }
      netconn_close(newconn);
      netconn_delete(newconn);
    }
  }
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
      xTaskCreate(stepControlMotor01, "stepControlMotor01", configMINIMAL_STACK_SIZE, NULL, 2, NULL);
      xTaskCreate(stepControlMotor02, "stepControlMotor02", configMINIMAL_STACK_SIZE, NULL, 5, NULL);
      xTaskCreate(stepControlMotor03, "stepControlMotor03", configMINIMAL_STACK_SIZE, NULL, 5, NULL);
      xTaskCreate(stepControlMotor04, "stepControlMotor04", configMINIMAL_STACK_SIZE, NULL, 5, NULL);
      xTaskCreate(stepControlMotor05, "stepControlMotor05", configMINIMAL_STACK_SIZE, NULL, 5, NULL);
        sdk_os_delay_ms(10);
    }
}
