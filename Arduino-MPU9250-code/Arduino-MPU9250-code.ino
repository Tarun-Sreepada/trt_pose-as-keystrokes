/**
 @file read9axis.ino
 @brief This is an Example for the FaBo 9Axis I2C Brick.

   http://fabo.io/202.html

   Released under APACHE LICENSE, VERSION 2.0

   http://www.apache.org/licenses/

 @author FaBo<info@fabo.io>
*/

#include <Wire.h>
#include "Keyboard.h"
#include <FaBo9Axis_MPU9250.h>

FaBo9Axis fabo_9axis;

float axo, ayo, azo;
float margin = 0.02;
float time_mult = 1000;
int howlong;

void setup() {
  Serial.begin(115200);
  Serial.println("RESET");
  Serial.println();

  Serial.println("configuring device.");

  if (fabo_9axis.begin()) {
    Serial.println("configured FaBo 9Axis I2C Brick");
  } else {
    Serial.println("device error");
    while(1);
  }
  
}

void loop() {
  float ax,ay,az;
  float gx,gy,gz;
  float mx,my,mz;
  float temp;

  fabo_9axis.readAccelXYZ(&ax,&ay,&az);
  fabo_9axis.readGyroXYZ(&gx,&gy,&gz);
  fabo_9axis.readMagnetXYZ(&mx,&my,&mz);
  fabo_9axis.readTemperature(&temp);

  Serial.print("ax: ");
  Serial.print(ax);
  Serial.print(" ay: ");
  Serial.print(ay);
  Serial.print(" az: ");
  Serial.println(az);

  if(ax > axo + margin){
    howlong = int(abs((ax - axo))* time_mult);
    
    Keyboard.press(228);
    delay(howlong);
    Keyboard.release(228);
    axo = ax;
  }
  if(ax < axo - margin){
    howlong = int(abs((ax - axo))* time_mult);
    
    Keyboard.press(230);
    delay(howlong);
    Keyboard.release(230);
    axo = ax;
  }

  if(ay > ayo + margin){
    howlong = int(abs((ay - ayo))* time_mult);
    
    Keyboard.press(232);    
    delay(howlong);
    Keyboard.release(232);
    ayo = ay;
  }
  if(ay < ayo - margin){
    howlong = int(abs((ay - ayo))* time_mult);
    Keyboard.press(226);
    delay(howlong);
    Keyboard.release(226);
    ayo = ay; 
  }

  if(az > azo + margin){
    howlong = int(abs((az - azo))* time_mult);
    
    Keyboard.press(225);
    delay(howlong);
    Keyboard.release(225);
    azo = az;
  }
  if(az < azo - margin){
    howlong = int(abs((az - azo))* time_mult);
    
    Keyboard.press(227);
    delay(howlong);
    Keyboard.release(227);
    azo = az; 
  }

  Keyboard.releaseAll();

  Serial.print("gx: ");
  Serial.print(gx);
  Serial.print(" gy: ");
  Serial.print(gy);
  Serial.print(" gz: ");
  Serial.println(gz);

  Serial.print("mx: ");
  Serial.print(mx);
  Serial.print(" my: ");
  Serial.print(my);
  Serial.print(" mz: ");
  Serial.println(mz);

  Serial.print("temp: ");
  Serial.println(temp);

  delay(200);

}