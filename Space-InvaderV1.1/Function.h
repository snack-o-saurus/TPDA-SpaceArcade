#include "Classes.h"
#include "Variable.h"

/*
void mainmenu(Gameobject * object) {

  while (!start) {
    switch (object -> _Dir) {
      case LEFT:
        lcd.setCursor(1, 1);
        lcd.print("[PvP]   Score");
        if (button.isPressed()) {
          start = true;
          solo = true;          //abfrage ob solo true ist
          lcd.clear();
          break;
          //initiate Verus-MOD
        }
      case RIGHT:
        lcd.setCursor(2, 1);
        lcd.print(String("PvP   [Score]"));
        if (button.isPressed()) {
          start = true;
          lcd.clear();
          break;
          //initiate Solo-MOD
        }
      default:
        lcd.clear();
        lcd.setCursor(4, 0);
        lcd.print("Mainmenu");
        lcd.setCursor(2, 1);
        lcd.print("PvP    Score");
        delay(1200);
        break;
    }
  }
}
*/

/*
  void testStick() {

  Serial.println(xPos);
  if (button.isPressed()) {
    Serial.println("The button is pressed");
    digitalWrite(3, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(9, HIGH);
  }
  else if (button.isReleased()) {
    Serial.println("The button is released");
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(9, LOW);
  }
  else if (xPos < -10) {
    digitalWrite(3, HIGH);
  }
  else if (xPos > 10) {
    digitalWrite(5, HIGH);
  }
  else if (yPos < -10) {
    digitalWrite(6, HIGH);
  }
  else if (yPos > 10) {
    digitalWrite(9, HIGH);
  }
  else {
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(9, LOW);
  }


  Serial.print("x = ");
  Serial.print(xPos);
  Serial.print(", y = ");
  Serial.println(yPos);
  Serial.print("button: ");
  Serial.println(buttonState);
  delay(500);
  }
*/

void singleplayer() {



}
