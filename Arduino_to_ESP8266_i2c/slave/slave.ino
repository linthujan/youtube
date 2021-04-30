#include <Wire.h>
void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  Serial.begin(115200);
  Wire.begin(8);                /* join i2c bus with address 8 */
  Wire.onRequest(requestEvent);
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
  Wire.print("\n");
}
