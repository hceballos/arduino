#include <Servo.h>

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

Servo servo_8;

void setup()
{
  pinMode(13, OUTPUT);
  servo_8.attach(8);

  pinMode(12, OUTPUT);
}

void loop()
{
  if (0.01723 * readUltrasonicDistance(10, 10) < 20) {
    delay(100);                       // wait for a second
    digitalWrite(13, HIGH);
    servo_8.write(80);
    digitalWrite(12, LOW);
    delay(100);                       // wait for a second

  } else {
    delay(100);                       // wait for a second
    digitalWrite(13, LOW);
    servo_8.write(0);
    digitalWrite(12, HIGH);
    delay(100);                       // wait for a second
  }
  delay(10); // Delay a little bit to improve simulation performance
}
