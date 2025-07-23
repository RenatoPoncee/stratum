#pragma once
#include <Arduino.h>

void setupTemperatureSensors();
bool readTemperatures(float &t1, float &t2, bool &heating);

