#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include<Servo.h>
Servo s;
RF24 radio(9, 8);  
const byte address[6] = "12345";


void setup()
{
  Serial.begin(9600);
  s.attach(6);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate(RF24_250KBPS);


  radio.startListening();
}


void loop()
{
  if (radio.available())
  {
    Serial.println("Connected");
    int val[2]                    ;
    radio.read(&val, sizeof(val));
    s.write(val[0]);
    analogWrite(A2,val[1]);
    analogWrite(A3,0);
    //Serial.println(val);
   
  }
  else
  {
    Serial.println("Disconnected");
  }
}
