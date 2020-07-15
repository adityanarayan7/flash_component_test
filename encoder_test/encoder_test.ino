int encoderCount = 0;
void encoder(void);


void setup() {
  // put your setup code here, to run once:
  pinMode(6, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
//  pinMode(18, INPUT);
//  pinMode(19, INPUT);

  analogWrite(6, 25);
  digitalWrite(15, HIGH);
  digitalWrite(14  , LOW);

  attachInterrupt(digitalPinToInterrupt(18), encoder, FALLING);

  Serial.begin(9600);
}

void encoder()
{
  //Serial.println("Interrupt called");
  encoderCount++;
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  

}
