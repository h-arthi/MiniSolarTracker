#include<Servo.h>

//intialize the ldr pins
int TR = A0;//top right ldr
int BR = A3;//bottom right ldr
int TL = A1;//top left ldr
int BL = A2;//bottom left
//initialize the servo
Servo myservo;
int servoPin = 11;//the analog servo pin
int initialStage = 70;//initial value for the servo 
void setup() {
  myservo.attach(servoPin);//setting the servo to this pin number
  pinMode(TR, INPUT);
  pinMode(BR, INPUT);
  pinMode(TL, INPUT);
  pinMode(BL, INPUT);
  myservo.write(initialStage);//setting the servo to move 90 degree
  delay (1000);
}

void loop() {

  //initializing variables to hold the vals of the ldr
  int top1 = analogRead(TR);
  int top2 = analogRead(BR);
  int top3 = analogRead(TL);
  int top4 = analogRead(BL);
  int avgR = (top1 + top3);
  int avgL = (top2 + top4);

  //using relational operators to compare the values
   if (avgR > avgL)
   {
    myservo.write(initialStage-20);
    delay(100);
   }
   else if(avgL > avgR)
   {
    myservo.write(initialStage+20);
    delay(100);
   }



   delay (50);

}
