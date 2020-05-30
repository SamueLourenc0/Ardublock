#include <robotOnLine.h>

robotOnLine robot;

bool cruzamento = 0;

void setup()
{
  robot.begin();
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(115200);
}

void loop()
{
  while ( (robot.readCLP() != HIGH)  && (robot.distance() > 10) )
  {
    if( (robot.readS2() == 0) || (robot.readS3() == 0) || (robot.readS4() == 0) )
    {
      if( (robot.readS2() == 1) && (robot.readS3() == 0) && (robot.readS4() == 1) )
      {
        robot.forward(255);
        while((robot.readS2() == 1) && (robot.readS3() == 0) && (robot.readS4() == 1))
        {
          ;
        }
      }
      else if( (robot.readS2() == 0) && (robot.readS3() == 1) && (robot.readS4() == 1) )
      {
        robot.rotateLeft(255);
        while((robot.readS2() == 0) && (robot.readS3() == 1) && (robot.readS4() == 1))
        {
          ;
        }
      }
      else if( (robot.readS2() == 1) && (robot.readS3() == 1) && (robot.readS4() == 0) )
      {
        robot.rotateRight(255);
        while((robot.readS2() == 1) && (robot.readS3() == 1) && (robot.readS4() == 0))
        {
          ;
        }
      }
      else if( (robot.readS3() == 0) && (robot.readS4() == 0) && (robot.readS5() == 0) )
      { //sensores do meio e da direita detetaram uma linha
        cruzamento = 1;
      }
      else if( (robot.readS1() == 0) && (robot.readS2() == 0) && (robot.readS3() == 0))
      { //sensores da esquerda e do meio detetaram uma linha
        cruzamento = 1;
      }
      else if( (robot.readS1() == 0) && (robot.readS2() == 0) && (robot.readS4() == 0) 
      && (robot.readS5() == 0) )
      { //sensores da esquerda e da direita detetaram uma linha
        cruzamento = 1;
      }

      if(cruzamento == 1)
      {

        // Inserir código a efetuar num cruzamento, aqui.
        robot.rotateRight(200);
        while(robot.readS3()==0);
        while(robot.readS3()==1);
        robot.stopMotors();
        
        cruzamento = 0;
      }
    }
    
    digitalWrite(LED_BUILTIN, HIGH);
    
    if( (robot.readS2() == 1) && (robot.readS3() == 1) && (robot.readS4() == 1) )
    {
      robot.stopMotors();
      while((robot.readS2() == 1) && (robot.readS3() == 1) && (robot.readS4() == 1));
    }
  }
  robot.stopMotors();

  digitalWrite(LED_BUILTIN, LOW);

  while (robot.readCLP());
}
