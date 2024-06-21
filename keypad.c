/*
    Project name : ESP8266 Keypad
    Modified Date: 20-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/esp8266-keypad
*/

#include <Keypad.h>

// Define the rows and columns for the keypad
const byte ROWS = 4; // Four rows
const byte COLS = 4; // Four columns

// Define the keymap for the keypad
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// Define the pins connected to the keypad rows and columns
byte rowPins[ROWS] = {D1, D2, D3, D4}; // Connect to the row pinouts of the keypad
byte colPins[COLS] = {D5, D6, D7, D8}; // Connect to the column pinouts of the keypad

// Create the Keypad object
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  // Read the key pressed on the keypad
  char key = keypad.getKey();

  // If a key is pressed, print it to the Serial Monitor
  if (key) {
    Serial.print("Key pressed: ");
    Serial.println(key);
  }

  delay(100); // Add a small delay to avoid spamming the Serial Monitor
}
