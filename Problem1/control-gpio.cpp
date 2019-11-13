/* A Simple GPIO application
* Written by Derek Molloy for the book "Exploring BeagleBone: Tools and
* Techniques for Building with Embedded Linux" by John Wiley & Sons, 2018
* ISBN 9781119533160. Please see the file README.md in the repository root
* directory for copyright and GNU GPLv3 license information.            */

#include<iostream>
#include<unistd.h> //for usleep
#include"GPIO.h"
#include"derek_LED.h"
using namespace exploringBB;
using namespace std;

int main(){
   GPIO outGPIO(49), inGPIO(26), inGPIO2(46);

   // Basic Output - Flash the LED 10 times, once per second
   outGPIO.setDirection(OUTPUT);
   inGPIO.setDirection(INPUT);
   if(inGPIO.getValue()==0)  
   outGPIO.setValue(HIGH);
   
   LED leds[1] =  LED(3);
   if(inGPIO2.getValue()==0)   
	  leds[0].turnOn();
   else
      leds[0].turnOff();
  
   return 0;
}
