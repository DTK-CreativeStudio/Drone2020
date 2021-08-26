void setup() {
  // put your setup code here, to run once:
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(6,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 100; i < 255; i += 10){
      analogWrite(11,i);
      analogWrite(10,i);
      analogWrite(9,i);
      analogWrite(6,i);
      delay(300);
    }
    for(int i = 255; i > 100; i -= 10){
      analogWrite(11,i);
      analogWrite(10,i);
      analogWrite(9,i);
      analogWrite(6,i);
      delay(300);
    }

}
