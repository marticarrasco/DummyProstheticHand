/*
 * 
 * Dos botons, si s'apreta un gira 
 * cap a la dreta, si s'apreta
 * l'altre a l'esquerra
 * 
 */

#include <Servo.h>

Servo s1;
Servo s2;
Servo s3;
Servo s4;
Servo s5;


void setup() {

  s1.attach(5);
  s2.attach(6);
  s3.attach(9);
  s4.attach(10);
  s5.attach(11);
  
  pinMode(2, INPUT);
  pinMode(3, INPUT);

}

void loop() {
  if(digitalRead(2)){
    s1.write(180);
    s2.write(180);
    s3.write(180);
    s4.write(180);
    s5.write(180);
    delay(10);
  }
  if(digitalRead(3)==true){
    s1.write(0);
    s2.write(10);
    s3.write(0);
    s4.write(0);
    s5.write(0);
    delay(10);
  }
  if(!digitalRead(3) && !digitalRead(2)){
    s1.write(90);
    s2.write(90);
    s3.write(90);
    s4.write(90);
    s5.write(90);
  }
  

 


}
