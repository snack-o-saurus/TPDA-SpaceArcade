#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include "Classes.h"
#include "Function.h"

//https://www.meccanismocomplesso.org/en/lcd1602-using-a-liquid-crystal-display-lcd-with-arduino-via-i2c/?msclkid=3800ee44b57e11ecae1c9bb74c7e21fb ( LiquidCrystal_I2C beispielcode mit Contrtoller)
// https://www.arduino.cc/reference/en/libraries/liquidcrystal-i2c/?msclkid=92be2c81b58411ecb6ae3d2d7f275e17( Richtige Library)
//zeilen können auch mit dem befehl char row1[] oder row2[] angesteuert werden

int t = 500;
// Library initialization with 16x2 size settings
Tower p1("Player 1", 1, 0, 0);
Tower p2("Player 2", 2, 0, 0);


void setup() {
  pinMode(YPIN, INPUT);
  pinMode(GSM1, OUTPUT);      //Motor PAN
  pinMode(PAN_LEFT, OUTPUT);  //Motor  links
  pinMode(PAN_RIGHT, OUTPUT); //Motor rechts
  pinMode(GSM2, OUTPUT);      //Motor PAN
  pinMode(TILT_UP, OUTPUT);   // Motor oben
  pinMode(TILT_DOWN, OUTPUT); // Motor unten

  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);

  Serial.begin(9600);
  button.setDebounceTime(15);
  pinMode(XPIN, INPUT);
  lcd.init();
  lcd.backlight();
}


void loop() {
  button.loop();
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
  Serial.print("x = ");
  Serial.print(xval);
  Serial.print(", y = ");
  Serial.println(yval);
  Serial.print("button: ");
  Serial.println(buttonState);
  delay(100);
}
