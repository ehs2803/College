/*
 * main.c
*/

#include "cortex_m4.h"
#include "MyLib.h"


int main(void) {

	uint32_t ui32SysClock;

	// Run from the PLL at 120 MHz.
	ui32SysClock = SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ |
										SYSCTL_OSC_MAIN | SYSCTL_USE_PLL |
										SYSCTL_CFG_VCO_480), 120000000);

	FND_init();
	FND_clear();
	DIP_init();
	PUSH_init();
	FND_init();
	LED_init();

	int seg6on=0,set5on=0;
	int seg6num=0,seg5num=1;
	int flag=0, dip_data, push_data;
	int time=0, time1=0;
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


				if(seg6on==1){
					time++;
					if(time==500000){

						if(seg6num==4){
							set5on=1;
						}

						WRITE_FND(6,seg6num);
						seg6num++;
						if(seg6num==5) seg6num=0;
						time=0;
					}

				}



		        if(!flag){
		           if(push_data & 0x1){
		        	   GPIO_WRITE(GPIO_PORTM, 0x0f, 1);
		        	   delay(2000000);
		        	   GPIO_WRITE(GPIO_PORTM, 0x0f,3);delay(2000000);
		        	   GPIO_WRITE(GPIO_PORTM, 0x0f, 7);delay(2000000);
		        	   GPIO_WRITE(GPIO_PORTM, 0x0f, 15);delay(2000000);
		        	   seg6on=1;
		        	   seg6num=0;
		              flag=1;
		           }
		           if(push_data & 0x02){ //push 2번 누르면 업카운트


		              flag=1;
		           }

		        }
		        else if(flag && !(push_data & 0x1) && !(push_data & 0x2)){
		           flag=0;
		        }
	}



}

void delay(int count){
	while(count != 0){
		count--;
	}
}

void WRITE_FND_MINUS(int digit){
	int i;

	GPIO_WRITE(GPIO_PORTC, 0x10 | 0x20 | 0x40 | 0x80,  (0x40 >> 4) & 0xf0);
	GPIO_WRITE(GPIO_PORTG,  0x01 | 0x02 | 0x04 | 0x08 , ((0x40 >> 4) & 0x0f));

	GPIO_WRITE(GPIO_PORTH, 0x01 | 0x02 | 0x04 | 0x08, fnd_pos[digit-1] & 0x0f);
	GPIO_WRITE(GPIO_PORTN, 0x10 | 0x20, fnd_pos[digit-1] & 0xf0);

	for(i=0; i<9999;i++);
}

