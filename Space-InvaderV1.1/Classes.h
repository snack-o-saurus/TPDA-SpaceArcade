#ifndef CLASSES_H
#define CLASSES_H
#include "libraries.h"
#include "Variable.h"

#define SWPIN_P1 15
#define XPIN_P1 A0
#define YPIN_P1 A1

#define SWPIN_P2 14
#define XPIN_P2 A2
#define YPIN_P2 A3

/* Target recognition */
#define PINT1     A4
#define PINT2     A5
#define PINT3     A6
#define PINT4     A7
#define PINT5     A8



#define STEP_PIN_PAN  10        // Step on rising edge
#define EN_PIN_PAN    12         // LOW = enable driver  / HIGH = disable driver
#define DIR_PIN_PAN   11

#define STEP_PIN_TILT  8        // Step on rising edge
#define EN_PIN_TILT    7        // LOW = enable driver  / HIGH = disable driver
#define DIR_PIN_TILT   6

#define SERVO_PIN      9


#define BUTTON1_PIN     1
#define BUTTON2_PIN     2
#define BUTTON3_PIN     3
#define BUTTON4_PIN     4


ezButton button1(BUTTON1_PIN);
ezButton button2(BUTTON2_PIN);
ezButton button3(BUTTON3_PIN);
ezButton button4(BUTTON4_PIN);


TMC2208Stepper driver = TMC2208Stepper(&Serial);  // Create driver and use
LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27
Servo servo;


/*   Implementing object type for targets & score counting      */


class target {
  private:


  public:
    String _tscore;
    int _tvalue;
    int _targetid;
    int _thealth;
    bool _talive = true;
    int _trank;

    target(int thealth, int  tvalue, bool talive, int tscore, int targetid, int trank) {
      setThealth(thealth);
      setTvalue(tvalue);
      setTalive(talive);
      setTargetid(targetid);
      setTrank(trank);
      detectHit();
      readTvalue();

    }

    //   Setter functions
    void setThealth(int thealth) {
      _thealth = thealth;
    }
    void setTvalue(int tvalue) {
      _tvalue = tvalue;
    }
    void setTalive(bool talive) {
      _talive = talive;
      if (_thealth <= 0) {
        _talive = false;
      }
    }
    void setTscore(int tscore) {
      _tscore = tscore;
    }
    void setTargetid(int targetid) {
      _targetid = targetid;
    }
    void setTrank(int trank) {
      _trank = trank;
    }

    //   Getter Functions
    int getThealth() {
      return _thealth;
    }
    int getTvalue() {
      return _tvalue;
    }
    bool getTalive() {
      return _talive;
    }
    int getTid() {
      return _targetid;
    }
    int getTrank() {
      return _trank;
    }
    //    Main Methods
    void detectHit() {
      Serial.println(_tvalue);
      if (_tvalue > 0) {
        _thealth = _thealth - 1;
        switch (_targetid) {
          case HEAVY:
            scoregain = 5;
            lcd.setCursor(0, 0);
            lcd.print("Heavy Target hit");
            if (_thealth > 1) {
              lcd.setCursor(1, 4);
              lcd.print("Try harder!");
            }
            break;
          case MIDDLE:
            scoregain = 3;
            lcd.setCursor(0, 0);
            lcd.print("normal Target hit");
            lcd.setCursor(1, 4 );
            lcd.print("Try harder!");

            break;
          case EASY:
            scoregain = 1;
            lcd.setCursor(0, 0);
            lcd.print("easy Target hit");
            lcd.setCursor(1, 2);
            lcd.print("Almost to easy!");
            break;
          default:
          scoregain = 0;
          break;
        }
      }
    }
    void readTvalue()  {
      _tvalue = analogRead(_targetid);
      Serial.println(_tvalue);
    }
};


class Gameobject {
  public:
    bool _control;
    int _score;
    String _id;
    byte _Dir;
    int _xstick;
    int _ystick;
    int _xPin;
    int _yPin;
    byte _swPin;

    Gameobject(String id, bool control, int score, byte Dir, int xstick, int ystick, int xPin, int yPin, byte swPin) {

      setId(id);
      setControl(control);
      setScore(score);
      setDir(Dir);
      motion();
      getMotion();
      setXstick(xstick);
      setYstick(ystick);
      setXpin(xPin);
      setYpin(yPin);
      setSWpin(swPin);
    }

    //Setter
    void setId(String id) {
      _id = id;
    }
    void setControl(bool control) {
      _control = control;
    }
    void setScore(int score) {
      _score = score;
    }
    void setDir( byte Dir) {
      _Dir = Dir;
    }
    void setXstick(int xstick) {
      _xstick = xstick;
    }
    void setYstick(int ystick) {
      _ystick = ystick;
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
    bool getControl() {
      return _control;
    }
    int getScore() {
      return _score;
    }
    int getDir() {
      return _Dir;
    }
    int getXstick() {
      return _xstick;
    }
    int getYstick() {
      return _ystick;
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

    void getMotion() {
      yStick_P1 = analogRead(_ystick);               // 0 = LINKS  1023 = RECHTS
      yVal_P1 = map(yStick_P1, 0, 1023, -100, 100);
      xStick_P1 = analogRead(XPIN_P1);               // 0 = OBEN   1023 = UNTEN
      xVal_P1 = map(xStick_P1, 0, 1023, -100, 100);

      yStick_P2 = analogRead(YPIN_P2);               // 0 = LINKS  1023 = RECHTS
      yVal_P2 = map(yStick_P2, 0, 1023, -100, 100);
      xStick_P2 = analogRead(XPIN_P2);               // 0 = OBEN   1023 = UNTEN
      xVal_P2 = map(xStick_P2, 0, 1023, -100, 100);


      if (yVal_P1 < -20) {         // Aussteuerung nach oben
        _Dir = UP;
      }
      else if (yVal_P1 > 20 ) {   // Aussteuerung nach unten
        _Dir = DOWN;
      }
      else if (xVal_P1 < -20) {         // Aussteuerung nach links
        _Dir = LEFT;
      }
      else if (xVal_P1 > 20) {    // Aussteuerung nach rechts
        _Dir = RIGHT;
      }
      else {
        _Dir = 0;
      }

      if (yVal_P2 < -20) {         // Aussteuerung nach oben
        _Dir = UP;
      }
      else if (yVal_P2 > 20 ) {   // Aussteuerung nach unten
        _Dir = DOWN;
      }
      else if (xVal_P2 < -20) {         // Aussteuerung nach links
        _Dir = LEFT;
      }
      else if (xVal_P2 > 20) {    // Aussteuerung nach rechts
        _Dir = RIGHT;
      }
      else {
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
          delay(50);
          break;

        case UP:
          Serial.println("UP");
          digitalWrite(DIR_PIN_TILT, HIGH);
          analogWrite(STEP_PIN_TILT, 127);
          delay(50);
          break;

        case DOWN:
          Serial.println("DOWN");
          digitalWrite(DIR_PIN_TILT, LOW);
          analogWrite(STEP_PIN_TILT, 127);
          delay(50);
          break;

        default:
          digitalWrite(STEP_PIN_TILT, LOW);
          digitalWrite(STEP_PIN_PAN, LOW);
          break;
      }
    }
};

  class Player {
  public:
    String _playerId;
    int _highscore;
    int _runDuration;

    Player ( String playerId, int highscore, int runDuration) {
      setPlayerId(playerId);
      setHighscore(highscore);
      setDuration(runDuration);
    }
    //setter
    void setPlayerId(String playerId) {
      _playerId = playerId;
    }
    void  setHighscore(int highscore) {
      _highscore = highscore;
    }
    void setDuration(int runDuration) {
      _runDuration = runDuration;
    }
    //getter
    String getPlayerId() {
      return _playerId;
    }
    int getHighscore() {
      return _highscore;
    }
    int getDuration() {
      return _runDuration;
    }

    
  };
  
#endif
