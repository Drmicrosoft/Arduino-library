/*
  Omar.cpp - Library for Simpling Ultasonic , Dc Motors and Servos through FLOW Shield .
  Created by Omar A.Okasha "Drmicrosoft", November 13, 2016.
  Released into the public domain.
*/

#include "Arduino.h"

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <avr/pgmspace.h>

#include "WString.h"
#include "FLOW_2.h"
#include "Servo.h"
//#include "Servo.h"

Omar::Omar(int pin,int pinx)
{
  pinMode(pin, OUTPUT);
  pinMode(pinx, OUTPUT);
  _pin = pin;
  _pinx = pinx;
  Serial.begin(9600);
  
}


int Omar::measure()
{

 long duration, inches, cm;

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(_pin, OUTPUT);
  digitalWrite(_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(_pin, HIGH);
  delayMicroseconds(5);
  digitalWrite(_pin, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(_pinx, INPUT);
  duration = pulseIn(_pinx, HIGH);

  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  
  
  delay(100);
	return cm ;

}


long Omar:: microsecondsToInches(long microseconds)
{
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
}

long Omar:: microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}



void Omar::control(int x,int y)
{
	if(x==0&&y==0)
	{
		digitalWrite(_pin,LOW);
		digitalWrite(_pinx,LOW);
	}
	
	if(x==1&&y==0)
	{
		digitalWrite(_pin,HIGH);
		digitalWrite(_pinx,LOW);
	}
	
	if(x==0&&y==1)
	{
		digitalWrite(_pin,LOW);
		digitalWrite(_pinx,HIGH);
	}
	
	if(x==1&&y==1)
	{
		digitalWrite(_pin,HIGH);
		digitalWrite(_pinx,HIGH);
	}
}



int Omar :: s_int()
{
	
	  if (Serial.available()) {
    return Serial.parseInt();
    
}

}

String Omar :: s_string()
{
	
	
	if (Serial.available()) {
    return Serial.readString();
    
}
}

void Omar:: s_send(char* data)
{
	
	Serial.begin(9600);
Serial.write(data);	
}

int Omar :: analog_scale(int pin , int scale)
{
	float val = analogRead(pin);
	return ( val/1024.0)*scale; 
	
}





 void Omar :: angle(int pin,int v)
{
	
	
	myservo.attach(pin);
	delay(100);
	myservo.write(v); 
}

 int Omar :: heat(int pin)
{
	float val = analogRead(pin);
float mv = ( val/1024.0)*5000; 
int cel = mv/10;
return cel;

}


