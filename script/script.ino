#include <Servo.h>

Servo myservo;  // create servo object to control a servo

// set variables
float openingDistanceLimit = 10;
float capacityLimit = 10;

// servo motor pin
int servoPin = 9;
float servoAngle = 90;

// ultrasonic sensor pins
int trigPin = 7;
int echoPin = 8;

// ultrasonic sensor pins
int trigPin2 = 5;
int echoPin2 = 6;

// buzzer pin
int buzzerPin = 10;

void setup() {
  // set pins as output
  // pinMode(servoPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(buzzerPin, OUTPUT);

  myservo.attach(servoPin);
}

void loop() {
  // check distance
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // set trigPin to HIGH
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  // set trigPin to LOW
  digitalWrite(trigPin, LOW);

  // read echoPin
  float duration = pulseIn(echoPin, HIGH);

  float distance = duration * 0.034 / 2;

  // check if distance is less than 10cm
  if (distance < openingDistanceLimit) {
    myservo.write(servoAngle);
  } else {
    myservo.write(0);
  }

  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);

  // set trigPin to HIGH
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);

  // set trigPin to LOW
  digitalWrite(trigPin2, LOW);

  // read echoPin
  float duration2 = pulseIn(echoPin2, HIGH);

  float capacity = duration2 * 0.034 / 2;  

  // check capacity
  if (capacity < capacityLimit) {
    // set buzzer pin to HIGH
    digitalWrite(buzzerPin, HIGH);
  } else {
    // set buzzer pin to LOW
    digitalWrite(buzzerPin, LOW);
  }
}

// float getDistance(trigPin, echoPin) {
//   // set trigPin to LOW
//   digitalWrite(trigPin, LOW);
//   delayMicroseconds(2);

//   // set trigPin to HIGH
//   digitalWrite(trigPin, HIGH);
//   delayMicroseconds(10);

//   // set trigPin to LOW
//   digitalWrite(trigPin, LOW);

//   // read echoPin
//   float duration = pulseIn(echoPin, HIGH);

//   // calculate distance
//   float distance = duration * 0.034 / 2;

//   // return distance
//   return distance;
// }