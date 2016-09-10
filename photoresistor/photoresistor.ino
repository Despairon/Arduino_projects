const int ARDUINO_LED = 13;
const int PHOTORESISTOR = A0;
const int LED1 = 3;
const int LED2 = 5;
int ledIntensity = 0;

void setup() 
{
  
  pinMode(ARDUINO_LED, OUTPUT);
  digitalWrite(ARDUINO_LED, LOW);
  pinMode(PHOTORESISTOR, INPUT);
  pinMode(ARDUINO_LED, OUTPUT);
  pinMode(ARDUINO_LED, OUTPUT);
}

void loop() 
{
  ledIntensity = analogRead(PHOTORESISTOR);
  ledIntensity = map(ledIntensity, 10, 49, 255, 1);
  analogWrite(LED1, ledIntensity);
  analogWrite(LED2, ledIntensity);
}
