#include "EEPROM.h"
#include <Adafruit_NeoPixel.h>
#define EEPROM_SIZE 16
Adafruit_NeoPixel strippy;
void setup() {
  while(!Serial);
  Serial.begin(9600);
  Serial.println("Welcome to the IntruderBeware setup wizard! Wait a moment as I setup the inputs, outputs, and EEPROM...");
  pinMode(27, INPUT);
  pinMode(32, OUTPUT);
  pinMode(15, OUTPUT);
  if (!EEPROM.begin(EEPROM_SIZE)){
    Serial.println("Failed to initialise EEPROM!");
    while(true);
  }
  Serial.println("Done! First, let's setup your PIR. Go behind your PIR, so it can't see you. In five seconds, I'll take 10 snapshots of the PIR pin.");
  delay(5000);
  Serial.println("Taking shapshots...");
  byte onSnaps = 0;
  byte offSnaps = 0;
  for (int i = 0; i < 10; i++) {
    if (digitalRead(27) == HIGH) {
      onSnaps++;
    } else {
      offSnaps++;
    }
    delay(100);
  }
  Serial.println("Okay, now let's have you make a whole bunch of motion. Again, in 5 seconds, I'll take 10 snapshots.");
  delay(5000);
  byte onSnapsMotion = 0;
  byte offSnapsMotion = 0;
  for (int i = 0; i < 10; i++) {
    if (digitalRead(27) == HIGH) {
      onSnapsMotion++;
    } else {
      offSnapsMotion++;
    }
    delay(100);
  }
  Serial.println("Hmm... let me figure out if your PIR is reverse...");
  if (onSnaps > offSnaps && onSnapsMotion < offSnapsMotion) {
    Serial.println("It's reverse! Give me a second to save that...");
    EEPROM.write(0, 1);
  } else if (onSnaps < offSnaps && onSnapsMotion > offSnapsMotion) {
    Serial.println("It's not reverse! Give me a second to save that...");
    EEPROM.write(0, 0);
  } else {
    Serial.println("Hmm... I'm having trouble. Try again by resetting this, and put up a issue on GitHub.");
    while(true);
  }
  Serial.println("Now, let's test the buzzer. In 5 seconds, I'll play a low tone, a medium tone, and then a high tone.");
  delay(5000);
  buzz(1500, 500);
  delay(500);
  buzz(2000, 500);
  delay(500);
  buzz(2500, 500);
  delay(500);
  Serial.println("Did you hear the tones? y/n");
  checkWords:
  while(!Serial.available());
  delay(100);
  String firstChar = String(Serial.read());
  firstChar.toLowerCase();
  if (firstChar == 'y') {
    Serial.println("Great!");
  } else if (firstChar == 'n') {
    Serial.println("Hmm... try making a issue on GitHub.");
  } else {
    while (Serial.available()) {Serial.read();}
    Serial.println("Please type y or n.");
    goto checkWords;
  }
  while (Serial.available()) {Serial.read();}
  Serial.println("Cover your ears! In 5 seconds, I'll test the siren.");
  delay(5000);
  // TODO: figure out if you use tone(32, 2000, 1000) or digitalWrite(32, HIGH)
  // put code to test siren here
  Serial.println("Did you hear the tone? y/n");
  checkWordsSiren:
  while(!Serial.available());
  delay(100);
  String firstChar = String(Serial.read());
  firstChar.toLowerCase();
  if (firstChar == 'y') {
    Serial.println("Great!");
  } else if (firstChar == 'n') {
    Serial.println("Hmm... try making a issue on GitHub.");
  } else {
    while (Serial.available()) {Serial.read();}
    Serial.println("Please type y or n.");
    goto checkWordsSiren;
  }
  while (Serial.available()) {Serial.read();}
  Serial.println("Let's try testing your NeoPixels. How many NeoPixels are in your strip? (I would discourage more than 25.)");
  while (!Serial.available());
  delay(100);
  int neoPixels = Serial.parseInt();
  Serial.println("Let me save that...");
  EEPROM.write(1, neoPixels);
  Serial.println("Okay, now I have some more questions. First, are your NeoPixels RGBW or RGB?");
  checkWordsNeopixels:
  while(!Serial.available());
  delay(100);
  String retval = Serial.readString();
  retval.toLowerCase();
  if (retval == "rgb") {
    Serial.println("Great! Now, second: Are your NeoPixels V1 or V2?");
    checkWordsRGBVersion:
    while(!Serial.available());
    delay(100);
    String retval = Serial.readString();
    retval.toLowerCase();
    if (retval == "v1") {
      Serial.println("The settings are found! Give me a second to save them...");
      EEPROM.writeUShort(2, NEO_KHZ400+NEO_RGB);
    } else if (retval == "v2") {
      Serial.println("The settings are found! Give me a second to save them...");
      EEPROM.writeUShort(2, NEO_KHZ800+NEO_GRB);
    } else {
      Serial.println("Please type V1 or V2.");
      goto checkWordsRGBVersion;
    }
  } else if (retval == "rgbw") {
    Serial.println("The settings are found! Give me a second to save them...");
    EEPROM.writeUShort(2, NEO_KHZ800+NEO_RGBW);
  } else {
    Serial.println("Please type RGBW or RGB.");
    goto checkWordsNeopixels;
  }
  Serial.println("Now, let's test your NeoPixels. Give me a second to set them up...");
  strip = Adafruit_NeoPixel(EEPROM.read(1), 4, EEPROM.readUShort(2));
  Serial.println("Done! You should see all of them turn red, then green, then blue.");
  colorWipe(strip.color(255, 0, 0), 2000/strip.numPixels());
  colorWipe(strip.color(0, 255, 0), 2000/strip.numPixels());
  colorWipe(strip.color(0, 0, 255), 2000/strip.numPixels());
  Serial.println("Did that work? Type y or n.");
}

void loop() {
  
}

void colorWipe(uint32_t c, uint16_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void buzz(int frequency, uint16_t time) {
  for (int i = 0; i < time/(1000000/frequency*2); i++) {
    digitalWrite(15, LOW);
    delayMicroseconds(1000000/frequency);
    digitalWrite(15, HIGH);
    delayMicroseconds(1000000/frequency);
  }
}
