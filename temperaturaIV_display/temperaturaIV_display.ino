#include <Wire.h>
#include <Adafruit_MLX90614.h>
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
#include <Adafruit_GFX.h>       // Include core graphics library for the display
#include <Adafruit_SSD1306.h>   // Include Adafruit_SSD1306 library to drive the display

#include <Fonts/FreeMonoBold12pt7b.h>  // Add a custom font
Adafruit_SSD1306 display(128, 64);            //Create display

void setup() {
  Serial.begin(9600);
  delay(100);  // This delay is needed to let the display to initialize
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // Initialize display with the I2C address of 0x3C
  display.clearDisplay();  // Clear the buffer
  display.setTextColor(WHITE);  // Set color of the text  
  mlx.begin();  
}
void loop() {
  display.setFont();
  display.clearDisplay();  // Clear the display so we can refresh
  display.setCursor(45,1);  // (x,y)
  display.println("AMBIENTE");  // Text or value to print

  display.setCursor(50,34);  // (x,y)
  display.println("OBJETO");  // Text or value to print
  
  // Print temperature
  char string[10];  // Create a character array of 10 characters
  // Convert float to a string:
  dtostrf(mlx.readAmbientTempC(), 3, 1, string);

  display.setFont(&FreeMonoBold12pt7b);  // Set a custom font
  display.setCursor(35,25);  // (x,y)
  display.println(mlx.readAmbientTempC()-6.5);  // Text or value to print

  display.setFont(&FreeMonoBold12pt7b);  // Set a custom font
  display.setCursor(35,61);  // (x,y)
  display.println(mlx.readObjectTempC()+7.4);  // Text or value to print
  
  Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempC()-6.5); 
  Serial.print("*C\tObject = "); Serial.print(mlx.readObjectTempC()+7.4); Serial.println("*C");
  //Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempF()); 
  //Serial.print("*F\tObject = "); Serial.print(mlx.readObjectTempF()); Serial.println("*F");
  Serial.println();

  display.display();  // Print everything we set previously
  
  delay(5000);
}
