#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <ezButton.h>
int xval = 0;
int yval = 0;
#define SWPIN 2
#define XPIN A0
#define YPIN A1
ezButton button(SWPIN);
int buttonState = 0;

//https://www.meccanismocomplesso.org/en/lcd1602-using-a-liquid-crystal-display-lcd-with-arduino-via-i2c/?msclkid=3800ee44b57e11ecae1c9bb74c7e21fb ( LiquidCrystal_I2C beispielcode mit Contrtoller)
// https://www.arduino.cc/reference/en/libraries/liquidcrystal-i2c/?msclkid=92be2c81b58411ecb6ae3d2d7f275e17( Richtige Library)
//zeilen können auch mit dem befehl char row1[] oder row2[] angesteuert werden

int t = 500;
// Library initialization with 16x2 size settings
LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27

void setup() {
  Serial.begin(9600);
  button.setDebounceTime(15);
  pinMode(XPIN, INPUT);
  pinMode(YPIN, INPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  lcd.init();
  lcd.backlight();
}

void loop(){
  button.loop(); 
  lcd.clear();
  xval = analogRead(XPIN);  // 0 = OBEN   1023 = UNTEN
  yval = analogRead(YPIN);  // 0 = LINKS  1023 = RECHTS
  buttonState = button.getState();

   if (button.isPressed()) {
    Serial.println("The button is pressed");
    digitalWrite(3, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(9, HIGH);
  }
  if (button.isReleased()) {
    Serial.println("The button is released");
     digitalWrite(3, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(9, LOW);
  }

  lcd.setCursor(4, 0); // set the cursor to column 15, line 1
  lcd.print(String("Mainmenu"));
  lcd.setCursor(2, 1);
  lcd.print(String("PvP    Score"));
  delay(t);
  
  Serial.print("x = ");
  Serial.print(xval);
  Serial.print(", y = ");
  Serial.println(yval);
  Serial.print("button: ");
  Serial.println(buttonState);
  delay(100);
  }
/*
   else {
    xval = analogRead(XPIN);
    yval = analogRead(YPIN);
    Serial.println(xval);
    Serial.println(yval);


    analogWrite(3, HIGH);
    analogWrite(5, HIGH);
    analogWrite(6, HIGH);
    analogWrite(9, HIGH);
    } */

}
