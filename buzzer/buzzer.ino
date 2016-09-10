const int ARDUINO_LED = 13;
const int MUSIC = 11;

void setup() 
{
  
  pinMode(ARDUINO_LED, OUTPUT);
  digitalWrite(ARDUINO_LED, LOW);
  pinMode(MUSIC, OUTPUT);
}

void loop() 
{
  static int i=0;
  analogWrite(MUSIC, i);
  delay(100);
  i++;
}
