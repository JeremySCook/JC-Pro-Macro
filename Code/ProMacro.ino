#include <SPI.h>
#include <Wire.h>

// Declare variables etc=========================================

bool SW1 = 1; //encoder button
bool SW2 = 1; //lower-left keyswitch
bool SW3 = 1;
bool SW4 = 1; //lower-right keyswitch
bool SW5 = 1;
bool SW6 = 1; //upper-right keyswitch
bool increment = 0;
bool decrement = 0;
long oldPosition;
long newPosition;
int inputMode = 0;
int LEDLight = 1;
int LEDCircle[4] = {0, 1, 3, 2};
long randNumber;
long randNumber1;

//Long Press Setup==================================================

const int LONG_PRESS_TIME  = 500; // 1000 milliseconds
int lastState = 0;  // the previous state from the input pin
unsigned long pressedTime  = 0;
unsigned long releasedTime = 0;

// Encoder setup =============================================

#include <Encoder.h>
#include <HID-Project.h>
Encoder myEnc(0,1);

// Screen setup =============================================

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// NeoPixel setup =============================================

// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        5 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 4 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels

//============================================================

void setup() {
  Serial.begin(9600);
  pinMode(4, INPUT_PULLUP); //SW1 pushbutton (encoder button)
  pinMode(15, INPUT_PULLUP); //SW2 pushbutton
  pinMode(A0, INPUT_PULLUP); //SW3 pushbutton
  pinMode(A1, INPUT_PULLUP); //SW4 pushbutton
  pinMode(A2, INPUT_PULLUP); //SW5 pushbutton
  pinMode(A3, INPUT_PULLUP); //SW6 pushbutton

  randomSeed(analogRead(A9));
     
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  display.setRotation(2); //sets rotation 1 through 4 (2 = 180º rotation vs 4)
  display.clearDisplay();
  // Draw text
  display.setTextSize(1);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(30,0);             // Start at top-left corner
  display.print("Hello, world!");
  display.setCursor(30,30);  
  display.print("test");
  display.display();
  delay(10);
  display.setTextSize(3); 

//setup keyboard and mouse input
//perhaps add in a delay so that you can program before this starts up
Mouse.begin();
Keyboard.begin();
//BootKeyboard.begin(); - BootKeyboard use appears to give problems w/ Macintosh


//NeoPixel setup=========================================

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.clear();


  for(int i=0; i<NUMPIXELS; i++){
    pixels.setPixelColor(i, pixels.Color(10, 0, 0));
  }
  pixels.show(); // Show results
}


void loop() {

  SW1 = digitalRead(4);
  SW2 = digitalRead(15);
  SW3 = digitalRead(A0);
  SW4 = digitalRead(A1);
  SW5 = digitalRead(A2);
  SW6 = digitalRead(A3);

  newPosition = myEnc.read();
  
  if (newPosition > (oldPosition + 1)) increment = 1;
  if (newPosition < (oldPosition - 1)) decrement = 1;

  oldPosition = newPosition;
  delay(5);
    
  //delay(100); **need a better way to debounce, or to send a single keystroke - maybe sense
  //when it's "off" as well and wait for next cycle
  //have some sort of secondary oldPosition comparison?

if ((inputMode == 0) && (SW1 == 0)){ 
  inputMode = 1;
  SW1 = 1;
  delay(200);
}
if ((inputMode == 1) && (SW1 == 0)){ 
  inputMode = 0;
  SW1 = 1;
  delay(200);
}

//================================

screen();
volume();
if (inputMode == 1) jiggler();

//Serial.println(inputMode);

}


void screen(){
  display.clearDisplay();
  display.invertDisplay(0);
  display.setCursor(0,10);
  display.print(increment);
  display.print(decrement);
  display.print(" ");
  display.print(newPosition);
  display.println(LEDLight);
  display.print(SW1);
  display.print(SW2);
  display.print(SW3);
  display.print(SW4);
  display.print(SW5);
  display.print(SW6);
  display.print(inputMode);
  display.display();
  //Serial.println(SW1);
  //delay(10);
}

void volume(){
  if (increment == 1) {
        Consumer.write(MEDIA_VOLUME_UP);
        if (LEDLight == 3) LEDLight = 0;
        else if (LEDLight < 3) LEDLight += 1;
        pixels.clear();
        pixels.setPixelColor(LEDCircle[LEDLight], pixels.Color(10, 0, 0));
        pixels.show(); // Show results
        increment = 0;
        decrement = 0;
        //delay(10);
      }
      
  if (decrement == 1) {
        Consumer.write(MEDIA_VOLUME_DOWN);
        if (LEDLight == 0) LEDLight = 3;
        else if (LEDLight > 0) LEDLight -= 1;
        pixels.clear();
        pixels.setPixelColor(LEDCircle[LEDLight], pixels.Color(10, 0, 0));
        pixels.show(); // Show results
        increment = 0;
        decrement = 0;
        //delay(10);
      }
  if (SW6 == 0){ //tab to next browser tab Firefox or Chrome
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press(KEY_TAB);          
        Keyboard.releaseAll();
        delay(50);
      }
  if (SW5 == 0){ //tab to previous browser tab Firefox or Chrome
        Keyboard.press(KEY_LEFT_SHIFT);
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press(KEY_TAB);
        Keyboard.releaseAll();
        delay(50);
      }
  if (SW4 == 0) {
        Consumer.write(MEDIA_PLAY_PAUSE); 
        delay(100);
      }
  if (SW3 == 0) {
        Consumer.write(MEDIA_NEXT);
        delay(50);
      }
  if (SW2 == 0) {
        Consumer.write(MEDIA_PREVIOUS);
        delay(50);
      }
}

void jiggler(){
  Serial.print("commence to jiggling");
      //Consumer.write(MEDIA_VOLUME_UP);
      //Consumer.write(MEDIA_VOLUME_DOWN);
      randNumber = random(-50, 50);
      randNumber1 = random(-50, 50);
      Mouse.move(randNumber, randNumber1);
      delay(200);
}
