#include<MsTimer2.h>

volatile int frequen;
volatile double detime;
volatile int state=0;
volatile int SPK;

void myTone(int pin, int frequency){
  detime=((1/(double)frequency)*0.5)*1000000;
  frequen=frequency;
  SPK=pin;
  state=1; 
}

void myNoTone(){
  state=0;
}

void fre(){
  int n=0;
  if(state==0){
    while(n<1000){
      digitalWrite(2,1); delayMicroseconds(500);
      digitalWrite(2,1); delayMicroseconds(500);
      n++;
    }   
  }
  else if(state==1){
    while(n<frequen){
      digitalWrite(SPK,1); delayMicroseconds(detime);
      digitalWrite(SPK,0); delayMicroseconds(detime);
      n++;
    }
  }
}

int inputFromTerm(){
  String inString;
  while(1){
    if(Serial.available()>0){
      char inchar=Serial.read();
      if(inchar=='\n') break;
     Serial.print(inchar);
     inString+=(char)inchar;
    }
  }
  return(inString.toInt());
}

void setup() {
  pinMode(11,OUTPUT);
  MsTimer2::set(1000, fre);
  MsTimer2::start();
  Serial.begin(9600);
}

void loop() {
  AAA: 
  Serial.print("주파수를 입력하세요 : ");
  int x=inputFromTerm();
  if(x>500){
    Serial.print("Hz");
    Serial.println(" 잘못된 범위 주파수!");
    goto AAA;
  }
  else{
    Serial.println("Hz");
    myTone(11,x);
    delay(2000);
    myNoTone();
  }
}