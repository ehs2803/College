int echopin=7;
int trigpin=8;
int temperature=27;
bool value;
long duration, distance;
double sSpeed_cm_us;

void setup(){
  Serial.begin(9600);
  pinMode(trigpin,OUTPUT); pinMode(echopin,INPUT);
  sSpeed_cm_us=(331.5+0.6*temperature)*pow(10,2)/pow(10,6);
  attachInterrupt(digitalPinToInterrupt(2), sign, FALLING); 
}

void sign(){
  Mypulseln();
}

void Mypulseln(){
  bool normal, event;
  value=1;
  if(value==HIGH){
    normal=LOW;
    event=HIGH;
  }
  else{
    normal=HIGH;
    event=LOW;
  }
  unsigned long cnt_s, cnt_e;

  delayMicroseconds(7*25);
  while(digitalRead(echopin)==normal);
  cnt_s=micros();
  while(digitalRead(echopin)==event);
  cnt_e=micros();
  duration=(cnt_e-cnt_s);
}

void loop(){
  int range;

  digitalWrite(trigpin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW);
  
 
  distance=duration/2*sSpeed_cm_us;

  if(distance<0){    
  }
  else{
    Serial.print(distance);
    Serial.println("cm");
  }
  delay(1000);
}