# Smart Irrigation System

This project is an IoT-based solution for monitoring soil moisture, temperature, and humidity using an ESP32 microcontroller. It uses a soil moisture sensor and a DHT sensor to collect data and sends the readings to the Blynk IoT platform for remote monitoring. The system is ideal for automating irrigation systems to optimize water usage in agriculture or gardening.

---

## Features
- **Soil Moisture Monitoring**: Displays real-time soil moisture levels in percentage.
- **Temperature and Humidity Monitoring**: Provides environmental data for better irrigation management.
- **Remote Monitoring**: Data is sent to the Blynk app, enabling access from anywhere.
- **Flexible Sensor Support**: Supports DHT11 or DHT22 sensors for temperature and humidity readings.
- **User-Friendly Interface**: Easy-to-read data on the Serial Monitor and Blynk app.

---

## Hardware Requirements
- **ESP32 Microcontroller**
- **Soil Moisture Sensor** (Analog output)
- **DHT Sensor** (DHT11 or DHT22)
- Breadboard and connecting wires
- Power source (e.g., USB cable or battery)

---

## Pin Connections

| Component             | ESP32 Pin    |
|-----------------------|--------------|
| Soil Moisture Sensor  | GPIO 34 (Analog) |
| DHT Sensor VCC        | 3.3V or 5V   |
| DHT Sensor GND        | GND          |
| DHT Sensor Signal     | GPIO 27      |

---

## Software Requirements
- Arduino IDE (with ESP32 board package installed)
- Blynk Library (`BlynkSimpleEsp32.h`)
- DHT Library (`DHT.h`)
