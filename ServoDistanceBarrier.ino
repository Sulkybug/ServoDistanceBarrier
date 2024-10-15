#include <Servo.h>

const int trigPin = 9;
const int echoPin = 10;
const int ledRed = 7;
const int ledYellow = 6;
const int ledGreen = 5;
int servoPosition = 0; // Variable to track the servo position
Servo servo;

// Function to obtain the distance measured by the sensor
float obtenerDistancia() {
  // Clear the TRIG pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Send a pulse on the TRIG
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Calculate the time it takes for the pulse to return
  long duration = pulseIn(echoPin, HIGH);
  
  // Convert that time into a distance in centimeters (with one decimal)
  float distance = duration * 0.0343 / 2.0;
  
  return distance;
}

void setup() {
  // Configure the pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledRed, OUTPUT);
  // Start serial communication
  Serial.begin(9600);
  servo.attach(3);
  servo.write(0);   // Set to 0 degrees
  servoPosition = 0;
}

// Function to move the servo smoothly to a target position
void moveServoTo(int targetPosition, int delayTime) {
  // Determine the step size based on the target position
  int stepSize = (targetPosition > servoPosition) ? 1 : -1;
  
  // Move the servo incrementally
  while (servoPosition != targetPosition) {
    servoPosition += stepSize;
    servo.write(servoPosition);
    delay(delayTime); // Delay to control speed
  }
}

void loop()
{
   // Call the function and obtain the distance
  float distance = obtenerDistancia();
  
  // Display the distance in the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance, 1);
  Serial.println(" cm");
  
  // Control the servo based on the distance
  if (distance > 400 || distance <= 400 && distance > 100) { 
    if(servoPosition == 90){
     digitalWrite(ledGreen, LOW);
     digitalWrite(ledYellow, HIGH);
     moveServoTo(0, 15);    // Move to 0 degrees
     digitalWrite(ledYellow, LOW);
     digitalWrite(ledRed, HIGH);
    } else {digitalWrite(ledRed, HIGH);}
  } else {
    if (servoPosition == 0){
     digitalWrite(ledRed, LOW);
     digitalWrite(ledYellow, HIGH);
     moveServoTo(90, 15);  // Move to 90 degrees
     digitalWrite(ledYellow, LOW);
     digitalWrite(ledGreen, HIGH);
    }
  }
  
  // Wait a bit before the next measurement
  delay(500);
}
