/*
  ESC_Ramp
    Based on the Sweep example in the Servo library, this allow a ramp up and down of the ESC speed based on the Min and Max values.
    The Min and Max speed are defined so you can change them at one location and it will be used in the ramp as well.
    
  27 April 2017
  by Eric Nantel
 */
#include "ESC.h"
#define LED_PIN (13)                                      // Pin for the LED 
#define SPEED_MIN (1000)                                  // Set the Minimum Speed in microseconds
#define SPEED_MAX (2000)                                  // Set the Minimum Speed in microseconds

//드론 모터 위치   위치별 핀 번호 
// One   Two     6       9 
//    drn           drn 
// Thr   Fou    10       11 

ESC OneESC (6, SPEED_MIN, SPEED_MAX, 500);// ESC_Name (ESC PIN, Minimum Value, Maximum Value, Arm Value)
ESC TwoESC (9, SPEED_MIN, SPEED_MAX, 500); // 1000-2000사이의 값에서 모터별 세기 조절가능함. 숫자는 수정가능! ex 100-200 등등등! 
ESC ThrESC (10, SPEED_MIN, SPEED_MAX, 500);
ESC FouESC (11, SPEED_MIN, SPEED_MAX, 500);

int oESC;                                                 // Variable for the speed sent to the ESC

void setup() {
  pinMode(LED_PIN, OUTPUT);       // LED Visual Output
  OneESC.arm();  // Send the Arm value so the ESC will be ready to take commands
  TwoESC.arm();
  ThrESC.arm();
  FouESC.arm();
  
  digitalWrite(LED_PIN, HIGH);    // LED High Once Armed
  delay(5000);                    // Wait for a while
} //여기까지는 수정을 하지 않는게 좋음. 


void loop() {
  for (oESC = SPEED_MIN; oESC <= SPEED_MAX; oESC += 1) {  // goes from 1000 microseconds to 2000 microseconds
    OneESC.speed(oESC);                                    // tell ESC to go to the oESC speed value
    TwoESC.speed(oESC);  
    ThrESC.speed(oESC);  
    FouESC.speed(oESC);  
    delay(10);                                            // waits 10ms for the ESC to reach speed
  }
  delay(1000);
  for (oESC = SPEED_MAX; oESC >= SPEED_MIN; oESC -= 1) {  // goes from 2000 microseconds to 1000 microseconds
    OneESC.speed(oESC);                                    // tell ESC to go to the oESC speed value
    TwoESC.speed(oESC);  
    ThrESC.speed(oESC);  
    FouESC.speed(oESC);                                   
    delay(10);                                            // waits 10ms for the ESC to reach speed  
   }
  delay(5000);                                            // Wait for a while befor restart
}
