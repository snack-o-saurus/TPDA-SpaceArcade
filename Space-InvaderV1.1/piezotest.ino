#include<Wire.h>

void setup(){
    pinMode(A0, INPUT);
    Serial.begin(115200);
    Serial.println("Piezoelektrische Folie / Vibrationssensor - Test");
    Serial.println("Ausgabe Pin A0");
}

void loop(){
    int pzval;
   pzval = digitalRead(A0);
   Serial.println(pzval);
    delay(5);

}