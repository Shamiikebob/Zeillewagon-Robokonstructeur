#include <Servo.h>
//Servo Configuration
Servo servo1;
int servo_control;
int servo_pin=10;

//L298N Pin Configuration
int ena = 3;
int enb = 9;
int in1 = 4;
int in2 = 5;
int in3 = 6;
int in4 = 7;
int left_motor_speed = 80;
int right_motor_speed =80;

void setup() {
  // put your setup code here, to run once:
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  servo1.attach(10);
  close_hatch();
}

void loop() {
  // put your main code here, to run repeatedly:
//  close_hatch();
  linear();
  delay(2000);
  halt();
  open_hatch();
  delay(1000);
  close_hatch();
  delay(1000);
  rotation_360();
  delay(3000);
  halt();
  delay(1000);
  

}

void linear(){
  analogWrite(ena,right_motor_speed);
  analogWrite(enb,left_motor_speed);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH); //left motor
  digitalWrite(in4, LOW);
}

void halt(){
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW); //left motor
  digitalWrite(in4, LOW);
}

void rotation_360(){
   analogWrite(ena,right_motor_speed);
  analogWrite(enb,left_motor_speed);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW); //left motor
  digitalWrite(in4, HIGH);
}

void open_hatch(){
  for (int i=0; i<=60;i++){
    servo1.write(i);
    delay(15);
  }
  
}

void close_hatch(){
  for (int i=60; i>=0;i--){
    servo1.write(i);
    delay(15);
  }
  
}
