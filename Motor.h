/*
  Motor.h - Library to handle a motor with PWM
  Created by Gustavo Eguez on Jan 27, 2019
  Released into the public domain.
*/
#ifndef Motor_h
#define Motor_h

#include "Arduino.h"

class Motor
{
  public:
    Motor(int pwmPin, int forwardPin, int backwardsPin);
    void setup();
    void forward(int percentage);
    void backwards(int percentage);
    void stop();
  private:
    void moveMotor(bool isForward, int percentage);
    int _pwmPin;
    int _forwardPin;
    int _backwardsPin;
};

#endif