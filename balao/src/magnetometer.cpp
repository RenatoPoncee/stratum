#include "magnetometer.h"
#include <Wire.h>

static uint8_t s_drdyPin = 2;
static Adafruit_HMC5883_Unified s_mag = Adafruit_HMC5883_Unified(12345);

static float calculateAzimuth(float x, float y) {
    float angle = atan2(y, x) * 180.0 / PI;
    if (angle < 0) {
        angle += 360.0;
    }
    return angle;
}

void setupMagnetometer(uint8_t drdyPin) {
    s_drdyPin = drdyPin;
    Wire.begin();
    pinMode(s_drdyPin, INPUT);
    s_mag.begin();
}

bool readMagnetometer(float &azimuth) {
    if (digitalRead(s_drdyPin) == HIGH) {
        sensors_event_t event;
        s_mag.getEvent(&event);
        azimuth = calculateAzimuth(event.magnetic.x, event.magnetic.y);
        return true;
    }
    return false;
}
