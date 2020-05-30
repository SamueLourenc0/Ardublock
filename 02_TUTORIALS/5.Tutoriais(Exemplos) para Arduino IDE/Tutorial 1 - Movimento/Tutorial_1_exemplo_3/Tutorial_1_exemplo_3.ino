#include <robotOnLine.h>

robotOnLine robot;

void setup() 
{
  robot.begin();
}

void loop() 
{
  // Mover roda esquerda em frente
  robot.leftWheel(255);

  delay(1000);

  // Mover roda esquerda para trás
  robot.leftWheel(-255);

  delay(1000);

  // Mover roda direita em frente
  robot.rightWheel(255);

  delay(1000);

  // Mover roda direita para trás
  robot.rightWheel(-255);

  delay(1000);
}
