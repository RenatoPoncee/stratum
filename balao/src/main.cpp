#include <Arduino.h>
#include "lora_e220.h"
#include "magnetometer.h"

#define PINO_DRDY 2
#define INTERVALO 120000UL


void setup() {
  Serial.begin(9600);
  delay(500);
  setupE220();
  setupMagnetometer(PINO_DRDY);
  sendMessage("Balloon ready");
}

void loop() {
  float azimute;
  if (readMagnetometer(azimute)) {
    String msg = "azimute=" + String(azimute, 2);
    sendMessage(msg);
    Serial.println(msg);
  }

  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    sendMessage(input);
  }

  delay(INTERVALO);
}