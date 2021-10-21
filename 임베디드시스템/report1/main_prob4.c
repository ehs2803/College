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

	int i,j;
	int check=1, check1=1, check2=1;
	int num;
	int dip_data1, dip_data2,dip_data3;
	int dip_data;
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
