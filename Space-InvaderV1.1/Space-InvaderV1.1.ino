#include "Classes.h"
#include "Function.h"
#include "Variable.h"

// https://www.meccanismocomplesso.org/en/lcd1602-using-a-liquid-crystal-display-lcd-with-arduino-via-i2c/?msclkid=3800ee44b57e11ecae1c9bb74c7e21fb ( LiquidCrystal_I2C beispielcode mit Contrtoller)
// https://www.arduino.cc/reference/en/libraries/liquidcrystal-i2c/?msclkid=92be2c81b58411ecb6ae3d2d7f275e17( Richtige Library)

// Zeilen können auch mit dem befehl char row1[] oder row2[] angesteuert werden
// Library initialization with 16x2 size settings

//Controller(String label, int stickPinX, int stickPinY, int stickButton, int buttonA)
//Tower(String id, byte control, int score, byte Dir)
Gameobject p1("Player 1", 1, 0, 0, 0, 0, XPIN_P1, YPIN_P1, SWPIN_P1);
Gameobject p2("Player 2", 2, 0, 0, 0, 0, XPIN_P2, YPIN_P2, SWPIN_P2);    // Stickbelegung für Player 2 festlegen



void setup() {
  Serial.begin(9600);
 
  pinMode(EN_PIN_PAN, OUTPUT);
  pinMode(STEP_PIN_PAN, OUTPUT);
  pinMode(EN_PIN_TILT, OUTPUT);
  pinMode(STEP_PIN_TILT, OUTPUT);

  pinMode(XPIN_P1,  INPUT);
  pinMode(YPIN_P1,  INPUT);
  pinMode(SWPIN_P1, INPUT);
  pinMode(XPIN_P2,  INPUT);
  pinMode(YPIN_P2,  INPUT);
  pinMode(SWPIN_P2, INPUT);

  button.setDebounceTime(100);
  servo.attach(SERVO_PIN);
  lcd.init();
  lcd.backlight();
  
  digitalWrite(EN_PIN_PAN, HIGH);
  digitalWrite(EN_PIN_TILT, HIGH);
}
void loop() {
  button.loop();
  buttonState = button.getState();
  mainmenu(&p1);
  runtime();
  if ()
  p1.motion();
  p2.motion();
  p1.getStick();
  p2.getStick();
  if(solo==true){
    enterName(&p1);
  }
  pullTrigger();

  if (button.isReleased()){
    
  }
  





}
