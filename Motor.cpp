#include "Arduino.h"
#include "Motor.h"

Motor::Motor(int pwmPin, int forwardPin, int backwardsPin)
{
    _pwmPin = pwmPin;
    _forwardPin = forwardPin;
    _backwardsPin = backwardsPin;
}

void Motor::setup()
{
    pinMode(_pwmPin, OUTPUT);
    pinMode(_forwardPin, OUTPUT);
    pinMode(_backwardsPin, OUTPUT);

    digitalWrite(_forwardPin, LOW);
    digitalWrite(_backwardsPin, LOW);
    analogWrite(_pwmPin, 0);
}

void Motor::moveMotor(bool isForward, int percentage)
{
    int value;

    digitalWrite(_forwardPin, isForward);
    digitalWrite(_backwardsPin, !isForward);

    value = 1023 * (percentage / 100.0);

    analogWrite(_pwmPin, value);
}

void Motor::forward(int percentage)
{
    moveMotor(true, percentage);
}

void Motor::backwards(int percentage)
{
    moveMotor(false, percentage);
}

void Motor::stop()
{
    digitalWrite(_forwardPin, LOW);
    digitalWrite(_backwardsPin, LOW);
    analogWrite(_pwmPin, 0);
}