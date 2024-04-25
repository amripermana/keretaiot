#include "globalDefinition.h"

void gyroscope_init(){
  Wire.beginTransmission(0x68);
  Wire.write(0x6B); 
  Wire.write(0x00);
  Wire.endTransmission(true);
}

void read_accel(){
  Wire.beginTransmission(0x68);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(0x68, 6, true); 
  accelx = (Wire.read() << 8 | Wire.read()) / 16384.0;
  accely = (Wire.read() << 8 | Wire.read()) / 16384.0; 
  accelz = (Wire.read() << 8 | Wire.read()) / 16384.0;
}

void read_gyro(){
  Wire.beginTransmission(0x68);
  Wire.write(0x43); 
  Wire.endTransmission(false);
  Wire.requestFrom(0x68, 6, true);
  gyrox = (Wire.read() << 8 | Wire.read()) / 131.0; 
  gyroy = (Wire.read() << 8 | Wire.read()) / 131.0;
  gyroz = (Wire.read() << 8 | Wire.read()) / 131.0;
  gyrox = gyrox + 0.56; // GyroErrorX ~(-0.56)
  gyroy = gyroy - 2; // GyroErrorY ~(2)
  gyroz = gyroz + 0.79; // GyroErrorZ ~ (-0.8)
}
