#include <Servo.h>

Servo ServoThumb;
Servo ServoIndex;
Servo ServoMiddlefinger;
Servo ServoRingfinger;
Servo ServoPinkyfinger;

int angulo = 0;

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

int pinky = 2;
int ring = 3;
int middle = 4;
int index = 5;
int thumb = 6;


void allON(){
   
digitalWrite(pinky, HIGH);
digitalWrite(index, HIGH);
digitalWrite(middle, HIGH);
digitalWrite(thumb, HIGH);
digitalWrite(ring, HIGH);
   
  }
 
 
void allOFF(){
   
digitalWrite(pinky, LOW);
digitalWrite(index, LOW);
digitalWrite(middle, LOW);
digitalWrite(thumb, LOW);
digitalWrite(ring, LOW);
}
 
 
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
        Pinky = myRevivedString.substring(1, 2).toInt();
        Ring = myRevivedString.substring(2, 3).toInt();
        Middle = myRevivedString.substring(3, 4).toInt();
        Index = myRevivedString.substring(4, 5).toInt();
        Thumb = myRevivedString.substring(5, 6).toInt();
        Serial.print(Pinky);
        Serial.print(" ");
        Serial.print(Ring);
        Serial.print(" ");
        Serial.print(Middle);
        Serial.print(" ");
        Serial.print(Index);
        Serial.print(" ");
        Serial.println(Thumb);      
        myRevivedString = "";
      }
    }
  }
}


void setup() {
  pinMode(pinky, OUTPUT);
  pinMode(ring, OUTPUT);
  pinMode(middle, OUTPUT);
  pinMode(index, OUTPUT);
  pinMode(thumb, OUTPUT);
 
  Serial.begin(9600);
  allOFF();

  //THUMB
  ServoThumb.attach(3);
  ServoThumb.write(angulo);

//INDEX
  ServoIndex.attach(5);
  ServoIndex.write(angulo);

//MIDDLE FINGER
  ServoMiddlefinger.attach(6);
  ServoMiddlefinger.write(angulo);

//RING FINGER
  ServoRingfinger.attach(9);
  ServoRingfinger.write(angulo);
 
//PINKY FINGER
  ServoPinkyfinger.attach(10);
  ServoPinkyfinger.write(angulo);  
  
}
 
void loop() {

receiveData();
  if (Thumb == 1){
    ServoThumb.write(90);
  }else{
    ServoThumb.write(0);
  }
  
  
  if (Index == 1){
    ServoIndex.write(90);
  }else{
    ServoIndex.write(0);
  }
  
  if (Middle == 1){
    ServoMiddlefinger.write(90);
  }else{
    ServoMiddlefinger.write(0);
  }
  
  if (Ring == 1){
    ServoRingfinger.write(90);
  }else{
    ServoRingfinger.write(0);
  }
  
   if (Pinky == 1){
    ServoPinkyfinger.write(90);
  }else{
    ServoPinkyfinger.write(0);
  }
}