/* 
  Simple control sketch that takes in an analogues signal and prints out the 
  value. First, we declare our variable to hold the measured analogue signal
  value, then we set values for system variables. Finally, we have the circuit
  control code.
*/
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
