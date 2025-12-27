#include <Arduino.h>
#include <wire.h>
#include "motor.h"
#include "sensor.h"

motor m1(3,5,4);
motor m2(6,9,7);
Encoder e1(2,3);
Encoder e2(4,5);

void setup() {
  Serial.begin(115200);
  m1.begin();
  m2.begin(); 
  e1.begin();
  e2.begin();
}

void loop() {
  cmd = Serial.read();
  if(cmd = 'f'){
    m1.foward(200);
    m2.foward(200);
  }
  else if(cmd = 'b'){
    m1.backward(200);
    m2.backward(200);
  }
  else if(cmd = 'l'){
    m1.left(200);
    m2.left(200);
  }
  else if(cmd = 'r'){
    m1.right(200);
    m2.right(200);
  }
  else if(cmd = 's'){
    m1.stop();
    m2.stop();
  }

  int read1 = e1.read();
  int read2 = e2.read();
  Serial.print("Encoder 1:", read1);
  serial.print("encoder 2:", read2);
}

