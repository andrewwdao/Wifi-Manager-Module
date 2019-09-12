/*------------------------------------------------------------*-
  ID CARD SCANNER - MASTER FILE
  (c) An Minh Dao 2019
  version 2.00 - 10/02/2019
---------------------------------------------------------------
*
* REMEMBER to define in c_cpp_properties.json as well
* 
--------------------------------------------------------------*/

// #include "config.h"
// #include "Arduino.h"
// #include "core0.h"
// #include "core1.h"
// #include "NI_TASKS_MONITOR.h"
#include "ESP32_wifiManager.h"

SemaphoreHandle_t baton;
#ifdef TASKS_MONITOR
SemaphoreHandle_t taskMonitor_baton;
#endif


extern "C" void app_main() {
  vSemaphoreCreateBinary(baton); //initialize binary semaphore //baton = xSemaphoreCreateBinary(); //this works too but not as good as the current use
  #ifdef TASKS_MONITOR
  vSemaphoreCreateBinary(taskMonitor_baton); //initialize binary semaphore //baton = xSemaphoreCreateBinary(); //this works too but not as good as the current use
  #endif
  
  // initArduino();
  // SERIAL_BEGIN(); 

  // Core0CombinedTask_init();
  // Core1CombinedTask_init();
  wifiManager_init();

  #ifdef TASKS_MONITOR
  TASKS_MONITOR_init();
  #endif
}//end main
