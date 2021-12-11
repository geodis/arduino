
// #include <SPI.h>
// #include <Wire.h>
// #include <Adafruit_GFX.h>
// #include <Adafruit_SSD1306.h>

// #define SCREEN_WIDTH 128
// #define SCREEN_HEIGHT 32

// #define OLED_RESET     -1
// #define SCREEN_ADDRESS 0x3C
// Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// // void print_message(Adafruit_SSD1306 d, String m, int8 x=0, int8 y=0){
// void print_message(){

//   d.clearDisplay();
//   // d.setCursor(x,y);
//   d.setCursor(0,0);
//   d.write("hola");
//   // d.write((char*)m.c_str());
//   d.display();
//   delay(1000);
//   Serial.println("impreso ...");
//   // Serial.println((char*)m.c_str());
// }

// void setup() {
//   Serial.begin(9600);

//   if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
//     Serial.println(F("SSD1306 allocation failed"));
//     for(;;);
//   }
//   display.clearDisplay();
//   display.setTextSize(0.1);
//   display.setTextColor(SSD1306_WHITE);
//   display.cp437(true);
//   display.setCursor(0, 0);
// }

// void loop() {
//   // String r[3] = [ "uno", "dos", "tricoa" ];

//   for(int i = 0; i < 3; i++) {
//     // print_message(display, r[i],0,0);
//     Serial.println("continue ...");
//   }

// }



// // void testdrawchar(void) {
// //   display.clearDisplay();

// //   display.setTextSize(1);      // Normal 1:1 pixel scale
// //   display.setTextColor(SSD1306_WHITE); // Draw white text
// //   display.setCursor(0, 0);     // Start at top-left corner
// //   display.cp437(true);         // Use full 256 char 'Code Page 437' font

// //   // Not all the characters will fit on the display. This is normal.
// //   // Library will draw what it can and the rest will be clipped.
// //   // for(int16_t i=0; i<256; i++) {
// //   //   if(i == '\n') display.write(' ');
// //   //   else          display.write(i);
// //   // }
// //   for (int i=0; i < 4; i++){

// //     display.write("hola mundo");

// //   }

// //   display.display();
// //   delay(2000);
// // }
