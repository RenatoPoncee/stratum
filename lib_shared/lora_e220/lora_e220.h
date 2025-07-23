#pragma once
#include "LoRa_E220.h"

void setupE220();
void sendMessage(const String& msg);
String checkForMessage();

