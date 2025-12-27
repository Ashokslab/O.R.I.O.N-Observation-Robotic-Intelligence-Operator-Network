#ifndef MOTOR_H
#define MOTOR_H


class motor1{
    private:
        int in1;
        int in2;
        int in3;
        int in4;
        int pwm1;
        int pwm2;
    public:
    motor1(int in1p, int in2p, int in3p, int in4p, int pwm1p, int pwm2p){
        in1 = in1p;
        in2 = in2p; 
        in3 = in3p;
        in4 = in4p;
        pwm1 = pwm1p;
        pwm2 = pwm2p;
    }
    void begin(){
     pinMode(in1,OUTPUT);
     pinMode(in2,OUTPUT);
     pinMode(pwm1,OUTPUT);
}
void foward(int speed = 225){
    speed = constrain(speed 0,255);
    analogWrite(pwm1,255);
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
}
void backward(int speed =255){
    speed = constrain(speed 0,255);
    analogWrite(pwm1,speed);
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH); 
    digitalwrite(in3,LOW);
    digitalwrite(in4,HIGH);
}
void right(int speed =255){
    speed = constrain(speed 0,255);
    analogWrite(pwm1,speed);
    analogWrite(pwm2,speed);
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW); 
    digitalwrite(in3,LOW);
    digitalwrite(in4,HIGH);
}
void left(int speed =255){
    speed = constrain(speed 0,255);
    analogWrite(pwm1,speed);
    analogWrite(pwm2,speed);
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH); 
    digitalwrite(in3,HIGH);
    digitalwrite(in4,LOW);
}
void stop(){
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);
}
};


class Encoder1 {
private:
    int pinA;
    int pinB;

public:
    Encoder(int a, int b) {
        pinA = a;
        pinB = b;
    }

    void begin() {
        pinMode(pinA, INPUT);
        pinMode(pinB, INPUT);
    }

    int read() {
        int valA = analogRead(pinA);
        int valB = analogRead(pinB);
        return valA - valB;
    }
};


class Encoder2{
private:
    int pinA;
    int pinB;

public:
    Encoder1(int a, int b) {
        pinA = a;
        pinB = b;
    }

    void begin() {
        pinMode(pinA, INPUT);
        pinMode(pinB, INPUT);
    }

    int read() {
        int valA = analogRead(pinA);
        int valB = analogRead(pinB);
        return valA - valB;
    }
};
