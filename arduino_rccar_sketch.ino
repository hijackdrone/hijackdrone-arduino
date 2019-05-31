#include <ArduinoJson.h>

const int capacity = JSON_OBJECT_SIZE(3) + 2*JSON_OBJECT_SIZE(1);
StaticJsonDocument<capacity> doc;

int led=13;
int i=0;
int tx=0;
int rx=1;
char data[200]={};
int incomingByte=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led,OUTPUT);
}
char init(char arr[]){
  int i;
  for(i=0;i<200;i++){
    arr[i]=0;
  }
}dddd
void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0){
    incomingByte = Serial.read();
    if(incomingByte==10){
      Serial.println("fin");
      i=0;
      DeserializationError err = deserializeJson(doc, data);
      if(err){
        Serial.print("err");
      }else{
        char move=doc["to"];
        Serial.println(move);
        switch(move){
          case 'f': //front
            digitalWrite(led,HIGH);
            digitalWrite(rx,HIGH);
            break;
          case 'l': //left
            digitalWrite(led,HIGH);
            break;
          case 'r': //right
            digitalWrite(led,HIGH);
            break;
          case 'b': //back
            digitalWrite(led,LOW);
            break;
          default: //stop
            digitalWrite(tx,HIGH);
            break;
        }
      }
      init(data);
    }
    else{
      data[i++]=incomingByte;
    }
    Serial.print(incomingByte);
  }
}