/*
  Inspiration and Copyright
  =========================
  This code is in the public domain.
  
  Code has been adapted from the tutorial written by Gus and posted on PiMyLifeUp
  [https://pimylifeup.com/arduino-light-sensor/] and the basic example sketch 
  AnalogReadSerial provided with the Arduino microcontroller accessable via the
  Arduino IDE and online [https://www.arduino.cc/en/Tutorial/AnalogReadSerial].
*/

/*
  First part of any sketch
  ------------------------
  Before we can do anything, we need to set up our variables.

  In our code we will want to tell Arduino which digital pins we will be using and 
  what name we will call them.
  Next, we will set up a variable that holds the value for the analogue pin we 
  will be using for our sensor to send input to. Note that Arduino internal code
  uses American  spelling, so you will see both Analogue and Analog used as I will
  stick with Australian spelling rules.
  Then, we will set the variable to hold the measured value and set it to a 
  starting value of 0. We could set it to any value but 0 shows that it is 
  currently empty which is why we chose it.
*/ 
int redLedPin = 2;
int yellowLedPin = 3;
int greenLedPin = 4;

int analogueSignalPin = A0;
int analogueValue = 0;

/*
  Second part of the sketch
  -------------------------
  Next we us the setup() structure. The counded brackets stay empty. setup()
  is only executed once during the first run of the program. This happens every 
  time the sketch is uploaded or the microcontroller is reset.

  At this stage we have to tell Arduino which pins we will be using and if we 
  will be using them for INPUT or OUTPUT. For this we use the command pinMode. It 
  demands two values. 

  pinMode(VALUE_ONE, VALUE_TWO);
  
  First, we  need to tell it which pin we want to set. The 
  next value declares if the pin is to be used for INPUT or OUTPUT. Note that the 
  last value is provided in capital letters.

  We further have to initialise the serial port and declare which speed we want 
  it to have. We will set it at the most common value of 9600.
*/
void setup () {
  pinMode(redLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  
  pinMode(analogueSignalPin, INPUT);

  Serial.begin(9600);
}

/*
  Third and last part of the sketch
  ---------------------------------
  Now comes the meat of our program. Here we write what we want our Arduino to 
  do. This code is continuously executed, over and over again, until the power is
  withdrawn, hence the structure’s name loop. 
*/
void loop () {
  /*
    First, we need to fill our analogueValue variable with the information we 
    are gathering with our sensor to let Arduino know which LED to turn on and 
    which to turn off.
  
    To get this information we use the analogRead() command. All it needs to know is where to 
    Find the information. In our case we stored that information in the lightSensorPin 
    variable.

    Note that the programming language has been defined with American English in mind, so you
    will find a difference in spelling analogue.
  */
  analogueValue = analogRead(analogueSignalPin);
  
  /*
    Once Arduino knows the sensor’s data that determines the LED that is to be turned on (it
    does so by reading the value stored in the analogValue variable), we need to say at what 
    value we want which LED to be switched on.

    Below, the code tells Arduino that any value below 600 is the value at which the red LED 
    is to be turned on. And if the value should be equal to or greater than that but equal or 
    smaller than 750 then the yellow LED will come on. If the value exceeds 750 the green LED 
    is to be turned on. Change the values to suit your needs. Each sensor provides values that 
    differ from each other. Use the feedback provided to you via the serial port to determine 
    which values to set.

    To turn the LED on we use the digitalWrite() command which demands two values. 

    digitalWrite(PIN_TO_CONTOL, ON_OR_OFF_STATE);
    
    First, we need to provide it with the pin we want to change and then it needs to know if 
    that pin is to be turned on or off. On has the HIGH value, while off has the LOW value. 
    Once again note that the ON_OR_OFF_STATE value is provided in capitals.

    Further, we want the serial monitor to not only show the value measured but also what this 
    means. Here we use the print() function which prints out what ever it is provided with (a 
    string or other data. The print out is without a carriage return. If you want a new line 
    to start after whatever you want printed out, use the println() function.
  */
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

  /*
    After printing out that the Arduino will print out the analgue measure value we now 
    instruct Aruino to print out the value measured. After printing out the value it 
    performs a carriage return and every new print command starts on a new line.
  */
  Serial.println(analogueValue);

  /*
    We now tell Arduino how long we want it to wait until it takes the next measurement. 
    Here we use the delay() function. It takes one value in milliseconds. For our 
    purposes taking a measurement every half a second is good enough. Hence the value set
    is 500. It needs to be at least set to 1, or it the circuit and sketch will not 
    perform properly.
  */
  delay(500);

  /*
    Now that we are ready to start again at the beginning ouf our loop construct we need 
    to turn the LED back off. The time from turning the light off and back on again can’t 
    be noticed as the microcontroller works fast enough not to notice it. If we do not 
    turn it off, it will stay on for the whole time of the loop. So after some point all
    three LEDs will be switched on.
  */
  digitalWrite(redLedPin, LOW);
  digitalWrite(yellowLedPin, LOW);
  digitalWrite(greenLedPin, LOW);
}
