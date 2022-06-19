#include "Classes.h"
#include "Function.h"
#include "Variable.h"

// https://www.meccanismocomplesso.org/en/lcd1602-using-a-liquid-crystal-display-lcd-with-arduino-via-i2c/?msclkid=3800ee44b57e11ecae1c9bb74c7e21fb ( LiquidCrystal_I2C beispielcode mit Contrtoller)
// https://www.arduino.cc/reference/en/libraries/liquidcrystal-i2c/?msclkid=92be2c81b58411ecb6ae3d2d7f275e17( Richtige Library)

// Zeilen können auch mit dem befehl char row1[] oder row2[] angesteuert werden
// Library initialization with 16x2 size settings

//Controller(String label, int stickPinX, int stickPinY, int stickButton, int buttonA)
// target(int thealth, int  tvalue, bool talive, int tscore, int targetid, int trank) 
Gameobject p1("Player 1", 1, 0, 0, 0, 0, XPIN_P1, YPIN_P1, SWPIN_P1);
Gameobject p2("Player 2", 2, 0, 0, 0, 0, XPIN_P2, YPIN_P2, SWPIN_P2);    // Stickbelegung für Player 2 festlegen
//target Alien(2,0,true,3,PINT1,MIDDLE);


void setup() {
  Serial.begin(9600);
  pinMode(EN_PIN_PAN, OUTPUT);
  pinMode(STEP_PIN_PAN, OUTPUT);
  pinMode(EN_PIN_TILT, OUTPUT);
  pinMode(STEP_PIN_TILT, OUTPUT);

  pinMode(XPIN_P1,  INPUT);
  pinMode(YPIN_P1,  INPUT);
  pinMode(SWPIN_P1, INPUT);
  /*
  pinMode(XPIN_P2,  INPUT);
  pinMode(YPIN_P2,  INPUT);
  pinMode(SWPIN_P2, INPUT);
  */
  pinMode(PINT1,INPUT);

  button1.setDebounceTime(100);
  button2.setDebounceTime(100);
 // button3.setDebounceTime(100);
 // button4.setDebounceTime(100);
 
  servo.attach(SERVO_PIN);
  lcd.init();
  lcd.backlight();

  digitalWrite(EN_PIN_PAN, HIGH);
  digitalWrite(EN_PIN_TILT, HIGH);
}
void loop() {

  button1.loop();
  button2.loop();
 // button3.loop();
 // button4.loop();
  button1State = button1.getState();
  button2State = button2.getState();
 // button3State = button3.getState();
 // button4State = button4.getState();

  mainmenu(&p1);
 // mainGame();
// Alien.detectHit();
// Alien.readTvalue();
  p1.getStick();
  p1.motion();
 // p2.getStick();
} 
 

  void mainGame() {
    // read Target feedback(hitzone, dead or alife)
    // count Score & save it
    runtime();
    if (solo == false) {
      if (player == false) {
        p2.getStick();
        p2.motion();
        pullTrigger();
        if (button1.isReleased()) {
          player = true;
        }
      }
      if (player == true) {
        p1.getStick();
        p1.motion();
        pullTrigger();
        if (button2.isReleased()) {
          player = false;
        }
      }
      //start PvP
      //switch controll off turret between p1 & p2
    }
    if (solo == true) {
      enterName(&p1);
      p1.getStick();
      p1.motion();
      pullTrigger();
      //start Countdown
      //start solo
    }
  }
