#include <AFMotor.h> // 모터드라이버L293D용 라이브러리

//Made by 상민

AF_DCMotor motor1(1); // 전방 좌측 바퀴 M1 ==전방 좌측 바퀴는 M1에 연결 할 것!
AF_DCMotor motor2(2); // 전방 우측 바퀴 M2 ==전방 우측 바퀴는 M2 "
AF_DCMotor motor3(3); // 후방 좌측 바퀴 M3 ==후방 좌측 바퀴는 M3 "
AF_DCMotor motor4(4); // 후방 우측 바퀴 M4 ==후방 우측 바퀴는 M4 "


//시리얼 모니터를 통한 4방향 조정

//"APP과의 연결만 끝나면 모든 개발 완료"

void setup() {
  Serial.begin(115200);
  
  motor1.setSpeed(200); // 모터 스피드(1~255)
  motor2.setSpeed(200);
  motor3.setSpeed(200);
  motor4.setSpeed(200);
  
  motor1.run(RELEASE); // 처음에는 멈춘 상태
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);

}

void loop() {
  
  if(Serial.available())
  {   
    char Dir = Serial.read();

    if( Dir == 'f') //f 받으면 전방바퀴만 전진
    {
    motor1. run(BACKWARD);
    motor2. run(FORWARD);
    motor3. run(BACKWARD);
    motor4. run(FORWARD);
    delay(100);
    }
    
    else if( Dir == 'b') //b받으면 후방바퀴만 후진
    {
    motor1.run(FORWARD);
    motor2.run(BACKWARD);
    motor3.run(FORWARD);
    motor4.run(BACKWARD);
    delay(100);
    }
    
    else if ( Dir == 'l') // l받으면 오른쪽은 뒤로 왼쪽은 앞으로 가서 방향만 회전
    {
    motor1.run(FORWARD);
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);
    motor4.run(FORWARD);
    delay(100); // 적당히 조절할 필요가 있어보임.
    }
    
    else if ( Dir == 'r') // l과 반대로 방향만 회전
    {
    motor1. run(BACKWARD);
    motor2. run(FORWARD);
    motor3. run(FORWARD);
    motor4. run(BACKWARD);
    delay(100); //적당히 조절할 필요가 있어보임.
    }
  }  
  motor1. run(RELEASE);
  motor2. run(RELEASE);
  motor3. run(RELEASE);
  motor4. run(RELEASE); 
}
