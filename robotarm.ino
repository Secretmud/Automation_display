#include <Servo.h> 
Servo turn;  // create servo object to control a servo 
Servo up;
Servo tilt;
int move_arm(int);
int x = 0;
int angle = 0;
void setup() {
  Serial.begin(9600);
  turn.attach(9);
  up.attach(15, 0, 180);
  tilt.attach(11, 0, 180);
}
int move_arm(int x) {
  return x + 5;
}

void loop() {
  for(angle = 0; angle < 180; angle += 1)    // command to move from 0 degrees to 180 degrees 
  {                                  
    turn.write(angle);                 //command to rotate the servo to the specified angle
    delay(15);                       
  } 
 
  delay(1000);
  
  for(angle = 180; angle>=1; angle-=5)     // command to move from 180 degrees to 0 degrees 
  {                                
    turn.write(angle);              //command to rotate the servo to the specified angle
    delay(5);                       
  } 

    delay(1000);
}
