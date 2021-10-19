
// D5
int t1 = 14;
// D6
int t2 = 12;
// D7
int t3 = 13;

// D0
int dataPin = 16;
// D1
int latchPin = 5;
// D2
int clockPin = 4;

void setup()
{

  pinMode(t1, OUTPUT);
  pinMode(t2, OUTPUT);
  pinMode(t3, OUTPUT);
  // pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  // pinMode(clockPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(t1,1);
  digitalWrite(t2,0);
  digitalWrite(t3,0);
  for (int j = 0; j < 256; j++)
  {
    digitalWrite(latchPin, 0);
    //count up on GREEN LEDs
    shiftOut(dataPin, clockPin, j);
    //count down on RED LEDs
    shiftOut(dataPin, clockPin, 255 - j);
    //return the latch pin high to signal chip that it
    //no longer needs to listen for information
    digitalWrite(latchPin, 1);
    delay(1000);
  }
}

void shiftOut(int myDataPin, int myClockPin, byte myDataOut)
{
  // This shifts 8 bits out MSB first,
  //on the rising edge of the clock,
  //clock idles low
  //internal function setup
  int i = 0;
  int pinState;
  pinMode(myClockPin, OUTPUT);
  pinMode(myDataPin, OUTPUT);
  digitalWrite(myDataPin, 0);
  digitalWrite(myClockPin, 0);
  //for each bit in the byte myDataOut&#xFFFD;
  //NOTICE THAT WE ARE COUNTING DOWN in our for loop
  //This means that %00000001 or "1" will go through such
  //that it will be pin Q0 that lights.
  for (i = 7; i >= 0; i--)
  {
    digitalWrite(myClockPin, 0);
    //if the value passed to myDataOut and a bitmask result
    // true then... so if we are at i=6 and our value is
    // %11010100 it would the code compares it to %01000000
    // and proceeds to set pinState to 1.
    if (myDataOut & (1 << i))
    {
      pinState = 1;
    }
    else
    {
      pinState = 0;
    }
    //Sets the pin to HIGH or LOW depending on pinState
    digitalWrite(myDataPin, pinState);
    //register shifts bits on upstroke of clock pin
    digitalWrite(myClockPin, 1);
    //zero the data pin after shift to prevent bleed through
    digitalWrite(myDataPin, 0);
  }
  //stop shifting
  digitalWrite(myClockPin, 0);
}