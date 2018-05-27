/*
   Author:
           Matt Tucker
   Date:
          26MAY2018
   Description:
          The combination of several individual test projects. The following code will test:
          4 LEDs, 2 motors, and 1 servo
          The code is to be executed on a Mega 2560 with a motor shield and sensor shield.
   Notes:
          Current iteration includes a Raspberry Pi running a Python script that communicates
          with the Mega 2560. The Python script will act as a mediator between a web control
          interface and the Mega 2560.
*/

//***UltraSonic***
const int pingPin = A4;
//********END*****//

//***LEDs***
const int ledPin1 = 34;
const int ledPin2 = 36;
const int ledPin3 = 38;
const int ledPin4 = 40;
//********END*****//

//***Motors***
#include <AFMotor.h>
AF_DCMotor motor1(2);
AF_DCMotor motor2(3);
//********END*****//

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
int check = 0;
//********END*****//

void setup()
{
  Serial.begin(9600);
  randomSeed(analogRead(0));

  //***Servo***
  servo1.attach(servoPin);
  //********END*****//

  //***Motors***
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  //********END*****//

  //***LEDs***
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  //********END*****//

  //***StartUP***
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, HIGH);
  digitalWrite(ledPin4, HIGH);
  delay(100);
  //********END*****//
}

void ComsCheck()
{
  String temp = "";
  while(temp!="Connection Good")
  {
    Serial.println("Connection Check");
    temp = Serial.readString();
    Serial.println("temp: " + temp);
    delay(1000);
  }
  Serial.println("temp: " + temp);
  Serial.println("Connection Good. Coming online");
  check = 1;
}

//***Motors***
void Forward()
{
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
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

void TurnLeft()
{
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  delay(1000);
}

void TurnLeft(long inches)
{
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  while (inches <= 12)
  {
    motor1.run(FORWARD);
    motor2.run(BACKWARD);
    delay(500);
    inches = Sensor_loop();
  }
}

void TurnRight()
{
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  delay(1000);
}

void TurnRight(long inches)
{
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  while (inches <= 12)
  {
    motor1.run(BACKWARD);
    motor2.run(FORWARD);
    delay(500);
    inches = Sensor_loop();
  }
}
void Backward(long inches)
{
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  while (inches <= 6)
  {
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    delay(500);
    inches = Sensor_loop();
  }
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

void Coast()
{
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}

void Stop()
{
  motor1.run(BRAKE);
  motor2.run(BRAKE);
}
//********END*****//

//***Servo***
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

void Servo_Motor_UnTurn()
{
  servo1.write(1500);
}
//********END*****//

//***UltraSonic***
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

//***LEDs***
void Blink1(int num)
{
  num = (num % 20) * 100;
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  delay(num);
  digitalWrite(ledPin3, LOW);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin4, LOW);
  delay(num);
  digitalWrite(ledPin3, HIGH);
  delay(num);
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin4, HIGH);
}

void Blink2(int num)
{
  num = (num % 20) * 100;
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin4, LOW);
  delay(num);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, LOW);
  digitalWrite(ledPin4, HIGH);
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin1, LOW);
  delay(num);
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin3, HIGH);
}

void Blink3(int num)
{
  num = (num % 20) * 100;
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin4, LOW);
  delay(num);
  digitalWrite(ledPin3, LOW);
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin4, HIGH);
  delay(num);
  digitalWrite(ledPin3, HIGH);
  digitalWrite(ledPin2, HIGH);
}
//********END*****//

void loop()
{
  check = 1;
  if(check = 1)
    {
      String command = "";
      command = Serial.readString();
      if(command == "Forward")
      {
        Forward();
        command = Serial.readString();
      }
      else if(command == "Backward")
      {
        Backward();
        command = Serial.readString();
      }
      else if(command == "Left")
      {
        TurnLeft();
        command = Serial.readString();
      }
      else if(command == "Right")
      {
        TurnRight();
        command = Serial.readString();
      }
      else
      {
        Stop();
        command = Serial.readString();
      }
    }
}
