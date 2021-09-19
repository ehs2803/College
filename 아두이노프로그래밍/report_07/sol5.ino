#include<MsTimer2.h>

volatile bool sign=false;
int Hcount=0;
int Tcount=0;
int timeSecond=0;
int pretime=0;

void counting(){  
   sign=true;
}

void setup() {
  MsTimer2::set(10,counting);
  MsTimer2::start();
  Serial.begin(9600);
}

void loop() {

  if(sign==true){
    Hcount++; //맥박측정
    if(Hcount%10==0){
      Tcount++; //온도측정
    }    
    sign=false;
  }

  if(Hcount==100){
    Serial.print("맥박 ");Serial.print(Hcount);Serial.println("회 측정");
    Serial.print("온도 ");Serial.print(Tcount);Serial.println("회 측정");
    Hcount=0;
    Tcount=0;
    timeSecond++;
  }
  
  if(pretime!=timeSecond){
    Serial.print(timeSecond);
    Serial.println("초\n");
    pretime=timeSecond;
  }
}