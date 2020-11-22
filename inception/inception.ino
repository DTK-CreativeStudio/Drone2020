#include <ESC.h>
#include <Servo.h>

//===================================================================================================================
//http://pe.org.pl/articles/2018/11/24.pdf


ESC myESC (9, 1000, 2000, 500);
//(ESC PIN, minimum value, maximam value, arm value)

Servo myservo;

int pos=0;

void setup() {
  myservo.attach(9);
  myESC.arm();
}
  
  aa
void loop() {
  for(pos=0;pos<180;pos+=1){
    //myservo.write(pos);
    myESC.speed(pos);
    delay(15);
  }
  for(pos=180;pos>=-1;pos-=1){
    //myservo.write(pos);
    myESC.speed(pos);
    delay(15);
  }  
}


//===================================================================================================================
//http://akiracing.com/2017/12/18/arduino_drone_motordrive/

/*
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
  delay(2000);
  for (level = 2000; level >= 1100; level -= 1) {//PWM幅を2000から1100まで徐々に下げる
    throttle.writeMicroseconds(level);
    delay(5);
  }
  delay(3000);
}
*/

//===================================================================================================================
//https://gist.github.com/rwaldron/9084516

/*
//Create the 4 esc objects
Servo esc1;

//Esc pins
int escPin1 = 9;

//Min and max pulse
int minPulseRate        = 1000;
int maxPulseRate        = 2000;
int throttleChangeDelay = 50;

//SETUP
void setup() {
  Serial.begin(9600);
  Serial.setTimeout(500);
  //Init escs
  initEscs();
}

//LOOP
void loop() {

  // Wait for some input
  if (Serial.available() > 0) {

    // Read the new throttle value
    int throttle = normalizeThrottle(Serial.parseInt());

    // Print it out
    Serial.print("Setting throttle to: ");
    Serial.println(throttle);

    // Change throttle to the new value
    changeThrottle(throttle);
  }
}

//Change throttle value
void changeThrottle(int throttle) {
  int currentThrottle = readThrottle();
  int step = 1;
  if(throttle < currentThrottle) {
      step = -1;
  }

// Slowly move to the new throttle value 
  while(currentThrottle != throttle) {
    writeTo4Escs(currentThrottle + step);
    currentThrottle = readThrottle();
    delay(throttleChangeDelay);
  }
}

//Read the throttle value
int readThrottle() {
  int throttle = esc1.read();
  Serial.print("Current throttle is: ");
  Serial.print(throttle);
  Serial.println();
  return throttle;
}

//Change velocity of the 4 escs at the same time
void writeTo4Escs(int throttle) {
  esc1.write(throttle);
}

//Init escs
void initEscs() {

  esc1.attach(escPin1, minPulseRate, maxPulseRate);
  //Init motors with 0 value
  writeTo4Escs(0);
}

//Start the motors
void startUpMotors() {
  writeTo4Escs(50);
}

// Ensure the throttle value is between 0 - 180
int normalizeThrottle(int value) {
  if(value < 0) {
    return 0;
    } else if(value > 180) {
    return 180;
    }
    return value;
}
*/

//===================================================================================================================
//https://www.instructables.com/Interfacing-Brushless-DC-Motor-BLDC-With-Arduino/

/*
Servo esc_signal;

void setup()
{
  esc_signal.attach(9);  //Specify here the pin number on which the signal pin of ESC is connected.
  esc_signal.write(30);   //ESC arm command. ESCs won't start unless input speed is less during initialization.
  delay(3000);            //ESC initialization delay.
}

void loop()
{
  esc_signal.write(55);	  //Vary this between 40-130 to change the speed of motor. Higher value, higher speed.
  delay(15);
}
*/

//===================================================================================================================
//https://www.instructables.com/How-to-run-an-ESC-with-Arduino/
/*
Servo ESC1;

int pos = 0; //Sets position variable

void arm(){
  setSpeed(0); //Sets speed variable
  delay(1000);
}

void setSpeed(int speed){
  int angle = map(speed, 0, 100, 0, 180); //Sets servo positions to different speeds ESC1.write(angle);
}

void setup() {
  ESC1.attach(9); //Adds ESC to certain pin. arm();
}

void loop() {

  int speed; //Implements speed variable

  for(speed = 0; speed <= 70; speed += 5) { //Cycles speed up to 70% power for 1 second
    setSpeed(speed); //Creates variable for speed to be used in in for loop
    delay(1000);
  }

  delay(4000); //Stays on for 4 seconds

  for(speed = 70; speed > 0; speed -= 5) { // Cycles speed down to 0% power for 1 second

    setSpeed(speed); delay(1000);

  }

  setSpeed(0); //Sets speed variable to zero no matter what
  delay(1000); //Turns off for 1 second

}
*/

