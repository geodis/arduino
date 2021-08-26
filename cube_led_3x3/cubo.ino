/*
Keybindings
Arduino: Upload Alt + Cmd + U or Alt + Ctrl + U
Arduino: Verify Alt + Cmd + R or Alt + Ctrl + R
Arduino: Rebuild IntelliSense Configuration Alt + Cmd + I or Alt + Ctrl + I
 */

//Pin connected to ST_CP of 74HC595
// D8
int latchPin = 15;
//Pin connected to SH_CP of 74HC595
// D5
int clockPin = 14;
////Pin connected to DS of 74HC595
// D7
int dataPin = 13;

//holders for infromation you're going to pass to shifting function
byte data;
byte dataArray[10];

void setup() {

  //set pins to output because they are addressed in the main loop
  pinMode(latchPin, OUTPUT);

  Serial.begin(9600);
  Serial.println("Setup");

  //Binary notation as comment
  // dataArray[0] = 0xFF; //0b11111111
  // dataArray[1] = 0xFE; //0b11111110
  // dataArray[2] = 0xFC; //0b11111100
  // dataArray[3] = 0xF8; //0b11111000
  // dataArray[4] = 0xF0; //0b11110000
  // dataArray[5] = 0xE0; //0b11100000
  // dataArray[6] = 0xC0; //0b11000000
  // dataArray[7] = 0x80; //0b10000000
  // dataArray[8] = 0x00; //0b00000000

  dataArray[0] = 0x80;  // 10000000
  dataArray[1] = 0x40;  // 01000000
  dataArray[2] = 0x20;  // 00100000
  dataArray[3] = 0x10;  // 00010000
  dataArray[4] = 0x8;   // 00001000
  dataArray[5] = 0x4;   // 00000100
  dataArray[6] = 0x2;   // 00000010
  dataArray[7] = 0x1;   // 00000001
}

void loop() {

  digitalWrite(latchPin, 0);
  
  for (int j = 0; j < 8; j++) {
    
    data = dataArray[j];
    digitalWrite(latchPin, 0);
    //move 'em out
    shiftOut(dataPin, clockPin, data);
    digitalWrite(latchPin, 1);
    delay(300);
  }
  delay(2000);
}

void shiftOut(int myDataPin, int myClockPin, byte myDataOut) {

  int i=0;
  int pinState;
  pinMode(myClockPin, OUTPUT);
  pinMode(myDataPin, OUTPUT);

  digitalWrite(myDataPin, 0);
  digitalWrite(myClockPin, 0);
  
  for (i=7; i>=0; i--)  {

    digitalWrite(myClockPin, 0);
    if ( myDataOut & (1<<i) ) {
      pinState= 1;
    }
    else {
      pinState= 0;
    }

    digitalWrite(myDataPin, pinState);
    digitalWrite(myClockPin, 1);
    digitalWrite(myDataPin, 0);
  }
  //stop shifting
  digitalWrite(myClockPin, 0);
}
