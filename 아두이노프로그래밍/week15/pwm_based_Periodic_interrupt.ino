/*
14장 8정 고찰문제 11번: pwm_based_Periodic_interrupt

Arduino uno의 경우 anlaogWrite() 함수는 단자 5번은 490Hz, 단자 6번은 980Hz의 인터럽트를 발생한다.
https://www.arduino.cc/reference/en/language/functions/analog-io/analogwrite/

본 실험에서는 6번 단자로 980Hz의 펄스를  발생하게 만든다.
#define PWM_PIN 6
analogWrite(PWM_PIN, 128);   // duty rate 50%, 980Hz


6번 단자를 jumper 선을 이용하여 2번에 연결하여 980x2 Hz의 인터럽트를 발생하게 만든다.
#define INT_PIN 2
#define Mode  CHANGE
attachInterrupt(digitalPinToInterrupt(INT_PIN), ISR, mode)
*/

#define PWM_PIN 6   // 6번과 2번을 jumper cable로 서로 연결한다.
#define INT_PIN 2   // PWM_PIN과 INT_PIN 단자는 서로 연결되어 있다.
#define mode  CHANGE
#define MS_500 98
#define SEC_1 980*2

const byte ledPin = 13;   // 1초에 한 번씩 내장 LED를 점멸시킬 예정
volatile unsigned int count = 0;
volatile int sec=0, ms=0, old_ms=1;
volatile bool  holding = true;      // 시간 출력 중지

void setup() {
  analogWrite(PWM_PIN, 128);   // duty rate 50%, 980Hz의 pulse를 PWM 단자로 출력한다.
  attachInterrupt(digitalPinToInterrupt(INT_PIN), increment, mode);
  Serial.begin(115200);   // max speed
  //Serial.begin(9600);
  //pinMode(INT_PIN, INPUT_PULLUP);   // 꼭 필요한 조치는 아님.
  //pinMode(ledPin, OUTPUT);
  Serial.println("Stop watch:\nPress 'b' to begin, or space key to end the watch");
  //Serial.print("00");   // 현재 초 보여주며 대기...
}

void loop() {
  unsigned long t1, t2;
  int tmp1, tmp2;
  char  ch;
    if(Serial.available() > 0) {
      ch=Serial.read(); 
      switch(ch) {
        case 'b':   // begin, or start
          sec = 0;
          ms = 0;
          count = 0;
          holding = false;    // 시간 갱신을 계속하라.
          break;
        case ' ':   // end, or stop
          holding = true;    // 시간 출력을 멈춘다.
          count = 0;
          break;          
        default:
          break;    
      }
    }
#define MS_25 49    // 25ms
//#define MS_100 98*2    // 100ms
    if(holding == false) { 
      if (count >= MS_25) {
        ms += 25;
        count = 0;
      }
      if ( ms >= 1000){
        sec += 1;
        ms = 0;
      }
    }

    if (ms != old_ms) {
      Serial.write('\r');
      Serial.write(0x30+sec/10);
      Serial.write(0x30+sec%10);
      Serial.write(':');
      Serial.write(0x30+ms/100);
      Serial.write(0x30+(ms/10)%10);
      Serial.write(0x30+(ms%10)); 
      old_ms = ms;
    }
}

void increment() {
  if (holding == false)  // 멈추어야 하는가?
    count++;
}






    
/*
// count 값이 0에서 980x2가 되는 순간 1초가 경과한 것이다. 980x2를 SEC_1이라 정한다.
// count 값이 0에서 98x2가 되는 순간 0.1초(100ms)가 경과한 것이다. 이를 MS_100이라 칭한다.
// count 값이 0에서 9.8x2=19.6가 되는 순간 0.1초가 경과한 것이다. => 소수 이하는 셀 수 없으므로 무시
// 대신, count 값이 0에서 98가 되는 순간 0.05초(50ms)가 경과한 것이다. 이를 MS_50이라 칭한다.
// 대신, count 값이 0에서 49가 되는 순간 0.025초(25ms)가 경과한 것이다. 이를 MS_25이라 칭한다.
*/


/*
      char sec_ms[10];
      sec_ms[0] = '\r';
      sec_ms[1] = 0x30+sec/10;
      sec_ms[2] = 0x30+sec%10;
      sec_ms[3] = ':';
      sec_ms[4] = 0x30+sec/100;
      sec_ms[5] = 0x30+sec/10;
      sec_ms[6] = 0x30+sec%10; 
      Serial.print(sec_ms);
*/
