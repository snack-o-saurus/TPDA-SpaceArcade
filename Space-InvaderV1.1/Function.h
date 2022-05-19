#include "Classes.h"
#include "Variable.h"


void mainmenu() {
  while (!start) {
    lcd.clear();
    lcd.setCursor(4, 0); // set the cursor to column 4, line 0
    lcd.print(String("Mainmenu"));
    lcd.setCursor(2, 1);
    lcd.print(String("PvP    Score"));
    delay(1000);
    if (xval < 0) {
      lcd.clear();
      lcd.print(String("[PvP]    Score"));
      if (button.isPressed()) {
        start = true;
        //initiate Verus-MOD
      }
    }
    if (xval > 0) {
      lcd.clear();
      lcd.print(String("PvP    [Score]"));
      if (button.isPressed()) {
        start = true;
        //initiate Solo-MOD
      }
    }
  }
}
void testStick() {
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
