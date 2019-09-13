/*------------------------------------------------------------*-
  WIFI MANAGER - MASTER FILE
  (c) An Minh Dao 2019
  version 1.00 - 13/09/2019
---------------------------------------------------------------
*
* REMEMBER to define in c_cpp_properties.json as well
* 
--------------------------------------------------------------*/
#include <WiFi.h> //for arduino component esp32
#include "ESP32_wifiManager.h"
// #include "NI_TASKS_MONITOR.h"
// #include "core0.h"
// #include "core1.h"
#include "debugConfig.h"
// #include "config.h"

SemaphoreHandle_t baton;
#ifdef TASKS_MONITOR
SemaphoreHandle_t taskMonitor_baton;
#endif


extern "C" void app_main() {
  vSemaphoreCreateBinary(baton); //initialize binary semaphore //baton = xSemaphoreCreateBinary(); //this works too but not as good as the current use
  #ifdef TASKS_MONITOR
  vSemaphoreCreateBinary(taskMonitor_baton); //initialize binary semaphore //baton = xSemaphoreCreateBinary(); //this works too but not as good as the current use
  #endif
  
   initArduino();
   SERIAL_BEGIN(); //must include config.h (defined there)

  // Core0CombinedTask_init();
  // Core1CombinedTask_init();
  wifiManager_init(); //put this function anywhere you want to call the web server

  while (1) {
    D_PRINTLN(wifiSSID_read());
    D_PRINTLN(wifiPASS_read());
    vTaskDelay(500);
  }

  #ifdef TASKS_MONITOR
  TASKS_MONITOR_init();
  #endif
}//end main
