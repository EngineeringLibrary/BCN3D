#ifndef WIFI_H
#define WIFI_H

#include "freertos/event_groups.h"
#include "esp_wifi.h"
#include "esp_event_loop.h"
#include "esp_log.h"

static EventGroupHandle_t wifi_event_group;
const int CLIENT_CONNECTED_BIT = BIT0;
const int CLIENT_DISCONNECTED_BIT = BIT1;

#define AP_SSID "DomingosNeto"
#define AP_PASSPHARSE "123456"
#define AP_SSID_HIDDEN 0
#define AP_MAX_CONNECTIONS 4
#define AP_AUTHMODE WIFI_AUTH_WPA2_PSK // the passpharese should be atleast 8 chars long
#define AP_BEACON_INTERVAL 100 // in milli seconds

static esp_err_t event_handler(void *ctx, system_event_t *event);
static void start_dhcp_server();
static void initialise_wifi_in_ap(void);
void printStationList();
void print_sta_info(void *pvParam);
static void telnetTask(void *pvParameters);

#endif
