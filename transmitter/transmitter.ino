/*
* Arduino Wireless Communication Tutorial
*     Example 1 - Transmitter Code
*                
* by Dejan Nedelkovski, www.HowToMechatronics.com
* 
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
*/

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 8); // CE, CSN

const byte address[6] = "00001";
String InBytes;

void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  Serial.begin(9600);
}

void loop() {
  const char forward[] = "f";
  const char sto[] = "stop";
  const char right[] = "r";
  const char left[] = "l";
  //radio.write(&text, sizeof(text));
  delay(500);
  if (Serial.available() > 0){
    InBytes = Serial.readStringUntil('\n');
    //radio.write(&text2, sizeof(text2));
    //delay(1000);
    
    if (InBytes == "forward") {
      //Serial.write("Hit");
      radio.write(&forward, sizeof(forward));
      
      //radio.write(&InBytes, sizeof(InBytes));
    }
    else if (InBytes == "right") {
      //Serial.write("Hit");
      radio.write(&right, sizeof(right));
      
      //radio.write(&InBytes, sizeof(InBytes));
    }
    else if (InBytes == "left") {
      //Serial.write("Hit");
      radio.write(&left, sizeof(left));
      
      //radio.write(&InBytes, sizeof(InBytes));
    }
    else if (InBytes == "stop") {
      //Serial.write("Hit");
      radio.write(&sto, sizeof(sto));
      
      //radio.write(&InBytes, sizeof(InBytes));
    } 
  }
  //Serial.println("Hello");
}
