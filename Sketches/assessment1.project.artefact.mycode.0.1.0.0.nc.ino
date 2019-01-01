int sensorValue = 0;

void setup() {
  pinMode(sensorValue, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(A0);

  Serial.print("Current value: ");
  Serial.println(sensorValue);
  
  delay(500);
  
  Serial.print("Value 500 milliseconds ago: ");
  Serial.println(sensorValue);

}
