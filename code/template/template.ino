#include "EEPROM.h"
#include <Adafruit_NeoPixel.h>
#define EEPROM_SIZE 16
bool armed = false;
bool sirenOn = false;
bool warningOn = false;
long warningMillis = 0;
Adafruit_NeoPixel strippy;

void setup() {
  pinMode(32, OUTPUT); // set siren pin to output
  pinMode(15, OUTPUT); // set beeper pin to output
  pinMode(27, INPUT); // set PIR pin to input
  // setup I/O config for smoke detection here
  while (!EEPROM.begin(EEPROM_SIZE)) {
    Serial.println("EEPROM ERROR!");
    delay(1000);
  }
  strippy = Adafruit_NeoPixel(EEPROM.read(1), 4, EEPROM.readUShort(2));
}

void loop() {
  if (isThereSmoke()) {
    sirenOn = true;
  }
  if (armed) {
    if (isThereMotion()) {
      warningMillis = millis();
      warningOn = true;
    }
  }
  if (warningOn) {
    activateBeeper();
    for (uint16_t i = 0; i < strippy.numPixels(); i++) {
      if (random(0, 2) != 0) {
        strippy.setPixelColor(i, strippy.Color(0, 0, 0))
      } else {
        strippy.setPixelColor(i, strippy.Color(230, 230, 0))
      }
    }
    strippy.show();
  }
  if (millis() - warningMillis > 30000 && warningOn) {
    sirenOn = true;
    warningOn = false;
  }
  if (sirenOn) {
    activateSiren();
    for (uint16_t i = 0; i < strippy.numPixels(); i++) {
      if (random(0, 2) != 0) {
        strippy.setPixelColor(i, strippy.Color(0, 0, 0))
      } else {
        strippy.setPixelColor(i, strippy.Color(255, 0, 0))
      }
    }
    strippy.show();
  }
}

bool isThereSmoke() {
  // Place your code to read/write to the IO pins to detect smoke
  // If there's smoke, return true
  bool smoke = false;
  return smoke;
}

bool isThereMotion() {
  bool inverted = EEPROM.read(0) == 1; // If when you read no motion you read HIGH and when when you read motion you read LOW, set this to true
  return inverted ^ digitalRead(27); // A fancy way to say inverted XOR digitalRead(27)
}

void activateSiren() {
  for (int i = 1000; i < 2000; i += 10) {
    tone(32, i, 20);
    delay(20);
  }
  for (int i = 2000; i > 1000; i -= 10) {
    tone(32, i, 20);
    delay(20);
  }
}

void activateBeeper() {
  // Beep on pin 15 for 500ms at 2000hz
  tone(15, 2000, 500);
  delay(500);
}
