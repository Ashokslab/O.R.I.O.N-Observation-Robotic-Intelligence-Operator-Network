#ifndef IMU_H
#define IMU_H

#include <Arduino.h>
#include <Wire.h>
#include <SparkFun_ISM330DHCX.h>
#include <SparkFun_MMC5983MA_Arduino_Library.h>

class IMU {
private:
    uint8_t sdaPin;
    uint8_t sclPin;

    SparkFun_ISM330DHCX ism;
    SFE_MMC5983MA mag;

public:
    sfe_ism_data_t accel;
    sfe_ism_data_t gyro;

    uint32_t magX;
    uint32_t magY;
    uint32_t magZ;

    // Constructor
    IMU(uint8_t sda, uint8_t scl) {
        sdaPin = sda;
        sclPin = scl;
    }

    // Initialize sensors
    bool begin() {
        Wire.begin(sdaPin, sclPin);

        if (!ism.begin()) {
            Serial.println("ISM330DHCX init failed");
            while (1);
        }

        ism.deviceReset();
        while (!ism.getDeviceReset()) {
            delay(1);
        }

        ism.setAccelDataRate(ISM_XL_ODR_104Hz);
        ism.setAccelFullScale(ISM_4g);

        ism.setGyroDataRate(ISM_GY_ODR_104Hz);
        ism.setGyroFullScale(ISM_2000dps);

        if (!mag.begin(Wire)) {
            Serial.println("MMC5983MA init failed");
            while (1);
        }

        mag.softReset();
        delay(10);

        return true;
    }

    // Read all sensors
    void update() {
        ism.getAccel(&accel);
        ism.getGyro(&gyro);
        mag.getMeasurementXYZ(&magX, &magY, &magZ);
    }
};

#endif
