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
#define PINT1     A2
#define PINT2     A3
#define PINT3     A4
#define PINT4     A5
#define PINT5     A6



#define STEP_PIN_PAN  10        // Step on rising edge
#define EN_PIN_PAN    13         // LOW = enable driver  / HIGH = disable driver
#define DIR_PIN_PAN   11

#define STEP_PIN_TILT  6        // Step on rising edge
#define EN_PIN_TILT    7        // LOW = enable driver  / HIGH = disable driver
#define DIR_PIN_TILT   5
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
         bool _tid = false;
  
public: int _tscore;
        int _targetid;
         int _tcount;
  
  target(int tcount, bool tid,int tscore, int targetid){
    setTcount(tcount);
    setTid(tid);
    settargetid(targetid);
  }
      
/*                Setter functions                            */       
void setTcount(int tcount){
 _tcount = tcount;                
}    
void setTid(bool tid){
   _tid = tid;      
}     
void setTscore(int tscore){         
 _tscore = tscore;        
}
void settargetid(int targetid){
_targetid = targetid;
}

/*                 Getter Functions                          */
int getcount(){
return _tcount;
}
bool getT(){
return(_tid);
}
int getTid(){
return(_targetid);
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
      yStick_P1 = analogRead(YPIN_P1);               // 0 = LINKS  1023 = RECHTS
      yVal_P1 = map(yStick_P1, 0, 1023, -100, 100);
      xStick_P1 = analogRead(XPIN_P1);               // 0 = OBEN   1023 = UNTEN
      xVal_P1 = map(xStick_P1, 0, 1023, -100, 100);
      
      yStick_P2 = analogRead(YPIN_P2);               // 0 = LINKS  1023 = RECHTS
      yVal_P2 = map(yStick_P2, 0, 1023, -100, 100);
      xStick_P2 = analogRead(XPIN_P2);               // 0 = OBEN   1023 = UNTEN
      xVal_P2 = map(xStick_P2, 0, 1023, -100, 100);
      
      if (yVal_P1 < -20 || yVal_P2 < -20) {         // Aussteuerung nach oben
        _Dir = UP;
      }
      else if (yVal_P1 > 20 ||yVal_P2 < -20 ) {    // Aussteuerung nach unten
        _Dir = DOWN;
      }
      else if (xVal_P1 < -20 || xVal_P2 < -20) {         // Aussteuerung nach links
        _Dir = LEFT;
      }
      else if (xVal_P1 > 20 || xVal_P2 > 20 ) {    // Aussteuerung nach rechts
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

  class Player {
    public:
    String _playerId;
    int _highscore;
    int _runDuration;
    
     Player ( String playerId, int highscore, int runDuration){
      setPlayerId(playerId);
      setHighscore(highscore);
      setDuration(runDuration);
    }
    //setter
   void setPlayerId(String playerId){
      _playerId = playerId;
    }
   void  setHighscore(int highscore){
      _highscore = highscore;
    }
   void setDuration(int runDuration){
      _runDuration = runDuration;
    }
    //getter
    String getPlayerId(){
      return _playerId;
    }
    int getHighscore(){
      return _highscore;
    }
    int getDuration(){
      return _runDuration;
    }
  };
#endif
