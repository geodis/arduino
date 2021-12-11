#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>
#include "ESP8266WiFi.h"
#include <Wire.h>

#define TFT_RST D4
#define TFT_CS D3
#define TFT_DC D2

/* para nodemcu
gnd -> gnd
vcc -> 3.3v
scl -> d5
sda -> d7
res -> d4
dc -> d2
cs -> d3
*/

// OPTION 1 (recommended) is to use the HARDWARE SPI pins, which are unique
// to each board and not reassignable. For Arduino Uno: MOSI = pin 11 and
// SCLK = pin 13. This is the fastest mode of operation and is required if
// using the breakout board's microSD card.

// For 1.44" and 1.8" TFT with ST7735 (including HalloWing) use:
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

// OPTION 2 lets you interface the display using ANY TWO or THREE PINS,
// tradeoff being that performance is not as fast as hardware SPI above.
//#define TFT_MOSI 11  // Data ougit t
//#define TFT_SCLK 13  // Clock out
//Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

// color definitions
const uint16_t Display_Color_Black = 0x0000;
const uint16_t Display_Color_Blue = 0x001F;
const uint16_t Display_Color_Red = 0xF800;
const uint16_t Display_Color_Green = 0x07E0;
const uint16_t Display_Color_Cyan = 0x07FF;
const uint16_t Display_Color_Magenta = 0xF81F;
const uint16_t Display_Color_Yellow = 0xFFE0;
const uint16_t Display_Color_White = 0xFFFF;

// The colors we actually want to use
uint16_t Display_Text_Color = Display_Color_White;
uint16_t Display_Backround_Color = Display_Color_Black;

const int RSSI_MAX = -50;  // define maximum strength of signal in dBm
const int RSSI_MIN = -100; // define minimum strength of signal in dBm

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  tft.initR(INITR_MINI160x80);
  tft.setRotation(3);
  tft.setFont();
  tft.fillScreen(Display_Backround_Color);
  tft.setTextColor(Display_Text_Color);
  tft.setTextSize(2);
  Serial.println("Setup done");
}

void loop(){
  
  int n = WiFi.scanNetworks();
  int power_percentage[n];
  String ssids[n];
  int top_power = 4;

  if (n == 0) {
    Serial.println("no networks found");
  } else {
    for (int i = 0; i < n; ++i) {
      ssids[i] = WiFi.SSID(i);
      power_percentage[i] = dbm_to_percentage(WiFi.RSSI(i));
      reset_display();
    }
  }
  sort_values_by_key(power_percentage, ssids, n);

  for (int a = 0; a < n && a < top_power; a++) {
    // Serial
    Serial.print(ssids[a]);
    Serial.print(" - ");
    Serial.println(power_percentage[a]);
    // ----------------------------------------------
    String m = ssids[a] + " - " + power_percentage[a];
    display_message(m, (a*20), 0, 1);
  }

  delay(5000);
  reset_display();
  display_message("Reseting...",0, Display_Color_Green, 2);
  delay(1500);
  reset_display();
  Serial.println("------------- 00 -------------");
}

void reset_display() {
  tft.fillScreen(ST77XX_BLACK);
}

void display_message(String m, int y_pos, int color, int text_size) {

  if (color == 0){
    color = Display_Text_Color;
  }
  tft.setTextWrap(false);
  tft.setCursor(0, y_pos);
  tft.setTextColor(color);
  tft.setTextSize(text_size);
  tft.println(m);
}

void sort_values_by_key(int key[], String values[], int length) {

  int i, j, flag = 1;
  int temp;
  String temp2;

  for (i = 0; (i < length && flag == 1); i++)
  {
    flag = 0;

    for (j = 0; j < (length - 1); j++)
    {
      if (key[j + 1] > key[j])
      {

        temp = key[j];
        temp2 = values[j];

        key[j] = key[j + 1];
        values[j] = values[j + 1];

        key[j + 1] = temp;
        values[j + 1] = temp2;

        flag = 1;
      }
    }
  }
}

int dbm_to_percentage(int dBm) {
  int quality;
  if (dBm <= RSSI_MIN)
  {
    quality = 0;
  }
  else if (dBm >= RSSI_MAX)
  {
    quality = 100;
  }
  else
  {
    quality = 2 * (dBm + 100);
  }
  return quality;
}

