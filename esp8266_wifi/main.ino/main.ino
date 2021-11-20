#include "ESP8266WiFi.h"
#include <SPI.h>
#include <Wire.h>
// #include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128    // OLED display width, in pixels
#define SCREEN_HEIGHT 32    // OLED display height, in pixels
#define OLED_RESET -1       // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int RSSI_MAX = -50;  // define maximum strength of signal in dBm
const int RSSI_MIN = -100; // define minimum strength of signal in dBm

const int displayEnc = 1; // set to 1 to display Encryption or 0 not to display

void setup()
{
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
  {

    Serial.println(F("SSD1306 allocation failed"));

    for (;;)
      ; // Don't proceed, loop forever
  }

  // display.clearDisplay();
  // display.setTextSize(1);
  // display.setTextColor(SSD1306_WHITE); // Draw white text
  // display.cp437(true);
  // display.setCursor(0, 0);     // Start at top-left corner
  // display.write("Setup done");
  // display.display();
  // delay(2000);

  Serial.println("Setup done");
}

void loop()
{

  int count = 1;

  while (true)
  {
    Serial.print("waiting ");
  
    int n = WiFi.scanNetworks();
    int power_percentage[n];
    String ssids[n];
    
    int top_power = 4;
    if (n == 0)
    {
      Serial.println("no networks found");
    }
    else
    {
      for (int i = 0; i < n; ++i)
      {
        ssids[i] = WiFi.SSID(i);
        power_percentage[i] = dbm_to_percentage(WiFi.RSSI(i));
      }
      
    }
    sort_values_by_key(power_percentage, ssids, n);
    
    for (int a =0; a < n && a < top_power; a++){
      Serial.print(ssids[a]);
      Serial.print(" - ");
      Serial.println(power_percentage[a]);
    }
    Serial.println("------------- 00 -------------");
    
    delay(1500);
  }
}

void sort_values_by_key(int key[], String values[], int length)
{

  int i, j, flag = 1;
  int temp; 
  String temp2;

  for ( i = 0; (i < length && flag == 1); i++ )
  {
    flag = 0;

    for (j = 0; j < (length -1); j++) {
      if (key[j + 1] > key[j]) {

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

int dbm_to_percentage(int dBm)
{
  int quality;
  if (dBm <= RSSI_MIN) {
    quality = 0;
  } else if (dBm >= RSSI_MAX) {
    quality = 100;
  } else {
    quality = 2 * (dBm + 100);
  }
  return quality;
}