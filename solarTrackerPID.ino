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
int avg;//average largest sun
int servoVal;
int error;
int derivative;
//PID Variables
int lastError = 0; //setting the last error to 0
int Kd = 5;//setting a derivative constant
int Kp = 20;//setting a proportional contstant


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
  int avgR = (top1 + top2)/2;
  int avgL = (top3 + top4)/2;
  
  Serial.println(avgR);
  Serial.println(avgL);
  
  
  //if-else statements to change th e servo position
  if (avgR > avgL)
  {
  	avg = avgR;
    //proportional term
  	error = 997 - avg;
  	//derivative term
  	derivative = error - lastError;
    //setting the servo to move accordingly
  	servoVal = initialStage - (error * Kp + derivative * Kd); 
    myservo.write(servoVal);  
  }
  
  else if (avgL > avgR)
  {
  	avg = avgL;
    //proportional term
  	error = 997 - avg;
  	//derivative term
  	derivative = error - lastError;
    //setting the servo to move accordingly
  	servoVal = initialStage + (error * Kp + derivative * Kd); 
    myservo.write(servoVal); 
  }
  
  
  lastError = error;
  
  

  /*//using relational operators to compare the values
   if (avgR > avgL)
   {
    myservo.write(initialStage-20);
    delay(100);
   }
   else if(avgL > avgR)
   {
    myservo.write(initialStage+20);
    delay(100);
   }*/



   delay (50);

}
