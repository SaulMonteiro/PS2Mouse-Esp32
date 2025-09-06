/*
PS2 Mouse Handler Library for Arduinos This library allows you to easily interface any PS2 compatible mouse
to your Arduino using only 2 digital I/O pins. Most USB mice will allow you to connect them as PS2 mice. 
Use the D+ line as the PS2 clock signal and the D- line as the PS2 data signal. 
It is based on the code by Getis which can be found at https://github.com/getis/Arduino-PS2-Mouse-Handler
I've included a basic example which shows how to gather the data from the mouse and access the x / y movement, 
scroll wheel, button states and button click data. Moded to work with ESP32 by Saul Monteiro.

*/



#include "PS2MouseHandler.h"
#define MOUSE_DATA 5 // PS2 DATA
#define MOUSE_CLOCK 18 // PS2 CLOCK


//PS2MouseHandler mouse(MOUSE_CLOCK, MOUSE_DATA, PS2_MOUSE_REMOTE);//PS2_MOUSE_STREAM
PS2MouseHandler mouse(MOUSE_CLOCK, MOUSE_DATA, PS2_MOUSE_STREAM);//PS2_MOUSE_STREAM

/**
 * Setup
 */
void setup()
{
  
  Serial.begin(115000);

  if(mouse.initialise() != 0){
    // mouse error
    Serial.println("mouse error");
  };

  Serial.println(mouse.device_id());
}

/**
 * Main program loop
 */

unsigned long last_run = millis();

void loop()
{
  if (millis() - last_run > 200) {
    last_run = millis();
    mouse.get_data();
    Serial.print(mouse.device_id()); // device id
    Serial.print(":");
    Serial.print(mouse.status()); // Status Byte
    Serial.print(":");
    Serial.print(mouse.x_movement()); // X Movement Data
    Serial.print(",");
    Serial.print(mouse.y_movement()); // Y Movement Data
    Serial.print(",");
    Serial.print(mouse.z_movement()); // Z Movement Data - scroll wheel
    Serial.print(",");
    Serial.print(mouse.button(0));
    Serial.print(",");
    Serial.print(mouse.button(1));
    Serial.print(",");
    Serial.print(mouse.button(2));
    Serial.print(",");
    Serial.print(mouse.clicked(0));
    Serial.print(",");
    Serial.print(mouse.clicked(1));
    Serial.print(",");
    Serial.print(mouse.clicked(2));
    Serial.println();
  }
}
