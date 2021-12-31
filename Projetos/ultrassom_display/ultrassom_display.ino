#include <Adafruit_GFX.h>       // Include core graphics library for the display
#include <Adafruit_SSD1306.h>   // Include Adafruit_SSD1306 library to drive the display
#include <Fonts/FreeMonoBold18pt7b.h>  // Add a custom font
Adafruit_SSD1306 display(128, 64);            //Create display

#include <NewPing.h>

#define TRIGGER_PIN  11  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     12  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup()
{                
  delay(100);  // This delay is needed to let the display to initialize
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // Initialize display with the I2C address of 0x3C
  display.clearDisplay();  // Clear the buffer
  display.setTextColor(WHITE);  // Set color of the text

Serial.begin(9600);
}
void loop(){
  display.clearDisplay();  // Clear the display so we can refresh

  // Print text:

  display.setFont(&FreeMonoBold18pt7b);  // Set a custom font
  display.setCursor(2,30);  // (x,y)
  display.print(sonar.ping_cm());  // Text or value to print
  display.println("cm");
  display.display();  // Print everything we set previously
  delay(500);
 
  
  
 
}
