/* Description:
This program allows the use to select a sound from a list
of sounds labeled 2-62.

Author:
Matt Tucker

Date:
18Jun17
*/

#include <SD.h>
#define SDPIN 53
#include <TMRpcm.h>

TMRpcm tmrpcm;
String label;
int i;

void setup()
{
 Serial.begin(9600);
 tmrpcm.speakerPin = 46; //Can be: 5,6,11 or 46
 tmrpcm.setVolume(5);
 if (!SD.begin(SDPIN))
 {
  Serial.println("Initialization Failed!");
  return;
 }
 tmrpcm.play("60.wav");
 Serial.println("Select the name of a .wav file to play(2-63): ");
}

void loop()
{
 if (Serial.available())
 {
  i = Serial.parseInt();
  //File names begin at 2 and end at 63
  if (i < 2 || i > 63)
   Serial.println("Not a valid sound");
  else
  {
   label = String(i) + ".wav";
   Serial.println("playing: " + label);
   tmrpcm.play(label.c_str());
  }
 }
}
