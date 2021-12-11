
// #include <ESP8266WiFi.h>
// #include <Adafruit_GFX.h>    // include Adafruit graphics library
// #include <Adafruit_ST7735.h> // include Adafruit ST7735 TFT library
// #include <SPI.h>

// // ST7735 TFT module connections
// #define TFT_RST D4 // TFT RST pin is connected to NodeMCU pin D4 (GPIO2)
// #define TFT_CS D3  // TFT CS  pin is connected to NodeMCU pin D3 (GPIO0)
// #define TFT_DC D2  // TFT DC  pin is connected to NodeMCU pin D2 (GPIO4)
// #define SerialDebugging true

// Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

// void setup(void)
// {
//   Serial.begin(9600);
//   tft.initR(INITR_GREENTAB); // initialize a ST7735S chip, black tab
//   tft.setRotation(3);

//   tft.setTextWrap(false); // Allow text to run off right edge
//   tft.fillScreen(ST77XX_BLACK);
//   Serial.println("This is a test of the rotation capabilities of the TFT library!");
//   Serial.println("Press <SEND> (or type a character) to advance");

// }

// void loop()
// {
//   rotateLine();
//   rotateText();
//   rotatePixel();
//   rotateFastline();
//   rotateDrawrect();
//   rotateFillrect();
//   rotateDrawcircle();
//   rotateFillcircle();
//   rotateTriangle();
//   rotateFillTriangle();
//   rotateRoundRect();
//   rotateFillRoundRect();
//   rotateChar();
//   rotateString();
// }

// void rotateText() {
//   for (uint8_t i=0; i<4; i++) {
//     tft.fillScreen(ST77XX_WHITE);
//     Serial.println(tft.getRotation(), DEC);

//     tft.setCursor(0, 30);
//     tft.setTextColor(ST77XX_RED);
//     tft.setTextSize(1);
//     tft.println("Hello World!");
//     tft.setTextColor(ST77XX_YELLOW);
//     tft.setTextSize(2);
//     tft.println("Hello World!");
//     tft.setTextColor(ST77XX_GREEN);
//     tft.setTextSize(3);
//     tft.println("Hello World!");
//     tft.setTextColor(ST77XX_BLUE);
//     tft.setTextSize(4);
//     tft.print(1234.567);
//     while (!Serial.available());
//     Serial.read();  Serial.read();  Serial.read();
  
//     tft.setRotation(tft.getRotation()+1);
//   }
// }

// void rotateFillcircle(void) {
//   for (uint8_t i=0; i<4; i++) {
//     tft.fillScreen(ST77XX_BLACK);
//     Serial.println(tft.getRotation(), DEC);

//     tft.fillCircle(10, 30, 10, ST77XX_YELLOW);

//     while (!Serial.available());
//     Serial.read();  Serial.read();  Serial.read();

//     tft.setRotation(tft.getRotation()+1);
//   }
// }

// void rotateDrawcircle(void) {
//   for (uint8_t i=0; i<4; i++) {
//     tft.fillScreen(ST77XX_BLACK);
//     Serial.println(tft.getRotation(), DEC);

//     tft.drawCircle(10, 30, 10, ST77XX_YELLOW);
 
//     while (!Serial.available());
//     Serial.read();  Serial.read();  Serial.read();
  
//     tft.setRotation(tft.getRotation()+1);
//   }
// }

// void rotateFillrect(void) {
//   for (uint8_t i=0; i<4; i++) {
//     tft.fillScreen(ST77XX_BLACK);
//     Serial.println(tft.getRotation(), DEC);

//     tft.fillRect(10, 20, 10, 20, ST77XX_GREEN);
 
//     while (!Serial.available());
//     Serial.read();  Serial.read();  Serial.read();

//     tft.setRotation(tft.getRotation()+1);
//   }
// }

// void rotateDrawrect(void) {
//   for (uint8_t i=0; i<4; i++) {
//     tft.fillScreen(ST77XX_BLACK);
//     Serial.println(tft.getRotation(), DEC);

//     tft.drawRect(10, 20, 10, 20, ST77XX_GREEN);
 
//     while (!Serial.available());
//     Serial.read();  Serial.read();  Serial.read();

//     tft.setRotation(tft.getRotation()+1);
//   }
// }

// void rotateFastline(void) {
//   for (uint8_t i=0; i<4; i++) {
//     tft.fillScreen(ST77XX_BLACK);
//     Serial.println(tft.getRotation(), DEC);

//     tft.drawFastHLine(0, 20, tft.width(), ST77XX_RED);
//     tft.drawFastVLine(20, 0, tft.height(), ST77XX_BLUE);

//     while (!Serial.available());
//     Serial.read();  Serial.read();  Serial.read();

//     tft.setRotation(tft.getRotation()+1);
//   }
// }

// void rotateLine(void) {
//   for (uint8_t i=0; i<4; i++) {
//     tft.fillScreen(ST77XX_BLACK);
//     Serial.println(tft.getRotation(), DEC);

//     tft.drawLine(tft.width()/2, tft.height()/2, 0, 0, ST77XX_RED);
//     while (!Serial.available());
//     Serial.read();  Serial.read();  Serial.read();

//     tft.setRotation(tft.getRotation()+1);
//   }
// }

// void rotatePixel(void) {
//   for (uint8_t i=0; i<4; i++) {
//     tft.fillScreen(ST77XX_BLACK);
//     Serial.println(tft.getRotation(), DEC);

//     tft.drawPixel(10,20, ST77XX_WHITE);
//     while (!Serial.available());
//     Serial.read();  Serial.read();  Serial.read();

//     tft.setRotation(tft.getRotation()+1);
//   }
// }

// void rotateTriangle(void) {
//   for (uint8_t i=0; i<4; i++) {
//     tft.fillScreen(ST77XX_BLACK);
//     Serial.println(tft.getRotation(), DEC);

//     tft.drawTriangle(20, 10, 10, 30, 30, 30, ST77XX_GREEN);
//     while (!Serial.available());
//     Serial.read();  Serial.read();  Serial.read();

//     tft.setRotation(tft.getRotation()+1);
//   }
// }

// void rotateFillTriangle(void) {
//   for (uint8_t i=0; i<4; i++) {
//     tft.fillScreen(ST77XX_BLACK);
//     Serial.println(tft.getRotation(), DEC);

//     tft.fillTriangle(20, 10, 10, 30, 30, 30, ST77XX_RED);
//     while (!Serial.available());
//     Serial.read();  Serial.read();  Serial.read();

//     tft.setRotation(tft.getRotation()+1);
//   }
// }

// void rotateRoundRect(void) {
//   for (uint8_t i=0; i<4; i++) {
//     tft.fillScreen(ST77XX_BLACK);
//     Serial.println(tft.getRotation(), DEC);

//     tft.drawRoundRect(20, 10, 25, 15, 5, ST77XX_BLUE);
//     while (!Serial.available());
//     Serial.read();  Serial.read();  Serial.read();

//     tft.setRotation(tft.getRotation()+1);
//   }
// }

// void rotateFillRoundRect(void) {
//   for (uint8_t i=0; i<4; i++) {
//     tft.fillScreen(ST77XX_BLACK);
//     Serial.println(tft.getRotation(), DEC);

//     tft.fillRoundRect(20, 10, 25, 15, 5, ST77XX_CYAN);
//     while (!Serial.available());
//     Serial.read();  Serial.read();  Serial.read();

//     tft.setRotation(tft.getRotation()+1);
//   }
// }

// void rotateChar(void) {
//   for (uint8_t i=0; i<4; i++) {
//     tft.fillScreen(ST77XX_BLACK);
//     Serial.println(tft.getRotation(), DEC);

//     tft.drawChar(25, 15, 'A', ST77XX_WHITE, ST77XX_WHITE, 1);
//     while (!Serial.available());
//     Serial.read();  Serial.read();  Serial.read();

//     tft.setRotation(tft.getRotation()+1);
//   }
// }

// void rotateString(void) {
//   for (uint8_t i=0; i<4; i++) {
//     tft.fillScreen(ST77XX_BLACK);
//     Serial.println(tft.getRotation(), DEC);

//     tft.setCursor(8, 25);
//     tft.setTextSize(1);
//     tft.setTextColor(ST77XX_WHITE);
//     tft.print("Adafruit Industries");
//     while (!Serial.available());
//     Serial.read();  Serial.read();  Serial.read();

//     tft.setRotation(tft.getRotation()+1);
//   }
// }