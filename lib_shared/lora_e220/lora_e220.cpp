#include "lora_e220.h"
#include "Arduino.h"

LoRa_E220* e220ttl = nullptr;

void setupE220(HardwareSerial& serial, int rxPin, int txPin, int auxPin,
               int m0Pin, int m1Pin) {
  serial.begin(9600, SERIAL_8N1, rxPin, txPin);
  delete e220ttl;
  e220ttl = new LoRa_E220(&serial, auxPin, m0Pin, m1Pin);
  e220ttl->begin();
  e220ttl->setMode(MODE_0_NORMAL);
}

void sendMessage(const String& msg) {
  if (!e220ttl) return;
  ResponseStatus rs = e220ttl->sendBroadcastFixedMessage(23, msg);

  Serial.println(rs.getResponseDescription());
}

String checkForMessage() {
  if (e220ttl && e220ttl->available() > 1) {
    ResponseContainer rc = e220ttl->receiveMessage();

    if (rc.status.code != 1) {
      Serial.println(rc.status.getResponseDescription());
    } else {
      Serial.println("Recebido:");
      Serial.println(rc.data);
      return rc.data;
    }
  }
  return "";
}

