#include <Servo.h>
const int throttle_set = 2000;//最大回転数時のPWM幅
const int throttle_low = 1000;//ESCの最小のPWM幅（800us以上じゃないと認識しない）
Servo throttle;
int level;

void setup()
{
  throttle.attach(9);//arduinoの9番ピンに接続

  level = throttle_low;//スロットルを最小に設定
  throttle.writeMicroseconds(level);//PWMを初期化
  delay(800);//ESCの初期化(500ms以下だと初期化できない)
}

void loop() {
  for (level = 1100; level <= 2000; level += 1) {//PWM幅を1100から2000まで徐々に上げる
    throttle.writeMicroseconds(level);
    delay(5);
  }
  //delay(2000);
  for (level = 2000; level >= 1100; level -= 1) {//PWM幅を2000から1100まで徐々に下げる
    throttle.writeMicroseconds(level);
    delay(5);
  }
  delay(800);
}
