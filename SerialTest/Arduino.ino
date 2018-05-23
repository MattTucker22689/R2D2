void setup() 
{
  Serial.begin(9600);
}
void ComsCheck()
{
  String temp = "";
  while(temp!="Connection Good")
  {
    Serial.println("Connection Check");
    temp = (Serial.readString());
    Serial.println("temp: " + temp);
    delay(1000);
  }
  Serial.println("temp: " + temp);
  Serial.println("Connection Good. Coming online");
}

void loop() 
{
  ComsCheck();
}
