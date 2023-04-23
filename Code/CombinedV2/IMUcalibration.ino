void calibrateIMUSetup() {
  Serial.begin(9600);
  while (!Serial); //wait for connection

  Wire.begin();

  if (IMU.begin() == false) // with no arguments, this uses default addresses (AG:0x6B, M:0x1E) and i2c port (Wire).
  {
    Serial.println(F("LSM9DS1 not detected"));
    while (1);
  }
  Serial.println("Collecting gyro data, hold still");
  delay(3000);
  // get gyro offset
  long gxa = 0, gya = 0, gza = 0;
  float gX, gY, gZ;
  for (int i = 0; i < 300; i++) {
    if ( IMU.gyroAvailable() )
    {

      IMU.readRawGyro(gX, gY, gZ);
      gxa += (int)gX;
      gya += (int)gY;
      gza += (int)gZ;
      Serial.print(gxa);
      Serial.print(", ");
      Serial.print(gya);
      Serial.print(", ");
      Serial.println(gza);
    }
  }
  Serial.println(F("gyro offsets"));
  Serial.print(gxa / 300);
  Serial.print(", ");
  Serial.print(gya / 300);
  Serial.print(", ");
  Serial.println(gza / 300);
  Serial.println();

  Serial.println(F("rotate slowly and carefully in 3D"));
  delay(3000);
  Serial.println("starting");
}

void calibrateIMU() {
  static int n = 0; //count values transmitted
  // Update the sensor values whenever new data is available

  float aX, aY, aZ, mX, mY, mZ;

  if ( IMU.accelAvailable() )
  {
    // To read from the accelerometer, first call the
    // readAccel() function. When it exits, it'll update the
    // ax, ay, and az variables with the most current data.
    IMU.readRawAccel(aX, aY, aZ);
  }
  if ( IMU.magneticFieldAvailable() )
  {
    IMU.readRawMagnet(mX, mY, mZ);
  }

  if (millis() - lastPrint > PRINT_SPEED)
  {
    Serial.print(aX);
    Serial.print(", ");
    Serial.print(aY);
    Serial.print(", ");
    Serial.print(aZ);
    Serial.print(", ");
    Serial.print(mX);
    Serial.print(", ");
    Serial.print(mY);
    Serial.print(", ");
    Serial.println(mZ);
    if (n++ > 299) {
      Serial.println("Done.");
      while (1); //hang here
    }
    lastPrint = millis(); // Update lastPrint time
  }
}
