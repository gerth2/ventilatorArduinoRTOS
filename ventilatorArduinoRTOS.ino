#include "ventilatorArduinoRTOS.h"

void setup(){
  //Set up serial for debugging
  Serial.begin(DEBUG_SERIAL_BAUD);
  Serial.println(F("Starting Main Setup...."));
  Serial.println(portTICK_PERIOD_MS);

  //Set up periodic tasks
  userDispInit();
  mainCtrlInit();
    
  //Set up the idle task
  xTaskCreate(IdleTask, "IdleTask", 100, NULL, tskIDLE_PRIORITY, NULL);

  //Scheduler starts after this function exits.
}

//We can change the priority of task according to our desire by changing the numeric’s //between NULL texts.

void loop(){
  //No code should be added here - tasking takes care of everything.
  return;
}

///////////////////////////////////////////////////////////////////////////////////////
//This is the idle task:
//  -- has the lowest priority and calls when no task is running.
static void IdleTask(void* pvParameters){
  for(;;){ 
    //Serial.println(F("Idle state"));
  }  
}


///////////////////////////////////////////////////////////////////////////////////////
//Custom OS error handling hooks with serial telemetry
void vApplicationStackOverflowHook( TaskHandle_t xTask, char *pcTaskName ){
    for(;;){
        Serial.println(F("Stack Overflow!"));
        Serial.println(pcTaskName);
        _delay_ms(2000);
    }
}
