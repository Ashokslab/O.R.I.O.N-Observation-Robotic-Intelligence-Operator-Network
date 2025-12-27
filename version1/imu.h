#ifndef
#define IMU_H
#include <Wire.h>
#include <Arduino.h>
#include <ICM_20948.h>


calss imu(){
    private:
     int sda;
        int scl;
    float accelX, accelY, accelZ;
    float gyroX, gyroY, gyroZ;
    float magnX, magnY, magnZ;
    public:
    imu(int sdap, int sclp){
        sda = sdap;
        scl = sclp;
    }
    bool begin(){
        imu.begin(wire, 0x6B);
        imu.initilize();
        imu.setfullscaleGyroRange(ICM_20948_GYRO_FS_2000DPS);
        imu.setfullscaleAccelRange(ICM_20948_ACCEL_FS_16G);
        return imu testconnections();
    }
    void update(){
        int16_t ax, ay, az;
        int16_t gx, gy, gz; 
        int16_t mx, my, mz;
        imu.readSensor();
        imu.getAGMT(&ax, &ay, &az, &gx, &gy, &gz, &mx, &my, &mz);
         // Accel: ±16g → 2048 LSB/g
    accelX = (float)ax / 2048.0;
    accelY = (float)ay / 2048.0;
    accelZ = (float)az / 2048.0;

    // Gyro: ±2000 dps → 16.4 LSB/dps
    gyroX = (float)gx / 16.4;
    gyroY = (float)gy / 16.4;
    gyroZ = (float)gz / 16.4;

    // Magnetometer (raw, calibrate later)
    magnX = (float)mx;
    magnY = (float)my;
    magnZ = (float)mz;
    }
    int read(){

        return 0;
        
    }

}


int imu1 = imu( SDA, SCL);

Serial.bregin(115200);
if(imu1.begin()){
    Serial.println("IMU initialized successfully");
}else{
    Serial.println("IMU initialization failed");        
}

 void loop(){
     imu1.update();
     Serial.print("Accel (g): ");
     Serial.print(imu1.accelX); Serial.print(", ");
     Serial.print(imu1.accelY); Serial.print(", ");
     Serial.println(imu1.accelZ);

     Serial.print("Gyro (dps): ");
     Serial.print(imu1.gyroX); Serial.print(", ");
     Serial.print(imu1.gyroY); Serial.print(", ");
     Serial.println(imu1.gyroZ);

     Serial.print("Magnetometer (raw): ");
     Serial.print(imu1.magnX); Serial.print(", ");
     Serial.print(imu1.magnY); Serial.print(", ");
     Serial.println(imu1.magnZ);

     delay(1000);
 }
#endif
