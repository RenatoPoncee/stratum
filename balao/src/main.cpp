#include <Arduino.h>
#include "lora_e220.h"
#include "magnetometer.h"
#include "gps.h"

#define PINO_DRDY 2
#define GPS_RX 8
#define GPS_TX 9
#define INTERVALO 120000UL

void setup() {
  Serial.begin(9600);
  delay(500);
  setupE220();
  setupMagnetometer(PINO_DRDY);
  setupGPS(GPS_RX, GPS_TX);
  sendMessage("Balloon ready");
}

void loop() {
  float azimute;
  float lat, lon;
  bool sent = false;

  if (readMagnetometer(azimute)) {
    String msg = "azimute=" + String(azimute, 2);
    sendMessage(msg);
    Serial.println(msg);
    sent = true;
  }

  if (readGPS(lat, lon)) {
    String msg = "lat=" + String(lat, 6) + ",lon=" + String(lon, 6);
    sendMessage(msg);
    Serial.println(msg);
    sent = true;
  }

  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    sendMessage(input);
  }

  if (sent) {
    delay(INTERVALO);
  } else {
    delay(1000);
  }
}
