/*
 Author: Matt Tucker

 Description: As I plan on recycling this code as I continue building/upgrading my R2D2 I added extra code, variations of the "forward()" 
 method, that can be implemented at a later date.
 
 Date: 19Dec16
*/

int pinI1=8;//define I1 interface
int pinI2=11;//define I2 interface 
int speedpinA=9;//enable motor A
int pinI3=12;//define I3 interface 
int pinI4=13;//define I4 interface 
int speedpinB=10;//enable motor B
int spead =10000;//defines the speed of motor
void setup()
{
 pinMode(pinI1,OUTPUT);
 pinMode(pinI2,OUTPUT);
 pinMode(speedpinA,OUTPUT);
 pinMode(pinI3,OUTPUT);
 pinMode(pinI4,OUTPUT);
 pinMode(speedpinB,OUTPUT);
}
void forward()//
{
 analogWrite(speedpinA,spead);//input a simulation value to set the speed
 analogWrite(speedpinB,spead);
 digitalWrite(pinI4,HIGH);//turn DC Motor B move clockwise
 digitalWrite(pinI3,LOW);
 digitalWrite(pinI2,LOW);//turn DC Motor A move anticlockwise
 digitalWrite(pinI1,HIGH);
}
void backward()//
{
 analogWrite(speedpinA,spead);//input a simulation value to set the speed
 analogWrite(speedpinB,spead);
 digitalWrite(pinI4,LOW);//turn DC Motor B move anticlockwise
 digitalWrite(pinI3,HIGH);
 digitalWrite(pinI2,HIGH);//turn DC Motor A move clockwise
 digitalWrite(pinI1,LOW);
}
void left()//
{
 analogWrite(speedpinA,spead);//input a simulation value to set the speed
 analogWrite(speedpinB,spead);
 digitalWrite(pinI4,HIGH);//turn DC Motor B move clockwise
 digitalWrite(pinI3,LOW);
 digitalWrite(pinI2,HIGH);//turn DC Motor A move clockwise
 digitalWrite(pinI1,LOW);
}
void right()//
{
 analogWrite(speedpinA,spead);//input a simulation value to set the speed
 analogWrite(speedpinB,spead);
 digitalWrite(pinI4,LOW);//turn DC Motor B move anticlockwise
 digitalWrite(pinI3,HIGH);
 digitalWrite(pinI2,LOW);//turn DC Motor A move clockwise
 digitalWrite(pinI1,HIGH);
}
void stop()//
{
 digitalWrite(speedpinA,LOW);// Unenble the pin, to stop the motor. this should be done to avid damaging the motor. 
 digitalWrite(speedpinB,LOW);
 delay(1000);
}
void loop()
{
 forward();
}
