/* Author:
   Matt Tucker
   Description:
   This is to run thru a list of 61 songs(2-62)
   and play them as the user sends "a".
*/

#include <SD.h>
#define SDPIN 53
#include <TMRpcm.h>

TMRpcm tmrpcm;
//File names begin at 2 and end at 62
int i = 2;
char user;
String lab;

void setup()
{

  Serial.begin(9600);
  tmrpcm.speakerPin = 11;
  tmrpcm.setVolume(5);
  if (!SD.begin(SDPIN))
  {
    Serial.println("Initialization Failed!");
    return;
  }
  tmrpcm.play("60.wav");
  Serial.println("Send 'a' to play: ");
}

void loop()
{
  if (Serial.available())
  {
    user = Serial.read();
    if (user == 'a')
    {
      lab = String(i) + ".wav";
      Serial.println("playing: " + lab );
      tmrpcm.play(lab.c_str());
      if (i == 62)
        i = 1;
      i++;
    }
  }
}
