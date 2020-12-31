const int btn = 13;
const int a_red = A2;
const int a_green = A1;
const int a_blue = A0;
const int r1 = 6;
const int g1 = 3;
const int b1 = 5;
const int r2 = 11;
const int g2 = 10;
const int b2 = 9;
const int debounce_delay = 50; // ms

//globals
int btn_state = HIGH;
int btn_prev = HIGH;
unsigned long last_debounce_time = 0;
int r_bright = 0;
int g_bright = 0;
int b_bright = 0;
int led1[3] = {r1, g1, b1};
int led2[3] = {r2, g2, b2};
int whichLED = false;

void setup() {
  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(g1, OUTPUT);
  pinMode(g2, OUTPUT);
  pinMode(b1, OUTPUT);
  pinMode(b2, OUTPUT);
  pinMode(btn, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // read current position of button
  int btn_read = digitalRead(btn);

  // maps the potentiometer values to 0-255 for LED
  int red = analogRead(a_red);
  r_bright = map(red, 0, 1023, 0, 255);
  int green = analogRead(a_green);
  g_bright = map(green, 0, 1023, 0, 255);
  int blue = analogRead(a_blue);
  b_bright = map(blue, 0, 1023, 0, 255);

  // remember when the button changed states
  if (btn_read != btn_prev) {
    last_debounce_time = millis();
  }

  // Wait before checking the state of the button again
  if ( millis() > (last_debounce_time + debounce_delay) ) {
    if ( btn_read != btn_state ) {
      btn_state = btn_read;
      if (btn_state == LOW) {
        whichLED = !whichLED;
      }
    }
  }

  if (whichLED == true) {
    RGB(led2, 0, 0, 0);
    RGB(led1, r_bright, g_bright, b_bright);
    delay(100);
  } else {
    RGB(led1, 0, 0, 0);
    RGB(led2, r_bright, g_bright, b_bright);
    delay(100);
  }
  btn_prev = btn_read;
}

void RGB(int pins[], int r_val, int g_val, int b_val) {
  analogWrite(pins[0], r_val); //red
  analogWrite(pins[1], g_val); //green
  analogWrite(pins[2], b_val); //blue
}
