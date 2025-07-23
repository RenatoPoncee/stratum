#include "lora_e220.h"
#include "Arduino.h"

#define RXD2 15
#define TXD2 14
#define AUX  21
#define M0   19
#define M1   18

LoRa_E220 e220ttl(&Serial2, AUX, M0, M1);

void setupE220() {
  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);
  e220ttl.begin();
  e220ttl.setMode(MODE_0_NORMAL);
}

void sendMessage(const String& msg) {
  ResponseStatus rs = e220ttl.sendBroadcastFixedMessage(23, msg);
  Serial.println(rs.getResponseDescription());
}

String checkForMessage() {
  if (e220ttl.available() > 1) {
    ResponseContainer rc = e220ttl.receiveMessage();
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

