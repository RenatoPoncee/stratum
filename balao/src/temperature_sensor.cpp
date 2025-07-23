#include "temperature_sensor.h"
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 15
#define RELAY_PIN 26

static OneWire oneWire(ONE_WIRE_BUS);
static DallasTemperature sensors(&oneWire);
static DeviceAddress sensor1;
static DeviceAddress sensor2;

void setupTemperatureSensors() {
    sensors.begin();
    pinMode(RELAY_PIN, OUTPUT);
    digitalWrite(RELAY_PIN, LOW);
    if (!sensors.getAddress(sensor1, 0)) {
        Serial.println("Unable to find address for sensor1");
    }
    if (!sensors.getAddress(sensor2, 1)) {
        Serial.println("Unable to find address for sensor2");
    }
}

bool readTemperatures(float &t1, float &t2, bool &heating) {
    sensors.requestTemperatures();
    t1 = sensors.getTempC(sensor1);
    t2 = sensors.getTempC(sensor2);
    if (t1 == DEVICE_DISCONNECTED_C || t2 == DEVICE_DISCONNECTED_C) {
        return false;
    }
    heating = (t2 <= 28.0f);
    digitalWrite(RELAY_PIN, heating ? HIGH : LOW);
    return true;
}
