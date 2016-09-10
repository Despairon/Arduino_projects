const char ARDUINO_LED = 13;
const char DATA = 2;
const char LATCH = 3;
const char CLOCK = 4;

enum leds {NONE = 0b00000000, LED_1 = 0b10000000, LED_2 = 0b01000000, LED_3 = 0b00100000, LED_4 = 0b00010000,
                LED_5 = 0b00001000, LED_6 = 0b00000100, LED_7 = 0b00000010, LED_8 = 0b00000001};
                
void openLatch()
{
  digitalWrite(LATCH, LOW);
}

void closeLatch()
{
  digitalWrite(LATCH, HIGH);
}

void ledOn(byte led)
{
  openLatch();
  shiftOut(DATA, CLOCK, LSBFIRST, led);
  closeLatch();
}

void clearLeds()
{
  shiftOut(DATA, CLOCK, LSBFIRST, NONE);
}

void setup()
{
  pinMode(ARDUINO_LED, OUTPUT);
  digitalWrite(ARDUINO_LED, LOW);

  pinMode(DATA,  OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  closeLatch();
}

void loop() 
{
  ledOn(LED_1);
  delay(500);
  ledOn(LED_2);
  delay(500);
  ledOn(LED_3);
  delay(500);
  ledOn(LED_4);
  delay(500);
  ledOn(LED_5);
  delay(500);
  ledOn(LED_6);
  delay(500);
  ledOn(LED_7);
  delay(500);
  ledOn(LED_8);
  delay(500);
}
