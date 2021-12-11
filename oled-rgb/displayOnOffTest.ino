// #include <Adafruit_GFX.h>
// #include <Adafruit_ST7735.h>
// #include <SPI.h>

// #define TFT_RST D4
// #define TFT_CS D3
// #define TFT_DC D2

// /* para nodemcu
// gnd -> gnd
// vcc -> 3.3v
// scl -> d5
// sda -> d7
// res -> d4
// dc -> d2
// cs -> d3
// */


// // OPTION 1 (recommended) is to use the HARDWARE SPI pins, which are unique
// // to each board and not reassignable. For Arduino Uno: MOSI = pin 11 and
// // SCLK = pin 13. This is the fastest mode of operation and is required if
// // using the breakout board's microSD card.

// // For 1.44" and 1.8" TFT with ST7735 (including HalloWing) use:
// Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

// // OPTION 2 lets you interface the display using ANY TWO or THREE PINS,
// // tradeoff being that performance is not as fast as hardware SPI above.
// //#define TFT_MOSI 11  // Data out
// //#define TFT_SCLK 13  // Clock out
// //Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

// // color definitions
// const uint16_t Display_Color_Black = 0x0000;
// const uint16_t Display_Color_Blue = 0x001F;
// const uint16_t Display_Color_Red = 0xF800;
// const uint16_t Display_Color_Green = 0x07E0;
// const uint16_t Display_Color_Cyan = 0x07FF;
// const uint16_t Display_Color_Magenta = 0xF81F;
// const uint16_t Display_Color_Yellow = 0xFFE0;
// const uint16_t Display_Color_White = 0xFFFF;

// // The colors we actually want to use
// uint16_t Display_Text_Color = Display_Color_Black;
// uint16_t Display_Backround_Color = Display_Color_White;


// void setup()
// {
//   Serial.begin(115200);
//   delay(250);
//   tft.initR(INITR_MINI160x80);
//   tft.setRotation(3);
//   tft.setFont();
//   tft.fillScreen(Display_Backround_Color);
//   tft.setTextColor(Display_Text_Color);
//   tft.setTextSize(1);
// }

// void loop()
// {
//   tft.setCursor(0, 0);
//   tft.setTextColor(Display_Text_Color);
//   tft.print("1234567890");
//   tft.enableDisplay(true);
//   delay(100);
//   tft.setCursor(10, 10);
//   tft.print("abcdef");
//   tft.setCursor(20, 20);
//   tft.print("ABCDEF");
//   tft.enableDisplay(true);
//   delay(1000);
//   tft.setRotation(1);
//   tft.setCursor(0, 0);
//   tft.setTextColor(Display_Text_Color);
//   tft.print("1234567890");
//   tft.enableDisplay(true);
//   delay(100);
//   tft.setCursor(10, 10);
//   tft.print("abcdef");
//   tft.setCursor(20, 20);
//   tft.print("ABCDEF");
//   tft.enableDisplay(true);
//   delay(1000);
//   tft.setRotation(0);
//   tft.setCursor(0, 0);
//   tft.setTextColor(Display_Text_Color);
//   tft.print("1234567890");
//   tft.enableDisplay(true);
//   delay(100);
//   tft.setCursor(10, 10);
//   tft.print("abcdef");
//   tft.setCursor(20, 20);
//   tft.print("ABCDEF");
//   tft.enableDisplay(true);
// }
