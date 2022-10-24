/*
 * inclou tant serial com botons, comentar
 * o descomentar el que es prefereixi
 * 
 * el dit abaix és 1, a dalt 0
 */

#include<Servo.h>

char number[50];
char c;
int state = 0;
String myStringRec;
int stringCounter = 0;
bool stringCounterStart = false;
String myRevivedString;
int stringLength = 6;
 
int Pinky,Middle,Index,Thumb,Ring;
int myVals[] ={0,0,0,0,0};

//buttons 
int bThumb = 13;
int bIndex = 12;
int bMiddle = 8;
int bRing = 7;
int bPinky = 4;

//current state
int cThumb = 0;
int cIndex = 0;
int cMiddle = 0;
int cRing = 0;
int cPinky = 0;


//time needed by each finger
int tThumb = 600;
int tIndex = 430;
int tMiddle = 600;
int tRing = 600;
int tPinky = 500;

Servo ServoThumb;
Servo ServoIndex;
Servo ServoMiddle;
Servo ServoRing;
Servo ServoPinky;

void receiveData() {
  int i = 0;
  while (Serial.available()) {
   char c = Serial.read();
   
    if (c == '$') {
      stringCounterStart = true;
    }
    if (stringCounterStart == true )
    {
      if (stringCounter < stringLength)
      {
        myRevivedString = String(myRevivedString + c);
        stringCounter++;
      }
      if (stringCounter >= stringLength) {
        stringCounter = 0; stringCounterStart = false;
        Thumb = myRevivedString.substring(1, 2).toInt();
        Index = myRevivedString.substring(2, 3).toInt();
        Middle = myRevivedString.substring(3, 4).toInt();
        Ring = myRevivedString.substring(4, 5).toInt();
        Pinky = myRevivedString.substring(5, 6).toInt();
        Serial.print(Thumb);
        Serial.print(" ");
        Serial.print(Index);
        Serial.print(" ");
        Serial.print(Middle);
        Serial.print(" ");
        Serial.print(Ring);
        Serial.print(" ");
        Serial.println(Pinky);      
        myRevivedString = "";
      }
    }
  }
}


void setup() {
  Serial.begin(9600);
  delay(1500);
  
    //THUMB
  ServoThumb.attach(3);
  //ServoThumb.write(90);

    //INDEX
  ServoIndex.attach(5);
  //ServoIndex.write(90);

    //MIDDLE FINGER
  ServoMiddle.attach(6);
  //ServoMiddle.write(90);

    //RING FINGER
  ServoRing.attach(9);
  //ServoRing.write(90);
 
    //PINKY FINGER
  ServoPinky.attach(10);
  //ServoPinky.write(90); 

  pinMode(bThumb, INPUT);
  pinMode(bIndex, INPUT);
  pinMode(bMiddle, INPUT);
  pinMode(bRing, INPUT);
  pinMode(bPinky, INPUT);
}

void loop() {
  //Thumb = digitalRead(bThumb);
  //Index = digitalRead(bIndex);
  //Middle = digitalRead(bMiddle);
  //Ring = digitalRead(bRing);
  //Pinky = digitalRead(bPinky);

  receiveData();
  
  if(Thumb==0 && cThumb != 0){
    ServoThumb.write(180);
    delay(tThumb);
    cThumb = 0;
    ServoThumb.write(90);
  }

  if(Index==0 && cIndex != 0){
    ServoIndex.write(0);
    delay(tIndex);
    cIndex = 0;
    ServoIndex.write(90);
  }

  if(Middle==0 && cMiddle != 0){
    ServoMiddle.write(180);
    delay(tMiddle);
    cMiddle = 0;
    ServoMiddle.write(90);
  }

  if(Ring==0 && cRing != 0){
    ServoRing.write(0);
    delay(tRing);
    cRing = 0;
    ServoRing.write(90);
  }

  if(Pinky==0 && cPinky != 0){
    ServoPinky.write(180);
    delay(tPinky);
    cPinky = 0;
    ServoPinky.write(90);
  }

  if(Thumb==1 && cThumb != 1){
    ServoThumb.write(0);
    delay(tThumb);
    cThumb = 1;
    ServoThumb.write(90);
  }

  if(Index==1 && cIndex != 1){
    ServoIndex.write(180);
    delay(tIndex);
    cIndex = 1;
    ServoIndex.write(90);
  }

  if(Middle==1 && cMiddle != 1){
    ServoMiddle.write(0);
    delay(tMiddle);
    cMiddle = 1;
    ServoMiddle.write(90);
  }

  if(Ring==1  && cRing != 1){
    ServoRing.write(180);
    delay(tRing);
    cRing = 1;
    ServoRing.write(90);
  }

  if(Pinky==1  && cPinky != 1){
    ServoPinky.write(0);
    delay(tPinky);
    cPinky = 1;
    ServoPinky.write(90);
  }

  Serial.print(String(Thumb) + "    ");
  Serial.print(String(Index) + "    ");
  Serial.print(String(Middle) + "    ");
  Serial.print(String(Ring) + "    ");
  Serial.println(Pinky);

  

}
