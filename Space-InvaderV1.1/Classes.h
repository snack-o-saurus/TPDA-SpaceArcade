#ifndef CLASSES_H
#define CLASSES_H
#include <TMC2208Stepper.h>
//#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <ezButton.h>
#include "Variable.h"

#define SWPIN 2
#define XPIN A0
#define YPIN A1


#define STEP_PIN_PAN  10        // Step on rising edge
#define EN_PIN_PAN    13         // LOW = enable driver  / HIGH = disable driver
#define DIR_PIN_PAN   11
#define STEP_PIN_TILT  10        // Step on rising edge
#define EN_PIN_TILT    9        // LOW = enable driver  / HIGH = disable driver
#define DIR_PIN_TILT   8


ezButton button(SWPIN);
TMC2208Stepper driver = TMC2208Stepper(&Serial);  // Create driver and use
//LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27

class Gameobject {

  private:
    String _id;
    byte _control;
    int _score;



  public:
    byte _Dir;
    int _xPos;
    int _yPos;
    int _xPin;
    int _yPin;
    byte _swPin;
    Gameobject(String id, byte control, int score, byte Dir, int xPos, int yPos, int xPin, int yPin, byte swPin) {

      setId(id);
      setControl(control);
      setScore(score);
      setDir(Dir);
      motion();
      getStick();
      setX(xPos);
      setY(yPos);
      setXpin(xPin);
      setYpin(yPin);
      setSWpin(swPin);
    }

    //Setter
    void setId(String id) {
      _id = id;
      /*
      for (byte z = 0; z <= 8; z++) {
        lcd.print( tempId + arrayLetters[i]);
        for (i = 0; i <= 25 && _Dir == DOWN; i++) {
          lcd.setCursor(1, 3);                            // Eingabeart ist noch nicht klar!!(vielleicht Buchstaben A-Z pro Zeichen durchlaufen und mit Button bestätigen und zur nächsten Stelle springen

          delay(500);
          if (button.isPressed()) {
            lcd.clear();
            j++;
            lcd.setCursor(1, 3);
            tempName[j] = arrayLetters[i];
            lcd.print( tempId + arrayLetters[i]);
            // Einzelne Buchstaben des Arrays in id übertragen in einen String
          }
          return  j;
          break;
        }
        tempId = tempId + tempName[z];
        
      }
      */
      _id = tempId;
    }
    void setControl(byte control) {
      _control = control;
    }
    void setScore(int score) {
      _score = score;
    }
    void setDir( byte Dir) {
      _Dir = Dir;
    }
    void setX(int xPos) {
      _xPos = xPos;
    }
    void setY(int yPos) {
      _yPos = yPos;
    }
    void setXpin(int xPin) {
      _xPin = xPin;
    }
    void setYpin(int yPin) {
      _yPin = yPin;
    }
    void setSWpin(byte swPin) {
      _swPin = swPin;
    }
    //Getter
    String getId() {
      return _id;
    }
    byte getControl() {
      return _control;
    }
    int getScore() {
      return _score;
    }
    int getDir() {
      return _Dir;
    }
    int getX() {
      return _xPos;
    }
    int getY() {
      return _yPos;
    }
    int getXpin() {
      return _xPin;
    }
    int getYpin() {
      return _yPin;
    }
    byte getSWpin() {
      return _swPin;
    }
    //Mainmethods

    void getStick() {
      yStick = analogRead(_yPin);               // 0 = LINKS  1023 = RECHTS
      _yPos = map(yStick, 0, 1023, -100, 100);
      xStick = analogRead(_xPin);               // 0 = OBEN   1023 = UNTEN
      _xPos = map(xStick, 0, 1023, -100, 100);

      if (_yPos < -20) {         // Aussteuerung nach oben
        _Dir = UP;
      }
      else if (_yPos > 20) {    // Aussteuerung nach unten
        _Dir = DOWN;
      }
      else if (_xPos < -20) {         // Aussteuerung nach links
        _Dir = LEFT;
      }
      else if (_xPos > 20) {    // Aussteuerung nach rechts
        _Dir = RIGHT;
      }
      else{
        _Dir = 0;
      }

    }
    void motion() {
      switch (_Dir) {
        case LEFT:
          Serial.println("LEFT");
          digitalWrite(DIR_PIN_PAN, HIGH);
          analogWrite(STEP_PIN_PAN, 127);
          //digitalWrite(STEP_PIN_PAN, HIGH);
          delay(50);
          break;

        case RIGHT:
          Serial.println("RIGHT");
          digitalWrite(DIR_PIN_PAN, LOW);
          analogWrite(STEP_PIN_PAN, 127);
          //digitalWrite(STEP_PIN_PAN, HIGH);
          delay(50);
          break;

        case UP:
          digitalWrite(DIR_PIN_TILT, HIGH);
          analogWrite(STEP_PIN_TILT, 127);
          //digitalWrite(STEP_PIN_TILT, HIGH);
          delay(50);
          break;
          
        case DOWN:
          digitalWrite(DIR_PIN_TILT, LOW);
          analogWrite(STEP_PIN_TILT, 127);
          //digitalWrite(STEP_PIN_TILT, HIGH);
          delay(50);
          break;
          
        default:
          digitalWrite(STEP_PIN_TILT, LOW);
          digitalWrite(STEP_PIN_PAN, LOW);
          break;
      }
    }
};

#endif
