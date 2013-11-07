#include <Arduino.h>

void setup()
{
  pinMode(13, OUTPUT);
}

int t;

void loop()
{
  //t = (double) millis() / 10 + 1;
  t = 500.;

  digitalWrite(13, HIGH);
  delay(t);

  digitalWrite(13, LOW);
  delay(t);
}

