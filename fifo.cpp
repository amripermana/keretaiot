#include "globalDefinition.h"

void merge_fifo_bytes(){
  memcpy(&byteData[0], &latitude, sizeof(float));
  memcpy(&byteData[4], &longitude, sizeof(float));
  memcpy(&byteData[8], &tahun, 2);
  memcpy(&byteData[10], &bulan, 2);
  memcpy(&byteData[12], &tanggal, 2);
  memcpy(&byteData[14], &jam, 2);
  memcpy(&byteData[16], &menit, 2);
  memcpy(&byteData[18], &detik, 2);
  memcpy(&byteData[20], &accelx, sizeof(float));
  memcpy(&byteData[24], &accely, sizeof(float));
  memcpy(&byteData[28], &accelz, sizeof(float));
  memcpy(&byteData[32], &gyrox, sizeof(float));
  memcpy(&byteData[36], &gyroy, sizeof(float));
  memcpy(&byteData[40], &gyroz, sizeof(float));  
}

void putFIFO(){
  int limit = saveAddress+50;
  int index = 0;
  for(saveAddress; saveAddress < limit; saveAddress++){
    sEEPROM.WriteByte(saveAddress, byteData[index]);
    index++;
  }
  if(saveAddress > 1500){
    saveAddress = 0;
  }
  fifoReadCounter = saveAddress;
}

void readFIFO(){
  int limit = fifoReadCounter + 50;
  for (int i = fifoReadCounter ; i<limit ; i++){
    byteDataRead[i] = sEEPROM.ReadByte(i);
  }
}

void sortingFIFO(){
  for(int i=0; i<1500;i++){ //50 byte, 30 datapacket
    byte prevbyte = sEEPROM.ReadByte(i);
    sEEPROM.WriteByte(i+50, prevbyte);
  }
 
}
