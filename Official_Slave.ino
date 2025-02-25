#define pumpPin 4
#define solenoidPin 3

int water = 0; // Initialize

void setup() {

  delay(1000); // Allow time for initialization (establish master/slave communication)
  Serial.begin(9600); // Bluetooth communication
  pinMode(pumpPin, OUTPUT);
  pinMode(solenoidPin, OUTPUT);

}

void loop() {

   if (Serial.available()) { // Check if command received
    water = Serial.parseInt();      // Read the integer value (0 or 1)
   }

    if (water == 1) {
      delay(5000); // Wait for soil to absorb water properly
      digitalWrite(pumpPin, LOW);      // Turn on pump
      delay(500);
      digitalWrite(solenoidPin, LOW); // Turn on solenoid
      delay(500);
      digitalWrite(pumpPin, HIGH);      // Turn off pump
      digitalWrite(solenoidPin, HIGH); // Turn off solenoid
      delay (5000);
    } else if (water == 0) {
      digitalWrite(pumpPin, HIGH);      // Turn off pump
      digitalWrite(solenoidPin, HIGH); // Turn off solenoid
    }

}
    