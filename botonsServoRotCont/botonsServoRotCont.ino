 /*

   Dos botons, si s'apreta un gira
   cap a la dreta, si s'apreta
   l'altre a l'esquerra

*/

#include <Servo.h>

Servo myServo;


void setup() {
  myServo.attach(9);
  pinMode(2, INPUT);
  pinMode(3, INPUT);

}

void loop() {
  if (digitalRead(2)) {
    myServo.write(180);
    delay(2);
  }
  else if (digitalRead(3)) {
    myServo.write(0);
    delay(2);
  }
  else {
    myServo.write(90);
  }
}
