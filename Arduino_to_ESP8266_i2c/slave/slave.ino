// SLAVE ARDUINO
#include <Wire.h>
void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  Serial.begin(115200); //begin serial monitor
  Wire.begin(8); //begin i2c with address
  Wire.onRequest(requestEvent); //send data to master
  Serial.print("Hi !");
}

void loop() {
  delay(1000);
}
void requestEvent() {  
  int p = analogRead(A0);
  int q = analogRead(A1);
  int r = analogRead(A2);
  int s = analogRead(A3);
  
  Wire.print(p);
  Wire.print("P");
  Serial.print("p");
  Serial.println(p);
  Wire.print(q);
  Wire.print("Q");
  Serial.print("q");
  Serial.println(q);
  Wire.print(r);
  Wire.print("R");
  Serial.print("r");
  Serial.println(r);
  Wire.print(s);
  Wire.print("S");
  Serial.print("s");
  Serial.println(s);
  Wire.print("\n"); // to stop read when complete one cycle
}
