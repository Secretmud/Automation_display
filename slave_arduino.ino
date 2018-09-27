/*
Slave arduino

This is might be used as a way of controlling a couple of motors. Not sure yet.

Slave:      Master:
  A4----------A4
  A5----------A5

  GND---------GND


*/

#include <Wire.h>

void setup() {
    Wire.begin(8);
    Wire.onRecieve(recieveEvent);
    Serial.begin(9600);
}

void loop() {
    delay(100);
}

void recieveEvent(int howMany) {
    while(1<Wire.available()) {
        char c = Wire.read();
        Serial.print(c);
    }
    int x = Wire.read();
    Serial.println(c, HEX);
}
