/*ブラシレスモーターの制御ピンを,arduinoの9ピンに接続し、ブラシレスモーターを単一制御させた時のプログラム。
*/


#include <Servo.h>

const int throttle_high = 2000;   //最高の回転数を決める(値は回転数ではない)
const int throttle_low = 1000;    //最低の回転数を決める(値は回転数ではない)

Servo throttle;　　　　　　　　　　
Servo throttle2;                  //モーターを2つ制御するためにサーボを2つ制御できるようにする

int level = throttle_low;
int val, val2;
void setup(){

  throttle.attach(9);　　　　　　　　//モーターの制御ピンをそれぞれ9,10にさすようにする。
  throttle2.attach(10);

  throttle.writeMicroseconds(level); //先にサーボモーターの初期位置を決めておく
  throttle2.writeMicroseconds(level);
  delay(1000);                        //[注意]この値を900,800などにすると回らなくなるので注意!!
}

void loop() {
      
      for (level = throttle_low; level <= throttle_high; level += 100) { //最初にある程度回転させないと制御できない
    throttle.writeMicroseconds(level);
    throttle2.writeMicroseconds(level);
    delay(1000);
  }

      for (level = throttle_low; level <= throttle_high; level += 100) {
      val = analogRead(A0);//valという変数のA0のアナログ値を格納(可変抵抗の示す値)
      val2 = analogRead(A1);//valという変数のA1のアナログ値を格納(可変抵抗の示す値)
      val = map(val,0,1024,1000,2000);//valの値が(可変抵抗を5Vに接続させたときに)0から1024まで動くので、それをブラシレスに適する1000から2000までに変換する。
      val2 = map(val2,0,1024,1000,2000);
      throttle.writeMicroseconds(val);
      throttle2.writeMicroseconds(val2);     
      delay(1000);                   //[注意]この値を900,800などにすると回らなくなるので注意!!
  }

    

}