void setup() 
{
  pinMode( 4,OUTPUT); //Direita
  pinMode(16,OUTPUT); //Direita
  pinMode(17,OUTPUT); //Esquerda
  pinMode(18,OUTPUT); //Esquerda
}

void loop() 
{
  // Para seguir em frente
  digitalWrite( 4, LOW);
  digitalWrite(16, HIGH);

  digitalWrite(17, HIGH);
  digitalWrite(18, LOW);
  
  delay(1000);

  // Para recuar
  digitalWrite( 4, HIGH);
  digitalWrite(16, LOW);

  digitalWrite(17, LOW);
  digitalWrite(18, HIGH);
  
  delay(1000);

  // Rodar para a direita
  digitalWrite( 4, HIGH);
  digitalWrite(16, LOW);

  digitalWrite(17, HIGH);
  digitalWrite(18, LOW);
  
  delay(1000);

  // Rodar para a esquerda
  digitalWrite( 4, LOW);
  digitalWrite(16, HIGH);

  digitalWrite(17, LOW);
  digitalWrite(18, HIGH);
  
  delay(1000);

  //Parar os motores
  digitalWrite( 4, LOW);
  digitalWrite(16, LOW);

  digitalWrite(17, LOW);
  digitalWrite(18, LOW);
  
  delay(1000);
}
