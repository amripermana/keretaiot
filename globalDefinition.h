
#ifndef GLOBALDEFINITION_H
#define GLOBALDEFINITION_H

#include <Arduino.h>
#include <EEPROMsimple.h>
#include <TinyGPS++.h>
#include <Wire.h>
#include <arduino-timer.h>
#include <SPI.h>
#include <SD.h>
#include "globalVariables.h"
//#include <esp32-hal-timer.h>
#include <esp_timer.h>
#include "esp32-hal-cpu.h"

#define CHECK 0
#define CREATE 1
#define OPEN 2
#define READ 3
#define WRITE 4
#define CLOSE 5

#define GSM_ 0
#define WIFI_ 1
#define NO_SLAVE 0
#define RS_485 1
#define ZIGBEE 2

#define FLAG_FREE 0
#define FLAG_SENSOR 1
#define FLAG_FIFO 2
#define FLAG_LOG 3
#define FLAG_SLAVE 4
#define FLAG_SERVER 5


extern EEPROMsimple sEEPROM;
extern TinyGPSPlus gps;
extern SensorData sensorData;

//process
int distanceCalc(int plat, int plong, int nlat, int nlong);
void createContainer();

//gps
void read_gps();

//gyroscope
void gyroscope_init();
void read_accel();
void read_gyro();

//fifo
void merge_fifo_bytes();
void putFIFO();
void readFIFO();
void sortingFIFO();

//datalogging
void sdcard_init();
void data_logging();

//config.txt
void configFileCheck(File file);

//rs232
void rs232_send_SensorData(SensorData sensor_data);

//timer
void onTimer0();
void timer0_init();
void onTimer1();
void timer1_init();


#endif
