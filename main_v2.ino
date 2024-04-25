//inisialisasi
#include "globalDefinition.h"

//init gps
TinyGPSPlus gps;

//init eeprom
#define CSPIN 10 
EEPROMsimple sEEPROM;

//init SD
File file;

//SensorData
SensorData sensordata;

TaskHandle_t Task1, Task2;


void core0_task( void * parameter )
{
  //timer0_init();
  int cnt0 = 0;
  int counter0=0;
  int interval0 = 1;
  bool state0 = false;
  unsigned long prevMillis0 = millis();
  for(;;) {
    //loop code for core0
    if(millis() - prevMillis0 > interval0){
      prevMillis0 = millis();
            
      if(counter0%100 == 0){
       Serial.println(counter0);
       if(state0 == false){
          digitalWrite(18,HIGH);
          state0 = true;
       }else{
          digitalWrite(18, LOW);
          state0 = false;
       }
      }

      counter0++;
      if(counter0 > 1000){
        counter0 = 0;
      }
      
    }
  }
}

void core1_task( void * parameter )
{
//  timer1_init();
  int cnt1 = 0;
  int cnt1_prev = 0;
  bool state = false;
  int counter=0;
  int interval = 1; //100us
  uint64_t prevMillis = millis();
  for(;;) {
    //loop code for core1
    if(millis() - prevMillis > interval){
      prevMillis = millis();
      
      
      if(counter%1 == 0){
       if(state == false){
          digitalWrite(16,HIGH);
          state = true;
       }else{
          digitalWrite(16, LOW);
          state = false;
       }
      }
    }
    
    counter++;  
    if(counter > 1000){
        counter = 0;
    }
    Serial.println(millis());
    
  }
}
  
void setup() {
  Serial.begin(115200);//serial monitor
  delay(300);
  Serial1.begin(9600, SERIAL_8N1, 4, 2); //gps (rx 4, tx 2)
  delay(300);
  Serial2.begin(115200);
  Wire.begin();
  setCpuFrequencyMhz(240);
  Serial.print("CPU clock : ");
  Serial.print(getCpuFrequencyMhz());
  Serial.println(" MHz");
  
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(18, OUTPUT);
  
  gyroscope_init();
  sdcard_init();
  
  //config.txt
  configFileCheck(file);

  xTaskCreatePinnedToCore(
    core0_task,
    "core0Task",
    1000,
    NULL,
    0,
    &Task1,
    0);
  delay(500);  // needed to start-up task1


  xTaskCreatePinnedToCore(
    core1_task,
    "core1Task",
    1000,
    NULL,
    0,
    &Task2,
    1);
  
}

void loop() {
//loop code
vTaskDelete(NULL);
}
