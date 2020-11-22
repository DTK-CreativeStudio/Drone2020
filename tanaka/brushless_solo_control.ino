/*ブラシレスモーターの制御ピンを。arduinoの9ピンに接続し、mブラシレスモーターを単一制御させた時のプログラム。
*/


#include <Servo.h>

const int throttle_high = 2000;   //最高の回転数を決める(値は回転数ではない)
const int throttle_low = 1000;    //最低の回転数を決める(値は回転数ではない)

Servo throttle;　　　　　　　　　　


int level = throttle_low;

void setup(){

  throttle.attach(9);

  throttle.writeMicroseconds(level);  //先にサーボモーターの初期位置を決めておく
  delay(1000);                        //[注意]この値を900,800などにすると回らなくなるので注意!!
}

void loop() {
      

      for (level = throttle_low; level <= throttle_high; level += 100) {
      throttle.writeMicroseconds(level);
            
      delay(1000);                   //[注意]この値を900,800などにすると回らなくなるので注意!!
  }

    

}