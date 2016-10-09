/*this template is designed to lock the program in the chip unless 
 *you activated it. By doing this, you may be able to reprogram the
 *chip when the program in the chip is disasterous for your computer
 */

#define LOCKER_PIN 9 //the pin to activate the program locked(HIGH)
#define ACT_LED 10 //the led to turn on when activated(LOW->on)
#define SUPPLIER 11 //the pin to supply the high voltage

#include "Keyboard.h"

void setup(){
  preSet();
}

void loop(){
  if(digitalRead(LOCKER_PIN)){
    mainSetup();
    while(1){
      mainLoop();
    }
  }
}

void preSet(){
  pinMode(ACT_LED,OUTPUT);
  pinMode(SUPPLIER,OUTPUT);
  pinMode(LOCKER_PIN,INPUT);
  digitalWrite(SUPPLIER,HIGH);
  lightOff(); //used packed command to clear your thinking
  delay(200); //wait till the stable stage
}

void lightOn(){
  digitalWrite(ACT_LED,LOW);
}

void lightOff(){
  digitalWrite(ACT_LED,HIGH);
}

void mainSetup(){
  //put your code that run once when activated
  Keyboard.begin();
  lightOn();
}

void mainLoop(){
  //put your code that run repeatedly when activated
  
}

