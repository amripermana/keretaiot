#include "globalDefinition.h"

void rs232_send_SensorData(SensorData sensor_data){
  uint8_t buffer[sizeof(sensor_data)];  
  memcpy(buffer, &sensor_data, sizeof(sensor_data));
  Serial2.write(buffer, sizeof(sensor_data));
}
