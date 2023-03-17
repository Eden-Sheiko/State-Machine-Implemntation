# State Machine Implementation
This code is an implementation of a state machine that changes the status of three LEDs based on the number of times a button (Button S1) is pressed. The state machine has 8 states, where each state corresponds to a different combination of LEDs being turned on/off.

## Getting Started
To use this code, you will need an Arduino board, three LEDs, a resistor for each LED, a push-button (Button S1), and some jumper wires. Connect the LEDs and resistors to pins 11, 12, and 13 of the Arduino board, and connect the push-button to pin 2. Then, upload the code to the Arduino board using the Arduino IDE or any other software that supports Arduino.

## Code Explanation
The code starts by defining some constants, including the initial state of the state machine. The setup() function initializes the input and output pins of the Arduino board. The loop() function reads the status of the push-button and updates the state of the state machine accordingly.

## The push-button is checked for debouncing, and the state is incremented by 1 each time the button is pressed. If the state reaches the value of 8, it returns to the initial state (0). The state machine is implemented using a switch statement, where each case corresponds to a different combination of LEDs being turned on/off. The default case is executed if the state value is not within the range of 0 to 7.

## Usage
This code can be used as a basic example of a state machine implementation in an Arduino project. It can also be modified to control other devices or sensors based on the state of the system.

License
This code is licensed under the MIT License. Please see the LICENSE file for more information.
