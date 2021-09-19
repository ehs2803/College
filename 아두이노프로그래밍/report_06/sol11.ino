#define intpin 2
#define analogpin 3

volatile int t=0;
volatile int count=0;
int ctrint=-1;

void setup() {
  pinMode(intpin, INPUT);
  attachInterrupt(digitalPinToInterrupt(intpin), counting, RISING);
  Serial.begin(9600); 
  analogWrite(analogpin,0);
  Serial.println("(a)스톱워치 시작 (b)스톱워치 중지 (c)스톱워치 초기화"); 
}

void loop() {
  if(Serial.available()>0){
    char inchar=Serial.read();
    if(inchar=='a'){
      analogWrite(analogpin,100);    
    }
    else if(inchar=='b'){
      analogWrite(analogpin,0);
    }
    else if(inchar=='c'){
      t=0;
      analogWrite(analogpin,0);
    }
  }
  if(ctrint!=t){ 
    Serial.print("\r"); Serial.print(t);
    ctrint=t; 
  } 
}

void counting(){
  count++;
  if(count==490){
    t++;
    count=0;
  }
}