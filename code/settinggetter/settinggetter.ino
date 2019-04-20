#include "EEPROM.h"
#include <Adafruit_NeoPixel.h>
#define EEPROM_SIZE 16
void setup() {
  while (!Serial);
  Serial.begin(9600);
  Serial.println("Welcome to the IntruderBeware setting getter! Give me a second to set up the EEPROM...");
  if (!EEPROM.begin(EEPROM_SIZE)){
    Serial.println("Failed to initialise EEPROM!");
    while(true);
  }
  Serial.println("Done! First, I'll find out if your PIR is reverse.");
  if (EEPROM.read(0) == 0) {
    Serial.println("It's not reverse!");
  } else if (EEPROM.read(0) == 1) {
    Serial.println("It's reverse!");
  } else {
    Serial.println("Hmm... I'm having trouble.");
  }
  Serial.println("I think you have "+String(EEPROM.read(1))+" NeoPixels.");
  switch (EEPROM.readUShort(2)) {
    case NEO_KHZ400+NEO_RGB:
      Serial.print("I think you have V1 RGB NeoPixels.");
      break;
    case NEO_KHZ800+NEO_GRB:
      Serial.print("I think you have V2 RGB NeoPixels.");
      break;
    case NEO_KHZ800+NEO_RGBW:
      Serial.print("I think you have RGBW NeoPixels.");
      break;
    default:
      Serial.println("Hmm... I'm having trouble.");
  }
  Serial.println("All fetchable settings have been fetched.");
}

void loop() {
  
}
