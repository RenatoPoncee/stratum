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

  Serial.println("Balão pronto");
}

void loop() {
  static float temp = 25.0;
  char buffer[16];
  sprintf(buffer, "TEMP:%.1f", temp);
  Serial2.println(buffer);
  Serial.print("Enviado: ");
  Serial.println(buffer);

  temp += 0.1; // simula mudança de temperatura
  delay(5000);
}
