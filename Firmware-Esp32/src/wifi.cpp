// #include "wifi.h"
//
// esp_err_t wifi::event_handler(void *ctx, system_event_t *event)
// {
//     switch(event->event_id) {
//     case SYSTEM_EVENT_AP_START:
// 		printf("Event:ESP32 is started in AP mode\n");
// 		break;
//
// 	case SYSTEM_EVENT_AP_STACONNECTED:
// 		xEventGroupSetBits(wifi_event_group, CLIENT_CONNECTED_BIT);
// 		break;
//
// 	case SYSTEM_EVENT_AP_STADISCONNECTED:
// 		xEventGroupSetBits(wifi_event_group, CLIENT_DISCONNECTED_BIT);
// 		break;
//     default:
//         break;
//     }
//     return ESP_OK;
// }
//
// void wifi::start_dhcp_server(){
//
//       	// initialize the tcp stack
//   	    tcpip_adapter_init();
//         // stop DHCP server
//         ESP_ERROR_CHECK(tcpip_adapter_dhcps_stop(TCPIP_ADAPTER_IF_AP));
//         // assign a static IP to the network interface
//         tcpip_adapter_ip_info_t info;
//         memset(&info, 0, sizeof(info));
//         IP4_ADDR(&info.ip, 192, 168, 1, 1);
//         IP4_ADDR(&info.gw, 192, 168, 1, 1);//ESP acts as router, so gw addr will be its own addr
//         IP4_ADDR(&info.netmask, 255, 255, 255, 0);
//         ESP_ERROR_CHECK(tcpip_adapter_set_ip_info(TCPIP_ADAPTER_IF_AP, &info));
//         // start the DHCP server
//         ESP_ERROR_CHECK(tcpip_adapter_dhcps_start(TCPIP_ADAPTER_IF_AP));
//         printf("DHCP server started \n");
// }
// void wifi::initialise_wifi_in_ap(void)
// {
//     esp_log_level_set("wifi", ESP_LOG_NONE); // disable wifi driver logging
//     wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
//     ESP_ERROR_CHECK( esp_wifi_init(&cfg) );
//     ESP_ERROR_CHECK(esp_wifi_set_storage(WIFI_STORAGE_RAM));
//     ESP_ERROR_CHECK( esp_wifi_set_mode(WIFI_MODE_AP) );
//
//     // configure the wifi connection and start the interface
// 	wifi_config_t ap_config = {
//       .ap = {
//         .ssid = AP_SSID,
//         .password = AP_PASSPHARSE,
//   			.ssid_len = 0,
//   			.channel = 0,
//   			.authmode = AP_AUTHMODE,
//   			.ssid_hidden = AP_SSID_HIDDEN,
//   			.max_connection = AP_MAX_CONNECTIONS,
//   			.beacon_interval = AP_BEACON_INTERVAL,
//       },
//     };
// 	ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_AP, &ap_config));
//     ESP_ERROR_CHECK( esp_wifi_start() );
//     printf("ESP WiFi started in AP mode \n");
// }
//
// // print the list of connected stations
// void wifi::printStationList()
// {
// 	printf(" Connected stations:\n");
// 	printf("--------------------------------------------------\n");
//
// 	wifi_sta_list_t wifi_sta_list;
// 	tcpip_adapter_sta_list_t adapter_sta_list;
//
// 	memset(&wifi_sta_list, 0, sizeof(wifi_sta_list));
// 	memset(&adapter_sta_list, 0, sizeof(adapter_sta_list));
//
// 	ESP_ERROR_CHECK(esp_wifi_ap_get_sta_list(&wifi_sta_list));
// 	ESP_ERROR_CHECK(tcpip_adapter_get_sta_list(&wifi_sta_list, &adapter_sta_list));
//
// 	for(int i = 0; i < adapter_sta_list.num; i++) {
//
// 		tcpip_adapter_sta_info_t station = adapter_sta_list.sta[i];
//         printf("%d - mac: %.2x:%.2x:%.2x:%.2x:%.2x:%.2x - IP: %s\n", i + 1,
// 				station.mac[0], station.mac[1], station.mac[2],
// 				station.mac[3], station.mac[4], station.mac[5],
// 				ip4addr_ntoa(&(station.ip)));
// 	}
//
// 	printf("\n");
// }
//
// void wifi::print_sta_info(void *pvParam){
//     printf("print_sta_info task started \n");
//     while(1) {
// 		EventBits_t staBits = xEventGroupWaitBits(wifi_event_group, CLIENT_CONNECTED_BIT | CLIENT_CONNECTED_BIT, pdTRUE, pdFALSE, portMAX_DELAY);
// 		if((staBits & CLIENT_CONNECTED_BIT) != 0) printf("New station connected\n\n");
//         else printf("A station disconnected\n\n");
//         printStationList();
// 	}
// }
//
// void wifi::telnetTask(void *pvParameters)
// {
//   struct netconn *conn, *newconn;
//   err_t err;
//   conn = netconn_new(NETCONN_TCP);  //cria um novo identificador de conexão
//   netconn_bind(conn,NULL,4000); //associa a conexão à porta 4000
//   netconn_listen(conn); //começa a escutar a conexão
//   while(1)
//   {
//     err = netconn_accept(conn, &newconn);
//     if(err == ERR_OK) // processando a nova conexão
//     {
//       struct netbuf *buf; // criando um buffer para armazenar os dados recebidos via wifi
//       void *data;
//       char *data_char;
//       u16_t len;
//       while((err = netconn_recv(newconn, &buf)) == ERR_OK)//entrando na rotina se algum dado for recebido
//       {
//         do{
//           netbuf_data(buf,&data,&len);//lê os dados recebidos e coloca no buffer
//           data_char = (char*)data; //convertendo os dados recebidos para caracter
//           printf("%s\n", data_char);
//           //é aqui que vocês recebem o sinal do wifi e convertem em controle para o robô
//
//           err = netconn_write(newconn,  "hello world",12,NETCONN_COPY);//envia um dado via wifi
//         }while(netbuf_next(buf) >= 0);//enquanto tiver dados recebidos, continua a executar
//       }
//       netconn_close(newconn);
//       netconn_delete(newconn);
//     }
//   }
// }
