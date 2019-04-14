void setup() {
  while(!Serial);
  Serial.begin(9600);
  Serial.println("Welcome to the IntruderBeware setup wizard! Wait a moment as I setup the inputs and outputs...");
  pinMode(27, INPUT);
  pinMode(32, OUTPUT);
  pinMode(15, OUTPUT);
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
  }
  Serial.println("Hmm... let me figure out if your PIR is reverse...");
  if (onSnaps > offSnaps && onSnapsMotion < offSnapsMotion) {
    Serial.println("It's reverse!");
  } else if (onSnaps < offSnaps && onSnapsMotion > offSnapsMotion) {
    Serial.println("It's not reverse!");
  } else {
    Serial.println("Hmm... I'm having trouble. Try again by resetting this.");
  }
}

void loop() {
  
}
