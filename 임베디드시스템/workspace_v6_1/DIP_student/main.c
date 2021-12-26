/*
 * main.c
 */

#include "cortex_m4.h"
#include "MyLib.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
void LED_clear();
void delay(int count);

int main(void) {

	uint32_t ui32SysClock = SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ |
												SYSCTL_OSC_MAIN | SYSCTL_USE_PLL |
												SYSCTL_CFG_VCO_480), 120000000);

	//unsigned char dip_data;

	LED_init();
	DIP_init();
	LED_clear();

	srand(time(NULL));


/*// 문제1
	int dip_data;
	int num=0;
	while(1){
		dip_data = GPIO_READ(GPIO_PORTA, 0x08);//1
		if(dip_data){
			GPIO_WRITE(GPIO_PORTL, 0x0f, num&0x0f);
			GPIO_WRITE(GPIO_PORTM, 0x0f, (num>>4)&0x0f);
			delay(2500000);
			num++;
			if(num==256) num=0;
		}

	}
*/

	/*
	// 과제1 - prob3
	int dip_data;
	int numL=0, numM=0;
	int IsdownL=0, IsdownM=0;
	while(1){
		dip_data = ( GPIO_READ(GPIO_PORTA, 0x08) >> 3 ) |
									   ( GPIO_READ(GPIO_PORTA, 0x40) >> 5 ) |
									   ( GPIO_READ(GPIO_PORTA, 0x80) >> 5 ) |
									   ( GPIO_READ(GPIO_PORTB, 0x08) >> 0 ) |
									   ( GPIO_READ(GPIO_PORTQ, 0x40) >> 2 ) |
									   ( GPIO_READ(GPIO_PORTQ, 0x20) >> 0 ) |
									   ( GPIO_READ(GPIO_PORTQ, 0x10) << 2 ) |
									   ( GPIO_READ(GPIO_PORTG, 0x40) << 1 );
		if(dip_data&0x01){
			GPIO_WRITE(GPIO_PORTL, 0x0f, numL);
			delay(2500000);
			if(IsdownL==0) numL++;
			else numL--;

			if(numL==16){
				IsdownL=1;
				numL=14;
			}
			if(numL==-1){
				IsdownL=0;
				numL=1;
			}
		}

		if(dip_data&0x02){

			GPIO_WRITE(GPIO_PORTM, 0x0f, numM);
			delay(2500000);
			if(IsdownM==0) numM++;
			else numM--;

			if(numM==16){
				IsdownM=1;
				numM=14;
			}
			if(numM==-1){
				IsdownM=0;
				numM=1;
			}
		}
	}
	*/

/*	// 문제2
	int dip_data;
	int num=255;
	while(1){
		dip_data = GPIO_READ(GPIO_PORTG, 0x40); //8
		if(dip_data){
			GPIO_WRITE(GPIO_PORTL, 0x0f, num&0x0f);
			GPIO_WRITE(GPIO_PORTM, 0x0f, (num>>4)&0x0f);
			delay(2500000);
			num--;
			if(num==-1) num=0;
		}

	}
*/


	/*//  과제1 - prob4
	int dipt_data, check=1, check1=1, check2=1, i, j, num;
	while(1){
	dip_data1 = ( GPIO_READ(GPIO_PORTA, 0x80) >> 5 );
	dip_data2 = ( GPIO_READ(GPIO_PORTQ, 0x40) >> 2 );
	dip_data3 = ( GPIO_READ(GPIO_PORTQ, 0x10) >> 0 );

	if(dip_data1){
		if(check1==1){
			//num=rand();
			i=13;//num%16;
			GPIO_WRITE(GPIO_PORTL, 0x0f, i);
			check1=0;
		}
	}
	if(dip_data2){
		if(check2==1){
			//num=rand();
			j=10;//num%16;
			GPIO_WRITE(GPIO_PORTM, 0x0f, j);
			check2=0;
		}
	}
	if(dip_data1 && dip_data2 && dip_data3 && check==1){
			LED_clear();
			int sum = i+j;
			if(sum<=15) GPIO_WRITE(GPIO_PORTL, 0x0f, sum);
			else{
				GPIO_WRITE(GPIO_PORTL, 0x0f, sum&15);
				GPIO_WRITE(GPIO_PORTM, 0x0f, (sum>>4)&15);
			}
			check=0;
	}

	if(dip_data1==0 && dip_data2==0 && dip_data3==0) {
		LED_clear();
		check=1;
		check1=1;
		check2=1;
	}
	}
	*/
/*
	int check=1, check1=1, check2=1;
	int num;
	int dip_data1, dip_data2,dip_data3;
	int dip_data;

	   int ledCountL=0;
	   int ledCountM=0;
	   int discountFlag=0;

	   while(1){
	         dip_data = ( GPIO_READ(GPIO_PORTA, 0x80) >> 5 ) | //PA7-3
	                  ( GPIO_READ(GPIO_PORTQ, 0x40) >> 2 ) | //PQ6-5
	                  ( GPIO_READ(GPIO_PORTQ, 0x10) << 2 ) ; //PQ4-7

	         int L=0xf; //십진수 15 이하 임의의 변수
	         int M=0xf; //십진수 15 이하 임의의 변수

	         if(dip_data&0x04){ //3번 스위치온, 0000 0100
	            if(check1==1){
	               GPIO_WRITE(GPIO_PORTL, 0xf, L);
	               check1=0;
	            }
	         }else{
	            GPIO_WRITE(GPIO_PORTL, 0xf, 0x0);
	         }

	         if(dip_data&0x10){ //5 번스위치 온, 0001 0000
	            if(check2==1){
	               GPIO_WRITE(GPIO_PORTM, 0xf, M);
	               check2=0;
	            }
	         }else{
	            GPIO_WRITE(GPIO_PORTM, 0xf, 0x0);
	         }

	         if((dip_data&0x04)&&(dip_data&0x10)&&(dip_data&0x40)&& check==1){ //3번,5번 스위치온상태에서 7번 스위치 온, 0101 0100
	            LED_clear();
	            if(L+M<=15){
	               GPIO_WRITE(GPIO_PORTL, 0xf, L+M);
	            }else{
	               GPIO_WRITE(GPIO_PORTL, 0xf, (L+M)%16);
	               GPIO_WRITE(GPIO_PORTM, 0xf, 0x01);
	            }
	         }else{
	            GPIO_WRITE(GPIO_PORTL, 0xf, 0x0);
	            GPIO_WRITE(GPIO_PORTM, 0xf, 0x0);
	         }
	         check=0;

	         if(dip_data==0) {
	            LED_clear();
	            check=1;
	            check1=1;
	            check2=1;
	         }
	      }

	   while(1){
	      dip_data = ( GPIO_READ(GPIO_PORTA, 0x08) >> 3 ) | //PA3-1번
	               ( GPIO_READ(GPIO_PORTA, 0x40) >> 5 );  //PA6-2번


	      if(dip_data&0x01){
	         if(ledCountL==0xf){ //1111 이면
	            discountFlag=1;
	         }
	         if(discountFlag==1){
	            if(ledCountL==0) //0이 될때까지
	               discountFlag=0;
	            else
	               ledCountL--; //다운카운트
	         }
	         else //discountFlag=0 일때,
	            ledCountL++; //업카운트
	         GPIO_WRITE(GPIO_PORTL, 0xf, ledCountL);
	         delay(2500000);
	      }

	      if(dip_data&0x02){
	         if(ledCountM==0xf){ //1111 이면
	            discountFlag=1;
	         }
	         if(discountFlag==1){
	            if(ledCountM==0) //0이 될때까지
	               discountFlag=0;
	            else
	               ledCountM--; //다운카운트
	         }
	         else //discountFlag=0 일때,
	            ledCountM++; //업카운트
	         GPIO_WRITE(GPIO_PORTM, 0xf, ledCountM);
	         delay(2500000);
	      }
	   }
*/

}

void LED_clear(){
	GPIO_WRITE(GPIO_PORTL, 0xf, 0x0);
	GPIO_WRITE(GPIO_PORTM, 0xf, 0x0);
	delay(2000000);
}

void delay(int count){
	while (count != 0) {
		count--;
	}
}

void LLED_UPCOUNT(){  //M포트 LED 점등&소등 (업카운팅 순서대로)
	int i=0;

	for(i=0;i<16;i++){

		GPIO_WRITE(GPIO_PORTL, i, 0xf);
		delay(2000000);
		GPIO_WRITE(GPIO_PORTL, i, 0x0);
	}
}

void LLED_DOWNCOUNT(){  //L포트 LED 점등&소등 (업카운팅 순서대로)
	int i=15;

	for(i=15;i>=0;i--){

		GPIO_WRITE(GPIO_PORTL, i, 0xf);
		delay(2000000);
		GPIO_WRITE(GPIO_PORTL, 0x0f, 0x0);
	}
}

void MLED_UPCOUNT(){  //M포트 LED 점등&소등 (업카운팅 순서대로)
	int i=0;

	for(i=0;i<16;i++){

		GPIO_WRITE(GPIO_PORTM, i, 0xf);
		delay(2500000);
		GPIO_WRITE(GPIO_PORTM, i, 0x0);
	}
}

void MLED_DOWNCOUNT(){  //L포트 LED 점등&소등 (업카운팅 순서대로)
	int i=15;

	for(i=15;i>=0;i--){

		GPIO_WRITE(GPIO_PORTM, i, 0xf);
		delay(2500000);
		GPIO_WRITE(GPIO_PORTM, 0x0f, 0x0);
	}
}
