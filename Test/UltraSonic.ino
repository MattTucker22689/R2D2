const int pingPin=7;//defines pin number of sensor's output. let it be noted that const means constant
 
void setup()
{

  Serial.begin(9600); //initializes serial communication
}

void loop()
{
  long duration, inches, cm;//establishes variables: duration and distance(inches and cm)
  
  //the next little bit is to initate Pulse(HIGH) for 2 or more us. Sends LOW pulse beforehand to ensure a clean HIGH pulse
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
  
  pinMode(pingPin, INPUT);
  duration=pulseIn(pingPin, HIGH);
 
 //code to convert time to distance
 inches=ToInches(duration);
 cm=ToCentimeters(duration);
 
 Serial.print(inches);
 Serial.print("in, ");
 Serial.print(cm);
 Serial.print("cm");
 Serial.println();

 delay(100);
}

long ToInches(long t)
{
  return t/74/2;
}
long ToCentimeters(long t)
{
  return t/29/2;
}
