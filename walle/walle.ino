#include <AFMotor.h>
#include <Servo.h>
const int trig_pin = A1;
const int echo_pin = A0;
const int trig_delay = 5; //ms

AF_DCMotor motorRL(1);
AF_DCMotor motorRR(2);
AF_DCMotor motorFR(3);
AF_DCMotor motorFL(4);

Servo myServo;

void setup() {
  motorRL.setSpeed(200);
  motorRR.setSpeed(200);
  motorFR.setSpeed(200);
  motorFL.setSpeed(200);

  motorRL.run(RELEASE);
  motorRR.run(RELEASE);
  motorFR.run(RELEASE);
  motorFL.run(RELEASE);
  Serial.begin(9600);
  myServo.attach(10);
  myServo.write(90);
  delay(250);

}

void loop() {
  long duration;
  float distance;

  pinMode(trig_pin , OUTPUT);
  digitalWrite(trig_pin, 0);
  delayMicroseconds(10);
  digitalWrite(trig_pin, 255);
  delayMicroseconds(trig_delay);
  digitalWrite(trig_pin, 0);

  pinMode(echo_pin, INPUT);
  duration = pulseIn(echo_pin, HIGH);
  distance = duration / 58.8;

  uint8_t i;
  uint8_t num;

  Serial.print("distance: ");
  Serial.println(distance);
  delay(500);
  if (distance < 10) {
    //    backward(127);
    delay(250);
    num = random(0, 2);
    if (num == 0) {
      //      myServo.write(180);
      //      delay(15);
      if (distance > 20) {
        //        left(127);
        delay(500);
      }
      else {
        //        myServo.write(0);
        //        delay(15);
        if (distance > 20) {
          //          right(127);
          delay(500);
        }
      }
    }
  } else {
    //    forward(127);
  }
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

  myServo.write(90);
  delay(15);
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

  myServo.write(90);
  delay(15);
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
