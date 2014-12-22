#include <font4x6.h>
#include <font6x8.h>
#include <font8x8.h>
#include <font8x8ext.h>
#include <fontALL.h>
#include <PS2Keyboard.h>
const int DataPin = 4;
const int IRQpin =  3;
PS2Keyboard keyboard;
#include <TVout.h>
#include <video_gen.h>
TVout TV;
void setup(){
  TV.begin(NTSC,128,96);
  start();
}
void start(){
  TV.clear_screen();
  TV.select_font(font4x6);
  TV.println("TV boot Successful");
  TV.tone(500, 20);
  delay(3000);
  keyboard.begin(DataPin, IRQpin);
  TV.tone(500, 20);
  TV.println("Keyboard Startup Sucessful");
  delay(4000);
  TV.println("BILLYTERM V1.5 Boot Success");
  TV.tone(500, 20);
  delay(2000);
  TV.println("Press [ESC] to begin.");
  TV.tone(800, 500);
  TV.select_font(font8x8);
}
void loop(){
  if (keyboard.available()) {
    // read the next key
    char c = keyboard.read();
    // check for some of the special keys
    if (c == PS2_ENTER) {
      TV.println();
      TV.tone(400, 20);
    } else if (c == PS2_TAB) {
      TV.tone(400, 20);
      start();
    } else if (c == PS2_ESC) {
      TV.tone(400, 20);
      TV.clear_screen();
    } else if (c == PS2_DELETE) {
      TV.print("\b");
    } else {
      TV.tone(400, 20);
      TV.print(c);
    }
  }
}
