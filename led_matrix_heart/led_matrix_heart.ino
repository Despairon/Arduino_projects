const int ARDUINO_LED = 13;
const int COL_1 = 6;
const int COL_2 = 7;
const int COL_3 = 8;
const int COL_4 = 9;
const int COL_5 = A3;
const int COL_6 = A2;
const int COL_7 = A1;
const int COL_8 = A0;
const int ROW_1 = 2;
const int ROW_2 = 3;
const int ROW_3 = 4;
const int ROW_4 = 5;
const int ROW_5 = 10;
const int ROW_6 = 11;
const int ROW_7 = 12;
const int ROW_8 = 13;

void setup() 
{
  
  pinMode(ARDUINO_LED, OUTPUT);
  digitalWrite(ARDUINO_LED, LOW);

  pinMode(COL_1, OUTPUT);
  pinMode(COL_2, OUTPUT);
  pinMode(COL_3, OUTPUT);
  pinMode(COL_4, OUTPUT);  
  pinMode(COL_5, OUTPUT);
  pinMode(COL_6, OUTPUT);
  pinMode(COL_7, OUTPUT);
  pinMode(COL_8, OUTPUT);

  pinMode(ROW_1, OUTPUT);
  pinMode(ROW_2, OUTPUT);
  pinMode(ROW_3, OUTPUT);
  pinMode(ROW_4, OUTPUT);  
  pinMode(ROW_5, OUTPUT);
  pinMode(ROW_6, OUTPUT);
  pinMode(ROW_7, OUTPUT);
  pinMode(ROW_8, OUTPUT);

}

void loop() 
{
  digitalWrite(ROW_1, HIGH);
  digitalWrite(COL_1, HIGH);
  digitalWrite(COL_2, HIGH);
  digitalWrite(COL_3, LOW);
  digitalWrite(COL_4, HIGH);
  digitalWrite(COL_5, HIGH);
  digitalWrite(COL_6, LOW);
  digitalWrite(COL_7, HIGH);
  digitalWrite(COL_8, HIGH);


  digitalWrite(ROW_1, LOW);
  digitalWrite(COL_1, HIGH);
  digitalWrite(COL_2, HIGH);
  digitalWrite(COL_3, HIGH);
  digitalWrite(COL_4, HIGH);
  digitalWrite(COL_5, HIGH);
  digitalWrite(COL_6, HIGH);
  digitalWrite(COL_7, HIGH);
  digitalWrite(COL_8, HIGH);
  
  
  digitalWrite(ROW_2, HIGH);
  digitalWrite(COL_1, HIGH);
  digitalWrite(COL_2, LOW);
  digitalWrite(COL_3, HIGH);
  digitalWrite(COL_4, LOW);
  digitalWrite(COL_5, LOW);
  digitalWrite(COL_6, HIGH);
  digitalWrite(COL_7, LOW);
  digitalWrite(COL_8, HIGH);


  digitalWrite(ROW_2, LOW);
  digitalWrite(COL_1, HIGH);
  digitalWrite(COL_2, HIGH);
  digitalWrite(COL_3, HIGH);
  digitalWrite(COL_4, HIGH);
  digitalWrite(COL_5, HIGH);
  digitalWrite(COL_6, HIGH);
  digitalWrite(COL_7, HIGH);
  digitalWrite(COL_8, HIGH);

  digitalWrite(ROW_3, HIGH);
  digitalWrite(COL_1, LOW);
  digitalWrite(COL_2, HIGH);
  digitalWrite(COL_3, HIGH);
  digitalWrite(COL_4, HIGH);
  digitalWrite(COL_5, HIGH);
  digitalWrite(COL_6, HIGH);
  digitalWrite(COL_7, HIGH);
  digitalWrite(COL_8, LOW);


  digitalWrite(ROW_3, LOW);
  digitalWrite(COL_1, HIGH);
  digitalWrite(COL_2, HIGH);
  digitalWrite(COL_3, HIGH);
  digitalWrite(COL_4, HIGH);
  digitalWrite(COL_5, HIGH);
  digitalWrite(COL_6, HIGH);
  digitalWrite(COL_7, HIGH);
  digitalWrite(COL_8, HIGH);

  
  digitalWrite(ROW_4, HIGH);
  digitalWrite(COL_1, HIGH);
  digitalWrite(COL_2, LOW);
  digitalWrite(COL_3, HIGH);
  digitalWrite(COL_4, HIGH);
  digitalWrite(COL_5, HIGH);
  digitalWrite(COL_6, HIGH);
  digitalWrite(COL_7, LOW);
  digitalWrite(COL_8, HIGH);


  digitalWrite(ROW_4, LOW);
  digitalWrite(COL_1, HIGH);
  digitalWrite(COL_2, HIGH);
  digitalWrite(COL_3, HIGH);
  digitalWrite(COL_4, HIGH);
  digitalWrite(COL_5, HIGH);
  digitalWrite(COL_6, HIGH);
  digitalWrite(COL_7, HIGH);
  digitalWrite(COL_8, HIGH);

  digitalWrite(ROW_5, HIGH);
  digitalWrite(COL_1, HIGH);
  digitalWrite(COL_2, HIGH);
  digitalWrite(COL_3, LOW);
  digitalWrite(COL_4, HIGH);
  digitalWrite(COL_5, HIGH);
  digitalWrite(COL_6, LOW);
  digitalWrite(COL_7, HIGH);
  digitalWrite(COL_8, HIGH);


  digitalWrite(ROW_5, LOW);
  digitalWrite(COL_1, HIGH);
  digitalWrite(COL_2, HIGH);
  digitalWrite(COL_3, HIGH);
  digitalWrite(COL_4, HIGH);
  digitalWrite(COL_5, HIGH);
  digitalWrite(COL_6, HIGH);
  digitalWrite(COL_7, HIGH);
  digitalWrite(COL_8, HIGH);

  digitalWrite(ROW_6, HIGH);
  digitalWrite(COL_1, HIGH);
  digitalWrite(COL_2, HIGH);
  digitalWrite(COL_3, HIGH);
  digitalWrite(COL_4, LOW);
  digitalWrite(COL_5, LOW);
  digitalWrite(COL_6, HIGH);
  digitalWrite(COL_7, HIGH);
  digitalWrite(COL_8, HIGH);


  digitalWrite(ROW_6, LOW);
  digitalWrite(COL_1, HIGH);
  digitalWrite(COL_2, HIGH);
  digitalWrite(COL_3, HIGH);
  digitalWrite(COL_4, HIGH);
  digitalWrite(COL_5, HIGH);
  digitalWrite(COL_6, HIGH);
  digitalWrite(COL_7, HIGH);
  digitalWrite(COL_8, HIGH);

}
