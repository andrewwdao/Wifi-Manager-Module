/*-------------------------------------------------------------
  Wifi Manager - header file
  ESP32 DEVKIT V1
  (c) Minh-An Dao - 2019. Copyright (c) 2017-2019 Tony Pottier
  Modified version from ESP32 wifi manager. See https://github.com/tonyp7/esp32-wifi-manager
  version 1.00 - 12/09/2019
---------------------------------------------------------------
 * ESP-IDF version: 3.2
 * Compiler version: 5.2.0
 * Arduino components version: latest
--------------------------------------------------------------*/
#ifndef __ESP32_WIFI_MANAGER_H
#define __ESP32_WIFI_MANAGER_H
#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_log.h"
#include "wifi_manager.h"
#include <WiFi.h> //for arduino component esp32
#include "debugConfig.h"
//#include "config.h"

// ------ Public constants ------------------------------------

// ------ Public function prototypes --------------------------
/**
Initialize Wifi Manager system
**/
void wifiManager_init();
/**
Read Wifi SSID from the NVS - non volatile system
**/
String wifiSSID_read();
/**
Read Wifi password from the NVS - non volatile system
**/
String wifiPASS_read();
// ------ Public variable -------------------------------------
//extern SemaphoreHandle_t baton; //declared in core0 cpp

#endif // __ESP32_WIFI_MANAGER_H
