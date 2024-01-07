/*
* Arduino Wireless Communication Tutorial
*       Example 1 - Receiver Code
*                
* by Dejan Nedelkovski, www.HowToMechatronics.com
* 
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
*/

int motor1pin1 = 2;
int motor1pin2 = 3;
int motor2pin1 = 4;
int motor2pin2 = 7;
String command;

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();

  pinMode(motor1pin1,OUTPUT);
  pinMode(motor1pin2,OUTPUT);
  pinMode(motor2pin1,OUTPUT);
  pinMode(motor2pin2,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  
}

void loop() {
  if (radio.available()) {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    Serial.println(text);
    command = text;
    if (command == "f") {
      //Serial.println("HERE");
      analogWrite(5,255);
      analogWrite(6,255);
      digitalWrite(motor1pin1, HIGH);
      digitalWrite(motor1pin2, LOW);
      
      digitalWrite(motor2pin1, HIGH);
      digitalWrite(motor2pin2, LOW);
    }
    else if (command == "r") {
      digitalWrite(motor1pin1, HIGH);
      digitalWrite(motor1pin2, LOW);
      
      digitalWrite(motor2pin1, LOW);
      digitalWrite(motor2pin2, HIGH);
    }
    else if (command == "l") {
      digitalWrite(motor1pin1, LOW);
      digitalWrite(motor1pin2, HIGH);
      
      digitalWrite(motor2pin1, HIGH);
      digitalWrite(motor2pin2, LOW);
    }  
    else if (command == "stop") {
      digitalWrite(motor1pin1, LOW);
      digitalWrite(motor1pin2, LOW);
      digitalWrite(motor2pin1, LOW);
      digitalWrite(motor2pin2, LOW);
    }  
    
  }
}
