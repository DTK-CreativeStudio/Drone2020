#include <SPI.h>                  // ライブラリのインクルード
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(3, 4);//0,1ピンを使うとシリアルと干渉を起こす                // CE,CSNピンの指
 const byte address[6] = "10000";  // データを受信するアドレス
 
 int LED_PIN = 5;
 
 int SW_state = 0;
 /////////////////////////以下超音波センサの関数/////////////////////////////////////////////
 float USread(int Trig, int Echo) {
  int Duration;
  float Distance;
  const unsigned int MAX_DIST = 23200; //400cm(23200μs/pulse)以上は測定範囲外
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);//上のloopが10msでリアルタイムに送れるように時間調整したらこうなった
  digitalWrite(Trig, LOW);
  Duration = pulseIn(Echo, HIGH);
  if (Duration > 0) {
  Distance = Duration / 58.8;
  }
  if (Duration > MAX_DIST) {
    return 400;
  } else {
    return Distance;
  }
}
//////////////////////////////以下gyroセンサの設定//////////////////////////////////////

#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h"
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    #include "Wire.h"
#endif
MPU6050 mpu;
#define OUTPUT_READABLE_YAWPITCHROLL
#define INTERRUPT_PIN 2  // use pin 2 on Arduino Uno & most boards
bool blinkState = false;

// MPU control/status vars
bool dmpReady = false;  // set true if DMP init was successful
uint8_t mpuIntStatus;   // holds actual interrupt status byte from MPU
uint8_t devStatus;      // return status after each device operation (0 = success, !0 = error)
uint16_t packetSize;    // expected DMP packet size (default is 42 bytes)
uint16_t fifoCount;     // count of all bytes currently in FIFO
uint8_t fifoBuffer[64]; // FIFO storage buffer

// orientation/motion vars
Quaternion q;           // [w, x, y, z]         quaternion container
VectorInt16 aa;         // [x, y, z]            accel sensor measurements
VectorInt16 aaReal;     // [x, y, z]            gravity-free accel sensor measurements
VectorInt16 aaWorld;    // [x, y, z]            world-frame accel sensor measurements
VectorFloat gravity;    // [x, y, z]            gravity vector
float euler[3];         // [psi, theta, phi]    Euler angle container
float ypr[3];           // [yaw, pitch, roll]   yaw/pitch/roll container and gravity vector

// packet structure for InvenSense teapot demo
uint8_t teapotPacket[14] = { '$', 0x02, 0,0, 0,0, 0,0, 0,0, 0x00, 0x00, '\r', '\n' };

volatile bool mpuInterrupt = false;     // indicates whether MPU interrupt pin has gone high
void dmpDataReady() {
    mpuInterrupt = true;
}

int gyro_init(){
   // join I2C bus (I2Cdev library doesn't do this automatically)
    #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
        Wire.begin();
        Wire.setClock(400000); // 400kHz I2C clock. Comment this line if having compilation difficulties
    #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
        Fastwire::setup(400, true);
    #endif

    // initialize serial communication
    // (115200 chosen because it is required for Teapot Demo output, but it's
    // really up to you depending on your project)
    while (!Serial); // wait for Leonardo enumeration, others continue immediately

    // NOTE: 8MHz or slower host processors, like the Teensy @ 3.3V or Arduino
    // Pro Mini running at 3.3V, cannot handle this baud rate reliably due to
    // the baud timing being too misaligned with processor ticks. You must use
    // 38400 or slower in these cases, or use some kind of external separate
    // crystal solution for the UART timer.

    // initialize device
    Serial.println(F("Initializing I2C devices..."));
    mpu.initialize();
    pinMode(INTERRUPT_PIN, INPUT);

    // verify connection
    Serial.println(F("Testing device connections..."));
    Serial.println(mpu.testConnection() ? F("MPU6050 connection successful") : F("MPU6050 connection failed"));

    // wait for ready
    Serial.println(F("\nSend any character to begin DMP programming and demo: "));
    while(Serial.available() && Serial.read())// empty buffer
    while(!Serial.available())                // wait for data
    while(Serial.available() && Serial.read())// empty buffer again

          // load and configure the DMP
          Serial.println(F("Initializing DMP..."));
          devStatus = mpu.dmpInitialize();
      
          // supply your own gyro offsets here, scaled for min sensitivity
          mpu.setXGyroOffset(220);
          mpu.setYGyroOffset(76);
          mpu.setZGyroOffset(-85);
          mpu.setZAccelOffset(1788); // 1688 factory default for my test chip
      
          // make sure it worked (returns 0 if so)

    
    if (devStatus == 0) {
        // Calibration Time: generate offsets and calibrate our MPU6050
        mpu.CalibrateAccel(6);
        mpu.CalibrateGyro(6);
        mpu.PrintActiveOffsets();
        // turn on the DMP, now that it's ready
        Serial.println(F("Enabling DMP..."));
        mpu.setDMPEnabled(true);

        // enable Arduino interrupt detection
        Serial.print(F("Enabling interrupt detection (Arduino external interrupt "));
        Serial.print(digitalPinToInterrupt(INTERRUPT_PIN));
        Serial.println(F(")..."));
        attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN), dmpDataReady, RISING);
        mpuIntStatus = mpu.getIntStatus();

        // set our DMP Ready flag so the main loop() function knows it's okay to use it
        Serial.println(F("DMP ready! Waiting for first interrupt..."));
        dmpReady = true;

        // get expected DMP packet size for later comparison
        packetSize = mpu.dmpGetFIFOPacketSize();
    } else {
        // ERROR!
        // 1 = initial memory load failed
        // 2 = DMP configuration updates failed
        // (if it's going to break, usually the code will be 1)
        Serial.print(F("DMP Initialization failed (code "));
        Serial.print(devStatus);
        Serial.println(F(")"));
    }

    // configure LED for output

}
int gyroread(){
      // if programming failed, don't try to do anything
    if (!dmpReady) return;
    // read a packet from FIFO
    if (mpu.dmpGetCurrentFIFOPacket(fifoBuffer)) { // Get the Latest packet 
        #ifdef OUTPUT_READABLE_YAWPITCHROLL
            // display Euler angles in degrees
            mpu.dmpGetQuaternion(&q, fifoBuffer);
            mpu.dmpGetGravity(&gravity, &q);
            mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);
            //Serial.print("pitch\t");
            int pitch = ypr[1] * 180/M_PI;
            return pitch;
            //Serial.print(pitch);            
        #endif
    }
  }

 void setup() {
  pinMode(LED_PIN, OUTPUT);
   Serial.begin(9600);
   ///////////////// 無線の設定////////////
   radio.begin();
   radio.openReadingPipe(0, address);  // データ受信アドレスを指定
   radio.setPALevel(RF24_PA_MIN);      // 出力を最小に
   radio.startListening();             // 

  
   
}
 
 int val = 0;
 int state = 1;
 void loop(){
   
   //Serial.println( USread(8, 7));//超音波センサの結果をシリアルに出力  

   if (radio.available()){
     radio.read(&SW_state, sizeof(SW_state));  // スイッチの状態を受信する
     digitalWrite(LED_PIN,SW_state);
   }


     
    if(state == 1){
    gyro_init();
    }
     Serial.print(gyroread());
     Serial.print("\t");
     Serial.println(USread(8,7)); 
     delay(65);
     state = 0;

   
}
