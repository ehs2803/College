#include<AltSoftSerial.h>
AltSoftSerial altSerial;
#define OAS 7
#define LED 13
int a=0;

void setup(){
  pinMode(OAS, INPUT);
  pinMode(LED,OUTPUT);
  digitalWrite(LED,LOW);
  altSerial.begin(9600);
}

void loop(){
  if(digitalRead(OAS)==LOW){
    if(a==0){  
      a=1;
      digitalWrite(LED,HIGH);
      altSerial.println("Warining");
    
    }
  }

  if(a==1){    
    AAA:
    if(altSerial.available()==true){
      int temp=altSerial.read();
      if(temp!=32){goto AAA;}
      digitalWrite(LED,LOW);
      a=0;
    }
  }
}