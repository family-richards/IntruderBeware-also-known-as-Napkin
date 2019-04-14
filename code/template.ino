void setup() {
  pinMode(32, OUTPUT); // set siren pin to output
  // setup I/O config for smoke detection here
}

void loop() {
  if (isThereSmoke()) {
    activateSiren();
  }
}

bool isThereSmoke() {
  // Place your code to read/write to the IO pins to detect smoke
  bool smoke = false;
  return smoke;
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
