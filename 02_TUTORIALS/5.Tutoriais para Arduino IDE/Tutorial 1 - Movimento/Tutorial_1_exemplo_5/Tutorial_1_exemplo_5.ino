
#define PWM_Frequency 5000  // PWM frequency, up to 312.5kHz
#define _IN1_PWM_channel 0 // select the channel number
#define _IN2_PWM_channel 1 // there are 15 channels,  
#define _IN3_PWM_channel 2 // choose between 0 to 15
#define _IN4_PWM_channel 3 // (not related to the pins)
#define PWM_RESOUTION 8    // 8 bits

//motor pins IN1&IN2 right engine
byte _IN1 = 4; //IO15 and 5 are HIGH during boot.
byte _IN2 = 16;

//IN3&IN4 left engine
byte _IN3 = 17;
byte _IN4 = 18;

void setup() 
{
  pinMode(4,OUTPUT);
  pinMode(16,OUTPUT);
  pinMode(17,OUTPUT);
  pinMode(18,OUTPUT);
  
  //setup PWM for motor pins
  ledcSetup(_IN1_PWM_channel, PWM_Frequency, PWM_RESOUTION);
  ledcAttachPin(_IN1, _IN1_PWM_channel);

  ledcSetup(_IN2_PWM_channel, PWM_Frequency, PWM_RESOUTION);
  ledcAttachPin(_IN2, _IN2_PWM_channel);

  ledcSetup(_IN3_PWM_channel, PWM_Frequency, PWM_RESOUTION);
  ledcAttachPin(_IN3, _IN3_PWM_channel);

  ledcSetup(_IN4_PWM_channel, PWM_Frequency, PWM_RESOUTION);
  ledcAttachPin(_IN4, _IN4_PWM_channel);

  ledcWrite(_IN1_PWM_channel, 0);
  ledcWrite(_IN2_PWM_channel, 0);
  ledcWrite(_IN3_PWM_channel, 0);
  ledcWrite(_IN4_PWM_channel, 0);
}

void loop() 
{
  byte speed = 255;

  // move forward
  //right engine forward
  ledcWrite(_IN1_PWM_channel, 0);
  ledcWrite(_IN2_PWM_channel, speed);
  //left engine forward
  ledcWrite(_IN3_PWM_channel, speed);
  ledcWrite(_IN4_PWM_channel, 0);

  delay(1000);

  // turn left
  //right engine forward
  ledcWrite(_IN1_PWM_channel, 0);
  ledcWrite(_IN2_PWM_channel, speed);
  //left engine reverse
  ledcWrite(_IN3_PWM_channel, 0);
  ledcWrite(_IN4_PWM_channel, speed);

  delay(1000);
 
  // turn right
  //right engine reverse
  ledcWrite(_IN1_PWM_channel, speed);
  ledcWrite(_IN2_PWM_channel, 0);
  //left engine forward
  ledcWrite(_IN3_PWM_channel, speed);
  ledcWrite(_IN4_PWM_channel, 0);

  delay(1000);
 
  // reverse
  //right engine reverse
  ledcWrite(_IN1_PWM_channel, speed);
  ledcWrite(_IN2_PWM_channel, 0);
  //left engine reverse
  ledcWrite(_IN3_PWM_channel, 0);
  ledcWrite(_IN4_PWM_channel, speed);

  delay(1000);
  
}
