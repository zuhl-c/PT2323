/* PT2323 6 channel input selector library for arduino.
written by zuhail
https://github.com/zuhl-c */

#ifndef  PT2323_H
#define  PT2323_H

#define  ADDRESS 0x4A  //ic address

#include <Arduino.h>

class  PT2323
{
  public:
     PT2323();
        void setInput(int in); //input(0..4)
        //channels muting(0/1)
        void setMute(int fl, int fr, int ct, int sub, int sl, int sr, int mute);
        // 0 - Enhanced Surround Function Active
        // 1 - Enhanced Surround Function Disabled
        // 0 - Mixed Channel  0dB Setup
        // 1 - Mixed Channel +6dB Setup
        void setFeature(int surr, int mix); 
  private:
	void writeWire(char a);
};
	
#endif
