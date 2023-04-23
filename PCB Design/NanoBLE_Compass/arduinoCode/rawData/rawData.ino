#include <Wire.h>
#include <Arduino_LSM9DS1.h>

//GLOBAL VARIABLES
float x,y, z;

void setup() {
  Serial.begin(115200);
  while (!Serial);
  Serial.println("Started");

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }
}

void loop() {
  IMU.readMagneticField(x, y, z);

  float pi = 3.14159;

  // Calculate the angle of the vector y,x
  float heading = (atan2(y, x) * 180) / pi;

//  if (heading < 0)
//  {
//    heading = 360 + heading;
//  }
  Serial.print("Heading: ");
  Serial.println(heading);
}
