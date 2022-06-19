#include "Classes.h"
#include "Variable.h"

void mainmenu(Gameobject * object) {
  if (!start) {
    object->getStick();
    switch (object -> _Dir) {
      case LEFT:
        lcd.setCursor(0, 0);
        lcd.print("-Press RED Button-");
        lcd.setCursor(1, 1);
        lcd.print("[PvP]   Solo");
        if (button1.isPressed()) {             //initiate Verus-MOD
          lcd.clear();
          digitalWrite(EN_PIN_PAN, LOW);
          digitalWrite(EN_PIN_TILT, LOW);
          Serial.println("Button pressed");
          start = true;
          menutime = millis();
          return menutime;
        }
        break;
      case RIGHT:
        lcd.setCursor(0, 0);
        lcd.print("-Press RED Button-");
        lcd.setCursor(2, 1);
        lcd.print(String("PvP   [Solo]"));
        if (button1.isPressed()) {            //initiate Solo-MOD
          lcd.clear();
          Serial.println("Button pressed");
          digitalWrite(EN_PIN_PAN, LOW);
          digitalWrite(EN_PIN_TILT, LOW);
          start = true;
          solo = true;          //abfrage ob solo true ist muss noch gebaut werden
          menutime = millis();
          return menutime;
        }
        break;
      default:
        lcd.clear();
        lcd.setCursor(4, 0);
        lcd.print("Mainmenu");
        lcd.setCursor(2, 1);
        lcd.print("PvP    Solo");
        delay(50);
        break;
    }
  }
}
void runtime() {
  if (start) {
    uint32_t playtime = millis();
    Serial.println("InGame-Time: ");
    Serial.println((playtime - menutime) / 1000);
  }
}
void pullTrigger() {
  if (button1.isPressed() || button2.isPressed()) {
    Serial.println(button1State);
    Serial.println(button2State);
    servo.write(180);
    delay(300);
    servo.write(90);
  }
}
/*
  void singleplayer() {
  // all functions explicitly for singleplayer belong here
  }
  void multiplayer() {
  // all functions explicitly for multiplayer belong here
  }
*/



void enterName(Gameobject * object) {
  lcd.setCursor(0,0);
  lcd.print("Enter your Name");
  for (i = 0; i <= 25 && object-> _Dir == DOWN; i++) {
    lcd.setCursor(1, 3 + j);                            // Eingabeart ist noch nicht klar!!(vielleicht Buchstaben A-Z pro Zeichen durchlaufen und mit Button bestätigen und zur nächsten Stelle springen
    lcd.print(arrayLetters[i]);
    delay(2000);

    if (button1.isPressed()) {
      tempName[j] = arrayLetters[i];                    // Einzelne Buchstaben des Arrays in id übertragen in einen String speichern
      // lcd.print(arrayLetters[i]);
      j++;
      return j;
      break;
    }
    if (j == 8) {
      lcd.setCursor(2, 1);
      lcd.print("Saving ID...");
      for (z = 0; z <= 8; z++) {
        object -> _id = object-> _id + tempName[z];

      }
    }
    if (i == 25) {
      i = 0;
    }
  }

}
