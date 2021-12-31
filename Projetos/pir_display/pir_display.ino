#include <Adafruit_GFX.h>       // Include core graphics library for the display
#include <Adafruit_SSD1306.h>   // Include Adafruit_SSD1306 library to drive the display
#include <Fonts/FreeMonoBold9pt7b.h>  // Add a custom font
#define pinPIR 7
Adafruit_SSD1306 display(128, 64);            //Create display

void setup()
{                
  delay(100);  // This delay is needed to let the display to initialize
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // Initialize display with the I2C address of 0x3C
  display.clearDisplay();  // Clear the buffer
  display.setTextColor(WHITE);  // Set color of the text

  pinMode(pinPIR, INPUT);
  Serial.begin(9600);
}

void loop(){
  display.clearDisplay();  // Clear the display so we can refresh
  bool valorPIR = digitalRead(pinPIR);
  
  // Print text:
  if (valorPIR) {
    display.setFont(&FreeMonoBold9pt7b);  // Set a custom font
    display.setCursor(2,10);  // (x,y)
    display.println("Detectado");  // Text or value to print
    display.display();  // Print everything we set previously
    delay(1);
  } else{
    display.setFont(&FreeMonoBold9pt7b);  // Set a custom font
    display.setCursor(2,10);  // (x,y)
    display.println("----");  // Text or value to print
    display.display();  // Print everything we set previously
    delay(1);
  }  
}
