#include <Arduino_LSM9DS1.h>

#define FREQUENCY_HZ        20 //fixed
#define INTERVAL_MS         (1000 / (FREQUENCY_HZ + 1))

const float Pi = 3.14159;
float max_x, min_x, max_y, min_y, max_z, min_z = -0.9;

float raw_x, raw_y, raw_z;

void setup() {
  Serial.begin(115200);
  while (!Serial);                  // wait till the serial monitor connects
  delay(1);
  if (!IMU.begin()) {               // initialize the magnetometer
    Serial.println("Failed to initialize IMU!");
    while (1);
  }

  /*****************   For a proper functioning of the compass the magnetometer needs to be calibrated    ********************
  *****************   Replace the lines below by the output of the DIY_Calibration_Magnetometer sketch   ********************/
  IMU.setMagnetFS(0);
  IMU.setMagnetODR(8);
  IMU.setMagnetOffset(17.090454, -4.826050, -49.390869);  //  calibrated
  IMU.setMagnetSlope (1.863850, 1.854550, 1.998646);  // calibrated
  /******************************************************************************************************************************
  ****  FS  Full Scale        range (0=±400 | 1=±800 | 2=±1200 | 3=±1600  (µT)                                              *****
  ****  ODR Output Data Rate  range (6,7,8)=(40,80,400)Hz | not available on all chips (0..5): (0.625,1.25,2.5,5.0,10,20)Hz *****
  *******************************************************************************************************************************/

  IMU.magnetUnit = MICROTESLA;  //   GAUSS   MICROTESLA   NANOTESLA
}

void loop() {
  { float magY, magX, magZ;
    doNMeasurements (50, magX, magY, magZ);                               //Average measurements to reduce noise
    float heading = atan2(magX, magZ) * 180 +180/ PI;

    Serial.print("Heading ");
    Serial.println(heading);
  }
}

void doNMeasurements(unsigned int N, float & averX, float & averY, float & averZ)
{ float x, y, z;
  averX = 0; averY = 0; averZ = 0;
  for (int i = 1; i <= N; i++)
  { while (!IMU.magnetAvailable());
    IMU.readMagnet(x, y, z);
    averX += x; averY += y;  averZ += z;
  }
  averX /= N;    averY /= N;  averZ /= N;
}
