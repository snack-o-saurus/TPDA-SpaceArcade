#ifndef CLASSES_H
#define CLASSES_H
#include "libraries.h"
#include "Variable.h"

#define SWPIN 2
#define XPIN A0
#define YPIN A1


#define STEP_PIN_PAN  10        // Step on rising edge
#define EN_PIN_PAN    13         // LOW = enable driver  / HIGH = disable driver
#define DIR_PIN_PAN   11

#define STEP_PIN_TILT  6        // Step on rising edge
#define EN_PIN_TILT    7        // LOW = enable driver  / HIGH = disable driver
#define DIR_PIN_TILT   5
#define SERVO_PIN      9
#define BUTTON_PIN     4


ezButton button(BUTTON_PIN);
TMC2208Stepper driver = TMC2208Stepper(&Serial);  // Create driver and use
LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27
Servo servo; 

class target {
private: int _tcount;
         bool _tid = false;
  
public: int _tscore;
        int _targetid;
  
  target(int tcount, bool tid, int targetid){
    setTcount(tcount);
    setTid(tid);
    settargetid(targetid);
    
   
    
    
    
  }
};

class Gameobject {

  private:
    byte _control;
  public:
    int _score;
    String _id;
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
        Serial.println("UP");
          digitalWrite(DIR_PIN_TILT, HIGH);
          analogWrite(STEP_PIN_TILT, 127);
          //digitalWrite(STEP_PIN_TILT, HIGH);
          delay(50);
          break;
          
        case DOWN:
        Serial.println("DOWN");
          digitalWrite(DIR_PIN_TILT, LOW);
          analogWrite(STEP_PIN_TILT, 127);
          //digitalWrite(STEP_PIN_TILT, HIGH);
          delay(50);
          break;
          
        default:
        //Serial.println("STOP");
          digitalWrite(STEP_PIN_TILT, LOW);
          digitalWrite(STEP_PIN_PAN, LOW);
          break;
      }
    }



    
};

#endif
