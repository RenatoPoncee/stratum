# Stratum Projects

This repository contains two PlatformIO projects that communicate using LoRa E220 modules.

- `estacao_base` — code that runs on the ground station ESP32.
- `balao` — code that runs on the balloon ESP32.

Both projects share a common library under `lib_shared` that wraps the LoRa E220 driver.

Each project has its own `platformio.ini` so they can be built independently using PlatformIO.

