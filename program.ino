#include <SoftwareSerial.h>

SoftwareSerial bluetooth(0, 1); // RX, TX

#define RELAY_1_PIN 2 // Pin for controlling first relay
#define RELAY_2_PIN 3 // Pin for controlling second relay
#define RELAY_3_PIN 4 // Pin for controlling third relay

char command; // Variable to store incoming command

void setup() {
  pinMode(RELAY_1_PIN, OUTPUT);
  pinMode(RELAY_2_PIN, OUTPUT);
  pinMode(RELAY_3_PIN, OUTPUT);

  digitalWrite(RELAY_1_PIN, LOW); // Initially turn off relay 1
  digitalWrite(RELAY_2_PIN, LOW); // Initially turn off relay 2
  digitalWrite(RELAY_3_PIN, LOW); // Initially turn off relay 3

  bluetooth.begin(9600); // Default baud rate for most Bluetooth modules
  Serial.begin(9600); // For debugging purpose
}

void loop() {
  if (bluetooth.available() > 0) { // If data is available to read
    command = bluetooth.read(); // Read the incoming command from Bluetooth
    executeCommand(command); // Execute the received command
  }
}

void executeCommand(char cmd) {
  switch (cmd) {
    case '1':
      digitalWrite(RELAY_1_PIN, !digitalRead(RELAY_1_PIN)); // Toggle relay 1
      break;
    case '2':
      digitalWrite(RELAY_2_PIN, !digitalRead(RELAY_2_PIN)); // Toggle relay 2
      break;
    case '3':
      digitalWrite(RELAY_3_PIN, !digitalRead(RELAY_3_PIN)); // Toggle relay 3
      break;
    default:
      break;
  }
}

