Servo Distance Barrier
Description
This project controls a servo motor to open a parking barrier based on distance measurements from an ultrasonic sensor. When a vehicle approaches, the system triggers the servo to rotate and allow access.

Features
Distance Measurement: Uses an ultrasonic sensor to detect vehicles.
Servo Control: Automatically opens the barrier based on proximity.
LED Indicators: Visual feedback with red, yellow, and green LEDs.
Code Overview
Ultrasonic Sensor: Measures the distance to the nearest object.
Servo Control Logic: Moves the servo to 0 or 90 degrees depending on the detected distance.
LED Indicators: Lights up based on the barrier's state.
Components Required
Arduino board
Servo motor
Ultrasonic sensor (HC-SR04)
3 LEDs (Red, Yellow, Green)
Resistors for LEDs (typically 220Ω)
