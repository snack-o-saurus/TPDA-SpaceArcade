#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include "Classes.h"
#include "Function.h"
#include "Variable.h"

//https://www.meccanismocomplesso.org/en/lcd1602-using-a-liquid-crystal-display-lcd-with-arduino-via-i2c/?msclkid=3800ee44b57e11ecae1c9bb74c7e21fb ( LiquidCrystal_I2C beispielcode mit Contrtoller)
// https://www.arduino.cc/reference/en/libraries/liquidcrystal-i2c/?msclkid=92be2c81b58411ecb6ae3d2d7f275e17( Richtige Library)

//Zeilen können auch mit dem befehl char row1[] oder row2[] angesteuert werden
// Library initialization with 16x2 size settings

//Controller(String label, int stickPinX, int stickPinY, int stickButton, int buttonA)
//Tower(String id, byte control, int score, byte Dir /*,  bool yDir*/)
Controller controller("Left Player",XPIN,YPIN,SWPIN,BUTTON);
Tower p1("Player 1", 1, 0, 0);
Tower p2("Player 2", 2, 0, 0);



void setup() {

  start:
  millis()=0;
  pinMode(XPIN, INPUT);
  pinMode(YPIN, INPUT);
  pinMode(SWPIN,INPUT);
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
  
  lcd.init();
  lcd.backlight();
  mainmenu();     //Start game 
 goto start;
  
}

void loop() {
  button.loop();
  testStick();     
 
}
