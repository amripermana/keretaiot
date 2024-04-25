#include <Arduino.h>

int tahun, bulan, tanggal, jam, menit, detik;
int saveAddress = 0;
int logStatus = 0;
int fifoWriteCounter = 0;
int fifoReadCounter = 0;
int timer_counter = 0;
int SRV_PORT = 0;
int FLAG_SERVER;
int counter_timer0=1;
int counter_timer1=1;
int cnt1 = 0;
int cnt0 = 0;

byte byteData[50];
byte byteDataRead[50];
byte DEVICE_ID[10];
byte DEVICE_ADDRESS;
byte NETWORK_TYPE;
byte SLAVE_CONNECTION;
byte GERBONG_NR;
byte DEVICE_POS;

float latitude, longitude;
float accelx, accely, accelz, gyrox, gyroy, gyroz;
float distance = 30;
float prev_lat = 0;
float prev_long = 0;
float new_lat = 0;
float new_long = 0;

bool isGpsValid = false;
bool filename_status = false;
bool timer1_1000ms = false;

String logfile = "";
String SRV_NAME = "0";
String WIFI_NAME = "0";
String WIFI_PWD = "0";

portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;

hw_timer_t * timer0 = NULL; 
hw_timer_t * timer1 = NULL; 
