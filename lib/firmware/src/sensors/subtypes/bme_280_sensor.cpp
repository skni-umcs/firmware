#include "bme_280_sensor.h"
#include <string>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <string>
#include <sstream>
#include <iostream>

#define SEALEVELPRESSURE_HPA (1013.25)
Adafruit_BME280 bme; // I2C

unsigned long delayTime;

void BME280Sensor::setupSensor(uint32_t* delayMS) {
  Serial.begin(9600);
  Serial.println(F("BME280 test"));

  bool status;

  // default settings
  // (you can also pass in a Wire library object like &Wire2)
  status = bme.begin(0x76);
  if (!status) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }

  Serial.println("-- Default Test --");
  delayTime = 1000;

  Serial.println();

}

std::string BME280Sensor::getSensorDataJson() {
    // Get temperature event and print its value.
    sensors_event_t event;
    std::stringstream result;
    result << "humidity: " << bme.readHumidity() << " temperature: " << bme.readTemperature() << " pressure: " << bme.readPressure() << " altitude: " << bme.readAltitude(SEALEVELPRESSURE_HPA);
    return result.str();
}