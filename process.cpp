#include "globalDefinition.h"

int distanceCalc(int plat, int plong, int nlat, int nlong){
  //distance calc
  float jarak = 1.0;
  //end of distance calc
  return jarak;
}

void createContainer(){
  sensorData.id = 0x3232;
  sensorData.id = 0x01;
  sensorData.length = 0x01; //create function length
  memcpy(&sensorData.latitude, &byteData[0], sizeof(float));
  memcpy(&sensorData.longitude, &byteData[4], sizeof(float));
  memcpy(&sensorData.year, &byteData[8], 2);
  memcpy(&sensorData.month, &byteData[10], 2);
  memcpy(&sensorData.day, &byteData[12], 2);
  memcpy(&sensorData.hour, &byteData[14], 2);
  memcpy(&sensorData.minute, &byteData[16], 2);
  memcpy(&sensorData.second, &byteData[18], 2);  
  memcpy(&sensorData.accelx, &byteData[20], sizeof(float));
  memcpy(&sensorData.accely, &byteData[24], sizeof(float));
  memcpy(&sensorData.accelz, &byteData[28], sizeof(float));
  memcpy(&sensorData.gyrox, &byteData[32], sizeof(float));
  memcpy(&sensorData.gyroy, &byteData[36], sizeof(float));
  memcpy(&sensorData.gyroz, &byteData[40], sizeof(float));
  sensorData.checksum = 0x01; //create function checksum
  sensorData.footer = 0xFFFF;
}
