/*
   Author:
           Matt Tucker
   Description:
           Makes 4 LEDs blink in different patterns. You 
           can use a random number generator to randomize the
           process.
*/

//***LEDs***
const int ledPin1 = 34;
const int ledPin2 = 36;
const int ledPin3 = 38;
const int ledPin4 = 40;
//********END*****//

void setup()
{
  Serial.begin(9600);

  //***LEDs***
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  //********END*****//
}

//***LEDs***
void Blink1()
{
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
  delay(1000);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin4, LOW);
  digitalWrite(ledPin3, HIGH);
  delay(1000);
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin4, HIGH);
}

void Blink2()
{
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin4, LOW);
  digitalWrite(ledPin2, HIGH);
  delay(1000);
  digitalWrite(ledPin3, LOW);
  digitalWrite(ledPin4, HIGH);
  digitalWrite(ledPin1, LOW);
  delay(1000);
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin1, HIGH);
  delay(1000);
  digitalWrite(ledPin3, HIGH);
}

void Blink3()
{
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin4, LOW);
  digitalWrite(ledPin3, LOW);
  delay(1000);
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin4, HIGH);
  delay(1000);
  digitalWrite(ledPin3, HIGH);
  digitalWrite(ledPin2, HIGH);
}
//********END*****//

void loop()
{
  Serial.println("Blink1");
  Blink1();
  Serial.println("Blink2");
  Blink2();
  Serial.println("Blink3");
  Blink3();
}
