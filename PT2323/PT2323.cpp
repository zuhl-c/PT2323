#include <Arduino.h>
#include <Wire.h>
#include "PT2323.h"

PT2323::PT2323(){
	Wire.begin();
}

void PT2323::setInput(int in){
     switch(in){
        case 0: in = 0xCB;break;
	case 1: in = 0xCA;break;
	case 2: in = 0xC9;break;
	case 3: in = 0xC8;break;
        case 4: in = 0xC7;break;
        } 
        writeWire(in);
}

void PT2323::setMute(int fl, int fr, int ct, int sub, int sl, int sr, int mute){
      if(fl==1){fl = 0xF1;}else{fl = 0xF0;}
      if(fr==1){fr = 0xF3;}else{fr = 0xF2;}
      if(ct==1){ct = 0xF5;}else{ct = 0xF4;}
    if(sub==1){sub = 0xF7;}else{sub= 0xF6;}
      if(sl==1){sl = 0xF9;}else{sl = 0xF8;}
      if(sr==1){sr = 0xFB;}else{sr = 0xFA;}
  if(mute==1){mute = 0xFF;}else{mute=0xFE;}
      
  writeWire(fl);
  writeWire(fr);
  writeWire(ct);
  writeWire(sub);
  writeWire(sl);
  writeWire(sr);
  writeWire(mute);
}

void PT2323::setFeature(int surr, int mix){
     switch(surr){
        case 0: surr = 0xD0;break;
	case 1: surr = 0xD1;break;
        }
     switch(mix){
        case 0: mix = 0x90;break;
	case 1: mix = 0x91;break;
        } 
        writeWire(surr);
        writeWire(mix);
}

void PT2323::writeWire(char a){
  Wire.beginTransmission(ADDRESS);
  Wire.write (a);
  Wire.endTransmission();
}
