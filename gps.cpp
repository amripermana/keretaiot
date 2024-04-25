#include "globalDefinition.h"


void read_gps(){
  latitude = gps.location.lat();
  longitude = gps.location.lng();
  tahun = gps.date.year();
  bulan = gps.date.month();
  tanggal = gps.date.day();
  jam = gps.time.hour();
  menit = gps.time.minute();
  detik = gps.time.second();
  String sdate = String(tanggal)+"/"+String(bulan)+"/"+String(tahun);
  logfile = "LOG" + sdate;
  filename_status = true;
}
