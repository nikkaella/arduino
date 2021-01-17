#include <AFMotor.h>

AF_DCMotor motorRL(1);
AF_DCMotor motorRR(2);
AF_DCMotor motorFR(3);
AF_DCMotor motorFL(4);

void setup() {
  motorRL.setSpeed(200);
  motorRR.setSpeed(200);
  motorFR.setSpeed(200);
  motorFL.setSpeed(200);

  motorRL.run(RELEASE);
  motorRR.run(RELEASE);
  motorFR.run(RELEASE);
  motorFL.run(RELEASE);
}

void loop() {
  uint8_t i;

  forward(255);
  delay(500);
  
  reverse(255);
  delay(1000);
  left(150);
  delay(250);
  forward(255);
  delay(250);
  right(150);
  delay(250);
  reverse(255);
  delay(100);
  brakes();

}

void forward(int speed) {
  if (speed < 0) {
    speed = 0;
  } else if (speed > 255) {
    speed = 255;
  }

  // Drive forward at full speed for 1 second
  // both motors spin forward
  motorRL.run(FORWARD);
  motorRL.setSpeed(speed);
  delay(10);
  motorRR.run(FORWARD);
  motorRR.setSpeed(speed);
  delay(10);
  motorFR.run(FORWARD);
  motorFR.setSpeed(speed);
  delay(10);
  motorFL.run(FORWARD);
  motorFL.setSpeed(speed);
  delay(10);

}

void left(int speed) {
  if (speed < 0) {
    speed = 0;
  } else if (speed > 255) {
    speed = 255;
  }

  // Turn left at half speed for 1 second
  // Right motor spins forward and left motor stops or spins backward
  motorRL.run(RELEASE);
  motorRL.setSpeed(0);
  delay(10);
  motorRR.run(FORWARD);
  motorRR.setSpeed(speed);
  delay(10);
  motorFR.run(FORWARD);
  motorFR.setSpeed(speed);
  delay(10);
  motorFL.run(RELEASE);
  motorFL.setSpeed(0);
  delay(10);
}

void right(int speed) {
  if (speed < 0) {
    speed = 0;
  } else if (speed > 255) {
    speed = 255;
  }

  // Turn right at half speed for 1 second
  // Left motor spins forward and right motor stops or spins backward
  motorRL.run(FORWARD);
  motorRL.setSpeed(speed);
  delay(10);
  motorRR.run(RELEASE);
  motorRR.setSpeed(0);
  delay(10);
  motorFR.run(RELEASE);
  motorFR.setSpeed(0);
  delay(10);
  motorFL.run(FORWARD);
  motorFL.setSpeed(speed);
  delay(10);
}

void reverse(int speed) {
  if (speed < 0) {
    speed = 0;
  } else if (speed > 255) {
    speed = 255;
  }

  // Drive backward at half speed for 1 second
  // both motors spin backward
  motorRL.run(BACKWARD);
  motorRL.setSpeed(speed);
  delay(10);
  motorRR.run(BACKWARD);
  motorRR.setSpeed(speed);
  delay(10);
  motorFR.run(BACKWARD);
  motorFR.setSpeed(speed);
  delay(10);
  motorFL.run(BACKWARD);
  motorFL.setSpeed(speed);
  delay(10);
}

void brakes() {
  // BRAKE
  // Both motors stop spinning
  motorRL.run(RELEASE);
  delay(10);
  motorRR.run(RELEASE);
  delay(10);
  motorFR.run(RELEASE);
  delay(10);
  motorFL.run(RELEASE);
  delay(10);
}
