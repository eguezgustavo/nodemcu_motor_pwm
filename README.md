# Motor control Arduino library
This library is a WIP, any suggestion please [email](mailto://eguezgustavo@gmail.com) me.

To control the motor you should use an H BRIDGE module. One pin of the NodeMcu will be connected to the enable terminal of the H BRIDGE and the other 2 are meant to be used for going forward or backward.

 
Use the library like this:

``` 
Motor motor(PWM_PIN, FORWARD_PIN, BACKWARDS_PIN); // Create a motor instance 

void setup() { 
    motor.setup(); // Set the motor
}

void loop() {
    motor.forward(100); // Go forward at full speed (100 %)
    delay(3000);

    motor.backwards(50); // Go backwards at half speed (50 %)
    delay(3000);
}
```