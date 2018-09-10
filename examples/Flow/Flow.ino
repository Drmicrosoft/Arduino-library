/*
  Omar.ino - Library for Simpling Ultasonic , Dc Motors and Servos through FLOW Shield .
  Created by Omar A.Okasha "Drmicrosoft", November 13, 2016.
  Released into the public domain.
*/

#include <FLOW_2.h>

void setup() {                
  // initialize the digital pin as an output.
}

// the loop routine runs over and over again forever:
void loop() {


// There are three Usage of this library 
// First take an Object for each Usage 
// First Dc Motor 
// Like this by sending between (first_pin,second_pin) the two Pins for DC motors
// to control the Motor us send through "object.control( , );" 
// by sending 00,11 to Stop , 10 to Forward , 01 to backward

Omar dcmotor_1(7,8);
dcmotor_1.control(1,0);

// Second Ultrasonic
// Like this by sending between (trigger , Echo ) the two Pins for Ultrasonic
// First pin is the trigger and Second is the Echo
// and it returns the value in cm 

Omar Ultrasonic (9,10);
int length = Ultrasonic.measure();

// To control Servo Use direct the order >> angle(pin , Degree);
Omar.angle(5,80);

float x = Omar.heat(A1);


int k = Omar.s_int();
String k = Omar.s_string();
Omar.s_send("omar");
float cc = Omar.analog_scale(10,1000);

}
