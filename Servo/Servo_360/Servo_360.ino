// basic demonstration of controling direction of 360 servo: cw, ccw, stop
// enable 'no line ending' in the serial monitor to avoid recieving a new line 
// byte that will be interpreted in the rotation
#include <Servo.h>

Servo myservo;  // create servo object to control a servo

#define servoPin 9

/* variables */
int pos = 0;  // variable to store the servo position
char incomingByte = 0; // serial data 


void setup() {
  Serial.begin(9600);
  myservo.attach(servoPin);  // attaches the servo on pin 9 to the servo object
}


// 0 = CW, 180 = CCW, 90 = STOP
void loop() {
  // send dataa only when you receive data
  if(Serial.available() > 0) {
    // read incoming byte
    incomingByte = Serial.read();

    Serial.print("received: ");
    Serial.print(incomingByte);

    // 'r' = right, 'l' = left, 's' = stop
    if(incomingByte == 's'){
      Serial.println(" STOPPED");
      myservo.write(90);
    } else if(incomingByte == 'r') {
        Serial.println(" CLOCK WISE");
        myservo.write(0);
    } else if(incomingByte == 'l'){
        Serial.println(" COUNTER CLOCK WISE");
        myservo.write(180); 
    } else{
      Serial.println(" RANDOM");
      myservo.write(incomingByte);
    }
  }
}
