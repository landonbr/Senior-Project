#include <Servo.h>

Servo myservo;  // create servo object to control a servo

#define servoPin 9

/* variables */
int start = 17;     // starting position of servo
int angle = 45;     // turn angle (i.e pin ON)
int pos = 0;        // variable to store the servo position
int overshoot = 5;  // reset state of pin after angle rotationi (i.e pin OFF)

void setup() {
  myservo.attach(servoPin);  // attaches the servo on pin 9 to the servo object
}

// sweeping motion
void rotate() {
  // 0 degrees to (45+5) in steps of 1 degree per 15ms
  for (pos = start; pos <= angle+overshoot; pos += 1) { 
    myservo.write(pos);   
    delay(15);    // speed of rotation - 15ms
  }
}

// this loop continuosly raises the left front pin and resets to starting posiotn every 2s
void loop() {
  myservo.write(start);   // start position
  delay(2000);
  rotate();               // raise left front pin (letter a) and reset
  delay(2000);
}

//void loop() {
  //myservo.write(0);
  //myservo.write(start);
  //delay(10000);
//}

