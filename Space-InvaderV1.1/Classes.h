#ifndef CLASSES_H
#define CLASSES_H

#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <ezButton.h>
#include "Variable.h"

#define SWPIN 2
#define XPIN A0
#define YPIN A1
#define BUTTON 1

#define GSM1      10
#define TILT_UP   9
#define TILT_DOWN 8

#define GSM2      7
#define PAN_LEFT  6
#define PAN_RIGHT 5


ezButton button(SWPIN);
LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27



class User {
  private:
    String _id;
    byte _control;
    int _score;

  public:
    User(String id, byte control, int score) {
      setName(id);
      setControl(control);
      setScore(score);
    }

    //Setter
    void setName(String id) {
      _id = id;
    }
    void setControl(byte control) {
      _control = control;
    }
    void setScore(int score) {
      _score = score;
    }
    //Getter
    String getName() {
      return _id;
    }
    byte getControl() {
      return _control;
    }
    int getScore() {
      return _score;
    }
    //Mainmethods
    getInput() {                          //Name über Display einstellen
      while (i <= 26 && yPos < 0) {       // Eingabeart ist noch nicht klar!!(vielleicht Buchstaben A-Z pro Zeichen durchlaufen und mit Button bestätigen und zur nächsten Stelle springen
        lcd.print( arrayLetters[i]);
        i++;
        delay(2000);
        if (button.isPressed()) {
          j++;
          lcd.setCursor(1, j + 4);
          arrayName[j]= arrayLetters[i];  // Buchstabe muss gespeichert werden! vielleicht in neuem Array? 
          return j;                       // Einzelne Buchstaben des Arrays in id übertragen in einen String
        }
        return i;
        break;
      }
      while (i > 0 && yPos >= 0) {
        lcd.print( arrayLetters[i]);
        i--;
        delay(1000);
        if (button.isPressed()) {
          j++;
          lcd.setCursor(1, j + 4);
          arrayName[j]= arrayLetters[i];  // Buchstabe muss gespeichert werden! vielleicht in neuem Array?
          return j;                       // Einzelne Buchstaben des Arrays in id übertragen in einen String
        }
        return i;
        break;



      }
    }
};

class Tower : public User {
  private:
    byte _Dir;
    //bool _yDir;
  public:
    Tower(String id, byte control, int score, byte Dir /*,  bool yDir*/): User(id, control, score) {
      setDir(Dir);
      //setY(yDir);
    }
    //Setter
    setDir( byte Dir) {
      _Dir = Dir;
    }
    /* setY(bool yDir) {
       _yDir = yDir;
      }
    */
    //Getter
    getDir() {
      return _Dir;
    }
    /* getY() {
       return _yDir;
      }
    */
    //Mainmethods
    void getMotion() {
      xval = analogRead(XPIN);  // 0 = OBEN   1023 = UNTEN
      yval = analogRead(YPIN);  // 0 = LINKS  1023 = RECHTS

      if (xPos < 0) {         // Aussteuerung nach links
        _Dir = LEFT;
      }
      else if (xPos > 0) {    // Aussteuerung nach rechts
        _Dir = RIGHT;
      }
      if (yPos < 0) {         // Aussteuerung nach oben
        _Dir = UP;
      }
      else if (yPos > 0) {    // Aussteuerung nach unten
        _Dir = DOWN;
      }
    }

    void motion() {
      switch (_Dir) {
        case LEFT:
          digitalWrite(PAN_LEFT, HIGH);
          digitalWrite(PAN_RIGHT, LOW);
          delay(1000);
          break;

        case RIGHT:
          digitalWrite(PAN_LEFT, LOW);
          digitalWrite(PAN_RIGHT, HIGH);
          delay(1000);
          break;

        case UP:
          digitalWrite(TILT_UP, HIGH);
          digitalWrite(TILT_DOWN, LOW);
          delay(1000);
          break;
        case DOWN:
          digitalWrite(TILT_UP, LOW);
          digitalWrite(TILT_DOWN, HIGH);
          delay(1000);
          break;
      }
    }

};
class Controller {
  protected:
    String _label;
    int _stickPinX;
    int _stickPinY;
    int _stickButton;
    int _buttonA;
  public:
    Controller(String label, int stickPinX, int stickPinY, int stickButton, int buttonA) {
      setLabel(label);
      setStickX(stickPinX);
      setStickY(stickPinY);

    }
    //Setter
    void setLabel(String label) {
      _label = label;
    }
    void setStickX(int stickPinX) {
      _stickPinX = stickPinX;
    }
    void setStickY(int stickPinY) {
      _stickPinY = stickPinY;
    }
    void setStickButton(int stickButton) {
      _stickButton = stickButton;
    }
    void setButtonA(int buttonA) {
      _buttonA = buttonA;
    }
    //Getter
    String getLabel() {
      return _label;
    }
    int getStickX() {
      return _stickPinX;
    }
    int getStickY() {
      return _stickPinY;
    }
    int getStickButton() {
      return _stickButton;
    }
    int getButtonA() {
      return _buttonA;
    }

    //Mainmethods

};




#endif
