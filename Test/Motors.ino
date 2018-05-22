/*
  Author:

  Matt Tucker

  Description:

  Motor test code- Here we want to predict and write AS MUCH, of the code that will
  be directly responsible for controlling the motors, as possible. That way, when it comes
  time to puting the cde all together, there won't be AS MUCH to do.

  Note:

  If your motors aren't moving in the correct directions you can always flip the wires or
  change the code to reflect this.

*/
//***Motors***
#include <AFMotor.h>
AF_DCMotor motor1(2);
AF_DCMotor motor2(3);
//********END*****//

void setup()
{

  Serial.begin(9600);
  //***Motors***
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  //********END*****//

}
//***Motors***
void Forward()
{
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  delay(500);
}
void VearLeft()
{
  motor1.setSpeed(200);
  motor2.setSpeed(100);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  delay(1000);
}
void VearRight()
{
  motor1.setSpeed(100);
  motor2.setSpeed(200);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  delay(1000);
}
void TurnLeft()
{
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  delay(1000);
}
void TurnRight()
{
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  delay(1000);
}
void Backward()
{
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  delay(1000);
}
void RevLeft()
{
  motor1.setSpeed(100);
  motor2.setSpeed(200);
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  delay(1000);
}
void RevRight()
{
  motor1.setSpeed(200);
  motor2.setSpeed(100);
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  delay(1000);
}
void Stop()
{
  motor1.run(BRAKE);
  motor2.run(BRAKE);
}
//********END*****/
void loop()
{
  Forward();
}
