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

	int h=13,m=59,s=53;
	int time=0;
	while(1){
		WRITE_FND(1,(h/10)%10);
		WRITE_FND(2,h%10);

		WRITE_FND_DOT(2,1);

		WRITE_FND(3,(m/10)%10);
		WRITE_FND(4,m%10);

		WRITE_FND_DOT(4,1);

		WRITE_FND(5,(s/10)%10);
		WRITE_FND(6,s%10);

		time++;
		if(time==100){
			s++;
			if(s==60){
				s=0;
				if(m==59){
					m=0;
					if(h==23) h=0;
					else h++;
				}
				else m++;
			}
			time=0;
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

