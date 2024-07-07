#include <Servo.h>

// Define pin numbers
const int buttonPin = 2;
const int blueLedPin = 3;
const int greenLedPin = 4;
const int servo1Pin = 9;
const int servo2Pin = 10;

// Create servo objects
Servo servo1;
Servo servo2;

// Define state variables
int buttonState = 0;
int lastButtonState = 0;
bool state = false;

void setup() {
  // Initialize LED pins as outputs
  pinMode(blueLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  
  // Initialize button pin as input with internal pull-up resistor
  pinMode(buttonPin, INPUT_PULLUP);

  // Attach the servos to their respective pins
  servo1.attach(servo1Pin);
  servo2.attach(servo2Pin);

  // Set initial servo positions
  servo1.write(90); // Neutral position
  servo2.write(90); // Neutral position
}

void loop() {
  // Read the state of the button
  buttonState = digitalRead(buttonPin);

  // Check if the button is pressed (active low due to pull-up resistor)
  if (buttonState == LOW && lastButtonState == HIGH) {
    state = !state; // Toggle state
    
    if (state) {
      // State 1: Blue light on, green light off
      digitalWrite(blueLedPin, HIGH);
      digitalWrite(greenLedPin, LOW);

      // Move servos
      servo1.write(60); //
      servo2.write(0);  // 
    } else {
      // State 2: Blue light off, green light on
      digitalWrite(blueLedPin, LOW);
      digitalWrite(greenLedPin, HIGH);

      // Move servos back
      servo1.write(0);  // 
      servo2.write(60); // 
    }
  }

  lastButtonState = buttonState;
}
