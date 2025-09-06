# PS2Mouse-Esp32
Arduino files for mouse and esp32
PS2 Mouse Handler Library for Arduinos This library allows you to easily interface any PS2 compatible mouse
to your Arduino using only 2 digital I/O pins. Most USB mice will allow you to connect them as PS2 mice. 
Use the D+ line as the PS2 clock signal and the D- line as the PS2 data signal. 
It is based on the code by Getis which can be found at https://github.com/getis/Arduino-PS2-Mouse-Handler
I've included a basic example which shows how to gather the data from the mouse and access the x / y movement, 
scroll wheel, button states and button click data. Moded to work with ESP32 by Saul Monteiro. 

You can see the code working here: https://www.youtube.com/watch?v=Jqwp29bVL0Y
