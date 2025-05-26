#include "arduino_secrets.h"
#include "thingProperties.h"

// === Right Motor (ENA, IN1, IN2) ===
const int ENA = 9;
const int IN1 = 10;
const int IN2 = 11;

// === Left Motor (ENB, IN3, IN4) ===
const int ENB = 3;
const int IN3 = 5;
const int IN4 = 6;

void setup() {
  Serial.begin(9600);
  delay(1500);

  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();

  // Motor control pins
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  stopMotors();
}

void loop() {
  ArduinoCloud.update();
}

//Stop All Motors
void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

//Forward
void onForWardChange() {
  if (forWard) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, 255);
    analogWrite(ENB, 255);
  } else {
    stopMotors();
  }
}

//Backward
void onBackWardChange() {
  if (backWard) {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENA, 255);
    analogWrite(ENB, 255);
  } else {
    stopMotors();
  }
}

//Turn Left
void onLeFtChange() {
  if (leFt) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, 255);
    analogWrite(ENB, 0);
  } else {
    stopMotors();
  }
}

//Turn Right
void onRiGhtChange() {
  if (riGht) {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, 0);
    analogWrite(ENB, 255);
  } else {
    stopMotors();
  }
}
