#include <Adafruit_MAX31865.h>

// uses hardware SPI.

Adafruit_MAX31865 thermo = Adafruit_MAX31865(14);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("hello");
  thermo.begin(MAX31865_3WIRE);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(thermo.temperature(100, 430.0));
  delay(1000);
  

}
