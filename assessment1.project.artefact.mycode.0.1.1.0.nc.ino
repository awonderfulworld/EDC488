int redLedPin = 2;

int analogueSignalPin = A0;
int analogueValue = 0;

void setup () {
  pinMode(redLedPin, OUTPUT);
  
  pinMode(analogueSignalPin, INPUT);

  Serial.begin(9600);
}

void loop () {
  analogueValue = analogRead(analogueSignalPin);

  if (analogueValue <= 600) {
    digitalWrite(redLedPin, HIGH);
    Serial.print("Time to turn on the lights! - Current value: ");
  }
  else {
    Serial.print("Too much natural light to turn on the lights! - Current value: ");
  }

  Serial.println(analogueValue);

  delay(500);

  digitalWrite(redLedPin, LOW);
}
