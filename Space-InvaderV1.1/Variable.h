#ifndef VARIABLE_H
#define VARIABLE_H
int t = 500;
bool start = false;
int xval;
int yval;
int xPos = map(xval, 0, 1023, -100, 100);
int yPos = map(yval, 0, 1023, -100, 100);
String arrayLetters[26] {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
String arrayName[5];
int buttonState;
String input;               
byte i = 0;             //Variable für Durchlauf des Buchstabenarray`s
byte j = 0;             //Variable für Durchlauf des Buchstabenarray`s
enum eDirection {
  LEFT = 1,
  RIGHT,
  UP,
  DOWN
};




#endif
