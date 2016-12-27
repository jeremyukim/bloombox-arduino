#include"pitches.h"

const int enableChord = 10; //Reads from Arduino 1 pin A1
const int chordSignal1 = 12; //Reads from Arduino 1 pin A3
const int chordSignal2 = 13; //Reads from Arduino 1 pin A2

void setup() {
  pinMode(chordSignal1, INPUT);
  pinMode(chordSignal2, INPUT);
  Serial.begin(9600);
}

void loop () {
  noTone(6);
  delay(20);
  while((digitalRead(enableChord) == HIGH && digitalRead(chordSignal1) == LOW) && (digitalRead(chordSignal2) == LOW)){
    tone(6, NOTE_G4);
    Serial.println("G");
  }
  while((digitalRead(enableChord) == HIGH && digitalRead(chordSignal1) == LOW) && (digitalRead(chordSignal2) == HIGH)){
    tone(6, NOTE_A4);
    Serial.println("A");
    
  }
  while((digitalRead(enableChord) == HIGH && digitalRead(chordSignal1) == HIGH) && (digitalRead(chordSignal2) == LOW)){
    tone(6, NOTE_B4);
    Serial.println("B");
  }
  while((digitalRead(enableChord) == HIGH && digitalRead(chordSignal1) == HIGH) && (digitalRead(chordSignal2) == HIGH)){
    tone(6, NOTE_C5);
    Serial.println("C");
  }
  if(digitalRead(enableChord) == LOW ){
    noTone(6);
    delay(20);
    Serial.println("Nothing");
  }
}
