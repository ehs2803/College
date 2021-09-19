/*
  855: 8장 5절 문제 8번
  인터럽트를 기반으로 pulseIn()과 같은 동작을 수행하는 myPulseIn() 함수를 제작한다.


  int MyPulseIn_Int(int echoPin, bool value)
  echoPin 단자의 상태가 value가 될 때까지 까지 기다리고, value의 폭을 us(micro second) 단위로 반환한다. 

  echoPin 단자의 상태변화(CHANGE: L->H, H-> L)가 일어날 때마다 인터럽트가 발생하게 한다. 총 2회의 인터럽트 발생.
  인터럽트 서비스 루틴 내부에서는 micros() 함수를 호충하여 현재의 timer tick cout를 기록한다.
  처음 L->H로 뙬때 micros() 함수를 호출하여 time tick count를 반환 받아 저장한다. => start_count
  H->L로 뙬때 한번 더 micros() 함수를 호출하여 time tick count를 반환 받아 저장한다. => end_count
  diff=end_count-start_count; // 이 값이 echo_pin 단자가 HIGH 상태를 유지하였던 시간(mocro 단위로 측정)이다. 
 
  */


int maximumRange = 4000; // Maximum range needed[mm]
int minimumRange = 30; // Minimum range needed[mm]
long duration, distance;
double sSpeed_m_s, sSpeed_cm_us;


// Echo 단자는 인터럽트 요구원으로 활용되므로 이 예제에서는 H/W 인터럽트가 지원되는 단자 번호를 사용해야 한다.
int echoPin=2;  
int trigPin=8;   // Trigger Pin
int Temperature=27;  // 섭씨 온도


void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT); pinMode(echoPin, INPUT);
  sSpeed_m_s = 331.5 + 0.6*Temperature; // 소리의 이동 속도 [m/sec]
  sSpeed_cm_us = (331.5 + 0.6*Temperature) * pow(10, 2) / pow(10, 6); // 이동 속도 [cm/us]
  Serial.print("sSpeed_m_s[m/sec] ="); Serial.println(sSpeed_m_s);
  Serial.print("sSpeed_cm_us[cm/us] ="); Serial.println(sSpeed_cm_us);

  // 초음파 센서의 echoPin 단자 신호에 의해 인터럽트가 발생하게 한다.
  attachInterrupt(digitalPinToInterrupt(echoPin), call_micros, CHANGE);    
}

volatile bool check_start = false;  // ISR 내부에서 시작시간의 기록을 지시. 
volatile bool check_end = false;    // ISR 내부에서 종료시간의 기록을 지시. 
volatile int start_count, end_count;  // micros() 함수로 반환되는 시작, 종료 tick count

// 인터럽트 서비스 루틴. echoPin 단자의 상태가 바뀌면 호출된다.
int call_micros(){
  if(check_start == true)
    start_count = micros();
  if(check_end == true)
    end_count = micros();
}

int MyPulseIn_Int(int echoPin, bool value) {    // valu=HIGH or LOW
  int v;  
  bool  normal, event;
  if (value == HIGH) {
    normal = LOW;
    event = HIGH;
  }
  else {
    normal = HIGH;
    event = LOW;
  }
  unsigned long cnt_s, cnt_e;
  // 주파수=40KHz => 주기=1/(40*1000) [s] = 1000/(40*1000*1000) [s]= 1000/40 [us] = 25[us] 
  delayMicroseconds(7*25);    // 7개의 파형이 송출될 때까지 기다린다. 실제로는 8개 인데 미리 기다린다.
  check_start = true;   // echoPin 단자가 현재 noral일 텐데 event가 되면 ISR에서 그 시점을 기록한다.

  // echoPin이 event 상태가 될 때까지 기다린다. 이 loop안에서 첫번째 인터럽트가 발생한다.
  while(digitalRead(echoPin)== normal);   
  
  check_start = false;
  check_end = true;   // echoPin 단자가 현재 event일 텐데 normal이 되면 ISR에서 그 시점을 기록한다.
  // 이번에는 echoPin이 normal 상태가 될 때까지 기다린다. 이 loop안에서 두번째 인터럽트가 발생한다.    
  while(digitalRead(echoPin)== event);   // LOW가 될 때까지 기다린다.
  check_end = false;
  
  return(end_count-start_count); 
}

int Read_mm_Dist(int echoPin, int trigPin, int Temperature) {
  digitalWrite(trigPin, LOW); // 시작하기 전에 일단 trig 신호를 LOW로 만들어 오동작 방지.
  delayMicroseconds(2); // 약간의 지연시간을 제공.
  digitalWrite(trigPin, HIGH); // 10 micro sec. High Pulse 생성
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW); // Low가 됨과 동시에 모듈은 40khz의 pulse 8개를 만들어 출력함.
  //duration = pulseIn(echoPin, HIGH); // 초음파가 발사+반사되어 돌아오는 시간(us)을 반환받는다.
  duration = MyPulseIn_Int(echoPin, HIGH); // 초음파가 발사+반사되어 돌아오는 시간(us)을 반환받는다.
  
  //distance = pow(10, 2) * duration * sSpeed_m_s / (2 * pow(10, 6)); // 식 (3)
  distance = duration/2 * sSpeed_cm_us; // 식 (4)  [cm] 단위
  distance = distance * 10;   // [mm] 단위로 환산하기 위해 추가.
  return(distance);
}


void loop() {
int range;
  distance = Read_mm_Dist(echoPin, trigPin, Temperature);
  
  if (distance > maximumRange )   {
    Serial.println("Too long..."); 
  }
  else if (distance < minimumRange)   {
    Serial.println("Too short..."); 
  }
  else {
    Serial.print("distance[mm] : ");
    Serial.println(distance);
    delay(1000);
  }
  delay(1000);
}



/*
// 기록용.
void loop() {
int range;
  digitalWrite(trigPin, LOW); // 시작하기 전에 일단 trig 신호를 LOW로 만들어 오동작 방지.
  delayMicroseconds(2); // 약간의 지연시간을 제공.
  digitalWrite(trigPin, HIGH); // 10 micro sec. High Pulse 생성
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW); // Low가 됨과 동시에 모듈은 40khz의 pulse 8개를 만들어 출력함.
  //duration = pulseIn(echoPin, HIGH); // 초음파가 발사+반사되어 돌아오는 시간(us)을 반환받는다.
  duration = MyPulseIn(echoPin, HIGH); // 초음파가 발사+반사되어 돌아오는 시간(us)을 반환받는다.
  
  //distance = pow(10, 2) * duration * sSpeed_m_s / (2 * pow(10, 6)); // 식 (3)
  distance = duration/2 * sSpeed_cm_us; // 식 (4)  [cm] 단위
  distance = distance * 10;   // [mm] 단위로 환산하기 위해 추가.
  
  if (distance > maximumRange || distance < minimumRange)   {
    Serial.println("out of range"); 
    delay(1000);
  }
  else {
    Serial.print("distance[mm] : ");
    Serial.println(distance);
    delay(1000);
  }
}

*/
 
