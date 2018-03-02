/* We used a magnetic contact switch to turn a 
 *  tiny DC motor that was conected to pin 4
 *  to turn on and off 
*/unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 10; 
int motor = 4;
int lastButtonState = LOW;
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(motor, OUTPUT);
   digitalWrite(motor, LOW);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  
  int sensorValue = analogRead(A0);
   if (sensorValue != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
  // print out the value you read:
  Serial.println(sensorValue);
  //delay(100);        // delay in between reads for stability
  if (sensorValue == 0){
  digitalWrite(motor, HIGH);
}
  }
else{
  digitalWrite (motor, LOW);
  
}
}

