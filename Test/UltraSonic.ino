/*
  Author:
          Matt Tucker
  Description:
          This is a test of the ultrasonic sensor. It will return the distance between the sensor
          and an object in serial.
*/

//***UltraSonic***//
const int pingPin = A4;
//********END*****

void setup()
{
  Serial.begin(9600);
}

//***UltraSonic***
//This will be returning a value in the form of a long, so instead of "void" we need to use "long"
long Sensor_loop()
{
  long microseconds, inches;

  //Sensor sends out a pulse and listens for a response
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW); pinMode(pingPin, INPUT);
  microseconds = pulseIn(pingPin, HIGH);

  //Converts time(microseconds) to distance(inches)---(t*k=d), k=[inches/time]
  //You may find this value to be inaccurate. If it is, you can use a ruler and
  //a book to find out what the value is off by inoder to calculate what you need.
  // k_new=k_old*(d_actual/d_sensor)
  inches = long(microseconds / 148);

  //Print distance values
  Serial.println(inches);
  return inches;

  //Waits 1 second
  delay(1000);
}

void loop()
{
  Sensor_loop();
}
