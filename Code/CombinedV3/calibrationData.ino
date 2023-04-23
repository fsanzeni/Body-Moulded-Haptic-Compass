// Accelerometer code
void calibrateAccel() {
  IMU.setAccelFS(3);
  IMU.setAccelODR(5);
  IMU.setAccelOffset(-0.008551, -0.024864, -0.009728);
  IMU.setAccelSlope (0.999645, 0.987011, 1.002797);
}

// Gyroscope code
void calibrateGyro() {
  IMU.setGyroFS(2);
  IMU.setGyroODR(5);
  IMU.setGyroOffset (0.416077, 0.406372, -0.806793);
  IMU.setGyroSlope (1.108250, 1.176817, 1.088161);
}

// Magnetometer code
void calibrateMagnet() {
  IMU.setMagnetFS(0);
  IMU.setMagnetODR(8);
  IMU.setMagnetOffset(3.919067, -8.062744, -50.018311);
  IMU.setMagnetSlope (1.007664, 1.194453, 1.400537);
}
