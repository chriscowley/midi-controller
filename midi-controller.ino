#include <Keypad.h>
#include <MIDIUSB.h>

const int ROW_NUM = 5; //four rows
const int COLUMN_NUM = 4; //three columns
const int NB_BUTTONS = ROW_NUM * COLUMN_NUM;

int analog1 = A0;
int analog2 = A1;
int analog1Old = 0;
int analog1New = 0;
int analog2Old = 0;
int analog2New = 0;
#define analog1CC 54
#define analog2CC 55

int note = 64;

char keys[ROW_NUM][COLUMN_NUM] = {
  {'1', '2', '3', 'g'},
  {'4', '5', '6', 'h'},
  {'7', '8', '9', 'i'},
  {'a', 'b', 'c', 'j'},
  {'d', 'e', 'f', 'k'},
};

byte pin_rows[ROW_NUM] = {2, 3, 4, 5, 6}; //connect to the row pinouts of the keypad
byte pin_column[COLUMN_NUM] = {16, 15, 14, 10}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );
unsigned int buttons_state[NB_BUTTONS] = {0, 0, 0, 0, 0, 0 };

float floatMap(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void noteOn(byte channel, byte pitch, byte velocity) {
  Serial.println(pitch);
  midiEventPacket_t noteOn = {0x09, 0x90 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOn);
}
void noteOff(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOff = {0x08, 0x80 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOff);
}

void setup() {
  Serial.begin(115200);

  pinMode(analog1, INPUT);
}

void controlChange(byte channel, byte control, byte value) {
  midiEventPacket_t event = {0x0B, 0xB0 | channel, control, value};
  MidiUSB.sendMIDI(event);
}

void loop() {
  char key = keypad.getKey();
  int note = 64;


//  Serial.print("Analog: ");
//  Serial.print(analogValue);
//  Serial.print(", Voltage: ");
//  Serial.println(voltage);
  
  if (key) {
    if (key == '1') {
      note = note + 1;
    } else if (key == '2') {
      note = note + 2;
    } else if (key == '3') {
      note = note + 3;
    } else if (key == '4') {
      note = note + 4;
    } else if (key == '5') {
      note = note + 5;
    } else if (key == '6') {
      note = note + 6;
    } else if (key == '7') {
      note = note + 7;
    } else if (key == '8') {
      note = note + 8;
    } else if (key == '9') {
      note = note + 9;
    } else if (key == 'a') {
      note = note + 10;
    } else if (key == 'b') {
      note = note + 11;
    } else if (key == 'c') {
      note = note + 12;
    } else if (key == 'd') {
      note = note + 13;
    } else if (key == 'e') {
      note = note + 14;
    } else if (key == 'f') {
      note = note + 15;
    } else if (key == 'g') {
      note = note + 16;
    } else if (key == 'h') {
      note = note + 17;
    } else if (key == 'i') {
      note = note + 18;
    } else if (key == 'j') {
      note = note + 19;
    }
    Serial.println("Sending note on");
    noteOn(1, note, 64);   // Channel 1, middle C, normal velocity
    MidiUSB.flush();
    delay(50);
    Serial.println("Sending note off");
    noteOff(1, note, 64);  // Channel 1, middle C, normal velocity
    MidiUSB.flush();
  }
  int pot1 = analogRead(analog1);
  int analog1New = analogRead(analog2);
  if (analog1New - analog1Old >= 35 || analog1Old - analog1New >= 35) {
      analog1Old = analog1New;
      analog1New = (map(analog1New, 1023, 0, 0, 120));
      analog1New = (constrain(analog1New, 0, 120));
      controlChange(2, analog1CC, analog1New );
      MidiUSB.flush();
  }
//
//  int pot2 = analogRead(analog2);
//  int analog2New = analogRead(analog2);
//  if (analog2New - analog2Old >= 35 || analog2Old - analog2New >= 35) {
//      analog2Old = analog2New;
//      analog2New = (map(analog2New, 1023, 0, 0, 120));
//      analog2New = (constrain(analog2New, 0, 120));
//      controlChange(2, analog2CC, analog2New );
//      MidiUSB.flush();
//  }
}
