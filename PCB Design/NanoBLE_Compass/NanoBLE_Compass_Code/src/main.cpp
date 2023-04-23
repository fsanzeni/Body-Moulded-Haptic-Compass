/*
  Quaternion implementation for a tilt-compensated compass based on the Arduino Nano 33 BLE board.
  Code by Filippo Sanzeni in partial fulfillment of his PhD Degree.

  This compass uses:
  - An Arduino Nano 33 BLE with integrated 9-DoF IMU
  - A custom PCB which includes:
    _ Battery charging circuitry
    _ Voltage regulation to a nominal 5V to power the Arduino through its VIN pin
    _ DRV2605 i2c haptic motor driver for feedback
  - An ERM DC motor
  - A custom enclosure

  This sketch uses the open-source Madgwick and Mahoney filter quaternion algorithms for calculating the rollpitch, roll and yaw.
*/

#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_LSM9DS1.h>
#include <Adafruit_Sensor.h>  // not used in this demo but required!

byte debugLed = 13;                             //set up pin 13 (inbuild LED) for debugging

//--i2c setup
Adafruit_LSM9DS1 lsm = Adafruit_LSM9DS1();
#define LSM9DS1_SCK A5
#define LSM9DS1_MISO 12
#define LSM9DS1_MOSI A4
#define LSM9DS1_XGCS 6
#define LSM9DS1_MCS 5

//--Defining offests for calibration
float
Mag_x_offset = 100.04,
Mag_y_offset = 546.62,
Mag_z_offset = -104.02,
Mag_x_scale = 1.19,
Mag_y_scale = 1.16,
Mag_z_scale = 0.77;

#define CALIBRATE

void setupSensor()
{
  // 1.) Set the accelerometer range
  lsm.setupAccel(lsm.LSM9DS1_ACCELRANGE_2G);
  //lsm.setupAccel(lsm.LSM9DS1_ACCELRANGE_4G);
  //lsm.setupAccel(lsm.LSM9DS1_ACCELRANGE_8G);
  //lsm.setupAccel(lsm.LSM9DS1_ACCELRANGE_16G);
  
  // 2.) Set the magnetometer sensitivity
  lsm.setupMag(lsm.LSM9DS1_MAGGAIN_4GAUSS);
  //lsm.setupMag(lsm.LSM9DS1_MAGGAIN_8GAUSS);
  //lsm.setupMag(lsm.LSM9DS1_MAGGAIN_12GAUSS);
  //lsm.setupMag(lsm.LSM9DS1_MAGGAIN_16GAUSS);

  // 3.) Setup the gyroscope
  lsm.setupGyro(lsm.LSM9DS1_GYROSCALE_245DPS);
  //lsm.setupGyro(lsm.LSM9DS1_GYROSCALE_500DPS);
  //lsm.setupGyro(lsm.LSM9DS1_GYROSCALE_2000DPS);
}



void setup() {
    Serial.begin(115200);

  while (!Serial) {
    delay(1); // will pause Zero, Leonardo, etc until serial console opens
  }

  setupSensor();

  #ifdef CALIBRATE
  //--start calibration routine
  Serial.println("Compass calibration routine");
  delay(1000);

  Serial.println("Place the compass on a level surface");

  #endif
}

void loop() {
  
}