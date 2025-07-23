# Stratum Projects

This repository contains two PlatformIO projects that communicate using LoRa E220 modules.

- `estacao_base` — firmware for the ground station ESP32.
- `balao` — firmware for the balloon ESP32. Sensors are organised in
  separate modules under `balao/src` (e.g. `magnetometer.cpp`, `gps.cpp`,
  `temperature_sensor.cpp`) and the main code periodically transmits the
  magnetometer azimuth, GPS coordinates and the readings from two DS18B20
  temperature sensors. A relay connected to the balloon ESP32 is activated when
  the second sensor reports 28 °C or below, indicating that the interior is being
  heated.


Both projects share a common library under `lib_shared` that wraps the
LoRa E220 driver.

Build either project with PlatformIO, for example:

```bash
pio run -d balao
pio run -d estacao_base
```
