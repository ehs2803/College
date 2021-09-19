#define echoPin 7
#define trigPin 8
#define Temperature 27

long Read_mm_Dist(int echopin, int trigpin, int temperature);//(1)번문제
long Read_mm_Dist2(int echopin, int trigpin, int temperature);//(2)번문제
unsigned long Mypulseln();//(2)번문제

void setup(){
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop(){
  ///*(1)번문제
  long distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  distance=Read_mm_Dist(echoPin, trigPin, Temperature);
  Serial.print(distance);
  Serial.println("mm");
  delay(50);
  //*/
  
  /*(2)번문제
  long distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  distance=Read_mm_Dist2(echoPin, trigPin, Temperature);
  Serial.print(distance);
  Serial.println("mm");
  delay(50);
  */

  /*(3)번문제
  long distance;
  int n=1;
  long sum1=0, sum2=0;
  long average1 = 0, average2 = 0;
  double percent;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  while(n<=10){
    distance=Read_mm_Dist(echoPin, trigPin, Temperature);
    sum1+=distance;
    n++;
    delay(50);
  }
  n=1;
  while(n<=10){
    distance=Read_mm_Dist2(echoPin, trigPin, Temperature);
    sum2+=distance;
    n++;
    delay(50);
  }
  average1=sum1/10;
  Serial.print("(1)번함수 10회평균 = ");
  Serial.print(average1);Serial.println("mm");
  average2=sum2/10;
  Serial.print("(2)번함수 10회평균 = ");
  Serial.print(average2);Serial.println("mm");
  percent=(((double)average2-(double)average1)/(double)average2)*100.0;
  Serial.print(percent); Serial.println("%");
  Serial.println("------------");
  */ 
}


long Read_mm_Dist(int echopin, int trigpin, int temperature){
  long duration;
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  
  duration = pulseIn(echopin, HIGH);  
  return (331.5 + 0.6*temperature) * ((float)duration/1000000/2) * 1000;  

}

long Read_mm_Dist2(int echopin, int trigpin, int temperature){
  long duration;
  digitalWrite(trigpin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  
  duration=Mypulseln();
  return (331.5 + 0.6*temperature) * ((float)duration/1000000/2) * 1000;  
}

unsigned long Mypulseln(){
  unsigned long Start, End,t;
  while(1){
   if(digitalRead(echoPin)==HIGH){
     Start=micros();break;
   }
  }
  while(1){
   if(digitalRead(echoPin)==LOW){
    End=micros(); break;
   }
  }
  t = End-Start;
  return t;
}