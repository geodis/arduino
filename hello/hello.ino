int bits1(int c) {
  int res = 0;
  for (int i = 0; i < 8; i++) {
    if ((1 << i) & c) res = res + 1;
  }
  return (res);
}

int bits2(int c) {
  int m = 0x80;
  int res = 0;
  do {
    if (m & c) res++; 
  } while (m >>= 1);
  return (res);
}

int bits3(int c) {
  int m = 0x80;
  int res = 0;
  do {
    res += (m & c) != 0; 
  } while (m >>= 1);
  return (res);
}

#define bits4(c) __builtin_popcount(c) 

#define bits bits4

void setup() {
 Serial.begin(9600);
 while (!Serial);
}

void loop() {
  if (Serial.available() > 0) {
    int c = Serial.read();
    if (bits(c) == 3) {
      Serial.print((char) c);
      Serial.print(':');
      Serial.print(c, BIN);
      Serial.println(": Hello World");
    }
  }
}