#include <Wire.h>
#include "rgb_lcd.h"
#include "Adafruit_MPR121.h"
#define greenLED 5
#define redLED 6
// Add CDC library

rgb_lcd lcd;
Adafruit_MPR121 cap = Adafruit_MPR121();

const int colorR = 255;
const int colorG = 0;
const int colorB = 0;

// Change threshold when gotten CDC capacitance reading
const int dry = 90; // Value for dry soil (packaged)
const int wet = 38; // Value for wet soil (saturated)

int water = 0; // Initialize watering state (0=off, 1=on)
static int lastWaterState = -1; // To track previous water state

void setup() {
  
  delay(1000); // Allow time for initialization (establish master/slave communication)
  Serial.begin(9600); // Bluetooth communication
  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  // Add CDC setup
  if (!cap.begin(0x5A)) { // Ensure the MPR121 is detected at address 0x5A
  Serial.println("MPR121 not found, check wiring!");
  while (1); // Halt execution if the sensor is not detected
  }
  Serial.println("MPR121 initialized.");

}

void loop() {
  int sum = 0;
  for (int i = 0; i < 10; i++) { // Take 10 readings in 1 second
    sum += cap.filteredData(0);
    delay(100); // Wait 0.1 second between readings
  }

  int current = sum / 10; // Average the readings, CDC measurement configurations with capacitance result

  // From here on can remain
  int moistPercent = map(current, wet, dry, 100, 0);
  moistPercent = constrain(moistPercent, 0, 100); // Ensure it's within 0-100%
  
  char buffer[17]; // Buffer for one line (16 characters + null terminator)
  sprintf(buffer, "Moisture:%3d%%", moistPercent); // Format the string
  lcd.setCursor(0, 0);
  lcd.print(buffer); // Print the entire line
  
  lcd.setCursor(0,1);
  lcd.print("Water Pump");

  if (moistPercent < 20 && water != 1) {
    water = 1; // Update watering state to on
    Serial.print(water); // Send state to slave
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
  } 
  else if (moistPercent >= 20 && water != 0) {
    water = 0; // Update watering state to off
    Serial.print(water);
    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);
  }

  // Display water pump status only when state changes
  if (lastWaterState != water) {
    lcd.setCursor(11, 1);
    if (water == 1) {
      lcd.print("ON ");
    } else {
      lcd.print("OFF");
    }
    lastWaterState = water;
  }

  delay(1000); // Delay for stability
  
}
