// set variables
float openingDistanceLimit = 10;
float capacityLimit = 10;

// servo motor speed
int servoSpeed = 100;

// servo motor pin
int servoPin = 9;

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
    pinMode(servoPin, OUTPUT);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(trigPin2, OUTPUT);
    pinMode(echoPin2, INPUT);
    pinMode(buzzerPin, OUTPUT);
}

void loop() {
    // check distance
    int distance = getDistance(trigPin, echoPin);
    int Capacity = getDistance(trigPin2, echoPin2);

    // check if distance is less than 10cm
    if (distance < openingDistanceLimit) {
        // set servo motor speed
        analogWrite(servoPin, servoSpeed);

        // check if distance is less than 5cm
        if (distance < 5) {
            // set buzzer pin to HIGH
            digitalWrite(buzzerPin, HIGH);
        } else {
            // set buzzer pin to LOW
            digitalWrite(buzzerPin, LOW);
        }
    } else {
        // set servo motor speed
        analogWrite(servoPin, 0);
    }

    // check capacity
    if (Capacity < capacityLimit) {
        // set buzzer pin to HIGH
        digitalWrite(buzzerPin, HIGH);
    } else {
        // set buzzer pin to LOW
        digitalWrite(buzzerPin, LOW);
    }
}

float getDistance(trigPin, echoPin) {
    // set trigPin to LOW
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    // set trigPin to HIGH
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);

    // set trigPin to LOW
    digitalWrite(trigPin, LOW);

    // read echoPin
    float duration = pulseIn(echoPin, HIGH);

    // calculate distance
    float distance = duration * 0.034 / 2;

    // return distance
    return distance;
}