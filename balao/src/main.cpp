#include <Arduino.h>
#include "lora_e220.h"

void setup() {
  Serial.begin(9600);
  delay(500);
  setupE220();
  sendMessage("Hello from balloon!");
}

void loop() {
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    sendMessage(input);
  }
}

