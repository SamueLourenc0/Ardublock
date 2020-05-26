#include <robotOnLine.h>

robotOnLine robot;

#define diametro 65

short leftPulse = 0;
short rightPulse = 0;

void setup() 
{
  robot.begin();
}

void loop() 
{
  robot.clearEncoderCount();
  delay(1000);

  robot.forward(200);
  while(1)
  {
    leftPulse = robot.getLeftEncoderCount();
    rightPulse = robot.getRightEncoderCount();

    // pulsos por cada volta = 40
    // diametro da roda = 65mm
    // perimetro da roda = 65mm * pi

    // Saber o perimetro da roda, ou seja, distancia que a roda faz numa volta completa
    short perimetro = diametro * PI;
    
    // Calcular a quantos pulsos equivale 10 cm (100 mm)
    short pulsos = (100*40)/perimetro; // se 40pulsos <-> perimetro (mm), xPulsos <-> 100mm

    if( ((leftPulse+rightPulse)/2) > pulsos)
    {
      robot.stopMotors();
      break;
    }    
  }
}
