
#include <robotOnLine.h>

robotOnLine robot;

short leftPulse = 0;
short rightPulse = 0;

void setup() 
{
  robot.begin();

  Serial.begin(115200);
}

void loop() 
{
  leftPulse = robot.getLeftEncoderCount();
  rightPulse = robot.getRightEncoderCount();

  Serial.print("Pulso da roda esquerda: ");
  Serial.print(leftPulse);
  Serial.print("\t");
  Serial.print("Pulso da roda direita: ");
  Serial.println(rightPulse);

  if( (leftPulse > 10000) || (rightPulse > 10000) )
  {
    robot.clearEncoderCount();
  }
  
  delay(250);
}
