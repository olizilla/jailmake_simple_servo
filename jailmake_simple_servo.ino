#include <Servo.h>

int loopDelay = 20; // Change me for smother moves. Less than 50 seems to cause the servo some confusion.
int pause = 3000;
int openPause = 500;
int openPos = 60;
int closedPos = 150;
int currentPos = closedPos;

Servo s1;
int servoPin = 9;

boolean running = true;

void setup() {
  // nothing to do yet
}

void loop() {
  if(running){
    openAndClose();
//reset();
  }  
}

void openAndClose() {
  
  s1.attach(servoPin);
  
  for (; currentPos <= closedPos; currentPos++){
    s1.write(currentPos);
    delay(loopDelay);
  }

  s1.detach();  
  
  delay(pause);
  
  s1.attach(servoPin);

  for (; currentPos >= openPos; currentPos--){
    s1.write(currentPos);
    delay(loopDelay);
  }  

  delay(openPause); 
}

void reset() {
  Serial.begin(9600);
  s1.attach(servoPin);
  int pos = s1.read();
  Serial.println(pos);
}
