#include <AccelStepper.h>
// pin 22: pulse, pin 23: dir
AccelStepper xmotor(AccelStepper::DRIVER,
                    22, 23);

void setup() {
  // put your setup code here, to run once:
  xmotor.setMaxSpeed(3200);
  xmotor.setAcceleration(2500);
  Serial.begin(9600);
  Serial.println("Testing X motor...");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Current position: ");
  Serial.println(xmotor.currentPosition());

//  xmotor.moveTo(3200);
//  xmotor.runToPosition();
//  
//  Serial.println("half revolution completed.");
//
//  xmotor.moveTo(0);
//  xmotor.runToPosition();

    while(Serial.read() != 's');
    xmotor.enableOutputs();
    delay(3000);
    xmotor.moveTo(6400);
    xmotor.runToPosition();
    
    Serial.print("Current position: ");
    Serial.println(xmotor.currentPosition());
    Serial.println("one rev done, reversing now..");
    
    delay(5000);

    xmotor.moveTo(0);
    xmotor.runToPosition();

    Serial.print("Current position: ");
    Serial.println(xmotor.currentPosition());
    delay(5000);

    xmotor.disableOutputs();

//  delay(8000);
  
}
