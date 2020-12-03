/*モーター4つをそれぞれの回転数を制御するプログラム

テンションはsolo_controlやdouble_controlと一緒なので解説は省く
*/

#include <Servo.h>

const int throttle_high = 2000;
const int throttle_low = 1000;
int val,val1,val2,val3;
Servo throttle;
Servo throttle1;
Servo throttle2;
Servo throttle3;
int level = throttle_low;

void setup(){
  Serial.begin(9600);
  throttle.attach(11);
  throttle1.attach(6);
  throttle2.attach(10);
  throttle3.attach(9);
  throttle.writeMicroseconds(level);
  throttle1.writeMicroseconds(level);
  throttle2.writeMicroseconds(level);
  throttle3.writeMicroseconds(level);
  delay(1000);
}

void loop() {

      for (level = throttle_low; level <= throttle_high; level += 500) { //最初にある程度回転させないと制御できない
  throttle.writeMicroseconds(level);
  throttle1.writeMicroseconds(level);
  throttle2.writeMicroseconds(level);
  throttle3.writeMicroseconds(level);
    delay(1000);
  }
        for (level = throttle_low; level <= throttle_high; level += 10) { //最初にある程度回転させないと制御できない
          val = analogRead(A0);
          val1 = analogRead(A1);    
          val2 = analogRead(A2);
          val3 = analogRead(A3); 
          val = map(val,0, 1024, 1000, 2000);
          val1 = map(val1,0, 1024, 1000, 2000);
          val2 = map(val2,0, 1024, 1000, 2000);
          val3 = map(val3,0, 1024, 1000, 2000);
          throttle.writeMicroseconds(val);
          throttle1.writeMicroseconds(val1);
          throttle2.writeMicroseconds(val2);
          throttle3.writeMicroseconds(val3);
          delay(1000);
  }
  
    

}