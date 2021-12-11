// D3
int button = 0;
// D5
int layer1 = 14;
// D6
int layer2 = 12;
// D7
int layer3 = 13;

// D0
int dataPin = 16;
// D1
int latchPin = 5;
// D2
int clockPin = 4;

const int arr_size = 11;
byte dataArray[arr_size];
// int *p_layer[3];
int *l1;
int *l2;
int *l3;

void setup()
{
  pinMode(button, INPUT);
  Serial.begin(9600);
  Serial.println("Starting ...");
  l1 = &layer1;
  l2 = &layer2;
  l3 = &layer3;
  pinMode(*l1, OUTPUT);
  pinMode(*l2, OUTPUT);
  pinMode(*l3, OUTPUT);
  digitalWrite(*l1, 1);
  digitalWrite(*l2, 1);
  digitalWrite(*l3, 1);

  // pinMode(layer1, OUTPUT);
  // pinMode(layer2, OUTPUT);
  // pinMode(layer3, OUTPUT);
  // p_layer[0] = &layer1;
  // p_layer[1] = &layer2;
  // p_layer[2] = &layer3;

  pinMode(latchPin, OUTPUT);

  // // Binary notation as comment

  dataArray[0] = 0x100;  // 100000000
  dataArray[1] = 0x80;   // 010000000
  dataArray[2] = 0x40;   // 001000000
  dataArray[3] = 0x20;   // 000100000
  dataArray[4] = 0x10;   // 000010000
  dataArray[5] = 0x8;    // 000001000
  dataArray[6] = 0x4;    // 000000100
  dataArray[7] = 0x2;    // 000000010
  dataArray[8] = 0x1;    // 000000001
  dataArray[9] = 0x0;    // 000000000
  dataArray[10] = 0x1FF; // 111111111

}

void loop()
{
  static uint8_t lastBtnState = LOW;
  uint8_t state = digitalRead(button);
  

  // // digitalWrite(*p_layer[random(0,2)], random(0,1));
  // *p_layer[0] = 1;
  // digitalWrite(latchPin, 0);
  // shiftOut(dataPin, clockPin, dataArray[random(0, 10)]);
  // digitalWrite(latchPin, 1);
  // delay(3);

  for (int j = 0; j < 11;)
  {
    digitalWrite(latchPin, 0);
    //count up on GREEN LEDs
    shiftOut(dataPin, clockPin, dataArray[j]);
    Serial.print("Count: ");
    Serial.println(j);
    //count down on RED LEDs
    // shiftOut(dataPin, clockPin, 255 - j);
    //return the latch pin high to signal chip that it
    //no longer needs to listen for information
    digitalWrite(latchPin, 1);
    delay(1000);
    j = j+1;Z
    // if (state != lastBtnState) {
    //   lastBtnState = state;
    //   if (state == HIGH) {
    //     j++;
    //     Serial.println("increment.... release");
    //     delay(2000);
    //   }
    // }
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