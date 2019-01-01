int redLedPin = 2;
int yellowLedPin = 3;
int greenLedPin = 4;

int analogueSignalPin = A0;
int analogueValue = 0;

void setup () {
  pinMode(redLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  
  pinMode(analogueSignalPin, INPUT);

  Serial.begin(9600);
}

void loop () {
  analogueValue = analogRead(analogueSignalPin);
  
  if (analogueValue <= 500) {
    digitalWrite(redLedPin, HIGH);
    Serial.print("Time to turn on the lights! - Current value: ");
  }
  else if (analogueValue > 500 && analogueValue <= 700) {
    digitalWrite(yellowLedPin, HIGH);
    Serial.print("We need a little extra light. - Current value: ");
  }
  else {
    digitalWrite(greenLedPin, HIGH);
    Serial.print("Too much natural light to turn on the lights! - Current value: ");
  }

  Serial.println(analogueValue);

  delay(500);

  digitalWrite(redLedPin, LOW);
  digitalWrite(yellowLedPin, LOW);
  digitalWrite(greenLedPin, LOW);
}
