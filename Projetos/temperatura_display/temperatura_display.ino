#include <Adafruit_GFX.h>       // Include core graphics library for the display
#include <Adafruit_SSD1306.h>   // Include Adafruit_SSD1306 library to drive the display
#include <Fonts/FreeMonoBold18pt7b.h>  // Add a custom font
#define LED 13
Adafruit_SSD1306 display(128, 64);            //Create display

int temp;  // Create a variable to have something dynamic to show on the display

void setup()
{                
  delay(100);  // This delay is needed to let the display to initialize
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // Initialize display with the I2C address of 0x3C
  display.clearDisplay();  // Clear the buffer
  display.setTextColor(WHITE);  // Set color of the text
// LED Indicativo
pinMode(LED, OUTPUT);

  //Temperatura config
unsigned long delayEnvio;
int ThermistorPin = 0;
int Vo;
float R1 = 10000;
float logR2, R2, T;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;
}

void loop()
{
digitalWrite(LED, HIGH);
    //Temperatura config
unsigned long delayEnvio;
int ThermistorPin = 0;
int Vo;
float R1 = 10000;
float logR2, R2, T;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;
    //dado temperatura

  Vo = analogRead(ThermistorPin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  T = T - 273.1;

  display.clearDisplay();  // Clear the display so we can refresh

  // Print text:
  display.setFont();
  display.setCursor(45,10);  // (x,y)
  display.println("TEMPERATURA");  // Text or value to print

  // Print temperature
  char string[10];  // Create a character array of 10 characters
  // Convert float to a string:
  dtostrf(T, 3, 1, string);  // (<variable>,<amount of digits we are going to use>,<amount of decimal digits>,<string name>)
  
  display.setFont(&FreeMonoBold18pt7b);  // Set a custom font
  display.setCursor(18,45);  // (x,y)
  display.println(string);  // Text or value to print
  display.setCursor(108,45);  // (x,y)
  display.println("C");  // Text or value to print
  display.setCursor(95,27);  // (x,y)
  display.println(".");  // Text or value to print
  
  // Draw a filled circle:
  display.fillCircle(10, 55, 7, WHITE);  // Draw filled circle (x,y,radius,color). X and Y are the coordinates for the center point

  // Draw rounded rectangle:
  display.drawRoundRect(8, 3, 5, 49, 2, WHITE);  // Draw rounded rectangle (x,y,width,height,radius,color)
                                                  // It draws from the location to down-right
    // Draw ruler step
  for (int i = 6; i<=45; i=i+3){
    display.drawLine(13, i, 15, i, WHITE);  // Draw line (x0,y0,x1,y1,color)
  }
  
  //Draw temperature
  T = T*0.43; //ratio for show
  display.drawLine(10, 46, 10, 46-T, WHITE);  // Draw line (x0,y0,x1,y1,color)

  display.display();  // Print everything we set previously
  delay(5000);
}
