#include <Arduino.h>

#define LORA_RX 15
#define LORA_TX 14
#define LORA_AUX 21
#define LORA_M0 19
#define LORA_M1 18

void setup() {
  Serial.begin(9600);
  Serial2.begin(9600, SERIAL_8N1, LORA_RX, LORA_TX);

  pinMode(LORA_M0, OUTPUT);
  pinMode(LORA_M1, OUTPUT);
  pinMode(LORA_AUX, INPUT);

  digitalWrite(LORA_M0, LOW);   // modo normal
  digitalWrite(LORA_M1, LOW);

  Serial.println("Estação pronta. Aguardando...");
}

void loop() {
  if (Serial2.available()) {
    String msg = Serial2.readStringUntil('\n');
    Serial.print("Recebido: ");
    Serial.println(msg);
  }
}
