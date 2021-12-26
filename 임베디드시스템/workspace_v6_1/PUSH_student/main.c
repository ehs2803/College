
#include "cortex_m4.h"
#include "MyLib.h"

void LED_clear();
void delay(int count);

int main(void) {
	int push_data;
	int dip_data;
	//unsigned char dip_data;
	char count = 0;
	int flag = 0;

	uint32_t ui32SysClock;
	// Run from the PLL at 120 MHz.
	ui32SysClock = SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ | SYSCTL_OSC_MAIN | SYSCTL_USE_PLL |
											   SYSCTL_CFG_VCO_480), 120000000);

	PUSH_init();
	LED_init();
	DIP_init();
	LED_clear();

	/*
	// 2번문제 - 5
	int num=0, Isdown=0;
	while(1){
		push_data = ~( GPIO_READ(GPIO_PORTP, 0x02) >> 1 );
		if(!flag){
			if(push_data & 0x01){
				flag=1;
				GPIO_WRITE(GPIO_PORTL, 0xf, i&0x0f);
				GPIO_WRITE(GPIO_PORTM, 0xf, (i>>4)&0x0f);
				delay(2500000);
			}

		}
		else if(flag && !(push_data & 0x1)){
			flag=0;
		}
		delay(900000);
	}
	*/

/* 2번문제 - 1~4
	int num,i;
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

		if(!flag){
			if(push_data & 0x01){
				flag=1;
				num=dip_data;
				for(i=0;i<num;i++){
					GPIO_WRITE(GPIO_PORTL, 0xf, 0xf);
					GPIO_WRITE(GPIO_PORTM, 0xf, 0xf);
					delay(2500000);
					GPIO_WRITE(GPIO_PORTL, 0xf, 0);
					GPIO_WRITE(GPIO_PORTM, 0xf, 0);
					delay(2500000);
				}
			}
			if(push_data & 0x02){
				num=dip_data;
				for(i=0;i<=num;i++){
					GPIO_WRITE(GPIO_PORTL, 0xf, i&0x0f);
					GPIO_WRITE(GPIO_PORTM, 0xf, (i>>4)&0x0f);
					delay(2500000);
				}
			}
			if(push_data & 0x04){
				flag=1;
				GPIO_WRITE(GPIO_PORTL, 0xf, 0xf);
				GPIO_WRITE(GPIO_PORTM, 0xf, 0xf);
			}
			if(push_data & 0x08){
				flag=1;
				GPIO_WRITE(GPIO_PORTL, 0xf, 0);
				GPIO_WRITE(GPIO_PORTM, 0xf, 0);
			}
		}
		else if(flag && !(push_data & 0x1) && !(push_data & 0x2) &&
				!(push_data & 0x4) &&!(push_data & 0x8)){
			flag=0;
		}
		delay(900000);
	}

	*/

	/*//prob1
	int cnt=0;
	while(1){
		push_data = ~( GPIO_READ(GPIO_PORTP, 0x02) >> 1 ) &
							~( GPIO_READ(GPIO_PORTN, 0x08) >> 2 ) &
							~( GPIO_READ(GPIO_PORTE, 0x20) >> 3 ) &
							~( GPIO_READ(GPIO_PORTK, 0x80) >> 4 );

		if(!flag){
			if(push_data & 0x04){
				flag=1;
				cnt++;
			}
			if(push_data & 0x08){
				flag=1;
				GPIO_WRITE(GPIO_PORTL, 0xf, cnt&0x0f);
				GPIO_WRITE(GPIO_PORTM, 0xf, (cnt>>4)&0x0f);

			}
		}
		else if(flag && !(push_data & 0x1) && !(push_data & 0x2) &&
				!(push_data & 0x4) &&!(push_data & 0x8)){
			flag=0;
		}
		delay(900000);

	}
	*/
	/*//prob2
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

		if(!flag){
			if(push_data & 0x1){
				flag=1;
				GPIO_WRITE(GPIO_PORTL, 0x0f, dip_data&15);
				GPIO_WRITE(GPIO_PORTM, 0x0f, (dip_data>>4)&15);
			}
			if(push_data & 0x02){
				flag=1;
				cnt++;
			}
			if(push_data & 0x04){
				flag=1;
				int sum = cnt+dip_data;
				GPIO_WRITE(GPIO_PORTL, 0x0f, sum&15);
								GPIO_WRITE(GPIO_PORTM, 0x0f, (sum>>4)&15);
			}
		}
		else if(flag && !(push_data & 0x1) && !(push_data & 0x2) &&
				!(push_data & 0x4) &&!(push_data & 0x8)){
			flag=0;
		}
		delay(900000);

	}
	*/
	/*//prob3
	int i=0;
	int k;
	while(1){
		dip_data = ( GPIO_READ(GPIO_PORTA, 0x08) >> 3 ) |
					( GPIO_READ(GPIO_PORTA, 0x40) >> 5 ) |
					( GPIO_READ(GPIO_PORTA, 0x80) >> 5 ) |
					( GPIO_READ(GPIO_PORTB, 0x08) >> 0 ) |
					( GPIO_READ(GPIO_PORTQ, 0x40) >> 2 ) |
					( GPIO_READ(GPIO_PORTQ, 0x20) >> 0 ) |
					( GPIO_READ(GPIO_PORTQ, 0x10) << 2 ) |
					( GPIO_READ(GPIO_PORTG, 0x40) << 1 );

		push_data = ~( GPIO_READ(GPIO_PORTP, 0x02) >> 1 ) &
					~( GPIO_READ(GPIO_PORTN, 0x08) >> 2 ) &
					~( GPIO_READ(GPIO_PORTE, 0x20) >> 3 ) &
					~( GPIO_READ(GPIO_PORTK, 0x80) >> 4 );

		if(!flag){
			if(push_data & 0x04){
				flag=1;
				k=dip_data;
				for(i=0;i<=k;i++){
					GPIO_WRITE(GPIO_PORTL, 0x0f, i&15);
					GPIO_WRITE(GPIO_PORTM, 0x0f, (i>>4)&15);
					delay(2000000);
				}
			}
			if(push_data & 0x8){
				flag=1;
				k--;
				GPIO_WRITE(GPIO_PORTL, 0x0f, k&15);
				GPIO_WRITE(GPIO_PORTM, 0x0f, (k>>4)&15);
			}
		}
		else if(flag && !(push_data & 0x1) && !(push_data & 0x2) &&
				!(push_data & 0x4) &&!(push_data & 0x8)){
			flag=0;
		}
		delay(900000);
	}
	*/
	return 0;
}

void LED_clear(){
	GPIO_WRITE(GPIO_PORTL, 0xf, 0x0);
	GPIO_WRITE(GPIO_PORTM, 0xf, 0x0);
	delay(2500000);
}

void delay(int count){
	while(count != 0){
		count--;
	}
}
