#define CLP 39
#define Near 36
#define S1 25
#define S2 33
#define S3 32
#define S4 35
#define S5 34

bool cruzamento = 0;
byte count = 0;

void setup()
{
  pinMode( 4,OUTPUT); //Direita
  pinMode(16,OUTPUT); //Direita
  pinMode(17,OUTPUT); //Esquerda
  pinMode(18,OUTPUT); //Esquerda
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(115200);
}

void loop()
{
  while ( (digitalRead(CLP) != HIGH)  && (distancia() > 10) )
  {
    if( (digitalRead(S2) == 0) || (digitalRead(S3) == 0) || (digitalRead(S4) == 0) )
    {
      if( (digitalRead(S2) == 1) && (digitalRead(S3) == 0) && (digitalRead(S4) == 1) )
      {
        frente();
        while((digitalRead(S2) == 1) && (digitalRead(S3) == 0) && (digitalRead(S4) == 1))
        {
          ;
        }
      }
      else if( (digitalRead(S2) == 0) && (digitalRead(S3) == 1) && (digitalRead(S4) == 1) )
      {
        esquerda();
        while((digitalRead(S2) == 0) && (digitalRead(S3) == 1) && (digitalRead(S4) == 1))
        {
          ;
        }
      }
      else if( (digitalRead(S2) == 1) && (digitalRead(S3) == 1) && (digitalRead(S4) == 0) )
      {
        direita();
        while((digitalRead(S2) == 1) && (digitalRead(S3) == 1) && (digitalRead(S4) == 0))
        {
          ;
        }
      }
      else if( (digitalRead(S3) == 0) && (digitalRead(S4) == 0) && (digitalRead(S5) == 0) )
      { //sensores do meio e da direita detetaram uma linha
        cruzamento = 1;
        count++;
      }
      else if( (digitalRead(S1) == 0) && (digitalRead(S2) == 0) && (digitalRead(S3) == 0))
      { //sensores da esquerda e do meio detetaram uma linha
        cruzamento = 1;
        count++;
      }
      else if( (digitalRead(S1) == 0) && (digitalRead(S2) == 0) && (digitalRead(S4) == 0) 
      && (digitalRead(S5) == 0) )
      { //sensores da esquerda e da direita detetaram uma linha
        cruzamento = 1;
        count++;
      }

      if(cruzamento == 1)
      {
        switch(count)
        {
          case 1:
            direita();
            while(digitalRead(S3)==0);
            while(digitalRead(S3)==1);
            pararMotores();
            break;
            
          case 2:
            esquerda();
            while(digitalRead(S3)==0);
            while(digitalRead(S3)==1);
            pararMotores();
            break;
            
          case 3:
            esquerda();
            while(digitalRead(S3)==0);
            while(digitalRead(S3)==1);
            pararMotores();
            break;
            
          default:
            break;
        }
        
        cruzamento = 0;
      }
    }
    
    digitalWrite(LED_BUILTIN, HIGH);
    
    if( (digitalRead(S2) == 1) && (digitalRead(S3) == 1) && (digitalRead(S4) == 1) )
    {
      pararMotores();
      while((digitalRead(S2) == 1) && (digitalRead(S3) == 1) && (digitalRead(S4) == 1));
    }
  }
  pararMotores();

  digitalWrite(LED_BUILTIN, LOW);

  while (digitalRead(CLP));
}

byte distancia()
{
  digitalWrite(14, LOW);
  delayMicroseconds(2);

  digitalWrite(14, HIGH);
  delayMicroseconds(10);
  digitalWrite(14, LOW);

  uint32_t duration = pulseIn(12, HIGH);

  uint dist = int(duration * 0.034f / 2.f);
  if (dist > 255)
  {
    return 255;
  }
  else
  {
    return dist;
  }
}

void frente()
{
  digitalWrite( 4, LOW);
  digitalWrite(16, HIGH);

  digitalWrite(17, HIGH);
  digitalWrite(18, LOW);
}

void recuar()
{
  digitalWrite( 4, HIGH);
  digitalWrite(16, LOW);

  digitalWrite(17, LOW);
  digitalWrite(18, HIGH);
}

void direita()
{
  digitalWrite( 4, HIGH);
  digitalWrite(16, LOW);

  digitalWrite(17, HIGH);
  digitalWrite(18, LOW);
}

void esquerda()
{
  digitalWrite( 4, LOW);
  digitalWrite(16, HIGH);

  digitalWrite(17, LOW);
  digitalWrite(18, HIGH);
}

void pararMotores()
{
  digitalWrite( 4, LOW);
  digitalWrite(16, LOW);

  digitalWrite(17, LOW);
  digitalWrite(18, LOW);
}
