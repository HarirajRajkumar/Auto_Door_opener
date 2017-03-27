

/* This following Arduino sketch is written to control door open and close movement using a 
 *  Servo motor (for movement) by reading object in front of the door (using IR sensor)
 *  
 *  Here, a servo library is used to control a SERVO motor for movements
 *  
 *  Link to download the library file
 *  https://github.com/arduino-libraries/Servo
 *  (Use the above link incase if the library is not already attached with the IDE)
 *  
 *  To check whether the SERVO library is attached or not
 *  1. Go to >>Sketch.
 *  2. Go to >>Include Library.
 *  3. See under >>Arduino libraries.
 */

#include<Servo.h>

Servo myServo; // class object (OOP conceptual)

// Variabeles Declarations
byte IRdigitalData = 0;

// Pin Declarations
byte IRdigitalPin = 3;
byte ServoPin = 4;
int pos =0;

void setup()
{
  // Declaring Infrared module digital pins as INPUT
  pinMode(IRdigitalPin , INPUT);

  // Attaching Servo
   myServo.attach(ServoPin);
}// close setup

void loop()
{
  IRdigitalData = digitalRead(IRdigitalPin); // reading pin state (either 0 or 1)
  
  if(IRdigitalData == HIGH) // if detected HIGH the open the door (goes from 0 to 180 degrees)
  {
      for (pos = 0; pos <= 180; pos += 1)
      { // goes from 0 degrees to 180 degrees in steps of 1 degree
   
    myServo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
      }// close for
  }// close if

  else
  {
    for (pos = 180; pos >= 0; pos -= 1) // goes from 180 degrees to 0 degrees
      {
      myServo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
       }// close for
  }// close else
  
}// close loop

