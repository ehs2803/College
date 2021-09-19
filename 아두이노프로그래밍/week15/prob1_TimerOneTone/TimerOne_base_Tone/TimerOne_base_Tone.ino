/*

1. 개요:
  microsecond 단위의 인터럽트를 호출할 수 있는 라이브러리를 활용하여 Tone()함수를 설계한다.
  
  타이머의 resolution이 낮으면 고음을 만들어 낼 수 없다. 
  cf. MsTimer2의 경우 1ms 간격의 인터럽트를 생성할 수 있으므로 1000Hz 간격의 인터럽트를 발생한다.
  인터럽트가 발생할 때마다 스피커의 출력을 반전한다면 실제로는 500Hz의 주파수를 발생시킨다.
  MsTimer2 based tone() 함수를 만든다면 그 프로그램 범위에 따른 출력 주파는 아래와 같을 것이다.
  프로그램 값(주기) 범위: 65535[ms] < period < 1[ms]
  => 출력 주파수(주파수)의 범위: 15/2[Hz] < Hz < 1000/2[Hz]

  아래의 timerOne 라이브러리는 1us 단위의 인터럽트를 발생시킬 수 있으므로 최대 500,000Hz의 음정을 만들어 낼 수 있다.
  참조 링크: https://github.com/PaulStoffregen/TimerOne

2. 프로그램의 동작
  특정 주파수를 출력하는 myTone()과 출력을 중지하는 myNoTone() 함수를 정의한다.
  직렬통신으로 입력받은 주파수의 음정을 myTone()과 아두이노 자체 함수 Tone()을 번갈아 출력하여 음정을 비교한다.
  또한, myTone()음정을 출력하는 동안 delay()함수 기반으로 내장 LED를 지정된 시간동안 점멸시키는 루틴, delayWithLED(시간)을 수행하게 하였다.
  이는 Tone(0과 myTone() 모두 인터럽트 기반으로 동작한다는 사실을 반증한다.


*/

#include <TimerOne.h>

// This example uses the timer interrupt to blink an LED
// and also demonstrates how to share a variable between
// the interrupt and the main program.


#define SPK_PIN 10

// global variable
volatile bool spk = false;
volatile int  spk_pin;

void setup(void) {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Speaker Test: tone() vs. myTone()");
}

// The interrupt will blink the LED, and keep
// track of how many times it has blinked.
int ledState = LOW;

// 인터럽트 서비스 루틴. 전역변수 spk_pin 단자에 반전된 spk 값을 출력한다.
void micro_int(void) {
  spk = !spk;
  digitalWrite(spk_pin, spk);
}

void myTone(int pin, int freq) {
  spk_pin = pin;
  pinMode(spk_pin, OUTPUT);
  Timer1.attachInterrupt(micro_int);  // link to interrupt service routine
  unsigned long prog_v = 1000000/(freq*2);  
  Timer1.initialize(prog_v);
}
void myNoTone(void) {
  Timer1.detachInterrupt();
}

// 주어진 dly[ms] 동안 LED를 4회 깜박인다.
void  delayWithLED(int dly) {
  int ddly = dly/8;
  for (int i=0; i<4; i++) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(ddly);
    digitalWrite(LED_BUILTIN, LOW);     
    delay(ddly);
  }
}

// 테라텀에서 문자열 받기, 시리얼 모니터도 된다(단 하단의 설정을 "새줄"(LF)로 설정해야함).
// 테라텀 setup->terminal에서 new-line을 보낼 때, 받을 때 모두 LF로 세팅해야 한다.
// 테라텀에서는 backspace도 그대로 보내기 때문에 이에 대한 별도의 처리가 필요하다.
int inputFromTerminal() {
  String inString;
  while (1) {
    if(Serial.available() > 0) {
    char inChar = Serial.read();
    if (inChar =='\n')    
      break;  // String에는 끝에 null이 없어도 된다.
    Serial.print(inChar);
    inString += (char)inChar; 
    }
  }
  return(inString.toInt());     // int로 바꾸어 반환
}

// 주파수를 입력받아 작성한 함수 MtTone()과 아두이노 내장함수 tone()으로 2회 출력한다.
// 두 음정의 차이가 있는지 점검한다.
// 음정을 출력하는 동안 LED를 점멸시키는 함수를 수행하게 하여, 두 개의 함수들이 인터럽트 기반으로 동작함을 보인다.
void loop(void) {
  Serial.print("Frequency = ");
  int freq = inputFromTerminal();    // 테라텀으로 입력받기. 시리얼 모니터도 된다.
  Serial.println("\nGenerating sound by myTone()...");
  myTone(SPK_PIN, freq);
  delayWithLED(4*1000); // 4초간 LED를 깜밖이며 기다린다. myTone()이 인터럽트 기반이라 문제없다.
  myNoTone(); // 본래의 noTone(단자번호)함수와는 달리 번호를 지정할 필요가 없도록 설계하였다.
  delayWithLED(1000);   // 일단 1초를 지연 시킨다.
  Serial.println("Generating sound by tone()...");
  tone(SPK_PIN, freq);
  delayWithLED(2*1000); // 2초간 LED를 깜밖이며 기다린다. tone()이 인터럽트 기반이라 문제없다.
  noTone(SPK_PIN);
}
