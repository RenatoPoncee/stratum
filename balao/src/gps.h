#pragma once
#include <TinyGPS++.h>

void setupGPS(int rxPin, int txPin);
bool readGPS(float &latitude, float &longitude);

