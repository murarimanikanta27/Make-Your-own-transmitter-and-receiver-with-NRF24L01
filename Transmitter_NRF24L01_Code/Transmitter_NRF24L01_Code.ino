//Include Libraries   FOR transmitter
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
int y=A0;
int val[2];
RF24 radio(9, 8);  
const byte address[6] = "12345";
void setup()
{
  Serial.begin(9600);
 
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate(RF24_250KBPS);
  radio.stopListening();
}
void loop()
{
   val[0]=analogRead(A0);
   val[1]=analogRead(A1);
   val[0]=map(val[0],0,1023,0,180);
   val[1]=map(val[1],0,1023,0,255);
   radio.write(&val, sizeof(val));
 
}
