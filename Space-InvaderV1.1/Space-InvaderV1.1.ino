#include "Classes.h"
#include "Function.h"
#include "Variable.h"

// https://www.meccanismocomplesso.org/en/lcd1602-using-a-liquid-crystal-display-lcd-with-arduino-via-i2c/?msclkid=3800ee44b57e11ecae1c9bb74c7e21fb ( LiquidCrystal_I2C beispielcode mit Contrtoller)
// https://www.arduino.cc/reference/en/libraries/liquidcrystal-i2c/?msclkid=92be2c81b58411ecb6ae3d2d7f275e17( Richtige Library)

// Zeilen können auch mit dem befehl char row1[] oder row2[] angesteuert werden
// Library initialization with 16x2 size settings

//Controller(String label, int stickPinX, int stickPinY, int stickButton, int buttonA)
//Tower(String id, byte control, int score, byte Dir)
Gameobject p1("Player 1", 1, 0, 0, 0, 0, XPIN, YPIN, SWPIN);
//Gameobject p2("Player 2", 2, 0, 0, 0, 0);


void setup() {

  Serial.begin(9600);
  /*
    driver.pdn_disable(1);              // Use PDN/UART pin for communication
    driver.I_scale_analog(0);           // Adjust current from the registers
    driver.rms_current(600);            // Set driver current 500mA
    driver.toff(0x2);                   // Enable driver
  */
  //button.setDebounceTime(7);
  pinMode(EN_PIN_PAN, OUTPUT);
  pinMode(STEP_PIN_PAN, OUTPUT);
  pinMode(EN_PIN_TILT, OUTPUT);
  pinMode(STEP_PIN_TILT, OUTPUT);

  pinMode(XPIN, INPUT);
  pinMode(YPIN, INPUT);
  pinMode(SWPIN, INPUT);
  // lcd.init();
  // lcd.backlight();
  Serial.println("Wake UP");
  digitalWrite(EN_PIN_PAN, LOW);

}
void loop() {
  Serial.println("Wake UP");
  //mainmenu(&p1);
  gametime = millis();

  gametime = gametime - systime ;
  // p1.update();
  p1.motion();
  p1.getStick();
  /* while(start = true&& gametime< 9000){
    }
  */

   button.loop();
   buttonState = button.getState();
  


}
