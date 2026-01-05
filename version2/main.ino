
#include "motor.h"
#include "imu.h"

motor rm(38,36,37);
motor lm(8,46,3);
stndby sb1(10);
imu myIMU(17,18);

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("System Initialized");
  rm.begin();
  lm.begin();
  myIMU.begin();
  sb1.disable();

}

void loop() {
  if(Serial.available() > 0){
  char cmd = Serial.read();
  if (cmd == 'f'){
      sb1.enable();
      rm.forward(200);
      lm.forward(200);
      Serial.println("Motor moving forward");
  }
  else if (cmd == 'b'){
      sb1.enable();
      rm.backward(200);
      lm.backward(200);
      Serial.println("Motor moving backward");
  }
  else if (cmd == 's'){
      rm.stop();
      lm.stop();
      sb1.disable();
      Serial.println("Motor stopped");
  }
  else if (cmd == 'l'){
      sb1.enable();
      lm.forward(200);
      rm.backward(200);
      Serial.println("Turning left");
  }
  else if (cmd == 'r'){
      sb1.enable();
      lm.backward(200);
      rm.forward(200);
      Serial.println("Turning right");
  }
}
  myIMU.update();
  Serial.print("Accel X: "); Serial.print(myIMU.accel.x); 
  Serial.print(" Y: "); Serial.print(myIMU.accel.y); 
  Serial.print(" Z: "); Serial.println(myIMU.accel.z); 

  Serial.print("Gyro X: "); Serial.print(myIMU.gyro.x); 
  Serial.print(" Y: "); Serial.print(myIMU.gyro.y); 
  Serial.print(" Z: "); Serial.println(myIMU.gyro.z); 

  Serial.print("Mag X: "); Serial.print(myIMU.magn.x); 
  Serial.print(" Y: "); Serial.print(myIMU.magn.y); 
  Serial.print(" Z: "); Serial.println(myIMU.magn.z); 

  delay(500);
}

