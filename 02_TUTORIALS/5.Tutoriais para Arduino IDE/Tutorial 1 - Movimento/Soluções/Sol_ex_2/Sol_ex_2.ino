#include <robotOnLine.h>

robotOnLine robot;

#define hopTime 10

void setup() 
{
  robot.begin();
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() 
{
  // Velocidade 
  // Pode variar de 1 a 255

  //acelerar
  for(int i=0; i<255; i = i+5)
  {
    robot.rotateLeft(i);
    delay(hopTime);
  }
  delay(10);
  //desacelerar
  for(int i=255; i>0; i = i-5)
  {
    robot.rotateLeft(i);
    delay(hopTime);
  }
  delay(10);

  //acelerar
  for(int i=0; i<255; i = i+5)
  {
    robot.rotateRight(i);
    delay(hopTime);
  }
  delay(10);
  //desacelerar
  for(int i=255; i>0; i = i-5)
  {
    robot.rotateRight(i);
    delay(hopTime);
  }
  delay(10);
}
