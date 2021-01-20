# WALL-DO

today we're playing with DC motors!


# tools used

## hardware
- L293D motor driver shield
- DC motors x 4
- jumper wires
- battery holder (in series)
- 1.5V batteries x 8
- distance sensor
- servo motor

## software
- [AF_DCMotor](https://learn.adafruit.com/adafruit-motor-shield/library-install) library

## how it works
- the distance sensor keeps Wall-E from hitting walls
- when it gets close to a wall, it turns its eyes(servo + distance sensor)
- distance sensor checks for clearance
- Wall-E turns and moves forward where there's space

## what i learned - how to...
- solder
- use a shield
- read a datasheet
- install a library

## how to run
1. i assume you know how to install the arduino IDE.
2. open the file on arduino IDE.
3. connect them accordingly.
4. upload the file to the arduino!
