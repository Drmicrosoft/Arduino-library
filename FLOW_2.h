/*
  Omar.h - Library for Simpling Ultasonic , Dc Motors and Servos through FLOW Shield .
  Created by Omar A.Okasha "Drmicrosoft", November 13, 2016.
  Released into the public domain.
*/

#ifndef FLOW_2_h
#define FLOW_2_h
#include "Arduino.h"

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <avr/pgmspace.h>


#include "/usr/share/arduino/libraries/Servo/Servo.h"
#include "Servo.h"
#include "WString.h"
   

class Omar 
{
  public:
  
    Omar(int pin,int pinx);
    Servo myservo; 	
    //void universal(int uni);
    int measure();
    long microsecondsToCentimeters(long microseconds);
    long microsecondsToInches(long microseconds);
    void control(int x,int y);
    //void angle(int v);
    int s_int();
    String s_string();
    void s_send(char* data);
    int analog_scale(int pin , int scale);
	void angle(int pin,int v);
	int heat(int pin);
    
 
    
    
    
  private:
    int _pin;
    int _pinx;
};

#endif

