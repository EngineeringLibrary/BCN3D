#ifndef WIFICPP_H
#define WIFICPP_H

#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event_loop.h"
#include "esp_log.h"

#include <lwip/ip.h>
#include <lwip/opt.h>
#include <lwip/arch.h>
#include <lwip/api.h>

#define AP_SSID "BCN3D"
#define AP_PASSPHARSE "bcn3d123"
#define AP_SSID_HIDDEN 0
#define AP_MAX_CONNECTIONS 4
#define AP_AUTHMODE WIFI_AUTH_WPA2_PSK // the passpharese should be atleast 8 chars long
#define AP_BEACON_INTERVAL 100 // in milli seconds
static EventGroupHandle_t wifi_event_group;
const int CLIENT_CONNECTED_BIT = BIT0;
const int CLIENT_DISCONNECTED_BIT = BIT1;
wifi_config_t ap_config;
uint16_t TCPgate = 4000;
void (*FunctionToBeCalledWhenADataHasBeenReceived)(const char*);

void printStationList();
static void start_dhcp_server();
void print_sta_info   (void *pvParam);
static void telnetTask(void *pvParameters);
static void initialise_wifi_in_ap(void);
static esp_err_t event_handler   (void *ctx, system_event_t *event);
void wifi_TCP_server_init(void);

// #include "wifi.h"


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

static void start_dhcp_server(){

    	// initialize the tcp stack
	    tcpip_adapter_init();
        // stop DHCP server
        ESP_ERROR_CHECK(tcpip_adapter_dhcps_stop(TCPIP_ADAPTER_IF_AP));
        // assign a static IP to the network interface
        tcpip_adapter_ip_info_t info;
        memset(&info, 0, sizeof(info));
        IP4_ADDR(&info.ip, 192, 168, 0, 100);
        IP4_ADDR(&info.gw, 192, 168, 0, 100);//ESP acts as router, so gw addr will be its own addr
        IP4_ADDR(&info.netmask, 255, 255, 255, 0);
        ESP_ERROR_CHECK(tcpip_adapter_set_ip_info(TCPIP_ADAPTER_IF_AP, &info));
        // start the DHCP server
        ESP_ERROR_CHECK(tcpip_adapter_dhcps_start(TCPIP_ADAPTER_IF_AP));
        printf("DHCP server started \n");
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
  netconn_bind(conn,NULL,TCPgate); //associa a conexão à porta 4000
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

          ((*FunctionToBeCalledWhenADataHasBeenReceived)(data_char));
          //é aqui que vocês recebem o sinal do wifi e convertem em controle para o robô
					//data_char = moveHndler(data_char);//retornar que finalizou a tarefa
          err = netconn_write(newconn, data_char, strlen(data_char), NETCONN_COPY);//envia um dado via wifi
        }while(netbuf_next(buf) >= 0);//enquanto tiver dados recebidos, continua a executar
      }
      netconn_close(newconn);
      netconn_delete(newconn);
    }
  }
}

static void initialise_wifi_in_ap(void)
{
    esp_log_level_set("wifi", ESP_LOG_NONE); // disable wifi driver logging
    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK( esp_wifi_init(&cfg) );
    ESP_ERROR_CHECK(esp_wifi_set_storage(WIFI_STORAGE_RAM));
    ESP_ERROR_CHECK( esp_wifi_set_mode(WIFI_MODE_AP) );

    // configure the wifi connection and start the interface
  strcpy((char*)ap_config.ap.ssid,AP_SSID); // nome da rede wifi gerada
	ap_config.ap.ssid_hidden = AP_SSID_HIDDEN; // indica se a rede será visível ou não
	ap_config.ap.channel = 0; // canal de comunicação wifi
	ap_config.ap.authmode = AP_AUTHMODE; // modo de autenticação
	strcpy((char*)ap_config.ap.password,AP_PASSPHARSE); //senha
	ap_config.ap.max_connection = AP_MAX_CONNECTIONS; // número máximo de dispositivos que podem se conectar ao esp
	ap_config.ap.beacon_interval = AP_BEACON_INTERVAL; //intervalo de roteamento

	ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_AP, &ap_config));
    ESP_ERROR_CHECK( esp_wifi_start() );
    printf("ESP WiFi started in AP mode \n");
}

static esp_err_t event_handler(void *ctx, system_event_t *event)
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

void wifi_TCP_server_init(void (*_FunctionToBeCalledWhenADataHasBeenReceived)(const char*) = 0, uint16_t _TCPgate = 4000)
{
  TCPgate = _TCPgate;
  FunctionToBeCalledWhenADataHasBeenReceived = _FunctionToBeCalledWhenADataHasBeenReceived;

  ESP_ERROR_CHECK( esp_event_loop_init(event_handler, NULL) );
  wifi_event_group = xEventGroupCreate();
  start_dhcp_server();
  initialise_wifi_in_ap();
  xTaskCreate(&print_sta_info,"print_sta_info",4096,NULL,5,NULL);
  xTaskCreate(&telnetTask,"telnetTask",4096,NULL,5,NULL);
}

#endif
