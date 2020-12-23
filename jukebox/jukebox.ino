// Songs: Part of Your World, Love is an Open Door, The Bare Necessities, Alouette, Still Alive
#include <LiquidCrystal.h>

const int speaker = 6;
const int btn_choose = 7;
const int btn_play = 8;
const int c_led = 9;
const int d_led = 13;

// Globals
int choose_prev = HIGH;
int play_prev = HIGH;
int sCursor = 0;
String titles[] = {"Part of Your World", "Love is an Open Door", "The Bare Necessities", "Alouette"};
int title = -1;

LiquidCrystal lcd(12, 11, 2, 3, 4, 5);

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("Choose a Song!->");
  pinMode(btn_choose, INPUT_PULLUP);
  pinMode(btn_play, INPUT_PULLUP);
  pinMode(c_led, OUTPUT);
  pinMode(d_led, OUTPUT);
}

void loop() {
  int choose_state = digitalRead(btn_choose);
  int play_state = digitalRead(btn_play);

  if ((choose_state == LOW) && (choose_prev == HIGH)) {
    title++;
    if (title > 3) {
      title = 0;
    }
    printTitle(titles[title]);
  }

  if ((play_state == LOW) && (play_prev == HIGH)) {
    playSong(titles[title]);
  }

  choose_prev = choose_state;
  play_prev = play_state;
}

void printTitle(String title) {
  lcd.clear();
  lcd.setCursor(0, 0);
  if (title == "Part of Your World") {
    lcd.setCursor(0, 0);
    lcd.print("Part of Your");
    lcd.setCursor(0, 1);
    lcd.print("World");
  } else if ( title == "Love is an Open Door") {
    lcd.setCursor(0, 0);
    lcd.print("Love is an");
    lcd.setCursor(0, 1);
    lcd.print("Open Door");
  } else if ( title == "The Bare Necessities") {
    lcd.setCursor(0, 0);
    lcd.print("The Bare");
    lcd.setCursor(0, 1);
    lcd.print("Necessities");
  } else if ( title == "Alouette") {
    lcd.setCursor(0, 0);
    lcd.print("Alouette");
  }
}

void playSong (String title) {
  String poyw = "deff efgg deffefefgg efggfgf dfgaagg";
  double poywDur[] = {0.5, 0.5, 0.5, 1.5, 1, 0.5, 0.5, 0.5, 1.5, 1,
                      0.5, 0.5, 0.5, 1, 1, 0.5, 0.5, 0.5, 0.5, 1, 1,
                      0.5, 0.5, 0.5, 1, 0.5, 0.5, 1.5, 0.5,
                      0.5, 0.5, 0.5, 1, 1, 0.5, 2.5
                     };

  String loveOpen = "fgaCCaDfagfdcfgapCagfdg p paCCaDCafgfagffgaCCaDCgfgfagff";
  double loveOpenDur[] = {0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 1, 0.5, 0.5, 1, 1, 0.5, 0.5,
                          0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 2, 1, 1, 1, 1,
                          0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 1, 0.5, 0.5, 0.5, 0.5,
                          0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 1, 0.5, 0.5, 1
                         };

  String bareNec = "cdf ahagffgfgfgfdcfcfaDCpag";
  double bareNecDur[] = {1, 1, 1, 1, 2, 1, 1, 1, 1, 1,
                         1, 1, 1, 1, 1, 1, 1, 1, 1.5, 0.5, 1, 1,
                         2, 1, 1, 1, 4
                        };

  String alouette = "cdeedcdec cdeedcdec";
  double alouetteDur[] = {2.5, 1, 2, 2, 1, 1, 1, 1, 2, 2,
                          2.5, 1, 2, 2, 1, 1, 1, 1, 4
                         };

  if (title == "Part of Your World") {
    for (int i = 0; i < poyw.length(); i++) {
      play(poyw[i], poywDur[i], 300, 250);
    }
  } else if (title == "Love is an Open Door") {
    for (int i = 0; i < loveOpen.length(); i++) {
      play(loveOpen[i], loveOpenDur[i], 300, 250);
    }
  } else if (title == "The Bare Necessities") {
    for (int i = 0; i < bareNec.length(); i++) {
      play(bareNec[i], bareNecDur[i], 200, 50);
    }
  } else if (title == "Alouette") {
    for (int i = 0; i < alouette.length(); i++) {
      play(alouette[i], alouetteDur[i], 200, 50);
    }
  }
}

void play(char note, int duration, int beatLength, int delayLen) {
  char notes[] = {'c', 'd', 't', 'e', 'f', 'g', 'h', 'a', 'p', 'b', 'C', 'S', 'D', 'E', 'F', 'G', 'H', ' '};
  int freqs[] = {262, 294, 277, 330, 349, 392, 415, 440, 466, 494, 523, 554, 587, 659, 698, 784, 831, 0};
  int curFreq = 0;

  for (int i = 0; i < 10; i++) {
    if (notes[i] == note) {
      curFreq = freqs[i];
    }
  }

  if (note == 'C') {
    digitalWrite(c_led, HIGH);
    delay(delayLen);
  }
  if (note == 'D') {
    digitalWrite(d_led, HIGH);
    delay(delayLen);
  }

  tone(speaker, curFreq, beatLength * duration);
  delay(beatLength * duration);
  delay(delayLen);
  noTone(speaker);
  digitalWrite(c_led, LOW);
  digitalWrite(d_led, LOW);


}
