void setup() {
  // put your setup code here, to run once:
  const int capacity = JSON_OBJECT_SIZE(2) + 2*JSON_OBJECT_SIZE(1);
  StaticJsonDocument<capacity> doc;
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    data = Serial.readString();
    Deserialization err = deserializeJson(doc, data);
    if(err){
      ...
    }else{
      char move=doc["to"];
      switch(move){
        case 'f': //front
          analogWrite(5,10);
          analogWrite(6,10);
          analogWrite(7,10);
          analogWrite(8,10);
          break;
        case 'l': //left
          analogWrite(5,10);
          analogWrite(6,0);
          analogWrite(7,10);
          analogWrite(8,0);
          break;
        case 'r': //right
          ...
          break;
        case 'b': //back
          ...
          break;
        default: //stop
          ...
          break;
      }
    }
  }
}
