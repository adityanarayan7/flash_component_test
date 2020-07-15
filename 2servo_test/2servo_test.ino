#include <Servo.h> 
Servo myservo1;
Servo myservo2; 
int pos;
float starttime,endtime,loopcount;
void setup() {
  Serial.begin(9600);
myservo1.attach(2); 
myservo2.attach(3); 
}
void loop() {
Serial.println("start dispensing");
stirrer_on();
stirrer_off();
dispenser_valve_open();
delay(3000);
Serial.println("stop dispensing");
dispenser_valve_close();
delay(10000);
}
void dispenser_valve_open()
{
myservo1.attach(2);  
myservo1.write(35);
delay(100);
myservo1.detach();
  }
void dispenser_valve_close()
{
myservo1.attach(2); 
myservo1.write(160);
delay(100);
myservo1.detach();
  }
void stirrer_on()
{
  starttime = millis();
endtime = starttime;
while ((endtime - starttime) <=5000)
{
  Serial.println("stirring");
for (pos = 0; pos <= 180; pos += 1) { 
    myservo2.write(pos);              
    delay(5);                       
  }
  for (pos = 180; pos >= 0; pos -= 1) {
    myservo2.write(pos);              
    delay(5);                     
  }
  loopcount = loopcount+1;
endtime = millis(); 
} 
}
void stirrer_off()
{
  myservo2.write(0);  
  delay(100);
  Serial.println("done stirring");
  }
 
