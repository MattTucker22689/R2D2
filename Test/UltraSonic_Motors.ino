/*
  Author:

  Matt Tucker

  Description:

  This is a test of the motors and ultrasonic sensor. It will return the distance between the sensor
  and an object in serial, as well as control the motors. The bot will now respond at a basic level to
  its enviroment.

*/

//***UltraSonic***//
const int pingPin = A4;
//********END*****//

//***Motors***//
#include
AF_DCMotor motor1(2);
AF_DCMotor motor2(3);
//********END*****//

void setup()
{
  Serial.begin(9600);

  //***Motors***//
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  //********END*****//
}

//***Motors***//
void Forward()
{
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  delay(500);
}

void TurnLeft()

{
  motor2.run(BACKWARD);
  motor1.run(FORWARD);
  delay(1000);
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



//***UltraSonic***//
long Sensor_loop()
{
  long microseconds, inches;

  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
  pinMode(pingPin, INPUT);
  microseconds = pulseIn(pingPin, HIGH);

  //code to convert time to distance
  inches = long (microseconds / 74 / 2);
  //code to print distance values
  Serial.println(inches);
  return inches;

  delay(100);
}
//********END*****//

void loop()
{
  long inches = Sensor_loop();
  if (inches < 6)
  {
    Stop();
    Backward();
    TurnLeft();
  }
  else
  {
    Forward();
  }
}
