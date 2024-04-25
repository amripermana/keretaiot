#include "globalDefinition.h"

void timer0_init(){
  // Inisialisasi dan konfigurasi timer 0
  timer0 = timerBegin(0, 80, true); 
  timerAttachInterrupt(timer0, &onTimer0, true); 
  timerAlarmWrite(timer0, 10000, true); 
  timerAlarmEnable(timer0);
}

void timer1_init(){
  // Inisialisasi dan konfigurasi timer 1
  timer1 = timerBegin(1, 80, true); 
  timerAttachInterrupt(timer1, &onTimer1, true); 
  timerAlarmWrite(timer1, 1000, true); // 1000us = 1ms
  timerAlarmEnable(timer1); 
}

void onTimer0() {
  counter_timer0++;
  if(counter_timer0 > 1000){
    counter_timer0 = 1;
  }

//  if(digitalRead(18) == HIGH){
//    digitalWrite(18, LOW);
//  }
//  else{
//    digitalWrite(18, HIGH);
//  }

}

void onTimer1() {  
  counter_timer1++;
  if(counter_timer1 > 1000){
    counter_timer1= 1;
  }
//
//  if(digitalRead(16) == HIGH){
//    digitalWrite(16, LOW);
//  }
//  else{
//    digitalWrite(16, HIGH);
//  }
}
