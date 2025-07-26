#include <Arduino.h>
#include "lora_e220.h"

#define LORA_RX 15
#define LORA_TX 14
#define LORA_AUX 21
#define LORA_M0 19
#define LORA_M1 18

void setup() {
  Serial.begin(9600);
  delay(500);
  setupE220(Serial2, LORA_RX, LORA_TX, LORA_AUX, LORA_M0, LORA_M1);

  Serial.println("Waiting for messages...");
}

void loop() {
  String msg = checkForMessage();
  if (msg.length() > 0) {
    Serial.print("Mensagem recebida: ");
    Serial.println(msg);
  }
}

