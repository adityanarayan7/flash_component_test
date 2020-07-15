#include <Wire.h>

#define PROTEIN_ADDRESS 0x70

#define ACTIVE_STATUS 0xCC
#define STATUS_REQUEST 0xEE

volatile uint8_t command = 0xFF;
byte _status[2] = {90, 0x7F};
void setup()
{   
    //Serial.begin(9600);
    Wire.begin(PROTEIN_ADDRESS);
    Wire.onReceive(receiveEvent);
    Wire.onRequest(sendData);
}

void receiveEvent(int howMany)
{   
//  Serial.println("got a request!");
    if(Wire.available())
    {   
        uint8_t c = Wire.read();
        command = c;
    }
    //Serial.println(command);
}

void sendData()
{   
    //Serial.println(command);
    if(command == ACTIVE_STATUS)
    { 
      //Serial.println("Sendind rq");
      Wire.write(1);
    }
    else if(command == STATUS_REQUEST)
    {
      //Serial.println("Sending the current status...");
      Wire.write(_status, 2);
      
    }
}

void loop()
{
    
}
