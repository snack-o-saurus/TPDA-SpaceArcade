#include <LiquidCrystal_I2C.h>
#include <Wire.h>

//https://www.meccanismocomplesso.org/en/lcd1602-using-a-liquid-crystal-display-lcd-with-arduino-via-i2c/?msclkid=3800ee44b57e11ecae1c9bb74c7e21fb ( LiquidCrystal_I2C beispielcode mit Contrtoller)
// https://www.arduino.cc/reference/en/libraries/liquidcrystal-i2c/?msclkid=92be2c81b58411ecb6ae3d2d7f275e17( Richtige Library)

char row1[]="Hallo DU ";
char row2[]="Hello world!"; 
int t = 500;
// Library initialization with 16x2 size settings
LiquidCrystal_I2C lcd(0x27,16,2); // set the LCD address to 0x27

void setup(){
   lcd.init();
   lcd.backlight();
}

void loop()
{
    lcd.clear();
    lcd.setCursor(15,0);
    for (int positionCounter1 = 0; positionCounter1 < 26; positionCounter1++){
        lcd.scrollDisplayLeft(); 
        lcd.print(row1[positionCounter1]); 
        delay(t); 
    }
    lcd.setCursor(15,1); // set the cursor to column 15, line 1
    for (int positionCounter = 0; positionCounter < 26; positionCounter++){
        lcd.scrollDisplayLeft(); 
        lcd.print(row2[positionCounter]); 
        delay(t); 
    }
 }
