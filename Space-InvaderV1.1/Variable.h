#ifndef VARIABLE_H
#define VARIABLE_H
int t = 500;
bool solo = false;
bool start = false;
bool player;
bool nameaccepted;
bool gameover = false;

int button1State;
int button2State;
int button3State;
int button4State;

int buttonPrestate;
int servoAngle = 0;
int xStick_P1 = 0;
int yStick_P1 = 0;
int yVal_P1;
int xVal_P1;
int xStick_P2 = 0;
int yStick_P2 = 0;
int yVal_P2;
int xVal_P2;
int scoregain;

uint32_t menutime;
uint32_t systime;
uint32_t playtime ;


byte i = 0;             //Variable für Durchlauf des Buchstabenarray`s
byte z = 0;             //Variable für Durchlauf des Buchstabenarray`s
byte j = 0;
byte difficulty = 0;

//char row1[];
//char row2[];

char arrayLetters[26] {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
String arrayName[10];
String tempName[10];
String tempId;

enum eDirection {
  LEFT,
  RIGHT,
  UP,
  DOWN
};

enum eTier{
  HEAVY,
  MIDDLE,
  EASY
};
 enum eSpeed{
  SLOW,
  REGULAR,
  FAST
 };
  






#endif
