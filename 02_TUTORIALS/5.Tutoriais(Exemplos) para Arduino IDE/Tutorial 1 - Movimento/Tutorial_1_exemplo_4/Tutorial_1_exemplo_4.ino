#include <robotOnLine.h>

robotOnLine robot;

void setup() 
{
  robot.begin();
}

void loop() 
{
  // Rodar para a esquerda 90 graus
  robot.turnLeft(90);

  delay(1000);

  // Rodar para a direita 270 graus
  robot.rightWheel(270);

  delay(1000);
  
}
