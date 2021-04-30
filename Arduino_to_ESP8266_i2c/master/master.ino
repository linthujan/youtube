//ESP8266 MASTER
#include <Wire.h>

char c;
String data;
String p,q,r,s;
int indexofp,indexofq,indexofr,indexofs;

void setup() {
 Serial.begin(115200); //start serial monitor
 Wire.begin(0,2); // begin i2c communication sda=0,scl=2
}

void loop() {
 Wire.requestFrom(8,25); // i2c slave address and recived value count
 while(Wire.available()){
    c = Wire.read(); //store received charactor
 if(c=='\n') {break;}
 else  {data+=c;} // store received charactors to string (data)
 }
 
 if(c=='\n')
 {
   parsestring(); // extract serial data 
   Serial.println("p : "+ p);
   Serial.println("q : "+ q);
   Serial.println("r : "+ r);
   Serial.println("s : "+ s);
   c=0;  // reset variables
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
