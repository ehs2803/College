#define echoPin 7
#define trigPin 8
#define Temperature 27
long duration, distance;
double sSpeed_cm_us;
int SPK=11;

void setup(){
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  sSpeed_cm_us=(331.5+0.6*Temperature)/pow(10,4);
}

void loop(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance=(duration*sSpeed_cm_us)/2;
  
  if(distance>40||distance<10){
    noTone(SPK); Serial.println("0");
    delay(50);
  }
  if(10<=distance&&distance<=14){
    tone(SPK, 262); Serial.println("1 도");
    delay(50);
  }
  else if(14<distance&&distance<=18)
  {
    tone(SPK, 294); Serial.println("2 레");
    delay(50);
  }
  else if(18<distance&&distance<=22)
  {
    tone(SPK, 330); Serial.println("3 미");
    delay(50);
  }
  else if(22<distance&&distance<=26)
  {
    tone(SPK, 347); Serial.println("4 파");
    delay(50);
  }
  else if(26<distance&&distance<=30)
  {
    tone(SPK, 392); Serial.println("5 솔");
    delay(50);
  }
  else if(30<distance&&distance<=34)
  {
    tone(SPK, 440); Serial.println("6 라");
    delay(50);
  }
  else if(34<distance&&distance<=37)
  {
    tone(SPK, 494); Serial.println("7 시");
    delay(50);
  }
  else if(37<distance&&distance<=40)
  {
    tone(SPK, 524); Serial.println("8 도");
    delay(50);
  }
}