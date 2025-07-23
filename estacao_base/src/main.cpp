#include <Arduino.h>
#include "lora_e220.h"

void setup() {
  Serial.begin(9600);
  delay(500);
  setupE220();
  Serial.println("Waiting for messages...");
}

void loop() {
  String msg = checkForMessage();
  if (msg.length() > 0) {
    Serial.print("Mensagem recebida: ");
    Serial.println(msg);
  }
}

