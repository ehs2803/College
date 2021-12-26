

int main(void){

   int buzzer_cnt = 0;
   int buzzer_count = 0;

   uint32_t ui32SysClock;


   ui32SysClock = SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ |
                              SYSCTL_OSC_MAIN | SYSCTL_USE_PLL |
                              SYSCTL_CFG_VCO_480), 120000000);
   TIMER_init();
   BUZZER_init();
   PUSH_init();
   FND_init();
   WDTinitISR();

   GPIO_WRITE(GPIO_PORTD, 0x10, 0x10);  // buzzer ON
   GPTMCTL = GPTMCTL | 0x41;          // timer enable

   BUZZER_clear();

   //prob();



   int push_data;
   int dip_data;
   int flag=0;
   int k=0;
   //int i=-1;    //바이너리 카운트
   int i = 0x00; //시프트 카운트
   int num1,num2,num3;
   int play=0;
   int time=0;
   int Melody_Name[8] = {C1,D1,E1,F1,G1,A1,B1};
   int cnt=0;
   while(1){
      push_data = ~( GPIO_READ(GPIO_PORTP, 0x02) >> 1 ) &
                  ~( GPIO_READ(GPIO_PORTN, 0x08) >> 2 ) &
                  ~( GPIO_READ(GPIO_PORTE, 0x20) >> 3 ) &
                  ~( GPIO_READ(GPIO_PORTK, 0x80) >> 4 );

      dip_data = ( GPIO_READ(GPIO_PORTA, 0x08) >> 3 ) |
                 ( GPIO_READ(GPIO_PORTA, 0x40) >> 5 ) |
                 ( GPIO_READ(GPIO_PORTA, 0x80) >> 5 ) |
                 ( GPIO_READ(GPIO_PORTB, 0x08) >> 0 ) |
                 ( GPIO_READ(GPIO_PORTQ, 0x40) >> 2 ) |
                 ( GPIO_READ(GPIO_PORTQ, 0x20) >> 0 ) |
                 ( GPIO_READ(GPIO_PORTQ, 0x10) << 2 ) |
                 ( GPIO_READ(GPIO_PORTG, 0x40) << 1 );

      if(play==1){
    	  time++;
    	  if(time==100){
    		  Play(Melody_Name[k]);
    		  DelayForPlay(DLY_8);
    		  k++;
    		  time=0;
    	  }
    	  if(k==7) k=0;

      }

      WRITE_FND(1,num1);
      WRITE_FND(2,num2);
      WRITE_FND(3,num3);

      if(!flag){
         if(push_data & 0x01 ){ //1번 눌렀을때, 음계 하나 씩 올라감
            play=1;
            flag=1;
         }
         if(push_data & 0x02){ //2번 눌렀을 때, 음계 하나 씩 다운
           play=0;
           cnt++;
           if(cnt==1){
        	   num1=k+1;
           }
           else if(cnt==2){
        	   num2=k+1;
           }
           else if(cnt==3){
        	   num3=k+1;
           }
           flag=1;
         }
          if(push_data & 0x04){ //push 3번 누르면 업시프트하면서 소리
        	  flag=1;
        	  while(1){
        		  Play(Melody_Name[num1]);
        		  DelayForPlay(DLY_8);
        		  Play(Melody_Name[num2]);
        		  DelayForPlay(DLY_8);
        		  Play(Melody_Name[num3]);
        		  DelayForPlay(DLY_8);
        	  }
          }

      } else if(flag && !(push_data & 0x1) && !(push_data & 0x2) && !(push_data & 0x4)){
           flag=0;
       }
   }
      //바이너리 카운트

/*

      if(!flag){
         if(push_data & 0x01 ){ //1번 눌렀을때, 음계 하나 씩 올라감
           i += 1;
            //Push1 on
            GPIO_WRITE(GPIO_PORTD, 0x10, 0x10); // buzzer ON
            GPIO_WRITE(GPIO_PORTL, 0xf, i);
            Play(Melody_Name[i]);
            DelayForPlay(DLY_8);

            GPIO_WRITE(GPIO_PORTD, 0x10, ~0x10);  // buzzer OFF
            flag=1;
         }
         if(push_data & 0x02){ //2번 눌렀을 때, 음계 하나 씩 다운
           i -= 1;
            //Push2 on
            GPIO_WRITE(GPIO_PORTD, 0x10, 0x10); // buzzer ON
            GPIO_WRITE(GPIO_PORTL, 0xf, i);
            Play(Melody_Name[i]);
            DelayForPlay(DLY_8);
            GPIO_WRITE(GPIO_PORTD, 0x10, ~0x10);  // buzzer OFF
            flag=1;
         }
          if(push_data & 0x04){ //push 3번 누르면 업카운트내면서 소리
             k=dip_data;
             GPIO_WRITE(GPIO_PORTD, 0x10, 0x10); // buzzer ON
             for(i=0;i<=k;i++){
                GPIO_WRITE(GPIO_PORTL, 0x0f, i&15);
                //GPIO_WRITE(GPIO_PORTM, 0x0f, (i>>4)&15);
                Play(Melody_Name[i]);
                DelayForPlay(DLY_8);
             }
             GPIO_WRITE(GPIO_PORTD, 0x10, ~0x10);  // buzzer OFF
             flag=1;
          }
          if(push_data & 0x08){ //push 4번 누르면 다운 카운트내면서 소리
             k=dip_data;
             GPIO_WRITE(GPIO_PORTD, 0x10, 0x10); // buzzer ON
             for(i=k;i>=0;i--){
                GPIO_WRITE(GPIO_PORTL, 0x0f, i&15);
                //GPIO_WRITE(GPIO_PORTM, 0x0f, (i>>4)&15);
                Play(Melody_Name[i]);
                DelayForPlay(DLY_8);
             }
             GPIO_WRITE(GPIO_PORTD, 0x10, ~0x10);  // buzzer OFF
             flag=1;
          }
      } else if(flag && !(push_data & 0x1) && !(push_data & 0x2) && !(push_data & 0x4) &&!(push_data & 0x8)){
           flag=0;
       }
*/
/*
      //시프트 카운트

      int Melody_Name[8] = {C1,D1,E1,F1,G1,A1,B1,C2};


      if(!flag){
         if(push_data & 0x01 ){ //1번 눌렀을때, 음계 하나 씩 올라감
             i = i*2;
             if(i>128) i=128;
             if(i==0) i=0x1;
            GPIO_WRITE(GPIO_PORTD, 0x10, 0x10); // buzzer ON
            GPIO_WRITE(GPIO_PORTL, 0xf, i);
            GPIO_WRITE(GPIO_PORTM, 0xf, (i>>4)&0xf);
            if(i==1)
               Play(C1);
            if(i==2)
               Play(D1);
            if(i==4)
               Play(E1);
            if(i==8)
               Play(F1);
            if(i==16)
               Play(G1);
            if(i==32)
               Play(A1);
            if(i==64)
               Play(B1);
            if(i==128)
               Play(C2);
            DelayForPlay(DLY_8);
            GPIO_WRITE(GPIO_PORTD, 0x10, ~0x10);  // buzzer OFF
            flag=1;
         }
         if(push_data & 0x02){ //2번 눌렀을 때, 음계 하나 씩 다운
             i = i/2;
             if(i<1) i=1;
            GPIO_WRITE(GPIO_PORTD, 0x10, 0x10); // buzzer ON
            GPIO_WRITE(GPIO_PORTL, 0xf, i);
            GPIO_WRITE(GPIO_PORTM, 0xf, (i>>4)&0xf);
            if(i==1)
               Play(C1);
            if(i==2)
               Play(D1);
            if(i==4)
               Play(E1);
            if(i==8)
               Play(F1);
            if(i==16)
               Play(G1);
            if(i==32)
               Play(A1);
            if(i==64)
               Play(B1);
            if(i==128)
               Play(C2);
            DelayForPlay(DLY_8);
            GPIO_WRITE(GPIO_PORTD, 0x10, ~0x10);  // buzzer OFF
            flag=1;
         }
          if(push_data & 0x04){ //push 3번 누르면 업시프트하면서 소리
             GPIO_WRITE(GPIO_PORTD, 0x10, 0x10); // buzzer ON
             i=1;
             for(k=0; k<8; k++){
                GPIO_WRITE(GPIO_PORTL, 0x0f, i&15);
                GPIO_WRITE(GPIO_PORTM, 0x0f, (i>>4)&15);
                Play(Melody_Name[k]);
                DelayForPlay(DLY_8);
                i=i*2;
             }
             GPIO_WRITE(GPIO_PORTD, 0x10, ~0x10);  // buzzer OFF
             flag=1;
             i=1;
          }
          if(push_data & 0x08){ //push 4번 누르면 다운시프트하면서 소리
            i=128;
             GPIO_WRITE(GPIO_PORTD, 0x10, 0x10); // buzzer ON
             for(k=7; k>=0; k--){
                GPIO_WRITE(GPIO_PORTL, 0x0f, i&15);
                GPIO_WRITE(GPIO_PORTM, 0x0f, (i>>4)&15);
                Play(Melody_Name[k]);
                DelayForPlay(DLY_8);
                i=i/2;
             }
             GPIO_WRITE(GPIO_PORTD, 0x10, ~0x10);  // buzzer OFF
             flag=1;
             i=128;
          }

      } else if(flag && !(push_data & 0x1) && !(push_data & 0x2) && !(push_data & 0x4) &&!(push_data & 0x8)){
           flag=0;
       }
   }

*/

      //도레미 푸시123번
/*
      if(!flag){
         if(push_data & 0x01 ){  //도
            GPIO_WRITE(GPIO_PORTD, 0x10, 0x10); // buzzer ON
            GPIO_WRITE(GPIO_PORTL, 0xf, 0x01);
            Play(Melody_Name[0]);
            DelayForPlay(DLY_16);
            GPIO_WRITE(GPIO_PORTD, 0x10, ~0x10);  // buzzer OFF
            flag=1;
         }
         if(push_data & 0x02){  //레
            GPIO_WRITE(GPIO_PORTD, 0x10, 0x10); // buzzer ON
            GPIO_WRITE(GPIO_PORTL, 0xf, 0x02);
            Play(Melody_Name[1]);
            DelayForPlay(DLY_16);
            GPIO_WRITE(GPIO_PORTD, 0x10, ~0x10);  // buzzer OFF
            flag=1;
         }
          if(push_data & 0x04){ //미
             k=dip_data;
             GPIO_WRITE(GPIO_PORTD, 0x10, 0x10); // buzzer ON
             GPIO_WRITE(GPIO_PORTL, 0x0f, 0x04);
             Play(Melody_Name[2]);
             DelayForPlay(DLY_16);
             GPIO_WRITE(GPIO_PORTD, 0x10, ~0x10);  // buzzer OFF
             flag=1;
          }
      } else if(flag && !(push_data & 0x1) && !(push_data & 0x2) && !(push_data & 0x4) &&!(push_data & 0x8)){
           flag=0;
       }
*/


/*
   Play(C1); //도
   DelayForPlay(DLY_8);

   Play(D1); //레
   DelayForPlay(DLY_8);

   Play(E1); //미
   DelayForPlay(DLY_8);

   Play(F1); //파
   DelayForPlay(DLY_8);

   Play(G1); //솔
   DelayForPlay(DLY_8);

   Play(A1); //라
   DelayForPlay(DLY_8);

   Play(B1); //시
   DelayForPlay(DLY_8);

   Play(C2); // 높은 도
   DelayForPlay(DLY_8);

   BUZZEROFF();


*/

/*
   int i, cnt, flag;
   while(1)
      {
         for(i = 0; i < cnt / 100; i++)
         {
            Play(10000+cnt);
            DelayForPlay(1);

            Play(10000+cnt);
            DelayForPlay(1);
         }

         if(flag) cnt += 50; else cnt -= 50;
         if(cnt >= 5000) flag = 0;   // Decrease cnt
         if(cnt <= 100) flag=1;      // Increase cnt
      }
*/

   return 0;
}

void TimerEn() {
// buzzer ON
   GPTMCTL = GPTMCTL | 0x41;          // timer enable

   BUZZER_clear();
}

void BUZZERON() {
   GPIO_WRITE(GPIO_PORTD, 0x10, 0x10);
}

void BUZZEROFF() {
   GPIO_WRITE(GPIO_PORTD, 0x10, ~0x10);  // buzzer OFF
   WDT1LOAD = 0xFFFFFFFF; //WDT RESET
}

void PLAY(int freq) {
   GPTMTAILR = buzzer[freq];
   GPTMTMATCHR = buzzer[freq] / 2;
}

void LED_clear(){
   GPIO_WRITE(GPIO_PORTL, 0xf, 0x0);
   GPIO_WRITE(GPIO_PORTM, 0xf, 0x0);
   delay(2500000);
}
/*
void prob(){



   delay(10000000);

   int Melody_Name[8] = {C1,D1,E1,F1,G1,A1,B1,C2};
   int push_data;
   int i=0;


   while(1){

      push_data = ~( GPIO_READ(GPIO_PORTP, 0x02) >> 1 ) &
               ~( GPIO_READ(GPIO_PORTN, 0x08) >> 2 ) &
               ~( GPIO_READ(GPIO_PORTE, 0x20) >> 3 ) &
               ~( GPIO_READ(GPIO_PORTK, 0x80) >> 4 );

      if(push_data & 0x01 ){
         //Push1 on
         GPIO_WRITE(GPIO_PORTD, 0x10, 0x10); // buzzer ON
         GPIO_WRITE(GPIO_PORTL, 0xf, i);
         Play(Melody_Name[i]);
         DelayForPlay(DLY_8);
         i += 1;
         GPIO_WRITE(GPIO_PORTD, 0x10, ~0x10);  // buzzer OFF
      }


      if(push_data & 0x02){
         //Push2 on
         GPIO_WRITE(GPIO_PORTD, 0x10, 0x10); // buzzer ON
         GPIO_WRITE(GPIO_PORTL, 0xf, i);
         Play(Melody_Name[i]);
         DelayForPlay(DLY_8);
         i -= 1;
         GPIO_WRITE(GPIO_PORTD, 0x10, ~0x10);  // buzzer OFF
      }

      if(push_data & 0x04){
         //Push3 on
         GPIO_WRITE(GPIO_PORTD, 0x10, 0x10); // buzzer ON

         delay(9000000);

         GPIO_WRITE(GPIO_PORTM, 0xf, 0x2);
         Play(E1);
         DelayForPlay(DLY_16);
         GPIO_WRITE(GPIO_PORTM, 0xf, 0x0);

         //GPIO_WRITE(GPIO_PORTD, 0x10, ~0x10);
         delay(250000);
         GPIO_WRITE(GPIO_PORTD, 0x10, 0x10);

         GPIO_WRITE(GPIO_PORTM, 0xf, 0x3);
         Play(D1);
         DelayForPlay(DLY_16);
         GPIO_WRITE(GPIO_PORTM, 0xf, 0x0);

         GPIO_WRITE(GPIO_PORTD, 0x10, ~0x10);
         delay(25000);
         GPIO_WRITE(GPIO_PORTD, 0x10, 0x10);

         GPIO_WRITE(GPIO_PORTM, 0xf, 0x4);
         Play(C1);
         DelayForPlay(DLY_8);
         GPIO_WRITE(GPIO_PORTM, 0xf, 0x0);

         GPIO_WRITE(GPIO_PORTD, 0x10, ~0x10);
         delay(25000);
         GPIO_WRITE(GPIO_PORTD, 0x10, 0x10);

         GPIO_WRITE(GPIO_PORTM, 0xf, 0x4);
         Play(D1);
         DelayForPlay(DLY_4);
         GPIO_WRITE(GPIO_PORTM, 0xf, 0x0);

         GPIO_WRITE(GPIO_PORTM, 0xf, 0x5);
         Play(E1);
         DelayForPlay(DLY_16);
         GPIO_WRITE(GPIO_PORTM, 0xf, 0x0);

         GPIO_WRITE(GPIO_PORTD, 0x10, ~0x10);
         delay(25000);
         GPIO_WRITE(GPIO_PORTD, 0x10, 0x10);

         GPIO_WRITE(GPIO_PORTM, 0xf, 0x6);
         Play(E1);
         DelayForPlay(DLY_16);
         GPIO_WRITE(GPIO_PORTM, 0xf, 0x0);

         GPIO_WRITE(GPIO_PORTD, 0x10, ~0x10);
         delay(25000);
         GPIO_WRITE(GPIO_PORTD, 0x10, 0x10);

         GPIO_WRITE(GPIO_PORTM, 0xf, 0x7);
         Play(E1);
         DelayForPlay(DLY_8);
         GPIO_WRITE(GPIO_PORTM, 0xf, 0x0);

         GPIO_WRITE(GPIO_PORTD, 0x10, ~0x10);
         delay(25000);
         GPIO_WRITE(GPIO_PORTD, 0x10, 0x10);

         GPIO_WRITE(GPIO_PORTM, 0xf, 0x7);
         Play(D1);
         DelayForPlay(DLY_4);
         GPIO_WRITE(GPIO_PORTM, 0xf, 0x0);

         GPIO_WRITE(GPIO_PORTD, 0x10, ~0x10);
         delay(25000);
         GPIO_WRITE(GPIO_PORTD, 0x10, 0x10);

         GPIO_WRITE(GPIO_PORTM, 0xf, 0x2);
         Play(D1);
         DelayForPlay(DLY_16);
         GPIO_WRITE(GPIO_PORTM, 0xf, 0x0);

         GPIO_WRITE(GPIO_PORTD, 0x10, ~0x10);
         delay(25000);
         GPIO_WRITE(GPIO_PORTD, 0x10, 0x10);

         GPIO_WRITE(GPIO_PORTM, 0xf, 0x3);
         Play(D1);
         DelayForPlay(DLY_16);
         GPIO_WRITE(GPIO_PORTM, 0xf, 0x0);

         GPIO_WRITE(GPIO_PORTM, 0xf, 0x4);
         Play(E1);
         DelayForPlay(DLY_16);
         GPIO_WRITE(GPIO_PORTM, 0xf, 0x0);

         GPIO_WRITE(GPIO_PORTD, 0x10, ~0x10);
         delay(40000);
         GPIO_WRITE(GPIO_PORTD, 0x10, 0x10);

         GPIO_WRITE(GPIO_PORTM, 0xf, 0x4);
         Play(E1);
         DelayForPlay(DLY_16);
         GPIO_WRITE(GPIO_PORTM, 0xf, 0x0);

         GPIO_WRITE(GPIO_PORTD, 0x10, ~0x10);
         delay(40000);
         GPIO_WRITE(GPIO_PORTD, 0x10, 0x10);

         GPIO_WRITE(GPIO_PORTM, 0xf, 0x4);
         Play(E1);
         DelayForPlay(DLY_16);
         GPIO_WRITE(GPIO_PORTM, 0xf, 0x0);

         GPIO_WRITE(GPIO_PORTD, 0x10, ~0x10);
         delay(40000);
         GPIO_WRITE(GPIO_PORTD, 0x10, 0x10);

         GPIO_WRITE(GPIO_PORTM, 0xf, 0x4);
         Play(E1);
         DelayForPlay(DLY_16);
         GPIO_WRITE(GPIO_PORTM, 0xf, 0x0);

         GPIO_WRITE(GPIO_PORTD, 0x10, ~0x10);
         delay(40000);
         GPIO_WRITE(GPIO_PORTD, 0x10, 0x10);

         GPIO_WRITE(GPIO_PORTM, 0xf, 0x4);
         Play(D1);
         DelayForPlay(DLY_8);
         GPIO_WRITE(GPIO_PORTM, 0xf, 0x0);

         GPIO_WRITE(GPIO_PORTD, 0x10, ~0x10);
         delay(25000);
         GPIO_WRITE(GPIO_PORTD, 0x10, 0x10);

         GPIO_WRITE(GPIO_PORTM, 0xf, 0x5);
         Play(C1);
         DelayForPlay(DLY_16);
         GPIO_WRITE(GPIO_PORTM, 0xf, 0x0);

         GPIO_WRITE(GPIO_PORTM, 0xf, 0x4);
         Play(D1);
         DelayForPlay(DLY_16);
         GPIO_WRITE(GPIO_PORTM, 0xf, 0x0);


         GPIO_WRITE(GPIO_PORTM, 0xf, 0x3);
         Play(E1);
         DelayForPlay(DLY_16);
         GPIO_WRITE(GPIO_PORTM, 0xf, 0x0);

         GPIO_WRITE(GPIO_PORTD, 0x10, ~0x10);
         delay(40000);
         GPIO_WRITE(GPIO_PORTD, 0x10, 0x10);

         GPIO_WRITE(GPIO_PORTM, 0xf, 0x3);
         Play(E1);
         DelayForPlay(DLY_16);
         GPIO_WRITE(GPIO_PORTM, 0xf, 0x0);

         GPIO_WRITE(GPIO_PORTD, 0x10, ~0x10);
         delay(40000);
         GPIO_WRITE(GPIO_PORTD, 0x10, 0x10);

         GPIO_WRITE(GPIO_PORTM, 0xf, 0x3);
         Play(E1);
         DelayForPlay(DLY_8);
         GPIO_WRITE(GPIO_PORTM, 0xf, 0x0);

         GPIO_WRITE(GPIO_PORTD, 0x10, ~0x10);
         delay(40000);
         GPIO_WRITE(GPIO_PORTD, 0x10, 0x10);

         GPIO_WRITE(GPIO_PORTM, 0xf, 0x3);
         Play(D1);
         DelayForPlay(DLY_8);
         GPIO_WRITE(GPIO_PORTM, 0xf, 0x0);

         GPIO_WRITE(GPIO_PORTD, 0x10, ~0x10);
         delay(25000);
         GPIO_WRITE(GPIO_PORTD, 0x10, 0x10);

         GPIO_WRITE(GPIO_PORTM, 0xf, 0x2);
         Play(D1);
         DelayForPlay(DLY_8);
         GPIO_WRITE(GPIO_PORTM, 0xf, 0x0);

         GPIO_WRITE(GPIO_PORTD, 0x10, ~0x10);
         delay(25000);
         GPIO_WRITE(GPIO_PORTD, 0x10, 0x10);

         GPIO_WRITE(GPIO_PORTM, 0xf, 0x4);
         Play(E1);
         DelayForPlay(DLY_8);
         GPIO_WRITE(GPIO_PORTM, 0xf, 0x0);

         GPIO_WRITE(GPIO_PORTM, 0xf, 0x0);
         Play(D1);
         DelayForPlay(DLY_8);
         GPIO_WRITE(GPIO_PORTM, 0xf, 0x0);

         GPIO_WRITE(GPIO_PORTM, 0xf, 0x2);
         Play(C1);
         DelayForPlay(DLY_8);
         GPIO_WRITE(GPIO_PORTM, 0xf, 0x0);



         GPIO_WRITE(GPIO_PORTD, 0x10, ~0x10);  // buzzer OFF
      }

      delay(100000);
      //GPIO_WRITE(GPIO_PORTD, 0x10, ~0x10);  // buzzer OFF
   }
}
*/
