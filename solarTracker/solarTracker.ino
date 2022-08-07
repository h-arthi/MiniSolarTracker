#include<Servo.h>

//intialize the ldr pins
int TR = A0;//top 
int BL = A2;//bottom 

//initialize the servo
Servo myservo;
int servoPin = 11;//the analog servo pin
int initialStage = 90;//initial value for the servo
int error = 10;//can change the error depending on your servo




void setup() {
  myservo.attach(servoPin);//setting the servo to this pin number
  pinMode(TR, INPUT);
  pinMode(BL, INPUT);
  myservo.write(initialStage);//setting the servo to move 90 degree
  Serial.begin(9600);
  delay (1000);
}

void loop() {

  //initializing variables to hold the vals of the ldr
  int top1 = analogRead(TR);
  int top2 = analogRead(BL);
  
  Serial.println(top1);
  Serial.println(top2);
  //getting the absolute difference between the top and bottom values
  int diff1 = abs(top1-top2);
 
  if (diff1 <= error)
  {
    initialStage = initialStage;
  }
  else if (top1 > top2)
  {
    initialStage = ++initialStage;
  }
  else if (top2 > top1)
  {
    initialStage = --initialStage;
  }
  
  myservo.write(initialStage);
  delay(100);
}
