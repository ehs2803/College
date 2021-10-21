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
	
		// Read Dip Data
		dip_data = ( GPIO_READ(GPIO_PORTA, 0x08) >> 3 ) |
							   ( GPIO_READ(GPIO_PORTA, 0x40) >> 5 ) |
							   ( GPIO_READ(GPIO_PORTA, 0x80) >> 5 ) |
							   ( GPIO_READ(GPIO_PORTB, 0x08) >> 0 ) |
							   ( GPIO_READ(GPIO_PORTQ, 0x40) >> 2 ) |
							   ( GPIO_READ(GPIO_PORTQ, 0x20) >> 0 ) |
							   ( GPIO_READ(GPIO_PORTQ, 0x10) << 2 ) |
							   ( GPIO_READ(GPIO_PORTG, 0x40) << 1 );


		if(dip_data&0x1){
			LLED_UPCOUNT();
			LLED_DOWNCOUNT();
			//LED_clear();
		}
		if(dip_data&0x2){
			MLED_UPCOUNT();
			MLED_DOWNCOUNT();
			//LED_clear();
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
