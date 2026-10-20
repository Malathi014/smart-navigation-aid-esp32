#include <ESP32Servo.h>
#include <DHT.h>

#define TRIG_PIN 5
#define ECHO_PIN 18
#define IR_PIN 19
#define DHT_PIN 4
#define GAS_PIN 34
#define LDR_PIN 35
#define SERVO_PIN 13
#define LED_PIN 2

#define DHTTYPE DHT11

DHT dht(DHT_PIN, DHTTYPE);
Servo feedbackServo;

void setup() {
  Serial.begin(115200);
  
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(IR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  
  dht.begin();
  feedbackServo.attach(SERVO_PIN);
  feedbackServo.write(0); // Rest position
  
  Serial.println("Smart Blind Navigation System Initialized.");
}

void loop() {
  // 1. Ultrasonic Obstacle Detection
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH);
  float distance = duration * 0.034 / 2;

  // 2. IR Sensor (Pothole / Ground Drop)
  int irState = digitalRead(IR_PIN); // LOW means detected ground/obstacle

  // 3. Environmental Readings
  float temp = dht.readTemperature();
  int gasValue = analogRead(GAS_PIN);
  int ldrValue = analogRead(LDR_PIN);

  // --- Logic & Feedback Actions ---

  // Obstacle or Step drop detected -> Servo tactile tap
  if ((distance > 0 && distance < 35) || irState == HIGH) {
    feedbackServo.write(60); // Nudges user's hand
    Serial.println("ALERT: Obstacle or Ground Drop Ahead!");
  } else {
    feedbackServo.write(0);
  }

  // Toxic Gas / Smoke Alert
  if (gasValue > 1500) { 
    Serial.println("DANGER: High Gas/Smoke Concentration!");
  }

  // Extreme Weather / Temperature Alert
  if (temp > 42.0) {
    Serial.println("WARNING: High Ambient Temperature / Heat Alert!");
  }

  // Night Visibility (Auto LED)
  if (ldrValue > 2000) { // High resistance = Low light / Dark
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }

  delay(250);
}
