#include <ezButton.h>
#include <LiquidCrystal_I2C.h>
#include <MIDI.h>
//#include <MIDIUSB.h>

MIDI_CREATE_DEFAULT_INSTANCE();

#define NUMBUTTONS = 4

const int BUTTON1_PIN = 2;
const int BUTTON2_PIN = 3;
const int BUTTON3_PIN = 4;
const int BUTTON4_PIN = 5;
const int BUTTON5_PIN = 6;
const int BUTTON6_PIN = 7;

const int LED1_PIN = 13;
const int LED2_PIN = 12;
const int LED3_PIN = 11;
const int LED4_PIN = 10;
const int LED5_PIN = 9;
const int LED6_PIN = 8;

ezButton button1(BUTTON1_PIN);
ezButton button2(BUTTON2_PIN);
ezButton button3(BUTTON3_PIN);
ezButton button4(BUTTON4_PIN);
ezButton button5(BUTTON5_PIN);
ezButton button6(BUTTON6_PIN);

int ledState = LOW;
int state = 0;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);
  pinMode(LED4_PIN, OUTPUT);
  pinMode(LED5_PIN, OUTPUT);
  pinMode(LED6_PIN, OUTPUT);
  button1.setDebounceTime(50);
  button2.setDebounceTime(50);
  button3.setDebounceTime(50);
  button4.setDebounceTime(50);
  button5.setDebounceTime(50);
  button6.setDebounceTime(50);

  lcd.init(); // initialize the lcd
  lcd.backlight();

}

void loop() {
  lcd.setCursor(0, 0);         // move cursor to   (0, 0)
  lcd.print("Button");        // print message at (0, 0)
  //lcd.setCursor(2, 1);         // move cursor to   (2, 1)
  //lcd.print("GetStarted.com"); // print message at (2, 1)
  button1.loop();
  button2.loop();
  button3.loop();
  button4.loop();
  button5.loop();
  button6.loop();

  if (button1.isPressed()) {
    Serial.println("The button1 is pressed");
    lcd.setCursor(0,1);

    // toggle state of LED
    ledState = !ledState;
    if (ledState != LOW) {
      state = 1;
    }
    else {
     state = 0;
    }

    // control LED arccoding to the toggleed sate
    digitalWrite(LED1_PIN, ledState);
    lcd.print(state);
    sendNote();
  }
  if (button2.isPressed()) {
    Serial.println("The button2 is pressed");
    lcd.setCursor(1,1);

    // toggle state of LED
    ledState = !ledState;
    if (ledState != LOW) {
      state = 1;
    }
    else {
     state = 0;
    }

    // control LED arccoding to the toggleed sate
    digitalWrite(LED2_PIN, ledState);
    lcd.print(state);
    sendNote();
  }
  if (button3.isPressed()) {
    Serial.println("The button3 is pressed");
    lcd.setCursor(2,1);

    // toggle state of LED
    ledState = !ledState;
    if (ledState != LOW) {
      state = 1;
    }
    else {
     state = 0;
    }

    // control LED arccoding to the toggleed sate
    digitalWrite(LED3_PIN, ledState);
    lcd.print(state);
    sendNote();
  }
  if (button4.isPressed()) {
    Serial.println("The button4 is pressed");
    lcd.setCursor(3,1);

    // toggle state of LED
    ledState = !ledState;
    if (ledState != LOW) {
      state = 1;
    }
    else {
     state = 0;
    }

    // control LED arccoding to the toggleed sate
    digitalWrite(LED4_PIN, ledState);
    lcd.print(state);
    sendNote();
  }
  if (button5.isPressed()) {
    Serial.println("The button5 is pressed");
    lcd.setCursor(4,1);

    // toggle state of LED
    ledState = !ledState;
    if (ledState != LOW) {
      state = 1;
    }
    else {
     state = 0;
    }

    // control LED arccoding to the toggleed sate
    digitalWrite(LED5_PIN, ledState);
    lcd.print(state);
    sendNote();
  }
  if (button6.isPressed()) {
    Serial.println("The button6 is pressed");
    lcd.setCursor(5,1);

    // toggle state of LED
    ledState = !ledState;
    if (ledState != LOW) {
      state = 1;
    }
    else {
     state = 0;
    }

    // control LED arccoding to the toggleed sate
    digitalWrite(LED5_PIN, ledState);
    lcd.print(state);
    sendNote();
  }
}

void sendNote() {
  Serial.println("midi note");
}
