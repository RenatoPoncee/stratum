#pragma once
#include <Adafruit_HMC5883_U.h>

void setupMagnetometer(uint8_t drdyPin);
bool readMagnetometer(float &azimuth);
