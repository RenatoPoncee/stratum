#include "gps.h"
#include <Arduino.h>

static TinyGPSPlus s_gps;
static HardwareSerial s_gpsSerial(1);
static int s_rxPin;
static int s_txPin;

void setupGPS(int rxPin, int txPin) {
    s_rxPin = rxPin;
    s_txPin = txPin;
    s_gpsSerial.begin(9600, SERIAL_8N1, s_rxPin, s_txPin);
}

bool readGPS(float &latitude, float &longitude) {
    while (s_gpsSerial.available()) {
        if (s_gps.encode(s_gpsSerial.read())) {
            if (s_gps.location.isValid()) {
                latitude = s_gps.location.lat();
                longitude = s_gps.location.lng();
                return true;
            }
        }
    }
    return false;
}

