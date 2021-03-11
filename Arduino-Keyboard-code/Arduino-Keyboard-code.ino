/*
  Arduino Leonardo/Micro: 8, 9, 10, 11, 14 (MISO), 15 (SCK), 16 (MOSI)
*/

#include "Keyboard.h"
#include "PinChangeInterrupt.h"

// Choose a valid PinChangeInterrupt pin of your Arduino board
#define pin8 8 //WS 4
#define pin9 9 //AD 5
#define pin10 10 //INT1 6
#define pin14 14 //INT2 12
#define pin15 15 //UPDOWN 13
#define pin16 16 //LEFTRIGHT 16

#define led 17

void setup() {
  // set pin to input with a pullup, led to output
  /*
  pinMode(pinBlink, INPUT_PULLUP);
  pinMode(led, OUTPUT);

  // Manually blink once to test if LED is functional
  blinkLed();
  delay(3000);
  blinkLed();

  // Attach the new PinChangeInterrupt and enable event function below
  attachPCINT(digitalPinToPCINT(pin8), blinkLed, CHANGE);

  */
  
}

void blinkLed(void) {
  // Switch Led state
  digitalWrite(led, !digitalRead(led));
}

void loop() {
  if(digitalRead(pin10) == HIGH){
    if(digitalRead(pin8) == HIGH){
      Keyboard.press('q');
      delay(100);
      Keyboard.release('q');
    }
    if(digitalRead(pin8) == LOW){
      Keyboard.press('e');
      delay(100);
      Keyboard.release('e');
    }
    if(digitalRead(pin9) == HIGH){
      Keyboard.press('a');
      delay(100);
      Keyboard.release('a');
    }
    if(digitalRead(pin9) == LOW){
      Keyboard.press('d');
      delay(100);
      Keyboard.release('d');
    }
   }
   else{
    Keyboard.releaseAll();
   }
   
  if(digitalRead(pin14) == HIGH){
    if(digitalRead(pin15) == HIGH){
      Keyboard.press('u');
      delay(100);
      Keyboard.release('u');
    }
    if(digitalRead(pin15) == LOW){
      Keyboard.press('o');
      delay(100);
      Keyboard.release('o');
    }
    if(digitalRead(pin16) == HIGH){
      Keyboard.press('j');
      delay(100);
      Keyboard.release('j');
    }
    if(digitalRead(pin16) == LOW){
      Keyboard.press('l');
      delay(100);
      Keyboard.release('l');
    }
   }
   else{
   Keyboard.releaseAll();
   }
  }