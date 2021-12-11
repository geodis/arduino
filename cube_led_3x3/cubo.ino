/*
Keybindings
Arduino: Upload Alt + Cmd + U or Alt + Ctrl + U
Arduino: Verify Alt + Cmd + R or Alt + Ctrl + R
Arduino: Rebuild IntelliSense Configuration Alt + Cmd + I or Alt + Ctrl + I
*/

int Layer[] = {10, 9, 1};

void setup() {

  for (int c = 0; c < 3; c++) {
    pinMode(Layer[c], OUTPUT);
  }
  pinMode(16, OUTPUT);

 digitalWrite(Layer[0], HIGH);
 digitalWrite(Layer[1], LOW);
 digitalWrite(Layer[2], LOW);

 digitalWrite(16, HIGH);
}

void loop(){
}