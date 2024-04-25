
#ifndef GLOBALVARIABLES_H
#define GLOBALVARIABLES_H

#include <Arduino.h>
extern float latitude, longitude;
extern int tahun, bulan, tanggal, jam, menit, detik;
extern float accelx, accely, accelz, gyrox, gyroy, gyroz;
extern byte byteData[50];
extern byte byteDataRead[50];
extern bool isGpsValid;
extern int saveAddress;
extern float distance, prev_lat, prev_long, new_lat, new_long;
extern bool filename_status;
extern String logfile;
extern int logStatus;
extern int fifoReadCounter;
extern int fifoWriteCounter;
extern byte DEVICE_ID[10];
extern byte DEVICE_ADDRESS;
extern byte NETWORK_TYPE;
extern byte SLAVE_CONNECTION;
extern int timer_counter;
extern String SRV_NAME;
extern String WIFI_NAME;
extern String WIFI_PWD;
extern int SRV_PORT;
extern byte GERBONG_NR;
extern byte DEVICE_POS;
extern int FLAG_SERVER;
extern int counter_timer0;
extern int counter_timer1;
extern int cnt0;
extern int cnt1;
extern hw_timer_t * timer0;
extern hw_timer_t * timer1;
extern bool timer1_1000ms;
extern portMUX_TYPE timerMux;

struct SensorData {
    uint16_t header; // 2 byte
    uint8_t id;      // 1 byte
    uint8_t length;  // 1 byte
    uint16_t year;  
    uint16_t month;   
    uint16_t day; 
    uint16_t hour;  
    uint16_t minute;   
    uint16_t second;
    uint32_t latitude;  
    uint32_t longitude;   
    uint32_t accelx;
    uint32_t accely;
    uint32_t accelz;
    uint32_t gyrox;
    uint32_t gyroy;
    uint32_t gyroz;    
    uint8_t checksum; // Checksum
    uint16_t footer; // 2 byte
};


#endif
