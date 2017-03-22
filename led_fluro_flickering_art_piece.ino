// Flickering LED fluro light art project
// As a visitor approaches the light, it flickers
// When they stop moving, it stops flickering

// By Kristen Coleman <kristen.coleman (at) internode dot on dot net>

// Technical: Hackerspace Adelaide - March 2017

// Parts:
// 96v LED fluro, split into 4 parallel sections at ~24v (actual ~26v)
// LED driver KC24W-700
// Infrared proximity sensor RCW-0506
// Arduino Uno

int pirPin = 7;  // Sensor
int ledPin = 6;  // Fluro
int pwmLowerLimit = 75;  // Fluro lower light limit
int pwmUpperLimit = 150;  // Fluro brightest light limit
int flickerDelayLowerLimit = 30; // Minimum time in milliseconds between the flickers
int flickerDelayUpperLimit = 100; // Maximum time in milliseconds between the flickers
int flickerCyclesWhenTriggered = 10; // How many times to flicker

void setup() {
  // Setup serial and the pins
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.println("Oh hello. http://hackadl.org");
  Serial.println("============================");
}

void loop() {
  // Check the sensor
  if (digitalRead(pirPin) == HIGH) {
    // Movement detected
    Serial.println("The light, it flickers.");
    flickerLED();
  } else {
    // No motion, so set it on
    analogWrite(ledPin, pwmUpperLimit);
  }
}

void flickerLED() {
  // Choose a random brightness, and stay on for a random time
  for (int i = 0; i < flickerCyclesWhenTriggered; i++) {
    analogWrite(ledPin, random(pwmLowerLimit, pwmUpperLimit));
    delay(random(flickerDelayLowerLimit, flickerDelayUpperLimit));
  }
}

