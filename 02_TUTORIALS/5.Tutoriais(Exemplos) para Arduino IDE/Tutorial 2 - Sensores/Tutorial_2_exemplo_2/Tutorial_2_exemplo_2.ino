
#include <robotOnLine.h>

robotOnLine robot;

void setup() 
{
  robot.begin();

  Serial.begin(115200);
}

void loop() 
{
  bool state = 0;

  state = robot.readCLP();
  Serial.print("Estado do pino CLP: ");
  Serial.println(state);

  state = robot.readNear();
  Serial.print("Estado do pino Near: ");
  Serial.println(state);

  state = robot.readS1();
  Serial.print("Estado do pino S1: ");
  Serial.println(state);

  state = robot.readS2();
  Serial.print("Estado do pino S2: ");
  Serial.println(state);

  state = robot.readS3();
  Serial.print("Estado do pino S3: ");
  Serial.println(state);

  state = robot.readS4();
  Serial.print("Estado do pino S4: ");
  Serial.println(state);

  state = robot.readS5();
  Serial.print("Estado do pino S5: ");
  Serial.println(state);

  delay(250);
}
