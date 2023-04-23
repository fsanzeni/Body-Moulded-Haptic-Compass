#include <Wire.h>
#include "Adafruit_DRV2605.h"
#include <Arduino_LSM9DS1.h>
#include "MadgwickAHRS.h"

//initialise haptic motor
Adafruit_DRV2605 drv;

// initialize a Madgwick filter:
Madgwick filter;

// sensor's sample rate is fixed at 104 Hz:
const float sensorRate = 104.00;

const float beta = 0.1;

// keep track of time and sample multiple times to get accurate triggering
unsigned long time_now = 0;
const int samplingTime = 200;

// bool set as TRUE if wearer is facing north within the specified cone of operation
bool north = false;

// cone of operation expressed in DEGREES
const float limit = 2.0;

void setup() {
  Serial.begin(9600);
  // attempt to start the IMU:
  if (!IMU.begin()) {
    Serial.println(F("Failed to initialize IMU"));
    // stop here if you can't access the IMU:
    while (true);
  }

  //start the haptic motor object
  drv.begin();
  drv.selectLibrary(1);

  // I2C trigger by sending 'go' command
  drv.setMode(DRV2605_MODE_INTTRIG); // default, internal trigger when sending GO command

  // start the filter to run at the sample rate:
  filter.begin(sensorRate, beta);

}

void loop() {
  time_now = millis();
  while (millis() < time_now + samplingTime) {
    north = getHeading(limit);
  }

  north = getHeading(limit);

  switch (north) {
    case false:
      north = getHeading(limit);
      break;

    case true:
      if (playSingleWaveform(1, 500) == true) {
        north = getHeading(limit);
      }
      break;
  }
}
