#ifndef MOTOR_H
#define MOTOR_H

class motor{
    private:
    int pwma;
    int  ain1;
    int ain2;
    public:
    motor(int pwml, int ain1l, int ain2l){
        pwma = pwml;
        ain1 = ain1l;
        ain2 = ain2l;

     
    }
    void begin(){
        pinMode(pwma,OUTPUT);
        pinMode(ain1,OUTPUT);
        pinMode(ain2,OUTPUT);

    }
    void forward(int speed = 100){
        analogWrite(pwma,speed);
        digitalWrite(ain1,HIGH);
        digitalWrite(ain2,LOW);
    }
    void backward(int speed = 100){
        analogWrite(pwma,speed);
        digitalWrite(ain1,LOW);
        digitalWrite(ain2,HIGH);
    }
    void stop(){
        analogWrite(pwma,0);
        digitalWrite(ain1,LOW);
        digitalWrite(ain2,LOW);
    }
};
class stndby
{
private:
    int pin;
public:
    stndby(int pinp){
        pin = pinp;
        pinMode(pin,OUTPUT);
    }
    void enable(){
        digitalWrite(pin,HIGH);
    }
    void disable(){
        digitalWrite(pin,LOW);
    }
};


#endif
