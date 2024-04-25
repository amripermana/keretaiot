#include "globalDefinition.h"

void configFileCheck(File file){
  if (SD.exists("config.txt")) {
        if (file) {
          while (file.available()) {
            Serial2.write(file.read());
          }
          file.close(); // Tutup file setelah dibaca
        } else {
          Serial.println("Error read file config.txt.");
        }
      }
      else {
        file = SD.open("config.txt", FILE_WRITE);
        file.println("ID = 0123456789");
        file.println("ADD = 0");
        file.println("TYPE = 0");
        file.println("SLAVE = 0");
        file.println("SRV_NAME = 0");
        file.println("SRV_PORT = 0");
        file.println("WIFI_NAME = 0");
        file.println("WIFI_PWD = 0");
        file.println("GERBONG_NR = 0");
        file.println("DEVICE_POS = 0");
        file.close();
      }
}
