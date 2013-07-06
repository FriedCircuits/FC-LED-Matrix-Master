/*
LED Matrix Link Test App
Created: 04/20/2013
Updated: 04/20/2013
by: William Garrido
Single 8x8 LED Maxtrix Link test app for with LED Matrix Master
*/


#include <LedControl.h> //  need the library\



const int devCount = 3;
int brightness = 15;
const int ledPin = 13;



LedControl lc=LedControl(12,11,10,devCount); 



void setup(){
  
  Serial.begin(57600);
  pinMode(ledPin, OUTPUT);
  
  for(int address=0;address<devCount;address++) {
    /*The MAX72XX is in power-saving mode on startup*/
    lc.shutdown(address,false);
    /* Set the brightness to a medium values */
    lc.setIntensity(address,brightness);
    /* and clear the display */
    lc.clearDisplay(address);
  }
  
  digitalWrite(ledPin, HIGH);
  
  
  
}


void loop(){
  
   for (int d=devCount-1;d>=0;d--) // Loop through displays
        {
          for (int r=0;r<8;r++) // Set up rows on current display
            {  
             
              lc.setRow(d,r,B11111111);

            }
            
            
        } 
        
        
   for(int address=0;address<devCount;address++) {
    /*The MAX72XX is in power-saving mode on startup*/
    lc.shutdown(address,false);
    /* Set the brightness to a medium values */
    lc.setIntensity(address,brightness);
    /* and clear the display */
    lc.clearDisplay(address);
  }
  
  
  
}
