
//////////////////////////////////////////////////////
// These utilities are designed to activate various 
//  runtime error handling mechanisms in the OS.
//  They are for test only, and should never be invoked
//  at runtime on the production machines!
//////////////////////////////////////////////////////

  
void recursiveDeathtrap1(String printText){
  Serial.println(printText);
  recursiveDeathtrap2(printText); //whoops
}

void recursiveDeathtrap2(String printText){
  Serial.println(printText);
  recursiveDeathtrap1(printText); //whoops
}

volatile void * mallocResult = NULL;
void bigMalloc(void){
  Serial.println("BigMalloc");
  mallocResult = malloc(999);
  Serial.println((int)mallocResult);
}

volatile int divZeroResult = 0;
void divByZero(void){
  divZeroResult = 10/0;
}
