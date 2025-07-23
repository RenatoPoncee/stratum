#pragma once
#include "LoRa_E220.h"

void setupE220(int rxPin, int txPin, int auxPin, int m0Pin, int m1Pin);
void sendMessage(const String& msg);
String checkForMessage();

