/*
Master arduino
Connect pin: A4 & A5 together on two board and a wire from Ground
Master:         Slave:
  A4-------------A4
  A5-------------A5
  GND------------GND

This arduino will send small instructions, using the <Wire.h> library

*/

#include <Wire.h>

int n_array[16][7] = {{1,1,1,1,1,1,0},//0
                      {0,1,1,0,0,0,0},//1
                      {1,1,0,1,1,0,1},//2
                      {1,1,1,1,0,0,1},//3
                      {0,1,1,0,0,1,1},//4
                      {1,0,1,1,0,1,1},//5
                      {1,0,1,1,1,1,1},//6
                      {1,1,1,0,0,0,0},//7
                      {1,1,1,1,1,1,1},//8
                      {1,1,1,0,0,1,1},//9
                      {1,1,1,0,1,1,1},//A
                      {0,0,1,1,1,1,1},//B
                      {1,0,0,1,1,1,0},//C
                      {0,1,1,1,1,0,1},//D
                      {1,0,0,1,1,1,1},//E
                      {1,0,0,0,1,1,1}};//F
//Function header
void segmentDisplay(int);
void transferData(int);

int x;
int incoming;
int led = 13;
int s_a = 2;
int s_b = 3;
int s_c = 4;
int s_d = 5;
int s_e = 6;
int s_f = 7;
int s_g = 8;
int s_dp = 9;

void setup() {
    Write.begin();
    Serial.begin(9600);
    
    pinMode(s_a, OUTPUT);
    pinMode(s_b, OUTPUT);
    pinMode(s_c, OUTPUT);
    pinMode(s_d, OUTPUT);
    pinMode(s_e, OUTPUT);
    pinMode(s_f, OUTPUT);
    pinMode(s_g, OUTPUT);
    pinMode(s_dp, OUTPUT);
    pinMode(led, OUTPUT);
}

void solidLed() {
    digitalWrite(led, HIGH);
    Serial.println("Solid");
    delay(1000);
}

void blink() {
    digitalWrite(led, HIGH);
    Serial.println("Blinking");;
    delay(1000);
    digitalWrite(led, LOW);
    delay(1000);
}

void transferData(int data) {
    Wire.beginTransmission(8);
    Wire.write(data);
    Wire.EndTransmission();
}

void segmentDisplay(int x) {
    int z = 2;
    for (int i = 0; i < x; i++) {
       digitalWrite(g, n_array[x][i]); 
    }
}

void loop() {
    // put your main code here, to run repeatedly:
    delay(300);
    //Serial.println("Arduino is live");
    if (Serial.available() > 0) {
        incoming = Serial.read();
        Serial.print("I recived: ");
        Serial.println(incoming);
    }
    if (incoming == 49) {
        blink();
    } 
    if (incoming == 50) {
        solidLed();
    }
}
