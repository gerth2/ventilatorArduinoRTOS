#include "ventilatorArduinoRTOS.h"

// User Display Loop Task Configuration
#define TASK_USER_DISP_LOOP_FCN userDispMain
#define TASK_USER_DISP_NAME    "User Disp"
#define TASK_USER_DISP_STACK_SZ_WORDS 500
#define TASK_USER_DISP_PRIORITY  1 //Fairly low priority
#define TASK_USER_DISP_PERIOD_MS 200

volatile int callCounter = 0;

void userDispInit(void){
  //////////////////////////////////////////////////////
  // One-Time Init Goes Here

  // End of one-time init code
  //////////////////////////////////////////////////////

  xTaskCreate(TASK_USER_DISP_LOOP_FCN, 
              TASK_USER_DISP_NAME, 
              TASK_USER_DISP_STACK_SZ_WORDS,
              NULL, 
              TASK_USER_DISP_PRIORITY, 
              NULL);
}

static void userDispMain(void* pvParameters){

  TickType_t xLastWakeTime = xTaskGetTickCount();
  for(;;){ 
    Serial.println(F("Display Update"));

    //////////////////////////////////////////////////////
    // Periodic code goes here


    // End of custom periodic code
    //////////////////////////////////////////////////////

    //Maintain periodic execution rate
    vTaskDelayUntil(&xLastWakeTime,TASK_USER_DISP_PERIOD_MS/portTICK_PERIOD_MS);
  }
}
