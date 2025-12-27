\\sensor
#ifndef SENSOR_H
#define SENSOR_H

class ut1{
    public:
    int trg;
    int ech;
    private:
    ut1(int trg1, int ech1){
        trg = trg1;
        ech = ech1;
    }
    void begin(){
        pinMode(trg,OUTPUT);
        pinMode(ech,INPUT);
    }
    int read(){
        long duration;
        digitalWrite(trg,LOW);
        delayMicroseconds(2);
        digitalWrite(trg,HIGH);
        delayMicroseconds(10);
        digitalWrite(trg,LOW);
        duration = pulseIn(ech,HIGH);
        return duration*0.034/2;
        dist = duration*0.034/2;
        return distance;
    }
}

int sen1 = ut1(10,11);
int sen2 = ut1(12,13);


