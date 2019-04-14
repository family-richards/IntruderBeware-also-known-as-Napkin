bool armed = false;
bool sirenOn = false;
bool warningOn = false;
long warningMillis = 0;

void setup() {
  pinMode(32, OUTPUT); // set siren pin to output
  pinMode(15, OUTPUT); // set beeper pin to output
  pinMode(27, INPUT); // set PIR pin to input
  // setup I/O config for smoke detection here
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
  }
  if (millis() - warningMillis > 30000 && warningOn) {
    sirenOn = true;
    warningOn = false;
  }
  if (sirenOn) {
    activateSiren();
  }
}

bool isThereSmoke() {
  // Place your code to read/write to the IO pins to detect smoke
  bool smoke = false;
  return smoke;
}

bool isThereMotion() {
  bool inverted = false; // If when you read no motion you read HIGH and when when you read motion you read LOW, set this to true
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
  tone(15, 2000, 500);
  delay(1000);
}
