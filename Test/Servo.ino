/*
   Author:
           Matt Tucker
   Date:
          22MAY2018
   Description:
          The following test is to for the servo motor. 
          It will turn the servo to several points and
          then return it to the 90deg post.
   Note:
          write() "measurement" to degrees->
              2000 = 180*
              1500 = 90*
              1000 = 0*
*/

//***Servo***
//#include <Servo.h>
//Servo servo1;
//const int servoPin = 9;
#include <ServoTimer2.h>
#define servoPin  9
ServoTimer2 servo1;
//********END*****//

//***GeneralGlobalVariables***
#include <math.h>
int rndNum;
int count = 0;
//********END*****//

void setup()
{

  //***Servo***
  servo1.attach(servoPin);
  //********END*****//
}

//***Servo***
//Turn() moves the servo to the 180 post to to 90, then to 0, 
//and back to 90
void Servo_Motor_Turn()
{
  servo1.write(2000);
  delay(1000);
  servo1.write(1500);
  delay(1000);
  servo1.write(1000);
  delay(1000);
  servo1.write(1500);
  delay(1000);
}

//UnTurn() centers the servo
void Servo_Motor_UnTurn()
{
  servo1.write(1500);
}
//********END*****//

void loop()
{
  Servo_Motor_UnTurn();
  Servo_Motor_Turn();
}
