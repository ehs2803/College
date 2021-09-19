#include<AltSoftSerial.h>
#define SPK_PIN 11
AltSoftSerial altSerial;
int scales[]={262,294,330,347,392,440,494,524};
String freqS;
int freq;

void setup(){
  altSerial.begin(9600);
}

void loop(){
   if(altSerial.available()==true){
     freqS=altSerial.readString();
     freq=freqS.toInt();
     if(freq==1)
     {
      tone(SPK_PIN,scales[freq-1],150);
      altSerial.print("도 ");
      altSerial.println(freq);
     }
     else if(freq==2)
     {
      tone(SPK_PIN,scales[freq-1],150);
      altSerial.print("레 ");
      altSerial.println(freq);
     }
     else if(freq==3)
     {
      tone(SPK_PIN,scales[freq-1],150);
      altSerial.print("미 ");
      altSerial.println(freq);
     }
     else if(freq==4)
     {
      tone(SPK_PIN,scales[freq-1],150);
      altSerial.print("파 ");
      altSerial.println(freq);
     }
     else if(freq==5)
     {
      tone(SPK_PIN,scales[freq-1],150);
      altSerial.print("솔 ");
      altSerial.println(freq);
     }
     else if(freq==6)
     {
      tone(SPK_PIN,scales[freq-1],150);
      altSerial.print("라 ");
      altSerial.println(freq);
     }
     else if(freq==7)
     {
      tone(SPK_PIN,scales[freq-1],150);
      altSerial.print("시 ");
      altSerial.println(freq);
     }
     else if(freq==8)
     {
      tone(SPK_PIN,scales[freq-1],150);
      altSerial.print("도 ");
      altSerial.println(freq);
     }    
   }
}