#ifndef VARIABLE_H
#define VARIABLE_H
int t = 500;
bool solo = false;
bool start = false;

int xStick;
int yStick;
uint32_t gametime;

int buttonState;
uint32_t systime;
byte i = 0;             //Variable für Durchlauf des Buchstabenarray`s
byte j = 0;             //Variable für Durchlauf des Buchstabenarray`s

char row1[16];
char row2[16];
char arrayLetters[26] {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', "S", "T", "U", "V", "W", "X", "Y", "Z"};
String arrayName[10];
String tempName[10];
String input;
String tempId;

enum eDirection {
  LEFT = 1,
  RIGHT,
  UP,
  DOWN
};




#endif
