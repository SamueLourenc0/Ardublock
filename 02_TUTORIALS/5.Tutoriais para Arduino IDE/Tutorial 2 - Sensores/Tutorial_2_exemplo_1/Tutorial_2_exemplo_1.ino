
#include <robotOnLine.h>

robotOnLine robot;

void setup() 
{
  robot.begin();

  Serial.begin(115200);
}

void loop() 
{
  byte dist = robot.distance();
  Serial.println(dist);

  delay(250);
}
