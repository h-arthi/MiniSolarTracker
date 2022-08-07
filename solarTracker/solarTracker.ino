#include<Servo.h>

//intialize the ldr pins
int TR = A0;//top right ldr
int BR = A3;//bottom right ldr
int TL = A1;//top left ldr
int BL = A2;//bottom left

//initialize the servo
Servo myservo;
int servoPin = 11;//the analog servo pin
int initialStage = 90;//initial value for the servo
int error = 10;//can change the error depending on your servo




void setup() {
  myservo.attach(servoPin);//setting the servo to this pin number
  pinMode(TR, INPUT);
  pinMode(BR, INPUT);
  pinMode(TL, INPUT);
  pinMode(BL, INPUT);
  myservo.write(initialStage);//setting the servo to move 90 degree
  Serial.begin(9600);
  delay (1000);
}

void loop() {

  //initializing variables to hold the vals of the ldr
  int top1 = analogRead(TR);
  int top2 = analogRead(BR);
  int top3 = analogRead(TL);
  int top4 = analogRead(BL);
  int avgR = (top1 + top3)/2;
  int avgL = (top2 + top4)/2;
  
  Serial.println(avgR);
  Serial.println(avgL);
  //getting the absolute difference between the top and bottom values
  int diff1 = abs(avgR-avgL);
  int diff2 = abs(avgL-avgR);
 
  if ((diff1 <= error)||(diff2 <= error))
  {
    initialStage = initialStage;
  }
  else if (avgR > avgL)
  {
    initialStage = ++initialStage;
  }
  else if (avgL > avgR)
  {
    initialStage = --initialStage;
  }
  
  myservo.write(initialStage);
  delay(100);
}
