int R1=13;
int R2=12;
int R3=11;
int R4=10;
int C1=9;
int C2=8;
int C3=7;
int C4=6;

char _getch();

void setup()
{
  pinMode(C1, INPUT_PULLUP);
  pinMode(C2, INPUT_PULLUP);
  pinMode(C3, INPUT_PULLUP);
  pinMode(C4, INPUT_PULLUP);
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(R3, OUTPUT);
  pinMode(R4, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  char a;
  a=_getch();
  Serial.print(a);
  Serial.println(": pushed");
  delay(200);
}

char _getch(){
  char ch;
  for(;;)
  {
     for(int i=10;i<=13;i++)
     {
       digitalWrite(10,HIGH);
       digitalWrite(11,HIGH);
       digitalWrite(12,HIGH);
       digitalWrite(13,HIGH);
       digitalWrite(i,LOW);
       if(digitalRead(C1)==LOW)
       {
           if(digitalRead(R1)==LOW)
           {
            ch='1';goto AAA;
           }
           else if(digitalRead(R2)==LOW)
           {
             ch='4';goto AAA;  
           }
           else if(digitalRead(R3)==LOW)
           {
             ch='7'; goto AAA;
           }
           else
           { ch='*'; goto AAA; }
        }
        else if(digitalRead(C2)==LOW)
        {
           if(digitalRead(R1)==LOW)
           {
            ch='2';goto AAA;
           }
           else if(digitalRead(R2)==LOW)
           {
             ch='5';goto AAA;  
           }
           else if(digitalRead(R3)==LOW)
           {
             ch='8'; goto AAA;
           }
           else
           { ch='0'; goto AAA; }
        }
        else if(digitalRead(C3)==LOW)
        {
           if(digitalRead(R1)==LOW)
           {
            ch='3';goto AAA;
           }
           else if(digitalRead(R2)==LOW)
           {
             ch='6';goto AAA;  
           }
           else if(digitalRead(R3)==LOW)
           {
             ch='9'; goto AAA;
           }
           else
           { ch='#'; goto AAA; }
        }
        else if(digitalRead(C4)==LOW)
        {
           if(digitalRead(R1)==LOW)
           {
            ch='A';goto AAA;
           }
           else if(digitalRead(R2)==LOW)
           {
             ch='B';goto AAA;  
           }
           else if(digitalRead(R3)==LOW)
           {
             ch='C'; goto AAA;
           }
           else
           { ch='D'; goto AAA; }
        }  
      }
  }
  AAA:
  return(ch);
}
