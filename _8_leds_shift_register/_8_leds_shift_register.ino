const char ARDUINO_LED = 13;
const char DATA = 2;
const char LATCH = 3;
const char CLOCK = 4;
                
void openLatch()
{
  digitalWrite(LATCH, LOW);
}

void closeLatch()
{
  digitalWrite(LATCH, HIGH);
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
    openLatch();
    shiftOut(DATA, CLOCK, LSBFIRST, 0x00);
    closeLatch();
}
