int incoming;
int led = 13;
void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  Serial.begin(9600);
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
  } else {
    solidLed();
  }
}
