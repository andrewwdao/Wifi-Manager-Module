/*-------------------------------------------------------------
  Wifi Manager - function file
  ESP32 DEVKIT V1
  (c) Minh-An Dao - 2019. Copyright (c) 2017-2019 Tony Pottier
  Modified version from ESP32 wifi manager. See https://github.com/tonyp7/esp32-wifi-manager
  version 1.00 - 12/09/2019
---------------------------------------------------------------
 * ESP-IDF version: 3.2
 * Compiler version: 5.2.0
 * Arduino components version: latest
--------------------------------------------------------------*/
#ifndef __ESP32_WIFI_MANAGER_CPP
#define __ESP32_WIFI_MANAGER_CPP
#include "ESP32_wifiManager.h"
// ------ Private constants -----------------------------------
#define TAG     "main"
// ------ Private function prototypes -------------------------
/**
a callback that you can setup to get notified of wifi manager event
**/
void got_cnted(void *);

// ------ Private variables -----------------------------------

// ------ PUBLIC variable definitions -------------------------

//--------------------------------------------------------------
// FUNCTION DEFINITIONS
//--------------------------------------------------------------
void got_cnted(void *pvParameter){
	ESP_LOGI(TAG, "I have a connection!");
}//end got_cnted
//------------------------------------------
void wifiManager_init() {
	/* start the wifi manager */
	wifi_manager_start();
	/* register a callback */
	wifi_manager_set_callback(EVENT_STA_GOT_IP, &got_cnted);
}//end wifiManager_init
//------------------------------------------
uint8_t* wifiSSID_read() {
  wifi_config_t* wifiSSID;
  wifiSSID = wifi_manager_get_wifi_sta_config();
  return wifiSSID->sta.ssid;
}//end wifiSSID_read
//------------------------------------------
uint8_t* wifiPASS_read() {
  wifi_config_t* wifiPASS;
  wifiPASS = wifi_manager_get_wifi_sta_config();
  return wifiPASS->sta.password;
}//end wifiPASS_read
//------------------------------------------
#endif //end __ESP32_WIFI_MANAGER_CPP