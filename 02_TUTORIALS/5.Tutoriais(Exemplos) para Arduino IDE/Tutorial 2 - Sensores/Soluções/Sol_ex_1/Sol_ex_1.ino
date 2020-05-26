
#include <robotOnLine.h>

robotOnLine robot;

bool estado=0;  //0 parado, 1 em movimento

void setup() 
{
  robot.begin();
}

void loop() 
{
  byte dist = robot.distance();
  if(dist <= 10)
  {
    robot.stopMotors();
    estado=0;
  }
  else if(estado==0)
  {
    robot.forward(200);
    estado=1;
  }
  
}
