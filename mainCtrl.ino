#include "ventilatorArduinoRTOS.h"

// Main Control Loop Task Configuration
#define TASK_MAIN_CTRL_LOOP_FCN mainCtrlMain
#define TASK_MAIN_CTRL_NAME    "Main Ctrl"
#define TASK_MAIN_CTRL_STACK_SZ_WORDS 500
#define TASK_MAIN_CTRL_PRIORITY  (configMAX_PRIORITIES - 1) //Main control loop task is highest priority
#define TASK_MAIN_CTRL_PERIOD_MS 64


void mainCtrlInit(void){
  //////////////////////////////////////////////////////
  // One-Time Init Goes Here

  // End of one-time init code
  //////////////////////////////////////////////////////
  
  xTaskCreate(TASK_MAIN_CTRL_LOOP_FCN, 
              TASK_MAIN_CTRL_NAME, 
              TASK_MAIN_CTRL_STACK_SZ_WORDS,
              NULL, 
              TASK_MAIN_CTRL_PRIORITY, 
              NULL);
}

static void mainCtrlMain(void* pvParameters){

  TickType_t xLastWakeTime = xTaskGetTickCount();
  for(;;){ 
    Serial.println(F("Main Control Update"));

    //////////////////////////////////////////////////////
    // Periodic code goes here


    // End of custom periodic code
    //////////////////////////////////////////////////////

    //Maintain periodic execution rate
    vTaskDelayUntil(&xLastWakeTime,TASK_MAIN_CTRL_PERIOD_MS/portTICK_PERIOD_MS);
  }
}
