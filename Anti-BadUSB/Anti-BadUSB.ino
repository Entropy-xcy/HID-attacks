/*
 * This program is designed to check if the device connected to the 
 * USB port is a Bad USB, the result will be pulled out from the 
 * Serial
 */

#define DATA_P 2
#define DATA_N 3
#define LED 13

boolean dataP=0;
boolean bufferP=0;
boolean dataN=0;
boolean bufferN=0;
boolean dataR=0;
boolean bufferR=0;

void setup(){
  pinMode(DATA_P,INPUT);
  pinMode(DATA_N,INPUT);
  pinMode(LED,OUTPUT);
  //Serial.begin(9600);
}

void loop(){
  bufferP=digitalRead(DATA_P);
  bufferN=digitalRead(DATA_N);
  if(bufferP>bufferN){
    bufferR=1;
  }
  else{
    bufferR=0;
  }
  if(bufferR!=dataR){
    dataR=bufferR;
    //Serial.println(dataR);
    digitalWrite(LED,dataR);
  }
}

