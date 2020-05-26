#include <robotOnLine.h>

robotOnLine robot;

void setup() 
{
  robot.begin();
}

void loop() 
{
  // Velocidade 
  // Pode variar de 1 a 255
  byte speed = 255;
  
  // Para seguir em frente
  robot.forward(speed);

  delay(500);

  // Para recuar
  robot.reverse(speed);

  delay(500);

  // Rodar para a direita
  robot.rotateRight(speed);

  delay(500);

  // Rodar para a esquerda
  robot.rotateLeft(speed);

  delay(500);

  // Parar os motores
  robot.stopMotors();
  
  delay(1000);
}
