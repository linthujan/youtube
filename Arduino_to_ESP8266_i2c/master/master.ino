#include <Wire.h>

char c;
String data;
String p;
String q;
String r;
String s;
int indexofp;
int indexofq;
int indexofr;
int indexofs;

void setup() {
 Serial.begin(115200);
 Wire.begin(0,2);
}

void loop() {
 Wire.requestFrom(8,25);
 while(Wire.available()){
    c = Wire.read();
 if(c=='\n') {break;}
 else  {data+=c;}
 }
 
 if(c=='\n')
 {
   parsestring();
   Serial.println("p : "+ p);
   Serial.println("q : "+ q);
   Serial.println("r : "+ r);
   Serial.println("s : "+ s);
   c=0;
   data="";
 }
 
 delay(100);
}

void parsestring () {
  indexofp =data.indexOf("P");
  indexofq =data.indexOf("Q");
  indexofr =data.indexOf("R");
  indexofs =data.indexOf("S");
  
    p = data.substring (0,indexofp);
    q = data.substring (indexofp+1,indexofq);
    r = data.substring (indexofq+1,indexofr);
    s = data.substring (indexofr+1,indexofs);
}
