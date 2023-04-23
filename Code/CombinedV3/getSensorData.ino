bool getHeading(float limit) {
  // declarations:
  float xAcc, yAcc, zAcc, xGyro, yGyro, zGyro, xMag, yMag, zMag;

  // values for orientation:
  float heading;

  // check if the IMU is ready to read:
  if (IMU.accelAvailable() && IMU.gyroAvailable() && IMU.magnetAvailable()) {

    // read accelerometer, gyroscope and magnetometer:
    IMU.readAccel(xAcc, yAcc, zAcc);
    IMU.readGyro(xGyro, yGyro, zGyro);
    IMU.readMagnet(xMag, yMag, zMag);

    // update the filter, to compute orientation:
    filter.update(xGyro, yGyro, zGyro, xAcc, yAcc, zAcc, xMag, yMag, zMag);

    // print the heading
    heading = filter.getYaw();
    Serial.println(heading);

    // determine whether the wearer is facing North within +/- limit
    if (heading >= 0 && heading <= limit) {
      return true;
    }

    if (heading < 0 && heading >= -limit) {
      return true;
    }
    return false;
  }
  return false;
}
