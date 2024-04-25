#include "globalDefinition.h"

void sdcard_init(){
  /////////////////SD Card Init//////////////////////// 
  Serial.println("Initializing SD card...");
  if (!SD.begin(5)) { //CS SD 5
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");
}

void data_logging(String filename, File file1){
  switch(logStatus) {
    case CHECK:
      //code
      if (SD.exists(filename)) {
        filename_status = true;
      }
      else {
        filename_status = false;
      }
      break;
    case CREATE:
      file1 = SD.open(filename, FILE_WRITE);
      file1.close();
      break;
    case OPEN:
      file1 = SD.open(filename);
      break;
    case READ:
      
      break;
    case WRITE:
      //code
      break;
    case CLOSE:
      //code
      break;
  }
}
