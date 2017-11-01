#include <Arduino.h>
#include <SoftwareSerial.h>

SoftwareSerial _gBTHC05(PD6, PD7);
String _gstrCommand = "";

void setup()
{
  Serial.begin(9600);
  Serial.println("Type AT command...");
  _gBTHC05.begin(9600);
}


void loop()
{
  if(0 < _gBTHC05.available())
  {
    for(;0 < _gBTHC05.available();)
    {
      char cChar = _gBTHC05.read();

      _gstrCommand += cChar;
    }

    Serial.print("Blue Send ");
    Serial.println(_gstrCommand);

    _gstrCommand = "";
  }

  if(0 < Serial.available())
  {
    char cChar = Serial.read();

    _gBTHC05.write(cChar);
  }
}
