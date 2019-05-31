#include <ArduinoJson.h>

const int capacity = JSON_OBJECT_SIZE(3) + 3*JSON_OBJECT_SIZE(1);
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
char init(char arr[],int len){
  int i;
  for(i=0;i<len;i++){
    arr[i]=0;
  }
}
void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0){
    incomingByte = Serial.read();
    if(incomingByte==13){
      data[i++]='\0';
      Serial.println("fin");
      i=0;
      DeserializationError err = deserializeJson(doc, data);
      if(err){
        Serial.print("err");
        digitalWrite(led,HIGH);
        delay(1000);
        digitalWrite(led,LOW);
      }else{
        char move=doc["to"];
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
            digitalWrite(led,HIGH);
            delay(100);
            digitalWrite(led,LOW);
            break;
        }
      }
      init(data,i);
    }
    else{
      data[i++]=incomingByte;
    }
    Serial.print(incomingByte);
    Serial.print(' ');
  }
}
