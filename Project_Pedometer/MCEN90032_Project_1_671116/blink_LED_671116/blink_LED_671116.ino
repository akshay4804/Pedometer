
// LED blinking function for Sensor Systems, which was written by Akshay Kumar, 671116

int ledPin = 13; //Delcaring the pin number of the LED

void setup() {

// Defining the LED to be an output
  pinMode(ledPin, OUTPUT);
  // Begin the serial printing
  Serial.begin(9600);
  Serial.print("Serial Monitor of Akshay, 671116 ");
  Serial.print("\n");
}

void loop() {
  // This will tell the LED to turn on
  digitalWrite(ledPin, HIGH);
  // This will print out in the Serial Monitor
  Serial.print("Current LED Pin state: ");
  Serial.println(digitalRead(ledPin));
  // Delay the print out by 1 second
  delay(1000);
   // This will tell the LED to turn off
  digitalWrite(ledPin, LOW);
  Serial.print("Current LED Pin state: ");
  Serial.println(digitalRead(ledPin));
  delay(1000);
  
  
}
