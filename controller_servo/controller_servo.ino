#include <Servo.h>

Servo myservo; //ประกาศตัวแปรแทน Servo
void setup()
{
  Serial.begin(9600);
  myservo.attach(D1); // กำหนดขาควบคุม Servo
}
void loop()
{
  servoSwap();
  servoSwap();
  sleepSec(10);
  servoSlowMoveRigth();
  servoSlowMoveLeft();
  servoSwap();
  sleepSec(5);
}
void servoSlowMoveLeft(){
  for(int i=0 ; i <= 180 ; i = i+5){
    Serial.println(180-i);
    myservo.write(180-i);
    delay(10);
  }
  delay(100);
}

void servoSlowMoveRigth(){
  for(int i=0 ; i <= 180 ; i++){
    Serial.println(i);
    myservo.write(i);
    delay(10);
  }
  delay(100);
}

void servoSwap(){
  myservo.write(0);  
  delay(100);
  myservo.write(180);  
  delay(100);
  myservo.write(0);   
  delay(500);
}

void sleepSec(int i){
  delay(i*1000);
}
